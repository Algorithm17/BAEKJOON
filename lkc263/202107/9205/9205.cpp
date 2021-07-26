#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int t, n, x, y;

int home_x,home_y;
int convenience_store_x[101];
int convenience_store_y[101];
int festival_x, festival_y;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while(t--){
        cin >> n;
        home_x = 0;
        home_y = 0;

        for(int i=0;i<n;i++){
            cin >> x >> y;
            convenience_store_x[i] = x;
            convenience_store_y[i] = y;

        }

        cin >> festival_x >> festival_y;
        int before_x = 0;
        int before_y = 0;

        for(int i=0;i<n;i++){
            if(abs(convenience_store_x[i] - home_x + convenience_store_y[i] - home_y) < 1000){
                before_x = convenience_store_x[i];
                before_y = convenience_store_y[i];
            }
            else if(abs(convenience_store_x[i] - home_x + convenience_store_y[i] - home_y) > 1000){
                home_x = before_x;
                home_y = before_y;
            }
        }
    }

    return 0;
}
