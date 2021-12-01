/*
Doubly Linked List Implementation
Each node in a list consists of at least three parts:
    1. Data
    2. Pointer to the previous node
    3. pointer to the next node

An example of a doubly linked list node with an integer data.
// A Doubly Linked list node
struct DoublyLinkedList
{
  int val;
  struct DoublyLinkedList *next, *pre;
};


*/