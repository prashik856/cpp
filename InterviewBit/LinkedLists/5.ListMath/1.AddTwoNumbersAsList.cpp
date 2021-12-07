/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)

Output: 7 -> 0 -> 8

    342 + 465 = 807
Make sure there are no trailing zeros in the output list

So, 7 -> 0 -> 8 -> 0 is not a valid response even though the value is still 807.
*/
/*
Solution Approach:
> Make both of the linked list of equal lenght.
> Add them, calculate carry and currentSum
If last node and currentSum == 0, don't add that node to result, else add this node.
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

ListNode* solve(ListNode *a, ListNode *b){
    if(a == 0 && b == 0){
        return new ListNode(0);
    }

    int lenA = 0;
    int lenB = 0;
    
    ListNode* tailA = 0;
    ListNode* tailB = 0;
    ListNode *temp = a;
    while(temp != 0){
        lenA++;
        if(temp -> next == 0){
            tailA = temp;
        }
        temp = temp -> next;
    }

    temp = b;
    while(temp != 0){
        lenB++;
        if(temp -> next == 0){
            tailB = temp;
        }
        temp = temp -> next;
    }

    ListNode* newNode = new ListNode(0);
    if(lenA > lenB){
        lenA++;
        tailA -> next = newNode;
        tailA = newNode;

        while(lenB < lenA){
            newNode = new ListNode(0);
            tailB -> next = newNode;
            tailB = newNode;
            lenB++;
        }
    } else {
        lenB++;
        tailB -> next = newNode;
        tailB = newNode;
        while(lenA < lenB){
            newNode = new ListNode(0);
            tailA -> next = newNode;
            tailA = newNode;
            lenA++;
        }
    }

    // cout << "Recreated linked lists are: " << endl;
    // printLinkedList(a);
    // printLinkedList(b);

    int carry = 0;
    int currentSum = 0;
    ListNode *headA = a;
    ListNode *headB = b;
    ListNode *result = 0;
    ListNode *resultTail = 0;

    while(headA != 0){
        int valA = headA -> val;
        int valB = headB -> val;

        currentSum = valA + valB + carry;
        carry = currentSum / 10;
        currentSum = currentSum % 10;

        ListNode *newNode = new ListNode(currentSum);
        if(headA -> next == 0){
            // last guy
            if(currentSum == 0){
                break;
            }

            if(result == 0){
                result = newNode;
                resultTail = newNode;
            } else {
                resultTail -> next = newNode;
                resultTail = newNode;
            }
        } else {
            if(result == 0){
                result = newNode;
                resultTail = newNode;
            }
            else {
                resultTail -> next = newNode;
                resultTail = newNode;
            }
        }

        headA = headA -> next;
        headB = headB -> next;
    }

    return result;
}

int main(){
    vector<int> a = {9,9,1};
    ListNode *head1 = createLinkedList(a);
    cout << "Given linked list is: " << endl;
    printLinkedList(head1);
    vector<int> b = {1};
    ListNode *head2 = createLinkedList(b);
    printLinkedList(head2);

    ListNode *result = solve(head1, head2);
    cout << "Result: " << endl;
    printLinkedList(result);
    return 0;
}

// g++ -std=c++11