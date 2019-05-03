#include <iostream>
#include <string>

// T max(T front, Args... args)
// ----------------------------
// max returns the largest of all the arguments passed to it,
//     using < as the comparison operator,
// max assumes all parameters are of the same datatype,
//     and that the data type is compatible with the < operator,
//     and that at least one argument is passed

// base case, just the required arguments
template <typename T>
T max(T x) {
	return x;
}

// general case, at least the required args and the typename
//    for the next arg, everything else is captured in the ... Args

template<typename T, typename... Args>
T max(T front, Args... args) {
	if (front > max(args...))
	{
	   return front;
	}else{
           return max(args...);
	}
}

int main()
{
   int iMax = max(3);
   float fMax = max(2.5, 23.2);
   std::string sMax = max("hi", "there", "world");
   std::cout << iMax << ", " << fMax << ", " << sMax << std::endl;
   return 0;
}

