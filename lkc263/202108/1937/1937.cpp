// 이 문제는 dfs로 풀어야 한다.
// 이유는
// 1 4
// 2 3
// 인 경우, bfs로 풀어버리면
// 1을 기준으로 이동할 때
// 1 -> 4 (4 true가 되버리고)
// 1 -> 2 -> 3 -> 4(true가 된 4를 할 수가 없다.)
// 그러므로 dfs를 이용한다.


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>

#define BAMBOOMAX 501

using namespace std;


int n;
int arr[BAMBOOMAX][BAMBOOMAX];
bool visited[BAMBOOMAX][BAMBOOMAX];
int dp[BAMBOOMAX][BAMBOOMAX];

int x_coor[] = {-1,0,1,0};
int y_coor[] = {0,1,0,-1};
int total_depth=1;

// dfs와 dp를 이용한다.
int dfs(int x, int y, int cnt){

    if(visited[x][y]) return dp[x][y];  // 이미 방문한 곳이라면 저장되어 있는 값을 반환한다. (위치한 곳에서 가장 큰 값이 저장되어 있다.)

    visited[x][y] = true;

    for(int i=0;i<4;i++){
        int x_next = x + x_coor[i];
        int y_next = y + y_coor[i];

        if(x_next <= 0 || x_next > n || y_next <= 0 || y_next > n) continue;
        if(arr[x][y] >= arr[x_next][y_next]) continue;   // 현재 방문한 곳 숫자 >= 다음 노드의 숫자 이면 continue

        // 여기서 dp 와 dfs를 사용한다.
        // 현재 연결된 노드(숫자)와 비교를 한다.
        // 제일 길게 연결되어 있는 값이 dp[x][y]에 저장된다.
        dp[x][y] = max(dfs(x_next,y_next,cnt+1)+1,dp[x][y]);

        if(total_depth < dp[x][y]) total_depth = dp[x][y];
    }

    if(dp[x][y]==0) dp[x][y] = 1;   // 현재 위치 노드 숫자가 커서 더 이상 갈 곳이 없어 현재 위치 dp에 1을 저장한다.

    return dp[x][y];        // dp 값을 반환한다.

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> arr[i][j];
        }
    }


    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            // 이미 방문한 곳이라면 continue
            if(visited[i][j]) continue;
            dfs(i,j,1);
        }
    }


    cout << total_depth << "\n";

    return 0;
}
