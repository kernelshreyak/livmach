/*

Sequenced Cell Control Simulation for LivMach Framework 1.3
Author: Shreyak Chakraborty (C) 2016


This program can be used to simulate growth of cell and also to modify the complete cell using a single integer array
i.e. a Digital DNA Sequence (ternary code).

Note: At this stage, only the abstract cell state can be modified

Multiple cells can be constructed using an object array of object type=Cell

*/



# include "livmach_cellenv.h"


int main()
{
cell c1;
int i,j,N,x;
ofstream fout;

cout<<"\n\n\nEnter dna sequence (12)";


for(i=0;i<12;i++)
{
cin>>c1.dna[i];
}

cout<<"\n\nEnter Number of complete sequence translations:\t";
cin>>N;

fout.open("DigiDNA_Cell_Test.txt");

for(i=0;i<N;i++)
{

for(j=0;j<12;j++)
{
x=c1.dna[i];
fout<<"\nCell State:"<<"\t"<<c1.dna_trans(x);  // Outputs the cell state after each translation of a DNA segment (one integer value)
}

}


return 0;

}




