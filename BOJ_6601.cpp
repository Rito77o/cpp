#include <iostream>
#include <vector>
using namespace std;


bool flag=false; //플래그변수
pair<int,int> goal;
vector<vector<int>> board(8,vector<int>(8,0));
//찾을 때까지 시작에서 [i][j]로 몇번걸리는지 기록


bool check(int x, int y, int time) {
    if (x >= 0 && x < 8 && y >= 0 && y < 8) {
        if (board[x][y]==0) {
            board[x][y]=time;
            return true;
        }
    }
    return false;
}


//find로 좌표들(0~8개) 오면 각각의 좌표들에서 가능한 8점을 check로 전달.
//check에서 true인 좌표들 중에 정점이 있다면 cout하고 break.
    //아니지 정점이었다면 check안해도 됐겠지. 정점확인은 check전에 하자.
//아니면 next_find에 저장.
//모든 좌표를 확인했으면 next_find를 find에 전달.
int find(vector<pair<int,int>> coordinates, int time) {
    vector<pair<int,int>> will_find{}; //너비우선탐색

    for (int i=0; i<coordinates.size(); ++i) {

        //확인차
        //cout <<coordinates[i].first <<" " <<coordinates[i].second <<"\n";

        if (coordinates[i]==goal) {
            cout <<time <<" knight moves.\n";
            flag=true;
            return 0;
        }
        int x=coordinates[i].first, y=coordinates[i].second;
        

        if (check(x-1,y-2,time)) will_find.push_back({x-1,y-2}); //1
        if (check(x-2,y-1,time)) will_find.push_back({x-2,y-1}); //2
        if (check(x-2,y+1,time)) will_find.push_back({x-2,y+1}); //3
        if (check(x-1,y+2,time)) will_find.push_back({x-1,y+2}); //4
        if (check(x+1,y-2,time)) will_find.push_back({x+1,y-2}); //5
        if (check(x+2,y-1,time)) will_find.push_back({x+2,y-1}); //6
        if (check(x+2,y+1,time)) will_find.push_back({x+2,y+1}); //7
        if (check(x+1,y+2,time)) will_find.push_back({x+1,y+2}); //8
    }


    find(will_find,time+1);
    if (flag) return 0;

    //차피 실행 안됨
    cout <<"\n error\n";
    return 0;
}


int main() {
    pair<int,int> start;
    string input; // [시작x, 시작y, (공백), 끝x, 끝y] <str>

    while (getline(cin, input)) {
        flag=false;
        cout <<"To get from " <<input[0] <<input[1] <<" to ";
        cout <<input[3] <<input[4] <<" takes ";

        //얘(start)는 find로 전송
        start.first = (int)input[0] - 97;
        start.second = (int)input[1] - 49;
        //얘(goal)는 global로 해서 find함수에서 계속 확인
        goal.first = (int)input[3] - 97;
        goal.second = (int)input[4] - 49;

        find(vector<pair<int,int>> {start}, 0);

        //board 초기화
        //board=(8,vector<int>(8,0));
        board = vector<vector<int>>(8, vector<int>(8, 0));
    }

    return 0;
}