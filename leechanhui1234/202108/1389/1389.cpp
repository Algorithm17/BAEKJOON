#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int answer[101];

vector<int> v[101]; //ģ������ ����

int n, m;

bool visit[102];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;

		cin >> a >> b;

		v[a].push_back(b);
		v[b].push_back(a);
	}

	int mi = 100000000;

	for (int i = 1; i <= n; i++) {
		fill(visit, visit + n + 1, false); //visit�迭 �ʱ�ȭ

		queue<pair<int, int > > q;

		q.push({ i, 0 }); //i�� ģ�� ���� �ľ� i -> i = 0

		while (!q.empty()) {
			int node = q.front().first;
			int depth = q.front().second;

			q.pop();

			if (visit[node]) continue; //�湮�� ��� continue

			visit[node] = true;

			answer[i] += depth; //�� node�� ���̸� answer[i]�� ����

			for (int j = 0; j < v[node].size(); j++) {
				int nextnode = v[node][j]; //���� ���
				int nextdepth = depth + 1; //i���� ���� �������� ����

				if (visit[nextnode]) continue; //�湮�� ���

				q.push({ nextnode, nextdepth });
			}
		}

		if (mi > answer[i]) mi = answer[i]; //�ɺ� �������� ���� ���� ���� ����� mi������ ����
	}

	for (int i = 1; i <= n; i++) {
		if (answer[i] == mi) {
			cout << i;
			break;
		}
	}
	return 0;
}
