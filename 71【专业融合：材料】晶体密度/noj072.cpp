#include <bits/stdc++.h>
#include <cmath>
#include <math.h>


using namespace std;

struct Atom{
    string name;
    double mass;
    double APF;//原子堆积因子
    double r;//原子半径 
};

Atom elemList[] =
{
    { "Po",   208.998, 0.52360, 1.68 },
    { "Li",     6.941, 0.68017, 1.52 },
    { "Na", 22.989770, 0.68017, 1.86 },
    { "Cr",   51.9961, 0.68017, 1.28 },
    { "Mn", 54.938049, 0.68017, 1.27 },
    { "Fe",    55.845, 0.68017, 1.26 },
    { "Mo",     95.94, 0.68017, 1.39 },
    { "Ta",  180.9749, 0.68017, 1.46 },
    { "Al", 26.981538, 0.74048, 1.43 },
    { "Ca",    40.078, 0.74048, 1.97 },
    { "Ni",   58.6934, 0.74048, 1.24 },
    { "Cu",    63.546, 0.74048, 1.28 },
    { "Ge",     72.64, 0.74048, 1.22 },
    { "Ag",  107.8682, 0.74048, 1.44 },
    { "Pt",   195.078, 0.74048, 1.39 },
    { "Au", 196.96655, 0.74048, 1.44 },
    { "Pb",     207.2, 0.74048, 1.75 }
};

int main(){
    int n;
    cin>>n;
    string atoms;
    for(int i=0; i<n; i++){
        cin >> atoms;
        for(int j=0;j<17;j++){
            if(elemList[j].name==atoms){
                double V=4.0/3.0*M_PI*pow(elemList[j].r,3);
                double density=10.0*elemList[j].mass*elemList[j].APF/6.022/V;
                printf("%.2lf\n",density);
                break;
            }
        }
    }

}

/*
3
Po
Mo
Cu
*/