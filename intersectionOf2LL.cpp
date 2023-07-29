#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *findIntersection(Node *firstHead, Node *secondHead)
{
    Node *first = firstHead;
    Node *second = secondHead;

    while (first != second)
    {
        first = first == NULL ? secondHead : first->next;
        second = second == NULL ? firstHead : second->next;
    }

    return first;
}
