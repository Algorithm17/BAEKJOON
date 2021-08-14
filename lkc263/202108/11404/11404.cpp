#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>


using namespace std;

int n, m;   // n : ������ ����, m :������ ����
int a, b, c;  // a : ���� ����, b : ���� ����, c : �� �� Ÿ�µ� �ʿ��� ���
vector<int> vc[101];  // ����, ���� ���� vector
int cost[101][101];   // ����, ���� ���� ���µ� �ּ� ���
int total[101][101];   // ���� i���� j�� ���µ� �ʿ��� �ּ� ���
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

        vc[a].push_back(b);     // ����, ���� ����
        if(cost[a][b] > c || cost[a][b] == 0){
            cost[a][b] = c;          // ���
        }

    }

    for(int i=1;i<=n;i++){      // ���� ���� : n��
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
