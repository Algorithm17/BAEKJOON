#include<iostream>
#include<cstdio>
#include<queue>

using namespace std;

bool prime[10000];
bool visit[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 2; i <= 9999; i++) {
		prime[i] = true;
	}

	for (int i = 2; i <= 9999; i++) {
		for (int j = i + i; j <= 9999; j = j + i) {
			prime[j] = false; //i�� ������ i�� ��� ����
		}
	}

	int testcase;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		for (int j = 0; j <= 9999; j++) {
			visit[j] = false; //visit�迭 �ʱ�ȭ
		}

		int a, b;

		cin >> a >> b;

		int answer = 0; //�� �Ҽ����� ��ȯ�� �ʿ��� �ּ� Ƚ��

		bool check = false;

		queue<pair<int, int> > q; //�ڽ��� ��, ��ȯ�� �ʿ��� �ּ� Ƚ��

		q.push({ a, 0 });

		while (!q.empty()) {
			int node = q.front().first;
			int count = q.front().second;

			q.pop();

			if (node == b) { //�ڱ��ڽ��� b�� ���� ���
				check = true; //��ȯ�����ϴٰ� ǥ��
				answer = count; //��ȯ�� �ʿ��� �ּ� Ƚ�� ������Ʈ
				break;
			}

			if (visit[node]) continue; //�̹� �湮�� ��� continue

			visit[node] = true; 

			int a1 = node / 1000;
			int a2 = (node % 1000) / 100;
			int a3 = (node % 100) / 10;
			int a4 = (node % 10);

			int arr[4] = { a1, a2, a3, a4 }; //������ �ڸ��� �迭�� ����

			for (int i = 0; i <= 3; i++) {
				for (int j = 0; j <= 9; j++) {
					if (i == 0 && j == 0) continue; //õ�� �ڸ��� ��� 0�� ���� �ȵǴϱ� continue

					if (arr[i] == j) continue; //������ ������ ��Ұ� �ڱ� �ڽ��̸� �ȵǴ� continue

					int arr2[4] = { a1, a2, a3, a4 };

					arr2[i] = j; //4���� �ڸ����� �ϳ��� j�� ��ȯ

					int num = arr2[0] * 1000 + arr2[1] * 100 + arr2[2] * 10 + arr2[3]; //�迭 ��Ҹ� �̿��� 4�ڸ����� ��ȯ

					if (!prime[num]) continue; //��ȯ�� ���� �Ҽ��� �ƴ� ��� continue

					q.push({ num, count + 1 }); //��ȯ�� ���� �Ҽ��� ���
				}
			}
		}

		if (check) cout << answer << '\n'; //��ȯ ������ ��� ��ȯ�� �ʿ��� �ּ� Ƚ�� ���
		else cout << "Impossible" << '\n'; //��ȯ �Ұ����� ��� Impossible�� ���
	}

	return 0;
}