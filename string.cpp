#include "string.h"

// destructor
string::~string()
{
    if (this->array) delete array;
    if (this->cap) delete cap;
    if (this->char_count) delete char_count;

    array = nullptr;
    cap = nullptr;
    char_count = nullptr;
}

// assignment operator
string & string::operator = (const string & right)
{
    if (this != & right)
    {
        this->cap = right.cap;
        this->char_count = right.char_count;
        strcpy(this->array, right.array);
    }
    return * this;
}

// constant subscript operator
const char & string::operator [](int index) const
{
    if (index <= 0) return array[0];
    if (index >= * cap) return array[* cap - 1];
    return array[index];
}

// dynamic subscript operator
char & string::operator [](int index)
{
    if (index <= 0) return array[0];
    if (index >= * cap) return array[* cap - 1];
    return array[index];
}

// delete array and set to empty string
void string::clear()
{
    if (this->array) 
    {
        set_array("");
        cap = 0;
        char_count = 0;
    }
}

// adds passed string to end of current string
void string::append(string right)
{
    set_capacity(* cap + right.capacity());
    set_array(* array + right.get_array()); // NOTE: this might not work
    set_length(strlen(array));
}

// resizes the string from the beginning
void string::resize(int new_size)
{
    // create temporary array to hold the shortened cstring
    char * temp_array;
    temp_array = new char [new_size];

    // step through and copy each index to the temp array
    for (int i = 0; i < new_size; i++) 
        temp_array[i] = get_array()[i];
    temp_array[new_size] = '\0'; // set new_size index to null terminator

    // delete current character array and copy the temp_array
    delete [] array;
    array = new char [new_size];
    strcpy(array, temp_array);
    * cap = new_size;
    * char_count = strlen(array);

    // free memory fro temp_array
    delete [] temp_array;
}

// getters/setters

char * string::get_array()
{
    return this->array;
}

int string::capacity()
{
    return * cap;
}

int string::length()
{
    return * char_count;
}
