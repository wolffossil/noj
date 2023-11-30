#include <stdio.h>



void print_dna1(){
    printf("   AT   \n");
    printf("  T--A  \n");
    printf(" A----T \n");
    printf("T------A\n");
    printf("T------A\n");
    printf(" G----C \n");
    printf("  T--A  \n");
    printf("   GC   \n");
}

void print_dna2(){
    printf("   CG   \n");
    printf("  C--G  \n");
    printf(" A----T \n");
    printf("A------T\n");
    printf("T------A\n");
    printf(" A----T \n");
    printf("  A--T  \n");
    printf("   GC   \n");
}

void print_dna3(){
    printf("   AT   \n");
    printf("  C--G  \n");
    printf(" T----A \n");
    printf("C------G\n");
    printf("C------G\n");
    printf(" T----A \n");
    printf("  G--C  \n");
    printf("   AT   \n");
}



int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n/2;i++){
        if(i%3==1) print_dna1();
        else if(i%3==2) print_dna2();
        else if(i%3==0) print_dna3();
    }
    return 0;

}