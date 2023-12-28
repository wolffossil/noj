#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct tagStudent{
    char id[11];//学号
    char name[31];//姓名
    int score;//成绩
};

int compare(const void *a,const void *b){
    int diff=((struct tagStudent*)b)->score - ((struct tagStudent*)a)->score;

    if(diff==0){
        return strcmp(((struct tagStudent *)a)->id, ((struct tagStudent *)b)->id);
    }

    return diff;
}

int main(){
    int n;
    scanf("%d",&n);
    struct tagStudent students[n];
    for(int i=0;i<n;i++){
        scanf("%s %s %d", students[i].id, students[i].name, &students[i].score);
    }
    qsort(students,n,sizeof(struct tagStudent),compare);
    for(int i=0;i<n;i++){
        printf("%s %s %d\n", students[i].id, students[i].name, students[i].score);
    }
}

/*
6
2001900001 Jerry 88
2001900005 Tom 92
2001900006 Mi1la 85
2001900002 Alice 80
2001900003 Mickey 85
2001900004 Aladdin 83

*/