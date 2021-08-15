#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

#define INF 1e9  // 무한을 의미하는 값으로 10억을 설정
using namespace std;

int n, m; // n : 도시의 개수, m : 버스의 개수
vector<pair<int,int>> graph[101];
int d[101][101];  // 최단 거리

// 우선순위 큐를 이용한 다익스트라 알고리즘
void dijkstra(int start){

    // start 지점에서 다른 노드까지 거리 비용 구한다.

    priority_queue<pair<int,int>> pq;
    pq.push({start,0});   // start : 지점, 0 : 비용

    while(!pq.empty()){
        int cur_node = pq.top().first;  // 현재 노드
        int dist = -pq.top().second;    // 현재 노드까지 비용

        pq.pop();

        // 현재 최단 경로를 찾은 상태라면 패스한다.
        // start : 시작 지점, cur_node : 현재 도착 지점
        // 최소 비용 결과 배열 현재 위치에 저장되어 있는 비용 < start 지점에서 현재 도착 지점까지 비용
        if(d[start][cur_node] < dist) continue;

        // 아니라면, 입력한다.
        d[start][cur_node] = dist;

        for(int i=0;i<graph[cur_node].size();i++){
            // start 지점에서 도착 지점까지 비용 : dist + graph[cur_node][i].second
            int cost = dist + graph[cur_node][i].second; // 거쳐서 가는 노드의 비용을 계산
            int next_node = graph[cur_node][i].first;  // 다음 노드

            // start 지점에서 도착 지점까지 비용 < 최소 비용 결과 배열 위치에 저장되어 있는 비용
            if(cost < d[start][next_node]){
                d[start][next_node] = cost;
                // -cost를 한 이유는 우선순위 큐에서 비용이 싼 것을 앞으로 정렬하기 위해서 사용하였다.
                // 우선순위 큐는 내림차순이다.
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

    int a, b, c; // a : 버스의 시작 도시, b : 버스의 도착 도시, c : 한 번 타는데 필요한 비용
    for(int i=1;i<=m;i++){
        cin >> a >> b >> c;

        // a번 노드에서 b번 노드로 가는 비용이 c라는 의미이다.
        graph[a].push_back({b,c});
    }

    // 최단 거리 테이블을 모두 무한으로 초기화 한다.
    fill(&d[0][0],&d[101-1][101],INF);

    for(int i=1;i<=n;i++){
        dijkstra(i);
    }

    // 플로이드 결과 출력
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
