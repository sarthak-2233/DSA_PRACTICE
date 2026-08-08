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

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;

    while (curr) {
        Node* nextNode = curr->next;

        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }

    return prev;
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
 
    head=reverseList(head);
    print(head);
    
    return 0;
    
}