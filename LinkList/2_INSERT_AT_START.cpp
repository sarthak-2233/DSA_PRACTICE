#include<iostream>

using namespace std;

struct Node{
    int data;
    Node* next;
  
  Node(int x)
  {
       data=x;
      Node*next=nullptr;
  }
};

// Printlist
void Printlist(Node*head)
{
    while(head!=nullptr)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* add(Node*head,int x )
{
    Node*temp=new Node(x);
    temp->next=head;
    return temp;
}

int main()
{
    Node* head = new Node(20);
    head->next = new Node(30);

    head = add(head, 10);

    Printlist(head);
    
    return 0;
    
}