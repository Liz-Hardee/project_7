#ifndef STRING_H
#define STRING_H

#include <iostream>
#include <cstring>

class string
{
    private:
        // members
        char * array;      // array of characters that makes up the string
        int  * cap;        // total number of indexes in the array
        int  * char_count; // number of actual characters in the array

    public:
        // constructors
        string();               // default constructor
        string(const string &); // copy constructor (from string)
        string(const char *);   // copy constructor (from char array)

        ~string(); // destructor

        // operators
        string & operator = (const string & right);
        const char & operator [](int) const; // subscript operator for read
        char & operator [](int);             // subscript operator for write

        // getters
        char * get_array(); // returns char array
        int length();       // returns char_count
        int capacity();     // returns capacity

        // setters
        void set_array(const char *); // sets array
        void set_capacity(const int); // sets cap
        void set_length(const int);   // sets char_count

        // methods
        void clear();                   // set array to nullptr
        void append(string &);            // appends string
        void insert(int, const string); // inserts string
        void resize(int);               // resizes string (smaller)
        void reserve(int);              // resizes string (bigger)
        string * substr(int, int);      // returns a substring between 2 index

        // friends (input/output stream operators)
        friend std::istream & operator >> (std::istream &, string &);
        friend std::ostream & operator << (std::ostream &, string &);
};

// reference operators
bool operator == (string &, string &);
bool operator != (string &, string &);
bool operator < (string &, string &);
bool operator > (string &, string &);
bool operator <= (string &, string &);
bool operator >= (string &, string &);
#endif
