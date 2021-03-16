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
            
            Node() // default constructor
            {
                data = nullptr;
                next = nullptr;
            }                
        };
        // node pointers
        Node * head;
        Node * tail;

    public:
        list();  // default constructor
        ~list(); // destructor

        // member functions
        bool is_empty() const;       // returns whether list is empty
        bool insert(Node *);         // inset  (ordered)
        void erase();                // erase all elements of list

        // subscript operators
        const string & operator [] (int) const; // for reading
        string & operator [] (int);             // for writing

        std::ostream & print_list(std::ostream & out) const;
};

std::ostream & operator << (std::ostream &, const list &);
std::istream & operator >> (std::istream &, list &);

#endif
