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
    // 문제 자체가 페스티벌에 갈 수 있는 지 연결 검사이다.
    // bfs를 이용하였다. queue를 이용하여 문제를 푼다.
    queue<int> q;
    q.push(start); // 첫 값 저장 queue에 저장

    while(!q.empty()){
        int node = q.front(); // 맨 앞에꺼 빼고
        q.pop();   // queue 가장 앞에꺼, 빼낸 거 제거

        if(node==n+2){ // 페스티벌에 도착 했다면
            visited[node] = true;
            break;
        }
        else if(visited[node]) continue;   // 현재 node 점을 이미 방문 했다면 다음으로 넘어간다.

        // 현재 노드는 검사 받았다라는 것을 알리기 위해 사용한다.
        visited[node] = true;

        // bfs에서는 queue를 사용한다.
        for(int i=0;i<vc[node].size();i++){
            // vc[node][i]는 다음 자리 노드가 저장되어 있다.
            // nextnode에 삽입!
            // 이제, 해당 visited[nextnode]가 이미 검사 받았다면 continue한다.
            int nextnode = vc[node][i];
            if(visited[nextnode]) continue;

            // 아니라면 queue에 다음 노드(nextnode)를 삽입한다.
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
            // vc[i].clear();를 왜 했을까?
            // 이유는 vc(vector)를 while t번 만큼 반복문을 돌려야하는데 사용할 때마다 초기화 한 후 사용한다.
            // vector에 이미 값이 있는 상태에서 사용할 시 다른 결과가 나온다.
            // i == 1일 때는 상근이네 집 시작 점이다.
            // i == n+2일 때는 펜타포트 락 페스티벌 점이다.
            // 그 사이, 2 ~ n + 1 까지는 편의점이다. (이부분 이해하는데 오래걸렸다.)
        }

        for(int i=1;i<=n+2;i++){
            for(int j=i+1; j<=n+2;j++){
                if(abs(convenience_store_x[j]-convenience_store_x[i])+
                   abs(convenience_store_y[j]-convenience_store_y[i]) <= 1000){
                       vc[i].push_back(j);
                       vc[j].push_back(i);
                       // 문제 자체에서 맥주 한박스에는 맥주가 20개 들어있다.
                       // 맥주 한병당 50미터이다. (문제에서는 미터로 범위를 측정하였다.)
                       // 결국 1000 = 20 x 50 이다.
                       // 편의점 사이의 거리가 1000이하여야지 편의점에서 맥주를 구매할 수 있다.
                       // 그래서, 편의점 x, y좌표 들을 이용하여 거리가 1000이하인 좌표들을 vector에 넣는다.
                       // 넣을 때 주요할 점 : vc[i점][인덱스] = j점, vc[j점][인덱스] = i점을 이용하여 두 개를 연결하였다.

                   }
            }
        }
        memset(visited,false,sizeof(visited));    // false로 초기화 해준다.
        bfs(1);  // 시작 값 : 1

        // n+2번째가 방문했는지 확인한다.
        if(visited[n+2]) cout << "happy"<<"\n";
        else cout <<"sad"<<"\n";

    }

    return 0;
}
