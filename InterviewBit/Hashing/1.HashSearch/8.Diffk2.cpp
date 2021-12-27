/*
Given an array A of integers and another non negative integer k, find if there exists 2 indices i and j such that A[i] - A[j] = k, i != j.

Example :

Input :

A : [1 5 3]
k : 2
Output :

1
as 3 - 1 = 2

Return 0 / 1 for this problem.
*/

/*
Easy enough.
Just like 2sum.

a[i] - a[j] = k
a[j] = a[i] - k, i!=j

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

int solve(vector<int> a, int b){
    int result = 0;

    int n = a.size();
    unordered_map<long, vector<int> > mapping;
    for(int i=0; i<n; i++){
        long value = a[i];
        vector<int> mapValue = mapping[value];
        if(mapValue.size() == 0){
            vector<int> temp;
            temp.push_back(i+1);
            mapping[value] = temp;
        } else {
            mapValue.push_back(i+1);
            mapping[value] = mapValue;
        }
    }

    for(int i=0; i<n; i++){
        long value = a[i];
        long valueToFind = (long)value - (long)b;
        vector<int> mapValue = mapping[valueToFind];
        if(mapValue.size() == 0){
            continue;
        } else {
            for(int j=0; j<mapValue.size(); j++){
                int indexValue = mapValue[j] - 1;
                if(indexValue != i){
                    return 1;
                }
            }
        }
    }

    return result;
}

int main(){
    vector<int> a = {1, 5, 3};
    int b = 2;
    cout << "Given array is: " << endl;
    printVector(a);
    cout << "Given difference is: " << b << endl;

    int result = solve(a, b);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11