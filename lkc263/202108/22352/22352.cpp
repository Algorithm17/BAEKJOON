#include<iostream>
#include<cstdio>
#include<queue>
#include<utility>

using namespace std;


int n, m;
bool visited[31][31];
int cpcu_before[31][31];
int cpcu_after[31][31];
int cnt;
int x_coordinate[4] = {-1,0,1,0};
int y_coordinate[4] = {0,1,0,-1};
int data = 0;

void bfs(int x, int y, int current_data){
    queue<pair<int, int>> q;

    q.push(make_pair(x,y));

    while(!q.empty()){
        int x_t = q.front().first;
        int y_t = q.front().second;

        q.pop();

        if(visited[x_t][y_t]) continue;
        visited[x_t][y_t] = true;

        for(int i=0;i<4;i++){
            int x_around = x_t + x_coordinate[i];
            int y_around = y_t + y_coordinate[i];

            if(x_around <=0 || y_around <=0 || x_around > n || y_around > m) continue;

            else if(cpcu_before[x_around][y_around] != current_data) continue;
            else if(visited[x_around][y_around]) continue;

            q.push(make_pair(x_around,y_around));

        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> cpcu_before[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> cpcu_after[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(cpcu_before[i][j] == cpcu_after[i][j]) continue;   // ��� ���� �� �����Ϳ� ��� ���� �� �����Ͱ� ���� ���� continue
            if(visited[i][j]) continue;   // �湮�� ���̶�� continue
            else if(cpcu_before[i][j] != cpcu_after[i][j]){
                bfs(i,j,cpcu_before[i][j]);
                // ���� ��ġ �����ͷ� bfs�� �����Ͽ� ��� ���� ���� �ش� ��ġ�� ã�´�.

                data = cpcu_after[i][j];
                // ��� ���� ���� �ش� ��ġ �����͸� data�� �����Ѵ�.

                for(int i_idx=1;i_idx<=n;i_idx++){
                    for(int j_idx=1;j_idx<=m;j_idx++){
                        if(!visited[i_idx][j_idx]) continue;

                        // bfs�� �����Ͽ� ��� ���� ���� �ش� ��ġ�� ã�ұ⿡
                        // �� ��ġ�� ��� ���� ���� �ش� ��ġ �����ͷ� �־��ش�.
                        cpcu_before[i_idx][j_idx] = data;
                    }
                }

                // ��� �ִ� ���� ã�ұ⿡ �����Ѵ�.
                break;
            }
        }
        // ��� �ִ� ���� ã�ұ⿡ �����Ѵ�.
        if(data) break;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(cpcu_before[i][j] != cpcu_after[i][j]){
            // ��� �ִ� ���� ã�� ���������� �ٸ� �����Ͱ� ������ �� cnt ������ �߰����ش�.
                cnt++;
            }
        }
    }

    if(!cnt) cout << "YES" << "\n";
    else cout << "NO" << "\n";



    return 0;
}
