#include <stdio.h>
#include <math.h>

#define EARTH_RADIUS 6371// 地球半径（公里）

// 使用Haversine公式计算两个地点之间的距离（直接使用弧度）
// 将角度转换为弧度
double degreesToRadians(double degrees) {
    return degrees * M_PI/ 180.0;
}

/*double calculateHaversineDistance(double lat1, double lon1, double lat2, double lon2) {
    double dlat = lat2 - lat1;
    double dlon = lon2 - lon1;

    double a = sin(dlat/2) * sin(dlat/2) + cos(lat1) * cos(lat2) * sin(dlon/2) * sin(dlon/2);
    double c = 2 * atan2(sqrt(a), sqrt(1-a));

    return EARTH_RADIUS * c;
}*/

int main() {
    double lat1, lon1, lat2, lon2;
    

    scanf("%lf %lf", &lat1, &lon1);
    

    scanf("%lf %lf", &lat2, &lon2);
    double lat=degreesToRadians(lat2-lat1);

    double lon=degreesToRadians(lon2-lon1);
    lat1=degreesToRadians(lat1);
    lat2=degreesToRadians(lat2);

    
    double havlat=sin(lat/2)*sin(lat/2);
    //havlat=round(havlat*10000.0)/10000.0;
    double havlon=sin(lon/2)*sin(lon/2);
    //havlon=round(havlon*10000.0)/10000.0;
    double coslat=cos(lat1)*cos(lat2);
    //coslat=round(coslat*10000.0)/10000.0;
    double havdr=havlat+coslat*havlon;
    //havdr=round(havdr*10000.0)/10000.0;
    double dr=acos(1-2*havdr);
    //dr=round(dr*10000.0)/10000.0;
    double d=dr*EARTH_RADIUS;
    d=round(d*10000.0)/10000.0;
    
   // double distance = calculateHaversineDistance(lat1, lon1, lat2, lon2);
    
    printf("%.4lfkm\n", d);
    
    return 0;
}

/*
34.260958 108.942369
55.755825 37.617298


*/