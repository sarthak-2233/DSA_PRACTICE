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

Node* middle(Node*head)
{
    if(head==nullptr||head->next==nullptr)
    return 0;
    
    Node*slow=head;
    Node*fast=head;
    
    while(fast&&fast->next)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
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
    head->next=new Node(20);
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    Node*result=middle(head);
    cout << "Middle node data: " << result->data << endl;
    print(head);
    
    return 0;
}