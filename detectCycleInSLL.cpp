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

bool detectCycle(Node *head)
{
    unordered_set<Node *> hashTable;
    while (head != NULL)
    {
        if (hashTable.find(head) != hashTable.end())
            return true;
        hashTable.insert(head);
        head = head->next;
    }
    return false;
}