#include <stdio.h>
#include <math.h>


int solve(double temperature,double pressure,int elevation,int runway,int weight,int Flaps,int Wet){
    if(Flaps!=1&&Flaps!=5&&Flaps!=15) return 0;
    if(weight<41413||weight>65000) return 0;
    if(runway<=6900) return 0;

    //floor函数用于向下取整，ceil用于向上取整，返回值均为double
    int temp,pre;
    temp=(int)floor(temperature/10);
    pressure=(elevation+1000*(29.92-pressure))/1000;
    pre=(int)ceil(pressure);

    //查操纵表，转换为数组,第一行无意义,其中有一些因为图像问题需要调整，但暂不知如何调整
    char table[8][10]={
        'X','X','X','X','X','X','X','X','X','X',
        'A','A','A','A','A','A','B','B','B','C',
        'A','A','A','A','A','A','B','B','B','C',
        'A','A','A','A','A','B','B','B','C','D',
        'B','B','B','B','B','C','C','D','D','D',
        'C','C','C','C','C','D','D','D','E','E',
        'D','D','D','D','E','E','E','X','X','X',
        'E','E','E','X','X','X','X','X','X','X'
    };
    char reference = table[temp][pre];
    if(reference=='X') return 0;


}

int main(){
    double temperature,pressure;
    int elevation,runway,weight,Flaps,Wet;
    scanf("%lf %lf %d %d %d %d %d %d",&temperature,&pressure,&elevation,&runway,&weight,&Flaps,&Wet);

    

}

