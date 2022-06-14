#include <stdio.h>

int main(){
    int C,L;
    int t1,t2;

    (void)scanf("%d%d",&L,&C);
    t1=L*C+(L-1)*(C-1);
    t2=2*(L-1)+2*(C-1);

    if(C==0 || L==0){
        printf("0\n0\n");
    }else{
        printf("%d\n%d\n",t1,t2);
    }


    return 0;
}