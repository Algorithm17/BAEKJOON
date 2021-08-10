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
			prime[j] = false; //i를 제외한 i의 배수 지움
		}
	}

	int testcase;

	cin >> testcase;

	for (int i = 0; i < testcase; i++) {
		for (int j = 0; j <= 9999; j++) {
			visit[j] = false; //visit배열 초기화
		}

		int a, b;

		cin >> a >> b;

		int answer = 0; //두 소수사이 변환에 필요한 최소 횟수

		bool check = false;

		queue<pair<int, int> > q; //자신의 값, 변환에 필요한 최소 횟수

		q.push({ a, 0 });

		while (!q.empty()) {
			int node = q.front().first;
			int count = q.front().second;

			q.pop();

			if (node == b) { //자기자신이 b와 같은 경우
				check = true; //변환가능하다고 표시
				answer = count; //변환에 필요한 최소 횟수 업데이트
				break;
			}

			if (visit[node]) continue; //이미 방문한 경우 continue

			visit[node] = true; 

			int a1 = node / 1000;
			int a2 = (node % 1000) / 100;
			int a3 = (node % 100) / 10;
			int a4 = (node % 10);

			int arr[4] = { a1, a2, a3, a4 }; //각각의 자리를 배열에 대입

			for (int i = 0; i <= 3; i++) {
				for (int j = 0; j <= 9; j++) {
					if (i == 0 && j == 0) continue; //천의 자리인 경우 0이 오면 안되니깐 continue

					if (arr[i] == j) continue; //다음에 삽입할 요소가 자기 자신이면 안되니 continue

					int arr2[4] = { a1, a2, a3, a4 };

					arr2[i] = j; //4개의 자릿수중 하나를 j로 변환

					int num = arr2[0] * 1000 + arr2[1] * 100 + arr2[2] * 10 + arr2[3]; //배열 요소를 이용해 4자리수로 변환

					if (!prime[num]) continue; //변환한 수가 소수가 아닌 경우 continue

					q.push({ num, count + 1 }); //변환한 수가 소수인 경우
				}
			}
		}

		if (check) cout << answer << '\n'; //변환 가능한 경우 변환에 필요한 최소 횟수 출력
		else cout << "Impossible" << '\n'; //변환 불가능한 경우 Impossible을 출력
	}

	return 0;
}