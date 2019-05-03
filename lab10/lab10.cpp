#include <iostream>
#include <cstring>

// apply(f, n, array)
// ------------------
// apply expects f to be a function that expects two parameters
//       (an integer n and an array of elements of type T1)
//    and returns an value of type T2
// apply returns the result of the function call,
//    i.e. return (*f)(n, array)
template <class T1, class T2 >
T2 apply(T2 (*f)(int,T1), int n, T1 array)
{
	return (*f)(n, array);
}
// explicitly instantiate funcall for data types:
//    bool f(int,float)
template bool apply<float, bool>(bool (*f)(int,float), int n, float array);
//    char f(int,char)
template char apply<char, char>(char (*f)(int,char), int n, char array);

// --- test functions to use with apply ---
// function that returns true iff all elements of arr are greater than 0
bool allPositive(int size, float arr[]){
	for(int i=0; i<size; i++){
		if (arr[i]<0){
		   return false;
		}
	}	
	return true;
}
// function that returns the largest char in str
char maxChar(int N, char str[]){
	char largest=str[0];
	for(int i=1; i<N; i++){
		if (largest < str[i]){
			largest = str[i];
		}
	}

	return largest;

}

int main()
{
    // test 1
    float data[3] = { 1.5, 23, -6 };
    if (apply(allPositive, 3, data))
       std::cout << "all data values were non-negative" << std::endl;
    else
       std::cout << "array contained negative value(s)" << std::endl;

    // test 2
    char str[] = "hello world!";
    int len = strlen(str);
    char max = apply(maxChar, len, str);
    std::cout << "The max char in \"" << str << "\" is " << max << std::endl;

    return 0;
}

