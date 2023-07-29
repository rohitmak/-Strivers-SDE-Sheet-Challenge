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

Node *firstNode(Node *head)
{
    unordered_set<Node *> st;
    while (head != NULL)
    {
        if (st.find(head) != st.end())
            return head;
        st.insert(head);
        head = head->next;
    }
    return NULL;
}