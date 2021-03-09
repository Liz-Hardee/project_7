#include "main.h"

int main()
{
    char test_char [100] = "hello";
    string test_string(test_char);
    string test_string2("goodbye");

    std::cout << "COPY CONSTRUCTOR TEST" << std::endl;
    test_log(test_string);
    
    test_string = test_string2;

    std::cout << "ASSIGNMENT OPERATOR TEST" << std::endl;
    test_log(test_string);

    std::cout << "SUBSCRIPT READ OPERATOR TEST" << std::endl;
    for (int i = 0; i < test_string.length(); i++)
    {
        std::cout << test_string[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;

    std::cout << "SUBSCRIPT WRITE OPERATOR TEST" << std::endl;
    for (int i = 0; i < test_string.length(); i++)
    {
        test_string[i] = 'a';
        std::cout << test_string[i] << " ";
    }
    std::cout << std::endl;
    std::cout << std::endl;
    
    test_string.append(test_string2);
    
    std::cout << "STRING APPEND TEST" << std::endl;
    test_log(test_string);

    test_string.resize(3);

    std::cout << "RESIZE TEST" << std::endl;
    test_log(test_string);

    // NOTE: this needs fixing
    // std::cout << "INPUT STREAM OPERATOR TEST" << std::endl;
    // std::cout << "Please enter a word: ";
    // std::cin >> test_string;
    // std::cout << test_string << std::endl << std::endl;

    std::cout << "OUTPUT STREAM OPERATOR TEST" << std::endl;
    std::cout << test_string << std::endl << std::endl;

    std::cout << "ASSIGNMENT TO WRITETIME CHAR ARRAY" << std::endl;
    test_string = "hello";
    test_log(test_string);

    // ADD CODE HERE FOR ADDITIONAL TESTS

    std::cout << "All Tests Completed!" << std::endl;

    return 0;
}

void test_log(string & test_string)
{
    std::cout << "string: "   << test_string.get_array() << std::endl;
    std::cout << "capacity: " << test_string.capacity() << std::endl;
    std::cout << "length: "   << test_string.length() << std::endl;
    std::cout << std::endl;
}
