/* The DNA Transcription and Translation Simulation Module  for the LivMach Framework 1.3
written in C++11 by Shreyak Chakraborty (C) 2016

The functions in this module can be used to transcribe or translate any DNA sequence entered manually

The actual bases are encoded as A=1, C=2, G=3, T=4


Digital DNA and RNA are represented as integer arrays and enzymes such as RNA Polymerase as functions of
integer arrays


The process of splicing is simulated in the Spliceosome Organelle by the use of dynamic arrays
The LivMAch mRNA Translation Algorithm generates Digital Proteins as an integer array with both negative and
positive entries using a predefined linear combination of elements of a mRNA codon.



Note:- No class implementations are done here as of v1.2
       In v1.4, this module will be merged with the LivMAch Standard Library.
*/

# include <iostream>
# include <conio.h>

using namespace std;

int dna[2][16],hnRNA[16];
int* mRNA;                   // declaration of the main ternary nucleic acid sequences
int i,j,k1,k2;

int dna_init()  // Initializes the DNA strands
{
    cout<<"\n\n\nEnter Template Strand (16)";

    for(i=0,j=0;j<16;j++)
    {
        cin>>dna[i][j];     // Template Strand (i=0)

        if(dna[i][j]==1)    // Template Strand (i+1=1)
            dna[i+1][j]=3;
        if(dna[i][j]==2)
            dna[i+1][j]=4;
        if(dna[i][j]==3)
            dna[i+1][j]=1;
        if(dna[i][j]==4)
            dna[i+1][j]=2;
    }

    cout<<"\n\n DNA Initialization Successful...\n";

    return 0;
}

int dna_disp()
{
    cout<<"\n\n";
    for(i=0;i<2;i++)
    {
        cout<<"\n";
        for(j=0;j<16;j++)
            cout<<dna[i][j]<<" ";
    }

    return 0;

}

/** The main "enzyme" functions and operators are defined below that converts DNA data into mRNA data
    based on promoter and terminator sub-sequences on the DNA strand

*/



int detect_promoter(int d[2][16])     // Detects promoter sequence in the DNA integer array
{
    for(i=0,j=0;j<16;j++)
    {
        if(d[i][j]==4&&d[i][j+1]==1&&d[i][j+2]==4&&d[i][j+3]==1)  // searches for 1st TATA sub-sequence
            k1=j;
        break;
    }

    cout<<"\nPromoter start=\t"<<k1<<endl;

    return k1;

}

int detect_terminator(int d[2][16])   // Detects terminator sequence in the DNA integer array
{
    for(i=0,j=0;j<16;j++)
    {
        if(d[i][j]==4&&d[i][j+1]==1&&d[i][j+2]==4&&d[i][j+3]==1)  // searches for 2Nd TATA sub-sequence
            k2=j;
    }
    cout<<"terminator start="<<k2<<endl;
    return k2;

}


int RNA_Polym2(int d[2][16],int a,int b)   // Defines RNA Polymerase II acting on the Digital DNA
{
    for(i=1,j=a;j<b;j++)
    {
        if(d[i][j]==4)               // Replaces T by U in RNA
            hnRNA[j]=5;
        else
            hnRNA[j]=d[i][j];

    }

    cout<<"\nENZYME:RNAP II Action on Digital DNA Strand completed....\n\n";

    return hnRNA[16];
}


/** Defines the spliceosome organelle as a function of the hnRNA for splicing of hnRNA to mRNA
    This organelle uses a dynamic array to simulate the spliced mRNA strand from the larger hnRNA strand

    Note: This routine uses pointers and therefore should be handled carefully
*/

int spliceosome(int hnrna[])
{
    int mrna_size=0,residue;

     mRNA=new (nothrow) int[mrna_size];    // The mRNA Strand is declared as a dynamic integer array

     for(i=0,j=0;i<16;i++)   // he Splicing Routine Loop
         {
             if(hnrna[i]==0)
                residue++;     // this is the no. of zero entries in the hnRNA array
             else
             {
                 mrna_size++;
                 mRNA[j]=hnrna[i];
                 j++;
             }
         }

     cout<<"\n\n\nThe transcribed mRNA sequence is:\n";

     for(i=0;i<mrna_size;i++)      // display the mRNA sequence
        cout<<mRNA[i]<<" ";

     delete[] mRNA;

     return 0;


}










int main()
{
    int x,y;
    char z;
    cout<<"DNA Transcription and Translation Simulation Module for the\nLivMAch Framework 1.3\nby Shreyak Chakraborty(C) 2015"<<endl;
	cout<<"\n\nA=1\tC=2\tG=3\tT=4\tU=5"<<endl;
    dna_init();
    dna_disp();
    x=detect_promoter(dna);
    y=detect_terminator(dna);
    cout<<"\n\nPromoter and Terminator detection complete.\n\tPress a key";
    cin>>z;
    RNA_Polym2(dna,x,y);

    cout<<"\n\n Nascent RNA sequence:\n ";

    for(i=0;i<16;i++)
    {
        cout<<hnRNA[i]<<" ";
    }

    cout<<"\n\n";

    cout<<"Press a key to start the Splicing Process via spliceosome()";
    cin>>z;

    spliceosome(hnRNA);

    getch();

    return 0;
}





