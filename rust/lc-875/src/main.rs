pub struct Solution {}

impl Solution {
    pub fn min_eating_speed(piles: Vec<i32>, h: i32) -> i32 {
        let mut right = 0_isize;
        for i in piles.iter() {
            if *i as isize > right {
                right = *i as isize;
            }
        }
        let mut left = 1;

        let check = |k: isize| -> isize {
            let mut hours = 0;
            for i in piles.iter() {
                hours += *i as isize / k;
                if *i as isize % k > 0 {
                    hours += 1;
                }
            }
            return hours as isize;
        };

        while left <= right {
            let mid = (left + right) >> 1;
            if (check(mid) <= h as isize) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left as i32;
    }
}

fn main() {
    println!("Hello, world!");
}
