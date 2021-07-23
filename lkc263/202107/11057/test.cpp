#include<iostream>
#include<cstdio>

using namespace std;

int number[1001][11];
int total[1001][11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 9; i >= 0; i--) { //1�ڸ��� �� ���� ���
		number[1][i] = 1; //1�ڸ��̰� �� ���ڸ��� i�϶� ������
		if (i == 9) {
			total[1][i] = 1; //1�ڸ��̰� �� ���ڸ��� i ~ 9������ ������ ����
			continue;
		}

		total[1][i] = total[1][i + 1] + 1;
	}

	for (int i = 2; i <= 1000; i++) {
		for (int j = 9; j >= 0; j--) {
			number[i][j] = total[i - 1][j] % 10007; //i�ڸ��̰� �� ���ڸ��� j�϶� ������

			if (j == 9) {
				total[i][j] = 1;
				continue;
			}

			total[i][j] = (total[i][j + 1] % 10007 + number[i][j] % 10007) % 10007; //i�ڸ��̰� �� ���ڸ��� i ~ 9�����϶��� ������ ����
		}
	}



	int num;

	cin >> num;

	cout << total[num][0]; //������ ���
	return 0;
}

