#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

Node* particular(Node* head, int x, int pos)
{
    Node* temp = new Node(x);
    
    if (pos == 0) {
        temp->next = head;
        return temp;
    }
    if (head == nullptr) {
        delete temp;
        return nullptr;
    }
    
    Node* current = head;
    int count = 0;
    
    while (count < pos - 1 && current->next != nullptr) {
        current = current->next;
        count++;
    }
    
    // Check if position is valid
    if (count != pos - 1) {
        // Position is beyond the end of the list
        delete temp;
        return head;  // Or handle as error
    }
    
    // Insert the new node
    temp->next = current->next;
    current->next = temp;
    
    return head;
}  // Removed the extra closing brace

void print(Node* head)
{
    while(head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    // Create a list: 10 -> 20 -> 30
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    
    cout << "Original list: ";
    print(head);
    
    // Test cases
    cout << "\nInsert 5 at position 0 (head): ";
    head = particular(head, 5, 0);
    print(head);
    
    cout << "Insert 15 at position 2: ";
    head = particular(head, 15, 2);
    print(head);
    
    cout << "Insert 35 at position 5 (end): ";
    head = particular(head, 35, 5);
    print(head);
    
    cout << "Insert 100 at position 10 (invalid - beyond end): ";
    head = particular(head, 100, 10);
    print(head);
    
    // Test with empty list
    cout << "\nTesting with empty list:";
    Node* empty = nullptr;
    empty = particular(empty, 50, 0);
    cout << "\nInsert 50 at position 0: ";
    print(empty);
    
    empty = particular(empty, 60, 1);
    cout << "Insert 60 at position 1 (invalid): ";
    print(empty);
    
    return 0;
}