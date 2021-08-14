#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>

#define MAX_INDEX 10000

using namespace std;

int t; // �׽�Ʈ ���̽��� ��
int n, n2;
int result_cnt;

bool check;
bool visited[MAX_INDEX];
int decimal[MAX_INDEX];  // 1000 ~ 9999

struct Struct{
    int number;
    int cnt; // ���� Ƚ��
};

void bfs(){
    queue<Struct> q;
    q.push({n,0});

    while(!q.empty()){
        Struct s = q.front();
        q.pop();

        if(s.number == n2){    // �Է��� �����͸� ã���� �� ������.
            check = true;      // �� ������ ã�Ҵ��� Ȯ���ϱ� ���ؼ� ����Ͽ���.
            result_cnt = s.cnt;     // Ƚ�� ���
            break;
        }


        if(s.number < 1000) continue;  // 1000 ~ 9999 ������.
        if(visited[s.number]) continue;

        visited[s.number] = true;

        // 1000 ~ 1�� �ڸ� ���� ���� ���Ѵ�.
        int a1 = s.number / 1000;
        int a2 = (s.number% 1000) / 100;
        int a3 = (s.number % 100) / 10;
        int a4 = (s.number % 10);


        // �� �ε����� �����͸� �����Ѵ�.
        int arr[4] = {a1,a2,a3,a4};

        for(int i=0;i<4;i++){
            for(int j=0;j<10;j++){
                // �ε��� i = 0, j = 0 �Ͻ� 1000���� ���� ���̴�. 0xxx �� ��� continue
                if(i==0 && j==0) continue;
                // j�� arr[i]�� ���ٸ� continue
                if(j==arr[i]) continue;

                int arr2[4] = {a1,a2,a3,a4};

                arr2[i] = j;    // ������ ���̴�.


                int num = arr2[0] * 1000 + arr2[1] * 100 + arr2[2] * 10 + arr2[3];

                if(visited[num]) continue;
                // �Ҽ��� �ƴ϶�� continue
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

    // �Ҽ� ����
    for(int i=2;i<MAX_INDEX;i++){
        decimal[i] = i;
    }

    for(int i=2;i<MAX_INDEX;i++){
        if(decimal[i] == 0) continue;      // i ��ġ ���� 0�̶�� continue
        for(int j = i+i;j<MAX_INDEX; j += i){  // �����ŭ 0 ����
            decimal[j] = 0;
        }
    }


    cin >> t;

    for(int i=0;i<t;i++){
        // �湮�� �� �ʱ�ȭ
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
