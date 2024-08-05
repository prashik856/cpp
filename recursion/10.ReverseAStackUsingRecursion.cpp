/**
 * Reverse a stack using recursion
 * 
 * I have used a queue here.
 * 
 * can we do without extra space?
 * Can we done with another recursion step.
 */
#include<bits/stdc++.h>
using namespace std;

void printStack(stack<int> st) {
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}

stack<int> reverseStack(stack<int> input, queue<int> &newQueue) {
    if(input.empty() && !newQueue.empty()) {
        // put queue top element in stack
        int queueFront = newQueue.front();

        // pop queue
        newQueue.pop();

        // push in input
        input.push(queueFront);
        
        return input;
    }

    int topElement = input.top();

    // pop stack
    input.pop();

    // push in queue
    newQueue.push(topElement);

    // call reverse stack
    input = reverseStack(input, newQueue);

    // Assuming input is now reversed, we put queue front in input
    if(!newQueue.empty()) {
        // get queue front
        int queueFront = newQueue.front();
        // pop queue
        newQueue.pop();

        // push into input
        input.push(queueFront);
    }

    return input;
}

stack<int> putElement(stack<int> input, int value) {
    if(input.empty()) {
        input.push(value);
        return input;
    }

    int topValue = input.top();
    input.pop();

    input = putElement(input, value);

    // we have put our value at the bottom of the stack.
    input.push(topValue);

    return input;
}

stack<int> reverseStackWithoutQueue(stack<int> input) {
    if(input.empty()) {
        return input;
    }

    int topElement = input.top();
    input.pop();

    input = reverseStackWithoutQueue(input);

    input = putElement(input, topElement);

    return input;
}

int main() {
    stack<int> st = stack<int>({2,3,7,0,6,4,5,9,1,10});
    cout << "Input Stack: " << endl;
    printStack(st);

    queue<int> newQueue = queue<int>();

    stack<int> output = reverseStack(st, newQueue);
    cout << "Output Stack: " << endl;
    printStack(output);

    // Does not use extra memory
    output = reverseStackWithoutQueue(st);
    cout << "Output Stack 2: " << endl;
    printStack(output);

    return 0;
}