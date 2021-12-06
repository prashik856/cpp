/*
Sort a linked list in O(n log n) time using constant space complexity.

Example :

Input : 1 -> 5 -> 4 -> 3

Returned list : 1 -> 3 -> 4 -> 5
*/
/*
Solution Approach:
https://www.geeksforgeeks.org/merge-sort-for-linked-list/
Basically, only merge sort can be used for this;
1. First we divide our linked list in two parts.
2. To divide, we move two pointers fast and slow, and have another pointer called prev.
3. We move fast 2x and slow only once, and store the value of slow in prev before moving slow forward.
4. Once fast ends, slow is at the mid point. 
5. Put prev -> next as 0. Now we have two linked lists, which is required in merge sort.
6. We then again divide our newly divided linked lists, and store their reference in firstRef and midRef.
7. We then use sortedMerge to merge firstRef and midRef.
8. sortedMerge is very similar to sortedMerge in arrays!
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

ListNode *SortMerge(ListNode *a, ListNode *b){
    ListNode *result = 0;
    if(a == 0){
        return b;
    }
    if(b == 0){
        return a;
    }

    ListNode *temp = result;
    while(a != 0 && b!= 0){
        if(a -> val < b -> val){
            if(temp == 0){
                temp = a;
                result = temp;
            } else {
                temp -> next = a;
                temp = a;
            }
            a = a -> next;
        } else {
            if(temp == 0){
                temp = b;
                result = temp;
            } else {
                temp -> next = b;
                temp = b;
            }
            b = b -> next;
        }
    }

    while(a != 0){
        temp -> next = a;
        temp = a;
        a = a -> next;
    }

    while(b != 0){
        temp -> next = b;
        temp = b;
        b = b -> next;
    }
    // cout << "Merged!" << endl;
    // printLinkedList(result);

    return result;
}

ListNode *MergeSort(ListNode *head){
    if(head == 0){
        return head;
    }

    // cout << "Active Linked List is: " << endl;
    // printLinkedList(head);
    if(head -> next == 0){
        return head;
    }

    // Divide list in halfs
    ListNode *temp = head;

    ListNode *fast = temp;
    ListNode *slow = temp;
    ListNode *prev = 0;
    
    while(fast != 0){
        fast = fast -> next;
        if(fast != 0){
            fast = fast -> next;
            prev = slow;
            slow = slow -> next;
        }
    }
    
    // slow is at mid point now.
    ListNode *first = head;
    // Store the value of node next to slow
    ListNode *mid = slow;
    // End the slow linked list
    if(prev != 0){
        prev -> next = 0;
    }
    

    ListNode* firstRef = MergeSort(first);
    ListNode* midRef = MergeSort(mid);

    // cout << "Need to merge " << endl;
    // printLinkedList(firstRef);
    // cout << "And this list: " << endl;
    // printLinkedList(midRef);
    temp = SortMerge(firstRef, midRef);

    return temp;
}

ListNode *solve(ListNode *head){
    // cout << "Starting sort: " << endl;
    head = MergeSort(head);
    return head;
}

int main(){
    vector<int> a = {1, 5, 4, 3};
    ListNode *head = createLinkedList(a);
    cout << "Given linked list is: " << endl;
    printLinkedList(head);

    ListNode *result = solve(head);
    cout << "Result: " << endl;
    printLinkedList(result);
    return 0;
}

// g++ -std=c++11