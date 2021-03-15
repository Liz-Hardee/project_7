#ifndef LIST_H
#define LIST_H

#include "string.h"

class element
{
    // data members
    int * size;
    int * capacity;
    string * index;

    // node pointers
    element * next;
    element * prev;
    element * head;
    element * tail;

    element();                              // default constructor
    element(const element &);               // copy constructor
    element & operator = (const element &); // assignment operator

    // member functions
    bool is_empty() const;       // returns whether list is empty
    bool insert(element *, int); // insert (by postion)
    bool insert(element *);      // inset  (ordered)
    bool erase();                // erase all elements of list

    // subscript operators
    const element & operator [] (int) const; // for reading
    element & operator [] (int);             // for writing

    // friends
    friend std::ostream & operator << (std::ostream &, const element &);
    friend std::istream & operator >> (std::istream &, element &);
};

// relational operators
bool operator <  (const element &, const element &);
bool operator <= (const element &, const element &);
bool operator == (const element &, const element &);
bool operator != (const element &, const element &);
bool operator >= (const element &, const element &);
bool operator >  (const element &, const element &);

#endif



