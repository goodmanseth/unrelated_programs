#include <iostream>
#include <string>
#include <cmath>

using namespace std;

bool isPrime(unsigned long long);

int main(int argc, char **argv) {
    if (argc == 3) {
        cout << "Incorrect number of input statements. Try again." << endl;
        return -1;
    }
    
    unsigned long long x=-1,y=-1;
    bool upperBound = false;
    if (argc == 1) x = 0;
    else if (argc == 2) {
        x = stoll(argv[1]);
    }
    else {
        x = stoll(argv[1]);
        y = stoll(argv[2]);
        upperBound = true;
    }
    if (y < x && y != 0) {
        unsigned long long temp = x;
        x = y;
        y = temp;
    }
     
    for(; x<y; x++) {
        if (isPrime(x)) 
            cout << x << endl;
    }
}

bool isPrime(unsigned long long z) {
    if (z < 2) return false;        // 0 and 1 are NOT prime
    if (z == 2) return true;        // 2 is prime
    if (!(z & 0x1)) return false;  // check if divisible by 2
    
    // the upper bound on a for loop is the sqrt of the number
    unsigned long long upper = static_cast<unsigned long long>(sqrt(z));
    for(int i=3; i<=upper; i++) {
        if (z%i == 0) return false; 
    }
    return true;
}
