/*
Merge two sorted linked lists and return it as a new list. 

The new list should be made by splicing together the nodes of the first two lists, and should also be sorted.

For example, given following linked lists :

  5 -> 8 -> 20 
  4 -> 11 -> 15
The merged list should be :

4 -> 5 -> 8 -> 11 -> 15 -> 20
*/

/*
We have already solved it.
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

ListNode *solve(ListNode *a, ListNode *b){
    ListNode *result = 0;
    ListNode *temp = result;

    while(a!=0 && b!=0){
        if(a -> val < b->val){
            if(result == 0){
                temp = a;
                result = temp;
            } else {
                temp -> next = a;
                temp = a;
            }
            a = a -> next;
        } else {
            if(result == 0){
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
        temp->next = a;
        temp = a;
        a = a -> next;
    }

    while(b != 0){
        temp -> next = b;
        temp = b;
        b = b -> next;
    }

    return result;
}

int main(){
    vector<int> a = {1,2,3,4,5};
    ListNode *head1 = createLinkedList(a);
    vector<int> b = {3,4,5,6,7};
    ListNode *head2 = createLinkedList(b);
    cout << "Given linked lists are: " << endl;
    printLinkedList(head1);
    printLinkedList(head2);

    ListNode *result = solve(head1, head2);
    cout << "Result: " << endl;
    printLinkedList(result);
    return 0;
}

// g++ -std=c++11