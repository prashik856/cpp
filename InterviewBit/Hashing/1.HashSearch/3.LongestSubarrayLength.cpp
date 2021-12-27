/*
Problem Description

Given an integer array A of size N containing 0's and 1's only. 

You need to find the length of the longest subarray having count of 1’s one more than count of 0’s.



Problem Constraints
1 <= N <= 105



Input Format
First and only argument is an integer array A of size N.



Output Format
Return an integer denoting the longest length of the subarray.



Example Input
Input 1:

 A = [0, 1, 1, 0, 0, 1]
Input 2:

 A = [1, 0, 0, 1, 0]


Example Output
Output 1:

 5
Output 2:

 1


Example Explanation
Explanation 1:

 Subarray of length 5, index 1 to 5 i.e 1, 1, 0, 0, 1. Count of 1 = 3, Count of 0 = 2.
Explanation 2:

 Subarray of length 1 will be only subarray that follow the above condition.
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
    unordered_map<int, int> mapping;
    int maxLength = 0;
    int currentSum = 0;
    for(int i=0; i<n; i++){
        if(a[i] == 0){
            currentSum--;
        } else {
            currentSum++;
        }

        if(currentSum == 1){
            maxLength = i + 1;
        }

        int value = mapping[currentSum];
        if(value == 0){
            mapping[currentSum] = i + 1;
        }

        // I don't understand why are we using this?
        // Why check if sum - 1 is present in the hash map?
        // I think this means we have difference of 1 between sum and sum -1.
        // That means, this can be a local maxima
        value = mapping[currentSum - 1];
        if(value > 0){
            int index = value - 1;
            int currentLength = i - index;
            maxLength = max(currentLength, maxLength);
        }
    }
    result = maxLength;
    return result;
}

int main(){
    vector<int> a = {1, 0, 0, 1, 0};
    cout << "Given array is: " << endl;
    printVector(a);

    int result = solve(a);
    cout << "Result is: " << result << endl;
    return 0;
}

// g++ -std=c++11