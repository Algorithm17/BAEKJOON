#include<iostream>
#include<cstdio>
#include<vector>

int n, m;

using namespace std;

vector<int> v[2001]; //친구관계 저장

bool visit[2001]; //방문배열

bool check = false; //A, B, C, D, E 친구관계가 존재하는지 여부

void dfs(int node, int depth) {
	if (depth == 4) { //친구관계가 존재함
		check = true;
		return;
	}

	if (check) return; //존재하면 다음계산을 할 필요가 없음

	visit[node] = true; //방문했다고 표시

	for (int i = 0; i < v[node].size(); i++) {
		int nextnode = v[node][i]; //다음 노드

		if (visit[nextnode]) continue; //다음 노드가 이미 방문한 노드일 때

		dfs(nextnode, depth + 1); //다음 노드에 대한 dfs 연산 수행
	}

	visit[node] = false; //방문배열을 다시 false로!
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;

		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0; i < n; i++) {
		fill(visit, visit + 2001, false); //방문 배열을 false로 초기화
		dfs(i, 0); //i부터 dfs 수행
		if (check) break; //친구관계가 존재하는 경우 다음 연산을 수행할 필요가 없음
	}

	if (check) cout << "1";
	else cout << "0";

	return 0;
}