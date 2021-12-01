/*
Doubly Linked List

A doubly linked list is a data structure where a set of sequential links of records called nodes exist. 
Unlike the singly linked list, a node of a doubly linked list consists of three fields: 
    two link fields and one information field. 
Two link fields provide information about the address of previous nodes and the next nodes in the sequence and one data field.

The link fields are also known as “previous” and “next” pointers and store the addresses of the previous and next nodes in the list. 
And the previous pointer of the very first node, as well as the next pointer of the last node points 
to a Null value or called a sentinel node.

Syntax:

Struct node{

    int data;

    struct node *next, *prev;

    *head;
}

Where struct keyword refers to a structure, node is the name of the structure, data is the information field which 
contains only integer values, *next is the pointer of type structure which holds the address of the next node in 
the sequential list, and *prev is the pointer of the type structure and hold the address of the previous node in the sequential list.


Working of a Doubly linked list:
> Insertion
    Insert after
    Insert before
    Insert at the end
    Insert at the first position, respectively.
> Deletion
> Display
> Searching


1.Insertion:
Insert at the first position: 
When a new node is inserted at the first position of the doubly linked list, it becomes the new head. 
Start by creating the node and inserting the data value in it. 
Next change the pointer references of the old and new head node. 
The prev pointer of the new node should be pointed to a NULL value, 
whereas the next pointer should be pointed towards the old head. 
Similarly, the prev pointers of the old head which was set to NULL should be pointing to the new head.

Insert at the end: 
When a new node is inserted at the last position of the doubly linked list, 
it requires a couple of changes as the previous last node now becomes the second last node. 
The next pointer of the previous last node should now be changed from null value and point towards the newly inserted node. 
The next of the newly inserted last node should now point towards null value and the prev pointer of this very node points to 
the older last node which is now the second last node.

Insert before: 
Suppose we have a node called A and the next node to A is C. 
Now we have to insert a node before C. 
When a new node is created which is to be placed before C requires the following changes. 
First the next pointer of this new node will point to node C and the prev pointer of this new node will point to A. 
Whereas the next pointer of node A will point to the newly inserted node and the previous pointer of node C will now 
point to the node inserted before C.


Insert after: 
Suppose we have a node called A and the next note to A is C. 
Now to insert a node after node we follow the steps similar to when we insert a node before any particular node. 
If a node B is to be placed after node A then the following changes need to be encountered. 
First we start with creating a new node and this node needs to be inserted after node A so the previous pointer of this 
node B will point to node A and the next of this node will point to node C. 
Now the next pointer of node A will point to node B, and the previous of node C will point to node B.

2. Deletion:
> If the node to be deleted is the head node, then change the head pointer from the first node 
to second and make the prev pointer of second node as NULL. 
Also, make the next and prev pointers of the older first node as NULL and free the node.
> Else, if the node to be deleted is the last node, then make the prev pointer of the last node as NULL 
and the next pointer of the older second last node as NULL.
> But is the node to be deleted suppose is B and lies in between two nodes A and C, 
then make the next pointer of the node A to point at node C and the prev pointer of node C point to node A. 
Once this is done, make the next and prev pointers of node B as NULL and free the node.

3. Display: 
> It calls for printing the values in some order, be it from first to last or last to first.
> When one wants to print the values in the order first to last, one keeps traversing till the next pointer of a node 
doesn’t point to NULL value.
> And if one wants to print in the last to first manner then, first one traverses till the node whose next pointer doesn’t 
point to NULL value and then prints the values in the reverse fashion, 
till the point where the prev pointer of the node doesn’t point to NULL value.

4. Searching: 
When one wants to search for a node, one keeps traversing the list till the required data value is found. 
Comparing each node’s data with the data value to be searched and return the index of the item found, 
is how searching takes place in a doubly linked list.


*/