use std::cmp::max;

pub struct Solution();

impl Solution {
    pub fn dfs(grid: &Vec<Vec<i32>>, visited: &mut Vec<Vec<bool>>, i: isize, j: isize) -> usize {
        let m = grid.len() as isize;
        let n = grid[0].len() as isize;

        if i < 0 || i >= m || j < 0 || j >= n {
            return 0;
        }

        let (x, y) = (i as usize, j as usize);
        if visited[x][y] || grid[x][y] == 0 {
            return 0;
        }
        visited[x][y] = true;

        return 1
            + Self::dfs(grid, visited, i + 1, j)
            + Self::dfs(grid, visited, i - 1, j)
            + Self::dfs(grid, visited, i, j + 1)
            + Self::dfs(grid, visited, i, j - 1);
    }

    pub fn max_area_of_island(grid: Vec<Vec<i32>>) -> i32 {
        let mut size: usize = 0;
        let m = grid.len();
        let n = grid[0].len();
        let mut visited = vec![vec![false; n]; m];

        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == 1 && !visited[i][j] {
                    let s = Self::dfs(&grid, &mut visited, i as isize, j as isize);
                    size = max(size, s);
                }
            }
        }

        return size as i32;
    }
}

fn main() {
    let grid = vec![
        vec![0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
        vec![0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0],
        vec![0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0],
        vec![0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0],
        vec![0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0],
    ];
    let result = Solution::max_area_of_island(grid);
    println!("{result}");
}
