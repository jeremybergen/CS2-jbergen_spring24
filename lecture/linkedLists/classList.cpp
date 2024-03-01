#include <iostream>

using namespace std;

template <class T1>
class Node
{
    private:
    T1 _data;
    Node<T1>* _next;
    Node<T1>* _prev;

    public:
    Node(T1, Node<T1>* = nullptr);
    void setData(T1);
    void setNext(Node<T1>*);
    void setPrev(Node<T1>*);
    Node<T1>* getNext();
};

template <typename T1>
class List
{
    private:
    Node<T1>* _head = nullptr;
    Node<T1>* _tail = nullptr;

    public:
    void push_back(T1);
    void printList();
};

int main(int argc, char* argv[])
{
    return 0;
}

template <class T1>
Node<T1>::Node(T1 data, Node<T1>* next)
{
    _data = data;
    _next = next;
}   