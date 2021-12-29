/*
Problem Description

You are given an array of N integers, A1, A2 ,..., AN and an integer B. Return the of count of distinct numbers in all windows of size B.

Formally, return an array of size N-B+1 where i'th element in this array contains number of distinct elements in sequence Ai, Ai+1 ,..., Ai+B-1.

NOTE:  if B > N, return an empty array.



Input Format
First argument is an integer array A

Second argument is an integer B.



Output Format
Return an integer array.



Example Input
Input 1:

 A = [1, 2, 1, 3, 4, 3]
 B = 3
Input 2:

 A = [1, 1, 2, 2]
 B = 1


Example Output
Output 1:

 [2, 3, 3, 2]
Output 2:

 [1, 1, 1, 1]


Example Explanation
Explanation 1:

 A=[1, 2, 1, 3, 4, 3] and B = 3
 All windows of size B are
 [1, 2, 1]
 [2, 1, 3]
 [1, 3, 4]
 [3, 4, 3]
 So, we return an array [2, 3, 3, 2].
Explanation 2:

 Window size is 1, so the output array is [1, 1, 1, 1].
*/
/*
Solution Approach:
Simple sliding window and checking if exiting and leaving number exists in the map or not.
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

vector<int> solve(vector<int> a, int b){
    vector<int> result;

    int n = a.size();
    unordered_map<int, int> mapping;
    if(b > n){
        return result;
    }

    int count = 0;
    // Let's first do for the 1st window
    // cout << "For first window " << endl;
    for(int i=0; i<b; i++){
        // cout << a[i] << " ";
        if(mapping[a[i]] == 0){
            // first occurance
            mapping[a[i]] = 1;
            count++;
        } else {
            // already present
            mapping[a[i]]++;
        }
    }
    // cout << endl;
    result.push_back(count);

    // start from second window
    int start = 1;
    while(start + b <= n){
        // cout << "Exiting element: " << a[start - 1] << endl;
        // exiting element:
        int val = a[start - 1];
        mapping[val]--;
        int mapValue = mapping[val];
        // if count inside window reaches 0?
        if(mapValue == 0){
            count--;
        }
        // cout << "Count after exiting: " << count << endl;

        // entering element
        // cout << "Entering element: " << a[start + b - 1] << endl;
        val = a[start + b - 1];
        mapValue = mapping[val];
        if(mapValue == 0){
            // first occurance
            mapping[val]++;
            count++;
        } else if(mapValue >= 1){
            // 2nd occurance
            mapping[val]++;
        }
        // cout << "Count after entering: " << count << endl;
        result.push_back(count);

        start++;
        // cout << endl;
    }

    return result;
}

int main(){
    vector<int> a = {1, 1, 2, 2};
    int b = 1;
    cout << "Given input array is: " << endl;
    printVector(a);
    cout << "Given window size is: " << b << endl;

    vector<int> result = solve(a,b);
    cout << "Result: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11