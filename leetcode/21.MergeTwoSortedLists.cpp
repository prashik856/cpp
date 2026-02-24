/*
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:

Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:

Input: list1 = [], list2 = []
Output: []

Example 3:

Input: list1 = [], list2 = [0]
Output: [0]

Constraints:

    The number of nodes in both lists is in the range [0, 50].
    -100 <= Node.val <= 100
    Both list1 and list2 are sorted in non-decreasing order.

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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode *result = nullptr;

    // edge cases
    if (list1 == nullptr) {
        // cout << "List 1 empty: " << endl;
        return list2;
    }

    if (list2 == nullptr) {
        // cout << "List 2 empty: " << endl;
        return list1;
    }

    ListNode *currentList1 = list1;
    ListNode *currentList2 = list2;

    while (currentList1 != nullptr && currentList2 != nullptr) {
        int val1 = currentList1->val;
        int val2 = currentList2->val;
        if (val1 <= val2) {
            result = addToList(result, val1);
            currentList1 = currentList1 -> next;
        } else {
            result = addToList(result, val2);
            currentList2 = currentList2 -> next;
        }
    }

    // list1 is not empty
    while (currentList1 != nullptr) {
        int val1 = currentList1 -> val;
        result = addToList(result, val1);
        currentList1 = currentList1 -> next;
    }

    // list2 is not empty
    while (currentList2 != nullptr) {
        int val2 = currentList2 -> val;
        result = addToList(result, val2);
        currentList2 = currentList2 -> next;
    }

    return result;
}


int main() {
    vector<vector<int>> list1 = {{1,2,4}, {}, {}};
    vector<vector<int>> list2 = {{1,3,4}, {}, {0}};

    vector<vector<int>> outputs = {{1,1,2,3,4,4}, {}, {0}};

    for (int i=0; i<list1.size(); i++) {
        cout << "List 1 : " << endl;
        printVector(list1[i]);

        cout << "List 2: " << endl;
        printVector(list2[i]);

        ListNode *linkedList1 = vectorToList(list1[i]);
        ListNode *linkedList2 = vectorToList(list2[i]);

        cout << "Linked List 1: " << endl;
        printList(linkedList1);

        cout << "Linked List 2: " << endl;
        printList(linkedList2);

        ListNode *outputList = mergeTwoLists(linkedList1, linkedList2);

        cout << "Output Linked List: " << endl;
        printList(outputList);

        vector<int> output = listToVector(outputList);
        cout << "Output in vector: " << endl;
        printVector(output);

        cout << "Expected Output: " << endl;
        printVector(outputs[i]);

        cout << endl;
    }

    return 0;
}