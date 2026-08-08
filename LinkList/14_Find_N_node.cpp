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
Node * returnN(Node*head,int n)
{   if(!head->next ||n<=0)
    {
        return NULL;
    }
    Node*temp=head;
    int count =0;
    while(temp)
    {
        count++;
        temp=temp->next;
    }
    if(count<n)
    {
        return NULL;
    }
    // NOW AB PEECHE HAT
    int k=0;
    temp=head;
    while(k<count-n)
    {
        k++;
        temp=temp->next;
    }
    
    
    return temp;
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
    head->next->next=new Node(20);
    head->next->next->next=new Node(30);
    head->next->next->next->next=new Node(40);
     print(head);
    Node*value=returnN(head,2);
    cout<<value->data;
    
    return 0;
    
}