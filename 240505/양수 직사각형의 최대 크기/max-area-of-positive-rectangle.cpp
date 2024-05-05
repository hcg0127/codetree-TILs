#include <iostream>
using namespace std;

int n,m,board[20][20],ans=-1;

int sol(int a, int b, int c, int d) {
    int tmp = 0;
    for (int i=a; i<=c; i++) {
        for (int j=b; j<=d; j++) {
            if (board[i][j]>0)
                tmp++;
            else return -1;
        }
    } 
    return tmp;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) cin >> board[i][j];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<n; k++) {
                for (int l=0; l<m; l++) {
                    ans = max(ans,sol(i,j,k,l));
                }
            }
        }
    }
    cout << ans;
}