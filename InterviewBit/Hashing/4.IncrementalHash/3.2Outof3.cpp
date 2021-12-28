/*
Problem Description

Given are Three arrays A, B and C.

Return the sorted list of numbers that are present in atleast 2 out of the 3 arrays.



Problem Constraints
1 <= |A|, |B|, |C| <= 100000

1 <= A[i], B[i], C[i] <= 100000

A, B, C may or may not have pairwise distinct elements.



Input Format
First argument is the array A.

First argument is the array B.

First argument is the array C.



Output Format
Return a sorted array of numbers.



Example Input
Input 1:

A = [1, 1, 2]
B = [2, 3]
C = [3]
Input 2:

A = [1, 2]
B = [1, 3]
C = [2, 3]


Example Output
Output 1:

[2, 3]
Output 2:

[1, 2, 3]


Example Explanation
Explanation 1:

1 is only present in A. 2 is present in A and B. 3 is present in B and C.
Explanation 2:

All numbers are present in atleast 2 out of 3 lists.
*/

/*
Solution Approach:
Just easily check if the number is present in any other array.

Fucking IB, doesn't explain the question properly.
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

vector<int> solve(vector<int> a, vector<int> b, vector<int> c){
    vector<int> result;

    unordered_map<int, int> aMap;
    unordered_map<int, int> bMap;
    unordered_map<int, int> cMap;
    for(int i=0; i<a.size(); i++){
        aMap[a[i]] = aMap[a[i]] + 1;
    }

    for(int i=0; i<b.size(); i++){
        bMap[b[i]] = bMap[b[i]] + 1;
    }

    for(int i=0; i<c.size(); i++){
        cMap[c[i]] = cMap[c[i]] + 1;
    }

    for(int i=0; i<a.size(); i++){
        int val = a[i];
        if(bMap[val] > 0){
            bMap[val] = 0;
            aMap[val] = 0;
            cMap[val] = 0;
            result.push_back(val);
            continue;
        }

        if(cMap[val] > 0){
            bMap[val] = 0;
            aMap[val] = 0;
            cMap[val] = 0;
            result.push_back(val);
            continue;
        }
    }

    for(int i=0; i<b.size(); i++){
        int val = b[i];
        if(aMap[val] > 0){
            bMap[val] = 0;
            aMap[val] = 0;
            cMap[val] = 0;
            result.push_back(val);
            continue;
        }

        if(cMap[val] > 0){
            bMap[val] = 0;
            aMap[val] = 0;
            cMap[val] = 0;
            result.push_back(val);
            continue;
        }
    }

    for(int i=0; i<c.size(); i++){
        int val = c[i];
        if(aMap[val] > 0){
            bMap[val] = 0;
            aMap[val] = 0;
            cMap[val] = 0;
            result.push_back(val);
            continue;
        }

        if(bMap[val] > 0){
            bMap[val] = 0;
            aMap[val] = 0;
            cMap[val] = 0;
            result.push_back(val);
            continue;
        }
    }

    sort(result.begin(), result.end());
    return result;
}

int main(){
    vector<int> a = {1, 2};
    vector<int> b = {1,3};
    vector<int> c = {2,3};
    cout << "Given inputs is: " << endl;
    printVector(a);
    printVector(b);
    printVector(c);

    vector<int> result = solve(a, b, c);
    cout << "Result is: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11