#include <stdio.h>
#include <complex.h>

// note if building, build it with the -lm flag

int main(){

    printf("starting complex computation\n");

    double _Complex number = 3 + 4* I;
    double _Complex number2 = -2 - 2 * I;
    double _Complex sum = number + number2;


    double real_part = creal(sum);
    double imaginary_part = cimag(sum);

    printf("Real Part: %f\t | imaginary part: %f\n", real_part, imaginary_part);
    printf("Distance / Absolute value %f\n", cabs(sum));




}
