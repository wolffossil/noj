#include <bits/stdc++.h>

using namespace std;

map<string, int> numberMap = {
    {"zero", 0}, {"one", 1}, {"two", 2}, {"three", 3}, {"four", 4},
    {"five", 5}, {"six", 6}, {"seven", 7}, {"eight", 8}, {"nine", 9},
    {"ten", 10}, {"eleven", 11}, {"twelve", 12}, {"thirteen", 13},
    {"fourteen", 14}, {"fifteen", 15}, {"sixteen", 16}, {"seventeen", 17},
    {"eighteen", 18}, {"nineteen", 19}, {"twenty", 20}, {"thirty", 30},
    {"forty", 40}, {"fifty", 50}, {"sixty", 60}, {"seventy", 70},
    {"eighty", 80}, {"ninety", 90}
};

map<int,string> enmap={
    {0,"zero"},{1,"one"},{2,"two"},{3,"three"},
    {4,"four"},{5,"five"},{6,"six"},{7,"seven"},
    {8,"eight"},{9,"nine"},{10,"ten"},{11,"eleven"},
    {12,"twelve"},{13,"thirteen"},{14,"fourteen"},{15,"fifteen"},
    {16,"sixteen"},{17,"seventeen"},{18,"eighteen"},{19,"nineteen"},
    {20,"twenty"},{30,"thirty"},{40,"forty"},{50,"fifty"},{60,"sixty"},
    {70,"seventy"},{80,"eighty"},{90,"ninety"}
};

int convert(string a){
    int num;
    int pos=a.find('-');
    if(pos!=-1){
        string x=a.substr(0,pos);
        string y=a.substr(pos+1);
        num=numberMap[x]+numberMap[y];
    }
    else{
        num=numberMap[a];
    }
    return num;
}

void convert_E(int a){
    //cout<<"a:"<<a<<endl;
    int x=a/10;
    int y=a%10;
    //cout<<x<<" "<<y<<endl;
    if(x>1&&y)
        cout<<enmap[x*10]<<"-"<<enmap[y]<<endl;
    else if(x>=1)
        cout<<enmap[a]<<endl;
    else
        cout<<enmap[y]<<endl;
}

int main(){
    string a,b;
    int num_a,num_b;
    cin>>a>>b;
    num_a=convert(a);
    num_b=convert(b);
    int res=num_a+num_b;
    convert_E(res);
    
    
}

/*
twenty-seven fifty-four
*/