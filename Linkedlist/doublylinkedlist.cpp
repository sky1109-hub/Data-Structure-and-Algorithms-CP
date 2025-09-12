#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL) {}
};
void insertatbegin(Node *&head, int val)
{
    if (!head)
        head = new Node(val);
    else
    {
        Node *New = new Node(val);
        New->next = head;
        head->prev = New;
        head = New;
    }
}
void insertatend(Node *&head, int val)
{
    Node *temp = head;
    if (!head)
        head = new Node(val);

    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        Node *New = new Node(val);
        New->prev = temp;
        temp->next = New;
    }
}
void deleteatbegin(Node *&head)
{
    if (!head)
        return;
    else
    {
        head = head->next;
    }
}
void deleteatend(Node *&head)
{
    Node *temp = head, *prev1 = NULL;
    if (!head)
        return;

    else
    {
        while (temp->next != NULL)
        {
            prev1 = temp;
            temp = temp->next;
        }
        prev1->next = NULL;
        delete(temp);
    }
}
    void print(Node * head)
    {
        while (head != NULL)
        {
            cout << head->data;
            if (head->next)
                cout << " -> ";
            head = head->next;
        }
        cout << endl;
    }
    int main()
    {
        Node *head = new Node(1);
        insertatbegin(head, 0);
        insertatend(head, 2);
        insertatend(head, 3);
        // deleteatbegin(head);
             deleteatend(head);

        print(head);

        return 0;
    }