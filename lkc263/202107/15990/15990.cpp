#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    int T;
    int n;
    long long result;
    int div = 1000000009;
    vector < vector <long long> > vc;




    for(int i=0;i<=100001;i++){
        vector<long long> vc2;
        vc2.push_back(0);
        vc2.push_back(0);
        vc2.push_back(0);
        vc.push_back(vc2);
    }

    vc[1][0]=1;
    vc[2][1] = 1;
    vc[3][0] = 1;
    vc[3][1] = 1;
    vc[3][2] = 1;


    for(int i=4;i<=100001;i++){
        vc[i][0] = (vc[i-1][1]+vc[i-1][2])%div;
        vc[i][1] = (vc[i-2][0]+vc[i-2][2])%div;
        vc[i][2] = (vc[i-3][0]+vc[i-3][1])%div;
    }

    cin >> T;

    while(T--){
        cin >> n;
        result = (vc[n][0]+vc[n][1]+vc[n][2])%div;
        printf("%d\n",result);
    }




    return 0;
}
