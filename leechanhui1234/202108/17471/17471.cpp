#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

int n;

vector<int> v[11]; //�������� ����

int person[11]; //�� ������ �α���

int answer = 987654321; //�� ������ ���̰� �ּ� 

int team[11]; //1 : û��, 0 : ����

int totalsum = 0; //��ü �α��� ��

void dfs(int start, int cnt, int sum1) { //��� ����� �� �ľ�

	if (cnt == n) return; //�� ������ ��ü ���ű��� ������ ��

	int bfsstart = 0; //�� ������ ���� �ο����� ���� �������� bfs ���� ���� ����

	for (int i = 1; i <= n; i++) {
		if (team[i] == 0) { //������ ��� �� �������� bfs �������� bfsstart������ �� ������ ����
			bfsstart = i;
			break;
		}
	}

	queue<int> q;

	q.push(bfsstart); 

	bool visitbfs[11] = { false, };

	while (!q.empty()) { //������ ���谡 ���� �������� bfs
		int node = q.front();
		q.pop();

		if (visitbfs[node]) continue; //�湮�� ���

		visitbfs[node] = true; 

		for (int i = 0; i < v[node].size(); i++) {
			int nextnode = v[node][i]; //���� ���

			if (visitbfs[nextnode]) continue; //�湮�� ��� continue

			if (team[nextnode] == 1) continue; //û���� ��� continue (������ ���踸 �ƴ°� �����̹Ƿ�)

			q.push(nextnode);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (team[i] == 1) { //���� û���� ���� �ľ� û���� ���� �ּҸ� bfsstart�� ����
			bfsstart = i;
			break;
		}
	}

	q.push(bfsstart);

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		if (visitbfs[node]) continue; //�湮�� ���

		visitbfs[node] = true; 

		for (int i = 0; i < v[node].size(); i++) {
			int nextnode = v[node][i]; //���� ���
			 
			if (visitbfs[nextnode]) continue; //�湮�� ���

			if (team[nextnode] == 0) continue; //û���� ���踦 �ľ��ϴ°� ����! ������ ��� continue

			q.push(nextnode);
		}
	}

	bool check = true;

	for (int i = 1; i <= n; i++) { //û��, ������ ���踦 �ľ��ϸ鼭 ��� ��带 �湮�ߴ��� �ľ�
		if (visitbfs[i]) continue; 

		check = false;
		break;
	}

	if (check) { //��� ��带 �湮�� ���
		int sum2 = totalsum - sum1; //sum1, sum2�� �ľ�

		if (answer > abs(sum2 - sum1)) answer = abs(sum2 - sum1); //answer���� sum1 - sum2�� ������ ���� ��� �װɷ� ������Ʈ
	}

	for (int i = start + 1; i <= n; i++) { 
		if (team[i] == 1) continue;

		team[i] = 1;

		dfs(i, cnt + 1, sum1 + person[i]); //��Ʈ��ŷ ����

		team[i] = 0;
	}

	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> person[i];
		totalsum += person[i];
	}

	for (int i = 1; i <= n; i++) {
		int num;

		cin >> num;

		for (int j = 0; j < num; j++) {
			int a;
			cin >> a;
			v[i].push_back(a);
		}
	}

	for (int i = 1; i <= n; i++) {

		fill(team, team + 11, 0);
	
		team[i] = 1; //i�� û���� ��

		dfs(i, 1, person[i]);

		team[i] = 0; //i�� ������ ��
	}

	if (answer != 987654321) cout << answer; //�� ���ű��� ���� �� ���� �� �α��� ����
	else cout << "-1"; //�� ���ű��� ���� �� ���� ��

	return 0;
}