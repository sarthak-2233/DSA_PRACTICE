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

int CountNode(Node*head)
{
    if(head==nullptr)
    return 0;
    
    int count=0;
    while(head)
    {
        head=head->next;
        count++;
    }
    return count;
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
    int findcount=CountNode(head);
    cout<<findcount<<endl;
    print(head);
    
    return 0;
}