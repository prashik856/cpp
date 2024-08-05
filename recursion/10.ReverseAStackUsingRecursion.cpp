/**
 * Reverse a stack using recursion
 * 
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

int main() {
    stack<int> st = stack<int>({2,3,7,0,6,4,5,9,1,10});
    cout << "Input Stack: " << endl;
    printStack(st);

    queue<int> newQueue = queue<int>();

    stack<int> output = reverseStack(st, newQueue);
    cout << "Output Stack: " << endl;
    printStack(output);

    return 0;
}