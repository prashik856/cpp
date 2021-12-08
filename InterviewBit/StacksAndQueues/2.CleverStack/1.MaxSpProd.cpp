/*
Problem Description

You are given an array A containing N integers. The special product of each ith integer in this array is defined as the product of the following:

LeftSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (i>j). If multiple A[j]'s are present in multiple positions, the LeftSpecialValue is the maximum value of j.
RightSpecialValue: For an index i, it is defined as the index j such that A[j]>A[i] and (j>i). If multiple A[j]'s are present in multiple positions, the RightSpecialValue is the minimum value of j.
Write a program to find the maximum special product of any integer in the array.

NOTE:  As the answer can be large, output your answer modulo 109 + 7.



Problem Constraints
1 <= N <= 105
 
1 <= A[i] <= 109



Input Format
First and only argument is an integer array A.



Output Format
Return an integer denoting the maximum special product of any integer.



Example Input
Input 1:

 A = [1, 4, 3, 4]
Input 2:

 A = [10, 7, 100]


Example Output
Output 1:

 3
Output 2:

 0


Example Explanation
Explanation 1:

 For A[2] = 3, LeftSpecialValue is 1 and RightSpecialValue is 3.
 So, the ans is 1*3 = 3.
 
Explanation 2:

 There is not any integer having maximum special product > 0. So, the ans is 0.
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/find-the-nearest-smaller-numbers-on-left-side-in-an-array/
Rather than st.top() >= arr[i], we do st.top() <= arr[i].
I don't know why this solution is not working, might work in python though.
But I don't wanna.
*/

#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void print2DVector(vector< vector<int> > arr){
    for(int i=0; i<arr.size(); i++){
        for(int j=0; j<arr[i].size(); j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printStrings(vector<string> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << endl;
    }
}

class ListNode{
    public: 
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createLinkedList(vector<int> arr){
    ListNode *head = 0;
    int n = arr.size();
    for(int i=0; i<n; i++){
        int value = arr[i];
        ListNode *newNode = new ListNode(value);

        if(head == 0){
            head = newNode;
        } else {
            ListNode *temp = head;
            while(temp->next != 0){
                temp = temp -> next;
            }
            temp -> next = newNode;
        }
    }
    return head;
}

void printLinkedList(ListNode *head){
    ListNode *temp = head;
    while(temp != 0){
        cout << temp->val << " ";
        temp = temp -> next;
    }
    cout << endl;
}


int getLinkedListLength(ListNode *head){
    ListNode *temp = head;
    int count = 0;
    while(temp !=0){
        temp = temp -> next;
        count++;
    }
    return count;
}

int solve(vector<int> a){
    int result = 0;
    int n = a.size();

    stack<int> st1;
    vector<long> left(n, 0);
    for(int i=0; i<n; i++){
        int value = a[i];

        while(!st1.empty()){
            int topIndex = st1.top();
            int topValue = a[topIndex];
            if(topValue <= value){
                st1.pop();
            } else {
                break;
            }
        }

        if(st1.empty()){
            left[i] = 0;
        } else {
            left[i] = st1.top();
        }

        st1.push(i);
    }

    stack<int> st2;
    vector<long> right(n,0);
    for(int i=n-1; i>=0; i--){
        int value = a[i];

        while(!st2.empty()){
            int topIndex = st2.top();
            int topValue = a[topIndex];

            if(topValue <= value){
                st2.pop();
            } else {
                break;
            }
        }

        if(st2.empty()){
            right[i] = 0;
        } else {
            right[i] = st2.top();
        }

        st2.push(i);
    }

    // cout << "Obtained left array is: " << endl;
    // printVector(left);

    // cout << "Obtained right array is: " << endl;
    // printVector(right);

    long long tempResult = 0;
    long long MOD = 1000000009;
    for(int i=0; i<n; i++){
        long long currentMul = (long long)left[i] * (long long)right[i];
        tempResult = max(tempResult, currentMul);
        long long modValue = tempResult % MOD;
        result = modValue;
    }

    return result;
}

int main(){
    vector<int> a = {7, 5, 7, 9, 8, 7 };
    cout << "Given array is: " << endl;
    printVector(a);

    int result = solve(a);
    cout<< "Result is: " << result << endl;
    return 0;
}

// g++ -std=c++11