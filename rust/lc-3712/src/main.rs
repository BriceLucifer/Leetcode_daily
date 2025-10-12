use std::collections::HashMap;

fn main() {
    let vec = vec![1, 2, 3, 4, 5];
    let k = 2;
    println!("{}", sum_divisible_by_k(vec, k));
}

fn sum_divisible_by_k(nums: Vec<i32>, k: i32) -> i32 {
    // use hashmap to collect the count of each element
    let mut hashmap: HashMap<i32, i32> = HashMap::new();

    // collecting counts
    for i in nums {
        let count = hashmap.entry(i).or_insert(0);
        *count += 1;
    }

    // set up a buffer to return a result
    let mut buffer = 0;
    for (key, value) in hashmap {
        // if value % k == 0 then add up to buffer
        if value % k == 0 {
            buffer += key * value;
        }
    }

    buffer
}
