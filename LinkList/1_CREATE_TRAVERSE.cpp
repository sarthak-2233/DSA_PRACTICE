#include <iostream>

using namespace  std;

// create a node pointer

struct Node {
    int data;
    Node* next;

    Node(int x)
    {
        data=x;
        next=nullptr;
    }

};

// call it 
void printlist(Node*head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}


int main()
{
    Node*head=new Node(10);
    head->next=new Node(20);
     head->next->next=new Node(20);
     head->next->next->next=new Node(20);

     printlist(head);

     return 0;
}