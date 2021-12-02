/*
Reverse a linked list. Do it in-place and in one-pass.

For example:

Given 1->2->3->4->5->NULL,

return 5->4->3->2->1->NULL.

PROBLEM APPROACH :

Complete solution code in the hints
*/

/*
Solution Approach:
Simple Linked List Reverse.
        // store next
        ListNode *tempNext = current -> next;
        
        // set current next to prev
        // store prevNode before losing it
        current -> next = prevNode;

        // set previous to current
        // store this before it is lost
        prevNode = current;

        // set current to next
        // lost current
        current = tempNext;
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

ListNode* solve(ListNode *head){
    ListNode *prevNode = 0;
    ListNode *current = head;
    
    if(current == 0){
        return head;
    }

    while(current != 0){
        // cout << "Current Node is: " << current -> val << endl;
        // if(prevNode != 0){
        //     cout << "Previous Node is: " << prevNode -> val << endl;
        // }
        // store next
        ListNode *tempNext = current -> next;
        
        // set current next to prev
        current -> next = prevNode;

        // set previous to current
        prevNode = current;

        // set current to next
        current = tempNext;
    }
    head = prevNode;

    return head;
}

int main(){
    vector<int> a = {1,2,3,4,5};
    ListNode *head = createLinkedList(a);
    cout << "Given Linked list is: " << endl;
    printLinkedList(head);
    
    ListNode* result = solve(head);
    cout << "Result is: " << endl;
    printLinkedList(result);
    return 0;
}

// g++ -std=c++11