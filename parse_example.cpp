#include <iostream>
#include <stack>
#include <stdlib.h>

/* Function to validate string containing open-close braces, brackets, etc. */
// Compile (FreeBSD): clang++ parse_example.cpp --std=c++0x


// input: 
//    param 0: string to validate for well-formedness
//    param 1: list of open/close symbols to validate against, listed as pairs
//    optional param 3: maximum string length for param 0
// returns:
//    boolean: true or false
//    true = well-formed string with respect to nested brackets
//    false = not well-formed string using nested brackets

bool
is_well_formed (const char * str, const char * brackets, int str_max = 1024)
   {
   auto sz = strnlen(str, str_max);
   std::stack<char> stak;
   
   for (auto i = 0; i < sz; ++i)
      {
      // input char at index
      const char ch = str[i];
      
      // location of ch in brackets array or nul
      auto loc = strcspn(brackets, &ch);
      
      // if input char is a bracket
      if (brackets[loc])
	{
        // if input char is closing bracket (odd)
	if(loc % 2)
	   {
	   // if stak empty or top not closing bracket
	   if(stak.empty() || stak.top() != brackets[loc])
              return false;

           // remove from stack
	   stak.pop();
	   }
	else
           {
           stak.push(brackets[loc + 1]);
	   }
	}
      }
    return stak.empty();
    }



int main(void)
{
// our list of open/close bracket pairs to validate
const char * brackets = "{}()[]";

// our input string to parse
const char * str2pars = 
  "ab{(abcde)fgh}akdjlad{}()[isdoaiusd]{[(laksdasdgqiuwd)]   }";

// call validator, check if input string is well-formed
bool res = is_well_formed(str2pars, brackets);

// print result
std::cout << (res ? "valid string" : "invalid string") << std::endl;

// return 0 for valid, -1 for invalid
return (res ? 0 : -1);
}
