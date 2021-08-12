#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<utility>

#define USERMAX 101
#define RELATIONSHIPS 5001

using namespace std;

int n,m;
// n : 유저의 수, m : 관계의 수

bool visited[RELATIONSHIPS];
int in_total=9999;
int out_total = 99999;
int total_list;
int total_index;
vector<int> vc[USERMAX];

// dfs로 풀었다.

void dfs(int current_data, int find_data, int cnt){
    if(current_data == find_data){
        if(in_total > cnt){
            in_total = cnt;
        }
    }

    visited[current_data] = true;
    for(int i=0;i<vc[current_data].size();i++){
        int number = vc[current_data][i];
        if(visited[number]) continue;
        dfs(vc[current_data][i],find_data,cnt+1);
    }
    visited[current_data] = false;
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
        for(int j=1;j<=n;j++){
            if(i!=j){
                fill(visited,visited+RELATIONSHIPS,false);
                dfs(i,j,0);
                total_list += in_total;
                in_total = 99999;
            }
        }
        if(out_total > total_list){
            out_total = total_list;
            total_index = i;
        }
        total_list = 0;
    }

    cout << total_index << "\n";



    return 0;
}
