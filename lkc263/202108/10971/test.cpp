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

		cout << "결과 : "<<answer<<" "<<pay << "\n\n";
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visit[i]) continue;

		if (arr[ind][i] == 0) continue;

		visit[i] = true; //일단 방문

		cout << "방문 : " << i<<" 열 인덱스  " << arr[ind][i] << " 총 방문횟수 : " << cnt <<" 현재 인덱스"<< ind <<" "<<pay<< "\n";
		backtracking(cnt + 1, i, pay + arr[ind][i]); //다음 노드로 가서 백트래킹을 수행

		cout << "나옴 : " << i<<" 열 인덱스  " << arr[ind][i] << " 총 방문횟수 : " << cnt <<" 현재 인덱스"<< ind <<" "<<pay <<"\n";
		visit[i] = false; //백트래킹 완료 후 방문하지 않은 노드로 변환
	}
	cout << "출력"<<"\n";
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
		fill(visit, visit + 11, false); //visit배열을 false로 초기화

		visit[i] = true; //일단 방문하고 다음 노드로!

		start = i; //시작 노드가 어딘지 저장

		backtracking(1, i, 0); //다음 노드부터 백트래킹 수행
	}

	cout << answer; //최소 비용 출력
	return 0;
}
