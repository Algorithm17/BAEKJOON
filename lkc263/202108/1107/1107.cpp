#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

// ���Ʈ���� �˰���
int n,m;
int data;
bool arr[11];



int decimal_confirmation(int number){
    int len = 0;
    if(number==0){
        // 0�� ���
        if(arr[0] == true) return 0;
        else return 1;
    }

    while(number > 0){
        // ���� ���峭 ��ư�� �����ϸ� �ٷ� ������.
        // ���峭 ��ư�� �ϳ��� �����ϸ� �ּ� ���� �� ���� ���� �����̴�.
        if(arr[number%10]) return 0;
        number /= 10;
        len++;
    }


    return len;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> n;
    cin >> m;

    for(int i=1;i<=m;i++){
        cin >> data;
        arr[data] = true;
    }

    // ���Ʈ���� �˰���
    // �ּ� ũ�⿡�� �ִ� ũ����� �˻縦 �Ѵ�.
    // 0 <= N <= 500,000�ε�
    // 1000,000���� �˻��ϴ� ������ ��� �ɱ�?
    // => N�� �ִ밪�� 500,000�̴�.
    // => �̷���� �ʱⰪ : 100�� �������� 500,000 +�θ� �̵��Ѵٸ�
    // => 500,000 - 100 = 499,900�̴�.
    // => �ʱⰪ : 1000,000�� �������� 500,000 -�θ� �̵��Ѵٸ�
    // => 1000,000 - 500,000 = 500,000�̴�.
    // ���������� ä���� ���Ѵ븸ŭ �ִٰ� �Ͽ��� ��ư�� �ּ� �� �� ������ ä�� N���� �̵��ϴ��� �����Ͽ���.
    // �׷��Ƿ� �� ���ø� ����, N�� 500,000�� ���� �������� +-�� �̿��� �ּҰ��� 499,900�̴�.
    // N�� �̸� �������� 1000,000 ���Ϸ� ������ �ָ� �ȴ�.

    int result = abs(n-100);
    for(int i=0;i<=1000000;i++){
        int len = decimal_confirmation(i);
        if(len > 0){
            int i_n_beside = abs(i-n);   // i������ n��°���� ����
            if(result > len + i_n_beside){
                result = len + i_n_beside;
            }
        }
    }

    cout << result << "\n";

    return 0;
}
