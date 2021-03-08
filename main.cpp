#include "main.h"

int main()
{
    char test_char [100] = "hello";
    string test_string(test_char);
    
    std::cout << "COPY CONSTRUCTOR TEST" << std::endl;
    std::cout << test_string.get_array() << std::endl;

    return 0;
}
