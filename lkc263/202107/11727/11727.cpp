#include<iostream>
#include<cstdio>

#define BALANCE 10007

using namespace std;


int n, result;
int rectangle[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    rectangle[1] = 1;
    rectangle[2] = 3;

    for(int i=3;i<=1000;i++){
        rectangle[i] = (rectangle[i-1]+rectangle[i-2]+rectangle[i-2])%BALANCE;
    }

    cin >> n;


    cout << rectangle[n] % BALANCE;






    return 0;
}
