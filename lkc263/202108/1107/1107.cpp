#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

// 브루트포스 알고리즘
int n,m;
int data;
bool arr[11];



int decimal_confirmation(int number){
    int len = 0;
    if(number==0){
        // 0인 경우
        if(arr[0] == true) return 0;
        else return 1;
    }

    while(number > 0){
        // 만약 고장난 버튼이 존재하면 바로 나간다.
        // 고장난 버튼이 하나라도 존재하면 최소 값이 될 수가 없기 때문이다.
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

    // 브루트포스 알고리즘
    // 최소 크기에서 최대 크기까지 검사를 한다.
    // 0 <= N <= 500,000인데
    // 1000,000까지 검사하는 이유는 어떻게 될까?
    // => N의 최대값이 500,000이다.
    // => 이럴경우 초기값 : 100을 기준으로 500,000 +로만 이동한다면
    // => 500,000 - 100 = 499,900이다.
    // => 초기값 : 1000,000을 기준으로 500,000 -로만 이동한다면
    // => 1000,000 - 500,000 = 500,000이다.
    // 문제에서는 채널이 무한대만큼 있다고 하였고 버튼을 최소 몇 번 눌러야 채널 N으로 이동하는지 질문하였다.
    // 그러므로 위 예시를 보면, N이 500,000일 때를 기준으로 +-를 이용한 최소값은 499,900이다.
    // N은 이를 기준으로 1000,000 이하로 범위를 주면 된다.

    int result = abs(n-100);
    for(int i=0;i<=1000000;i++){
        int len = decimal_confirmation(i);
        if(len > 0){
            int i_n_beside = abs(i-n);   // i번에서 n번째까지 개수
            if(result > len + i_n_beside){
                result = len + i_n_beside;
            }
        }
    }

    cout << result << "\n";

    return 0;
}
