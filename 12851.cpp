#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

int n, k;

int arr[100001];
int time1[100001];

struct Point {
	int node;
	int count;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i <= 100000; i++) {
		time1[i] = 100001;
	}

	queue<Point> q;

	q.push({ n, 0 });

	int answer = 0; //최단 시간 방법의 수

	while (!q.empty()) {
		int node = q.front().node;
		int count = q.front().count;

		q.pop();

		if (node == k) {
			answer++;
		}

		time1[node] = count;

		if (node - 1 >= 0) {
			if (time1[node - 1] >= count + 1) {
				time1[node - 1] = count + 1;
				q.push({ node - 1, count + 1 });
			}
		}

		if (node + 1 <= 100000) {
			if (time1[node + 1] >= count + 1) {
				time1[node + 1] = count + 1;
				q.push({ node + 1, count + 1 });
			}
		}

		if (2 * node <= 100000) {
			if (time1[2 * node] >= count + 1) {
				time1[2 * node] = count + 1;
				q.push({ 2 * node, count + 1 });
			}
		}
	}

	cout << time1[k] << '\n' << answer;

	return 0;
}