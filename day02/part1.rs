use std::fs;

fn is_ordered(numbers: &[i32]) -> bool
{
    let is_increasing = numbers.windows(2).all(|w| w[0] < w[1]);
    let is_decreasing = numbers.windows(2).all(|w| w[0] > w[1]);

    is_increasing || is_decreasing
}

fn check_range(numbers: &[i32]) -> bool
{
    numbers.windows(2).all(|w| (1..=3).contains(&(w[1] - w[0]).abs()))
}

fn main() {
    let content = fs::read_to_string("input.txt")
        .expect("error with input file.");

    let mut result = 0;

    for lines in content.split('\n')
    {

        let values: Vec<i32> = lines.split_whitespace().map(|x| x.parse().expect("Invalid number")).collect();

        if is_ordered(&values) && check_range(&values)
        {
            result += 1;
        }
    }

    println!("{}", result);
}
