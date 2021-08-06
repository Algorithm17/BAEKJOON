#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m;

int arr[1001][1001];

bool visit[1001][1001][5]; //distroy에 대한 (y,x) 의 방문 여부

int answer = -1;

int xpos[4] = { -1, 0, 1, 0 };
int ypos[4] = { 0, 1, 0, -1 };

struct Point {
	int x; //x좌표
	int y; //y좌표
	int distance; //최소이동거리
	int distroy; //파괴한 벽의 수
};

void bfs(int x, int y) {
	queue<Point> q;

	q.push({ x, y, 1, 0 });

	while (!q.empty()) {
		int startx = q.front().x;
		int starty = q.front().y;
		int dis = q.front().distance;
		int dist = q.front().distroy;

		q.pop();

		if (starty == n && startx == m) { //(n,m)의 좌표에 도착했을 때
			answer = dis; //answer변수 업데이트
			break;
		}

		if (visit[starty][startx][dist]) continue; //dist(파괴한 벽의 수)에 대한 (y,x)의 좌표가 방문한 좌표일 때 continue

		visit[starty][startx][dist] = true; //방문하지 않은 좌표일 땐 방문했다고 표시

		for (int i = 0; i <= 3; i++) {
			int nextx = startx + xpos[i];
			int nexty = starty + ypos[i];

			if (nextx <= 0 || nextx > m || nexty <= 0 || nexty > n) continue; //next좌표가 범위를 벗어난 좌표일 때

			if (arr[nexty][nextx] == 1) { //next 좌표에 벽이 존재할 때
				if (dist == 1) continue; //이미 벽을 파괴한 적이 있을 때

				if (visit[nexty][nextx][dist + 1]) continue; //그 좌표가 방문한 좌표일 때

				q.push({ nextx, nexty, dis + 1, dist + 1 }); //다음 좌표를 벽을 파괴했다고 표시한 후 큐에 삽입
			}

			else {
				if (visit[nexty][nextx][dist]) continue; //그 좌표가 방문한 좌표일 때

				q.push({ nextx, nexty, dis + 1, dist }); //다음 좌표를 큐에 삽입
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		char str[1001];

		cin >> str;

		for (int j = 0; j < strlen(str); j++) {
			arr[i][j + 1] = str[j] - '0';
		}
	}

	bfs(1, 1); //bfs 수행

	cout << answer; //answer값 출력

	return 0;
}
