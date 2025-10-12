fn main() {
    let n = 7;
    println!("count 1: {}", brain_kernighan(n));
}

// 魔法序列的数组乘积之和
/*
 * m is the lenght of the magic seq
 * every item in the seq is from the length
 * which means:
 *  nums = 2, 3, 5
 *  M = 3
 *  the seq = [0, 0, 1] or [0, 1, 2]...
 *  and the sumofSeq is M
 * so the sum the magical_sum is the sum of 2 ^ j
 */

// 取mod
fn magical_sum(m: i32, k: i32, nums: Vec<i32>) -> i32 {
    let n = nums.len();
    let m = m as usize;
    let k = k as usize;
    let mod_val = 1_000_000_007u64;

    fn quickmul(x: u64, mut y: u64, mod_val: u64) -> u64 {
        let mut res = 1;
        let mut cur = x % mod_val;
        while y > 0 {
            if y & 1 == 1 {
                res = res * cur % mod_val;
            }
            y >>= 1;
            cur = cur * cur % mod_val;
        }
        res
    }

    let mut fac = vec![0u64; m + 1];
    fac[0] = 1;
    for i in 1..=m {
        fac[i] = fac[i - 1] * i as u64 % mod_val;
    }

    let mut ifac = vec![0u64; m + 1];
    ifac[0] = 1;
    ifac[1] = 1;
    for i in 2..=m {
        ifac[i] = quickmul(i as u64, mod_val - 2, mod_val);
    }
    for i in 2..=m {
        ifac[i] = ifac[i - 1] * ifac[i] % mod_val;
    }

    let mut nums_power = vec![vec![0u64; m + 1]; n];
    for i in 0..n {
        nums_power[i][0] = 1;
        let num = nums[i] as u64 % mod_val;
        for j in 1..=m {
            nums_power[i][j] = nums_power[i][j - 1] * num % mod_val;
        }
    }

    let mut f = vec![vec![vec![vec![0u64; k + 1]; m * 2 + 1]; m + 1]; n];
    for j in 0..=m {
        f[0][j][j][0] = nums_power[0][j] * ifac[j] % mod_val;
    }

    for i in 0..n - 1 {
        for j in 0..=m {
            for p in 0..=m * 2 {
                for q in 0..=k {
                    let current = f[i][j][p][q];
                    let q2 = (p % 2) as usize + q;
                    if q2 > k {
                        break;
                    }

                    for r in 0..=(m - j) {
                        let p2 = (p / 2) as usize + r;
                        let add_val = current * nums_power[i + 1][r] % mod_val * ifac[r] % mod_val;
                        f[i + 1][j + r][p2][q2] = (f[i + 1][j + r][p2][q2] + add_val) % mod_val;
                    }
                }
            }
        }
    }

    let mut res = 0u64;
    for p in 0..=m * 2 {
        for q in 0..=k {
            if p.count_ones() as usize + q == k {
                res = (res + f[n - 1][m][p][q] * fac[m] % mod_val) % mod_val;
            }
        }
    }

    res as i32
}
