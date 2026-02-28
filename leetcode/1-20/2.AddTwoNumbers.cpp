/**
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]

Constraints:

    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.

The solution accepted.
 */

#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>
using namespace std;

void printVector(vector<int> arr){
    for(int i=0; i<arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Let's create a Linked List here
struct ListNode {
    // Values stored in struct
    int val;
    ListNode *next;

    // Constructors
    ListNode() : val(0), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
    ListNode(int x): val(x), next(NULL) {}
};

void printLinkedList(ListNode *head) {
    if (head == NULL) {
        return;
    }
    cout << head -> val << " ";
    printLinkedList(head -> next);
    return;
}

ListNode *putIntoLinkedList(ListNode *head, int value){
    ListNode *currentNode = head;
    while(true) {
        if (currentNode == NULL) {
            head = new ListNode(value);
            break;
        }

        if (currentNode -> next == NULL) {
            currentNode -> next = new ListNode(value);
            break;
        }

        currentNode = currentNode -> next;
    }

    return head;
}

int main() {
    vector<int> arr1 = {9,9,9,9};
    vector<int> arr2 = {9,9,9,9};

    ListNode *l1 = NULL;
    ListNode *l2 = NULL;

    for (int i=0; i<arr1.size(); i++) {
        l1 = putIntoLinkedList(l1, arr1[i]);
    }

    for (int i=0; i<arr2.size(); i++) {
        l2 = putIntoLinkedList(l2, arr2[i]);
    }

    cout << "Created fist linked list is: " << endl;
    printLinkedList(l1);
    cout << endl;

    cout << "Created second linked list is: " << endl;
    printLinkedList(l2);
    cout << endl;

    // Now I know how to create the linked list and navigate through it
    long carry = 0;
    long value = 0;
    long sum = 0;
    long val1 = 0;
    long val2 = 0;
    ListNode *index1 = l1;
    ListNode *index2 = l2;
    ListNode *resultHead = NULL;

    while (index1 != NULL || index2 != NULL) {
        if (index1 == NULL) {
            val1 = 0;
        } else {
            val1 = index1 -> val;
            index1 = index1 -> next;
        }

        if (index2 == NULL) {
            val2 = 0;
        } else {
            val2 = index2 -> val;
            index2 = index2 -> next;
        }

        sum = val1 + val2 + carry;
        carry = sum/10;
        value = sum % 10;

        resultHead = putIntoLinkedList(resultHead, value);
    }

    if (carry > 0) {
        resultHead = putIntoLinkedList(resultHead, carry);
    }

    cout << "The resulting linked list is: " << endl;
    printLinkedList(resultHead);
    cout << endl;

    return 0;
}