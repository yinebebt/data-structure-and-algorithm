#include <iostream>

using namespace std;

int fact(int x)
{
    if (x == 1)
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
    int number = 5;
    int result = fact(number);
    cout << "Factorial of " << number << " is: " << result << endl;

    return 0;
}
