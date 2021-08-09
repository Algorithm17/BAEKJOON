#include<iostream>
#include<cstdio>

using namespace std;

int n, m;

char arr[1010][60]; //DNA 문자열들 저장

int alpabat[60][27]; //어느 알파벳이 많이 사용되었는지 파악하는 배열

char alpa[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; //그냥 알파벳 저장 문자열
char answer[100]; //해밍 거리의 합이 가장 작은 문자열 저장

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int cnt = 0; //hamming distance 개수 저장 변수
	int index = 0; //haming distance 문자열의 길이 저장 변수

	for (int i = 0; i < m; i++) {
		int ma = 0; //알파벳 빈도수의 최댓값 저장 변수
		int maind = 0; //빈도수가 가장 많은 알파벳의 인덱스 저장 변수

		for (int j = 1; j <= n; j++) {
			int ind = arr[j][i] - 'A';
			alpabat[i][ind]++;
			if (ma < alpabat[i][ind]) { //현재 저장되어 있는 최댓값보다 알파벳 빈도수가 더 많은 경우
				ma = alpabat[i][ind];
				maind = ind;
			}

			else if (ma == alpabat[i][ind]) { //현재 저장되어 있는 최댓값과 알파벳 빈도수가 동일한 경우
				if (maind > ind) { //알파벳의 아스키코드값이 더  작은 경우
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

	cout << answer << '\n'; //hamming distance 합이 가장 작은 문자열 출력

	cout << n * m - cnt; //그 때 hamming distance의 합 출력
	return 0;
}
