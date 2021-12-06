/*
Given a singly linked list, determine if its a palindrome. Return 1 or 0 denoting if its a palindrome or not, respectively.

Notes:

Expected solution is linear in time and constant in space.
For example,

List 1-->2-->1 is a palindrome.
List 1-->2-->3 is not a palindrome.
*/
/*
Okay. This is a singly linked list, and we need to use two pointers somehow.
*/
/*
Solution Approach:
1. We use our previous fast and slow method to get to the mid point.
2. Take decisions based on the length of the string.
3. Reverse other half of the linked list and compare.
Remember how to reverse a linked list!
        ListNode *nextNode = current -> next;
        current -> next = prev;
        if(nextNode == 0){
            midRef = current;
        }
        prev = current;
        current = nextNode;
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

int solve(ListNode * head){
    int result = 1;

    // base cases
    if(head == 0){
        return 0;
    }

    // If length 1
    if(head -> next == 0){
        return 1;
    }

    ListNode *temp = head;
    ListNode *fast = temp;
    ListNode *slow = temp;
    ListNode *prev = 0;
    int len = 0;

    while(fast != 0){
        fast = fast -> next;
        len++;
        if(fast != 0){
            fast = fast -> next;
            prev = slow;
            slow = slow -> next;
            len++;
        }
    }
    // cout << "Length of linked list is: " << len << endl;
    if(len % 2 == 0){
        prev -> next = 0;
    } else {
        slow = slow -> next;
        prev -> next = 0;
    }

    ListNode *firstRef = head;
    ListNode *midRef = slow;
    // cout << "Two Parted linked lists are: " << endl;
    // printLinkedList(firstRef);
    // printLinkedList(midRef);

    // cout << "Reversing second linked list: " << endl;
    prev = 0;
    temp = midRef;
    ListNode *current = temp;
    while(current != 0){
        ListNode *nextNode = current -> next;
        current -> next = prev;
        if(nextNode == 0){
            midRef = current;
        }
        prev = current;
        current = nextNode;
    }
    // cout << "Reversed Linked list is: " << endl;
    // printLinkedList(midRef);

    // Now that we have reversed linked list, we can just compare 1 and 2
    fast = firstRef;
    slow = midRef;
    while(fast != 0 && slow != 0){
        if(fast -> val != slow -> val){
            return 0;
        }
        fast = fast -> next;
        slow = slow -> next;
    }

    return result;
}

int main(){
    vector<int> a = {1,2,2,2,2,1};
    cout << "Given Linked list is: " << endl;
    ListNode *head = createLinkedList(a);
    printLinkedList(head);

    int result = solve(head);
    cout << "Result is: " << result << endl;
    return 0;
}

// g++ -std=c++11