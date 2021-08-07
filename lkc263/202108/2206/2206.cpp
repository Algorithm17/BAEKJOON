#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;


struct PointData{
    int x;
    int y;
    int cnt;
    int wall;  //
};

int n,m;
int arr[1001][1001];
bool visited[1001][1001][5];
int total = -1;
char data[1001];

int x_coordinate[4] = {-1,0,1,0};
int y_coordinate[4] = {0,1,0,-1};

void bfs(){
    queue<PointData> q;
    q.push({1,1,1,0});

    while(!q.empty()){
        int x_data = q.front().x;
        int y_data = q.front().y;
        int cnt = q.front().cnt;
        int wall = q.front().wall;

        q.pop();

        if(x_data == n && y_data == m){
            total = cnt;
            return;
        }
//        cout << x_data << " " << y_data << " "<< cnt << " " << wall <<"\n";
        if(visited[x_data][y_data][wall]) continue;
        visited[x_data][y_data][wall] = true;

        for(int i=0;i<4;i++){
            int x_udlr = x_data + x_coordinate[i];
            int y_udlr = y_data + y_coordinate[i];

            if(x_udlr <=0 || x_udlr > n || y_udlr <=0 || y_udlr > m) continue;


            if(arr[x_udlr][y_udlr]){

                if(wall==1) continue;
                if(visited[x_udlr][y_udlr][wall+1]) continue;
                else{
//                    cout << "ÀÎµ¦½º : " << i << " " <<arr[x_udlr][y_udlr] << " ";
//                    cout << "push : " << x_udlr << " " << y_udlr << " "<<cnt+1 << " " << wall+1 <<"\n";
                    q.push({x_udlr,y_udlr,cnt+1,wall+1});

                }
            }else{
                if(visited[x_udlr][y_udlr][wall]) continue;
//                cout << "ÀÎµ¦½º : " << i << " " <<arr[x_udlr][y_udlr] << " ";
//                cout << "push : " << x_udlr << " " << y_udlr << " "<<cnt+1 << " " << wall <<"\n";
                q.push({x_udlr,y_udlr,cnt+1,wall});
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
        cin >> data;
        for(int j=1;j<=strlen(data);j++){
            arr[i][j] = data[j-1] - '0';
        }
    }

    bfs();

    cout << total << "\n";


    return 0;
}
