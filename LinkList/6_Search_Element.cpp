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


Node* Find(Node* head, int value)
{
    if(head == nullptr)
    {
        cout << "Empty list" << endl;
        return nullptr;
    }
    int count =0;
    Node* curr = head;
    while(curr != nullptr)  
    {   count++;
        if(curr->data == value)
        {
            cout << "VALUE FOUND at Place: " << count << endl;
            return curr;  
        }
        curr = curr->next;  
    }
    
    cout << "VALUE NOT FOUND" << endl;
    return nullptr;}


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
    Node* result = Find(head, 30);
    print(head);
    
    return 0;
}