#include<iostream>
#include<cstdio>
#define MAX 501

using namespace std;

int tree[MAX][MAX]; //대나무의 양

int n;

int dp[MAX][MAX]; //이동한 칸의 수
bool visit[MAX][MAX]; //해당 칸의 방문 여부

int xpos[4] = { -1, 0, 1, 0 };
int ypos[4] = { 0, 1, 0, -1 };

int dfs(int y, int x, int cnt) {
	if (visit[y][x]) return dp[y][x]; //이미 방문한 노드인 경우 dp에 그 칸으로부터 이동한 칸의 수가 적혀있으니 그 dp를 리턴

	visit[y][x] = true; //해당노드를 방문했다고 표시

	bool check = false; //해당노드로부터 다음 노드로 갈 수 있는지 여부

	for (int i = 0; i <= 3; i++) {
		int nextx = x + xpos[i];
		int nexty = y + ypos[i];

		if (nextx <= 0 || nextx > n || nexty <= 0 || nexty > n) continue; //범위를 벗어난 경우 continue

		if (tree[y][x] >= tree[nexty][nextx]) continue; //자신의 노드보다 다음 노드가 대나무 양이 더 적은 경우 continue

		check = true;

		dp[y][x] = max(dfs(nexty, nextx, cnt + 1) + 1, dp[y][x]); //자신의 dp와 다음노드 dp + 1을 비교해 더 큰수를 자신의 dp에 저장
	}

	if (!check) dp[y][x] = 1; //해당 노드로부터 다음 노드로 갈 수 없는 경우 dp를 1로 저장

	return dp[y][x]; //해당 노드에서 이동할 수 있는 칸의 수 리턴
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
			if (visit[i][j]) continue; //이미 방문한 경우 continue

			dfs(i, j, 1); //(i, j)에서 이동할 수 있는 칸의 수 파악
		}
	}

	int ma = 0; //이동할 수 있는 칸의 수 최댓값 저장 변수

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ma < dp[i][j]) ma = dp[i][j];
		}
	}

	cout << ma; //최댓값 출력

	return 0;
}
