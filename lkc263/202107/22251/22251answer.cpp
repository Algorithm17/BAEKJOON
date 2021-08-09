#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int arr[10][8] = {
	{1,1,1,1,1,1,0}, //0�� LED
	{0,0,0,0,1,1,0}, //1�� LED
	{1,0,1,1,0,1,1}, //2�� LED
	{1,0,0,1,1,1,1}, //3�� LED
	{0,1,0,0,1,1,1}, //4�� LED
	{1,1,0,1,1,0,1}, //5�� LED
	{1,1,1,1,1,0,1}, //6�� LED
	{1,0,0,0,1,1,0}, //7�� LED
	{1,1,1,1,1,1,1}, //8�� LED
	{1,1,0,1,1,1,1}  //9�� LED
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k, p, x;

	cin >> n >> k >> p >> x;

	int answer = 0;

	for (int i = 1; i <= n; i++) {
		if (i == x) continue;

		int count = 0;

		int num1 = i;
		int num2 = x;

		int index = k;

		while (1) { //�� �ڸ������� ���ϴ� �˰���
			if (index == 0) break;

			int num = pow(10, index - 1);

			int n1 = num1 / num;
			int n2 = num2 / num;

			for (int j = 0; j <= 6; j++) {
				if (arr[n1][j] != arr[n2][j]) count++;
			}

			num1 %= num;
			num2 %= num;

			index--;
		}

		if (count <= p) { //count�� p������ �۰ų� ���� ��
			answer++; //answer++������
		}
	}

	cout << answer;
	return 0;
}

