#include<iostream>
#include<cstdio>
#include<vector>

int n, m;

using namespace std;

vector<int> v[2001]; //ģ������ ����

bool visit[2001]; //�湮�迭

bool check = false; //A, B, C, D, E ģ�����谡 �����ϴ��� ����

void dfs(int node, int depth) {
	if (depth == 4) { //ģ�����谡 ������
		check = true;
		return;
	}

	if (check) return; //�����ϸ� ��������� �� �ʿ䰡 ����

	visit[node] = true; //�湮�ߴٰ� ǥ��

	for (int i = 0; i < v[node].size(); i++) {
		int nextnode = v[node][i]; //���� ���

		if (visit[nextnode]) continue; //���� ��尡 �̹� �湮�� ����� ��

		dfs(nextnode, depth + 1); //���� ��忡 ���� dfs ���� ����
	}

	visit[node] = false; //�湮�迭�� �ٽ� false��!
}

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

	for (int i = 0; i < n; i++) {
		fill(visit, visit + 2001, false); //�湮 �迭�� false�� �ʱ�ȭ
		dfs(i, 0); //i���� dfs ����
		if (check) break; //ģ�����谡 �����ϴ� ��� ���� ������ ������ �ʿ䰡 ����
	}

	if (check) cout << "1";
	else cout << "0";

	return 0;
}