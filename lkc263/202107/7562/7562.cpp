#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

int T, l;
int current_x, current_y;
int end_x,end_y;


int knight[8][2] = {{-1, 2},{-2, 1},{-2,-1},{-1, -2},{1, -2},{2, -1},{2,1},{1,2}};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;

    while(T--){
        cin >> l;

        cin >> current_x >> current_y;
        cin >> end_x >> end_y;

        int total_data = 0;
        bool visited[301][301] = {false,};
        priority_queue<pair<int,pair<int, int>>> pq;


        pq.push({0,{current_x,current_y}});

        while(!pq.empty()){
            int index_data = -pq.top().first;
            int startx = pq.top().second.first;
            int starty = pq.top().second.second;

            pq.pop();

            if(startx == end_x && starty == end_y){
                total_data = index_data;
                break;
            }

            if(visited[startx][starty]) continue;
            visited[startx][starty] = true;

            for(int i=0;i<8;i++){
                int nextx = startx + knight[i][0];
                int nexty = starty + knight[i][1];
                if(nextx < 0 || nexty < 0 || nextx >= l || nexty >= l) continue;

                if(visited[nextx][nexty]) continue;
                pq.push({-index_data-1,{nextx,nexty}});
            }



        }

        printf("%d\n",total_data);
    }





    return 0;
}
