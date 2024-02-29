#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node* next = nullptr;
};

void printList(Node);
// void appendNode(Node*, Node*);
// void insertNode(Node*, Node*);
void insertNode(Node**, Node**, Node**);
void deleteNode(Node**, int);
Node* findLocation(Node*, int);
void freeMem(Node*);

int main(int argc, char* argv[])
{
    Node* node1 = new Node();
    int numNodes;

    cout << "How many numbers to you want to add? ";
    cin >> numNodes;

    cout << "Enter a number: ";
    cin >> node1->data;
    for(int i = 1; i < numNodes; i++)
    {
        Node* newNode = new Node();
        Node* prevNode;
        // cout << "DEBUG: newNode: " << newNode << endl;
        cout << "Enter a number: ";
        cin >> newNode->data;
        // appendNode(node1, newNode);
        prevNode = findLocation(node1, newNode->data);
        insertNode(&prevNode, &newNode, &node1);
    }

    printList(*node1);
    deleteNode(&node1, 123);
    printList(*node1);
    // cout << "DEBUG: node1.data: " << node1.next->data << endl;
    // cout << "DEBUG: node1.next: " << node1.next->next << endl;

    // Node node1;
    // Node node2;
    // Node node3;

    // node1.data = 42;
    // node2.data = 15;
    // node3.data = 9000;

    // node1.next = &node2;
    // node2.next = &node3;

    // cout << node1.data << endl;
    // cout << node1.next->data << endl;
    // cout << node1.next->next->data << endl;
    // printList(node1);

    // Node newNode;
    // appendNode(&node1, &newNode);
    // printList(node1);
    freeMem(node1);
    return 0;
}

void deleteNode(Node** head, int data)
{
    Node* prevNode = *head;
    Node* curNode = *head;
    while(curNode->next != nullptr && curNode->data != data)
    {
        prevNode = curNode;
        curNode = curNode->next;
    }

    if(curNode->next == nullptr && curNode->data != data)
    {
        cout << "Element not found" << endl;
    }
    else if (curNode->next == nullptr)
    {
        prevNode->next = nullptr;
        delete curNode;
    }
    else
    {
        prevNode->next = curNode->next;
        delete curNode;
    }
}

Node* findLocation(Node* head, int data)
{
    // list only has one entry
    if(head->next == nullptr || head->data >= data)
    {
        if(head->data > data)
        {
            return nullptr;
        }
        return head;
    }

    //list has more than one entry
    while(head->next != nullptr && head->next->data < data)
    {
        head = head->next;
    }

    return head;
}

void insertNode(Node** prevNode, Node** newNode, Node** head)
{
    if((*prevNode) == nullptr)
    {
        (*(*newNode)).next = *head;
        *head = *newNode;
    }
    else
    {
        (*newNode)->next = (*prevNode)->next;
        (*prevNode)->next = *newNode;
    }
}

// void insertNode(Node* head, Node* newNode)
// {
//     Node* curNode = head;
//     Node* nxtNode = head;
//     while(curNode->next != nullptr && newNode->data > curNode->next->data)
//     {
//         curNode = curNode->next;
//         nxtNode = nxtNode->next;
//     }

//     nxtNode = nxtNode->next;
//     curNode->next = newNode;
//     newNode->next = nxtNode;
// }

void freeMem(Node* head)
{
    Node* tmpNode = head;
    // Node* curNode = head;
    while(tmpNode->next != nullptr)
    {
        Node* curNode = tmpNode;
        tmpNode = tmpNode->next;
        // cout << "DELETING: " << endl;
        // cout << "DEBUG: curNode->data: " << curNode->data << endl;
        // cout << "DEBUG: curNode->next: " << curNode->next << endl;
        // cout << "Next: " << endl;
        // cout << "DEBUG: tmpNode->data: " << tmpNode->data << endl;
        // cout << "DEBUG: tmpNode->next: " << tmpNode->next << endl;
        delete curNode;
    }
    delete tmpNode;
}

// void appendNode(Node* head, Node* newNode)
// {
//     // Node newNode;
//     Node* tmpNode = head;
//     while(tmpNode->next != nullptr)
//     {
//         tmpNode = tmpNode->next;
//     }
//     // end of the list
    
//     // newNode->data = 8;
//     // newNode->next = nullptr;
//     tmpNode->next = newNode;
// }

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