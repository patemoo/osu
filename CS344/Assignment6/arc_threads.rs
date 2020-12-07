use std::sync::Arc;
use std::sync::Mutex;
use std::thread;
use std::thread::JoinHandle;

fn increment_counter(thread_name : char, m : Arc<Mutex<i32>>, reps : i32){
  for _ in 0..reps {
    {
      // Acquire lock
      let mut val = m.lock().unwrap();
      *val +=1;
      if *val % 100 == 0 {
        // Print the thread name and value after every 100 increments of the counter
        println!("Thread {} val {}", thread_name, *val);
      }
    } 
    // lock is automatically given up here as val goes out of scope
  }
}


fn main(){
  // Create the mutex using an Arc
  let counter : Arc<Mutex<i32>> = Arc::new(Mutex::new(0));
  let iterations = 1000;

  // Vector to hold JoinHandle for the threads we spawn
  let mut handles : Vec<JoinHandle<()>> = Vec::new();

  {
    // Call the clone method of Arc to create a pointer to counter
    let x = Arc::clone(&counter);
    // Pass this pointer to the new thread
    let handle = thread::spawn(move || increment_counter('a', x, iterations));
    handles.push(handle);
  }

  {
    // Call the clone method of Arc to create another pointer to counter
    let y = Arc::clone(&counter);
    // Pass this pointer to another thread
    let handle = thread::spawn(move || increment_counter('b', y, iterations));
    handles.push(handle);
  }
  
  // Wait for the threads to terminate
  for handle in handles {
    handle.join().unwrap();
  }

  println!("Result: {}", *counter.lock().unwrap());
}
