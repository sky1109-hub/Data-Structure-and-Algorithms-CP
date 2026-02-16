#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

void insertatbegin(Node *&head, int val)
{
    if (!head)
    {
        head = new Node(val);
    }
    else
    {
        Node *New = new Node(val);
        New->next = head;
        head = New;
    }
}
void insertatend(Node *&head, int val)
{
    if (!head)
    {
        head = new Node(val);
    }
    Node *temp = head;
    Node *New = new Node(val);
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = New;
}
void insertatposition(Node* &head,int val,int pos){

}


void deleteatbegin(Node*& head){
    if(!head) return ;
    Node*temp=head->next;
    head=temp;

}
void deleteatend(Node *&head){
    if(!head) return;
    Node*temp=head;
    Node*prev=NULL;

    if(!head->next) head=NULL;
    while(temp->next!=NULL){
        prev=temp;
        temp=temp->next;
    }
    prev->next=NULL;
}  int findelement(Node*head,int val){
    int pos=-1;
    while(head!=NULL){
        pos++;
        if(head->data==val) break;
        head=head->next;
    }
    return head==NULL?-1:pos;
}
void print(Node *head)
{
    if (!head)
        return;
    while (head != NULL)
    {
        cout << head->data;
        if (head->next)
        {
            cout << "->";
        }
        head = head->next;
    }
    cout<<endl;
}
void reverse(Node* &head){
if(!head ) return ;
    Node* curr=head,*prev=NULL;
    while(curr!=NULL){
        Node* temp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=temp;
    }
    head=prev;


}
int main()
{

    Node *head = NULL;
    insertatbegin(head, 1);
    insertatbegin(head, 2);

    insertatbegin(head, 3);
    insertatend(head, 0);
    // deleteatbegin(head);
    //     deleteatbegin(head);
 // deleteatend(head);

    print(head);
//  int x=findelement(head,4);

//  if(x==-1) cout<<"Element not found"<<endl;
//  else cout<<"Element found at "<<x<<endl;
  reverse(head);
    print(head);

    return 0;
}