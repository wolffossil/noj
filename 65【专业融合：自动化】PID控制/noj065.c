#include <stdio.h>

typedef struct PIDController{
    double Kp,Ki,Kd;//比例、积分、微分系数
    double preError,integral;//前次误差、积分
}PIDData;//PID数据类型

void PIDInit(PIDData *pid) {
    pid->Kp = 0;
    pid->Ki = 0;
    pid->Kd = 0;
    pid->preError = 0;
    pid->integral = 0;
}

double PIDCalculate(PIDData *pid,double setpoint,double measuredValue){
    double error=setpoint-measuredValue;
    pid->integral+=error;
    double diff=error-pid->preError;
    pid->preError=error;
    double output=pid->Kp*error+pid->Ki*pid->integral+pid->Kd*diff;
    return output;

}

int main(){
    double setpoint,measuredValue;
    PIDData pid;
    int n;
    PIDInit(&pid);
    scanf("%lf %lf %lf",&pid.Kp,&pid.Ki,&pid.Kd);
    scanf("%lf %lf",&setpoint,&measuredValue);
    scanf("%d",&n);
    for(int i=1; i<=n;i++){
        double output=PIDCalculate(&pid,setpoint,measuredValue);
        printf("%d %.6lf\n",i,measuredValue);
        measuredValue+=output;
    }


}

/*
0.1 0.01 0.05
100 0
100
*/