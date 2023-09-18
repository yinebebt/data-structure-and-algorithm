#include <iostream>
using namespace std;

int fact(int x)
{
    if (x == 1) //base case
    {
        return 1;
    }
    else
    {
    return x * fact(x - 1); // Recursive call
    }
}

int main()
{
    int x = 5;
    int factorial = fact(x);
    cout << "Factorial of " << x << " is: " << factorial << endl;

    return 0;
}
