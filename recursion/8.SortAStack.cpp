/**
 * Sort a Stack
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

stack<int> putValue(stack<int> input, int value) {
    // if empty or highest element
    if(input.empty() || value < input.top()) {
        input.push(value);
        return input;
    }

    // save top element
    int topElement = input.top();
    input.pop();

    // put the element in the proper place
    input = putValue(input, value);

    // push the top element
    input.push(topElement);
    return input;
}

stack<int> sortStack(stack<int> input) {
    if(input.empty()) {
        return input;
    }

    int topElement = input.top();
    input.pop();

    input = sortStack(input);

    input = putValue(input, topElement);

    return input;
}

int main() {
    stack<int> st = stack<int>({2,3,7,0,6,4,5,9,1});
    cout << "Input Stack: " << endl;
    printStack(st);

    stack<int> output = sortStack(st);
    cout << "Output stack: " << endl;
    printStack(output);

    return 0;
}