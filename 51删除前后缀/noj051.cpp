#include <bits/stdc++.h>

using namespace std;



void str_removeprefix(string str,string words){
    while(str.compare(0,words.length(),words)==0&&str.length()>=words.length()){
        str.erase(0,words.length());
    } 
    cout << str << endl;   

}

void str_removesuffix(string str,string words){
    while(str.compare(str.length()-words.length(),words.length(),words)==0&&str.length()>=words.length()){
        str.erase(str.length()-words.length());
    }
    cout << str << endl;
}

int main(){
    string str,words;
    getline(cin,str);
    getline(cin,words);
    str_removeprefix(str,words);
    str_removesuffix(str,words);

}

/*
antiantianwartiantianti
anti
*/