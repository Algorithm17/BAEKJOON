#include<iostream>
#include<cstdio>

using namespace std;

int n;

int day[20];
int money[20];
int dp[20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> day[i] >> money[i];
	}

	for (int i = n; i >= 1; i--) {
		if (i + day[i] > n + 1) { //�ش����� ����� �Ұ����� ��
			dp[i] = dp[i + 1];
			continue;
		}

		else { //�ش����� ����� ������ ��
			dp[i] = max(money[i] + dp[i + day[i]], dp[i + 1]);
		}
	}
	cout << dp[1]; //�ִ� ���� ���

	return 0;
}
