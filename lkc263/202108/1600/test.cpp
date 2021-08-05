#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

struct Point {
	int x; //x��ǥ
	int y; //y��ǥ
	int jump; //�� �̵�Ƚ��
	int move; //���� ��ǥ�� �̵��� Ƚ��
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

	q.push({ x, y, 0, 0}); //x��ǥ, y��ǥ, �� �̵�Ƚ��, ���� �̵���ǥ�� �̵��� Ƚ��

	while (!q.empty()) {
		int jump = q.front().jump; //�� �̵� ��
		int nodex = q.front().x;   //x
		int nodey = q.front().y;   //y
		int move = q.front().move; //���� �̵��������� �̵��� Ƚ��

		q.pop();

		if (nodex == w && nodey == h) { //(h,w)�� ��ǥ�� ������ ���
			answer = jump; //answer�� jump���� ���Խ�Ų�� break
			break;
		}

		if (visit[nodey][nodex][move]) continue; //���� �̵��������� �̵��� Ƚ���� move�� ��, (y,x)�� �湮�� ��ǥ�̸� continue

		visit[nodey][nodex][move] = true;

		if (move < k) { //move < k�̸� ���� �̵� �������� �̵��ص� �ǰ�, �����¿�� �̵��ص� ��
			for (int i = 0; i < 8; i++) { //���� �̵� �������� �̵�
				int nextx = nodex + xpos1[i];
				int nexty = nodey + ypos1[i];

				if (nextx <= 0 || nextx > w || nexty <= 0 || nexty > h) continue;

				if (visit[nexty][nextx][move + 1]) continue;

				if (arr[nexty][nextx] == 1) continue; //(nexty, nextx)�� ��ǥ �ڸ��� ��ֹ��� �����ϴ� ��� continue

				q.push({ nextx, nexty, jump + 1, move + 1}); //���� �̵���ǥ�� �̵������Ƿ� move + 1���Ѽ� ť�� ����
			}

			for (int i = 0; i < 4; i++) { //�����¿�� �̵�
				int nextx = nodex + xpos2[i];
				int nexty = nodey + ypos2[i];

				if (nextx <= 0 || nextx > w || nexty <= 0 || nexty > h) continue;

				if (visit[nexty][nextx][move]) continue;

				if (arr[nexty][nextx] == 1) continue; //(nexty, nextx)�� ��ǥ �ڸ��� ��ֹ��� �����ϴ� ��� continue

				q.push({ nextx, nexty, jump + 1, move}); //�����¿�θ� �̵������Ƿ� move�� ť�� ����
			}
		}

		else { //move == k�� ��� ���� �̵��������� �̵� �Ұ� => �����¿�θ� �̵�����
			for (int i = 0; i < 4; i++) { //�����¿�� �̵�
				int nextx = nodex + xpos2[i];
				int nexty = nodey + ypos2[i];

				if (nextx <= 0 || nextx > w || nexty <= 0 || nexty > h) continue;

				if (visit[nexty][nextx][move]) continue;

				if (arr[nexty][nextx] == 1) continue; //(nexty, nextx)�� ��ǥ �ڸ��� ��ֹ��� �����ϴ� ��� continue

				q.push({ nextx, nexty, jump + 1, move}); //�����¿�θ� �̵������Ƿ� move�� ť�� ����
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

	bfs(1, 1); //(1, 1)���� bfs ����

	return 0;
}
