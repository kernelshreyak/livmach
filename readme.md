LivMach Organism Simulation Framework
[Developed by Shreyak Chakraborty     
email:shreyak.rekshda@gmail.com]
[Distributed under GNU GPL]

LivMach Framework is written in C++ to facilitate the simulation of biological unicellular and multicellular organisms.

Current version (v1.3) combines the functions of the framework into two library (header) files: "livmach_core.h" and "livmach_cellenv.h"

"livmach_core.h": this file contains the main code for simulation of organisms at a macroscopic level i.e creation of custom organ systems and biological networks and defining the respone under various stimuli. Currently contains classes for the Brain, Central Nervous System (CNS), Lungs and Sensory I/0 system

"livmach_cellenv.h": this file contains the 'Cell' class and accompanying functions to simulate organisms at a microscopic level.
A digital DNA (integer array) can be used to control behaviour of the cell.
Multiple objects of 'Cell' type form a tissue that can be modified as required.

To test the LivMach Framework, compile any of the separate examples: 
1."lifeprosim.cpp"(simulation of breathing process)
2."cellsim.cpp" (simulation of a simple tissue and response under external stimulus)
3."cellseq.cpp" (simulation of cellular mutations based on a single integer array: the DNA)
4."digidna.cpp" (initial simulation of a digital counterpart of DNA to control the cell. Currently it supports 4 bases:A,C,T,G
and simulates transcription and translation of a DNA sequence entered manually)

-----------MORE  FEATURES WILL BE ADDED IN SUBSEQUENT RELEASES------------------------------
