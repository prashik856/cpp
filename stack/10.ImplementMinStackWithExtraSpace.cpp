/**
 * Implement Minimum stack with extra space.
 * 
 * Design a datastructure SpecialStack that supports all the stack operations, like push(),
 * pop(), isEmpty(), isFull() and an additional operation, getMin(),
 * which should return minimum element from the stack.
 * All these operations of the stack should be O(1).
 * 
 * To implement SpecialStack, you should only use standard Stack data structure and no
 * other datastructure like arrays, list, ... etc.
 * 
 * We can do this using a supporting stack datastructure.
 * We can have a supporting stack which will only store minimum element.
 */
#include <iostream>
#include<stack>
using namespace std;

class specialStack {
    private:
        stack<int> normalStack;
        stack<int> supportingStack;

    public:
        specialStack() { 
            normalStack = stack<int>();
            supportingStack = stack<int>();
        }

        void push(int item) {
            normalStack.push(item);
            if(supportingStack.empty()) {
                // supporting stack is empty
                supportingStack.push(item);
            } else {
                // top value of supporting stack is greater than item
                // equal will handle duplicates
                if(supportingStack.top() >= item) {
                    supportingStack.push(item);
                }
            }
        }

        void pop() {
            int top = normalStack.top();
            normalStack.pop();

            if(top == supportingStack.top()) {
                supportingStack.pop();
            }
        }

        int top() {
            return normalStack.top();
        }

        int getMin() {
            if(normalStack.size() > 0) {
                return supportingStack.top();
            } else {
                throw invalid_argument("Cannot get minimum element when stack is empty");
            }            
        }

        bool empty() {
            return normalStack.empty();
        }
};

int main() {
    specialStack st = specialStack();

    st.push(10);
    st.push(15);
    st.push(5);
    st.push(-1);
    st.push(25);

    cout << st.getMin() << endl;
    st.pop();
    cout << st.getMin() << endl;
    st.pop();
    cout << st.getMin() << endl;
    st.pop();
    st.pop();
    st.pop();
    st.top();
    cout << st.getMin() << endl;

    return 0;
}