#include <math.h>

float distancias(float x1, float y1, float z1, float x2, float y2, float z2){

    float dist = sqrt(pow(x2-x1,2)+pow(y2-y1,2)+pow(z2-z1,2));
    return dist;

}

float calcularPerimetro(float puntos[4][3], float *p1, float *p2, float *p3, float *p4,  float *l1, float *l2, float *l3, float *l4, float *l5, float *l6, float *s1,float *s2,float *s3,float *s4){

    *l1 = distancias(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *l2 = distancias(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]);
    *l3 = distancias(puntos[2][0], puntos[2][1], puntos[2][2], puntos[1][0], puntos[1][1], puntos[1][2]);
    *l4 = distancias(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *l5 = distancias(puntos[1][0], puntos[2][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]);
    *l6 = distancias(puntos[2][0], puntos[2][1], puntos[2][2], puntos[3][0], puntos[3][1], puntos[3][2]);

    ///printf("%f   %f   %f   %f  %f    %f\n", *l1, *l2, *l3, *l4, *l5, *l6);

    *p1 = *l1 + *l2 + *l3;
    *p2 = *l2 + *l4 + *l6;
    *p3 = *l3 + *l5 + *l6;
    *p4 = *l1 + *l5 + *l4;

    ///printf("%f   %f   %f   %f  \n", *p1, *p2, *p3, *p4);

    float per = *p1 + *p2 + *p3 + *p4;

    *s1 = *p1/2;
    *s2 = *p2/2;
    *s3 = *p3/2;
    *s4 = *p4/2;

    ///printf("%f   %f   %f   %f  \n", *s1, *s2, *s3, *s4);

    return per;
}

float heron(float s, float l1, float l2, float l3){

    float heron = sqrt(s * (s-l1) * (s-l2) * (s-l3));
    return heron;
}

float calcularArea(float *l1, float *l2, float *l3, float *l4, float *l5, float *l6, float *s1,float *s2,float *s3,float *s4, float *abase){

    float area2, area3, area4, at;

    *abase = heron(*s1, *l1, *l2, *l3);
    area2 = heron(*s2, *l2, *l4, *l6);
    area3 = heron(*s3, *l3, *l5, *l6);
    area4 = heron(*s4, *l1, *l5, *l4);

    ///printf("%f   %f   %f   %f   \n", *abase, area2, area3, area4);

    at = *abase + area2 + area3 + area4;

    return at;
}

float calcularVolumen( float puntos[4][3], float *abase, float b[1][3]){

    float h, v;

    b[1][0] = (puntos[0][0] + puntos[0][1] + puntos[0][2]) / 3;
    b[1][1] = (puntos[1][0] + puntos[1][1] + puntos[1][2]) / 3;
    b[1][2] = (puntos[2][0] + puntos[2][1] + puntos[2][2]) / 3;

    h = distancias(b[0][0], b[0][1], b[0][2], puntos[3][0], puntos[3][1], puntos[3][2]);

    v = (*abase * h )/ 3;

    return v;
}
