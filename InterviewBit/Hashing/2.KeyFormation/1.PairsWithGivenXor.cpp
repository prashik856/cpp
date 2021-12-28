/*
Problem Description

Given an 1D integer array A containing N distinct integers.

Find the number of unique pairs of integers in the array whose XOR is equal to B.

NOTE:

Pair (a, b) and (b, a) is considered to be same and should be counted once.


Problem Constraints
1 <= N <= 105

1 <= A[i], B <= 107



Input Format
First argument is an 1D integer array A.

Second argument is an integer B.



Output Format
Return a single integer denoting the number of unique pairs of integers in the array A whose XOR is equal to B.



Example Input
Input 1:

 A = [5, 4, 10, 15, 7, 6]
 B = 5
Input 2:

 A = [3, 6, 8, 10, 15, 50]
 B = 5


Example Output
Output 1:

 1
Output 2:

 2


Example Explanation
Explanation 1:

 (10 ^ 15) = 5
Explanation 2:

 (3 ^ 6) = 5 and (10 ^ 15) = 5 
*/
/*
Solution Approach:
We need find pairs whose value is b
a[i] ^ a[j] = B
a[i] ^ (a[j] ^ B) = 0
Now, when a[i] ^ (a[j] ^ B) = 0. This means we need a[i] = a[j] ^ B or a[j] = a[i] ^ B
Thus, we will need two maps, one to check if the value exists, and 2nd to check if the solution 
already exists.
I thought I would get TLE, but this worked.
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
    unordered_map<int, vector<int> > mapping;
    unordered_map<string, int> resultMapping;

    for(int i=0; i<n; i++){
        int value = a[i];
        vector<int> mapValue = mapping[value];
        if(mapValue.size() == 0){
            vector<int>temp;
            temp.push_back(i+1);
            mapping[value] = temp;
        } else {
            mapValue.push_back(i+1);
            mapping[value] = mapValue;
        }
    }

    for(int i=0; i<n; i++){
        int value = a[i];
        // printVector(mapping[value]);
        int valueToFind = a[i] ^ b;
        // cout << "Value: " << value << endl;
        // cout << "Value to find: " << valueToFind << endl;

        vector<int> mapValue = mapping[valueToFind];
        if(mapValue.size() == 0){
            continue;
        } else {
            for(int j=0; j<mapValue.size(); j++){
                int indexValue = mapValue[j] - 1;
                if(indexValue != i){
                    int val1 = a[i];
                    int val2 = a[indexValue];
                    string key = "";
                    if(val1 < val2){
                        key = to_string(val1) + " " + to_string(val2);
                    } else {
                        key = to_string(val2) + " " + to_string(val1);
                    }
                    int resultMapValue = resultMapping[key];
                    if(resultMapValue == 0){
                        result++;
                        resultMapping[key] = 1;
                    }
                }
            }
        }
    }


    return result;
}

int main(){
    vector<int> a = {3, 6, 8, 10, 15, 50};
    int b = 5;
    cout << "Given array is: " << endl;
    printVector(a);
    cout << "Given xor value is: " << b << endl;

    int result = solve(a, b);
    cout << "Result is: " << result << endl;

    return 0;
}

// g++ -std=c++11