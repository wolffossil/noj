#include <bits/stdc++.h>
using namespace std;
// 从str左边删除chars里的每个字符
void str_lstrip(string& str, string& chars) {
    int pos = str.find_first_not_of(chars);
    if (pos != string::npos) {
        str.erase(0, pos);
    }
    
}

// 从str右边删除chars里的每个字符
void str_rstrip(string& str, string& chars) {
    int pos = str.find_last_not_of(chars);
    if (pos != string::npos) {
        str.erase(pos + 1);
    } 
}

// 从str两边删除chars里的每个字符
void str_strip(string& str, string& chars) {
    str_lstrip(str, chars);
    str_rstrip(str, chars);
}

int main() {
    string str;
    string chars;
    string tmp;
    getline(cin, str);
    tmp=str;
    getline(cin, chars);
    
    str_lstrip(str, chars);
    cout << str << endl;
    str=tmp;

    str_rstrip(str, chars);
    cout << str << endl;
    str=tmp;
    
    str_strip(str, chars);
    cout << str << endl;

    
    return 0;
}

/*
www.example.com
cmowz.
*/