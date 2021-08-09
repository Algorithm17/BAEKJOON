#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>

using namespace std;

int n, k;

int time1[100001]; //i������ ���� ���� �ð�

struct Point {
	int node; //���� ���� ��ġ ��
	int count; //���� ���� �ð� ��
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

	int answer = 0; //�ִ� �ð� ����� ��

	while (!q.empty()) {
		int node = q.front().node;
		int count = q.front().count;

		q.pop();

		if (node == k) { //���� node ���� k ��ġ�� ���� ��
			answer++; //answer++
		}

		time1[node] = count; //time1[node]�� ���� count�� ����

		if (node - 1 >= 0) { //node - 1�� 0~100000���� ������ ������ ��
			if (time1[node - 1] >= count + 1) { 
				time1[node - 1] = count + 1; //time�� ����
				q.push({ node - 1, count + 1 }); //ť�� �������� ����
			}
		}

		if (node + 1 <= 100000) { //node + 1�� 0~100000���� ������ ������ ��
			if (time1[node + 1] >= count + 1) {
				time1[node + 1] = count + 1; //time�� ����
				q.push({ node + 1, count + 1 }); //ť�� �������� ����
			}
		}

		if (2 * node <= 100000) { //2 *node�� 0~100000���� ������ ������ ��
			if (time1[2 * node] >= count + 1) {
				time1[2 * node] = count + 1; //time�� ����
				q.push({ 2 * node, count + 1 }); //ť�� �������� ����
			}
		}
	}

	cout << time1[k] << '\n' << answer; //k������ �ִܽð� ���� ����� �� ���

	return 0;
}
