# rcomp_sim
Simulator for 4-bit relay computer

# Usage

To use the simulator one must write a program in r4 and store it in a file with the .r4 file ending.
To run the simulator use the command ./rcomp_sim [ARG_01: filename .r4] [ARG_02: bitsize of machine]
The command-set of r4 is as follows:

# r4 commands

A command in r4 consists of a 3 char long command, followed by a n-bit number. 
In the current state the simulator expects a 4-bit number, but this will in future be updated to be customisable.

The simulated machine is currently a 4-bit machine, thus there are 16 registers available for use. 
This also will be customisable by adding arguments when running the simulator. 

command-set includes: 

NOP: does nothing
LDI: loads the argument as integer into the accu
LDA: loads the adresse given by the argument as integer into the accu
STA: stores the current value of the accu into the adresse given by the argument
ADI: adds argument as integer to current accu value and stors value in accu
ADA: adds value of register at adresse corresponding to the argument to the accu and stores value in accu
SBA: subtracts value of register at adresse corresponding to argument from the current accu value and stores in accu
INC: increases adresse given by argument by 1
DEC: decreases adresse given by argument by 1 
JMP: sets program counter to argument
JPZ: sets program counter to argument if accu is equal to 0
