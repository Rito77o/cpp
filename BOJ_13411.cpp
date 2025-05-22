#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int n, x, y, v;
    pair<double,int> k;
    vector<pair<double,int>> time; //{시간,순서}}
    cin >>n;
    for (int i=0; i<n; ++i) {
        cin >>x >>y >>v;
        k={pow(x*x+y*y,0.5)/v,i+1};
        time.push_back(k);
        //cout <<k.first <<" " <<k.second <<"\n";
    }
    sort(time.begin(),time.end());
    for (int i=0; i<n; ++i) {
        cout <<time[i].second <<"\n";
    }
    
    return 0;
}