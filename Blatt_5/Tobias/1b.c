//\xde
//shift Enter (soft return)

#include <stdio.h>

char*encrypt(char* s)
//char encrypt(char s[])
{
//0x41+25;0x61

    for(int i=0; s[i+1]!=0;i++)
    {
        if(s[i]<0x61&&s[i]>=0x41)
        {
            s[i]=(13+(s[i]-0x41))%26+0x41;
            //s[i]+=13;
        }
        else if(s[i]>=0x61&&s[i]<=0x7a)
        {
            s[i]=(13+(s[i]-0x61))%26+0x61;
            //s[i]+=13;
        }
    } 
    printf("verschlüsselter String:\t%s\n", s);
}

char*decrypt(char*s)
//char decrypt(char s[])
{
    for(int i=0; s[i+1]!=0;i++)
    {
        if(s[i]<0x61&&s[i]>=0x41)
        {
            s[i]=(((s[i]-0x41)-13)+26)%26+0x41;
        }
        else if(s[i]>=0x61&&s[i]<=0x7aa)
        {
            s[i]=(((s[i]-0x61)-13)+26)%26+0x61;
        }
    } 
    printf("entschlüsselter String:\t%s\n", s);
}



int main()
{
//1. Herangehensweise
//ersten Buchstaben als int
//dann mod 26 und addieren auf ersten Buchstaben
//Rausfinden, wo im Alphabet, indem int von erstem Buchstaben abgezogen wird
//Dafür sorgen, dass Groß- und Kleinbuchstaben funktionieren


//2. Herangehensweise
//Array rotieren. steckt ja eig. im Funktionsnamen
//zweites Array, wo die zwischenpositionen abgespeichert werden


char string[50];
printf("Geben Sie einen String ein\n");
fgets(string, 50,stdin);    
//printf("%s\n", string);
//printf("test %c\n", 0x41);
//printf("test %i\n", ((-2)%26));

encrypt(string);
decrypt(string);
    return 0;
}
