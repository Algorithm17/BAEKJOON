#include<iostream>
#include<cstdio>
#include<queue>

int n, m;

using namespace std;

int road[51][51]; //�� ���� (��? �ٴ�?)

int answer = 0; //��� �� �� �ִ� �Ÿ��� ���� �� �� ����

bool visit[51][51]; //�湮 ����

int xpos[4] = { -1, 0, 1, 0 };
int ypos[4] = { 0, 1, 0, -1 };

struct Point {
	int x;
	int y;
	int depth;
};

void bfs(int x, int y, int depth) {
	queue<Point> q;
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			visit[i][j] = false;
		}
	}

	q.push({ x, y, 0 }); //(y, x)�� �Ÿ� 0���� �����ϰ� ť�� ����

	int ans = 0; //ans : (y, x)�κ��� ��� �� �� �ִ� �ִܰŸ� �� ���� �� �Ÿ�

	while (!q.empty()) {
		int nodex = q.front().x;
		int nodey = q.front().y;
		int dep = q.front().depth;

		q.pop();

		if (visit[nodey][nodex]) continue; //�湮�� ��� 

		if (ans < dep) ans = dep;

		visit[nodey][nodex] = true;

		for (int i = 0; i <= 3; i++) {
			int nextx = nodex + xpos[i];
			int nexty = nodey + ypos[i];
			int nextdep = dep + 1;

			if (nextx <= 0 || nextx > m || nexty <= 0 || nexty > n) continue; //������ ��� ���
			
			if (visit[nexty][nextx]) continue; //�湮�� ���

			if (road[nexty][nextx] == 0) continue; //���� �ƴ� ���

			q.push({ nextx, nexty, nextdep });
		}
	}

	if (answer < ans) answer = ans; //answer������ ans���� ū ��� �� ������ ����
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		char arr[52];

		cin >> arr;

		for (int j = 1; j <= m; j++) {

			if (arr[j - 1] == 'W') road[i][j] = 0;

			else road[i][j] = 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (road[i][j] == 0) continue;

			bfs(j, i, 0);
		}
	}

	cout << answer;

	return 0;
}