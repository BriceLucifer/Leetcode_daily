use std::collections::VecDeque;

pub struct Solution {}

impl Solution {
    pub fn max_distance(grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len() as i32;
        let cols = grid[0].len() as i32;
        let mut queue = VecDeque::new();
        let directions = vec![(0, 1), (0, -1), (1, 0), (-1, 0)];
        let mut visited = vec![vec![false; cols as usize]; rows as usize];

        for i in 0..rows {
            for j in 0..cols {
                if grid[i as usize][j as usize] == 1 {
                    queue.push_back((i, j));
                    visited[i as usize][j as usize] = true;
                }
            }
        }

        if queue.is_empty() || queue.len() as i32 == rows * cols {
            return -1;
        }

        let mut step = 0;
        while !queue.is_empty() {
            let mut has_space = false;

            let size = queue.len();
            for _ in 0..size {
                let (x, y) = queue.pop_front().unwrap();
                for (dx, dy) in directions.iter() {
                    let (nx, ny) = (dx + x, dy + y);
                    if nx >= 0
                        && nx < rows
                        && ny >= 0
                        && ny < cols
                        && grid[nx as usize][ny as usize] == 0
                        && visited[nx as usize][ny as usize] == false
                    {
                        visited[nx as usize][ny as usize] = true;
                        queue.push_back((nx, ny));
                        has_space = true
                    }
                }
            }

            if has_space {
                step += 1;
            }
        }

        return step;
    }
}

fn main() {
    let result = Solution::max_distance(vec![vec![1, 0, 1], vec![0, 0, 0], vec![1, 0, 1]]);
    println!("{}", result)
}
