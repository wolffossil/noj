#include <bits/stdc++.h>

using namespace std;

void str_swapcase(string &str){
    for(int i=0; i<str.length();i++){
        if(str[i]>='A'&&str[i]<='Z'){
            str[i]+='a'-'A';
        }
        else if(str[i]>='a'&&str[i]<='z'){
            str[i]-='a'-'A';
        }
    }
}

int main(){
    string str;
    getline(cin, str);
    str_swapcase(str);
    cout << str <<endl;
}

/*
Hello world
*/