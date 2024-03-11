#include <iostream>

using namespace std;

template <class T1>
struct Node
{
    T1 data;
    Node<T1>* left = nullptr;
    Node<T1>* right = nullptr;
};

template <class T1>
Node<T1>* insert(Node<T1>*, T1);

template <class T1>
void printTree(Node<T1>*);

template <class T1>
void freeTree(Node<T1>*);

int main(int argc, char* argv[])
{
    int numNodes = 0;
    Node<float>* root = new Node<float>();
    // Node<int>* child1 = new Node<int>();
    // Node<int>* child2 = new Node<int>();
    // Node<int>* child3 = new Node<int>();

    cout << "How many strings do you want to enter? ";
    cin >> numNodes;

    // root->data = 42;
    for(int i = 0; i < numNodes; i++)
    {
        float data;
        cout << "Enter a string: ";
        if(i == 0)
        {
            cin >> root->data;
            continue;
        }
        cin >> data;
        insert<float>(root, data);
    }
    // insert(root, 15);
    // insert(root, 9000);

    printTree<float>(root);
    cout << endl;
    // child1->data = 15;
    // child2->data = 9000;
    // child3->data = 23;

    // root->left = child1;
    // root->right = child2;
    // child1->right = child3;

    // delete root;
    freeTree<float>(root);
    // delete root;
    // delete child1;
    // delete child2;
    // delete child3;
    return 0;
}

template <class T1>
void freeTree(Node<T1>* root)
{
    if(root == nullptr)
    {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    cout << "Deleting: " << root << endl;
    delete root;
}

template <class T1>
void printTree(Node<T1>* root)
{
    if(root == nullptr)
    {
        return;
    }
    // cout << "DEBUG: root->left: " << root->left << endl;
    
    printTree(root->right);
    cout << root->data << " ";
    // cout << "DEBUG: root->right: " << root->right << endl;
    printTree(root->left);
}

template <class T1>
Node<T1>* insert(Node<T1>* root, T1 data)
{
    if(root == nullptr)
    {
        Node<T1>* newNode = new Node<T1>();
        newNode->data = data;
        return newNode;
        // return new Node<T1>(data);
    }
    if(data > root->data)
    {
        root->right = insert(root->right, data);
    }
    else if(data < root->data)
    {
        root->left = insert(root->left, data);
    }

    return root;
}