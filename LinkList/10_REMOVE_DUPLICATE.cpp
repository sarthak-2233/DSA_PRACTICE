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

Node* removeDuplicate(Node* head) {
    if(head==NULL)
    return NULL;
    
    Node*curr=head;
    while(curr&& curr->next)
    {
        if(curr->data==curr->next->data)
        {
            Node*temp=curr->next;
            curr->next=temp->next;
            delete temp;
        }
        else
        {
            curr=curr->next;
        }
    }
    return head;
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
    head=removeDuplicate(head);
    print(head);
    
    return 0;
    
}