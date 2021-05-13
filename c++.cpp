****************************c99*********************
-- C99 defines: bool
-- Literals refer to fixed values of a built-in type
-- Every expression has a value: A function call is an expression
-- Control constructs like if, if-else, switch, for, while, do-while, goto, continue, break, return are statements
-- c is designed for pointer to use it for unix

-- The %c conversion specifier won't automatically skip any leading whitespace, so if there's a stray newline in the input stream (from a previous entry, for example) the scanf call will consume it immediately.

One way around the problem is to put a blank space before the conversion specifier in the format string:

scanf(" %c", &c);
The blank in the format string tells scanf to skip leading whitespace, and the first non-whitespace character will be read with the %c conversion specifier.

char *str = strdup("Partha ");

dangling pointer
generic pointer
null pointer 
complex pointer
wild pointer
near pointer
far pointer
huge pointer

-- Segmentation fault is a specific kind of error caused by accessing memory that does not belong to you. Whenever you get a segfault, you are doing something wrong with memory.

****************************c++*********************

-- Any C standard library header is to be used in C++ with a prefix ’c’ and without the .h. These symbols will be in std namespace. Like:
	#include <cmath> // In C it is <math.h>

	std::sqrt(5.0); // In C it is <math.h>

	It is possible that a C++ program include a C header as in C. Like:
	#include <math.h> // Not in std namespace
	sqrt(5.0); // Use without std::

	This, however, is not preferred.
	Using .h with C++ header files, like iostream.h, is disastrous. These are deprecated. It is dangerous, yet true, that some compilers do 	not error out on such use. Exercise caution.

-- <=, <, >=, > can be used on strings in place of strcmp function in C

-- c descending
   int compare(const void *a, const void *b) {
   return (*(int*)a < *(int*)b); }
   qsort(data, 5, sizeof(int), compare);
   
-- c++ descending 
   bool compare (int i, int j) {
   return (i > j); }
   sort (data, data+5, compare);
   
-- stack<char> s;
   s.push(ele);
   s.top();
   s.pop();
   
-- Manifest constants are defined by #define

****************************constant*********************

const int n; // Is a compilation error as n must be initialized
const int n = 10;
int *p = 0;
p = &n; //error

Note: NULL is a manifest constant in C/C++ set to 0.

Prefer const over #define
Manifest constant
-----------------
Is not type safe
Replaced textually by CPP
Cannot be watched in debugger
Evaluated as many times as replaced

constant
--------
Has its type
Visible to the compiler
Can be watched in debugger
Evaluated only on initialization


const int n = 5;
int * p = &n; // Error: If this were allowed, we would be able to change constant n
...
n = 6; // Error: n is constant and cannot be changed
*p = 6; // Would have been okay, if declaration of p were valid

****************************volatile*********************

The value of a volatile variable may be different every time it is read – even if no assignment has been made to it 
A variable is taken as volatile if it can be changed by hardware, the kernel, another thread etc.

cv-qualifier: A declaration may be prefixed with a qualifier – const or volatile


static int i;
void fun(void) 
{
	i = 0;
	while (i != 100);
}
This is an infinite loop! Hence the compiler should optimize as:
static int i;
void fun(void) 
{
	i = 0;
	while (1); // Compiler optimizes
}


Now qualify i as volatile:

static volatile int i;
void fun(void) 
{
	i = 0;
	while (i != 100); // Compiler does not optimize
}
Being volatile, i can be changed by hardware anytime. It waits till the value becomes 100.

****************************inline*********************
Inline function
An inline function is expanded (inlined) at the site of its call and the overhead of passing parameters between caller and callee (or called) functions is avoided

Macros
------
Expanded at the place of calls
Efficient in execution
Code bloats
Has syntactic and semantic pitfalls
Type checking for parameters is not done
Helps to write max / swap for all types
Errors are not checked during compilation
Not available to debugger

inline Functions
----------------
Expanded at the place of calls
Efficient in execution
Code bloats
No pitfall
Type checking for parameters is robust
Needs template for the same purpose
Errors are checked during compilation
Available to debugger in DEBUG build


Limitations
--------
inlineing is a directive – compiler may not inline functions with large body
inline functions may not be recursive
Function body is needed for inlineing at the time of function call. Hence, implementation hiding is not possible. Implement inline functions in header files
inline functions must not have two different definitions


-- use PI = acos(-1) for more precise value of PI

-- cin.ignore()
-- cin.get()
-- (char*)str.c_str() to convert c++ string into c style string

-- eg: "12 34 56" extract 12, 34, 56
   strtok(c-stylestring, delimeter) first call  12
   strtok(NULL, " ") first onwards   34

****************************reference*********************
int a = 2;
int &b = a;
a and b have the same memory location and hence the same value
Changing one changes the other and vice-versa

int &j = i+k //error
const int &j = i+k //correct
const int &j = function(); // const needed if function return by value

Never return a local variables by reference
References cannot be NULL int &j ; //wrong

For a reference, its referent is fixed
int a, c, &b = a; // Okay
&b = c // Error

Array of references not allowed

*********************overloading*********************

Function Overloading or Static Polymorphism

int area(int a, int b = 2)
{
	return a * b;
}
int area(int a)
{
	return a * a;
}

int main()
{
	cout << area(2, 5);
	cout << area(5); // error: call of overloaded ‘area(int)’ is ambiguous
	return 0;
}

Two functions having the same signature but different return
types cannot be overloaded

int f(int = 0);

default parameters is a special case of function overloading

operator overloading

*********************operator new and delete*********************
int *p = new int(5); //operator
int *q = (int *)operator new(sizeof(int)); //function


delete p;
operator delete(p);

int *a = new int[3];
delete [] a;


*********************class*********************
struct is a derived data type
struct only aggregates
class is User-defined Data Type(UDT)
class is the only way to implement User-defined Data Type (UDT)
class aggregates and helps to do more for building a UDT
Unless specified, the access of the members of a class is considered private

An implicit this pointer holds the address of an object
this pointer serves as the identity of the object in C++
Type of this pointer for a class X object: X * const this;
this pointer is accessible only in methods


Constructor: default, parameterized, copy

May have any number of parameters
Can be overloaded

Destructor:
No parameter is allowed - unique for the class
Cannot be overloaded
