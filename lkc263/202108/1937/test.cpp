#include<iostream>
#include<cstdio>
#define MAX 501

using namespace std;

int tree[MAX][MAX]; //�볪���� ��

int n;

int dp[MAX][MAX]; //�̵��� ĭ�� ��
bool visit[MAX][MAX]; //�ش� ĭ�� �湮 ����

int xpos[4] = { -1, 0, 1, 0 };
int ypos[4] = { 0, 1, 0, -1 };

int dfs(int y, int x, int cnt) {
	if (visit[y][x]) return dp[y][x]; //�̹� �湮�� ����� ��� dp�� �� ĭ���κ��� �̵��� ĭ�� ���� ���������� �� dp�� ����

	visit[y][x] = true; //�ش��带 �湮�ߴٰ� ǥ��

	bool check = false; //�ش���κ��� ���� ���� �� �� �ִ��� ����

	for (int i = 0; i <= 3; i++) {
		int nextx = x + xpos[i];
		int nexty = y + ypos[i];

		if (nextx <= 0 || nextx > n || nexty <= 0 || nexty > n) continue; //������ ��� ��� continue

		if (tree[y][x] >= tree[nexty][nextx]) continue; //�ڽ��� ��庸�� ���� ��尡 �볪�� ���� �� ���� ��� continue

		check = true;

		dp[y][x] = max(dfs(nexty, nextx, cnt + 1) + 1, dp[y][x]); //�ڽ��� dp�� ������� dp + 1�� ���� �� ū���� �ڽ��� dp�� ����
	}

	if (!check) dp[y][x] = 1; //�ش� ���κ��� ���� ���� �� �� ���� ��� dp�� 1�� ����

	return dp[y][x]; //�ش� ��忡�� �̵��� �� �ִ� ĭ�� �� ����
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> tree[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (visit[i][j]) continue; //�̹� �湮�� ��� continue

			dfs(i, j, 1); //(i, j)���� �̵��� �� �ִ� ĭ�� �� �ľ�
		}
	}

	int ma = 0; //�̵��� �� �ִ� ĭ�� �� �ִ� ���� ����

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ma < dp[i][j]) ma = dp[i][j];
		}
	}

	cout << ma; //�ִ� ���

	return 0;
}
