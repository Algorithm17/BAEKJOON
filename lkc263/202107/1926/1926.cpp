#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

int n, m;
int arr[501][501];
int visited[501][501];
int painting_count,widthofthepicture;

int maximum_picture = 0;


// x, y 좌표 1 ~ 4 분면 좌표이다.
int x_coordinate[4] = {-1,0,1,0};
int y_coordinate[4] = {0,1,0,-1};



void dfs(int x,int y){
    queue<pair<int,int>> q;

    // pair 입력할 때는 make_pair 사용한다.
    q.push(make_pair(x,y));

    // 연결된 1의 개수를 세기 위하여 변수 = 0
    widthofthepicture = 0;
    while(!q.empty()){
        int x_t = q.front().first;  // q 첫 번째 값 반환
        int y_t = q.front().second;  // q 두 번째 값 반환

        q.pop();

        // 이미 방문한 곳이라면 continue
        if(visited[x_t][y_t]) continue;

        // 방문안한 곳이라면 true
        visited[x_t][y_t] = true;


        widthofthepicture++;

        // x, y값에 1 ~ 4 좌표 값을 더해준다.
        for(int i=0;i<=3;i++){
            int x_check = x_t + x_coordinate[i];
            int y_check = y_t + y_coordinate[i];

            // 범위에 속하지 않는 다면, continue
            if(x_check<=0||x_check > n||y_check <=0 ||y_check >m) continue;
            else if(visited[x_check][y_check]) continue;
            else if(!arr[x_check][y_check]) continue;
            // 이미 방문한 곳이거나, 0인지점은 다음으로 넘어간다.


            // 성립하면 queue에 x, y좌표 삽입한다.
            q.push(make_pair(x_check,y_check));
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
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(visited[i][j]) continue;
            if(!arr[i][j]) continue;

            painting_count++;
            dfs(i,j);


            // 현재 출력된 횟수가 최대 값보다 많을 때 업데이트
            if(widthofthepicture > maximum_picture) maximum_picture = widthofthepicture;
        }
    }

    cout << painting_count << "\n";
    cout << maximum_picture << "\n";

    return 0;
}
