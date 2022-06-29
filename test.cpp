#include <iostream> // standard library
#include <string>   // standard library

/*
 * Andreas Schaler
 * Structure of Programming Languages
 * Aditi Singh
 * Spring 2022
 *
 * code should compile with g++ compiler
 *
 * -----------------------------------------------
 * This program is ment to deminstrate the use of 
 * garbage collection, pointers and memory allocation,
 * and parameter passing in the c++ language. Where
 * these mechinisms are supported or not.
 *
 * 1) Garbage Collection is implisitly done 
 *    by automatic collection of locally declaired
 *    variables and call by value arguments. When 
 *    an argument is passed call by value mechinism
 *    in c++ a copy of the argument is alocated in
 *    procedure call stack with the passed arguments
 *    value copied and a refrence back to the original
 *    calling memory location. In terms of programmer
 *    defined types with use of dynamic memory memory
 *    allocation and deallocation is controled by the 
 *    programer whose resposibility it is to allocate
 *    and release memory while ensureing memory issues
 *    do not result in bad memory allocation and 
 *    deallocation practices.
 *
 * 2) Pointers are supported in c++ language. Here
 *    I would like to demonstrate thier use in
 *    dynamic memory contents. Pointers
 *    usefullness grows furthure as a handle to
 *    memory locations.
 *
 * 3) Pass by by refrence, pass by value are both
 *    supported in c++. The dirrect memory location 
 *    is passed when passing by refrence in c++ as
 *    seen in the console output. Pass by value is
 *    implicitly handeld in terms of fundimental types
 *    and dynamic objects with the need for programmer
 *    definded memory managing methods in the case of 
 *    dynamic objects.
 *
*/

void rev_str_ref(const std::string &s) {
    // 3) memory location is the exact as argument
    std::cout << &s << "  --Memory location of passed by refrence argument, local funtion output." << '\n';

    char *s2;               // 2) use of pointers
    s2 = new char[5];       // 2) memory allocation, assignment used for later access and manipulation of memory
    const char *ret = s2;
    if(s2 != nullptr && ret != nullptr) {
        int i = 4;
        while(i>=0){
            *s2 = s[ i ];   // 2)
            std::cout << *s2;
            --i;
            ++s2;
        }
        std::cout << '\n';
    }
    
    delete[] ret;           // 1) memory release, explicitly done by programer  
}

void rev_str_val(std::string s) {
    // 3) call by value, contents of argument are copied over to a automatically allocated parameter
    std::cout << &s << "  --Memory location of passed by value argument, local funtion output." << '\n';

    char *s2;
    s2 = new char[5];
    const char *ret = s2;
    if(s2 != nullptr && ret != nullptr) {
        int i = 4;
        while(i>=0){
            *s2 = s[ i ];
            std::cout << *s2;
            --i;
            ++s2;
        }
    }
    delete[] ret;
}

int main() {
    std::string s1 = "abcd";
    // 3) memory location output
    std::cout << &s1 << "  --Memory location for output from main() calling area, for compairison." << '\n';
    std::cout << s1 << '\n';

    rev_str_ref(s1);            // 3) call by refrence
    rev_str_val(s1);            // 3) call by value

    std::cout << std::endl;
    return 0;
}
