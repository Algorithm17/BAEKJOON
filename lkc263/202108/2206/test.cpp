#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m;

int arr[1001][1001];

bool visit[1001][1001][5]; //distroy�� ���� (y,x) �� �湮 ����

int answer = -1;

int xpos[4] = { -1, 0, 1, 0 };
int ypos[4] = { 0, 1, 0, -1 };

struct Point {
	int x; //x��ǥ
	int y; //y��ǥ
	int distance; //�ּ��̵��Ÿ�
	int distroy; //�ı��� ���� ��
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

		if (starty == n && startx == m) { //(n,m)�� ��ǥ�� �������� ��
			answer = dis; //answer���� ������Ʈ
			break;
		}

		if (visit[starty][startx][dist]) continue; //dist(�ı��� ���� ��)�� ���� (y,x)�� ��ǥ�� �湮�� ��ǥ�� �� continue

		visit[starty][startx][dist] = true; //�湮���� ���� ��ǥ�� �� �湮�ߴٰ� ǥ��

		for (int i = 0; i <= 3; i++) {
			int nextx = startx + xpos[i];
			int nexty = starty + ypos[i];

			if (nextx <= 0 || nextx > m || nexty <= 0 || nexty > n) continue; //next��ǥ�� ������ ��� ��ǥ�� ��

			if (arr[nexty][nextx] == 1) { //next ��ǥ�� ���� ������ ��
				if (dist == 1) continue; //�̹� ���� �ı��� ���� ���� ��

				if (visit[nexty][nextx][dist + 1]) continue; //�� ��ǥ�� �湮�� ��ǥ�� ��

				q.push({ nextx, nexty, dis + 1, dist + 1 }); //���� ��ǥ�� ���� �ı��ߴٰ� ǥ���� �� ť�� ����
			}

			else {
				if (visit[nexty][nextx][dist]) continue; //�� ��ǥ�� �湮�� ��ǥ�� ��

				q.push({ nextx, nexty, dis + 1, dist }); //���� ��ǥ�� ť�� ����
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

	bfs(1, 1); //bfs ����

	cout << answer; //answer�� ���

	return 0;
}
