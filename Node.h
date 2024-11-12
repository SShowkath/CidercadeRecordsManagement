// Shahrukh Showkath sxs20032

#ifndef NODE_H
#define NODE_H
#include <iostream>

/* Templated Node class with relevant methods, including getters, setters, and comparison/output operators */
template <class T>
class Node
{
    public:
        T data;
        Node <T>* left;
        Node <T>* right;
    //private: 
        Node() {left = NULL; right = NULL;}
        Node(T d) {data = d; left = NULL; right = NULL;};
        Node<T>* getLeft() {return left;};
        Node<T>* getRight() {return right;};
        T getData() {return data;};
        void setData(T d) {data = d;};
        void setLeft(Node* n) {left = n;};
        void setRight(Node* n) {right = n;};
        
        
        
        bool operator< (T val){return (data < val) ?  (true) : (false);};
        bool operator> (T val) {return (data > val) ? (true) : ( false);};
        
        friend std::ostream& operator<<(std::ostream& output, Node<T>* n)
        {
            output << n->getData() << std::endl;
            return output;
        }
        
};
#endif