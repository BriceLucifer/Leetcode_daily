fn main() {
    let mut power = vec![1, 1, 3, 4];
    let mut result = maxium_total_damage(power);
    println!("{}", result);
    power = vec![7, 1, 6, 6];
    result = maxium_total_damage(power);
    println!("{}", result);
}

fn maxium_total_damage(power: Vec<i32>) -> i64 {
    // power = [1, 1, 3, 4]
    // return 6
    // explain: use 0, 1, 3 the damage is 1, 1, 4, total is 6
    // use dp

    // when use power[i] can not use power[i] - 2 and power[i] -1 and power[i] + 1 and power[i] + 2
}
