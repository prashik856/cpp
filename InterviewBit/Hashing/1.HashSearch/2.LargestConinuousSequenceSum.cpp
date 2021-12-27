/*
Find the largest continuous sequence in a array which sums to zero.

Example:


Input:  {1 ,2 ,-2 ,4 ,-4}
Output: {2 ,-2 ,4 ,-4}

NOTE : If there are multiple correct answers, return the sequence which occurs first in the array.
*/
/*
https://www.geeksforgeeks.org/find-the-largest-subarray-with-0-sum/
This involves the use of brute force where two nested loops are used. 
The outer loop is used to fix the starting position of the sub-array, 
and the inner loop is used for the ending position of the sub-array and 
if the sum of elements is equal to zero, then increase the count.

Consider all sub-arrays one by one and check the sum of every sub-array.
Run two loops: the outer loop picks the starting point i and the inner loop tries all sub-arrays starting from i.


Method 2:
The brute force solution is calculating the sum of each and every sub-array and
 checking whether the sum is zero or not. 
Let’s now try to improve the time complexity by taking an extra space of ‘n’ length. 
The new array will store the sum of all the elements up to that index. 
The sum-index pair will be stored in a hash-map. 
A Hash map allows insertion and deletion of key-value pair in constant time. 
Therefore, the time complexity remains unaffected. 
So, if the same value appears twice in the array, it will be guaranteed that the particular 
array will be a zero-sum sub-array. 


Mathematical Proof:
prefix(i) = arr[0] + arr[1] +…+ arr[i] 
prefix(j) = arr[0] + arr[1] +…+ arr[j], j>i 
if prefix(i) == prefix(j) 
    then prefix(j) – prefix(i) = 0 
        that means arr[i+1] + .. + arr[j] = 0, 
    So a sub-array has zero sum , and the length of that sub-array is j-i+1  

Now, the code works with above proof. But we still need to take care when currentSum reaches zero.
That means, the start to currentIndex subarray matches.
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

    int n =a.size();
    int startIndex = -1;
    int endIndex = -1;
    int maxLength = INT_MIN;
    unordered_map<int, int> mapping;
    vector<int> prefix(n, 0);
    int currentSum = 0;
    for(int i=0; i<n; i++){
        currentSum += a[i];
        prefix[i] = currentSum;

        int value = mapping[currentSum];

        if(currentSum == 0){
            int prevIndex = -1;
            int currentIndex = i;
            int currentLength = currentIndex + 1;
            if(currentLength > maxLength){
                maxLength = currentLength;
                startIndex = prevIndex;
                endIndex = currentIndex;
            }
            continue;
        }

        // let's store index + 1
        if(value == 0){
            mapping[currentSum] = i+1;
        } else {
            // This value already exists;
            int prevIndex = value - 1;
            int currentIndex = i;
            int currentLength = currentIndex - prevIndex;
            // cout << "Current Length is: " << currentLength << endl;
            if(currentLength > maxLength){
                maxLength = currentLength;
                startIndex = prevIndex;
                endIndex = currentIndex;
            }
        }
    }
    // cout << "Start Index: " << startIndex << endl;
    // cout << "End Index: " << endIndex << endl;

    for(int i=startIndex + 1; i<=endIndex; i++){
        result.push_back(a[i]);
    }

    return result;
}

int main(){
    vector<int> a = {1, 2, -3, 3};
    cout << "Given array is: " << endl;
    printVector(a);

    vector<int> result = solve(a);
    cout << "Result: " << endl;
    printVector(result);
    return 0;
}

// g++ -std=c++11