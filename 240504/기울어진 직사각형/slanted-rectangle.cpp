#include <iostream>
using namespace std;

int n,board[20][20],tmp,ans=0,dx[4]={-1,-1,1,1},dy[4]={1,-1,-1,1};

int rec(int a, int b, int w, int h) {
    int tmp=0;
    for (int i=0; i<w; i++) {
        a+=dx[0];
        b+=dy[0];
        if (a<0 || b<0 || a>=n || b>=n) return 0;
        tmp+=board[a][b];
    }
    for (int i=0; i<h; i++) {
        a+=dx[1];
        b+=dy[1];
        if (a<0 || b<0 || a>=n || b>=n) return 0;
        tmp+=board[a][b];
    }
    for (int i=0; i<w; i++) {
        a+=dx[2];
        b+=dy[2];
        if (a<0 || b<0 || a>=n || b>=n) return 0;
        tmp+=board[a][b];
    }
    for (int i=0; i<h; i++) {
        a+=dx[3];
        b+=dy[3];
        if (a<0 || b<0 || a>=n || b>=n) return 0;
        tmp+=board[a][b];
    }
    return tmp;
}

void sol(int a, int b) {
    int tmp;
    for (int i=1; i<n-1; i++) {
        for (int j=1; j<n-1; j++) {
            tmp = rec(a,b,i,j);
            ans = max(tmp,ans);
        }
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) cin >> board[i][j];
    for (int i=2; i<n; i++)
        for (int j=1; j<n-1; j++)
            sol(i,j);
    cout << ans;
}