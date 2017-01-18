/*The cell behavior and response simulation module for the LivMach Framework 1.3
  with support for Cell Growth Simulation Digital DNA.

  LIBRARY FILE(.h)== "livmach_cellenv.h"

  written by Shreyak Chakraborty (C) 2016
*/

# ifndef __LIVMACH_CELLENV__H
# define __LIVMACH_CELLENV__H

# include <iostream>
# include <conio.h>
# include <fstream>

using namespace std;

class cell     // the basic definition of a single cell in livmach
{

/* the DigiDNA integer array (dna[n]) controls the overall behavior of the cell. In LivMach 1.2,it contains 4
members.Each member controls specific part of the cell(object of the 'cell' class).
LivMach 1.2 supports only growth members in the dna (by default).
dna[0]=controls +X growth
dna[1]=controls -X growth
dna[2]=controls +Y growth
dna[3]=controls -Y growth

*/
public:   // no access protection. (To be changed)

int dna[12]; //declaration of the dna
float r,l,u,d; // growth attributes

int state;

cell()
{
state=0;   //Numerical Instantaneous State of the cell
}

int dna_trans(int a) //important function that translates the dna array to useful information and output
{
if (a==1)
state+=1;

else if (a==2)
state+=a;

else if (a==3)
state-=1;

else if (a==4)
state-=a;

else state=0;

return state;
}

public:
bool life;      // 1 is alive-state and 0 is dead-state
float tolerance; int c0,c1,c2,c3,n;

int cell_membrane(int pass) //defines a selectively permeable membrane used to access nuclear contents securely
{
if(pass==101) //selective permeability
{
c0=dna[0]; c1=dna[1]; c2=dna[2],c3=dna[3];
for(int i=0;i<10;i++)
{
r+=c0;
l+=c1;
u+=c2;
d+=c3;
}
cout<<"\nCell growth extensions:\n"<<"Left="<<l<<"\tRight="<<r<<"\nUp="<<u<<"\tDown="<<d;
}
return 0;
}
};

bool repair(cell C)   // function to repair cells
{
C.life=1;
return C.life;
}


int intro()
{
	cout<<"THE LivMach ORGANISM SIMULATION FRAMEWORK DEVELOPED BY ShreyakChakraborty(C)2015\n";
}


# endif




