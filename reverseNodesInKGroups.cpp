#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

int lengthLL(Node *head)
{
    int count = 0;
    while (head)
    {
        count++;
        head = head->next;
    }
    return count;
}

Node *getListAfterReverseOperation(Node *head, int n, int b[])
{
    if (head == NULL || head->next == NULL)
        return head;

    int length = lengthLL(head);

    Node *temp = new Node(0);
    temp->next = head;
    Node *prev = temp;
    Node *curr;
    Node *next;

    int i = 0;

    while (length > 0 && i < n)
    {
        if (b[i] == 0)
        {
            i++;
            continue;
        }
        curr = prev->next;
        next = curr->next;

        if (length >= b[i])
        {
            for (int j = 1; j < b[i]; j++)
            {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            length -= b[i];
            i++;
        }
        else if (length < b[i])
        {
            for (int j = 1; j < length; j++)
            {
                curr->next = next->next;
                next->next = prev->next;
                prev->next = next;
                next = curr->next;
            }
            prev = curr;
            length -= b[i];
            i++;
        }
    }

    return temp->next;
}