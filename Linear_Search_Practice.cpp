#include <iostream> //Pulls in directives: std::cout & std::cin & is short for Standard Input Output Stream
#include <vector> //Dynamic arrays, Automatic Memory Management
// Arrays are fixed-size data structures that store elements of the same type in contiguous memory locations
// Vectors are dynamic arrays that can grow or shrink in size as needed
// providing more flexibility than traditional arrays, automatic memory management
// and a rich set of member functions for manipulating the stored elements

int search(std::vector<int>& arr, int x) //Function signatures
// int is a return type
// search is the function name
// std::vector<int>& arr is a reference to a vector of **integers**
// allowing the function to access and modify the original vector without making a copy
// and int x is the integer value to search for in the vector
// & is a pass-by-reference operator -- 
// which allows the function to modify the original vector without making a copy -- 
{
    // Iterate over the array in order to
    // find the key x
    for (std::size_t i = 0; i < arr.size(); i++)
		// std::size_t is an unsigned integer type that is used to represent the size of objects in bytes
        // std::size_t i = 0; creates a counter variable named i and starts it at 0
        // std::size_t is a special data type for sizes adn indexes beacuse it can never be negative
		// i < arr.size() returns the number of elements in the vector arr
        // arr.size() is the condition, the loop will keep running as long as i is less than the total
        // number of items in our vector (arr.size())
        // i++, add 1 to i it happensath the end of every cycle loop, moving us to the next item
		// If the current element matches the key x, return its index
        if (arr[i] == x) 
            // arr[i] looks inside our vector position i
            // if i is 0, it looks at the first item, if i is 1, it looks at the second item
            return static_cast<int>(i);
            // if we found the match, this stops the function immediately and hands back a result
            // static_cast<int>(i) This is a safety tool that converts (or "casts") the types
            // of i into a standard int so the program does not crash or cause errors
    return -1; //Same way as saying, "Erro, item not found"
}

int main()
{
    std::vector<int> arr = { 2, 3, 4, 10, 40 };
	// std::vector<int> arr = { 2, 3, 4, 10, 40 }; creates a vector of integers 
    // named arr and initializes it with the values 2, 3, 4, 10, and 40
    int x = 10;
    int res = search(arr, x);
	// int res = search(arr, x); calls the search function with the vector arr
    // and the integer x as arguments
    // We call our search function, passing it into our array and our target (x)
    // The function runs, finds 10 at index position 3, and returns that value to us
    // 3 is not stored inside of res

    if (res == -1)
        std::cout << "Element is not present in the array";
    else
        std::cout << "Element is present at index " << res;

    return 0;
}

// push_back() effecienty adds an element to the end
// pop_back() efficiently removes the last element
// size() returns the current number of element
// at () or [] access elements at a specific index (with at() providing
// bounds-checking and throwing an exception if the index is out of range)

// An lvalue is an expression that refers to a memory location and allows us to take
// the address of that memory location via the & operator. 
// An rvalue is an expression that does not refer to a memory location and cannot have its address taken. 
// In general, lvalues are objects that persist beyond a single expression, 
// while rvalues are temporary objects that are created and destroyed within a single expression.

// lvalue cannot be a function, expression (like a + b) or a constant (like 3, 4, etc.)
// lvalue often represents as identifier
// Expression referring to modifiable locations are called "modifiable l-values" 
// A modfiable l-value cannot have an array type, an incomplete type, or a type with the const attribute

//Structures and unions are user-defined data types used to group variables of 
// different types under a single name. Both look similarily in syntax, but they have different use cases.
// struct = used to create a record that can hold multiple variables of different types simultaneously
// memory_allocation_struct = each member has its own seperate memory location
// size_struct = the total size of each structure is at least the sum of the sizes of its members
// plus any padding added for alignment
// usage_struct = best for organizing complex data objects like a student record
// C++ Specifics: a struct is almost identical to a class, but its members are public by default
// while class members are private by default.
// ----------------------------------------------------------------------------------------------------------------
// union = used to store different data types in the same memory location
// union_memory_allocation = all members share the same exact memory location
// union_size = the size of the union is equal to the size of its largest member
// key restrictions_union = you can only store a value in one member at a time
// assigning a value to one member overwrites whatever was stored in the other
// union_usage = ideal for memory optimization in embedded systems or for "type punning" -- 
// interpreting the same bits as different types -- 

//sources: https://www.geeksforgeeks.org/dsa/linear-search/ 

