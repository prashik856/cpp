/*
Problem Description

Given a string A of parantheses  ‘(‘ or ‘)’.

The task is to find minimum number of parentheses ‘(‘ or ‘)’ (at any positions) we must add to make the resulting parentheses string valid.

An string is valid if:

Open brackets must be closed by the corresponding closing bracket.
Open brackets must be closed in the correct order.


Problem Constraints
1 <= |A| <= 105

A[i] = '(' or A[i] = ')'



Input Format
First and only argument is an string A.



Output Format
Return a single integer denoting the minimumnumber of parentheses ‘(‘ or ‘)’ (at any positions) we must add in A to make the resulting parentheses string valid.



Example Input
Input 1:

 A = "())"
Input 2:

 A = "((("


Example Output
Output 1:

 1
Output 2:

 3


Example Explanation
Explanation 1:

 One '(' is required at beginning.
Explanation 2:

 Three ')' is required at end.
*/
/*
My solution worked.
Need to use stack.
1. Take care when the stack is empty at runtime.
2. Take care when the stack is not empty at the end.
3. Remember, we can put bracket anywhere.
*/

#include<bits/stdc++.h>
using namespace std;

int solve(string a){
    int result = 0;
    int n = a.size();
    stack<char> st;
    int count = 0;
    for(int i=0; i<n; i++){
        if(a[i] == '('){
            st.push(a[i]);
        } else if(!st.empty()){
            st.pop();
        } else if(st.empty()){
            count++;
        }
    }
    if(st.empty()){
        result = abs(count);
    } else {
        int low = 0;
        int high = 0;
        while(!st.empty()){
            char top = st.top();
            st.pop();
            if(top == '('){
                low++;
            } else {
                high++;
            }
        }
        count += abs(low - high);
    }
    // cout << "Value of count is: " << count << endl;
    result = abs(count);
    return result;
}

int main(){
    string a = "((((()()()()()()((()()())))))))))";
    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}