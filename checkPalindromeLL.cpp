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

LinkedListNode<int> *reverse(LinkedListNode<int> *root)
{
    LinkedListNode<int> *prev = NULL;
    LinkedListNode<int> *next = NULL;

    while (root != NULL)
    {
        next = root->next;
        root->next = prev;
        prev = root;
        root = next;
    }

    return prev;
}

bool isPalindrome(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
        return true;

    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverse(slow->next);
    slow = slow->next;
    LinkedListNode<int> *temp = head;

    while (slow != NULL)
    {
        if (temp->data != slow->data)
            return false;
        temp = temp->next;
        slow = slow->next;
    }

    return true;
}