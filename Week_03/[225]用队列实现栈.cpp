//使用队列实现栈的下列操作： 
//
// 
// push(x) -- 元素 x 入栈 
// pop() -- 移除栈顶元素 
// top() -- 获取栈顶元素 
// empty() -- 返回栈是否为空 
// 
//
// 注意: 
//
// 
// 你只能使用队列的基本操作-- 也就是 push to back, peek/pop from front, size, 和 is empty 这些操作是合
//法的。 
// 你所使用的语言也许不支持队列。 你可以使用 list 或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。 
// 你可以假设所有操作都是有效的（例如, 对一个空的栈不会调用 pop 或者 top 操作）。 
// 
// Related Topics 栈 设计 
// 👍 193 👎 0


//leetcode submit region begin(Prohibit modification and deletion)

class MyStack {
public:
    queue<int> qi; //主队列
    queue<int> qt; //辅助队列

    /** Initialize your data structure here. */
    MyStack() {

    }


    /** Push element x onto stack. */
    void push(int x) {
        while(qi.size()) { //将qi中的元素全部搬至qt
            qt.push(qi.front());
            qi.pop();
        }
        qi.push(x);  //插入新元素
        while(qt.size()) {  //将qt中的元素全部搬回qi
            qi.push(qt.front());
            qt.pop();
        }
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = qi.front();
        qi.pop();
        return temp;
    }


    /** Get the top element. */
    int top() {
        return qi.front();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return qi.empty();
    }
};



/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
//leetcode submit region end(Prohibit modification and deletion)
