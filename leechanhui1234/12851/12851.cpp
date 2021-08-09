#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

int n, k;

int time1[100001]; //i까지의 가장 빠른 시간

struct Point {
	int node; //지금 현재 위치 값
	int count; //지금 현재 시간 값
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i <= 100000; i++) {
		time1[i] = 100001;
	}

	queue<Point> q;

	q.push({ n, 0 });

	int answer = 0; //최단 시간 방법의 수

	while (!q.empty()) {
		int node = q.front().node;
		int count = q.front().count;

		q.pop();

		if (node == k) { //현재 node 값과 k 위치가 같을 때
			answer++; //answer++
		}

		time1[node] = count; //time1[node]의 값을 count로 업뎃

		if (node - 1 >= 0) { //node - 1이 0~100000까지 범위에 존재할 때
			if (time1[node - 1] >= count + 1) { 
				time1[node - 1] = count + 1; //time값 업뎃
				q.push({ node - 1, count + 1 }); //큐에 다음원소 대입
			}
		}

		if (node + 1 <= 100000) { //node + 1이 0~100000까지 범위에 존재할 때
			if (time1[node + 1] >= count + 1) {
				time1[node + 1] = count + 1; //time값 업뎃
				q.push({ node + 1, count + 1 }); //큐에 다음원소 대입
			}
		}

		if (2 * node <= 100000) { //2 *node가 0~100000까지 범위에 존재할 때
			if (time1[2 * node] >= count + 1) {
				time1[2 * node] = count + 1; //time값 업뎃
				q.push({ 2 * node, count + 1 }); //큐에 다음원소 대입
			}
		}
	}

	cout << time1[k] << '\n' << answer; //k에서의 최단시간 값과 방법의 수 출력

	return 0;
}
