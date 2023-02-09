/*
implement a templated linked list class where each node contains a value of the templated type. Node must be a class/structure with that value and a pointer to a Node
the content of the list values should be read from a file. To make life easier, the first number given can be the number of elements in the list and you can “hardcode” the file name
implement the class member function push_back that inserts a new node, containing a proper value, at the end of the list. Don’t forget that the Node should live on the heap (be allocated with new)
implement the member function print_list that prints the values stored by nodes
implement the destructor which will properly free all the heap memory
implement a copy constructor for the list class
use valgrind to check for possible memory leaks (if you work in VS under Windows, google alternatives)
*/

#ifndef LINK
#define LINK

#include <iostream>
#include <string>

// define a 'Node Class'
template <typename T>
class Node{
public:
    T value;
    T* succ;

    // default constructor
    Node();

    // constructor
    Node(const T& val);

/*
    // copy constructor
    Node(const Node<T>& n);
    
    // move copy constructor
    Node(Node<T>&& n);

    // destructor
    ~Node();
*/

    // assignement operator
    Node<T> operator=(const Node<T>& n);
/*
    // move assignement operator
    Node<T> operator=(Node<T>&& n); 
*/

    // print_node
    void print_node();
};

// default constructor
template <typename T>
    Node<T>::Node(){
        value = 0;
        succ = nullptr;
    }

// constructor
template <typename T>
    Node<T>::Node(const T& val){
        value = val;
        succ = nullptr;
    }
/*
// copy constructor
template <typename T>
    Node<T>::Node(const Node<T>& n){
        if (this != &n)
        {
            value = n.value;
            if (n.succ == nullptr)
            {
                succ = nullptr;
            }else{
                succ = new T;
                succ = n.succ;
            }   
        }
    }

// move copy constructor
template <typename T>
    Node<T>::Node(Node<T>&& n){
        if (this != &n)
        {
            value = n.value;
            n.value = 0;
            if (n.succ == nullptr)
            {
                succ = nullptr;
            }else{
                succ = new T;
                succ = n.succ;
            }
            n.succ = nullptr; 
        }
    }

// destructor
template <typename T>
    Node<T>::~Node(){
        value = 0;
        delete succ;
    }
*/


// assignement operator
template <typename T>
    Node<T> Node<T>::operator=(const Node<T>& n){
        if (this != &n)
        {
            value = n.value;
            if (n.succ == nullptr)
            {
                succ = nullptr;
            }else{
                if (succ != nullptr)
                {
                    delete succ;
                }
                succ = new T;
                succ = n.succ;
            }   
        }
        return *this;
    }
/*
// move assignement operator
template <typename T>
    Node<T> Node<T>::operator=(Node<T>&& n){
        if (this != &n)
        {
            value = n.value;
            n.value = 0;
            if (succ != nullptr)
            {
                delete succ;
            }
            succ = n.succ;
            n.succ = nullptr;
        }
        return *this;
    }
*/

// print_node
template <typename T>
    void Node<T>::print_node(){
        std::cout<<value<<" ";
    }


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

// define a 'List Class'
template <typename T>
class List{
public:
    Node<T>* head;
    Node<T>* tail;

    // default constructor
    List();

/*
    // constructor: don't needed; when build a List, we build it empty and add nodes with insert

    // copy constructor
    List(const List<T>& list);

    // move copy constructor
    List(List<T>&& list);

    // destructor (to free the memory of a list)
    ~List();

    // assignement operator
    List<T> operator=(const List<T>& list);

    // move assignement operator
    List<T> operator=(List<T>&& list);

    // read_from_file
    void read_from_file(const std::string filename);
*/
    // insert a new node at the end of the list
    void insert(const T& val);

    // print_list
    void print_list();
};

// default constructor
template <typename T>
    List<T>::List(){
        head = nullptr;
        tail = nullptr;
    }

/*
// copy constructor
template <typename T>
    List<T>::List(const List<T>& list){
        if (this != &list)
        {
            if (list.head == nullptr) // means empty list
            {
                // assume we are safe with "if head is null, then also tail is null". So assume we don't deal with exotic things.
                head = nullptr;
                tail = nullptr;
            }else{
                T* current_node;
                current_node = *head;
                while (current_node.succ != nullptr)
                {
                    list.insert(current_node.value);
                }
            }   
        }
    }

// move copy constructor
template <typename T>
    List<T>::List(List<T>&& list){

    }

// destructor (to free the memory of a list)
template <typename T>
    List<T>::~List(){

    }

// assignement operator
template <typename T>
    List<T> List<T>::operator=(const List<T>& list){

    }

// move assignement operator
template <typename T>
    List<T> List<T>::operator=(List<T>&& list){

    }

// read_from_file
template <typename T>
    void List<T>::read_from_file(const std::string filename){

    }
*/

// insert a new node at the end of the list
template <typename T>
    void List<T>::insert(const T& val){
        Node<T> new_node(val);
        if (tail == nullptr) // insert the first node
        {
            head = &new_node;
            tail = &new_node;
        }else{ // insert new node
            Node<T> current_node = *tail;
            current_node.succ = &new_node;
            tail = &new_node;
        }
        
    }

// print_list
template <typename T>
    void List<T>::print_list(){
        if (tail == nullptr) // insert the first node
        {
            std::cout<<"empty list: insert firs node"<<std::endl;
        }else{ // insert new node
            Node<T> current_node;
            current_node = *head;
            while (current_node.succ != nullptr)
            {
                std::cout<<current_node.value<<" "<<std::endl;
            }
        }
    }







#endif