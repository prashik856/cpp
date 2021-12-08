/*
Problem Description

Given an array of integers A .

A represents a histogram i.e A[i] denotes height of the ith histogram's bar. Width of each bar is 1.

Find the area of the largest rectangle formed by the histogram.



Problem Constraints
1 <= |A| <= 100000

1 <= A[i] <= 1000000000



Input Format
The only argument given is the integer array A.



Output Format
Return the area of largest rectangle in the histogram.



Example Input
Input 1:

 A = [2, 1, 5, 6, 2, 3]
Input 2:

 A = [2]


Example Output
Output 1:

 10
Output 2:

 2


Example Explanation
Explanation 1:

The largest rectangle has area = 10 unit. Formed by A[3] to A[4].
Explanation 2:

Largest rectangle has area 2.
*/
/*
We know this solution, let's try it out ourselves.

Yeah... we kinda remembered the code!

We use two stacks, index or height
And we use lastIndex, and bool of useLastIndex.

while our current array value is less than heigh.top(), 
we will calculate max area here.
For every value less than height.top() and stack is non empty,
    we let useLastIndex to true
    set lastIndex to index.top();
    calculate height = height.top()
    width = i - index.top()
    area = heightValue*widthValue
    result = max(result, area)
    index.pop()
    height.pop()
if stack is empty
    if we are using lastindex
        if lastindex < i -> push lastindex
        else push i
    else push our index i
    push heigh a[i]
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
    a.push_back(0);

    int result = 0;
    int n = a.size();
    stack<int> index;
    stack<int> height;
    int lastIndex = -1;
    bool useLastIndex = false;

    for(int i=0; i<n; i++){
        useLastIndex = false;
        int value = a[i];
        while(!index.empty() && value < height.top()){
            useLastIndex = true;
            lastIndex = index.top();

            int heightValue = height.top();
            int widthValue = i - lastIndex;
            int area = heightValue * widthValue;
            result = max(result, area);

            index.pop();
            height.pop();
        }

        if(index.empty() || a[i] > height.top()){
            if(useLastIndex){
                if(lastIndex < i){
                    index.push(lastIndex);
                } else {
                    index.push(i);
                }
            } else {
                index.push(i);
            }
            height.push(a[i]);
        }
    }


    return result;
}

int main(){
    vector<int> a = {2};
    cout << "Given array is: " << endl;
    printVector(a);

    int result = solve(a);
    cout << "Max area of rectange is: " << result << endl;
    return 0;
}

// g++ -std=c++11