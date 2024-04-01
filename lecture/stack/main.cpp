#include <iostream>

using namespace std;

class Stack
{
    private:
    int maxArr = 100;
    int stack[100];
    int top;

    public:
    Stack();

    bool empty();
    int size();

    void push(int);
    int pop();
    int peek();
};

int main(int argc, char* argv[])
{
    Stack myStack;

    myStack.push(42);
    myStack.push(15);
    myStack.push(23);

    // while(!myStack.empty())
    // while(myStack.empty() == false)
    // {
    //     cout << myStack.pop() << " ";
    // }
    // int stackSize = ;
    for(int i = 0; i < myStack.size(); )
    {
        cout << myStack.pop() << " ";
    }
    cout << endl;
    // cout << "myStack.peek(): " << myStack.peek() << endl;
    return 0;
}

int Stack::peek()
{
    if(empty())
    {
        cerr << "Stack is empty" << endl;
        return -999;
    }
    return stack[top];
}

int Stack::pop()
{
    if(empty())
    {
        cerr << "Stack is empty" << endl;
        return -999;
    }

    top--;
    return stack[top+1];
}

void Stack::push(int data)
{
    if(top+1 == maxArr)
    {
        // create larger array and copy elements
    }
    top++;
    stack[top] = data;
}

int Stack::size()
{
    return top+1;
}

bool Stack::empty()
{
    if(top == -1) return true;
    return false;
}

Stack::Stack()
{
    top = -1;
}