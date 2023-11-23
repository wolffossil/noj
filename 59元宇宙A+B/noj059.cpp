#include <bits/stdc++.h>

using namespace std;


int convert_char_to_int(char ch){
    if(ch>='0'&&ch<='9')
        return ch-'0';
    else if(ch>='A'&&ch<='Z')
        return ch-'A'+10;

}

char convert_int_to_char(int num){
    if(num>=0&&num<=9){
        return num+'0';
    }
    else if(num>=10&&num<=36){
        return num+'A'-10;
    }
}

string add(string a,string b){
    long long  num1=0,num2=0;
    for(int i=0;i<a.length();i++){
        num1=num1*36+convert_char_to_int(a[i]);
    }  
    for(int i=0;i<b.length();i++){
        num2=num2*36+convert_char_to_int(b[i]);
    }
    long long  res=num1+num2;
    string str="";
    if(res==0){
        return "0";
    }
    while(res>0){
        str+=convert_int_to_char(res%36);
        res=res/36;
    } 
    return str;
    
}

int main(){
    string a,b;
    cin>>a>>b;
    string str=add(a,b);
    for(int i=str.length()-1;i>=0;i--){
        cout<<str[i];
    }
    cout<<endl;
}