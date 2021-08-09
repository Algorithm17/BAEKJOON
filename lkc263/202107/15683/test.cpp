#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct str{
    int cctv; //cctv 종류
    int y; //cctv y좌표
    int x; //cctv x좌표
    str(int cctv,int y,int x):cctv(cctv),y(y),x(x){};
};

int N,M;
int ans=100; //사각 지대 최소값
int cctv_cnt=0; //cctv 개수
vector<vector<int>> ma(8,vector<int>(8,0)); //사무실
vector<str> vec;





int main(){

    cin>>N>>M;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            scanf("%d",&ma[i][j]);

        }

    }

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << ma[i][j]<<" ";
        }
        cout <<"\n";
    }




    return 0;
}
