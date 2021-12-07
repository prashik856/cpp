/*
Problem Description

Given a linked list A of length N and an integer B.

You need to find the value of the Bth node from the middle towards the beginning of the Linked List A.

If no such element exists, then return -1.

NOTE:

Position of middle node is: (N/2)+1, where N is the total number of nodes in the list.


Problem Constraints
1 <= N <= 105
1<= Value in Each Link List Node <= 103
1 <= B <= 105


Input Format
First argument is the head pointer of the linkedlist A.

Second argument is an integer B.



Output Format
Return an integer denoting the value of the Bth from the middle towards the head of the linked list A. If no such element exists, then return -1.



Example Input
Input 1:

 A = 3 -> 4 -> 7 -> 5 -> 6 -> 1 6 -> 15 -> 61 -> 16
 B = 3
 Input 2:

 A = 1 -> 14 -> 6 -> 16 -> 4 -> 10
 B = 2
 Input 3:

 A = 1 -> 14 -> 6 -> 16 -> 4 -> 10
 B = 10


Example Output
Output 1:

 4
 Output 2:

 14
 Output 3:

 -1


Example Explanation
Explanation 1:

 The Middle of the linked list is the node with value 6.
 The 1st node from the middle of the linked list is the node with value 5.
 The 2nd node from the middle of the linked list is the node with value 7.
 The 3rd node from the middle of the linked list is the node with value 4.
 So we will output 4.
Explanation 2:

 The Middle of the linked list is the node with value 16.
 The 1st node from the middle of the linked list is the node with value 6.
 The 2nd node from the middle of the linked list is the node with value 14.
 So we will output 14.
Explanation 3:

 The Middle of the linked list is the node with value 16.
 There are only 3 nodes to the left of the middle node and we need to find the 10th node which doesn't exist so we will return -1.
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

int solve(ListNode* head, int b){
    if(head == 0){
        return -1;
    }

    ListNode *fast = head;
    ListNode *slow = head;
    int len = 0;
    while(fast != 0){
        fast = fast -> next;
        len++;
        if(fast != 0){
            fast = fast -> next;
            slow = slow -> next;
            len++;
        }
    }

    // cout << "Length of Linked List is: " << len << endl;
    
    // cout << "Middle Element is: " << slow -> val << endl;
    int midElement = 1 + (len/2);
    // cout << "Middle element index: " << midElement << endl;

    int diff = midElement - b - 1;
    // cout << "Difference value is: " << diff << endl;
    if(diff < 0){
        return -1;
    }

    if(diff == 0){
        return head -> val;
    }

    int count = 0;
    ListNode* temp = head;
    while(count != diff){
        temp = temp -> next;
        count++;
    }
    return temp -> val;
}

int main(){
    vector<int> a = {1,2,3,4,5, 6};
    ListNode *head = createLinkedList(a);
    cout << "Given linked list is: " << endl;
    printLinkedList(head);
    int b = 2;

    int result = solve(head, b);
    cout << "Result: " << result << endl;
    return 0;
}

// g++ -std=c++11