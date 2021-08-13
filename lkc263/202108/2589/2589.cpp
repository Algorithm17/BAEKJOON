#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>
#include<string>

using namespace std;


struct Struct{
    int x;
    int y;
    int cnt;        // 회수

};

int col,row;
string str;
char arr[51][51];
bool visited[51][51];
int x_coor[4] = {-1,0,1,0};   // 상하좌우
int y_coor[4] = {0,1,0,-1};   // 상하좌우
int distance_cnt;             // 개수

void bfs(int x, int y){
    queue<Struct> q;

    q.push({x,y,0});



    while(!q.empty()){
        Struct s = q.front();
        q.pop();

        if(visited[s.x][s.y]) continue;
        visited[s.x][s.y] = true;

        if(distance_cnt < s.cnt) distance_cnt = s.cnt;

        for(int i=0;i<4;i++){
            int x_data = s.x + x_coor[i];  // 상하좌우 x, y 좌표
            int y_data = s.y + y_coor[i];

            if(x_data <= 0 || x_data > col || y_data <= 0 || y_data > row) continue;

            // 방문한 곳이라면 continue
            if(visited[x_data][y_data]) continue;
            if(arr[x_data][y_data]=='W') continue; // W 이면 이동하지 못한다.

            q.push({x_data,y_data,s.cnt+1});        // queue에 넣을 때, 다음 육지(L)이므로 횟수 + 1

        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> col >> row;

    for(int i=1;i<=col;i++){
        cin >> str;
        for(int j=1;j<=row;j++){
            arr[i][j] = str[j-1];
        }
    }

    int total_cnt = 0;
    for(int i=1;i<=col;i++){
        for(int j=1;j<=row;j++){
            if(arr[i][j]=='L'){
                // 이차 배열 초기화 [1][1]에서 [col][row] 까지
                fill(&visited[1][1],&visited[col][row+1],false);
                distance_cnt = 0;
                bfs(i,j);

                // 이동거리 최대 값 < 현재 나온 이동 거리
                // 이동거리 최대 값 = 현재 나온 이동 거리
                if(distance_cnt > total_cnt) total_cnt = distance_cnt;

            }
        }
    }

    cout << total_cnt << "\n";



    return 0;
}
