fn main() {
    let mut energy = vec![5, 2, -10, -5, 1];
    let mut k = 3;
    let mut max = maximum_energy(energy, k);
    println!("{}", max);
    println!("=============");
    energy = vec![5, -10, 4, 3, 5, -9, 9, -7];
    k = 2;
    max = maximum_energy(energy, k);
    println!("{}", max);
    println!("=========");
    energy = vec![2, 8];
    k = 1;
    max = maximum_energy(energy, k);
    println!("{}", max);
}

pub fn maximum_energy(energy: Vec<i32>, k: i32) -> i32 {
    // 全是负数

    // 其实这块可以优化
    // 如果不需要这块去 存index 那么就直接存max value就好
    // k + i < energy.len
    // e.g:
    //      0 1 2 3 4 k = 3
    //      所以 从 倒数2 3 4开始 就已经没办法 i + k 了

    let n = energy.len();
    let k = k as usize;
    let mut max_val = i32::MIN;

    for i in 0..n {
        let mut index = i;
        let mut result = energy[index];
        while index + k < n {
            result += energy[index + k];
            index += k;
        }
        if result > max_val {
            max_val = result;
        }
    }

    max_val

    // return value.iter().max().unwrap().clone();

    // #[derive(Hash, Debug, Clone, Copy, PartialEq, Eq)]
    // struct Magic {
    //     value: i32,           // return max value
    //     pair: (usize, usize), // return the index pair.1 - pair.0 = k
    // }

    // let mut magic_set = Vec::new();

    // for i in 0..energy.len() {
    //     if energy.len() - i > k as usize {
    //         magic_set.push(Magic {
    //             value: energy[i] + energy[i + k as usize],
    //             pair: (i, i + k as usize),
    //         });
    //     } else {
    //         magic_set.push(Magic {
    //             value: energy[i],
    //             pair: (i, 0),
    //         });
    //     }
    // }

    // let mut max = magic_set[0];
    // for magic in magic_set {
    //     if magic.value > max.value {
    //         max = magic
    //     } else {
    //         continue;
    //     }
    // }

    // return max.value;
}

/*
 * energy = [5, 2, -10, -5, 1] k = 3
 * return 3 => [2, 1] (1, 4)
 */
