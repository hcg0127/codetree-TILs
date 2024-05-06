#include <iostream>
using namespace std;

int n,board[3][200],t;

int main() {
    cin >> n >> t;
    for (int i=0; i<3; i++)
        for (int j=0; j<n; j++) cin >> board[i][j];
    while (t--) {
        int tmp1=board[0][n-1], tmp2=board[1][n-1], tmp3=board[2][n-1];
        for (int i=0; i<3; i++)
            for (int j=n-1; j>0; j--)
                board[i][j]=board[i][j-1];
        board[1][0]=tmp1;
        board[2][0]=tmp2;
        board[0][0]=tmp3;
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<n; j++) cout << board[i][j] << ' ';
        cout << '\n';
    }
}