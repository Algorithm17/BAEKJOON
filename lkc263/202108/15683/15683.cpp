#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cmath>
#include<cstring>


using namespace std;

struct str{
    int cctv; // cctv 종류
    int x; //cctv x 좌표
    int y; //cctv y 좌표
    str(int cctv, int x, int y):cctv(cctv),x(x),y(y){};
};

vector<str> vc;
int n,m;
int arr[9][9];
int ans = 1000; // 사각 지대 최소 값

int cctv_cnt; // cctv 개수


void move_surveillance(int dir,int x, int y){
    switch(dir){
        case 0:  // 동
            for(int j=y+1;j<=m;j++){
                if(arr[x][j]==6) break;
                if(arr[x][j]==0) {
                    arr[x][j] = -1;

                }


            }
            break;
        case 1: // 서
            for(int j=1;j<y;j++){
                if(arr[x][j]==6) break;
                if(arr[x][j]==0) {
                    arr[x][j] = -1;

                }
            }
            break;
        case 2: // 남
            for(int i=x+1;i<=n;i++){
                if(arr[i][y]==6) break;
                if(arr[i][y]==0) {
                    arr[i][y] = -1;
                }
            }
            break;
        case 3:  // 북
            for(int i=x-1;i>0;i--){
                if(arr[i][y]==6) break;
                if(arr[i][y]==0) {
                    arr[i][y] = -1;
                }
            }
            break;


    }

}

void dfs(int step){
    if(step==cctv_cnt){

        int cnt_0 = 0;   // 0의 개수
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr[i][j] == 0)
                    cnt_0++;
            }
        }
//        cout << arr[3][4] <<"\n";
//        cout << "step : " <<step << " cnt :" << cnt_0 <<"\n";
        ans = min(ans,cnt_0);

    }

    int cctv = vc[step].cctv;
    int x = vc[step].x;
    int y = vc[step].y;

    int arr2[9][9];
    memcpy(arr2,arr,sizeof(arr));

    int ew = 0;
    int sn = 2;

    switch(cctv){
        case 1:
            // 동 서 남 북
            for(int dir=0;dir<4;dir++){
                move_surveillance(dir,x,y);
                dfs(step+1);

                memcpy(arr,arr2,sizeof(arr2));
            }
            break;

        case 2:
            // 동서, 북남
            for(int dir =0 ;dir<2;dir++){
                move_surveillance(dir,x,y);
                move_surveillance(dir+1,x,y);

                dfs(step+1);

                memcpy(arr,arr2,sizeof(arr));
            }
            break;

        case 3:
            // 동남, 동북, 서남, 서북

            for(int dir=0;dir<4;dir++){
                if(dir<2){
                    move_surveillance(ew,x,y);
                    move_surveillance(sn+dir,x,y);
                }else{
                    move_surveillance(ew+1,x,y);
                    move_surveillance(dir,x,y);
                }
                dfs(step+1);
                memcpy(arr,arr2,sizeof(arr));
            }
            break;
        case 4:
            for(int dir=0;dir<4;dir++){
                move_surveillance(dir,x,y);
                move_surveillance((dir+1)%4,x,y);
                move_surveillance((dir+2)%4,x,y);
                dfs(step+1);

                // 동남북, 동서남, 서남북, 동서북
                // 1 x, 3 x, 0 x, 2 x

                memcpy(arr,arr2,sizeof(arr));
            }
            break;

        case 5:
            for(int dir=0;dir<4;dir++){
                move_surveillance(dir,x,y);
            }

            dfs(step+1);
            break;


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
            if(1<=arr[i][j] && arr[i][j] <= 5){
                cctv_cnt++;
                vc.push_back(str(arr[i][j],i,j));
            }
        }
    }

    dfs(0);

    cout << ans << "\n";

    return 0;
}
