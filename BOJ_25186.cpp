#include <iostream>
using namespace std;

int main() {
    int types, max=0, k;
    long long sum=0;
    cin >>types;
    for (int i; i<types; ++i) {
        cin >>k;
        sum+=k;
        if (k>max) {
            max=k;
        }
    }

    if (types==max==sum==1) {
        cout <<"Happy";
        return 0;
    }
    
    if (max<=(sum-max)) {/*==if (max<(sum/2)) {  */
        cout <<"Happy";
    }
    else {
        cout <<"Unhappy";
    }

    return 0;
}