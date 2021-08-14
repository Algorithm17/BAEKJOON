#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>

#define MAX_INDEX 10000

using namespace std;

int t; // 테스트 케이스의 수
int n, n2;
int result_cnt;

bool check;
bool visited[MAX_INDEX];
int decimal[MAX_INDEX];  // 1000 ~ 9999

struct Struct{
    int number;
    int cnt; // 현재 횟수
};

void bfs(){
    queue<Struct> q;
    q.push({n,0});

    while(!q.empty()){
        Struct s = q.front();
        q.pop();

        if(s.number == n2){    // 입력한 데이터를 찾았을 때 나간다.
            check = true;      // 준 이유는 찾았는지 확인하기 위해서 사용하였다.
            result_cnt = s.cnt;     // 횟수 결과
            break;
        }


        if(s.number < 1000) continue;  // 1000 ~ 9999 까지다.
        if(visited[s.number]) continue;

        visited[s.number] = true;

        // 1000 ~ 1의 자리 까지 값을 구한다.
        int a1 = s.number / 1000;
        int a2 = (s.number% 1000) / 100;
        int a3 = (s.number % 100) / 10;
        int a4 = (s.number % 10);


        // 각 인덱스에 데이터를 삽입한다.
        int arr[4] = {a1,a2,a3,a4};

        for(int i=0;i<4;i++){
            for(int j=0;j<10;j++){
                // 인덱스 i = 0, j = 0 일시 1000보다 작은 값이다. 0xxx 일 경우 continue
                if(i==0 && j==0) continue;
                // j와 arr[i]가 같다면 continue
                if(j==arr[i]) continue;

                int arr2[4] = {a1,a2,a3,a4};

                arr2[i] = j;    // 갱신할 값이다.


                int num = arr2[0] * 1000 + arr2[1] * 100 + arr2[2] * 10 + arr2[3];

                if(visited[num]) continue;
                // 소수가 아니라면 continue
                if(!decimal[num]) continue;

                q.push({num,s.cnt+1});


            }
        }

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 소수 구함
    for(int i=2;i<MAX_INDEX;i++){
        decimal[i] = i;
    }

    for(int i=2;i<MAX_INDEX;i++){
        if(decimal[i] == 0) continue;      // i 위치 값이 0이라면 continue
        for(int j = i+i;j<MAX_INDEX; j += i){  // 배수만큼 0 대입
            decimal[j] = 0;
        }
    }


    cin >> t;

    for(int i=0;i<t;i++){
        // 방문한 곳 초기화
        fill(visited,visited+MAX_INDEX,false);
        cin >> n >> n2;
        bfs();

        if(check) cout << result_cnt << "\n";
        else cout << "Impossible" << "\n";

        check = false;
        result_cnt = 0;
    }



    return 0;
}
