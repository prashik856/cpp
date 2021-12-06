/*
Write a program to find the node at which the intersection of two singly linked lists begins.

For example, the following two linked lists:


A:          a1 → a2
                   ↘
                     c1 → c2 → c3
                   ↗
B:     b1 → b2 → b3

begin to intersect at node c1.

Notes:

If the two linked lists have no intersection at all, return null.
The linked lists must retain their original structure after the function returns.
You may assume there are no cycles anywhere in the entire linked structure.
Your code should preferably run in O(n) time and use only O(1) memory.
Problem approach completely explained :

Complete code in the hints section.
*/

/*
Solution Approach:
https://www.geeksforgeeks.org/write-a-function-to-get-the-intersection-point-of-two-linked-lists/
Method 1(Simply use two loops) 
Use 2 nested for loops. 
The outer loop will be for each node of the 1st list and inner loop will be for 2nd list. 
In the inner loop, check if any of nodes of the 2nd list is same as the current node of the first linked list. 
The time complexity of this method will be O(M * N) where m and n are the numbers of nodes in two lists.

Method 2 (Mark Visited Nodes) 
This solution requires modifications to basic linked list data structure. 
Have a visited flag with each node. 
Traverse the first linked list and keep marking visited nodes. 
Now traverse the second linked list, 
If you see a visited node again then there is an intersection point, 
return the intersecting node. 
This solution works in O(m+n) but requires additional information with each node. 
A variation of this solution that doesn’t require modification to the basic data structure can be implemented using a hash. 
Traverse the first linked list and store the addresses of visited nodes in a hash. 
Now traverse the second linked list and if you see an address that already exists in the hash then return the intersecting node.


Method 3(Using difference of node counts) 
> Get count of the nodes in the first list, let count be c1.
> Get count of the nodes in the second list, let count be c2.
> Get the difference of counts d = abs(c1 – c2)
> Now traverse the bigger list from the first node till d nodes so that from here onwards both the lists have equal no of nodes
> Then we can traverse both the lists in parallel till we come across a common node. 
(Note that getting a common node is done by comparing the address of the nodes)
> First we travel the d amount of nodes. That means, after d number of nodes, length of remaining 
linked list L1 and L2 will be same. After this, we can just travel both of the linked list in parallel and find the common node.
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

ListNode* getIntersectionNode(ListNode* A, ListNode* B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    ListNode *result=0;
    int aLength = 0;
    int bLength = 0;

    aLength = getLinkedListLength(A);
    bLength = getLinkedListLength(B);

    int difference = 0;
    ListNode *temp;
    ListNode *temp2;
    if(aLength > bLength){
        difference = aLength - bLength;
        temp = A;
        temp2 = B;
    } else {
        difference = bLength - aLength;
        temp = B;
        temp2 = A;
    }

    int d = 0;
    while(d < difference){
        temp = temp -> next;
        d++;
    }
    // Now, length of A and B are the same.
    while(temp != 0){
        if(temp == temp2){
            result = temp;
            return temp;
        }
        temp = temp -> next;
        temp2 = temp2 -> next;
    }
    return result;
}

int main(){
    vector<int> a = {1,2,3,4,5};
    return 0;
}

// g++ -std=c++11
