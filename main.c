#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define XI 0.01745329252

int main()
{
    int N=1000000,B,i,k;
    double r_x,r_y,angle;
    double P,pi[100];
    double p1_x,p1_y,p2_x,p2_y;
    double a=3,b=4,l=1;
    FILE* fp;
    fp=fopen("pi.txt","w");
    if(l>=sqrt(a*a+b*b)){
        printf("l is larger than sqrt(a*a+b*b,wrong!");
        exit(1);
    }
    srand(time(NULL));
    for(k=0;k<100;k++){
        B=0;
        for(i=0;i<N;i++){
            r_x=((double)rand())*100000/((double)RAND_MAX);
            r_y=((double)rand())*100000/((double)RAND_MAX);
            angle=((double)rand())*360/((double)RAND_MAX);
            p1_x=r_x-0.5*l*sin(XI*angle);p1_x=p1_x/a;
            p2_x=r_x+0.5*l*sin(XI*angle);p2_x=p2_x/a;
            p1_y=r_y-0.5*l*cos(XI*angle);p1_y=p1_y/b;
            p2_y=r_y+0.5*l*cos(XI*angle);p2_y=p2_y/b;
            if(ceil(p1_x)!=ceil(p2_x) || ceil(p1_y)!=ceil(p2_y)){
                B++;
            }
        }
        P=((double)B)/((double)N);
        pi[k]=(2.0*l*(a+b)-l*l)/(P*a*b);
        fprintf(fp,"%f\n",pi[k]);
    }
    fclose(fp);
    return 0;
}
