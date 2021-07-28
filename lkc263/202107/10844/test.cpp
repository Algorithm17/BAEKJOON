#include<iostream>
#include<cstdio>
#define MOD 1000000000

using namespace std;

long long int dp[101][11];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (i == 1) {
				dp[i][j] = 1;
				continue;
			}

			if(j - 1 < 0){
				dp[i][j] = dp[i - 1][j + 1] % MOD;
				continue;
			}

			if (j + 1 >= 10) {
				dp[i][j] = dp[i - 1][j - 1] % MOD;
				continue;
			}

			dp[i][j] = (dp[i - 1][j - 1] % MOD + dp[i - 1][j + 1] % MOD) % MOD;
		}
	}

	long long int answer = 0;

	for (int j = 1; j <= 9; j++) {
		answer = (answer % MOD + dp[n][j] % MOD) % MOD;
	}

	cout << answer;
	return 0;
}
