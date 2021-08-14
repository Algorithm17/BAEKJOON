#include<iostream>
#include<cstdio>
#include<string>
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
    int cnt; // 인덱스 1 ~ 4중 어떤게 넘어 왔는지
};

void bfs(){
    queue<Struct> q;
    q.push({n,0});

    while(!q.empty()){
        Struct s = q.front();
        q.pop();

        if(s.number == n2){
            check = true;
            result_cnt = s.cnt;
            break;
        }


        if(s.number < 1000) continue;  // 1000 ~ 9999 까지다.
        if(visited[s.number]) continue;

        visited[s.number] = true;

        string number2 = to_string(s.number);

        for(int i=0;i<4;i++){
            int num = number2[i] - '0';

            for(int j=0;j<10;j++){
                string str_num = number2;
                if(i==0 && j==0) continue;

                if(j==num) continue;

                str_num[i] = j+'0';
                int check_number = stoi(str_num);
                if(!decimal[check_number]) continue;


                q.push({check_number,s.cnt+1});


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
