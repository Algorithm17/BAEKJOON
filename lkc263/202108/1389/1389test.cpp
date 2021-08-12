    // 1 3
    // 1 4
    // 2 3
    // 3 4
    // 4 5 일 때

    // 1일 때, visited[1] = true; 1을 방문했으니
    // 나올 수 있는 값이 3, 4일 때
    // push한다.
    // 0 : 시작

    // i) 3일 때, visited[3] = true; 3을 방문했으니
    // 나올 수 있는 값이 1, 2, 4 이다.
    // 1은 방문하였다.
    // push는 2, 4만 가능하다.
    // 1 -> 3 : 1번 이동

    // ii) 4일 때, visited[4] = true; 4을 방문했으니
    // 나올 수 있는 값이 1, 3, 5
    // 1, 3은 방문하였다.
    // push는 5를 한다.
    // 1 -> 4 : 1번 이동

    // iii) 2일 때, visited[2] = true; 2을 방문했으니
    // 나올 수 있는 값이 3
    // 3은 방문하였다.
    // push할 값이 없다.
    // 1 -> 3 -> 2 : 2번 이동

    // iv) 5일 때, visited[5] = true; 5을 방문했으니
    // 나올 수 있는 값이 4 이다.
    // 5는 방문하였다.
    // push할 값이 없다.
    // 1 -> 4 -> 5  : 2번 이동

    // total : 6번이다.

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>

#define USERMAX 101
#define RELATIONSHIPS 5001

using namespace std;

int n,m;
// n : 유저의 수, m : 관계의 수

bool visited[RELATIONSHIPS];
int banker_ind_cnt[USERMAX];
vector<int> vc[USERMAX];

void bfs(int index){
    queue<pair<int,int>> q;
    q.push({index,0});


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int number, number2;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> number >> number2;

        vc[number].push_back(number2);
        vc[number2].push_back(number);
    }

    // 유저의 수만큼 반복
    for(int i=1;i<=n;i++){
        fill(visited,visited+RELATIONSHIPS,false);
        bfs(i);
    }

    cout << total_index << "\n";



    return 0;
}
