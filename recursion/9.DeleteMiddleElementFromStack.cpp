/**
 * Delete Middle Element from the stack
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

stack<int> removeMiddleElement(stack<int> input, int element) {
    // base condition
    if(element == 0) {
        input.pop();
        return input;
    }

    // save top element
    int topElement = input.top();

    // pop 
    input.pop();

    // get new input
    input = removeMiddleElement(input, element - 1);

    // put top element back
    input.push(topElement);

    return input;
}

int main() {
    stack<int> st = stack<int>({2,3,7,0,6,4,5,9,1,10});
    cout << "Input Stack: " << endl;
    printStack(st);

    // if odd, remove the middle element
    // if even, remove the size/2 + 1th element.
    int size = st.size();
    int element = size/2;
    cout << "Element Value: " << element << endl;

    stack<int> output = removeMiddleElement(st, element);
    cout << "Output: " << endl;
    printStack(output);

    return 0;
}