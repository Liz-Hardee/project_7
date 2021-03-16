#ifndef LIST_H
#define LIST_H

#include "string.h"

class list
{
    private:
        // node for the linked list
        struct Node
        {
            string * data;
            Node   * next;
            Node   * prev;
            
            Node();                           // default constructor
            Node & operator = (const Node &); // assignment operator
        };
        // node pointers
        Node * head;
        Node * tail;

        list();                              // default constructor

        // member functions
        bool is_empty() const;       // returns whether list is empty
        bool insert(Node *, int);    // insert (by postion)
        bool insert(Node *);         // inset  (ordered)
        bool erase();                // erase all elements of list

        // subscript operators
        const list & operator [] (int) const; // for reading
        list & operator [] (int);             // for writing

        // friends
        friend std::ostream & operator << (std::ostream &, const list &);
        friend std::istream & operator >> (std::istream &, list &);
};

#endif



