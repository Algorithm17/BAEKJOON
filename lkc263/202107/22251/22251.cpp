#include<iostream>
#include<cstdio>
#include<cmath>


using namespace std;

// 0 ~ 9까지 배열로 처리
int number[10][7] = {
    {1,1,1,0,1,1,1},
    {0,0,0,0,0,1,1},
    {0,1,1,1,1,1,0},
    {0,0,1,1,1,1,1},
    {1,0,0,1,0,1,1},
    {1,0,1,1,1,0,1},
    {1,1,1,1,1,0,1},
    {0,0,1,0,0,1,1},
    {1,1,1,1,1,1,1},
    {1,0,1,1,1,1,1}
};


int main(){
    int N, K, P, X;
    scanf("%d %d %d %d",&N,&K,&P,&X);
    int input_arr[K];
    int X_data = X;
    int result=0;
    for(int i=K-1;i >=0;i--){
        input_arr[i] = X_data % 10;
        X_data /= 10;
    }



    for(int N_data=1;N_data<=N;N_data++){
        if(N_data == X) continue;
        int p_count = 0;
        int data = N_data;
        for(int in_data = 0;in_data<K;in_data++){
            int to_n = pow(10,K-in_data-1);
            int N_num = data / to_n;
            for(int index = 0;index<7;index++){
                if( number[input_arr[in_data]][index]!= number[N_num][index]){
                        p_count++;
                }
            }
            data %= to_n;
        }

        if(p_count <= P){
            result++;
        }

    }

    printf("%d\n",result);


    return 0;
}
