#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next = nullptr;
};

void printList(Node);
void appendNode(Node, Node&);

int main(int argc, char* argv[])
{
    Node node1;
    Node node2;
    Node node3;

    node1.data = 42;
    node2.data = 15;
    node3.data = 9000;

    node1.next = &node2;
    node2.next = &node3;

    // cout << node1.data << endl;
    // cout << node1.next->data << endl;
    // cout << node1.next->next->data << endl;
    printList(node1);

    Node newNode;
    appendNode(node1, newNode);
    printList(node1);
    return 0;
}

void appendNode(Node head, Node& newNode)
{
    // Node newNode;
    Node* tmpNode = &head;
    while(tmpNode->next != nullptr)
    {
        tmpNode = tmpNode->next;
    }
    // end of the list
    
    newNode.data = 8;
    newNode.next = nullptr;
    tmpNode->next = &newNode;
}

void printList(Node head)
{
    Node* tmpNode = &head;
    while (tmpNode->next != nullptr)
    {
        cout << tmpNode->data << " ";
        tmpNode = tmpNode->next;
    }
    cout << tmpNode->data << endl;
}