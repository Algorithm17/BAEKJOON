// 카드게임
// 1) 왼쪽카드만 통에 버리거나, 두개다 통제로 버림 (이때, 점수가 없다.)
// 2) 왼쪽카드 > 오른쪽 카드 일 때
// - 오른쪽 카드만 통에 버림
// - 오른쪽 카드 적힌 수만큼 점수를 얻는다.
// 3) 어느쪽이든 남은 카드가 없다면 게임이 끝나며 그때가지 얻은 점수의 합이 최종점수

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){

    vector<int> vc_A;
    vector<int> vc_B;


    int N;
    int A, B;
    int result_sum = 0;

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> A;
        vc_A.push_back(A);
    }
    for(int i=0;i<N;i++){
        cin >> B;
        vc_B.push_back(B);
    }

    // 인덱스 구함
    int A_max = max_element(vc_A.begin(),vc_A.end())-vc_A.begin();
    int B_index = 0;


    while(A_max < N && B_index<N){
        if(vc_A[A_max] > vc_B[B_index]){
            result_sum += vc_B[B_index];
            B_index++;
        }
        else if(vc_A[A_max] <= vc_B[B_index]){
            A_max +=1;
            for(int i=A_max;i<N;i++){
                if(vc_A[i] > vc_A[A_max]){
                    A_max = i;
                }
            }
            B_index++;
        }

    }

    printf("%d\n",result_sum);





    return 0;
}
