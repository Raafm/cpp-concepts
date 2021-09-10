#include <iostream>

using namespace std;

    
template <typename T>
struct Node {
    T data;
    Node* next;
    Node* prev;
    Node()next(NULL){};
    Node(T data): data(data), next(NULL){};
    Node(T data, Node* nextNode): data(data), next(nextNode), prev(NULL){};
    Node(T data, Node* nextNode,Node* prevNode):  data(data), next(nextNode), prev(prevNode){};
};

template <typename T>
void link(Node<T>* node1, Node<T>* node2){
    node1->next = node2;
    node2->prev = node1;
}

template <typename T>
class linked_list{

    protected:

        int length = 0; 
        Node* head = NULL;
        Node* tail = NULL;

    public:
        void push_front(T new_data);
        void push_back (T new_data);
        T first();
        T last();
        int size();
}; 

template<typename T>
void linked_list<T> :: push_front(T new_data)
{
    if(head)
    {
        link(head , new Node(new_data));
    }
    else
    {
        tail = head = new Node(new_data);
        tail->next = tail;
    }
    length++;
}

template<typename T>
void linked_list<T> :: push_back(T new_data)
{
    if(head)
    {
        link(tail, new Node(new_data));
        tail = tail->next;
    }
    else
    {
        tail = head = new Node(new_data);
        tail->next = tail;
    }
    length++;
}

template<typename T>
T linked_list<T> :: first()
{
    if(head)return head->data;
}

template<typename T>
T linked_list<T> :: last()
{
    if(head)return tail->data;
}