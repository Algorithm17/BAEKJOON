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

		sort(arr, arr + n); //A�迭 ����
		sort(arr2, arr2 + m); //B�迭 ����

		int ind = 0;

		int cnt = 0;

		for (int i = 0; i < n; i++) {

			if (ind == m) { // A�迭���� ���� �ε����� cnt�� m���� ���, �����ε��� ���ĵ� m���̴�.
				cnt += m;
				continue;
			}

			while (1) {
				if (ind == m) break; // ind�� m�� ��� B�迭�� ������ �̵��ߴٴ� ���̴�.
				if (arr2[ind] >= arr[i]) break; // ������ ���¿��� ���� A�ε��� ���� B�ε��� ������ �۰ų� ���ٸ� ���� �ε��� �ݺ����� �����Ѵ�.

				ind++;
			}

			cnt += ind; // ��ü Ƚ�� ���Ѵ�.
		}

		cout << cnt << endl; //cnt���
	}
	return 0;
}

