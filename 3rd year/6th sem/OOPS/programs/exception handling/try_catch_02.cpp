#include <iostream>

using namespace std;

int divide(int numerator, int denominator)
{
    try
    {
        if (denominator == 0)
        {
            throw runtime_error("Division by zero!");
        }
        return numerator / denominator;
    }
    catch (const exception &e)
    {
        cout << "Caught exception in divide(): " << e.what()
             << endl;
        throw; // Rethrow the caught exception to handle it at a higher level
    }
}

int calculateSum(int a, int b)
{
    try
    {
        if (a < 0 || b < 0)
        {
            throw invalid_argument("Negative numbers not allowed!"); // Throw an invalid_argument exception for negative numbers
        }
        return a + b;
    }
    catch (const exception &e)
    {
        cout << "Caught exception in calculateSum(): " << e.what() << endl;
        throw; // Rethrow the caught exception to handle it at a higher level
    }
}

int main()
{
    try
    {
        int result = calculateSum(10, divide(20, 2));
        cout << "Result: " << result << endl;
        
        int invalidResult = calculateSum(5, divide(10, 0));
        cout << "Invalid Result: " << invalidResult << endl;
    }
    catch (const exception &e)
    {
        cout << "Caught exception in main: " << e.what() << endl;
    }

    return 0;
}