# A simple linked list

This is a rudamentary basic implementation of a linked list.

A linked list is made of nodes which store a value and a pointer to the next
node. Only a reference to the first node is kept. To get the n-th node. We
access the Node.next element `n` times.

This makes access `O(n)`. The linked list has an advantage over ArrayLists
when removing values. In ArrayLists if the first value is removed, all
subsequent values have to be shifted back, which is an `O(n)` operation. This
is similar for insertion.

In linked list, removal and insertion are `O(1)`, since we can simply hook up
the pointers to a new node as needed. However, since lookup is `O(n)`
linked-list insertion is also `O(n)`, but it should be noted that traversal
takes fewer operatoins than memory transfer.

# A Caveat on Linked Lists
Linked lists are relatively speaking inefficient on modern CPUs due to cache
miss issues (since data may be stored in very desperate parts of the heap).
