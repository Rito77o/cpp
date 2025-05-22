#include <iostream>
#include <vector>
using namespace std;

int main() {
    int time;
    cin >>time;

    bool flag=false;
    string word, highlighted_word;
    char now, next;
    for (int i=0; i<time; ++i) {
        highlighted_word.clear();
        cin >>word;
        for (int j=0; j<word.size()-1; ++j) {
            now=word[j];
            next=word[j+1];
            highlighted_word.push_back(now);
            if (now<next) highlighted_word.push_back(now);

            
            else if (now==next) {
                for (int k=j; (k<word.size()) && not(now>word[k]) && (not flag); ++k){
                    if (now<word[k]) {
                        highlighted_word.push_back(now);
                        flag=true;
                    }
                }
                flag=false;
            }
            

        }
        highlighted_word.push_back(word.back());

        cout <<"Case #" <<i+1 <<": ";
        for (int j=0; j<highlighted_word.size(); ++j) {
            cout <<highlighted_word[j];
        }
        cout <<"\n";
    }

    return 0;
}
