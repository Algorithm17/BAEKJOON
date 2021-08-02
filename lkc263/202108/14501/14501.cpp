#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;


int n;
int T[16];
int P[16];
int dp[16];
int ma_cnt=0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> T[i] >> P[i];
    }

    for(int i=1;i<=n;i++){
        if(i+T[i]> n) continue; // 범위를 넘어섰다면

        dp[i] = P[i];

        for(int j= i; j+T[j]<=n;j+=T[j]){
            dp[i] += P[j];
            cout << j << " " << P[j] << " "<<dp[i]<<"\n";

        }

        ma_cnt = max(ma_cnt,dp[i]);

    }


    cout << ma_cnt << "\n";


    return 0;
}
