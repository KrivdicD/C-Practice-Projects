#include <iostream>
#include <vector> //Dynamic arrays, Automatic Memory Management
// 

int search(std::vector<int>& arr, int x)
{
    // Iterate over the array in order to
    // find the key x
    for (std::size_t i = 0; i < arr.size(); i++)
        if (arr[i] == x)
            return static_cast<int>(i);
    return -1;
}

int main()
{
    std::vector<int> arr = { 2, 3, 4, 10, 40 };
    int x = 10;
    int res = search(arr, x);

    if (res == -1)
        std::cout << "Element is not present in the array";
    else
        std::cout << "Element is present at index " << res;

    return 0;
}