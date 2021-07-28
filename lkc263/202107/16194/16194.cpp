#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int vc[1001][1];
int result;
int P[1001];

int N;
int find_check;

int main(){

    cin >> N;

    for(int i=1;i<=N;i++){
        cin >> P[i];
        if(N % i == 0){
            vc[i][0] = N/i;
        }
    }

    result = 999999;
    int test_n = N;

    for(int i=1;i<=N;i++){
        if(N % i == 0 && result > vc[i][0] * P[i]){
            result = vc[i][0] * P[i];
        }
    }

    cout << result <<"\n";

    return 0;
}


