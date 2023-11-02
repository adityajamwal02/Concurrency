/*
Suppose you are given the following code:
class FooBar {
  public void foo() {
    for (int i = 0; i < n; i++) {
      print("foo");
    }
  }

  public void bar() {
    for (int i = 0; i < n; i++) {
      print("bar");
    }
  }
}
The same instance of FooBar will be passed to two different threads:
thread A will call foo(), while
thread B will call bar().
Modify the given program to output "foobar" n times.

Example 1:
Input: n = 1
Output: "foobar"
Explanation: There are two threads being fired asynchronously. One of them calls foo(), while the other calls bar().
"foobar" is being output 1 time.

Example 2:
Input: n = 2
Output: "foobarfoobar"
Explanation: "foobar" is being output 2 times.
*/

class FooBar {
private:
    int n;
    mutex m;
    condition_variable cv;
    bool isFoo;

public:
    FooBar(int n) {
        this->n = n;
        isFoo=true;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
        	// printFoo() outputs "foo". Do not change or remove this line.
            while(!isFoo){
                cv.wait(lock);
            }
        	printFoo();
            isFoo=false;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
        	// printBar() outputs "bar". Do not change or remove this line.
            while(isFoo){
                cv.wait(lock);
            }
        	printBar();
            isFoo=true;
            cv.notify_one();
        }
    }
};
