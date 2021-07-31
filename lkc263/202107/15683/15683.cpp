#include<iostream>

#define NMAXSIZE 9
#define MMAXSIZE 9


using namespace std;

int n, m;
int arr[NMAXSIZE][MMAXSIZE];
int visited[NMAXSIZE][MMAXSIZE];
int cctvarr[6];
int current_check_cctv;
void dfs(int row, int column, int cctv){

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(cctv==1){
                if(row<=i&&i<=n){
                    if(arr[i][j] ==6 ) continue;
                }
            }
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> arr[i][j];

            if(1<=arr[i][j] && arr[i][j] <=5) cctvarr[arr[i][j]] = 1;
        }
    }


    for(int i=1;i<=5;i++){
        // cctvarr 1 ~ 5까지
        if(cctvarr[i]==0) continue;


        for(int row=1;row<=n;row++){
            for(int column=1;column<=m;column++){
                // -1 : *를 의미한다. cctv 경로에 포함된 곳
                if(!arr[row][column] || arr[row][column]== -1) continue;
                if(visited[row][column]) continue;


                dfs(row,column,i);
            }
        }
    }




    return 0;
}
