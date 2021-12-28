/*
Given an array A of integers, find the index of values that satisfy A + B = C + D, where A,B,C & D are integers values in the array

Note:

1) Return the indices `A1 B1 C1 D1`, so that 
  A[A1] + A[B1] = A[C1] + A[D1]
  A1 < B1, C1 < D1
  A1 < C1, B1 != D1, B1 != C1 

2) If there are more than one solutions, 
   then return the tuple of values which are lexicographical smallest. 

Assume we have two solutions
S1 : A1 B1 C1 D1 ( these are values of indices int the array )  
S2 : A2 B2 C2 D2

S1 is lexicographically smaller than S2 iff
  A1 < A2 OR
  A1 = A2 AND B1 < B2 OR
  A1 = A2 AND B1 = B2 AND C1 < C2 OR 
  A1 = A2 AND B1 = B2 AND C1 = C2 AND D1 < D2
Example:

Input: [3, 4, 7, 1, 2, 9, 8]
Output: [0, 2, 3, 5] (O index)
If no solution is possible, return an empty list.
*/

/*
Let's try 4sum solution here:
a[A1] + a[B1] = a[C1] + a[D1]
=> a[A1] + a[B1] - a[C1] = a[D1]
We need to find if a[A1] + a[B1] - a[C1] exists in the array, and 
D1 > A1 && D1 > B1 && D1 > C1

But, here, there is no given condition that B1 > C1, but we have B1,C1 > A1
So, the jth and kth loop will i+1.
Check if j!=k, then continue.

O(n^3) works here.
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

vector<int> solve(vector<int> a){
    vector<int> result;

    int n = a.size();
    unordered_map<int, vector<int> > mapping;
    for(int i=0; i<n; i++){
        int value = a[i];
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
        for(int j=i+1;j<n; j++){
            for(int k=i+1; k<n; k++){
                if(j!=k){
                    int valueToFind = a[i] + a[j] - a[k];
                    vector<int> mapValue = mapping[valueToFind];
                    if(mapValue.size() == 0){
                        continue;
                    } else {
                        for(int l=0; l<mapValue.size(); l++){
                            int indexValue = mapValue[l]-1;
                            if(indexValue > i &&
                                indexValue > j && 
                                indexValue > k){
                                    result.push_back(i);
                                    result.push_back(j);
                                    result.push_back(k);
                                    result.push_back(indexValue);
                                    return result;
                                }
                        }
                    }
                }
            }
        }
    }

    return result;
}

int main(){
    vector<int> a = {0, 0, 1, 0, 2, 1};
    cout << "Given array is: " << endl;
    printVector(a);

    vector<int> result = solve(a);
    cout << "Result: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11