#include <bits/stdc++.h>

using namespace std;

int main(){
    string s;
    int x;
    cin>>s;
    cin>>x;
    int alphabet[26]={0};
    for(int i=0;i<s.length();i++){
        alphabet[s[i]-'a']++;
    }
    for(int i=0;i<s.length();i++){
        char tmp;
        if(alphabet[s[i]-'a']%2){
            tmp=((int)(s[i]-x-'a')%26+26)%26+'a';
        }
        else{
            tmp=((int)(s[i]+x-'a')%26+26)%26+'a';
        }
        s[i]=tmp;

    }
    cout<<s<<endl;


}