#include<iostream>
#include<cstdio>
#include<algorithm>


using namespace std;

int n; // 도시의 수
long long arr[11][11];
bool visited[11];
int current_result;
int total_result;
int start;
// dfs
// stack

// bfs
// queue

void backtracking(int cnt, int ind, int pay){

    if(cnt==n){
        pay += arr[ind][start];

        if(arr)
    }

    for(int i=1;i<=n;i++){
        if(visited[i]) continue;
        visited[i] = true
        backtracking(cnt+1,i,pay+arr[ind][i]);
        visited[i] = false;
    }



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
        fill(visited,visited+10,false);
        visited[i] = true;
        start = i;

        backtracking(1,i,0);


    }

    cout << total_result << "\n";

    return 0;
}
