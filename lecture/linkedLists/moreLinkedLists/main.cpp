#include <iostream>

using namespace std;

template <typename T1>
class Node
{
    private:
    T1 _data;
    Node<T1>* _prev;
    Node<T1>* _next;

    public:
    Node(T1 data, Node<T1>* prev, Node<T1>* next) {_data = data; _prev = prev; _next = next;}
    void setData(T1 data) {_data = data;}
    void setPrev(Node<T1>* prev) {_prev = prev;}
    void setNext(Node<T1>* next) {_next = next;}
    T1 getData() {return _data;}
    Node* getPrev() {return _prev;}
    Node* getNext() {return _next;}
};

template <typename T1>
class List
{
    private:
    Node<T1>* _head = nullptr;
    Node<T1>* _tail = nullptr;
    size_t _size = 0;
    void addEndPrivate(Node<T1>*, T1);
    void addStartPrivate(Node<T1>*, T1);
    T1 removeEnd(Node<T1>*);
    T1 removeStart(Node<T1>*);
    void walkList(Node<T1>*);

    public:
    void addEnd(T1);
    void addStart(T1);
    T1 getEnd();
    T1 getStart();
    void printList();
};

int main(int argc, char* argv[])
{
    List<int>* lList = new List<int>;

    while(true)
    {
        int number;
        cout << "Enter a number, -999 to quit: ";
        cin >> number;
        if(number == -999) break;
        lList->addEnd(number);
    }

    cout << "Printing the list: ";
    lList->printList();

    delete lList;
    return 0;
}

template <typename T1>
void List<T1>::addEndPrivate(Node<T1>* tail, T1 data)
{
    Node<T1>* newNode = new Node<T1>(data, nullptr, nullptr);
    if(_head == _tail && tail == nullptr)
    {
        _head = newNode;
        _tail = newNode;
        _size++;
        return;
    }
    newNode->setPrev(_tail);
    _tail->setNext(newNode);
    _tail = newNode;
    _size++;
}

template <typename T1>
void List<T1>::addStartPrivate(Node<T1>* head, T1 data)
{
    Node<T1>* newNode = new Node<T1>(data, nullptr, nullptr);
    if(_head == _tail && head == nullptr)
    {
        _head = newNode;
        _tail = newNode;
        _size++;
        return;
    }
    newNode->setNext(_head);
    _head->setPrev(newNode);
    _head = newNode;
    _size++;
}

template <typename T1>
T1 List<T1>::removeEnd(Node<T1>* end)
{
    
}

template <typename T1>
T1 List<T1>::removeStart(Node<T1>* head)
{
    
}

template <typename T1>
void List<T1>::addEnd(T1 data)
{
    addEndPrivate(_tail, data);
}

template <typename T1>
void List<T1>::addStart(T1 data)
{
    addStartPrivate(_head, data);
}

template <typename T1>
T1 List<T1>::getEnd()
{
    return removeEnd(_tail);
}

template <typename T1>
T1 List<T1>::getStart()
{
    return removeStart(_head);
}

template <typename T1>
void List<T1>::printList()
{
    walkList(_tail);
    cout << endl;
}

template <typename T1>
void List<T1>::walkList(Node<T1>* curNode)
{
    if(_head == _tail && _tail == nullptr)
    {
        cout << "List is empty";
        return;
    }
    if(curNode == nullptr)
    {
        return;
    }
    cout << curNode->getData() << " ";
    walkList(curNode->getPrev());
}