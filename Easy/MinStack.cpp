/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2
 

Constraints:

-2^31 <= val <= 2^31 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
*/
#include <iostream>
#include <vector>

class MinStack
{
public:
    /** initialize your data structure here. */
    MinStack()
    {

    }
    
    void push(int val)
    {
        storage_.push_back(val);
    }
    
    void pop()
    {
        int nPos = storage_.size() - 1;
        storage_.erase(storage_.begin() + nPos);
    }
    
    int top()
    {
        return storage_.back();
    }
    
    int getMin()
    {
        std::vector<int>::iterator itr = storage_.begin();
        int min = *itr;
        for (itr = storage_.begin() + 1; itr != storage_.end(); itr++)
        {
            if (min > *itr)
                min = *itr;
        }

        return min;
    }
private:
    std::vector<int> storage_;
};

int main()
{   
    MinStack* obj = new MinStack();
    obj->push(-2);
    obj->push(0);
    obj->push(-3);
    int param_3 = obj->getMin();
    std::cout << "getMin() = " << param_3 << std::endl;
    obj->pop();
    int param_4 = obj->top();
    std::cout << "getMin() = " << param_4 << std::endl;
    int param_5 = obj->getMin();
    std::cout << "getMin() = " << param_5 << std::endl;
    return 0;
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */