#include<iostream>
#include<algorithm>
#include<cstdio>


#define N_MAX_NUMBER 10001
#define M_MAX_NUMBER 10001

using namespace std;

int arr[N_MAX_NUMBER][M_MAX_NUMBER];
int visited[N_MAX_NUMBER];
int count_arr[N_MAX_NUMBER];

int N,M;
int A,B;
int max_result;
int cnt;

void dfs(int n){

    visited[n] = 1;

    for(int i= 1;i<=arr[n];i++){
        if(arr[n][i] && !visited[i]){
            cnt++;
            visited[i] = 1;
            dfs(arr[n][i]);
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> N >> M;


    for(int i=0;i<M;i++){
        cin >> A >> B;
        arr[A][i] = B;
    }

    for(int i=1;i<=N;i++){
        fill(visited,visited+N_MAX_NUMBER,0);
        cnt = 0;

        dfs(i);
        count_arr[i] = cnt;
        if(count_arr[i] > max_result) max_result = count_arr[i];
    }

    int input_index = 0 ;
    for(int i=1;i<=N;i++){
        if(count_arr[i] == max_result) printf("%d ",i);
    }

    return 0;
}
