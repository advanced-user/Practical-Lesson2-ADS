#include <iostream>
using namespace std;

#pragma region 1-2

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

#pragma endregion


#pragma region LinkedList

template<typename T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();

    void pop_front();
    void clear();
    void push_back(T data);
    void PrintList();
    void PrintListReverse();
    int Sum();

    T& operator[](const int index);
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

    Node<T> *Head;

    void push_back(Node<T> *currentNode, T data);
    void PrintList(Node<T> *currentNode);
    void PrintListReverse(Node<T> *currentNode);
    int Sum(Node<T> *currentNode);
};

template<typename T>
LinkedList<T>::LinkedList()
{
    Head = nullptr;
}

template<typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template<typename T>
void LinkedList<T>::pop_front()
{
    Node<T> *temp = Head;

    Head = Head->pNext;

    delete temp;
}

template<typename T>
void LinkedList<T>::clear()
{
    while(Head != nullptr)
    {
        pop_front();
    }
}

template<typename T>
T &LinkedList<T>::operator[](const int index)
{
    int counter = 0;
    Node<T> *currentNode = Head;

    while(currentNode != nullptr)
    {
        if(counter == index)
            return currentNode->data;

        currentNode = currentNode->pNext;
        counter++;
    }
}

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

template<typename T>
int LinkedList<T>::Sum()
{
    return Sum(Head);
}

template<typename T>
int LinkedList<T>::Sum(LinkedList::Node<T> *currentNode) {
    if(currentNode == nullptr)
        return 0;

    return currentNode->data + Sum(currentNode->pNext);
}

template<typename T>
void LinkedList<T>::PrintList()
{
    PrintList(Head);
    cout << endl;
}

template<typename T>
void LinkedList<T>::PrintList(LinkedList::Node<T> *currentNode)
{
    if(currentNode == nullptr)
        return;

    cout << currentNode->data << " ";
    PrintList(currentNode->pNext);
}

template<typename T>
void LinkedList<T>::PrintListReverse()
{
    PrintListReverse(Head);
    cout << endl;
}

template<typename T>
void LinkedList<T>::PrintListReverse(LinkedList::Node<T> *currentNode)
{
    if(currentNode == nullptr)
        return;

    PrintListReverse(currentNode->pNext);

    cout << currentNode->data << " ";
}

#pragma endregion comment


#pragma region BinarySearchTree

template <typename T>
class BinarySearchTree
{
public:
    BinarySearchTree();
    ~BinarySearchTree();

    void push_back(T data);
    void BST_print_asc();
    void BST_print_desc();
    int BST_sum();
    void BST_List(LinkedList<T> *linkedList);
private:
    template<typename T>
    class Node
    {
    public:
        Node<T> *parent;
        Node<T> *leftNode;
        Node<T> *rightNode;
        T data;

        Node(T data = T(), Node *parent = nullptr)
        {
            this->data = data;
            this->parent = parent;
            this->leftNode = nullptr;
            this->rightNode = nullptr;
        }
    };

    Node<T> *Root;
    int size;
    int sum;

    void push_back(Node<T> *currentNode, T data);
    void BST_print_asc(Node<T> *currentNode);
    void BST_print_desc(Node<T> *currentNode);
    void BST_sum(Node<T> *currentNode);
    void BST_List(Node<T> *currentNode, LinkedList<T> *linkedList);
};

template<typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    Root = nullptr;
    size = 0;
    sum = 0;
}

template<typename T>
BinarySearchTree<T>::~BinarySearchTree() {}

template<typename T>
void BinarySearchTree<T>::push_back(T data)
{
    if(Root == nullptr)
        Root = new Node<T>(data);
    else
        push_back(Root, data);
    size++;
}

template<typename T>
void BinarySearchTree<T>::push_back(BinarySearchTree::Node<T> *currentNode, T data)
{
    if(currentNode->data >= data)
    {
        if(currentNode->leftNode == nullptr)
            currentNode->leftNode = new Node<T>(data, currentNode);
        else
            push_back(currentNode->leftNode, data);
    }
    else
    {
        if(currentNode->rightNode == nullptr)
            currentNode->rightNode = new Node<T>(data, currentNode);
        else
            push_back(currentNode->rightNode, data);
    }
}

template<typename T>
void BinarySearchTree<T>::BST_print_asc()
{
    BST_print_asc(Root);
    cout << endl;
}

template<typename T>
void BinarySearchTree<T>::BST_print_asc(Node<T> *currentNode)
{
    if(currentNode == nullptr)
        return;

    BST_print_asc(currentNode->leftNode);
    cout << currentNode->data << " ";
    BST_print_asc(currentNode->rightNode);
}

template<typename T>
void BinarySearchTree<T>::BST_print_desc()
{
    BST_print_desc(Root);
    cout << endl;
}

template<typename T>
void BinarySearchTree<T>::BST_print_desc(BinarySearchTree::Node<T> *currentNode)
{
    if(currentNode == nullptr)
        return;

    BST_print_desc(currentNode->rightNode);
    cout << currentNode->data << " ";
    BST_print_desc(currentNode->leftNode);
}

template<typename T>
int BinarySearchTree<T>::BST_sum()
{
    BST_sum(Root);

    return sum;
}

template<typename T>
void BinarySearchTree<T>::BST_sum(BinarySearchTree::Node<T> *currentNode)
{
    if(currentNode == nullptr)
        return;

    sum += currentNode->data;
    BST_sum(currentNode->leftNode);
    BST_sum(currentNode->rightNode);
}





template<typename T>
void BinarySearchTree<T>::BST_List(LinkedList<T> *linkedList)
{
    BST_List(Root, linkedList);
}

template<typename T>
void BinarySearchTree<T>::BST_List(BinarySearchTree::Node<T> *currentNode, LinkedList<T> *linkedList)
{
    if(currentNode == nullptr)
        return;

    BST_List(currentNode->leftNode, linkedList);
    linkedList->push_back(currentNode->data);
    BST_List(currentNode->rightNode, linkedList);
}





#pragma endregion


int main() {
    cout << F(3) << endl;
    cout << Prod(-26, 25) << endl;

    LinkedList<int> linkedList;
    for(int i = 0; i < 10; i++)
    {
        linkedList.push_back(i);
    }

    cout << linkedList.Sum() << endl;

    linkedList.PrintList();
    linkedList.PrintListReverse();

    BinarySearchTree<int> binarySearchTree;
    binarySearchTree.push_back(5);
    binarySearchTree.push_back(25);
    binarySearchTree.push_back(2);
    binarySearchTree.push_back(1);
    binarySearchTree.push_back(3);
    binarySearchTree.push_back(24);
    binarySearchTree.push_back(26);

    binarySearchTree.BST_print_asc();
    binarySearchTree.BST_print_desc();

    cout << binarySearchTree.BST_sum() << endl;

    LinkedList<int> L;
    binarySearchTree.BST_List(&L);

    L.PrintList();

    return 0;
}
