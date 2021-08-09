#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;


int n;
int T[17];
int P[17];
int dp[17];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> T[i] >> P[i];
    }


    for(int i=n;i>0;i--){
        if(i+T[i]-1>n){ // 범위를 벗어났을 때(상담할 수 없을 때)
            dp[i] = dp[i+1];
        }
        else{  // 상담 가능할 때
            dp[i] = max(P[i]+dp[i+T[i]],dp[i+1]);
        }
    }

    cout << dp[1] <<"\n";


    return 0;
}
