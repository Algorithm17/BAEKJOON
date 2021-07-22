#include <iostream>
#include <queue>
#include <cstring>
#define MAX 1001
using namespace std;

int n, m, v;
int a, b;
int map[MAX][MAX];
bool visited[MAX];
queue<int>q;

void bfs(int v) {
	visited[v] = 1;
	q.push(v);

	while (!q.empty()) {
		v = q.front();
		q.pop();
		cout << v << " ";
		for (int i = 1; i <= n; i++) {
			if (map[v][i]  && !visited[i]) {
				q.push(i);
				visited[i] = 1;
			}
		}
	}
}

void dfs(int v) {
	cout << v << " ";
	visited[v] = 1;
	for (int i = 1; i <= n; i++) {
		if (map[v][i]  && !visited[i]) {
			dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> n >> m >> v;
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		map[a][b] = map[b][a] = 1;
	}
	cout << "bfs" <<'\n';
//	dfs(v);
//	cout << '\n';
//	memset(visited, false, sizeof(visited));
	bfs(v);
	cout << '\n';
}
