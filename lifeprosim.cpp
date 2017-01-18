/*
Life Process Simulation written in C++ using LivMach Framework 1.3
Author: Shreyak Chakraborty (C) 2016
(this code uses the stimulus response engine and the LifeProSim Module of LivMach Framework)
*/

# include "livmach_core.h"   // the core library file of Livmach

int main()
{
intro();
int stim,air; char x;
AIn A;

START:
cout<<"\nEnter Stimulus No.";
cin>>stim;

cout<<"\nPress a key to test the LifeProSim Module";
x=getche();
cout<<"\nEnter air value";
cin>>air;

# pragma omp parallel sections
{
# pragma omp section  // this section executes the stimulus response engine
{
DoStim(stim);
NCItoCNS(flag);
}

# pragma omp section // this section executes the LifeProSim Module
{
	A.Air_Start(air);
}
}



getch();
return 0;
}
