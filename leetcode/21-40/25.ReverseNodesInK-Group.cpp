/**
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

E.g. 1
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

E.g. 2
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Constraints:

    The number of nodes in the list is n.
    1 <= k <= n <= 5000
    0 <= Node.val <= 1000


*/
#include<bits/stdc++.h>
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

ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode *result = nullptr;

    // edge case
    if (k == 1) {
        // cout << "K value is 1" << endl;
        return head;
    }

    // our k sized vector
    vector<int> arr = {};
    ListNode *currentHead = head;
    while (currentHead != nullptr) {
        int val = currentHead->val;
        currentHead = currentHead -> next;
        arr.push_back(val);

        if (arr.size() == k) {
            for (int i=arr.size() - 1; i>=0; i--) {
                result = addToList(result, arr[i]);
            }
            arr.clear();
        }
    }

    if (arr.size() > 0) {
        for (int i=0; i<arr.size(); i++) {
            result = addToList(result, arr[i]);
        }
    }

    return result;
}

int main() {
    vector< vector<int>> inputs = {{1,2,3,4,5}, {1,2,3,4,5}};
    vector<int> ks = {2, 3};
    vector<vector<int>> outputs = {{2,1,4,3,5}, {3,2,1,4,5}};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Input: " << endl;
        printVector(inputs[i]);

        cout << "K: " <<  ks[i] << endl;

        ListNode *head = vectorToList(inputs[i]);
        ListNode *result = reverseKGroup(head, ks[i]);

        cout << "Output: " << endl;
        printList(result);

        cout << "Expected Output: " << endl;
        printVector(outputs[i]);
        cout << endl;
    }

    return 0;
}

// Accepted. Remember we just need to reverse the k sized group.

