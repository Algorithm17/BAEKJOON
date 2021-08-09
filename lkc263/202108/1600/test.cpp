#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>

using namespace std;

// https://debuglog.tistory.com/90

struct StructList{
    int x;
    int y;
    int horse_cnt;
    int current_total_count;
    StructList(int x,int y,int horse_cnt,int current_total_count):x(x),y(y),horse_cnt(horse_cnt),current_total_count(current_total_count){}
};
// ���� �̵��� ������ x, y��ǥ�� ���� �̵��� �� �ִ� Ƚ��, �� �̵��� Ƚ���� �̿��Ѵ�.


int k, w, h;

int horse_coordinate[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};
// �� �̵��� ����
int adjacent_coordinate[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
// ������ ĭ (�����̰� �̵��� ����)

int arr[201][201];
bool visited[201][201][31] = {false};
int total;

int bfs(){
    queue<StructList> q;
    q.push(StructList(1,1,k,0));

    while(!q.empty()){
        StructList sl = q.front();
        q.pop();


        if(sl.x<=0 || sl.y <=0 || sl.x > h || sl.y > w) continue;
        if(arr[sl.x][sl.y]) continue;

        if(sl.x==h&&sl.y==w){
            return sl.current_total_count;
        }

        if(visited[sl.x][sl.y][sl.horse_cnt]) continue;
        // 3���� �迭�� ���� ������ ���� ������ ������ ���� ������ Ƚ���� �����ϱ� ���� ���
        // ex) (4, 3) ���� ���� 2�� �������� ������ ���� �ְ�
        // (4, 3) ���� ���� 5�� �������� ������ ���� �ִ�.

        visited[sl.x][sl.y][sl.horse_cnt] = true;

        for(int i=0;i<4;i++){
            int x_data = sl.x + adjacent_coordinate[i][0];
            int y_data = sl.y + adjacent_coordinate[i][1];
            q.push(StructList(x_data,y_data,sl.horse_cnt,sl.current_total_count+1));
        }

        if(sl.horse_cnt == 0) continue;

        for(int i=0;i<8;i++){
            int x_data = sl.x + horse_coordinate[i][0];
            int y_data = sl.y + horse_coordinate[i][1];
            q.push(StructList(x_data,y_data,sl.horse_cnt-1,sl.current_total_count+1));
        }
    }


    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;

    cin >> w >> h;

    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> arr[i][j];
        }
    }



    cout << bfs() << "\n";
    return 0;
}
