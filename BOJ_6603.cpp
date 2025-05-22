#include <iostream>
#include <vector>
#include <set>
using namespace std;


int k;
vector<int> S;


void alpha(vector<int> list, set<int> set, int depth){
    if (depth==6) {
        for (int u=0; u<6; ++u) {
            cout <<list[u] <<" ";
        }
        cout <<"\n";
        return;
    }
    else {
        for (int t=0; t<(k); ++t) {
            if (set.find(t) == set.end()) {
                list.push_back(S[t]);
                set.insert(t);
                alpha(list,set,depth+1);
                list.pop_back();
                set.erase(t);
            }
        }

    }   
    
}


int main() {
    int b;
    cin >>k;
    while (int(k)!=0){
        S.clear();

        for (int i=0; i<k; ++i) {
            cin >>b;
            S.push_back(b);
        }
        //cout <<"\n";

        set<int> set;
        set.insert(0);
        alpha({S[0]}, set ,1);

        cin >>k;
    }

    return 0;
}