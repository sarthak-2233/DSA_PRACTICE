#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int x) : data(x), next(nullptr) {}
};

Node* reverseList(Node* head) {
    Node* prev = nullptr;

    while (head) {
        Node* next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }

    return prev;
}

bool isPalindrome(Node* head) {
    if (!head || !head->next)
        return true;

    Node* slow = head;
    Node* fast = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* second = reverseList(slow->next);
    Node* copySecond = second;

    Node* first = head;

    bool result = true;

    while (second) {
        if (first->data != second->data) {
            result = false;
            break;
        }

        first = first->next;
        second = second->next;
    }

    slow->next = reverseList(copySecond);

    return result;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);

    cout << (isPalindrome(head) ? "Palindrome" : "Not Palindrome");

    return 0;
}