// f(n) = f(n-1) + (f(n-1) - f(n-2)f(0)) + (f(n-1) - (f(n-2)f(0) + f(n-2)f(1))) + ~ + (f(n-1) - (f(n-2)f(0) + f(n-2)f(1) + ~ + f(n-2)f(8)))

#include <iostream>
#include <cstdio>

using namespace std;


int N; // 수의 길이
int uphill_road[1001];
int uphill_road_secondary[1001][10];  // 오르막 수 개수

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    cin >> N;


    for(int i =0;i<10;i++){
        uphill_road_secondary[1][i] = 1;
    }

    for(int i=2;i<=N;i++){
        int sum = 0;
        int result =0 ;
        for(int j=0;j<10;j++){
            sum += uphill_road_secondary[i-1][j];
            uphill_road_secondary[i][j] = uphill_road[i-1] - sum;
            result += uphill_road_secondary[i][j];
        }
        uphill_road[i] = (uphill_road[i-1] + result)%10007;
    }

    printf("%d\n",uphill_road[N]);








    return 0;
}
