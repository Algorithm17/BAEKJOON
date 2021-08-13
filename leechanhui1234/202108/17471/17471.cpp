#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n;

vector<int> v[11]; //구역간의 관계

int person[11]; //각 구역의 인구수

int answer = 987654321; //두 구역의 차이가 최소 

int team[11]; //1 : 청팀, 0 : 백팀

int totalsum = 0; //전체 인구의 합

void dfs(int start, int cnt, int sum1) { //모든 경우의 수 파악

	if (cnt == n) return; //한 구역에 전체 선거구가 몰렸을 때

	int bfsstart = 0; //한 구역에 백팀 인원들이 존재 가능한지 bfs 수행 시작 변수

	for (int i = 1; i <= n; i++) {
		if (team[i] == 0) { //백팀인 경우 그 지점부터 bfs 돌리도록 bfsstart변수에 그 지점을 저장
			bfsstart = i;
			break;
		}
	}

	queue<int> q;

	q.push(bfsstart); 

	bool visitbfs[11] = { false, };

	while (!q.empty()) { //백팀간 관계가 존재 가능한지 bfs
		int node = q.front();
		q.pop();

		if (visitbfs[node]) continue; //방문한 경우

		visitbfs[node] = true; 

		for (int i = 0; i < v[node].size(); i++) {
			int nextnode = v[node][i]; //다음 노드

			if (visitbfs[nextnode]) continue; //방문한 경우 continue

			if (team[nextnode] == 1) continue; //청팀인 경우 continue (백팀간 관계만 아는게 목적이므로)

			q.push(nextnode);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (team[i] == 1) { //이제 청팀간 관계 파악 청팀의 시작 주소를 bfsstart에 저장
			bfsstart = i;
			break;
		}
	}

	q.push(bfsstart);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		if (visitbfs[node]) continue; //방문한 경우

		visitbfs[node] = true; 

		for (int i = 0; i < v[node].size(); i++) {
			int nextnode = v[node][i]; //다음 노드
			 
			if (visitbfs[nextnode]) continue; //방문한 경우

			if (team[nextnode] == 0) continue; //청팀간 관계를 파악하는게 목적! 백팀인 경우 continue

			q.push(nextnode);
		}
	}

	bool check = true;

	for (int i = 1; i <= n; i++) { //청팀, 백팀간 관계를 파악하면서 모든 노드를 방문했는지 파악
		if (visitbfs[i]) continue; 

		check = false;
		break;
	}

	if (check) { //모든 노드를 방문한 경우
		int sum2 = totalsum - sum1; //sum1, sum2를 파악

		if (answer > abs(sum2 - sum1)) answer = abs(sum2 - sum1); //answer보다 sum1 - sum2의 절댓값이 작은 경우 그걸로 업데이트
	}

	for (int i = start + 1; i <= n; i++) { 
		if (team[i] == 1) continue;

		team[i] = 1;

		dfs(i, cnt + 1, sum1 + person[i]); //백트래킹 수행

		team[i] = 0;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> person[i];
		totalsum += person[i];
	}

	for (int i = 1; i <= n; i++) {
		int num;

		cin >> num;

		for (int j = 0; j < num; j++) {
			int a;
			cin >> a;
			v[i].push_back(a);
		}
	}

	for (int i = 1; i <= n; i++) {

		fill(team, team + 11, 0);
	
		team[i] = 1; //i가 청팀일 때

		dfs(i, 1, person[i]);

		team[i] = 0; //i가 백팀일 때
	}

	if (answer != 987654321) cout << answer; //두 선거구로 나눌 수 있을 때 인구수 차이
	else cout << "-1"; //두 선거구로 나눌 수 없을 때

	return 0;
}