/* The LivMach Framework Project(C) 2016, Shreyak Chakraborty
   aims to create an artificial living being with a complete system of
   organs,a central nervous system and even a 'Digital DNA'!!
   This source code is distributed under GPL v2.0

In this cpp file, all the basic functions and data structures of the livmach
are defined.These are essential for the survival of the livmach.Other
files in the main livmach directry are used for additional purposes.


The code in this file contols all the life processes of the livmach.
Only the main organs: brain,nervous system and sense organs are defined in
this file. Any other organ can be coded separately or used by including other
files of the livmach directry.

	Classes Used:    NCI_SYS             the brain
			         CNS_IO              the central nervous system
			         RS_IO               the sensory system

*/


//  LIBRARY FILE(.h)== "livmach_core.h"



// This is the core header file of LivMach 1.2

# ifndef __LIVMACH_CORE__H
# define __LIVMACH_CORE__H


# include <iostream>
# include <string.h>
# include <process.h>
# include <iomanip>
# include <stdlib.h>
# include <stdio.h>
# include <conio.h>

using namespace std;

int flag;     //Indicator Variable



class NCI_SYS               // The Brain is declared
{
int resp;

protected:
void interpret(int cod)   // This important function interprets the stimulus
{
if(cod==1)
resp=1;
else if(cod==2)
{
cout<<"\nSOUND";
resp=2;
}
else resp=0;
cout<<"\n\t NCI Response generated";
sendresp(resp);
}
void brainaccess(int y)
{
cout<<"\n Stimulus data reached NCI_SYS";
int cod;
cod=y;
interpret(cod);
}
void sendresp(int rsp)
{
cout<<"\nResponse reached NCI_SYS";
flag=rsp;
}
void AIRCONTROL(int x)
{
	cout<<"\nAIR SIGNAL REACHED BRAIN!!!";
	cout<<"\nValue="<<x;
}


};



class CNS_IO:public NCI_SYS       //The Central Nervous System is declared
{
int braincb; int LP_access;   //LP_access is a common variable used for all life processes

public:
void I_stream(int x)  // establishes connection to brain
{
cout<<"\nStimuls data reached CNS_IO";
braincb=x;
brainaccess(braincb);
}
int O_stream(int rsp)
{
cout<<"\nResponse reached CNS_IO";
return rsp;
}
int I_Stream2(int AIR)   // another stream for signalling brain
{
	cout<<"\nSignal from respiration reached CNS_IO";
	LP_access=AIR;
	AIRCONTROL(LP_access);
}

};



class RS_IO:public CNS_IO                    // Root Sensory System
{
int Rn1,y;

public:
void recp(int s)    // receptor function
{
cout<<"\nStimulus data reached RS_IO";
Rn1=s;
I_stream(Rn1);
}
void OutResp(int R)
{
cout<<"\nResponse data reached RS_IO";
cout<<"\n\t Brain commanded RS_IO to change state of the receptor\n Press a key to continue";
y=getche();

cout<<"\n\t Receptor state changed successfully due to response:\t"<<R;
}
};

//#############################################################################



/* Here we use 2 special functions to transfer the repsonse signals between
      various parts of LivMach. These are called Transfer Functions and
      are declared globally. These donot contribute to the physicality of
      any of the LivMach classes.
*/

void CNStoRS(int rsp)      /* sends response from central nervous system
			                  to the Root Sensory System */
{
RS_IO rs;
rs.OutResp(rsp);
}

void NCItoCNS(int rsp)     /* sends response from brain to the
			      Central Nervous System */
{
CNS_IO cns;
cns.O_stream(rsp);
CNStoRS(rsp);
}
//*****************************************************************************

void intro()
{
printf("THE LivMach ORGANISM SIMULATION FRAMEWORK developed by ShreyakChakraborty(C)2015");
}
//******************************************************************************
/* We now define the Stimulus Enumeration List(SEL) and a function DoStim to
   give a variety of stimulii to LivMach */

enum stimulus
{
no_stim,
stim_heat,
stim_mechanical,
stim_electrical,
stim_air,
};

void DoStim(int st)
{
RS_IO organism;       char g;
stimulus stim;
if(st==0)
{ cout<<"\nNo stimulus given";
stim=no_stim;
cout<<"\nPress a key to continue";
g=getche();
exit(1);
}
else if(st==1)
{ cout<<"\nHeat stimulus given\n\n";
stim=stim_heat;
organism.recp(stim);   // sends stimulus to the Sensory System's receptor(s)
}
else if(st==2)
{ cout<<"\nMechanical stimulus given\n\n";
stim=stim_mechanical;
organism.recp(stim);
}
}



   // SIMULATION OF LIFE PROCESSES USING THE LifeProSim INBUILT MODULE

   /*
    We briefly explain the LifeProSim Inbuilt/Internal Module for simulating life processes in LivMach
We now use a number of structures to simulate various life processes in the livmach body. These data structures
generally allow unidirectional data flow. The structures behave as organs as seen earlier(in case of response
simulations). Any cell of a given organ(a structure) is defined as an object of that structure.

The organ systems defined are
     THE RESPIRATORY SYSTEM:          struct air_input         AIn
	                                  struct air_process       APro
								      struct air_output        AOut

	 THE MAIN ENERGY CONTROL SYSTEM:  struct energy_input      EIn
                                      struct energy_process	   EPro
                                      struct energy_output     EOut
                                      struct energy_usage	   EAv


		Similarly, other organ systems can be defined with the required properties. These organs and organ systems
		implement the Data Flow Replication Method(DFRM) i.e replicating the data flow flow of a full fledged
		living system into a computer system.

In LivMach 1.0, the life processes start at the user command at TUI but end automatically.
*/



struct AOut     // this structure helps in exhaling
{
	void Air_End(int aval)
	{
		cout<<"\nAir exhaled with value=\t"<<aval;
		cout<<"\nLIFE PROCESS COMPLETE\n\n";
	}

};




struct EPro
{
void E_Abs(int &a)
{
	CNS_IO enerstream;
		cout<<"\nENERGY ABSORBED";
		enerstream.I_Stream2(a);
		}
};




struct APro                     // this structures manages air flow throughout livmach body
{
	int Air_Flow(int a,int bfac,int M)     //bfac=Bronchii Factor
{
	EPro epro; CNS_IO airstream;   // airstream tranfers data from virtual lungs to the brain via CNS
	cout<<"\nAir Recieved..\nOxygen being extracted from Air";
	a=a-bfac;          //reduces effective air value
	epro.E_Abs(a);
	airstream.I_Stream2(a);
	cout<<"\nOxygen extracted from air...\nOXYGEN TRANSFERRED TO\t"<<M<<"\tbody sites\n\n";
	return a;
	a+=bfac;
}

};





struct AIn    // this tructures helps in inhaling
{
	void Air_Do(int air,int n)
{
	APro apro; AOut aout;
	int aval;             // aval is a temporary variable to store changed air value
	for(int i=0;i<n;i++)
	{
		cout<<"\nLIFE PROCESS STARTED";
	  aval=apro.Air_Flow(air,2,2000);     // Bronchii factor bfac=2.3 and M= no. of sites where
	  aout.Air_End(aval);
	}
}
void Air_Start(int air)
{
int n;
cout<<"\nEnter loop index(n)";
cin>>n;
Air_Do(air,n);
}
};






# endif



