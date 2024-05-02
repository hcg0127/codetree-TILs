#include <iostream>
using namespace std;

int n,m,board[200][200],mx=0,tmp;

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cin >> board[i][j];
    }
    // ㅡ
    for (int i=0; i<n; i++) {
        for (int j=0; j<m-2; j++) {
            tmp = board[i][j] + board[i][j+1] + board[i][j+2];
            mx = max(tmp,mx);
        }
    }
    // ㅣ
    for (int i=0; i<n-2; i++) {
        for (int j=0; j<m; j++) {
            tmp = board[i][j] + board[i+1][j] + board[i+2][j];
            mx = max(tmp,mx);
        }
    }
    // ㄴ
    for (int i=1; i<n; i++) {
        for (int j=0; j<m-1; j++) {
            tmp = board[i][j] + board[i-1][j] + board[i][j+1];
            mx = max(tmp,mx);
        }
    }
    // ㄱ
    for (int i=0; i<n-1; i++) {
        for (int j=1; j<m; j++) {
            tmp = board[i][j] + board[i][j-1] + board[i+1][j];
            mx = max(tmp,mx);
        }
    }
    // ㄱ mirror
    for (int i=0; i<n-1; i++) {
        for (int j=0; j<m-1; j++) {
            tmp = board[i][j] + board[i][j+1] + board[i][j+1];
            mx = max(tmp,mx);
        }
    }
    // ㄴ mirror
    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            tmp = board[i][j] + board[i+1][j-1] + board[i+1][j-1];
            mx = max(tmp,mx);
        }
    }
    cout << mx;
}