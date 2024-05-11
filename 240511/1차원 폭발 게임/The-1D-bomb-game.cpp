#include <iostream>
#include <algorithm>
using namespace std;

int n,m,board[100];

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> board[i];
    while (1) {
        int cnt=1,boom=0,tmp[100]={},idx=0;
        for (int i=0; i<n-1; i++) {
            if (board[i]==board[i+1]) {
                cnt++;
            }
            else {
                if (cnt>=m) {
                    for (int j=i-cnt+1; j<=i; j++) {
                        board[j]=0;
                        boom++;
                    }
                }
                cnt = 1;
            }
        }
        if (cnt>=m) {
            for (int i=n-cnt; i<n; i++) {
                board[i]=0;
                boom++;
            }
        }
        for (int i=0; i<n; i++) {
            if (board[i]!=0) {
                tmp[idx]=board[i];
                idx++;
            }
        }
        copy(tmp,tmp+100,board);
        n-=boom;
        if (boom==0 || n==0) break;
    }
    cout << n << '\n';
    for (int i=0; i<n; i++)
        cout << board[i] << '\n';
}