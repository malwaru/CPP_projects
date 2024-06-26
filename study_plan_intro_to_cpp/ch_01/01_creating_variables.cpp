#include <iostream>

int main()
{
// Declare and initialize a variable x of type int using the traditional syntax
int a = 10;
// Declare a variable x of type int and initialize it with the value 10 
// Using tjhe uniform initialization syntax
int x {10};
// Copy the value of x into y
int y {x};
// But to change the value of y to 20 we need to use the = operator
y = 20;
return 0;
}