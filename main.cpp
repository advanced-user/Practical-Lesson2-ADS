#include <iostream>
using namespace std;


int F(int n)
{
    if(n == 0)
        return 3;
    else if(n > 0)
        return 4 * F(n - 1) + 2 * F(n / 2) + 7;
}

int Prod(int a, int b)
{
    if(b == 0)
        return 0;

    if(b < 0)
    {
        b = -b;
        a = -a;
    }

    return a + Prod(a, b-1);
}




template<typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void push_back(T data);
private:

    template<typename T>
    class Node
    {
    public:
        Node *pNext;
        T data;

        Node(T data = T(), Node *pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;
        }
    };

    int Size;
    Node<T> *Head;

    void push_back(Node<T> *currentNode, T data);
};

template<typename T>
LinkedList<T>::LinkedList()
{
    Size = 0;
    Head = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList(){}

template<typename T>
void LinkedList<T>::push_back(T data)
{
    if(Head == nullptr)
        Head = new Node<T>(data);
    else
        push_back(Head, data);
}

template<typename T>
void LinkedList<T>::push_back(LinkedList::Node<T> *currentNode, T data)
{
    if(currentNode->pNext == nullptr)
    {
        currentNode->pNext = new Node<T>(data);
        return;
    }
    else
    {
        push_back(currentNode->pNext, data);
    }
}


int main() {
    cout << F(3) << endl;
    cout << Prod(-26, 25) << endl;

    LinkedList<int> linkedList;
    for(int i = 54; i < 84; i++)
    {
        linkedList.push_back(i * 10);
    }

    return 0;
}
