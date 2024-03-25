#include <iostream>
#include <algorithm>
using namespace std;

int n,board[20][20],mx=0;

int cnt(int x, int y) {
    int tmp=0;
    for (int i=x; i<x+3; i++) {
        for (int j=y; j<y+3; j++) {
            if (board[i][j]==1) tmp++;
        }
    }
    return tmp;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> board[i][j];
        }
    }
    for (int i=0; i<n-2; i++) {
        for (int j=0; j<n-2; j++) {
            mx=max(mx,cnt(i,j));
        }
    }
    cout << mx;
    
    return 0;
}