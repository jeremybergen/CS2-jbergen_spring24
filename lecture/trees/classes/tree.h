#pragma once
// #ifndef TREE_H
// #define TREE_H

#include "node.h"
#include <iostream>

template <class T1>
class Tree
{
    private:
    Node<T1>* _root;
    Node<T1>* insertNode(Node<T1>*, T1);
    void inOrderPrint(Node<T1>*);
    Node<T1>* searchData(Node<T1>*, T1);
    Node<T1>* removeNode(Node<T1>*, T1);
    Node<T1>* minVal(Node<T1>*);
    void destroyTree(Node<T1>*);

    public:
    ~Tree();
    void insert(T1);
    void inOrder();
    bool search(T1);
    void remove(T1);
};

template <class T1>
void Tree<T1>::destroyTree(Node<T1>* root)
{
    if(root == nullptr)
    {
        return;
    }
    destroyTree(root->getLeft());
    destroyTree(root->getRight());
    std::cout << "Freeing: " << &root << std::endl;
    delete root;
}

template <class T1>
Tree<T1>::~Tree()
{
    // destroyTree(_root);
    if(_root != nullptr) delete _root;
}

template <class T1>
Node<T1>* Tree<T1>::removeNode(Node<T1>* root, T1 data)
{
    if(root == nullptr) return root;

    if(data < root->getData())
    {
        root->setLeft(removeNode(root->getLeft(), data));
    }
    else if(data > root->getData())
    {
        root->setRight(removeNode(root->getRight(), data));
    }
    else
    {
        if(root->getLeft() == nullptr)
        {
            Node<T1>* tmpNode = root->getRight();
            delete root;
            return tmpNode;
        }
        else if(root->getRight() == nullptr)
        {
            Node<T1>* tmpNode = root->getLeft();
            delete root;
            return tmpNode;
        }
        Node<T1>* tmpNode = minVal(root->getRight());

        root->setData(tmpNode->getData());
        root->setRight(removeNode(root->getRight(), tmpNode->getData()));
    }
    return root;
}

template <class T1>
Node<T1>* Tree<T1>::minVal(Node<T1>* root)
{
    Node<T1>* curNode = root;
    while(curNode != nullptr && curNode->getLeft() != nullptr)
    {
        curNode = curNode->getLeft();
    }
    return curNode;
}

template <class T1>
void Tree<T1>::remove(T1 data)
{
    _root = removeNode(_root, data);
}

template <class T1>
bool Tree<T1>::search(T1 data)
{
    Node<T1>* foundNode;
    foundNode = searchData(_root, data);
    if(foundNode == nullptr)
    {
        return false;
    }
    return true;
}

template <class T1>
Node<T1>* Tree<T1>::searchData(Node<T1>* root, T1 data)
{
    if(root == nullptr || root->getData() == data)
    {
        return root;
    }

    if(data < root->getData())
    {
        return searchData(root->getLeft(), data);
    }
    return searchData(root->getRight(), data);
}

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
// #endif