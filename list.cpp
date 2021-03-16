#include "list.h"
#include "string.h"

// default constructor
list::list()
{
   head = nullptr; 
   tail = nullptr; 
}

// copy constructor
list::~list()
{
    erase();
}

// erases all elements of the list
void list::erase()
{
    Node * curr = head;
    while(head)
    {
        head = curr->next;
        delete curr;
        curr = head;
    }
}

// subscript operator for reading
const string & list::operator [] (int index) const
{
    Node * curr = head;
    for (int i = 0; i < index; i++)
        curr = curr->next;
    return * curr->data;
}

// subscript operator for writing
string & list::operator [] (int index)
{
    Node * curr = head;
    for (int i = 0; i < index; i++)
        curr = curr->next;
    return * curr->data;
}

// print list to access node data
std::ostream & list::print_list(std::ostream & out) const
{
    Node * curr;
    for (curr = head; curr; curr = curr->next)
        out << * curr->data << std::endl;
    return out;
}

// output operator to print list
std::ostream & operator << (std::ostream & out, const list & out_list)
{
    return out_list.print_list(out);
}
