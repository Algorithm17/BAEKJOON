#include<iostream>
#include<cstdio>
using namespace std;


// �״�� �����ϸ� ���� ���ϴµ� �ſ� �����ð��� �ɸ���.
// ������ �����ִ� �ڵ带 ����� �ð� �ʰ��ϴ� ������ �Ȱ��� ������ ��� �ݺ������ϸ鼭
// ����� �ϱ� �����̴�.
// �� �� ����� ������ �����ϱ� ���� dp�� �̿��Ѵ�.
int dp[51][51][51];
int w(int a,int b, int c){

    if(a<=0 || b<=0 || c<=0) return 1; //����� ������ �ʿ� ���� 0���ϴ� �迭 �ε����� �� �� ����.
    if(dp[a][b][c]) return dp[a][b][c]; // ����Ǿ� �ִ� ���̸� �״�� ��ȯ�Ѵ�.
    if(a > 20 || b>20 || c>20) return dp[a][b][c] = w(20,20,20); // ������� dp �ε��� �ڸ��� �ִ´�.
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