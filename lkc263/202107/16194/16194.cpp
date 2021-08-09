#include<iostream>
#include<algorithm>
#include<cmath>

#define NLAN 1001

using namespace std;

int N;
int minarr[NLAN];
int P[NLAN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;


    for(int i=1;i<=N;i++){
        cin >> P[i];
        minarr[i] = P[i];
        for(int j=1;j<i;j++){
            minarr[i] = min(minarr[j]+P[i-j],minarr[i]);
        }
    }


    cout << minarr[N] << "\n";


    return 0;
}


