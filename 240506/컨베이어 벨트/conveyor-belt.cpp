#include <iostream>
using namespace std;

int n,t,board[2][200];

int main() {
    cin >> n >> t;
    for (int i=0; i<2; i++)
        for (int j=0; j<n; j++) cin >> board[i][j];
    while (t--) {
        int tmp1=board[0][n-1];
        int tmp2=board[1][n-1];
        for (int i=n-1; i>0; i--) {
            board[1][i]=board[1][i-1];
        }
        for (int i=n-1; i>0; i--) {
            board[0][i]=board[0][i-1];
        }
        board[1][0]=tmp1;
        board[0][0]=tmp2;
    }
    for (int i=0; i<2; i++) {
        for (int j=0; j<n; j++) cout << board[i][j] << ' ';
        cout << '\n';
    }
}