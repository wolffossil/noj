#include <bits/stdc++.h>

using namespace std;

int str_endswith(string str,string suffix){
    if(str.length()<suffix.length()) return 0;
    int len=str.length()-suffix.length();
    str.erase(0,len);
    if(str==suffix)
        return 1;

    return 0;

}


int main(){
    string str,suffix;
    getline(cin, str);
    getline(cin, suffix);
    if(str_endswith(str, suffix))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    

}

/*
hello world!
world!
*/