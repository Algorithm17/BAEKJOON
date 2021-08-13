// �� ������ dfs�� Ǯ��� �Ѵ�.
// ������
// 1 4
// 2 3
// �� ���, bfs�� Ǯ�������
// 1�� �������� �̵��� ��
// 1 -> 4 (4 true�� �ǹ�����)
// 1 -> 2 -> 3 -> 4(true�� �� 4�� �� ���� ����.)
// �׷��Ƿ� dfs�� �̿��Ѵ�.


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

// dfs�� dp�� �̿��Ѵ�.
int dfs(int x, int y, int cnt){

    if(visited[x][y]) return dp[x][y];  // �̹� �湮�� ���̶�� ����Ǿ� �ִ� ���� ��ȯ�Ѵ�. (��ġ�� ������ ���� ū ���� ����Ǿ� �ִ�.)

    visited[x][y] = true;

    for(int i=0;i<4;i++){
        int x_next = x + x_coor[i];
        int y_next = y + y_coor[i];

        if(x_next <= 0 || x_next > n || y_next <= 0 || y_next > n) continue;
        if(arr[x][y] >= arr[x_next][y_next]) continue;   // ���� �湮�� �� ���� >= ���� ����� ���� �̸� continue

        // ���⼭ dp �� dfs�� ����Ѵ�.
        // ���� ����� ���(����)�� �񱳸� �Ѵ�.
        // ���� ��� ����Ǿ� �ִ� ���� dp[x][y]�� ����ȴ�.
        dp[x][y] = max(dfs(x_next,y_next,cnt+1)+1,dp[x][y]);

        if(total_depth < dp[x][y]) total_depth = dp[x][y];
    }

    if(dp[x][y]==0) dp[x][y] = 1;   // ���� ��ġ ��� ���ڰ� Ŀ�� �� �̻� �� ���� ���� ���� ��ġ dp�� 1�� �����Ѵ�.

    return dp[x][y];        // dp ���� ��ȯ�Ѵ�.

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
            // �̹� �湮�� ���̶�� continue
            if(visited[i][j]) continue;
            dfs(i,j,1);
        }
    }


    cout << total_depth << "\n";

    return 0;
}
