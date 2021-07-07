// https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=stacks-queues
// Explanation in discussion: https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks/forum
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
  
    public:
        stack<int> stack_newest_on_top, stack_oldest_on_top;   
        void push(int x) {
            stack_newest_on_top.push(x);
        }

        void pop() {
            if(!stack_oldest_on_top.empty()){
                stack_oldest_on_top.pop();
            } else {
                // put all elements from stack_newest_on_top to 
                // stack_oldest_on_top
                while(!stack_newest_on_top.empty()){
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
                stack_oldest_on_top.pop();
            }
        }

        int front() {
            int result = -1;
            if(!stack_oldest_on_top.empty()){
                result = stack_oldest_on_top.top();
            } else {
                // put all elements from stack_newest_on top
                // to stack_oldest_on_top
                while(!stack_newest_on_top.empty()){
                    stack_oldest_on_top.push(stack_newest_on_top.top());
                    stack_newest_on_top.pop();
                }
                result = stack_oldest_on_top.top();
            }
            return result;
        }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}