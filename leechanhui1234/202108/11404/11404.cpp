#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#define INF 987654321

using namespace std;

int n, m;

vector <int> v[101];
vector <int> ga[101];

bool visit[105];

int dis[101][101];

void dijkstra(int start) {
	priority_queue<pair<int, int> > pq;

	pq.push({ 0, start });

	while (!pq.empty()) {
		int node = pq.top().second;
		int co = -pq.top().first;

		pq.pop();

		if (visit[node]) continue;

		visit[node] = true;

		dis[start][node] = co;

		for (int i = 0; i < v[node].size(); i++) {
			int nextnode = v[node][i];
			int nextga = co + ga[node][i];

			if (visit[nextnode]) continue;

			pq.push({ -nextga, nextnode });
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b, c;

		cin >> a >> b >> c;

		v[a].push_back(b);

		ga[a].push_back(c);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dis[i][j] = INF;
		}
	}

	for (int i = 1; i <= n; i++) {
		fill(visit, visit + 101, false);

		dijkstra(i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dis[i][j] == INF) cout << 0 << ' ';
			else cout << dis[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}