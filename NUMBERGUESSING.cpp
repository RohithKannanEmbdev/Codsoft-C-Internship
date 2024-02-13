#include<iostream>
#include<cstdlib>
using namespace std;

int main()
{
    int Magicnum, Guessnum, snum, ennum;
	cout<<"Enter Start Range: \n";
    cin>>snum;
    cout<<"Enter End Range: \n";
    cin>>ennum;
    Magicnum=rand()%(ennum-snum+1)+snum;
    cout<<"Guess the number between "<<snum<<" and "<<ennum<<"!\n";

    while(true)
    {
        cout<<"Enter your guess: ";
        cin>>Guessnum;
        if(Guessnum==Magicnum)
        {
            cout << "Congrats! You've Guessed the Number!\n";
            break;
        }
        else if(Guessnum<Magicnum)
        {
        	Magicnum-=2;
            if(Magicnum<=Guessnum)
			{
				cout<<"Near!";
			}
			else
			{
				cout<<"Low!";
			}
        }
        else
        {
        	Magicnum+=2;
			if(Magicnum>=Guessnum)
			{
				cout<<"Near!";
			}
			else
			{
				cout<<"High!";
			}
        }
    }
}



