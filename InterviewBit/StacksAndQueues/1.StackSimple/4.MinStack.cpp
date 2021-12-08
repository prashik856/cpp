/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) – Push element x onto stack.
pop() – Removes the element on top of the stack.
top() – Get the top element.
getMin() – Retrieve the minimum element in the stack.
Note that all the operations have to be constant time operations.

Questions to ask the interviewer :

Q: What should getMin() do on empty stack? 
A: In this case, return -1.

Q: What should pop do on empty stack? 
A: In this case, nothing. 

Q: What should top() do on empty stack?
A: In this case, return -1
NOTE : If you are using your own declared global variables, make sure to clear them out in the constructor.
*/
/*
Nice and easy:
Take care when popping any element, if the top element is our minValue element, we need to update our minValue.
Else, a normal stack.
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> minStack;
int minValue = INT_MAX;
class MinStack{
    public:
        MinStack(){
            minStack.clear();
            minValue = INT_MAX;
        }
        void push(int x);
        void pop();
        int top();
        int getMin();
};

MinStack::MinStack() {
    minStack.clear();
    minValue = INT_MAX;
}

void MinStack::push(int x) {
    minStack.push_back(x);
    minValue = min(minValue, x);
}

void MinStack::pop() {
    if(minStack.size() == 0){
        minValue = INT_MAX;
        return;
    }

    int top = MinStack::top();
    if(minValue == top){
        // we need to update this minimum value
        minValue = INT_MAX;
        for(int i=0; i<minStack.size()-1; i++){
            minValue = min(minValue, minStack[i]);
        }
    }

    minStack.pop_back();
}

int MinStack::top() {
    if(minStack.size() == 0){
        return -1;
    }
    return minStack.back();
}

int MinStack::getMin() {
    if(minValue == INT_MAX){
        return -1;
    }
    return minValue;
}

int main(){
    MinStack myMinStack;

    myMinStack.push(1);
    myMinStack.push(2);
    return 0;
}