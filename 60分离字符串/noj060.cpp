#include <bits/stdc++.h>

using namespace std;



void str_split(string str,string sep){
    while(1){
        int pos=str.find(sep);
        if(pos==-1){
            cout<<str<<endl;
            break;
        }
        else{
            cout<<str.substr(0,pos)<<endl;
            str=str.substr(pos+sep.length());
        }
    }
}

int main(){
    string str,sep;
    getline(cin,str);
    getline(cin,sep);
    str_split(str,sep);

}