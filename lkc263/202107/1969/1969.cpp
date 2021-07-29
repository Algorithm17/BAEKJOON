#include<iostream>
#include<cstring>

#define NLEN 1001
#define MLEN 51

// N : DNA�� ��
// M : ���ڿ��� ����


using namespace std;

int n,m;
int cnt;
char alpabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int alpa[MLEN][27];
char dna_data[NLEN][MLEN];




int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string result;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> dna_data[i];
    }

    for(int i=0;i<m;i++){
        int maxi_dna = 0;
        int idx = 0;
        for(int j=0;j<n;j++){
            int dna_alpa = dna_data[j][i]-'A';
            // ���� �ԷµǾ� �ִ� ���ĺ����� - A�� ���ص�
            // ���� ���� �����Ѵ�.
            alpa[i][dna_alpa] += 1;
            // �� ��ġ�� 1�� ���Ѵ�.
            if(maxi_dna < alpa[i][dna_alpa]){
                maxi_dna = alpa[i][dna_alpa];
                idx = dna_alpa;
            }else if(maxi_dna == alpa[i][dna_alpa]){
                if(dna_alpa < idx){  // ���� ����Ǿ��ִ� ���ĺ��� ���� ���� ���ĺ����� ���� ������ �۴ٸ� �����Ѵ�.
                    idx = dna_alpa;
                    maxi_dna = alpa[i][dna_alpa];
                }
            }
        }

        result += alpabet[idx];
        cnt += maxi_dna;

    }

    cout << result <<"\n";
    cout << n*m-cnt << "\n";


    return 0;
}
