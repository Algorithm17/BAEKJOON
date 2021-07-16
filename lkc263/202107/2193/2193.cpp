// 규칙
// n번째
// n = (n-1)때 나온 개수 + (n-2)때 나온 개수

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    vector<long long> vc;

    int N = 0;
    long long result = 0;

    cin >> N;

    vc.push_back(1);
    vc.push_back(1);

    for(int i=2;i<N;i++){
        vc.push_back(vc[i-1]+vc[i-2]);
    }


    result = vc[N-1];

    printf("%lld\n",result);


    return 0;
}
