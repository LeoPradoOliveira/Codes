#include <stdio.h>

int main(){
    int b=0;
    int N,D,A;
    //n=posições,d=disco voador,a=avião

    scanf("%d%d%d",&N,&D,&A);

    while(A!=D){
        if(A==N){
            A = 1;
            b++;
        }
        else{
            A++;
            b++;
        }
    }


    printf("%d\n",b);


    return 0;
}