#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>

#define N_MAX 2001
#define M_MAX 2001


using namespace std;


int n,m;
int cnt;
int arr[N_MAX][M_MAX];
bool visited[M_MAX];

void dfs(int index, int lr){

    if(cnt==4) return;
    if(visited[index]) return;


    for(int i=0;i<m;i++){
        if(!visited[i] && arr[index][lr] == arr[i][0] && arr[index][lr] == arr[i][1]){
            visited[i] = true;
            if(arr[index][lr] == arr[i][0]) dfs(i,1);
            else if(arr[index][lr] == arr[i][1]) dfs(i,0);
            cnt++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin >> arr[i][j];
        }
    }


    for(int i=0;i<m;i++){

        if(arr[i][0] != arr[i][1]){

            int lr =0;
                while(lr < 2){
                    fill(visited,visited+M_MAX,false);
                    cnt = 0;
                    visited[i] = true;
                    dfs(i,lr);

                    if(cnt==4){
                        cout << 1;
                        return 0;
                    }
                    lr++;
                }

        }
    }

    cout << 0;



    return 0;
}
