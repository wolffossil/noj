#include <bits/stdc++.h>

using namespace std;

int check(string str){
    int i,result;

    for(result=str[1],i=2;str[i]!='*';i++)
    {
        result^=str[i];
    }
    return result;
}

int convert(string str){
    int res=0;
    res=stoi(str,0,16);
    //cout<<res<<endl;
    return res;
}


void print_BeingTime(string utcTime){
    int  hour=stoi(utcTime.substr(0,2));
    int  B_hour=(hour+8)%24;
    cout<<B_hour<<":"<<utcTime.substr(2,2)<<":"<<utcTime.substr(4,2)<<endl; 
}

int main(){
    string str;
    while(cin>>str){
        if(str=="END") break;
        if(str.compare(0,6,"$GPRMC")==0){
            size_t asteriskPos = str.find('*');
            if(asteriskPos!=string::npos){
                int checksum=check(str);
                
                int senchecksum=convert(str.substr(asteriskPos + 1, 2));
                if(checksum!=senchecksum) cout<<"error"<<endl;
                else{
                    // 提取UTC时间字段
                    string utcTime = str.substr(7, 6);
                    //cout<<utcTime<<endl;
                    print_BeingTime(utcTime);
                }
            }
        }

    }
}

/*
$GPRMC,024813.640,A,3158.4608,N,11848.3737,E,10.05,324.27,150706,,,A*50
$GPGSV,3,1,11,10,63,137,17,07,61,098,15,05,59,290,20,08,54,157,30*70
$GPRMC,194548.127,A,5230.657,N,01325.713,E,3968.7,122.8,200220,000.0,W*44
$GPGGA,092750.000,5321.6802,N,00630.3372,w,1,8,1.03,61.7,M,55.2,M,,*76
$GPRMC,111724.681,A,5231.801,N,01329.267,E,1289.3,000.0,291123,000.0,W*48
$GNVTG,112.99,T,109.99,M,0.15,N,0.08,K,A*3B
END
*/