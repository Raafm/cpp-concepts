#include <iostream>

using namespace std;

    
template <typename T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    Node():next(NULL),prev(NULL) {};
    Node(T data): data(data), next(NULL), prev(NULL) {};
    Node(T data, Node<T>* nextNode): data(data), next(nextNode), prev(NULL){};
    Node(T data, Node<T>* nextNode,Node<T>* prevNode):  data(data), next(nextNode), prev(prevNode){};
};

template <typename T>
void link(Node<T>* node1, Node<T>* node2){
    if(node1)node1->next = node2;
    if(node2)node2->prev = node1;
}

template <typename T>
class linked_list{

    protected:

        int length = 0; 
        Node<T>* head = NULL;
        Node<T>* tail = NULL;

    public:
        ~linked_list<T>()
        {   
            Node<T>* temp = head;
            while (temp)
            {
                temp = temp->next;
                free(head);
                head = temp;
            }      
        }
        int size();
        void push_front(T new_data);
        void push_back (T new_data);
        void pop_front();
        void pop_back();
        T first();
        T last();
        void print_list();
        void print_backwards();
        
}; 

template<typename T>
int linked_list<T> :: size() 
{ 
    return length;
}

template<typename T>
void linked_list<T> :: push_front(T new_data)
{
    if(head)
    {
        Node<T>*new_node = new Node<T>(new_data);
        link(new_node,head);
        head = new_node;
    }
    else
    {
        tail = head = new Node<T>(new_data);
    }
    length++;
}

template<typename T>
void linked_list<T> :: push_back(T new_data)
{
    if(head)
    {
        link(tail, new Node<T>(new_data));
        tail = tail->next;
    }
    else
    {
        tail = head = new Node<T>(new_data);
    }
    length++;
}

template<typename T>
void linked_list<T> :: pop_front()
{
    if(head)
    {
        Node<T>*nextNode = head->next;
        free(head);
        head = nextNode;
        if(nextNode)head->prev = NULL;   
        else head =tail = NULL;
        length--; 
    }
    else cout<<"Empty\n";
}

template<typename T>
void linked_list<T> :: pop_back()
{
    if(head)
    {
        Node<T>* previous = tail->prev;
        free(tail);
        if(previous)
        {
            tail = previous;
            tail->next = NULL;
        }
        else tail = head = NULL;
        length--;
    }
    else cout<<"Empty\n";
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
    Node<T>* printer = head;
    while(printer)
    {
        cout<<printer->data<<" -> ";
        printer = printer->next;
    }
    cout<<"NULL\n";
}

template<typename T>
void linked_list<T> :: print_backwards()
{
    Node<T>* printer = tail;
    while(printer)
    {
        cout<<printer->data<<" -> ";
        printer = printer->prev;
    }
    cout<<"NULL\n";
}

void options()
{
    cout<<"0 exit\n";
    cout<<"1 push_front\n";
    cout<<"2 push_back\n";
    cout<<"3 pop_front\n";
    cout<<"4 pop_back\n";
    cout<<"5 first\n";
    cout<<"6 last\n";
    cout<<"7 print_list\n";
    cout<<"8 print_backwards\n";    
}

int main(){
    linked_list<int> test_list;
    int choice = 1;
    while(choice)
    {
        options();
        cout<<"choose: ";
        cin>>choice;
        int number;
        switch(choice) 
        {
            case 0:
                break;

            case 1:
                cout<<"number: ";
                cin>>number;
                test_list.push_front(number);
                break;

            case 2:
                cout<<"number: ";
                cin>>number;
                test_list.push_back(number);
                break;
            case 3:
                test_list.pop_front();
                break;

            case 4:
                test_list.pop_back();
                break;

            case 5:
                test_list.first();
                break;

            case 6:
                test_list.last();
                break;

            case 7:
                test_list.print_list();
                break;

            case 8:
                test_list.print_backwards();
                break;            
        }
        test_list.print_list();
        cout<<endl;
    }
    return 0;
}