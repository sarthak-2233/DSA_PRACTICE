#include<iostream>
using namespace std;

struct Node{
  int data;
  Node*next;
  
  Node(int x)
  {
      data=x;
      next=nullptr;
  }
};


Node* atend(Node*head,int x)
{   
    Node*temp=new Node(x);
    if(head==NULL)
    return head;
    
    Node*curr=head;
    while(curr->next!=nullptr)
    {
        curr=curr->next;
    }
    curr->next=temp;
    
    return curr;
}

void print(Node*head)
{
    while(head)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main()
{
    Node*head=new Node(10);
    head=atend(head,20);
    print(head);
    return 0;
}