// ī�����
// 1) ����ī�常 �뿡 �����ų�, �ΰ��� ������ ���� (�̶�, ������ ����.)
// 2) ����ī�� > ������ ī�� �� ��
// - ������ ī�常 �뿡 ����
// - ������ ī�� ���� ����ŭ ������ ��´�.
// 3) ������̵� ���� ī�尡 ���ٸ� ������ ������ �׶����� ���� ������ ���� ��������

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

    // �ε��� ����
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
