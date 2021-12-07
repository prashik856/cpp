/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,

Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/
/*
Use 4 pointers
prev, next, current, and adjacent
Take care of all of them when they are 0
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

    // We will need 4 nodes
    // prevNode nextNode, currentNode adjacentNode
    ListNode *prevNode = 0;
    ListNode *currentNode = head;
    ListNode *adjacentNode = currentNode -> next;
    ListNode *nextNode = 0;

    while(currentNode != 0){
        // reached end
        if(adjacentNode == 0){
            break;
        }
        nextNode = adjacentNode -> next;
        // Swap
        adjacentNode -> next = currentNode;
        currentNode -> next = nextNode;

        // restore previous node
        if(prevNode != 0){
            prevNode -> next = adjacentNode;
        } else {
            head = adjacentNode;
        }

        // set new prev node value
        prevNode = currentNode;

        // Update currentNode
        currentNode = nextNode;
        if(currentNode == 0){
            // reached end
            break;
        }
        adjacentNode = currentNode -> next;
    }
    return head;
}

int main(){
    vector<int> a = {1,2,3,4,5, 6};
    ListNode *head = createLinkedList(a);
    cout << "Given linked list is: " << endl;
    printLinkedList(head);

    ListNode *result = solve(head);
    cout << "Result: " << endl;
    printLinkedList(result);
    return 0;
}

// g++ -std=c++11