#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long len, k, biggestest;
    cin >>len;
    vector<long> input;
    for (int i=0; i<len; ++i) {
        cin >>k;
        input.push_back(k);
    }

    biggestest=*max_element(input.begin(),input.end());

    vector<long> biggest = input;
    for (int i=1; i<len; ++i) {
        for (int j=0; j<i; ++j) {
            if (input[j]>input[i]) {
                k=input[i]+biggest[j];
                if (k>biggest[i]) {
                    biggest[i]=k;
                    if (k>biggestest) {
                        biggestest=k;
                    }
                }
            }
        }
    }

    cout <<biggestest;

    return 0;
}