#include<iostream>
#include<cstdio>

using namespace std;

int n;

int arr[11][11];

bool visit[15];

int answer = 1000000000;

int start;

void backtracking(int cnt, int ind, int pay) {
	if (cnt == n) {
		pay = pay + arr[ind][start];

		if (arr[ind][start] == 0) return;

		if (answer > pay) answer = pay;

		cout << "��� : "<<answer<<" "<<pay << "\n\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;

		if (arr[ind][i] == 0) continue;

		visit[i] = true; //�ϴ� �湮

		cout << "�湮 : " << i<<" �� �ε���  " << arr[ind][i] << " �� �湮Ƚ�� : " << cnt <<" ���� �ε���"<< ind <<" "<<pay<< "\n";
		backtracking(cnt + 1, i, pay + arr[ind][i]); //���� ���� ���� ��Ʈ��ŷ�� ����

		cout << "���� : " << i<<" �� �ε���  " << arr[ind][i] << " �� �湮Ƚ�� : " << cnt <<" ���� �ε���"<< ind <<" "<<pay <<"\n";
		visit[i] = false; //��Ʈ��ŷ �Ϸ� �� �湮���� ���� ���� ��ȯ
	}
	cout << "���"<<"\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		fill(visit, visit + 11, false); //visit�迭�� false�� �ʱ�ȭ

		visit[i] = true; //�ϴ� �湮�ϰ� ���� ����!

		start = i; //���� ��尡 ����� ����

		backtracking(1, i, 0); //���� ������ ��Ʈ��ŷ ����
	}

	cout << answer; //�ּ� ��� ���
	return 0;
}
