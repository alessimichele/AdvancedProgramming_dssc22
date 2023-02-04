#include <iostream>
#include <exception>

/*
"throw" is a keyword in C++ used to raise an exception, 
while "catch" is used to handle the exception. 
Here's an example of how they work together:
*/

void divisionByZero()
{
  int x = 5;
  int y = 0;
  if (y == 0)
  {
    throw std::runtime_error("Cannot divide by zero");
  }
  int result = x / y;
  std::cout << "Result: " << result << std::endl;
}

int main()
{
  try
  {
    divisionByZero();
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  return 0;
}

/*
In the example, the divisionByZero function raises an exception
 when y is equal to zero. 
 The exception is then caught in the main function and its 
 message is printed to the standard error stream.
 */