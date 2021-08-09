#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#define MAX 501

using namespace std;

int n, m;

int arr[MAX][MAX];

bool visit[MAX][MAX]; //방문여부 저장 배열

int count1 = 0; //영역 개수 count 변수

int ma = 0; //영역 넓이 최댓값 저장 변수

int xpos[4] = { -1, 0, 1, 0 };
int ypos[4] = { 0, 1, 0, -1 };
//(-1,0), (0,1), (1,0), (0,-1)

void bfs(int startx, int starty) { //bfs 수행
	queue<pair<int, int > > q;

	q.push(make_pair(startx, starty));

	int co = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		if (visit[y][x]) continue;

		co++;

		visit[y][x] = true;

		for (int i = 0; i <= 3; i++) {
			int nextx = x + xpos[i];
			int nexty = y + ypos[i];

			if (nextx <= 0 || nextx > m || nexty <= 0 || nexty > n) continue;

			if (visit[nexty][nextx]) continue;

			if (arr[nexty][nextx] == 0) continue;

			q.push(make_pair(nextx, nexty));
		}
	}

	if (ma < co) ma = co;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (visit[i][j]) continue; //방문한 경우 continue
			if (arr[i][j] == 0) continue; //자신의 자리가 색칠되지 않은 자리인 경우 continue

			count1++;

			bfs(j, i);
		}
	}

	cout << count1 << '\n';
	cout << ma << '\n';
	return 0;
}
