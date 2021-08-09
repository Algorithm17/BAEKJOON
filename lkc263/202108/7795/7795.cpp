#include<iostream>
#include<cstdio>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

int T;
int n,m;
int cnt,idx;


int arr[20001];
int arr2[20001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--){
        cin >> n >> m;
        int n_data;
        int m_data;



        for(int i=1;i<=n;i++) {
            cin >> arr[i];
        }
        for(int i=1;i<=m;i++){
            cin >> arr2[i];
        }

        sort(arr+1,arr+n+1,greater<>());
        sort(arr2+1,arr2+m+1,greater<>());



        cnt = 0;
        idx = 0;

        for(int i=1;i<=n;i++){
            if(arr[i] > arr2[1]){
                cnt += m;
                continue;
            }

            idx = m;
            while(true){
                if(idx==0) break;
                if(arr[i] <= arr2[idx--])break;
                cnt +=1;

            }
        }

        cout << cnt << "\n";


    }

    return 0;
}
