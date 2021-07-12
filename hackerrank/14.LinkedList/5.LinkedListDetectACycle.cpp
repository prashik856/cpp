// Problem: https://www.hackerrank.com/challenges/ctci-linked-list-cycle/problem?h_l=interview&playlist_slugs%5B%5D%5B%5D=interview-preparation-kit&playlist_slugs%5B%5D%5B%5D=linked-lists
// Intuition: https://www.hackerrank.com/challenges/ctci-linked-list-cycle/forum
/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head == 0){
        return false;
    }
    
    Node *slow = head -> next;
    if(slow == 0){
        return false;
    } 
    Node *fast = head -> next -> next;
    if(fast == 0){
        return false;
    }
    
    while(slow != 0 && fast != 0) {
        if(slow == fast){
            return true;
        }

        if(slow -> next == 0){
            return false;
        } else {
            slow = slow -> next;    
        }
        
        if(fast -> next == 0){
            return false;
        } else {
            fast = fast -> next;
            if(fast -> next == 0){
                return false;
            } else {
                fast = fast -> next;
            }
        }
    }
    return false;
}