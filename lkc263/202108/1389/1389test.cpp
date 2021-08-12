    // 1 3
    // 1 4
    // 2 3
    // 3 4
    // 4 5 �� ��

    // 1�� ��, visited[1] = true; 1�� �湮������
    // ���� �� �ִ� ���� 3, 4�� ��
    // push�Ѵ�.
    // 0 : ����

    // i) 3�� ��, visited[3] = true; 3�� �湮������
    // ���� �� �ִ� ���� 1, 2, 4 �̴�.
    // 1�� �湮�Ͽ���.
    // push�� 2, 4�� �����ϴ�.
    // 1 -> 3 : 1�� �̵�

    // ii) 4�� ��, visited[4] = true; 4�� �湮������
    // ���� �� �ִ� ���� 1, 3, 5
    // 1, 3�� �湮�Ͽ���.
    // push�� 5�� �Ѵ�.
    // 1 -> 4 : 1�� �̵�

    // iii) 2�� ��, visited[2] = true; 2�� �湮������
    // ���� �� �ִ� ���� 3
    // 3�� �湮�Ͽ���.
    // push�� ���� ����.
    // 1 -> 3 -> 2 : 2�� �̵�

    // iv) 5�� ��, visited[5] = true; 5�� �湮������
    // ���� �� �ִ� ���� 4 �̴�.
    // 5�� �湮�Ͽ���.
    // push�� ���� ����.
    // 1 -> 4 -> 5  : 2�� �̵�

    // total : 6���̴�.

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<utility>

#define USERMAX 101
#define RELATIONSHIPS 5001

using namespace std;

int n,m;
// n : ������ ��, m : ������ ��

bool visited[RELATIONSHIPS];
int banker_ind_cnt[USERMAX];
vector<int> vc[USERMAX];

void bfs(int index){
    queue<pair<int,int>> q;
    q.push({index,0});


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int number, number2;
    cin >> n >> m;
    for(int i=1;i<=m;i++){
        cin >> number >> number2;

        vc[number].push_back(number2);
        vc[number2].push_back(number);
    }

    // ������ ����ŭ �ݺ�
    for(int i=1;i<=n;i++){
        fill(visited,visited+RELATIONSHIPS,false);
        bfs(i);
    }

    cout << total_index << "\n";



    return 0;
}
