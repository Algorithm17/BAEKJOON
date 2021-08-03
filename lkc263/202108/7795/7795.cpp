#include<iostream>
#include<cstdio>

using namespace std;

int T;
int n,m;
int cnt;

int arr_n[20001];
int arr_m[20001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--){
        cin >> n >> m;

        cnt = 0;
        for(int i=1;i<=n;i++) cin >> arr_n[i];
        for(int i=1;i<=m;i++) cin >> arr_m[i];


        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(arr_n[i] > arr_m[j]){
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";

    }

    return 0;
}
