#include "string.h"

// default constructor
string::string()
{
    array      = nullptr;
    cap        = nullptr;
    char_count = nullptr;
}

// copy constructor (char array)
string::string(const char * char_array)
{
    array      = new char [strlen(char_array) + 1];
    cap        = new int;
    char_count = new int;

    strcpy(array, char_array);
    * cap = strlen(array) + 1;
    * char_count = strlen(array);
}

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
        * cap = *(right.cap);
        * char_count = *(right.char_count);
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
    if (this->array) delete [] array;
    if (this->cap) delete cap;
    if (this->char_count) delete char_count;

    array = nullptr;
    cap = nullptr;
    char_count = nullptr;
}

// adds passed string to end of current string
void string::append(string & right)
{
    * cap = * cap + right.length();
    array = strcat(array, right.get_array());
    * char_count = strlen(array);
}

// adds passed char * to end of current string
void string::append(char * right)
{
    * cap = * cap + strlen(right) + 1;
    array = strcat(array, right);
    * char_count = strlen(array);
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
    * cap = new_size + 1;
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

// friends

// input stream operator
// NOTE: this needs fixing
std::istream & operator >> (std::istream & in, string & right)
{
    int  * count = new int;
    char * byte  = new char;
    
    // step through input stream
    while (in.peek() != EOF && in.peek() != '\n')
    {
        * byte = in.get();
        right[* count++] = * byte;
    }
    return in;
}

// output stream operator 
std::ostream & operator << (std::ostream & out, string & right)
{
    out << right.get_array();
    return out;
}
