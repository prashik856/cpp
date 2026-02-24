/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6


Example 2:

Input: lists = []
Output: []

Example 3:

Input: lists = [[]]
Output: []

Constraints:

    k == lists.length
    0 <= k <= 10^4
    0 <= lists[i].length <= 500
    -10^4 <= lists[i][j] <= 10^4
    lists[i] is sorted in ascending order.
    The sum of lists[i].length will not exceed 104.

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

void print2Dvector(vector<vector<int>> &arr) {
    for (int i=0; i<arr.size(); i++) {
        printVector(arr[i]);
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

ListNode* mergeKLists(vector<ListNode*>& lists) {
    ListNode *result = nullptr;

    // edge case
    if (lists.size() == 0) {
        return result;
    }

    ListNode *minValue;
    int minIndex = -1;
    while (true) {
        minIndex = -1;
        minValue = new ListNode(INT_MAX, nullptr);

        for (int i=0; i<lists.size(); i++) {
            if (lists[i] != nullptr && lists[i] -> val < minValue -> val) {
                minValue = lists[i];
                minIndex = i;
            }
        }

        if (minIndex != -1) {
            // Now that I have my minimum value.
            result = addToList(result, minValue -> val);

            // update minIndex vector
            lists[minIndex] = lists[minIndex] -> next;
        } else {
            // all values of lists[i] are nullptr
            break;
        }
    }

    // cout << "Output obtained is: " << endl;
    // printList(result);

    return result;
}

int main() {
    vector<vector<vector<int>>> inputs = {{{1,4,5}, {1,3,4}, {2,6}}, {}, {{}}};
    vector<vector<int>> outputs = {{1,1,2,3,4,4,5,6}, {}, {}};

    for (int i=0; i<inputs.size(); i++) {
        cout << "Input: " << endl;
        print2Dvector(inputs[i]);

        vector<ListNode*> lists;
        // Create the linked list
        for (int j=0; j<inputs[i].size(); j++) {
            ListNode *node = vectorToList(inputs[i][j]);
            lists.push_back(node);
        }

        for (int j=0; j<lists.size(); j++) {
            cout << "Created List is: " << endl;
            printList(lists[j]);
            cout << endl;
        }

        ListNode *output = mergeKLists(lists);
        cout << "Output in list: " << endl;
        printList(output);

        vector<int> outputVector = listToVector(output);
        cout << "Output in vector: " << endl;
        printVector(outputVector);

        cout << "Expected output: " << endl;
        printVector(outputs[i]);
    }

    return 0;
}


// Accepted. We haven't removed unwanted vectors, so that is expected.
// But our solution worked.