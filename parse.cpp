#include <iostream>
#include <stack>
#include <stdlib.h>

bool
is_well_formed (const char * str, const char * brackets, int str_max = 1024)
   {
   auto sz = strnlen(str, str_max);
   std::stack<char> stak;
   
   for (auto i = 0; i < sz; ++i)
      {
      const char ch = str[i];
      
      auto loc = strcspn(brackets, &ch);
      
      if (brackets[loc])
	{
	if(loc % 2)
	   {
	   if(stak.empty() || stak.top() != brackets[loc])
              return false;

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

