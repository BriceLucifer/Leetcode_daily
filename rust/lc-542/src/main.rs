use std::collections::VecDeque;

pub struct Solution {}

impl Solution {
    pub fn update_matrix(mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let m: isize = mat.len() as isize;
        let n: isize = mat[0].len() as isize;
        let mut result = vec![vec![0; n as usize]; n as usize];
        // 四个方向
        let directions = vec![(1, 0), (-1, 0), (0, 1), (0, -1)];
        // 访问节点
        let mut visited = vec![vec![0; n as usize]; m as usize];
        // 保存状态
        let mut queue: VecDeque<(usize, usize)> = VecDeque::new();

        for i in 0..m as usize {
            for j in 0..n as usize {
                if mat[i][j] == 0 {
                    queue.push_back((i, j));
                    visited[i][j] = 1;
                }
            }
        }

        while !queue.is_empty() {
            let size = queue.len();
            for _ in 0..size {
                let (x, y) = queue.pop_front().unwrap();
                for (dx, dy) in directions.iter() {
                    let nx = x as isize + dx;
                    let ny = y as isize + dy;

                    if nx >= 0 && nx < m && ny >= 0 && ny < n {
                        if mat[nx as usize][ny as usize] == 1
                            && visited[nx as usize][ny as usize] == 0
                        {
                            result[nx as usize][ny as usize] = result[x][y] + 1;
                            visited[nx as usize][ny as usize] = 1;
                            queue.push_back((nx as usize, ny as usize));
                        }
                    }
                }
            }
        }

        return result;
    }
}

fn main() {
    let result = Solution::update_matrix(vec![vec![0, 0, 0], vec![0, 1, 0], vec![1, 1, 1]]);
    for i in result {
        for j in i {
            print!("{j} ")
        }
        println!();
    }
}
