/// Threads, Synchronization,

// Creating Threads

#include<bits/stdc++.h>
#include<thread>                // For threads
using namespace std;

void makeThread(){
    cout<<" Next Thread "<<this_thread::get_id()<<endl;
}

int main(){
    thread t(makeThread);
    cout<<" Main Thread "<<this_thread::get_id()<<endl;
    t.join();
  return 0;
}

// Synchronization using mutex

#include<iostream>
#include<thread>               
#include<mutex>                 
using namespace std;

mutex m;
int counter=0;

void increase(){
    m.lock();
    counter++;
    m.unlock();
}

int main(){
    thread t1(increase);
    thread t2(increase);
    thread t3(increase);
    t1.join();
    t2.join();
    t3.join();
    cout<<"Total: "<<counter<<endl;
    
  return 0;
}

// Synchronization with condition variables

#include<bits/stdc++.h>
#include<mutex>
#include<thread>
#include<condition_variable>
using namespace std;

mutex m;
condition_variable cv;
int n;
vector<int> arr;

void producer() {
    for (int i = 0; i < n; i++) {
        unique_lock<mutex> ul(m);
        arr.push_back(i);
        cv.notify_one();
    }
}

void consumer() {
    for (int i = 0; i < n; i++) {
        unique_lock<mutex> ul(m);
        cv.wait(ul);
        int value = arr.back();
        arr.pop_back();
        cout << "Consumed: " << value << endl;
    }
}

int main() {
    cin >> n;

    thread producer_thread(producer);
    thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    return 0;
}
