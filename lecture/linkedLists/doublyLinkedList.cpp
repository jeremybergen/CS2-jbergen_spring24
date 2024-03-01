#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next = nullptr;
    Node* prev = nullptr;
};

void printList(Node*);
void printRevList(Node*);
void deleteNode(Node*, int);
void insertNode(Node*, Node*);

int main(int argc, char* argv[])
{
    Node* head = new Node();
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* tail = new Node();

    head->data = 42;
    node1->data = 15;
    node2->data = 64;
    node3->data = 9000;
    tail->data = -8;

    head->next = node1;

    node1->prev = head;
    node1->next = node2;

    node2->prev = node1;
    node2->next = node3;

    node3->prev = node2;
    node3->next = tail;

    tail->prev = node3;

    printList(head);
    printRevList(tail);

    deleteNode(head, 64);
    printList(head);
    printRevList(tail);

    insertNode(node3, node2);
    printList(head);
    printRevList(tail);

    

    delete head;
    delete node1;
    delete node2;
    delete node3;
    delete tail;
    return 0;
}

void insertNode(Node* prevNode, Node* newNode)
{
    prevNode->next->prev = newNode;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    
}

void deleteNode(Node* head, int data)
{
    while(head->next != nullptr && head->data != data)
    {
        head = head->next;
    }

    if(head->data == data)
    {
        head->prev->next = head->next;
        head->next->prev = head->prev;
        // delete head;
    }
    else
    {
        cout << "Element not found" << endl;
    }
}

void printList(Node* head)
{
    while(head->next != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data << endl;
}

void printRevList(Node* tail)
{
    while(tail->prev != nullptr)
    {
        cout << tail->data << " ";
        tail = tail->prev;
    }
    cout << tail->data << endl;
}