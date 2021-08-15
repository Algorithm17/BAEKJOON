#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define INF 1e9  // ������ �ǹ��ϴ� ������ 10���� ����
using namespace std;

int n, m; // n : ������ ����, m : ������ ����
vector<pair<int,int>> graph[101];
int d[101][101];  // �ִ� �Ÿ�

// �켱���� ť�� �̿��� ���ͽ�Ʈ�� �˰���
void dijkstra(int start){

    // start �������� �ٸ� ������ �Ÿ� ��� ���Ѵ�.

    priority_queue<pair<int,int>> pq;
    pq.push({start,0});   // start : ����, 0 : ���

    while(!pq.empty()){
        int cur_node = pq.top().first;  // ���� ���
        int dist = -pq.top().second;    // ���� ������ ���

        pq.pop();

        // ���� �ִ� ��θ� ã�� ���¶�� �н��Ѵ�.
        // start : ���� ����, cur_node : ���� ���� ����
        // �ּ� ��� ��� �迭 ���� ��ġ�� ����Ǿ� �ִ� ��� < start �������� ���� ���� �������� ���
        if(d[start][cur_node] < dist) continue;

        // �ƴ϶��, �Է��Ѵ�.
        d[start][cur_node] = dist;

        for(int i=0;i<graph[cur_node].size();i++){
            // start �������� ���� �������� ��� : dist + graph[cur_node][i].second
            int cost = dist + graph[cur_node][i].second; // ���ļ� ���� ����� ����� ���
            int next_node = graph[cur_node][i].first;  // ���� ���

            // start �������� ���� �������� ��� < �ּ� ��� ��� �迭 ��ġ�� ����Ǿ� �ִ� ���
            if(cost < d[start][next_node]){
                d[start][next_node] = cost;
                // -cost�� �� ������ �켱���� ť���� ����� �� ���� ������ �����ϱ� ���ؼ� ����Ͽ���.
                // �켱���� ť�� ���������̴�.
                pq.push({graph[cur_node][i].first,-cost});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int a, b, c; // a : ������ ���� ����, b : ������ ���� ����, c : �� �� Ÿ�µ� �ʿ��� ���
    for(int i=1;i<=m;i++){
        cin >> a >> b >> c;

        // a�� ��忡�� b�� ���� ���� ����� c��� �ǹ��̴�.
        graph[a].push_back({b,c});
    }

    // �ִ� �Ÿ� ���̺��� ��� �������� �ʱ�ȭ �Ѵ�.
    fill(&d[0][0],&d[101-1][101],INF);

    for(int i=1;i<=n;i++){
        dijkstra(i);
    }

    // �÷��̵� ��� ���
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j] == INF) cout << 0;
            else cout << d[i][j];
            cout <<" ";
        }
        cout << "\n";
    }

    return 0;
}
