#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#include "DSString.h"

/* TODO: This file is a start to test your DSString class. Add more tests and add code to check if the results are correct. */

int main()
{  
    DSString myString = "Hello, World!";
    std::cout << myString << "\n";

    // this uses the one argument constructor in DSString and then the inherited operator=
    myString = "Good bye!";
    std::cout << myString << "\n";

    std::cout << "substr: " << myString.substring(5, 3) << "\n";

    // test some operators (=, ==, [])
    DSString a = "test";
    DSString b;
    b = a;

    std::cout << std::boolalpha;
    std::cout << (a == b) << "\n";

    b[0] = 'T';
    std::cout << "a is now: " << a << "\n";
    std::cout << (a == b) << "\n";

    // use initialization list
    std::vector<DSString> strings = {
        DSString("bb"),
        DSString("aaa"),
        DSString("ddd"),
        DSString("ee"),
        DSString("ccc")};

    // find strings
    for (const auto &s : strings)
        std::cout << s << "\n";
        
    // find implements linear search
    std::cout << "found ddd: " << (std::find(strings.begin(), strings.end(), DSString("ddd")) != strings.end()) << "\n";
    std::cout << "found z: " << (std::find(strings.begin(), strings.end(), DSString("z")) != strings.end()) << "\n";

    // sorting using the STL (note thus needs operator= and operator<)
    std::sort(strings.begin(), strings.end());

    for (const auto &s : strings)
        std::cout
            << s << "\n";

    // the data structure is sorted. Now we can do more efficient search using STL binary search
    std::cout << "found ddd: " << binary_search(strings.begin(), strings.end(), DSString("ddd")) << "\n";
    std::cout << "found z: " << binary_search(strings.begin(), strings.end(), DSString("z")) << "\n";

    //--------------------

    DSString tokTestEasy("I am a tweet object");
    DSString tokTestAvg("I am a tweet object, look at me.");
    DSString tokTestHard("I am a tweet  object,   look at me! #cool #fun");
    std::vector<DSString> result1 = tokTestEasy.tokenization();
    std::vector<DSString> result2 = tokTestAvg.tokenization();
    std::vector<DSString> result3 = tokTestHard.tokenization();

    assert(result1 == std::vector<DSString>({
        "I", "am", "a", "tweet", "object"
    })); 
    
    assert(result2 == std::vector<DSString>({
        "I", "am", "a", "tweet", "object", "look", "at", "me"
    }));
    assert(result3 == std::vector<DSString>({
        "I", "am", "a", "tweet", "object", "look", "at", "me", "cool", "fun"
    }));
    return 0;
}
