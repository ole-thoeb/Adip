#include <stdio.h>

float summeflo()
{
    float x1=10000.0, x2=-1.0/9000.0, x3=2500.0, x4=1.0/7000.0, x5=-12500.0;
    float erg=0.0;
    erg=x1+x2+x3+x4+x5;    
    return erg;

}
double summedou()
{
    double x1=(double)10000, x2=(double)-1/9000, x3=(double)2500, x4=(double)1/7000, x5=(double)-12500;
    double erg=0;
    erg=x1+x2+x3+x4+x5;
    return erg;
}

float verfahren()
{
    float x[5]={10000.0, (-1.0/9000.0), 2500.0, (1.0/7000.0), (-12500.0)};
    float S=0.0, D=0.0;
    int n=5;

    for (int i=0;i<n; i++)
    {
        float Salt=S;
          //printf("Salt=%f\n", Salt);
        S=S+x[i];
          //printf("S=%f+%f=%f\n", Salt, x[i], S);
        D=D+(x[i]-(S-Salt));
           //printf("D=%f=(%f-(%f-%f)\n", D, x[i], S, Salt);
        S=S+D;
           //printf("S=%f=%f+%f\n\n", S, D, Salt);
    }
    return S;
}

double verfdou()
{
    double x[5]={(double)10000.0, ((double)-1.0/9000.0), (double)2500.0, ((double)1.0/7000.0), ((double)-12500.0)};
    double S=0.0, D=0.0;
    int n=5;

    for (int i=0;i<n; i++)
    {
        double Salt=S;
           // printf("Salt=%lf\n", Salt);
        S=S+x[i];
           // printf("S=%lf+%lf=%lf\n", Salt, x[i], S);
        D=D+(x[i]-(S-Salt));
           // printf("D=%lf=(%lf-(%lf-%lf)\n", D, x[i], S, Salt);
        S=S+D;
           // printf("S=%lf=%lf+%lf\n\n", S, D, Salt);
    }
    return S;
}

int main()
{

    printf("b) floats: %f\n", summeflo());
    printf("c) doubles: %lf\n", summedou());

    printf("d) Spezialverfahren, floats: %f\n", verfahren());

    printf("e) das Spezialverfahren ist besser geeignet, da in diesem Fall Rundungsfehler wieder rückgängig gemacht werden können.\n\tWährend bei der einfachen Addition durch die hohen Zahlen und den Gleitpunkt Genauigkeit bei den Nachkommastellen verloren geht, \n\tkann in dem Spezialverfahren die Variable D für die Genauigkeit bei den Nachkommastellen sorgen.\n" );
    printf("f) Spezialverfahren, doubles: %lf\n", verfdou());





return 0;
}
