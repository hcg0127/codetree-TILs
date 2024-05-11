#include <iostream>
#include <algorithm>
using namespace std;

int n,board[200][200],r,c;

void boom(int x, int y) {
    int tmp = board[x][y];
    board[x][y]=0;
    for (int i=1; i<tmp; i++) {
        if (y+i<n)
            board[x][y+i]=0;
        if (y-i>=0)
            board[x][y-i]=0;
        if (x+i<n)
            board[x+i][y]=0;
        if (x-i>=0)
            board[x-i][y]=0;
    }
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) cin >> board[i][j];
    cin >> r >> c;
    boom(r-1,c-1);
    
    for (int i=0; i<n; i++) { //열
        int tmp[200],idx=0;
        fill(tmp,tmp+200,0);
        for (int j=0; j<n; j++) { //행
            if (board[j][i]!=0) {
                tmp[idx]=board[j][i];
                idx++;
            }
        }
        for (int j=0; j<n-idx; j++) {
            board[j][i]=0;
        }
        for (int j=n-idx; j<n; j++) {
            board[j][i]=tmp[j-n+idx];
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) cout << board[i][j] << ' ';
        cout << '\n';
    }
}