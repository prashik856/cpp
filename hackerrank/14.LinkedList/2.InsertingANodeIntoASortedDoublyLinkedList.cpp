// Problem : https://www.hackerrank.com/challenges/insert-a-node-into-a-sorted-doubly-linked-list/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=linked-lists
#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
    public:
        int data;
        DoublyLinkedListNode *next;
        DoublyLinkedListNode *prev;

        DoublyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
            this->prev = nullptr;
        }
};

class DoublyLinkedList {
    public:
        DoublyLinkedListNode *head;
        DoublyLinkedListNode *tail;

        DoublyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
                node->prev = this->tail;
            }

            this->tail = node;
        }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

/*
 * Complete the 'sortedInsert' function below.
 *
 * The function is expected to return an INTEGER_DOUBLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_DOUBLY_LINKED_LIST llist
 *  2. INTEGER data
 */

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */

DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode *temp = llist;
    DoublyLinkedListNode *node = new DoublyLinkedListNode(data);
    bool found = false;
    
    // head null
    if(temp == 0){
        llist = node;
        return llist;
    }
    
    // smaller than head
    if(data <= temp -> data){
        // put head as node 
        temp -> prev = node;
        node -> next = temp;
        llist = node;
        return llist;
    }
    
    // only head is present
    // already checked if data is less than head
    if(temp -> next == 0){
        temp -> next = node;
        node -> prev = temp;
        return llist;
    }
    
    // We have already checked if data is less than temp -> data
    temp = temp -> next;
    
    // We have atleast 2 elements in linked list now
    while(!found){
        if(data > temp -> prev -> data && data < temp -> data){
            // found our node
            DoublyLinkedListNode *prev = temp -> prev;
            
            prev -> next = node;
            node -> prev = prev;
            
            node -> next = temp;
            temp -> prev = node;
            return llist;
        } else if(temp -> data == data){
            // insert
            DoublyLinkedListNode *prev = temp -> prev;
            
            prev -> next = node;
            node -> prev = prev;
            
            node -> next = temp;
            temp -> prev = node;
            return llist;
        }
        
        if(data > temp -> data){
            if(temp -> next != 0){
                temp = temp -> next;
                continue;
            } else {
              // temp -> next is null
              temp -> next = node;
              node -> prev = temp;
              return llist;  
            }
        }   
    }
    return llist;
}

int main()