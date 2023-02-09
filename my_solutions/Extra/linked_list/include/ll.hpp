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
    Node<T>* succ;

    // default constructor
    Node();

    // constructor
    Node(const T& val);

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


///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////

// define a 'List Class'
template <typename T>
class List{
public:
    Node<T>* head;

    // default constructor
    List();

    // constructor: don't needed; when build a List, we build it empty and add nodes with insert

    // copy constructor
    List(const List<T>& list);

    // destructor (to free the memory of a list)
    ~List();

    // assignement operator
    List<T> operator=(const List<T>& list);

    // read_from_file
    void read_from_file(const std::string filename);

    // insert a new node at the end of the list
    void insert(const T& val);

    // print_list
    void print_list();
};

// default constructor
template <typename T>
    List<T>::List(){
        head = nullptr;
    }


// copy constructor
template <typename T>
    List<T>::List(const List<T>& list){
        if (this != &list)
        {
            if (list.head == nullptr) // means empty list
            {
                // assume we are safe with "if head is null, then also tail is null". So assume we don't deal with exotic things.
                head = nullptr;
            }else{
                Node<T>* current_pointer;
                current_pointer = list.head;
                while (current_pointer != nullptr)
                {
                    insert(current_pointer->value);
                    current_pointer = current_pointer->succ;

                }
            }   
        }
    }


// destructor (to free the memory of a list)
template <typename T>
    List<T>::~List(){
        Node<T>* current_pointer;
        while (head != nullptr)
        {
            current_pointer = head->succ;
            delete head;
            head = current_pointer;
        }
    }


// read_from_file
template <typename T>
    void List<T>::read_from_file(const std::string filename){

    }


// insert a new node at the end of the list
template <typename T>
    void List<T>::insert(const T& val){
        
        if (head == nullptr) // insert the first node
        {
            head = new Node<T>(val);
        }else{ // insert new node
            Node<T>* current_pointer = head;
            while (current_pointer->succ!=nullptr) {
            current_pointer = current_pointer->succ;
            }
            current_pointer->succ=new Node<T>(val);
        }
        
    }

// print_list
template <typename T>
    void List<T>::print_list(){
        if (head == nullptr) // insert the first node
        {
            std::cout<<"empty list: insert first node"<<std::endl;
        }else{ // insert new node
            Node<T>* current_pointer;
            current_pointer = head;
            while (current_pointer != nullptr)
            {
                std::cout<<current_pointer->value<<" ";
                current_pointer = current_pointer->succ;
            }
        }
    }







#endif