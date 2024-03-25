#include <iostream>
#include "tree.h"

using namespace std;

int main(int argc, char* argv[])
{
    int numNodes = 5;
    Tree<int>* binaryTree = new Tree<int>();

    for(int i = 0; i < numNodes; i++)
    {
        int tmpNum;
        cout << "Enter a whole number: ";
        cin >> tmpNum;
        binaryTree->insert(tmpNum);
    }

    binaryTree->inOrder();
    

    return 0;
}