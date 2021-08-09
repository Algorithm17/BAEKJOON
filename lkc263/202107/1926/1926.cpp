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


// x, y ��ǥ 1 ~ 4 �и� ��ǥ�̴�.
int x_coordinate[4] = {-1,0,1,0};
int y_coordinate[4] = {0,1,0,-1};



void dfs(int x,int y){
    queue<pair<int,int>> q;

    // pair �Է��� ���� make_pair ����Ѵ�.
    q.push(make_pair(x,y));

    // ����� 1�� ������ ���� ���Ͽ� ���� = 0
    widthofthepicture = 0;
    while(!q.empty()){
        int x_t = q.front().first;  // q ù ��° �� ��ȯ
        int y_t = q.front().second;  // q �� ��° �� ��ȯ

        q.pop();

        // �̹� �湮�� ���̶�� continue
        if(visited[x_t][y_t]) continue;

        // �湮���� ���̶�� true
        visited[x_t][y_t] = true;


        widthofthepicture++;

        // x, y���� 1 ~ 4 ��ǥ ���� �����ش�.
        for(int i=0;i<=3;i++){
            int x_check = x_t + x_coordinate[i];
            int y_check = y_t + y_coordinate[i];

            // ������ ������ �ʴ� �ٸ�, continue
            if(x_check<=0||x_check > n||y_check <=0 ||y_check >m) continue;
            else if(visited[x_check][y_check]) continue;
            else if(!arr[x_check][y_check]) continue;
            // �̹� �湮�� ���̰ų�, 0�������� �������� �Ѿ��.


            // �����ϸ� queue�� x, y��ǥ �����Ѵ�.
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


            // ���� ��µ� Ƚ���� �ִ� ������ ���� �� ������Ʈ
            if(widthofthepicture > maximum_picture) maximum_picture = widthofthepicture;
        }
    }

    cout << painting_count << "\n";
    cout << maximum_picture << "\n";

    return 0;
}
