#include <iostream>

using namespace std;

class Queue
{
    private:
    static const int maxQueue = 100;
    int queueArr[maxQueue];
    int beginning, end;

    public:
    Queue();
    void enqueue(int);
    int dequeue();
    int front();
    bool empty();
    int size();
};

int main(int argc, char* argv[])
{
    Queue myQueue;

    cout << boolalpha << myQueue.empty() << endl;
    cout << myQueue.size() << endl;

    myQueue.enqueue(42);
    myQueue.enqueue(23);
    myQueue.enqueue(9000);
    myQueue.enqueue(5);
    myQueue.enqueue(8);

    cout << myQueue.size() << endl;

    int queueSize = myQueue.size();
    for(int i = 0; i < queueSize; i++)
    {
        cout << myQueue.dequeue() << " ";
    }
    cout << endl;

    cout << boolalpha << myQueue.empty() << endl;
    cout << myQueue.size() << endl;

    return 0;
}

void Queue::enqueue(int data)
{
    if(empty())
    {
        beginning = 0;
        end = 0;
        queueArr[beginning] = data;
        return;
    }
    if(end == maxQueue + 1)
    {
        cout << "Queue is full" << endl;
        return;
    }
    end++;
    queueArr[end] = data;
}

int Queue::dequeue()
{
    if(empty())
    {
        cout << "Queue is empty" << endl;
        return -999;
    }
    int tmpData = queueArr[beginning];
    if(beginning == end)
    {
        
        beginning = -1;
        end = -1;
        // return tmpData;
    }
    else
    {
        beginning++;
    }
    // beginning++;
    // return queueArr[beginning - 1];

    // int tmpData = queueArr[beginning];
    // beginning++;
    return tmpData;
}

int Queue::front()
{
    if(beginning == -1)
    {
        cout << "The queue is empty" << endl;
        return 0;
    }
    return queueArr[beginning];
}

bool Queue::empty()
{
    if(beginning == -1 && end == -1)
        return true;
    return false;
}

int Queue::size()
{
    if(beginning == -1)
        return 0;
    return end - beginning + 1;
}

Queue::Queue()
{
    beginning = -1;
    end = -1;
}