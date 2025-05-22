#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
    map<char,char> dic;
    dic['.']='.'; dic['O']='O'; dic['-']='|';
    dic['|']='-'; dic['/']='\\'; dic['\\']='/';
    dic['^']='<'; dic['<']='v'; dic['v']='>';
    dic['>']='^';

    int N, M;
    cin >>N >>M;
    cin.ignore();

    string line;
    vector<vector<char>> input;
    for (int i=0; i<N; ++i) {
        getline(cin,line);
        vector<char> k(line.begin(),line.end());
        input.push_back(k);
    }

    char kk;
    for (int i=0; i<M; ++i) {
        for (int j=0; j<N; ++j) {
            kk=input[j][M-1-i];
            cout <<dic[kk];
        }    
        cout <<"\n";
    }

    return 0;
}