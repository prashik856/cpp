/*
Problem Description

Given a sorted array A containing N integers both positive and negative.

You need to create another array containing the squares of all the elements in A and return it in non-decreasing order.

Try to this in O(N) time.


Problem Constraints
1 <= N <= 105.

-103 <= A[i] <= 103



Input Format
First and only argument is an integer array A.



Output Format
Return a integer array as described in the problem above.



Example Input
Input 1:

 A = [-6, -3, -1, 2, 4, 5]
Input 2:

 A = [-5, -4, -2, 0, 1]


Example Output
Output 1:

 [1, 4, 9, 16, 25, 36]
Output 2:

 [0, 1, 4, 16, 25]
*/
/*
nlog(n) solution approach: Make use of priority queue.

O(n) solution:
Make use of stack to store all the negative absolute values (These will be reverse sorted form).

From the positive integer (which are already sorted), 
    if stack is non empty
        find if positive integer element is smaller or the stack top element
        put the square of smaller value inside result.
        Take care of indices.
    if stack is empty
        push inside current array element square 

Check if stack is empyt:
    if not, push all the squares of elements inside the result.
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr) {
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

vector<int> solve(vector<int> arr) {
    vector<int> result;
    // first put positive negative integers inside the stack

    stack<int> st;
    int index = 0;
    for(int i=0; i<arr.size(); i++){
        if(arr[i] < 0) {
            st.push(abs(arr[i]));
        } else {
            // first positive
            index = i;
            break;
        }
    }

    // cout << "Stack size: " << st.size() << endl;
    // cout << "Positive integer index: " << index << endl;

    for(int i=index; i<arr.size(); i++) {
        int currentValue = arr[i];
        if(!st.empty()) {
            int topStack = st.top();

            if(currentValue < topStack) {
                result.push_back(currentValue * currentValue);
            } else {
                result.push_back(topStack*topStack);
                i--;
                st.pop();
            }
        } else {
            result.push_back(currentValue*currentValue);
        }
        
    }

    while(!st.empty()){
        int topStack = st.top();
        result.push_back(topStack*topStack);
        st.pop();
    }

    return result;
}

int main() {
    int t;
    cin >> t;
    for(int z=0; z<t; z++) {
        int n; 
        cin >> n;
        cout << n << endl;
        vector<int> arr;
        cout << "Given input array is: " << endl;
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            arr.push_back(temp);
            cout << temp << " ";
        }
        cout << endl;

        vector<int> result = solve(arr);
        cout << "Result: " << endl;
        printVector(result);
        cout << endl;
    }
    return 0;
}