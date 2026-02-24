/*
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the
values in the list's nodes (i.e., only nodes themselves may be changed.)

Example 1:

Input: head = [1,2,3,4]

Output: [2,1,4,3]


Example 2:

Input: head = []

Output: []

Example 3:

Input: head = [1]

Output: [1]

Example 4:

Input: head = [1,2,3]

Output: [2,1,3]

Constraints:

    The number of nodes in the list is in the range [0, 100].
    0 <= Node.val <= 100

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

ListNode *swap(ListNode *node1, ListNode *node2, ListNode *previousNode) {
    if (previousNode == nullptr) {
        ListNode *tempNode = node2 -> next;
        node2 -> next = node1;
        node1 -> next = tempNode;
    } else {
        ListNode *tempNode = node2 -> next;
        node2 -> next = node1;
        node1 -> next = tempNode;
        previousNode -> next = node2;
    }

    return node2;
}

ListNode* swapPairs(ListNode* head) {
    // empty
    if (head == nullptr) {
        // cout << "Head is null: " << endl;
        return head;
    }

    // single
    if (head -> next == nullptr) {
        // cout << "Only one eleent: " << endl;
        return head;
    }

    ListNode *previousNode = nullptr;
    ListNode *currentNode = head;
    ListNode *adjacentNode = nullptr;
    ListNode *nextNode = nullptr;
    while (true) {
        if (currentNode == nullptr) {
            break;
        }

        // we have our adjacent node and current Node
        adjacentNode = currentNode -> next;
        if (adjacentNode == nullptr) {
            // no point of swapping
            break;
        }

        // first timme
        if (previousNode == nullptr) {
            nextNode = adjacentNode -> next;
            head = swap(currentNode, adjacentNode, previousNode);
            currentNode = nextNode;
            previousNode = head -> next;
        } else {
            nextNode = adjacentNode -> next;
            adjacentNode = swap(currentNode, adjacentNode, previousNode);
            currentNode = nextNode;
            previousNode = adjacentNode -> next;
        }
    }

    // cout << "Output is: " << endl;
    // printList(head);

    return head;
}

int main() {
    vector<vector<int>> inputs = {{1,2,3,4}, {}, {1}, {1,2,3}, {1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5}};
    vector<vector<int>> outputs = {{2,1,4,3}, {}, {1}, {2,1,3}, {2, 1, 4, 3, 6, 5}, {2, 1, 4, 3, 5}};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Input is: " << endl;
        printVector(inputs[i]);

        ListNode *input = vectorToList(inputs[i]);

        ListNode *output = swapPairs(input);
        cout << "Output is: " << endl;
        printList(output);

        cout << "Expected output is: " << endl;
        printVector(outputs[i]);
        cout << endl;
    }

    return 0;
}

// Remember in linked lists, we also need to take care of the previous node too when swapping nodes.