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

//insert alphabetically
bool list::insert(Node * newcomer)
{
        Node * curr = head;

        Node * temp = new Node;

        while (*newcomer->data < *curr->data)
                curr=curr->next; //skip to correct position

        *newcomer->prev = *curr;         //set newcomer's previous pointer
        newcomer->next = curr->next;    //set newcomer's next pointer to next node
        *temp = *curr->next;             //put the next node in a temp variable so as not to lose it
        *curr->next = *newcomer;         //put newcomer in front of current node
        *curr = *temp;                    //put temp node in current
        newcomer->next = curr;          //set newcomer's next pointer
        temp->prev = nullptr;
        temp->next = nullptr;
        temp->data->clear();             //delete temp

        return 1;
}

bool list::is_empty() const  //returns whether list is empty
{
        if     (head->data == nullptr 
             && head->next == nullptr)
                   return 1;
        else
                   return 0;
}

