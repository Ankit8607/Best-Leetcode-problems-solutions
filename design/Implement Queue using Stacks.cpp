// https://leetcode.com/problems/implement-queue-using-stacks/description/?envType=daily-question&envId=2024-01-29

class MyQueue {
public:
    int n;
    stack<int>a,b;
    MyQueue() {
        n=0;
    }
    
    void push(int x) {
        a.push(x);
        n++;
    }
    
    void settle(){
        while(!a.empty()) b.push(a.top()), a.pop();
    }

    int pop() {
        if(b.empty()) settle();
        n--;
        int t=b.top();
        b.pop();
        return t;
    }
    
    int peek() {
        if(b.empty()) settle();
        return b.top();
    }
    
    bool empty() {
        return n==0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
