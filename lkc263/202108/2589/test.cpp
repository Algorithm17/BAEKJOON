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
    int cnt;

};

int col,row;
string str;
char arr[51][51];
int visited[51][51];
int x_coor[4] = {-1,0,1,0};
int y_coor[4] = {0,1,0,-1};
int distance_cnt;

void bfs(int x, int y){
    queue<Struct> q;

    q.push({x,y,1});



    while(!q.empty()){
        Struct s = q.front();
        q.pop();

        if(visited[s.x][s.y]) continue;
        visited[s.x][s.y] = true;

        if(distance_cnt < s.cnt) distance_cnt = s.cnt;

        for(int i=0;i<4;i++){
            int x_data = s.x + x_coor[i];
            int y_data = s.y + y_coor[i];

            if(x_data <= 0 || x_data > col || y_data <= 0 || y_data > row) continue;

            if(visited[x_data][y_data]) continue;
            if(arr[x_data][y_data]=='W') continue; // W 이면 이동못함

            q.push({x_data,y_data,s.cnt+1});

        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> col >> row;

    // 전체 초기화 : 처음에는 [0][0]을 써주고, 그 다음 칸에는 [최대 행(값) - 1][최대 열], 다음 칸에는 초기 상태의 값
    // 이 때는, 시작 점 : [0,0] 에서 [MAX-1, MAX-1]일 때
    //fill(&arr[0][0], &arr[MAX - 1][MAX], 7);
    // 이 때는, 시작 점 : [1,1] 에서 [MAX, MAX]일 때
    //fill(&visited[0][0],&visited[col][row+1],30);


    int total_cnt = 0;
    for(int i=1;i<=col;i++){
        for(int j=1;j<=row;j++){
            fill(&visited[1][1],&visited[col][row+1],30);
            cout << visited[i][j] << " ";
        }
        cout << "\n";
    }


    return 0;
}
