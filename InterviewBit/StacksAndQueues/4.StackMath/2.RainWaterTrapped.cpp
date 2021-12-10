/*
Problem Description

Given an integer array A of non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.



Problem Constraints
1 <= |A| <= 100000



Input Format
The only argument given is integer array A.



Output Format
Return the total water it is able to trap after raining.



Example Input
Input 1:

 A = [0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1]
Input 2:

 A = [1, 2]


Example Output
Output 1:

 6
Output 2:

 0


Example Explanation
Explanation 1:

 
 In this case, 6 units of rain water (blue section) are being trapped.
Explanation 2:

 No water is trapped.
*/
/*
https://www.geeksforgeeks.org/trapping-rain-water/

Basic Insight: 
An element of the array can store water if there are higher bars on the left and right.
The amount of water to be stored in every element can be found out by finding the heights of bars on the 
left and right sides. 
The idea is to compute the amount of water that can be stored in every element of the array. 

Consider the array {3, 0, 2, 0, 4}, 
three units of water can be stored three indexes 1 and 2, 
and one unit of water at index 3, and three units of water at index 4. 
For Array[] = {3, 0, 2, 0, 4} 
Water stored = 0 + 3 + 1 + 3 + 0 = 7 

Method 1 : This is a simple solution to the above problem.
Approach: The idea is to traverse every array element and find the highest bars on the left and right sides. Take the smaller of two heights. The difference between the smaller height and height of the current element is the amount of water that can be stored in this array element.

Method 2: (Which is the same that I used):
Approach: In the previous solution, to find the highest bar on the left and right, array traversal is needed which reduces the efficiency of the solution. To make this efficient one must pre-compute the highest bar on the left and right of every bar in linear time. Then use these pre-computed values to find the amount of water in every array element.
Algorithm: 
Create two arrays left and right of size n. create a variable max_ = INT_MIN.
Run one loop from start to end. In each iteration update max_ as max_ = max(max_, arr[i]) and also assign left[i] = max_
Update max_ = INT_MIN.
Run another loop from end to start. In each iteration update max_ as max_ = max(max_, arr[i]) and also assign right[i] = max_
Traverse the array from start to end.
The amount of water that will be stored in this column is min(a,b) – array[i],(where a = left[i] and b = right[i]) add this value to total amount of water stored
Print the total amount of water stored.
*/
/*
Let's try our approach first.
So, we actually need the max from left and max from right.
Let's create two arrays, Left and Right which stores the max from left and right for every element.

So then, we will follow the above gkgs solution, where we will find the rainwater stored
for every element.

Return the sum
(It worked)
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
    int n =a.size();
    vector<int> Left(n, 0);
    vector<int> Right(n,0);
    int maxValue = a[0];
    // Create left array
    for(int i=1; i<n; i++){
        Left[i] = maxValue;
        maxValue = max(maxValue, a[i]);
    }

    maxValue = a[n-1];
    for(int i=n-2;i>=0; i--){
        Right[i] = maxValue;
        maxValue = max(maxValue, a[i]);
    }
    // cout << "Left array created is: " << endl;
    // printVector(Left);
    // cout << "Right array created is: " << endl;
    // printVector(Right);

    for(int i=0; i<n; i++){
        int left = Left[i];
        int right = Right[i];
        int valueToUse = min(left, right);
        if(a[i] >= valueToUse){
            continue;
        } else {
            result += valueToUse - a[i];
        }
    }
    return result;
}

int main(){
    vector<int> a = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Given array is: " << endl;
    printVector(a);

    int result = solve(a);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11