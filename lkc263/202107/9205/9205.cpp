#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<queue>
#include<cstring>

#define MAXLEN 103

using namespace std;

int t, n, x, y;

int convenience_store_x[MAXLEN];
int convenience_store_y[MAXLEN];

vector<int> vc[MAXLEN];
bool visited[MAXLEN];

void bfs(int start){
    // ���� ��ü�� �佺Ƽ���� �� �� �ִ� �� ���� �˻��̴�.
    // bfs�� �̿��Ͽ���. queue�� �̿��Ͽ� ������ Ǭ��.
    queue<int> q;
    q.push(start); // ù �� ���� queue�� ����

    while(!q.empty()){
        int node = q.front(); // �� �տ��� ����
        q.pop();   // queue ���� �տ���, ���� �� ����

        if(node==n+2){ // �佺Ƽ���� ���� �ߴٸ�
            visited[node] = true;
            break;
        }
        else if(visited[node]) continue;   // ���� node ���� �̹� �湮 �ߴٸ� �������� �Ѿ��.

        // ���� ���� �˻� �޾Ҵٶ�� ���� �˸��� ���� ����Ѵ�.
        visited[node] = true;

        // bfs������ queue�� ����Ѵ�.
        for(int i=0;i<vc[node].size();i++){
            // vc[node][i]�� ���� �ڸ� ��尡 ����Ǿ� �ִ�.
            // nextnode�� ����!
            // ����, �ش� visited[nextnode]�� �̹� �˻� �޾Ҵٸ� continue�Ѵ�.
            int nextnode = vc[node][i];
            if(visited[nextnode]) continue;

            // �ƴ϶�� queue�� ���� ���(nextnode)�� �����Ѵ�.
            q.push(vc[node][i]);
        }


    }


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--){
        cin >> n;

        for(int i=1;i<=n+2;i++){
            cin >> x >> y;
            convenience_store_x[i] = x;
            convenience_store_y[i] = y;
            vc[i].clear();
            // vc[i].clear();�� �� ������?
            // ������ vc(vector)�� while t�� ��ŭ �ݺ����� �������ϴµ� ����� ������ �ʱ�ȭ �� �� ����Ѵ�.
            // vector�� �̹� ���� �ִ� ���¿��� ����� �� �ٸ� ����� ���´�.
            // i == 1�� ���� ����̳� �� ���� ���̴�.
            // i == n+2�� ���� ��Ÿ��Ʈ �� �佺Ƽ�� ���̴�.
            // �� ����, 2 ~ n + 1 ������ �������̴�. (�̺κ� �����ϴµ� �����ɷȴ�.)
        }

        for(int i=1;i<=n+2;i++){
            for(int j=i+1; j<=n+2;j++){
                if(abs(convenience_store_x[j]-convenience_store_x[i])+
                   abs(convenience_store_y[j]-convenience_store_y[i]) <= 1000){
                       vc[i].push_back(j);
                       vc[j].push_back(i);
                       // ���� ��ü���� ���� �ѹڽ����� ���ְ� 20�� ����ִ�.
                       // ���� �Ѻ��� 50�����̴�. (���������� ���ͷ� ������ �����Ͽ���.)
                       // �ᱹ 1000 = 20 x 50 �̴�.
                       // ������ ������ �Ÿ��� 1000���Ͽ����� ���������� ���ָ� ������ �� �ִ�.
                       // �׷���, ������ x, y��ǥ ���� �̿��Ͽ� �Ÿ��� 1000������ ��ǥ���� vector�� �ִ´�.
                       // ���� �� �ֿ��� �� : vc[i��][�ε���] = j��, vc[j��][�ε���] = i���� �̿��Ͽ� �� ���� �����Ͽ���.

                   }
            }
        }
        memset(visited,false,sizeof(visited));    // false�� �ʱ�ȭ ���ش�.
        bfs(1);  // ���� �� : 1

        // n+2��°�� �湮�ߴ��� Ȯ���Ѵ�.
        if(visited[n+2]) cout << "happy"<<"\n";
        else cout <<"sad"<<"\n";

    }

    return 0;
}
