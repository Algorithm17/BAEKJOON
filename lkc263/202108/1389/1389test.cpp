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
int result = 9999;
int result_ind;


void bfs(int index){
    queue<pair<int,int>> q;
    q.push({index,0});

    while(!q.empty()){
        int node = q.front().first;
        int step = q.front().second;

        q.pop();


        if(visited[node]) continue;
        visited[node] = true;

        banker_ind_cnt[index] += step;

        for(int i=0;i<vc[node].size();i++){
            if(visited[vc[node][i]]) continue;
            q.push({vc[node][i],step+1});
        }

    }


    if(banker_ind_cnt[index]<result){
        result = banker_ind_cnt[index];
        result_ind = index;
    }

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

    cout << result_ind << "\n";



    return 0;
}
