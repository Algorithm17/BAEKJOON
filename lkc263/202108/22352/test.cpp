#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>


using namespace std;

int n, m;
\
int arr[31][31];
int arr2[31][31];

bool visit[31][31];

int xpos[4] = { -1, 0, 1, 0 };
int ypos[4] = { 0, 1, 0, -1 };

void bfs(int x, int y) {
	queue<pair<int, int> > q;

	q.push({ x, y });

	while (!q.empty()) {
		int nodex = q.front().first;
		int nodey = q.front().second;

		q.pop();

		if (visit[nodey][nodex]) continue;

		visit[nodey][nodex] = true; //�湮�ߴٰ� ���� ǥ��

		for (int i = 0; i <= 3; i++) {
			int nextx = nodex + xpos[i];
			int nexty = nodey + ypos[i];

			if (nexty <= 0 || nexty > n || nextx <= 0 || nextx > m) continue;

			if (visit[nexty][nextx]) continue;

			if (arr[nodey][nodex] != arr[nexty][nextx]) continue; //���ڰ� ������ ��츸 ������ ǥ�� �ٸ� ���� continue

			q.push({ nextx, nexty });
		}
	}
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
			cin >> arr2[i][j];
		}
	}

	bool check = false; //bfs�� ������ ���� �ִ��� üũ

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == arr2[i][j]) continue; //�����Ͱ� ������ ��� continue

			if (visit[i][j]) continue; //�湮�� ��� continue

			bfs(j, i); //bfs ����

			check = true; //bfs ������ ���� �ִٰ� ǥ��

			int data = arr2[i][j];

			for (int ii = 1; ii <= n; ii++) {
				for (int jj = 1; jj <= m; jj++) {
					if (!visit[ii][jj]) continue;

					arr[ii][jj] = data; //�� ������ arr[i][j]�� �ִ� �����͸� arr2[i][j]�� �����ͷ� ����
				}
			}

			if (check) break; //bfs�� ������ ���� �ִ� ��� break
		}

		if (check) break; //bfs�� ������ ���� �ִ� ��� break
	}

	bool answer = true; //�����Ͱ� �������� Ȯ���ϴ� ����

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] != arr2[i][j]) {
				answer = false; //arr�� arr2�� �����Ͱ� �������� ���� ��� answer�� false�� ��ȯ
			}
		}
	}

	if (answer) cout << "YES"; //answer�� true�� ��� YES ���
	else cout << "NO"; //answer�� false�� ��� NO ���
	return 0;
}
