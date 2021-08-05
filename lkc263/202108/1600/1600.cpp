#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;


struct StructList{
    int x, y;
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
bool visited[201][201][101];
int total;

void bfs(){
    queue<StructList> q;

    q.push({0,0,0,0});

    while(!q.empty()){
        int x_position = q.front().x;
        int y_position = q.front().y;
        int current_horse_cnt = q.front().horse_cnt;
        int current_total = q.front().current_total_count;

        q.pop();

        if(x_position == w && y_position == h){
            total = current_total;
            return;
        }
        if(visited[start_x][start_y][current_horse_cnt]) continue;
        visited[start_x][start_y][current_horse_cnt] = true;

        int number_of_repetitions = 0;


        if(k > 0){
            // 말의 움직임
            for(int i=0;i<8;i++){
                int x_horse = start_x + horse_coordinate[i][0];
                int y_horse = start_y + horse_coordinate[i][1];

                if(x_horse < 0 || x_horse > w || y_horse < 0 || y_horse > h) continue;
                else if(visited[x_horse][y_horse]) continue;
                else if(arr[x_horse][y_horse]==1) continue;

                number_of_repetitions++;

                pq.push({-index_data-1,{x_horse,y_horse}});

            }
            k--;
        }

        if(number_of_repetitions == 0){
            // 원숭이 움직임
            for(int i=0;i<4;i++){
                int x_monkey = start_x + adjacent_coordinate[i][0];
                int y_monkey = start_y + adjacent_coordinate[i][1];

                if(x_monkey < 0 || x_monkey > w || y_monkey < 0 || y_monkey > h) continue;
                else if(visited[x_monkey][y_monkey]) continue;
                else if(arr[x_monkey][y_monkey]==1) continue;

                number_of_repetitions++;

                pq.push({-index_data-1,{x_monkey,y_monkey}});
            }

        }


        if(number_of_repetitions==0){
            total_count = -1;
            return;
        }

        number_of_repetitions = 0;

        bfs_count++;


    }



}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;

    cin >> w >> h;

    for(int i=1;i<=w;i++){
        for(int j=1;j<=h;j++){
            cin >> arr[i][j];
        }
    }

    bfs();

    cout << total_count << "\n";
    return 0;
}
