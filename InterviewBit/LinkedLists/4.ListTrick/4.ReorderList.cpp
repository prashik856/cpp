/*
Given a singly linked list

    L: L0 → L1 → … → Ln-1 → Ln,
reorder it to:

    L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → …
You must do this in-place without altering the nodes’ values.

For example,

Given {1,2,3,4}, reorder it to {1,4,2,3}.
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

ListNode *solve(ListNode *head){
    if(head == 0){
        return head;
    }

    if(head -> next == 0){
        return head;
    }

    // forward and reverse
    vector<ListNode *> forward;
    ListNode *temp = head;
    while(temp != 0){
        ListNode *node = temp;
        temp = temp -> next;
        node -> next = 0;
        forward.push_back(node);
    }

    int lowIndex = 0;
    int highIndex = forward.size() - 1;
    bool useLow = true;
    ListNode *newHead = 0;
    ListNode *newTail = 0;
    while(lowIndex <= highIndex){
        if(useLow){
            ListNode *node = forward[lowIndex];
            if(newHead == 0){
                newHead = node;
                newTail = node;
            } else {
                newTail -> next = node;
                newTail = node;
            }
            lowIndex++;
            useLow = false;
        } else {
            ListNode *node = forward[highIndex];
            newTail -> next = node;
            newTail = node;
            useLow = true;
            highIndex--;
        }
    }

    head = newHead;
    return head;
}

int main(){
    vector<int> a = {1,2,3,4};
    ListNode *head = createLinkedList(a);
    cout << "Given linked list is: " << endl;
    printLinkedList(head);

    ListNode *result = solve(head);
    cout << "Result: " << endl;
    printLinkedList(result);
    return 0;
}

// g++ -std=c++11