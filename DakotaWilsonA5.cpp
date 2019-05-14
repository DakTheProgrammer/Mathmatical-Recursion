#include <iostream>
#include <iomanip>
using namespace std;
//*****************************************************************************
//							Assignment #5
//						Name: Dakota Wilson
//						Data Structures: 4/1/19
//*****************************************************************************
//		This program uses 3 recursive functions. The first function uses 
//	recursion to find the summation of a positve number by all even numbers to 
//	the value 1. The second function uses recursion to find the exponenential 
//	value of a base for a integer base and an integer exponent value. Lastly, 
//	the third function uses recursion to find the product of an input number
//  by all even values until 1.
//*****************************************************************************

//*****************************************************************************
//							int Summation(int n1)
//		This function takes in a integer value and will find the summation of 
//	all declining odd numbers recursivly until it reaches the number 1. It 
//	will then return that value to the main function for output.
//*****************************************************************************
int Summation(int n1);

//*****************************************************************************
//					double BaseExponent(int base, int exp);
//		This function takes in 2 integer values. The base number and the 
//	exponent of that base number that the user wants to see ex.6^-4. it will
//	then run recursivly to find the value and then will return to main for 
//	output
//*****************************************************************************
double BaseExponent(int base, int exp);

//*****************************************************************************
//					int Product(int prod);
//		This function takes in an integer value and will then recursivly
//	find the product of all declining even numbers of that number until it 
//	reaches 1. It will then return to main the product of thoes numbers for 
//	output.
//*****************************************************************************
int Product(int prod);

int main()
{
	int n1, base, exp, prod;

	cout << "Enter a integer number to be the summation of all odd integers "
		"from 1 to the number input: ";
	cin >> n1;//inputs number to be summated by odds
	
	while (n1 <= 0)//used for if the user enters 0 or negative
	{
		cout << "That number is smaller then 1 try again: ";
		cin >> n1;
	}

	cout << "The summation is: " << Summation(n1) << '\n';//prints summation

	cout << "Enter a base intieger vale: ";
	cin >> base;//enters base of exponent
	cout << "Enter a integar exponential value: ";
	cin >> exp;//enters exponent value

	cout << "The Value of your exponential value "
		"is(prints to the 10th decimal point): " 
		<< fixed << setprecision(10) << BaseExponent(base, exp) 
		<< '\n';//prints exponetial value

	cout << "Enter a positive number that will compute the product "
		"of all even numbers between the number given and 1: ";
	cin >> prod;//enters number to find product of evens

	while (prod <= 0)//used if number entered is 0 or neg
	{
		cout << "That number is smaller then 1 try again: ";
		cin >> prod;
	}

	cout << "The product of all even numbers is: " << Product(prod)
		<< '\n';//outputs product of evens

	system("pause");
	return 0;
}

int Summation(int n1)
{
	if (n1 == 0)//ends recursion
	{
		cout << 0 << '\n';
		return 0;
	}
	else if (n1 % 2 == 0)//used if even
	{
		return Summation(n1 - 1);//loops
	}
	else if (n1 % 1 == 0)//used if odd
	{
		cout << n1 << '\n';
		return n1 + Summation(n1 - 1);//sumates then loops
	}
}

double BaseExponent(int base, int exp)
{
	if (exp == 0)//ends recursion
	{
		return 1;
	}
	else if(exp > 0)//used if exponent is positive
	{
		return base * BaseExponent(base, exp - 1);//returns pos exp
	}
	else//used if exponent is negative
	{
		return ((1 / BaseExponent(base, -exp)));//returns neg exp
	}
}

int Product(int prod)
{
	if (prod == 1)//ends recursion
	{
		return 1;
	}
	else if (prod % 2 == 0)//used if even
	{
		return prod * Product(prod - 1);//returns product
		
	}
	else if (prod % 1 == 0)//used if odd
	{
		return Product(prod - 1);//loops recursion
	}
}