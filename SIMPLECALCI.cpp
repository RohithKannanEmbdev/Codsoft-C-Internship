#include<iostream>
using namespace std;
int main()
{
	int num1,num2;
	char symbol;
	cout<<"Enter Number 1 Value: ";
	cin>>num1;
	cout<<"Enter Number 2 Value: ";
	cin>>num2;
	cout<<"Enter Sign: ";
	cin>>symbol;
	switch(symbol)
	{
		case '+':
		cout<<"Result: "<<num1+num2;	
		break;
		
		case '-':
		cout<<"Result: "<<num1-num2;	
		break;
		
		case '*':
		cout<<"Result: "<<num1*num2;	
		break;
		
		case '/':
			if(num2==0)
			{
				cout<<"Not Divisible!\n";
				cout<<"Enter Number 2 Value Again: ";
				cin>>num2;
			}
		cout<<"Result: "<<num1/num2;	
		break;	
	}
}


