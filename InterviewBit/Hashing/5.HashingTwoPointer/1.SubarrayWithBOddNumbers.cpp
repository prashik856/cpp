/*
Problem Description

Given an array of integers A and an integer B.

Find the total number of subarrays having exactly B odd numbers.



Problem Constraints
1 <= length of the array <= 105

1 <= A[i] <= 109

0 <= B <= A



Input Format
The first argument given is the integer array A.

The second argument given is integer B.



Output Format
Return the total number of subarrays having exactly B odd numbers.



Example Input
Input 1:

 A = [4, 3, 2, 3, 4]
 B = 2
Input 2:

 A = [5, 6, 7, 8, 9]
 B = 3


Example Output
Output 1:

 4
Output 2:

 1


Example Explanation
Explanation 1:

 The subarrays having exactly B odd numbers are:
 [4, 3, 2, 3], [4, 3, 2, 3, 4], [3, 2, 3], [3, 2, 3, 4]
Explanation 2:

 The subarrays having exactly B odd numbers is [5, 6, 7, 8, 9]
*/
/*
Solution approach:
Naive Approach: 
The naive approach is to generate all possible subarrays and simultaneously checking for the subarrays 
with m odd numbers.

Efficient Approach: 
An efficient approach is to while traversing, compute the prefix[] array.
Prefix[i] stores the number of prefixes which has ‘i’ odd numbers in it. 
We increase the count of odd numbers if the array element is an odd one. 
When the count of odd numbers exceeds or is equal to m, 
add the number of prefixes which has “(odd-m)” numbers to the answer. 
At every step odd>=m, we calculate the number of subarrays formed till a particular index with the help of prefix array. 
prefix[odd-m] provides us with the number of prefixes which has “odd-m” odd numbers, 
which is added to the count to get the number of subarrays till the index. 

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

    int odd = 0;
    int n = a.size();
    vector<int> prefix(n, 0);
    for(int i=0; i<n; i++){
        // keep in adding
        prefix[odd] += 1;

        // if odd number is encountered, increment odd counter
        if(a[i] % 2 == 1){
            odd++;
        }

        // if number of odd numbers increases b
        if(odd >= b){
            // Add all prefixes 
            result += prefix[odd - b];
        }
    }
    return result;
}

int main(){
    vector<int> a = {4, 3, 2, 3, 4};
    int b = 2;
    cout << "Given array is: " << endl;
    printVector(a);
    cout << "Given required number of odd numbers are: " << b << endl;

    int result = solve(a, b);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11