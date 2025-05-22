#include <iostream>
using namespace std;

int main() {
    int in, out, present=0, max=0;
    for (int i; i<4; ++i) {
        cin >>out >>in;
        present-=out; present+=in;
        if (present>max) max=present;
    }

    cout <<max;

    return 0;
}