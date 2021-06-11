#include <string>
#include <iostream>
#include <algorithm>
#include <numeric> 
#include <functional>   // needed fo not1 and ptr_fun

using namespace std;

string upperCase(string x)
{
    for(unsigned int i =0; i < x.size(); i++)
     x[i] = toupper(x[i]);

    return x;
}

// trim from start
string ltrim(string s) 
{
    //object.erase(begin, end);
   s.erase(s.begin(), find_if(s.begin(), s.end(),
            not1(ptr_fun<int, int>(isspace)))); // isspace is a function that looks at a char and dleliverers if it is or isn't a space char
   return s; 
}

// trim from end
string rtrim(string s) {
   s.erase(find_if(s.rbegin(), s.rend(),
            not1(ptr_fun<int, int>(isspace))).base(), s.end());
   return s;
}

// trim from both ends
string trim(string s) {
   return ltrim(rtrim(s));
}
