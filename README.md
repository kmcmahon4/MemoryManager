# MemoryManager
Memory Management Simulation Written in C.


Memory Manager Program - Readme File @author: Kerri McMahon

Welcome to my Memory Management Simulation Program. Some brief things to note:

-TO USE AND RUN PROGRAM:

    -Open terminal (CLICK BUTTON IN BOTTOM RIGHT CORNER, TYPE IN TERMINAL IN SEARCH BAR)

    cd ./Desktop/cpu

    ./memory_manager
        ASSUMPTIONS - -
        Maximum amount of processes in the queue that can be considered is 10 for each algorithm. 
        Job size no more than 1000.

  
My program consists of:

-int main() function -Purpose: to control program flow

-void ff() function -Purpose: to perform First Fit Algorithm

-void bf() function -Purpose: to perform Best FitAlgorithm

-void wf() function -Purpose: to perform Worst Fit Algorithm

-My program does NOT include its own header (.h) file, as it was not necessary.

How to use my program:

-Choose which algorithm you would like to simulate

    Press 1 for First Fit
    Press 2 for Best Fit
    Press 3 for Worst Fit

-If you choose FCFS: -Press Y or N if you would like randomized burst times

    If N, you will be asked to manually input them

-If you are in SJF: -Press Y or N if you would like randomized burst times

    If N, you will be asked to manually input them

-If you are in RR: -Press Y or N if you would like to consider arrival times -if N, all arrival times will be initialized to 0. If Y, you will be asked to input them manually -Enter a time quantum

-Press 9 to exit the program after desired execution
