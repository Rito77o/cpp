#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers(10000,0);
    vector<int> num;
    int sum;

    //10000이하의 모든 수 i에 대해 d(i)를 구함.
    for (int i=1; i<10001; ++i) {
        sum=i;  //sum 초기화 및 i 추가(자기도 더해야함).
        
        //i의 각 자릿수 더함.
        int k=i;
        while (k>0) {
            sum+=k%10;
            k/=10;
        }

        if (sum<10001) {
            numbers[sum]=1;
        }
    }

    for (int i=1; i<10000; ++i) {
        if (not numbers[i]) cout <<i <<"\n";
    }

    return 0;
}