#include<iostream>
#include<cstring>

#define NLEN 1001
#define MLEN 51

// N : DNA의 수
// M : 문자열의 길이


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
            // 현재 입력되어 있는 알파벳에서 - A를 빼준뒤
            // 숫자 값을 저장한다.
            alpa[i][dna_alpa] += 1;
            // 그 위치에 1을 더한다.
            if(maxi_dna < alpa[i][dna_alpa]){
                maxi_dna = alpa[i][dna_alpa];
                idx = dna_alpa;
            }else if(maxi_dna == alpa[i][dna_alpa]){
                if(dna_alpa < idx){  // 기존 저장되어있던 알파벳이 새로 들어온 알파벳보다 사전 순으로 작다면 변경한다.
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
