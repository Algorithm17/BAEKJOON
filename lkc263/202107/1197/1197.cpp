#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;


int main(){

    vector<vector<int>> vc;
    vector<int> vc_result;
    vector<int> vc_trunk;


    int V, E;

    cin >> V >> E;

    // V : 정점의 개수, E : 간선의 개수


    for(int i=0;i<=V;i++){
        vc_result.push_back(0);
        vector<int> vc2;
        for(int j=0;j<=V;j++){
            vc2.push_back(0);
        }
        vc.push_back(vc2);
    }

    int dot1,dot2,trunk;
    int min_trunk = 99999;
    for(int i=0;i<E;i++){
        cin >> dot1 >>dot2>>trunk;
        vc[dot1][dot2] = trunk;
        vc[dot2][dot1] = trunk;
        vc_trunk.push_back(trunk);
    }



    sort(vc_trunk.begin(),vc_trunk.end());
    vc_trunk.erase(unique(vc_trunk.begin(),vc_trunk.end()),vc_trunk.end());






    int E_size = E;
    int trunk_index = 0;

    while(E_size--){
        int count = 0;

        for(int i = 1;i<=V;i++ ){

            for(int j=1;j<=V;j++){
                if(vc[i][j]==vc_trunk[trunk_index]){
                    count++;
                    if(vc_result[i] != j){
                        vc_result[i] = j;
                    }

                }
            }

        }

        if(count >0) count /= 2;


        while(count > 0){

        }


    }







    return 0;
}
