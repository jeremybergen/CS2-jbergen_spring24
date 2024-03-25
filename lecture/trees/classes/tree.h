#pragma once
#include "node.h"
#include <iostream>

template <class T1>
class Tree
{
    private:
    Node<T1>* _root;
    Node<T1>* insertNode(Node<T1>*, T1);
    void inOrderPrint(Node<T1>*);

    public:
    void insert(T1);
    void inOrder();
};

template <class T1>
void Tree<T1>::insert(T1 data)
{
    _root = insertNode(_root, data);
}

template <class T1>
Node<T1>* Tree<T1>::insertNode(Node<T1>* root, T1 data)
{
    if(root == nullptr)
    {
        Node<T1>* newNode = new Node<T1>();
        newNode->setData(data);
        return newNode;
    }
    
    if(data < root->getData())
    {
        root->setLeft(insertNode(root->getLeft(), data));
    }
    else if(data > root->getData())
    {
        root->setRight(insertNode(root->getRight(), data));
    }
    return root;
}

template <class T1>
void Tree<T1>::inOrderPrint(Node<T1>* root)
{
    if(root == nullptr) return;

    inOrderPrint(root->getLeft());
    std::cout << root->getData() << " ";
    inOrderPrint(root->getRight());
}

template <class T1>
void Tree<T1>::inOrder()
{
    inOrderPrint(_root);
    std::cout << std::endl;
}