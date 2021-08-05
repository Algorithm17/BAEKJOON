#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct Point {
	int x; //x좌표
	int y; //y좌표
	int jump; //총 이동횟수
	int move; //말의 좌표로 이동한 횟수
};

int k;

int w, h;

int arr[201][201];

bool visit[201][201][31];

int xpos1[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int ypos1[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };

int xpos2[4] = { -1, 0, 1, 0 };
int ypos2[4] = { 0, 1, 0, -1 };

int answer = -1;

void bfs(int x, int y) {
	queue<Point> q;

	q.push({ x, y, 0, 0}); //x좌표, y좌표, 총 이동횟수, 말의 이동좌표로 이동한 횟수

	while (!q.empty()) {
		int jump = q.front().jump; //총 이동 수
		int nodex = q.front().x;   //x
		int nodey = q.front().y;   //y
		int move = q.front().move; //말의 이동방향으로 이동한 횟수

		q.pop();

		if (nodex == w && nodey == h) { //(h,w)의 좌표에 도착한 경우
			answer = jump; //answer에 jump값을 대입시킨후 break
			break;
		}

		if (visit[nodey][nodex][move]) continue; //말의 이동방향으로 이동한 횟수가 move일 때, (y,x)가 방문한 좌표이면 continue

		visit[nodey][nodex][move] = true;

		if (move < k) { //move < k이면 말의 이동 방향으로 이동해도 되고, 상하좌우로 이동해도 됨
			for (int i = 0; i < 8; i++) { //말의 이동 방향으로 이동
				int nextx = nodex + xpos1[i];
				int nexty = nodey + ypos1[i];

				if (nextx <= 0 || nextx > w || nexty <= 0 || nexty > h) continue;

				if (visit[nexty][nextx][move + 1]) continue;

				if (arr[nexty][nextx] == 1) continue; //(nexty, nextx)의 좌표 자리에 장애물이 존재하는 경우 continue

				q.push({ nextx, nexty, jump + 1, move + 1}); //말의 이동좌표로 이동했으므로 move + 1시켜서 큐에 대입
			}

			for (int i = 0; i < 4; i++) { //상하좌우로 이동
				int nextx = nodex + xpos2[i];
				int nexty = nodey + ypos2[i];

				if (nextx <= 0 || nextx > w || nexty <= 0 || nexty > h) continue;

				if (visit[nexty][nextx][move]) continue;

				if (arr[nexty][nextx] == 1) continue; //(nexty, nextx)의 좌표 자리에 장애물이 존재하는 경우 continue

				q.push({ nextx, nexty, jump + 1, move}); //상하좌우로만 이동했으므로 move를 큐에 대입
			}
		}

		else { //move == k인 경우 말의 이동방향으로 이동 불가 => 상하좌우로만 이동가능
			for (int i = 0; i < 4; i++) { //상하좌우로 이동
				int nextx = nodex + xpos2[i];
				int nexty = nodey + ypos2[i];

				if (nextx <= 0 || nextx > w || nexty <= 0 || nexty > h) continue;

				if (visit[nexty][nextx][move]) continue;

				if (arr[nexty][nextx] == 1) continue; //(nexty, nextx)의 좌표 자리에 장애물이 존재하는 경우 continue

				q.push({ nextx, nexty, jump + 1, move}); //상하좌우로만 이동했으므로 move를 큐에 대입
			}
		}
	}

	cout << answer;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> k;

	cin >> w >> h;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> arr[i][j];
		}
	}

	bfs(1, 1); //(1, 1)부터 bfs 수행

	return 0;
}
