/*
Problem Description

Given two integers arrays A and B of size N each.

Find the maximum N elements from the sum combinations (Ai + Bj) formed from elements in array A and B.



Problem Constraints
1 <= N <= 2 * 105

-1000 <= A[i], B[i] <= 1000



Input Format
First argument is an integer array A.

Second argument is an integer array B.



Output Format
Return an intger array denoting the N maximum element in descending order.



Example Input
Input 1:

 A = [1, 4, 2, 3]
 B = [2, 5, 1, 6]
Input 2:

 A = [2, 4, 1, 1]
 B = [-2, -3, 2, 4]


Example Output
Output 1:

 [10, 9, 9, 8]
Output 2:

 [8, 6, 6, 5]


Example Explanation
Explanation 1:

 4 maximum elements are 10(6+4), 9(6+3), 9(5+4), 8(6+2).
Explanation 2:

 4 maximum elements are 8(4+4), 6(4+2), 6(4+2), 5(4+1).
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/k-maximum-sum-combinations-two-arrays/

We use priority queue of vectors.
In the vector, we store the current max value, ith index and jth index.
if i and j are not encountered, we store these indices in the map, and create new possible combinations 
of i-1 and j, j-1 and i.
We repeat this process till size of result is n.
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

vector<int> solve(vector<int> a, vector<int> b){
    vector<int> result;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    // cout << "Sorted arrays are: " << endl;
    // printVector(a);
    // printVector(b);
    int n = a.size();

    priority_queue< vector<int> > maxValues;
    unordered_map<string, int> mapping;
    vector<int> temp = { a[n-1] + b[n-1],n-1, n-1};
    maxValues.push(temp);
    while(result.size() != n){
        vector<int> currentMax = maxValues.top();
        maxValues.pop();

        int i = currentMax[1];
        int j = currentMax[2];
        string key = to_string(i) + " " + to_string(j);
        if(mapping[key] == 0){
            mapping[key] = 1;
            result.push_back(currentMax[0]);

            // use new combination now
            vector<int> first = {a[i] + b[j-1], i, j-1};
            vector<int> second = {a[i-1] + b[j], i-1, j};
            maxValues.push(first);
            maxValues.push(second);
        } else {
            // we have already encountered these indices
            continue;
        }
    }
    

    return result;
}

int main(){
    vector<int> a = {1, 4, 2, 3};
    vector<int> b = {2, 5, 1, 6};
    cout << "Given arrays are: " << endl;
    printVector(a);
    printVector(b);

    vector<int> result = solve(a, b);
    cout << "Result: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11