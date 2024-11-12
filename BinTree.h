// Shahrukh Showkath sxs20032
#ifndef BINTREE_H
#define BINTREE_H
#include "Node.h"
#include <iomanip>
#include <queue>
#include <iostream>

// templated Binary search tree class with relevant methods
template <class T>
class BinTree
{
    public: 
        Node<T>* root;
        
    
        BinTree (){root = nullptr;};
        
        BinTree(Node<T>* no) {root = no;};
        
        Node<T>* getRoot() {return root;};
        
        void setRoot(Node<T>* r) {root = r;};
        
        void Insert(T, Node<T>*);
        
        Node<T>* retNode(Node<T>*, std::string);
        
        void Edit(std::string, int, std::string);
        
        bool Search(Node<T>* n, std::string d, bool &toRet);
        
        void Delete(Node<T>*);
        
        bool SearchNoPrint(Node<T>* n, std::string d, bool &toRet);
        
        void printInorder(Node<T>*);
        void printReverseOrder(Node<T>*);
        
        void printFile(Node<T>* n, std::ostream& fileStream);
};
#endif

//Inserts node into BST by alphabetical order
template <class T>
void BinTree<T>::Insert (T d, Node<T>* r)
{
    if (r == nullptr)
    {
        Node<Game>* no = new Node<Game> (d);
        root = no;
    }
    else if (r->getData() > d)
    {
        if (r->getLeft() == nullptr)
        {
            r->setLeft(new Node<Game>(d));
        }
        Insert(d, r->getLeft());
    }
    else if (r->getData() < d)
    {
        if (r->getRight() == nullptr)
        {
            r->setRight(new Node<Game>(d));
        }
        Insert(d, r->getRight());
    }
    
}

//returns node to be found in parameter
template <class T>
Node<T>* BinTree<T>::retNode(Node<T>* r, std::string d)
{
    if (r == nullptr || r->getData().getName() == d)
        {
            return r;
        }
        
        
        if (r->getData().getName() < d)
        {
            return retNode(r->getRight(), d);
        }
        
        return retNode(r->getLeft(), d);
}

// Edits certain node with data from parameter
template <class T>
void BinTree<T>::Edit (std::string name, int num, std::string val)
{
    bool checkTemp = false;
    if (SearchNoPrint(root, name, checkTemp))
    {
       Node<T>* temp = retNode(root, name);
       if (num == 1)
       {
           Game g (temp->getData().getName(), stoi(val), temp->getData().getInitials(), temp->getData().getPlays());
           temp->setData(g);
           std::cout << name << " UPDATED" << std::endl;
           std::cout << "UPDATE TO " << "high score" << " - VALUE " << val << std::endl;
           
       }
       else if (num == 2)
       {
           Game g (temp->getData().getName(), temp->getData().getScore(), val, temp->getData().getPlays());
           temp->setData(g);
           std::cout << name << " UPDATED" << std::endl;
           std::cout << "UPDATE TO " << "initials" << " - VALUE " << val << std::endl;
       }
       else if (num == 3)
       {
           Game g (temp->getData().getName(), temp->getData().getScore(), temp->getData().getInitials(), stoi(val));
           temp->setData(g);
           std::cout << name << " UPDATED" << std::endl;
           std::cout << "UPDATE TO " << "plays" << " - VALUE " << val << std::endl;
       }
       float f = (float) (temp->getData().getPlays() / 4.0);
       std::cout << "High Score: " << temp->getData().getScore() << std::endl;
        std::cout << "Initials: " << temp->getData().getInitials() << std::endl;
        std::cout << "Plays: " << temp->getData().getPlays() << std::endl;
        std::cout << "Revenue: $";
        std::cout << std::fixed << std::setprecision(2) << f << std::endl;
    }   

}

//Deletes node from BST
template <class T>
void BinTree<T>::Delete(Node<T>* r)
{
    Node<T>* par = nullptr;
    Node<T>* cur = root;

    while (cur != nullptr)
    {
       if (cur->getData().getName() == r->getData().getName())
       {
          if (cur->getLeft() == nullptr && cur->getRight() == nullptr)
          {
             
             if (par == nullptr)
             {
                root = (nullptr);
             }
             else if (par->getLeft() == cur)
             {
                par->setLeft(nullptr);
             }
             else
             {
                par->setRight(nullptr);
             }
             
          }
         else if (cur->getRight() == nullptr)
         {
            if (par == nullptr)
            {
             root = (cur->getLeft());
            }
            else if (par->getLeft() == cur)
            {
             par->setLeft(cur->getLeft());
            }
            else
            {
             par->setRight(cur->getLeft());
            }
            
         }
         else if (cur->getLeft() == nullptr) 
         {     
            if (par == nullptr)
            {
             root = (cur->getRight());
            }
            else if (par->getLeft() == cur)
            {
             par->setLeft(cur->getRight());
            }
            else
            {
             par->setRight(cur->getRight());
            }
            
         }
         else 
         {
            Node<T>* suc = cur->getRight();
            
            while (suc->getLeft()!= nullptr)
            {
               suc = suc->getLeft();
            }
            Game g (suc->getData().getName(), suc->getData().getScore(), suc->getData().getInitials(), suc->getData().getPlays());
            Delete(suc); 
            cur->setData(g);
            
         }
         break;
        }
        else if (cur->getData().getName() < r->getData().getName())
        {
           par = cur;
           cur = cur->getRight();
           
        }
        else
        {
           par = cur;
           cur = cur->getLeft();
        }
    }
    //return nullptr;
}

//Searches BST for certain name
template <class T>
bool BinTree<T>::Search(Node<T>* n, std::string d, bool &toRet)
{
    
    if (!n)
    {
        std::cout << "";
    }
    else
    {
        Search(n->getLeft(), d, toRet);
     
        if (n->getData().getName().find(d) != std::string::npos)
        {
            float f;
            f = (float) (n->getData().getPlays() * 0.25);
            std::cout << n->getData().getName() << " FOUND" << std::endl;
            std::cout << "High Score: " << n->getData().getScore() << std::endl;
            std::cout << "Initials: " << n->getData().getInitials() << std::endl;
            std::cout << "Plays: " << n->getData().getPlays() << std::endl;
            std::cout << "Revenue: $";
            std::cout << std::fixed << std::setprecision(2) << f << std::endl;
            toRet = true;
        }
        
        Search(n->getRight(), d, toRet);
    }
    return toRet;
}

//Searches node for a certain name but returns boolean value only
template <class T>
bool BinTree<T>::SearchNoPrint(Node<T>* n, std::string d, bool &toRet)
{
    if (!n)
    {
        std::cout << "";
    }
    
    
    else
    {
        SearchNoPrint(n->getLeft(), d, toRet);
     
        if (n->getData().getName() == d)
        {
    
            toRet = true;
        }
        
        SearchNoPrint(n->getRight(), d, toRet);
    }
    return toRet;
}

//Prints BST in order
template <class T>
void BinTree<T>::printInorder(Node<T>* n)
{
    if (n == NULL)
        return;
    
    printInorder(n->getLeft());
    
    std::cout << n->getData() << std::endl;
    
    printInorder(n->getRight());

}

// Prints BST in reverse order
template <class T>
void BinTree<T>::printReverseOrder(Node<T>* n)
{
    std::string s;
    
    if (n == NULL)
        return;
    
    printReverseOrder(n->getRight());
    
    std::cout << n->getData() << std::endl;
    
    printReverseOrder(n->getLeft());
    
}

//outputs BST to file in breadth first traversal
template <class T>
void BinTree<T>::printFile(Node<T>* n, std::ostream& fileStream)
{
    std::queue<Node<T>*>* q = new std::queue<Node<T>*>();
    
    if (!n)
        return;
    q->push(n);
    while (!q->empty())
    {
        Node<T>* temp = q->front();
        q->pop();
        fileStream << temp->getData() << std::endl;
        if (temp->getLeft())
        {
            q->push(temp->getLeft());
        }
        if (temp->getRight())
        {
            q->push(temp->getRight());
        }
    }
}