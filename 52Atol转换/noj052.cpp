#include <bits/stdc++.h>

using namespace std;

int Atol(string str){
    long long res=0;
    int len = str.length();
    int sign = 1;
    int i=0;

    while(str[i]==' '){
        i++;
    }


    if(str[i]=='+'){
        sign=1;
        i++;
    }
    else if(str[i]=='-'){
        sign=-1;
        i++;
    }


    while(str[i]>='0' && str[i]<='9'){
        res=res*10+(str[i]-'0');
        if(res*sign>INT_MAX) return INT_MAX;
        if(res*sign<INT_MIN) return INT_MIN;
        i++;
    }

    return res*sign;


}

int main(){
    string str;
    getline(cin,str);
    cout<<Atol(str)<<endl;

}

/*
-123x+123
*/