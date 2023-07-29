#include <bits/stdc++.h>
using namespace std;

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *newHead = NULL;
    while (head != NULL)
    {
        LinkedListNode<int> *next = head->next;
        head->next = newHead;
        newHead = head;
        head = next;
    }
    return newHead;
}