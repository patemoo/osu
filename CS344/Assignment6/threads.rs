use std::thread;
use std::time::Duration;

fn count_to_val(tid: char, x: u32){
  for i in 1..x {
    println!("Thread {}, i is {}", tid, i);
    thread::sleep(Duration::from_millis(10));
  }
}

fn main(){

  let t1 = thread::spawn(|| count_to_val('a', 5));
  let t2 = thread::spawn(|| count_to_val('b', 10));
  let _r1 = t1.join().unwrap();
  let _r2 = t2.join().unwrap();
}