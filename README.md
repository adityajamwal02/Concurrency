# Concurrency
#### Concurrency refers to the program's capabality to carry out several tasks at once. Supported by modern multithreading in C++ (threads library). Process executed by multiple threads, creating a control flow. Threads act independently however, this can sometimes lead to data race (condtion where 2 or more threads simultaneously access a variable or memory location). C++ stands out for its concurrent capabilities with lower than average overhead costs as well as its capacity for complex instruction.

### History
#### C++ 11 was first to introduce concurency, threading, memory model, mutex locks, tasks and condition variables. C++ 14 introduced reader-writer locks whereas parallel STL came up with C++ 17. 

### Concurrency vs Parallelism
#### In parallelism, we run multiple copies of the same program simultaneously, but they are executed on different data. Concurrent programming involves a shared memory location, and the different threads actually “read” the information provided by the previous threads.
