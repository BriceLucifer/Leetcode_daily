use std::iter::zip;

fn main() {
    let mut vec: Vec<Vec<i32>> = vec![
        vec![1, 1, 1, 1],
        vec![1, 1, 1, 1],
        vec![1, 1, 1, 1],
        vec![1, 1, 1, 1],
    ];
    let mut result = diagonal_sum(vec);
    println!("{}", result);
    println!("+++++++++++++++++");
    vec = vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]];
    result = diagonal_sum(vec);
    println!("{}", result)
}

// 正方形矩阵
fn diagonal_sum(mat: Vec<Vec<i32>>) -> i32 {
    if mat.len() == 1 {
        return mat[0][0];
    }

    let mut result = 0;
    let length = mat.len();
    for i in 0..length {
        result += mat[i][i];
        result += mat[i][length - i - 1]
    }

    if length % 2 == 0 {
        return result;
    }

    return result - mat[length / 2][length / 2];
}
