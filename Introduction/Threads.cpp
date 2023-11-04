/*
  Threads are lightweight process and forms basic unit of CPU Utilization. Having multiple threads can favour to perform various tasks at the same time. A Thread have its own PC (program counter), register set and stack.
  Shares resources with other threads of the same process, code section, files, signals and data section.

  -> Can be introduced by calling fork() method.
  -> Generates 2^n-1 child processed.
  -> 2 types of threads : User Threads (by Users) and Kernel Threads (by OS) 
*/

/// Single Thread Example

void print(int n, const string &str)  {  
    cout<<"Printing integer: "<<n<<endl;  
    cout<<"Printing string: "<<str<<endl;  
} 

int main() {
    thread t1(print, 10, "Aditya Jamwal");
    t1.join();
return 0;
}

/// Multi Thread Example

#include <bits/stdc++.h>
using namespace std;

void print(int num, const string &str){
    string msg=to_string(num)+":"+str;
    cout<<msg<<endl;
}

int main(){
    vector<thread> threads;
    vector<string> str={"Aditya","Jamwal","B.Tech","CSE","JIIT"};
    for(int i=0;i<str.size();i++){
        threads.push_back(thread(print,i,str[i]));
    }  
    for(auto &th : threads){
        th.join();
    }
return 0;
}
