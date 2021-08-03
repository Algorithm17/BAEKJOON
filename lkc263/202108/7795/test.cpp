#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int arr[20001];
int arr2[20001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int testcase;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		int n, m;

		cin >> n >> m;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < m; i++) {
			cin >> arr2[i];
		}

		sort(arr, arr + n); //A배열 정렬
		sort(arr2, arr2 + m); //B배열 정렬

		int ind = 0;

		int cnt = 0;

		for (int i = 0; i < n; i++) {

			if (ind == m) { // A배열에서 현재 인덱스의 cnt가 m개인 경우, 현재인덱스 이후도 m개이다.
				cnt += m;
				continue;
			}

			while (1) {
				if (ind == m) break; // ind가 m인 경우 B배열의 끝까지 이동했다는 것이다.
				if (arr2[ind] >= arr[i]) break; // 정렬한 상태에서 현재 A인덱스 값이 B인덱스 값보다 작거나 같다면 현재 인덱스 반복문을 종료한다.

				ind++;
			}

			cnt += ind; // 전체 횟수 더한다.
		}

		cout << cnt << endl; //cnt출력
	}
	return 0;
}

