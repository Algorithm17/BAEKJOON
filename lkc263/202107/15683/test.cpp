#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct str{
    int cctv; //cctv ����
    int y; //cctv y��ǥ
    int x; //cctv x��ǥ
    str(int cctv,int y,int x):cctv(cctv),y(y),x(x){};
};

int N,M;
int ans=100; //�簢 ���� �ּҰ�
int cctv_cnt=0; //cctv ����
vector<vector<int>> ma(8,vector<int>(8,0)); //�繫��
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
