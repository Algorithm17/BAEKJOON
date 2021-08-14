#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>


using namespace std;

int n, m;   // n : 도시의 개수, m :버스의 개수
int a, b, c;  // a : 시작 도시, b : 도착 도시, c : 한 번 타는데 필요한 비용
vector<int> vc[101];  // 시작, 도착 도시 vector
int cost[101][101];   // 시작, 도착 도시 가는데 최소 비용
int total[101][101];   // 도시 i에서 j로 가는데 필요한 최소 비용
int current_result;

bool visited[101];


void dfs(int start, int arrive,int cost_data){

    if(start==arrive){
        if(cost_data < current_result) current_result = cost_data;
//        cout << "\ncost data : "  << cost_data << "\n";
        return;
    }

    visited[start] = true;

    for(int i=0;i<vc[start].size();i++){
        int next_data = vc[start][i];
        if(visited[next_data]) continue;

        dfs(next_data,arrive,cost_data + cost[start][next_data]);
    }

    visited[start] = false;

}


int main(){
    ios_base::sync_with_stdio();
    cin.tie();
    cout.tie();


    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> a >> b >> c;

        vc[a].push_back(b);     // 시작, 도착 도시
        if(cost[a][b] > c || cost[a][b] == 0){
            cost[a][b] = c;          // 비용
        }

    }

    for(int i=1;i<=n;i++){      // 도시 개수 : n개
        for(int j=1;j<=n;j++){
            fill(visited,visited+101,false);
            current_result = 999999999;
            dfs(i,j,0);
            if(current_result == 999999999) current_result = 0;
            total[i][j] = current_result;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout << total[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
