#include<iostream>
#include<cstdio>

using namespace std;

int n, m;

char arr[1010][60]; //DNA ���ڿ��� ����

int alpabat[60][27]; //��� ���ĺ��� ���� ���Ǿ����� �ľ��ϴ� �迭

char alpa[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //�׳� ���ĺ� ���� ���ڿ�
char answer[100]; //�ع� �Ÿ��� ���� ���� ���� ���ڿ� ����

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int cnt = 0; //hamming distance ���� ���� ����
	int index = 0; //haming distance ���ڿ��� ���� ���� ����

	for (int i = 0; i < m; i++) {
		int ma = 0; //���ĺ� �󵵼��� �ִ� ���� ����
		int maind = 0; //�󵵼��� ���� ���� ���ĺ��� �ε��� ���� ����

		for (int j = 1; j <= n; j++) {
			int ind = arr[j][i] - 'A';
			alpabat[i][ind]++;
			if (ma < alpabat[i][ind]) { //���� ����Ǿ� �ִ� �ִ񰪺��� ���ĺ� �󵵼��� �� ���� ���
				ma = alpabat[i][ind];
				maind = ind;
			}

			else if (ma == alpabat[i][ind]) { //���� ����Ǿ� �ִ� �ִ񰪰� ���ĺ� �󵵼��� ������ ���
				if (maind > ind) { //���ĺ��� �ƽ�Ű�ڵ尪�� ��  ���� ���
					ma = alpabat[i][ind];
					maind = ind;
				}
			}
		}

		answer[index] = alpa[maind];

		cnt += ma;

		index++;
	}

	answer[index] = '\0';

	cout << answer << '\n'; //hamming distance ���� ���� ���� ���ڿ� ���

	cout << n * m - cnt; //�� �� hamming distance�� �� ���
	return 0;
}
