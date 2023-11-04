# Concurrency
#### Concurrency refers to the program's capabality to carry out several tasks at once. Supported by modern multithreading in C++ (threads library). Process executed by multiple threads, creating a control flow. Threads act independently however, this can sometimes lead to data race (condtion where 2 or more threads simultaneously access a variable or memory location). C++ stands out for its concurrent capabilities with lower than average overhead costs as well as its capacity for complex instruction.

### History
#### C++ 11 was first to introduce concurency, threading, memory model, mutex locks, tasks and condition variables. C++ 14 introduced reader-writer locks whereas parallel STL came up with C++ 17. 

### Concurrency vs Parallelism
#### In parallelism, we run multiple copies of the same program simultaneously, but they are executed on different data. Concurrent programming involves a shared memory location, and the different threads actually “read” the information provided by the previous threads.

### Concurrency Best Practices
#### 1) Minizing waiting 2) Minimizing data sharing of mutable data 3) Prefer Immutable data 4) Watch for deadlocks and livelocks

### Mutex (Mutual Exclusion)
#### A mutex is used to guard shared data such as a linked-list, an array, or any primitive type. A mutex allows only a single thread to access a resource or critical section. Once a thread acquires a mutex, all other threads attempting to acquire the same mutex are blocked until the first thread releases the mutex. [ One Customer at a time ] .

### Semaphore 
#### It is used for limiting access to a collection of resources. If a semaphore has given out all the permits it has, then any new thread that comes along requesting a permit will be blocked till an earlier thread with a permit returns it to the semaphore. Semaphores can also be used for signaling among threads. This is an important distinction as it allows threads to work towards completing a task cooperatively. [ N Fixed numbers of Customer at a time ]

### Applications
#### Multithreading programs and multithreaded applications are common in modern business systems. One example could be an email server, returning mailbox contents when requested by a user, By using a thread pool, the program can process as many user requests as possible without risking an overload. Another example could be a web crawler, which downloads pages across the web. By using multithreading, the developer would ensure that the web crawler is using as much of the hardware’s capability as possible to download and index multiple pages at once.
