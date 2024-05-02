#include <iostream>
using namespace std;

int m,n,board[100][100],ans=0;

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) cin >> board[i][j];
    }

    for (int i=0; i<n; i++) {
        int tmp=board[i][0], cnt=1,mx=0;
        for (int j=1; j<n; j++) {
            if (board[i][j]==tmp) cnt++;
            else {
                cnt=1;
                tmp=board[i][j];
            }
            mx=max(cnt,mx);
        }
        if (mx>=m) ans++;
    }

    for (int i=0; i<n; i++) {
        int tmp=board[0][i], cnt=1,mx=0;
        for (int j=1; j<n; j++) {
            if (board[j][i]==tmp) cnt++;
            else {
                cnt=1;
                tmp=board[j][i];
            }
            mx=max(cnt,mx);
        }
        if (mx>=m) ans++;
    }

    cout << ans;

    return 0;
}