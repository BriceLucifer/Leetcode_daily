use std::collections::VecDeque;

pub struct Solution {}

impl Solution {
    pub fn oranges_rotting(grid: Vec<Vec<i32>>) -> i32 {
        // using bfs for level search
        let m = grid.len();
        let n = grid[0].len();
        let mut visited = vec![vec![false; n]; m];
        let mut step = 0;

        let directions = vec![(1, 0), (-1, 0), (0, 1), (0, -1)];
        let mut queue = VecDeque::new();
        let mut fresh = 0 as i32;

        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 2 {
                    queue.push_back((i, j));
                    visited[i][j] = true;
                }
                if grid[i][j] == 1 {
                    fresh += 1;
                }
            }
        }

        while !queue.is_empty() {
            let size = queue.len();
            let mut rotted = false;
            for _ in 0..size {
                let (x, y) = queue.pop_front().unwrap();
                for (dx, dy) in directions.iter() {
                    let (nx, ny) = (x as isize + dx, y as isize + dy);
                    if nx >= 0 && nx < m as isize && ny >= 0 && ny < n as isize {
                        if grid[nx as usize][ny as usize] == 1 && !visited[nx as usize][ny as usize]
                        {
                            queue.push_back((nx as usize, ny as usize));
                            visited[nx as usize][ny as usize] = true;
                            rotted = true;
                            fresh -= 1;
                        }
                    }
                }
            }
            if rotted {
                step += 1;
            }
        }

        if fresh > 0 { -1 } else { step }
    }
}

fn main() {
    let grid = vec![vec![2, 1, 1], vec![1, 1, 0], vec![0, 1, 1]];
    println!("{}", Solution::oranges_rotting(grid));
}
