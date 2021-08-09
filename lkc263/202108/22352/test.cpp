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

		visit[nodey][nodex] = true; //방문했다고 영역 표시

		for (int i = 0; i <= 3; i++) {
			int nextx = nodex + xpos[i];
			int nexty = nodey + ypos[i];

			if (nexty <= 0 || nexty > n || nextx <= 0 || nextx > m) continue;

			if (visit[nexty][nextx]) continue;

			if (arr[nodey][nodex] != arr[nexty][nextx]) continue; //숫자가 동일한 경우만 영역을 표시 다른 경우는 continue

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

	bool check = false; //bfs를 수행한 적이 있는지 체크

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == arr2[i][j]) continue; //데이터가 동일한 경우 continue

			if (visit[i][j]) continue; //방문한 경우 continue

			bfs(j, i); //bfs 수행

			check = true; //bfs 수행한 적이 있다고 표시

			int data = arr2[i][j];

			for (int ii = 1; ii <= n; ii++) {
				for (int jj = 1; jj <= m; jj++) {
					if (!visit[ii][jj]) continue;

					arr[ii][jj] = data; //그 영역만 arr[i][j]에 있는 데이터를 arr2[i][j]의 데이터로 변경
				}
			}

			if (check) break; //bfs를 수행한 적이 있는 경우 break
		}

		if (check) break; //bfs를 수행한 적이 있는 경우 break
	}

	bool answer = true; //데이터가 동일한지 확인하는 변수

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] != arr2[i][j]) {
				answer = false; //arr과 arr2의 데이터가 동일하지 않은 경우 answer를 false로 변환
			}
		}
	}

	if (answer) cout << "YES"; //answer가 true인 경우 YES 출력
	else cout << "NO"; //answer가 false인 경우 NO 출력
	return 0;
}
