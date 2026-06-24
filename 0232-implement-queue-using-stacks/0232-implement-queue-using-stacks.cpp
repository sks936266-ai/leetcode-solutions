#include <stack>
using namespace std;

class MyQueue {
private:
    stack<int> input;
    stack<int> output;

public:
    MyQueue() {
        // Constructor blank rehne do
    }
    
    // O(1) Push
    void push(int x) {
        input.push(x);
    }
    
    // Amortized O(1) Pop
    int pop() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        int val = output.top();
        output.pop();
        return val;
    }
    
    // Amortized O(1) Peek / Top
    int peek() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
        // FIXED: Condition ke baad direct return
        return output.top(); 
    }
    
    // Empty check
    bool empty() {
        return input.empty() && output.empty();
    }
};