# Prime Finder

This program finds prime numbers between a specified range. To use the program, run the command `./primeFinder X Y`, where X and Y are the lower bound and the upper bound, respectively. Alternatively, you can run the program with no upper bound, except the one limited by 64 bits (2^64-1), by typing `./primeFinder X`, where X is a lower bound. If you just run `./primeFinder`, the lower bound will default to 0.

This program should be compiled like the following:

`g++ -g -O3 -ffast-math primeFinder.cpp -o primeFinder -lm` 
