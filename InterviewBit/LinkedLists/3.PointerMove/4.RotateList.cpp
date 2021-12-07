/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:

Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.
*/
/*
Solution Approach:
Easy solution.
First get the length of the linked list.
Get value of k % len
if k == 0:
return our list.
Else, put the last k nodes of linked list to the start, and first n-k nodes after k nodes.
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

ListNode *solve(ListNode* head, int k){
    // base cases
    if(k == 0){
        return head;
    }

    if(head == 0){
        return head;
    }

    if(head -> next == 0){
        return head;
    }

    int len = 0;
    ListNode *temp = head;
    ListNode *tail = 0;
    while(temp != 0){
        // last node
        if(temp -> next == 0){
            tail = temp;
        }
        temp = temp -> next;
        len++;
    }

    // cout << "Length of list is: " << len << endl;

    k = k % len;
    if(k == 0){
        return head;
    }
    
    // Go till len - k nodes
    int diff = len - k;
    int count = 0;
    temp = head;
    ListNode *prev = 0;
    while(count != diff){
        prev = temp;
        temp = temp -> next;
        count++;
    } 

    // cout << "Remove from this node: " << temp -> val << endl;
    ListNode *newHeadRef = temp;
    
    // The new tail now is prev
    prev -> next = 0;

    tail -> next = head;
    head = newHeadRef;

    return head;
}

int main(){
    vector<int> a = {1,2,3,4,5, 6};
    ListNode *head = createLinkedList(a);
    cout << "Given linked list is: " << endl;
    printLinkedList(head);
    int k = 90;

    ListNode *result = solve(head, k);
    cout << "Result: " << endl;
    printLinkedList(result);
    return 0;
}

// g++ -std=c++11