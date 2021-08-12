#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int answer[101];

vector<int> v[101]; //친구관계 저장

int n, m;

bool visit[102];

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

	int mi = 100000000;

	for (int i = 1; i <= n; i++) {
		fill(visit, visit + n + 1, false); //visit배열 초기화

		queue<pair<int, int > > q;

		q.push({ i, 0 }); //i의 친구 관계 파악 i -> i = 0

		while (!q.empty()) {
			int node = q.front().first;
			int depth = q.front().second;

			q.pop();

			if (visit[node]) continue; //방문한 경우 continue

			visit[node] = true;

			answer[i] += depth; //그 node의 깊이를 answer[i]에 더함

			for (int j = 0; j < v[node].size(); j++) {
				int nextnode = v[node][j]; //다음 노드
				int nextdepth = depth + 1; //i에서 다음 노드까지의 깊이

				if (visit[nextnode]) continue; //방문한 경우

				q.push({ nextnode, nextdepth });
			}
		}

		if (mi > answer[i]) mi = answer[i]; //케빈 베이컨의 수가 가장 작은 사람을 mi변수에 저장
	}

	for (int i = 1; i <= n; i++) {
		if (answer[i] == mi) {
			cout << i;
			break;
		}
	}
	return 0;
}
