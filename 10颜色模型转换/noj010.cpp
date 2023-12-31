#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;
void RGBtoHSV(float& fR, float& fG, float fB, float& fH, float& fS, float& fV) {
  float fCMax = max(max(fR, fG), fB);
  float fCMin = min(min(fR, fG), fB);
  float fDelta = fCMax - fCMin;
  
  if(fDelta > 0) {
    if(fCMax == fR) {
      fH = 60 * (fmod(((fG - fB) / fDelta), 6));
    } else if(fCMax == fG) {
      fH = 60 * (((fB - fR) / fDelta) + 2);
    } else if(fCMax == fB) {
      fH = 60 * (((fR - fG) / fDelta) + 4);
    }
    
    if(fCMax > 0) {
      fS = fDelta / fCMax;
    } else {
      fS = 0;
    }
    
    fV = fCMax;
  } else {
    fH = 0;
    fS = 0;
    fV = fCMax;
  }
  
  if(fH < 0) {
    fH = 360 + fH;
  }
}


int main(){
     float fH,fS,fV,fR,fG,fB;
     scanf("%f %f %f", &fR, &fG, &fB);
     RGBtoHSV(fR, fG, fB, fH, fS, fV);
     fS=fS*100;
     fV=fV*100/255;
     //fV=fV*100;
     fS=round(fS*10000.0)/10000.0;
     fV=round(fV*10000.0)/10000.0;
     fH=round(fH*10000.0)/10000.0;
     printf("%.4f,%.4f%%,%.4f%%",fH,fS,fV);
}