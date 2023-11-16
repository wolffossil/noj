#include <bits/stdc++.h>

using namespace std;

void str_slice(string src,int start,int stop,int step){
    string res="";
    if(start<0)
        start=src.length()+start;
    if(stop<0)
        stop=src.length()+stop;

    if(stop>=start)
        for (int i = start; i < stop; i += step) {
            res += src[i];
        }
    else
        for (int i = start; i > stop; i += step) {
            res += src[i];
        }
    cout<<res<<endl;

}



int main() {
    string src;
    cin >> src;

    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;

        int start, stop, step;
        if (n == 3) {
            cin >> start >> stop >> step;
        } else if (n == 2) {
            cin >> start >> stop;
            step = 1;
        } else if (n == 1) {
            cin >> start;
            stop = src.length();
            step = 1;
        }

        str_slice(src, start, stop, step);

    }

    return 0;
}

/*
ABCDEFGHI
8
2 2 7
2 -7 -2
2 2 -5
3 2 7 2
3 6 1 -2
2 0 3
1 6
3 -1 -10 -1
*/