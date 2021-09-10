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
        int size();
        void push_front(T new_data);
        void push_back (T new_data);
        void pop_front();
        void pop_back();
        T first();
        T last();
        void print_list();
        void printe_backwards();
        
}; 

template<typename T>
int size() 
{ 
    return length;
}

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
    }
    length++;
}



template<typename T>
void linked_list<T> :: pop_front()
{
    if(head)
    {
        Node*temp = head->next;
        free(head);
        head = temp;
        length--;
    }
}

template<typename T>
void linked_list<T> :: pop_back()
{
    if(head)
    {
        Node* previous = tail->prev;
        free(tail);
        if(previous)
            tail = previous;
        else tail = head = NULL;
        length--;
    }
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

template<typename T>
void linked_list<T> :: print_list()
{
    Node* printer = head;
    while(printer)
    {
        cout<<printer->data<<" -> ";
        printer = printer->next;
    }
}

template<typename T>
void linked_list<T> :: print_backwards()
{
    Node* printer = tail;
    while(head)
    {
        cout<<printer->data<<" -> ";
        printer = printer->prev;
    }
}