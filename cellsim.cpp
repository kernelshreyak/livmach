/*
Cell/tissue response simulation module for LivMach Framework 1.3
Author: Shreyak Chakraborty (C) 2016

Multiple cells i.e. tissue are created using an array of "Cell" Type
*/

# include "livmach_cellenv.h"

int main()
{
int i,pass;
float stim;   // the numeric value of the external stimulus
char x;

cell tissue[5];
cell Cell;

intro();

cout<<"Enter stimulus value";
cin>>stim;
cout<<"\n\nDefine tissue:";
for(i=0;i<5;i++)
{
cin>>tissue[i].tolerance;
}
cout<<"\n\nThe tissue response is-\n\t";
for(i=0;i<5;i++)
{
if(tissue[i].tolerance<stim)
tissue[i].life=0;
else
tissue[i].life=1;
cout<<tissue[i].life<<" ";
}

cout<<"\n\nPress a key to repair cells";
x=getche();
cout<<"\n";
for (i=0;i<5;i++)
{
tissue[i].life=repair(tissue[i]);
}

for (i=0;i<5;i++)
cout<<tissue[i].life<<" ";
cout<<"\nCells repaired successfully...";

cout<<"\n\n\nPress a key to start the experimental Digital DNA Module 1";
x=getch();
cout<<"\n\n Enter passcode";
cin>>pass;
Cell.cell_membrane(pass);



getch();

return 0;
}
