#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node *next;
};

template <typename T>
class LinkedList
{
public:
    void insert(T data)
    {
    }

private:
    Node<int> *head = nullptr;
    Node<int> *tail = nullptr;
};

int main()
{
    LinkedList<int> ll;

    return 0;
}