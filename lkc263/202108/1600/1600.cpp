#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;


struct StructList{
    int x;
    int y;
    int horse_cnt;
    int current_total_count;
};
// 현재 이동한 점에서 x, y좌표와 말이 이동할 수 있는 횟수, 총 이동한 횟수를 이용한다.


int k, w, h;

int horse_coordinate[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
// 말 이동한 공간
int adjacent_coordinate[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
// 인접한 칸 (원숭이가 이동한 공간)

int arr[201][201];
bool visited[201][201][31];
int total = -1;

void bfs(){
    queue<StructList> q;

    q.push({1,1,0,0});

    while(!q.empty()){
        int x_position = q.front().x;
        int y_position = q.front().y;
        int current_horse_cnt = q.front().horse_cnt;
        int current_total = q.front().current_total_count;



        q.pop();

        if(x_position == h && y_position == w){
            total = current_total;
            break;
        }

        if(visited[x_position][y_position][current_horse_cnt]) continue;
        visited[x_position][y_position][current_horse_cnt] = true;


        if(k > current_horse_cnt){
            // 말의 움직임
            for(int i=0;i<8;i++){
                int x_horse = x_position + horse_coordinate[i][0];
                int y_horse = y_position + horse_coordinate[i][1];

                if(x_horse <= 0 || x_horse > h || y_horse <= 0 || y_horse > w) continue;
                else if(visited[x_horse][y_horse][current_horse_cnt]) continue;
                else if(arr[x_horse][y_horse]==1) continue;

                q.push({x_horse,y_horse,current_horse_cnt+1,current_total+1});
            }

            // 원숭이의 움직임(이미 지나간 곳을 검사할 수도 있다.)
            for(int i=0;i<4;i++){
                int x_monkey = x_position + adjacent_coordinate[i][0];
                int y_monkey = y_position + adjacent_coordinate[i][1];

                if(x_monkey <= 0 || x_monkey > h || y_monkey <= 0 || y_monkey > w) continue;
                else if(visited[x_monkey][y_monkey][current_horse_cnt]) continue;
                else if(arr[x_monkey][y_monkey]==1) continue;

                q.push({x_monkey,y_monkey,current_horse_cnt,current_total+1});
            }
        }else{
            // 원숭이 움직임, 인접한 칸 이동 (말이 k번 움직였을 때)
            for(int i=0;i<4;i++){
                int x_monkey = x_position + adjacent_coordinate[i][0];
                int y_monkey = y_position + adjacent_coordinate[i][1];

                if(x_monkey <= 0 || x_monkey > h || y_monkey <= 0 || y_monkey > w) continue;
                else if(visited[x_monkey][y_monkey][current_horse_cnt]) continue;
                else if(arr[x_monkey][y_monkey]==1) continue;


                q.push({x_monkey,y_monkey,current_horse_cnt,current_total+1});
            }
        }


    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;

    cin >> w >> h;

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> arr[i][j];
        }
    }

    bfs();

    cout << total << "\n";
    return 0;
}

