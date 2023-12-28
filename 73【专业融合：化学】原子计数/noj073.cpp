#include <bits/stdc++.h>

using namespace std;

struct Atom {
    string name;
    int count;
};

void resolve(string str,unordered_map<string,int>& atoms){
    int i=0;
    
    while(i<str.length()){
        string atom_e="";
        //检查首字母是否大写
        if(isupper(str[i])){
            atom_e+=str[i++];
        }
        //检查小写字母
        while(i<str.length()&&islower(str[i])){
            atom_e+=str[i++];

        }
        //读取元素数量
        int count=0;
        while(i<str.length()&&isdigit(str[i])){
            count =count*10+(str[i++]-'0');
        }
        if(!count){
            count=1;
        } 
        atoms[atom_e]+=count;  
    }
}


int main() {
    string str;
    cin>>str;
    unordered_map<string ,int> atoms;
    resolve(str,atoms);

    vector<Atom> elements;
    for (const auto& entry : atoms) {
        elements.push_back({entry.first, entry.second});
    }
    sort(elements.begin(), elements.end(), [](const Atom& a, const Atom& b) {
        return a.name < b.name;
    });

    for (const auto& element : elements) {
        cout << element.name << " " << element.count << endl;
    }


    
}
/*
Fe2H3OH
*/