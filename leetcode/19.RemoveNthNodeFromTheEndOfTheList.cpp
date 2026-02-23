/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:

Input: head = [1], n = 1
Output: []

Example 3:

Input: head = [1,2], n = 1
Output: [1]

Constraints:

    The number of nodes in the list is sz.
    1 <= sz <= 30
    0 <= Node.val <= 100
    1 <= n <= sz

 */
#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){}
    ListNode(int x): val(x), next(nullptr){}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

void printVector(vector<int> &arr) {
    for (int i=0; i<arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

ListNode *addToList(ListNode *head, int val) {
    if (head == nullptr) {
        head = new ListNode(val);
        return head;
    }

    ListNode *currentNode = head;
    while (true) {
        if (currentNode -> next == nullptr) {
            currentNode -> next = new ListNode(val);
            break;
        }
        currentNode = currentNode -> next;
    }

    return head;
}

void printList(ListNode *head) {
    ListNode *currentNode = head;
    while (currentNode != nullptr) {
        cout << currentNode -> val << " ";
        currentNode = currentNode -> next;
    }
    cout << endl;
}

ListNode *vectorToList(vector<int> &arr) {
    ListNode *head = nullptr;

    for (int i=0; i<arr.size(); i++) {
        int val = arr[i];

        head = addToList(head, val);
    }

    return head;
}

vector<int> listToVector(ListNode *head) {
    ListNode *currentNode = head;
    vector<int> result;
    while (currentNode != nullptr) {
        result.push_back(currentNode->val);
        currentNode = currentNode -> next;
    }
    return result;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    vector<int> arr = listToVector(head);

    arr.erase(arr.begin() + arr.size() - n);

    head = vectorToList(arr);

    return head;
}

int main() {
    vector<vector<int>> inputs = {{1,2,3,4,5}, {1}, {1,2}};
    vector<int> ns = {2, 1, 1};
    vector<vector<int>> outputs = {{1,2,3,5}, {}, {1}};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Input vector is: " << endl;
        printVector(inputs[i]);

        cout << "Value of n is: " << ns[i] << endl;

        ListNode *head = vectorToList(inputs[i]);
        cout << "Linked List created: " << endl;
        printList(head);

        ListNode *outputHead = removeNthFromEnd(head, ns[i]);

        vector<int> output = listToVector(outputHead);
        cout << "Linked List to vector value: " << endl;
        printVector(output);

        cout << "Expected output: " << endl;
        printVector(outputs[i]);
        cout << endl;
    }

    return 0;
}

// Remember how to traverse through the linked list. How to add elements and how to delete them.
