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


Node* deleteNode(Node*head,int key)
{
        if(head==nullptr)
        return NULL;
        
        if(head->next==nullptr)
        {
            delete head;
            return 0;
        }
        
    if (head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node* curr = head;

    while (curr->next && curr->next->data != key)
        curr = curr->next;

    if (curr->next) {
        Node* temp = curr->next;
        curr->next = temp->next;
        delete temp;
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
    head->next->next=new Node(30);
    head->next->next->next=new Node(40);
    head=deleteNode(head,30);
    print(head);
    
    return 0;
}