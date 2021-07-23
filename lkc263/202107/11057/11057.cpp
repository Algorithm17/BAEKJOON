// f(n) = f(n-1) + (f(n-1) - f(n-2)f(0)) + (f(n-1) - (f(n-2)f(0) + f(n-2)f(1))) + ~ + (f(n-1) - (f(n-2)f(0) + f(n-2)f(1) + ~ + f(n-2)f(8)))

#include <iostream>
#include <cstdio>

using namespace std;


int N; // 수의 길이
int uphill_road[1001][11]; // 자리 값
int total[1001][11];  // 총합
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);



    cin >> N;



    for(int i = 9;i >= 0;i--){
        uphill_road[1][i] = 1;

        if(i==9){
            total[1][i] = 1;
            continue;
        }


        total[1][i] += total[1][i+1] + 1;
    }

    for(int i=2;i<=N;i++){
        for(int j=9;j>=0;j--){
            uphill_road[i][j] = total[i-1][j]%10007;
            if(j==9){
                total[i][j] = 1;
                continue;
            }

            total[i][j] = (total[i][j+1]%10007 + uphill_road[i][j]%10007)%10007;
        }
    }



    printf("%d\n",total[N][0]%10007);






    return 0;
}
