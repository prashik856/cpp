/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,

Given 1->4->3->2->5->2 and x = 3,

return 1->2->2->4->3->5.
*/
/*
Solution Approach:
Get all nodes which are smaller than the given value.
While getting those nodes, remove them from linked list.
Keep track of head while deleting nodes. If our prev = 0, that means we need to update head.

Now, find the correct positions of the items and add them in the linked list.
Keep track of head while adding the node too. If prev = 0, then we need to update the head.
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

ListNode* solve(ListNode* head, int b){
    ListNode* temp = head;
    bool valueFound = false;

    vector<ListNode *> items;
    ListNode *prev = 0;
    temp = head;
    while(temp != 0){
        if(temp -> val < b){
            // Delete temp from linked list and store it in a vector
            ListNode *nextNode = temp -> next;
            if(prev != 0){
                prev -> next = nextNode;
            } else {
                // Keeping track of head, as we can lose it!!
                head = nextNode;
            }
            temp -> next = 0;
            items.push_back(temp);
            temp = nextNode;
        } else {
            prev = temp;
            temp = temp -> next;
        }
    }

    // print the vector that we have generated
    // cout << "Values we need to restore are: " << endl;
    // for(int i=0; i<items.size(); i++){
    //     cout << items[i]->val << " ";
    // }
    // cout << endl;

    temp = head;
    prev = 0;
    for(int i=0; i<items.size(); i++){
        ListNode *node = items[i];
        // cout << "For item: " << node -> val << endl;
        
        // Now we need to find the position of this node
        while(temp != 0){
            if(temp -> val > node -> val){
                // cout << "Inserting node before " << temp->val << " node" << endl;
                if(prev != 0){
                    // cout << "Inserting node after " << prev -> val << " node" << endl;
                    prev -> next = node;
                } else {
                    // We might lose our head here!
                    head = node;
                }
                node -> next = temp;
                prev = node;
                break;
            } else {
                prev = temp;
                temp = temp -> next;
            }
        }
        // cout << endl;
    }

    return head;
}

int main(){
    vector<int> a = {1,2,3,4,5};
    int b = 5;
    ListNode *head = createLinkedList(a);
    cout << "Given linked list is: " << endl;
    printLinkedList(head);

    ListNode *result = solve(head, b);
    cout << "Result: " << endl;
    printLinkedList(head);

    return 0;
}

// g++ -std=c++11