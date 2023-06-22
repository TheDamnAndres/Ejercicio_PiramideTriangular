#include <stdio.h>
#include "headers.h"

int main(){

    float puntos[4][3] = {{0,0,3}, {3,0,0},{0,0,0},{1,7,1}};
    float b[1][3];
    float p1, p2, p3, p4, l1, l2, l3, l4, l5,l6, s1, s2, s3, s4, abase;

    float perimetro = calcularPerimetro(puntos, &p1, &p2,  &p3,  &p4,   &l1,  &l2,  &l3,  &l4, &l5, &l6, &s1, &s2, &s3, &s4);
    float area = calcularArea(&l1,  &l2,  &l3,  &l4,  &l5,  &l6,  &s1, &s2, &s3, &s4, &abase);
    float volumen = calcularVolumen(puntos, &abase, b);

    printf("Perimetro %.2f\n", perimetro);
    printf("Area %.2f\n", area);
    printf("Volumen %.2f\n", volumen);

    return 0;
}







