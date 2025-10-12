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
const MOD: i64 = 1000_000_007;

fn magical_sum(m: i32, k: i32, nums: Vec<i32>) -> i32 {
    // helper function
    let mod_add = |a: i64, b: i64| -> i64 {
        let mut s = a + b;
        if s >= MOD {
            s -= MOD;
        }
        s
    };

    // helper function

    // K = 5 1100111 => 指的是2进制是5个1
    let mut dp: Vec<Vec<Vec<i32>>> = Vec::new();
    dp[0][0][0] = 1;

    0
}

// Brain Kernighan 算法
// 每次执行 n & (n - 1)
// 计算binary多少个1
#[inline]
fn brain_kernighan(n: i32) -> i32 {
    let mut count = 0;
    let mut n = n;
    while n != 0 {
        n = n & (n - 1);
        count += 1;
    }
    return count;
}

#[inline]
fn mod_add(a: i64, b: i64) -> i64 {
    let mut s = a + b;
    if s >= MOD {
        s -= MOD;
    }
    s
}

#[inline]
fn mod_mul(a: i64, b: i64) -> i64 {
    ((a as i128 * b as i128) % (MOD as i128)) as i64
}
