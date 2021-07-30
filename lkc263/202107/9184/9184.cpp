#include<iostream>
#include<cstdio>
using namespace std;


// 그대로 구현하면 값을 구하는데 매우 오랜시간이 걸린다.
// 문제에 나와있는 코드를 실행시 시간 초과하는 이유는 똑같은 연산을 계속 반복수행하면서
// 계산을 하기 때문이다.
// 한 번 실행된 값들은 저장하기 위해 dp를 이용한다.
int dp[51][51][51];
int w(int a,int b, int c){

    if(a<=0 || b<=0 || c<=0) return 1;
    if(dp[a][b][c]) return dp[a][b][c];
    if(a > 20 || b>20 || c>20) return dp[a][b][c] = w(20,20,20);
    if(a<b && b<c) return dp[a][b][c] = (w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c));
    else return dp[a][b][c] = (w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1));

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;

    while(true){
        cin >> a >> b >> c;
        if(a == -1 && b== -1 && c ==-1) break;
        cout << "w("<<a<<", "<<b<<", "<<c<<") = "<<w(a,b,c) << "\n";
    }


    return 0;
}
