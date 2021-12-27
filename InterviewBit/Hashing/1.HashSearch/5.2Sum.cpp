/*
Problem Description

Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 < index2. Please note that your returned answers (both index1 and index2 ) are not zero-based. Put both these numbers in order in an array and return the array from your function ( Looking at the function signature will make things clearer ). Note that, if no pair exists, return empty list.

If multiple solutions exist, output the one where index2 is minimum. If there are multiple solutions with the minimum index2, choose the one with minimum index1 out of them.

Input: [2, 7, 11, 15], target=9
Output: index1 = 1, index2 = 2
*/
/*
Solution Approach:
1. We need to created mapping using int as key and vector<int> as value as there can be multiple repeated values.
2. Looking at the conditions, we need index1 < index2 && index2 should be as small as possible.
That's why we need 4 more variables, index1, index2, minimumIndex1 and minimumIndex2 to keep track of global 
index2 which will be smaller.
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
    unordered_map<int, vector<int> > mapping;
    for(int i=0; i<n; i++) {
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

    // Check our mapping created
    // cout << "Checking map created: " << endl;
    // for(int i=0; i<n; i++){
    //     cout << "Value: " << a[i] << endl;
    //     vector<int> mapValue = mapping[a[i]];
    //     printVector(mapValue);
    //     cout << endl;
    // }

    // Solving 2 sum
    int minimumIndex1 = INT_MAX;
    int minimumIndex2 = INT_MAX;
    int index1 = 0;
    int index2 = 0;
    for(int i=0; i<n; i++){
        int value = a[i];
        int requiredValue = b - value;

        vector<int> mapValue = mapping[requiredValue];
        if(mapValue.size() == 0){
            continue;
        } else {
            for(int j=0; j<mapValue.size(); j++){
                int indexValue = mapValue[j] - 1;
                // if index value is same as i, we need i!=j
                if(indexValue == i){
                    continue;
                } else {
                    // we got our answer.
                    index1 = i+1;
                    index2 = indexValue + 1;
                    
                    // Check if our index2 is smaller than minimumIndex2
                    if(index2 < minimumIndex2 && index1 < index2){
                        minimumIndex2 = index2;
                        minimumIndex1 = index1;
                    } else if(index2 == minimumIndex2 && index1 < index2){
                        if(index1 <= minimumIndex1){
                            minimumIndex1 = index1;
                            minimumIndex2 = index2;
                        }
                    }
                }
            }
        }
    }
    if(minimumIndex1 == INT_MAX){
        return result;
    } else {
        result.push_back(minimumIndex1);
        result.push_back(minimumIndex2);
        return result;
    }
}

int main(){
    vector<int> a = { 4, 7, -4, 2, 2, 2, 3, -5, -3, 9, -4, 9, -7, 7, -1, 9, 9, 4, 1, -4, -2, 3, -3, -5, 4, -7, 7, 9, -4, 4, -8};
    int b = -3;
    cout << "Given array is: " << endl;
    printVector(a);

    vector<int> result = solve(a, b);
    cout << "Result: " << endl;
    printVector(result);

    return 0;
}

// g++ -std=c++11