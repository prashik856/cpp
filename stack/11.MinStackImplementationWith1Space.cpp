/**
 * Minimum Stack Implementation with O(1) space.
 * 
 * Design a Data Structure SpecialStack that supports all the stack operations like push(), 
 * pop(), isEmpty(), isFull() and an additional operation getMin() which should 
 * return minimum element from the SpecialStack. 
 * All these operations of SpecialStack must be O(1). 
 * To implement SpecialStack, you should only use standard Stack data structure and 
 * no other data structure like arrays, list, .. etc.
 * 
 * This time, we will try to implement it using only O(1) space.
 * 
 * O(1) is usually only a variable. [or a list of variables]
 * 
 * So, for now, we will create a variable, int minEle.
 * Using this, we will have space complexity of O(1).
 * 
 * We will also have our normal stack data structure.
 */
#include <iostream>
#include<stack>
using namespace std;

class SpecialStack {
    private:
        stack<int> st;
        int minValue;
    
    public:
        SpecialStack() {
            st = stack<int>();
            minValue = -1;
        }

        bool empty() {
            return st.empty();
        }

        void push(int item) {
            if(st.empty()) {
                st.push(item);
                this->minValue = item;
            } else {
                if(item >= this->minValue) {
                    st.push(item);
                } else {
                    // we have a new minimum here
                    int itemToPush = 2 * item - this->minValue;
                    this->minValue = item;
                    st.push(itemToPush);
                }
            }
        }

        int top() {
            if(st.empty()) {
                return -1;
            }

            int top = st.top();
            if(top < this->minValue) {
                // we have an anomaly
                // actual value stored here is minValue
                return this->minValue;
            }
            return top;
        }

        void pop() {
            int top = st.top();
            if(top < this->minValue) {
                // anomaly
                // calculate previous minValue
                int previousMinValue = 2 * this->minValue - top;
                st.pop();
                this->minValue = previousMinValue;
            } else {
                st.pop();
            }
        }

        int size() {
            return st.size();
        }

        int getMin() {
            return this->minValue;
        }
};

int main() {
    SpecialStack st = SpecialStack();
    st.push(10);
    st.push(5);

    cout << "Top: " << st.top() << endl;
    cout << "Min Value: " << st.getMin() << endl;

    st.push(20);
    st.push(3);
    cout << "Top: " << st.top() << endl;
    cout << "Min Value: " << st.getMin() << endl;

    st.push(15);
    st.push(5);
    cout << "Top: " << st.top() << endl;
    cout << "Min Value: " << st.getMin() << endl;

    st.push(1);
    st.push(50);
    cout << "Top: " << st.top() << endl;
    cout << "Min Value: " << st.getMin() << endl;

    st.pop();
    st.pop();
    cout << "Top: " << st.top() << endl;
    cout << "Min Value: " << st.getMin() << endl;

    return 0;
}