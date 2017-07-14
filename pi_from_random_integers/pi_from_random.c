/* 
*   This program uses the probability that two numbers are coprime
*   ( 6/(pi^2) ) to generate pi.
*   
*   6/pi^2 = coprime/num 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <unistd.h>

void loading_icon();
int min(int, int);
int gcd(int, int);

int main(int argc, char **argv) {
    int num;
    
    // asks for input
    printf("This program estimates the value of pi, utilizing the probability that two random numbers are coprime (6/pi^2).\n");
    printf("Number of random pairs to generate: ");
    
    // error checking
    if (scanf("%d", &num) != 1) {
        fprintf(stderr, "Input not an integer.\n");
        return EXIT_FAILURE;
    }
    
    //clock_t t = clock();
    int coprime = 0, i,j;
    srand(time(NULL));          // generating random seed
    for (i=0;i<num;i++){ 
        int a = rand();
        int b = rand();
        if (gcd(a,b) == 1) coprime++;
        if (i % 500000 == 0)
            loading_icon();
    }
    float coprime_percentage = (float) coprime / (float) num;
    float pi = sqrt(6.0/coprime_percentage);
    printf("The approximate value of pi is: %f\n",pi);
    //t = clock() - t;
    //double time_taken = ((double)t)/CLOCKS_PER_SEC;
    //printf("\nThis function took approximately %f seconds to execute\n\n",
    //        time_taken);
}

void loading_icon(){
    static int state = 0;
    char cursor[4] = {'|','/','-','\\'};
    fflush(stdout);
    printf("%c\b",cursor[state]);
    state = (state+1) % 4;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int gcd(int a, int b) {
    if (!b) return a;
    return gcd(b,a%b);
}
