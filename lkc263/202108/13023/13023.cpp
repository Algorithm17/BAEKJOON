#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>

#define N_MAX 2001
#define M_MAX 2001


using namespace std;


// 어떠한 연결을 할 때에는 vector를 사용한다.
// 1 -> 2 -> 3 (연결리스트 일 때는 vector를 사용한다.)


// 정리하기
int n,m;
int cnt;
vector<int> vc[M_MAX];
bool visited[M_MAX];
bool checkbox;

void dfs(int index, int cnt){

    if(cnt==4){
        checkbox = true;
        return;
    }
    visited[index] = true;

    // 연결된 부분만 확인한다.
    for(int i=0;i<vc[index].size();i++){
        int number = vc[index][i];

        if(visited[number]) continue;

        dfs(number,cnt+1);
    }

    visited[index] = false;
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    int num,num2;
    for(int i=0;i<m;i++){
        cin >> num >> num2;

        vc[num].push_back(num2);
        vc[num2].push_back(num);
    }

    for(int i=0;i<m;i++){
        fill(visited,visited+M_MAX,false);

        dfs(i,0);

        if(checkbox==true) {
            cout << 1 <<"\n";
            return 0;
        }
    }



    cout << 0;



    return 0;
}
