#include <stdio.h>

int main() {
    //火箭初始质量、火箭自身干质量、燃烧时间、有效排气速度cE、重力
    double initialMass, dryMass, burnTime, exhaustVelocity, gravity;
   
    scanf("%lf %lf %lf %lf %lf", &initialMass, &dryMass, &burnTime, &exhaustVelocity, &gravity);

    // 推进剂质量
    double propellantMass = initialMass - dryMass;

    double time = 0.0;
    double altitude = 0.0;
    double velocity = 0.0;

    // 时间步长
    double timestep = 0.1;
    double Mass_Flow=propellantMass/burnTime;

    while (time <= burnTime) {

        double thrust = Mass_Flow * exhaustVelocity;

        // 加速度
        //double acceleration = (thrust / (dryMass + propellantMass)) ;
        
        //题目要求-g,但样例过不了
        double acceleration = (thrust / (dryMass + propellantMass))-gravity;
        
       

        // 速度增量
        double velocityIncrement = acceleration * timestep;
        velocity += velocityIncrement;

        // 海拔高度增量
        double altitudeIncrement = velocity * timestep;


        altitude += altitudeIncrement;

        propellantMass -= Mass_Flow* timestep;


        time += timestep;
    }


    printf("%.3lf km\n", altitude/1000);

    return 0;
}
/*
100000 10000 100 4000 9.81
*/