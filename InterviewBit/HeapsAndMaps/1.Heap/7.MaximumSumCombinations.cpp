/*
Problem Description

Given two equally sized 1-D arrays A, B containing N integers each.

A sum combination is made by adding one element from array A and another element of array B.

Return the maximum C valid sum combinations from all the possible sum combinations.



Problem Constraints
 1 <= N <= 105

 1 <= A[i] <= 103

 1 <= C <= N



Input Format
First argument is an one-dimensional integer array A of size N.

Second argument is an one-dimensional integer array B of size N.

Third argument is an integer C.



Output Format
Return a one-dimensional integer array of size C denoting the top C maximum sum combinations.

NOTE:

The returned array must be sorted in non-increasing order.



Example Input
Input 1:

 A = [3, 2]
 B = [1, 4]
 C = 2
Input 2:

 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
 C = 4


Example Output
Output 1:

 [7, 6]
Output 1:

 [10, 9, 9, 8]


Example Explanation
Explanation 1:

 7     (A : 3) + (B : 4)
 6     (A : 2) + (B : 4)
Explanation 2:

 10   (A : 4) + (B : 6)
 9   (A : 4) + (B : 5)
 9   (A : 3) + (B : 6)
 8   (A : 3) + (B : 5)
*/
/*
solution Approach:
Easy enough. We just solved this.
Only change is result array size.
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

vector<int> solve(vector<int> a, vector<int> b, int c){
    vector<int> result;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    priority_queue< vector<int> > maxValues;
    unordered_map<string, int> mapping;
    int n = a.size();
    vector<int> temp = {a[n-1] + b[n-1], n-1, n-1};
    maxValues.push(temp);
    while(result.size() != c){
        vector<int> maxValue = maxValues.top();
        maxValues.pop();
    
        int i = maxValue[1];
        int j = maxValue[2];
        // create key
        string key = to_string(i) + " " + to_string(j);
        if(mapping[key] == 0){
            mapping[key] = 1;
            int val = maxValue[0];
            result.push_back(val);

            // create possible combinations
            vector<int> first = {a[i-1] + b[j], i-1, j};
            vector<int> second = {a[i] + b[j-1], i, j-1};
            maxValues.push(first);
            maxValues.push(second);
        } else {
            // combination already in the map
            continue;
        }
    }

    return result;
}

int main(){
    vector<int> a = {1, 4, 2, 3};
    vector<int> b = {2, 5, 1, 6};
    int c = 2;
    cout << "Given arrays are: " << endl;
    printVector(a);
    printVector(b);
    cout << "Result vector size: " << c << endl;

    vector<int> result = solve(a, b, c);
    cout << "Result: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11