#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    vector<int> vc_square;

    int N;

    cin >> N;


    for(int i=0;i<=N;i++){
        vc_square.push_back(i);
    }


    for(int i=2;i<=N;i++){
        for(int j=2;j*j<=i;j++){
                vc_square[i] = min(vc_square[i],vc_square[i-j*j]+1);
        }

    }

    printf("%d",vc_square[N]);





    return 0;

}
