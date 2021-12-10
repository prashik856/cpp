/*
Given an array of integers A.  There is a sliding window of size B which 

is moving from the very left of the array to the very right. 

You can only see the w numbers in the window. Each time the sliding window moves 

rightwards by one position. You have to find the maximum for each window. 

The following example will give you more clarity.

The array A is [1 3 -1 -3 5 3 6 7], and B is 3.

Window position	Max
———————————-	————————-
[1  3  -1] -3  5  3  6  7	3
1 [3  -1  -3] 5  3  6  7	3
1  3 [-1  -3  5] 3  6  7	5
1  3  -1 [-3  5  3] 6  7	5
1  3  -1  -3 [5  3  6] 7	6
1  3  -1  -3  5 [3  6  7]	7
Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1].

Note: If B > length of the array, return 1 element with the max of the array.




Input Format

The first argument given is the integer array A.
The second argument given is the integer B.
Output Format

Return an array C, where C[i] is the maximum value of from A[i] to A[i+B-1]
For Example

Input 1:
    A = [1, 3, -1, -3, 5, 3, 6, 7]
    B = 3
Output 1:
    C = [3, 3, 5, 5, 6, 7]
*/
/*
We can use a normal queue.
First we track the max element when initializing the queue.

But take care when popping an element.
If element we are going to pop is max value, we will need to recalculate the max value.

I thought the time complexity won't work, but it did.
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

int getMaxFromQueue(queue<int> q){
    int maxValue = INT_MIN;
    while(!q.empty()){
        maxValue = max(maxValue, q.front());
        q.pop();
    }
    return maxValue;
}

vector<int> solve(vector<int> a, int b){
    vector<int> result;
    queue<int> q;
    int n =a.size();
    int i=0;
    int maxValue = INT_MIN;
    while(q.size() < b){
        int value = a[i];
        maxValue = max(maxValue, value);
        q.push(value);
        i++;
    }

    result.push_back(maxValue);
    for(;i<n; i++){
        // Check if maxValue is popping value
        int frontValue = q.front();
        if(maxValue == frontValue){
            q.pop();
            q.push(a[i]);
            maxValue = getMaxFromQueue(q);
        } else {
            q.pop();
            q.push(a[i]);
            maxValue = max(a[i], maxValue);
        }
        result.push_back(maxValue);
    }
    return result;
}

int main(){
    vector<int> a = {1, 3, -1, -3, 5, 3, 6, 7};
    int b = 3;
    cout << "Given array is: " << endl;
    printVector(a);

    vector<int> result = solve(a, b);
    cout << "Result is: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11