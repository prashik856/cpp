/*
Problem Description

Given a linked list A of length N and an integer B.

You need to reverse every alternate B nodes in the linked list A.



Problem Constraints
1 <= N <= 105
1<= Value in Each Link List Node <= 103
1 <= B <= N
N is divisible by B


Input Format
First argument is the head pointer of the linkedlist A.

Second argument is an integer B.



Output Format
Return the head pointer of the final linkedlist as described.



Example Input
Input 1:

 A = 3 -> 4 -> 7 -> 5 -> 6 -> 6 -> 15 -> 61 -> 16
 B = 3
 Input 2:

 A = 1 -> 4 -> 6 -> 6 -> 4 -> 10
 B = 2


Example Output
Output 1:

 7 -> 4 -> 3 -> 5 -> 6 -> 6 -> 16 -> 61 -> 15
Output 2:

 4 -> 1 -> 6 -> 6 -> 10 -> 4


Example Explanation
Explanation 1:

 The linked list contains 9 nodes and we need to reverse alternate 3 nodes.
 First sublist of length 3  is 3 -> 4 -> 7 so on reversing it we get 7 -> 4 -> 3.
 Second sublist of length 3 is 5 -> 6 -> 6 we don't need to reverse it.
 Third sublist of length 3 is 15 -> 61 -> 16 so on reversing it we get 16 -> 61 -> 15.
Explanation 2:

 The linked list contains 6 nodes and we need to reverse alternate 2 nodes.
 First sublist of length 2 is 1 -> 4 so on reversing it we get 4 -> 1.
 Second sublist of length 2 is 6 -> 6 we don't need to reverse it.
 Third sublist of length 2 is 4 -> 10 so on reversing it we get 10 -> 4.
*/
/*
Solution Approach:
Rather than a stack, we use a vector this time to store list nodes of length k.
if reverse is true, we start from last
else we start from the start.
And we create a new linked list using this logic.
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

ListNode* solve(ListNode *head, int k){
    if(head == 0){
        return head;
    }
    if(head -> next == 0){
        return head;
    }

    ListNode *temp = head;
    
    ListNode *newHead = 0;
    ListNode *newTail = 0;
    vector<ListNode*> nodes;
    bool reverse = true;
    while(temp != 0){
        if(nodes.size() == k){
            // we need to empty this
            if(reverse){
                for(int i=nodes.size() - 1; i>=0 ;i--){
                    ListNode *node = nodes[i];
                    if(newHead == 0){
                        newHead = node;
                        newTail = node;
                    } else {
                        newTail -> next = node;
                        newTail = node;
                    }
                }
                nodes.clear();
                reverse = false;
            } else {
                for(int i=0; i<nodes.size(); i++){
                    ListNode *node = nodes[i];
                    if(newHead == 0){
                        newHead = node;
                        newTail = node;
                    } else {
                        newTail -> next = node;
                        newTail = node;
                    }
                }
                nodes.clear();
                reverse = true;
            }
        } else {
            ListNode *node = temp;
            temp = temp -> next;
            node -> next = 0;
            nodes.push_back(node);
        }
    }
    if(reverse){
        for(int i=nodes.size() - 1; i>=0 ;i--){
            ListNode *node = nodes[i];
            if(newHead == 0){
                newHead = node;
                newTail = node;
            } else {
                newTail -> next = node;
                newTail = node;
            }
        }
    } else {
        for(int i=0; i<nodes.size(); i++){
            ListNode *node = nodes[i];
            if(newHead == 0){
                newHead = node;
                newTail = node;
            } else {
                newTail -> next = node;
                newTail = node;
            }
        }
    }
    head = newHead;
    return head;
}

int main(){
    vector<int> a = {1,2,3,4,5,6,7,8,9,10};
    ListNode *head = createLinkedList(a);
    cout << "Given linked list is: " << endl;
    printLinkedList(head);
    int k = 2;

    ListNode *result = solve(head, k);
    cout << "Result: " << endl;
    printLinkedList(result);
    return 0;
}

// g++ -std=c++11