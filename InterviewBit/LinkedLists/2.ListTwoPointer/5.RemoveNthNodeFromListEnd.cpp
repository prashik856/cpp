/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.

Note:

If n is greater than the size of the list, remove the first node of the list.
Try doing it using constant additional space.
*/

/*
Let's get the length.
check if b > n:
    if yes -> remove first element
    else:
        remove (length - n)th node
Then subtract the value

Take care when prevNode == 0!
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

ListNode *solve(ListNode *head, int b){
    // base case
    if(b == 0){
        return head;
    }

    int len = 0;
    ListNode *temp = head;
    while(temp != 0){
        len++;
        temp = temp -> next;
    }
    // cout << "Lenght of linked list is: " << len << endl;
    
    if(b > len){
        // Remove first element
        head = head -> next;
        return head;
    } else {
        // cout << "len - b value is: " << len - b << endl;
        temp = head;
        ListNode *prev = 0;
        int currentLength = 0;
        int diff = len - b;
        while(currentLength != diff){
            prev = temp;
            temp = temp -> next;
            currentLength++;
        }

        // cout << "Node to delete is: " << temp -> val << endl;
        ListNode *nextNode = temp -> next;
        if(prev != 0){
            prev -> next = nextNode;
        } else {
            head = nextNode;
        }
    }

    return head;
}

int main(){
    vector<int> a = {1,2,3,4,5};
    int b = 2;
    ListNode *head = createLinkedList(a);
    cout << "Given linked list is: " << endl;
    printLinkedList(head);

    ListNode *result = solve(head, b);
    cout << "Result: " << endl;
    printLinkedList(result);
    return 0;
}

// g++ -std=c++11