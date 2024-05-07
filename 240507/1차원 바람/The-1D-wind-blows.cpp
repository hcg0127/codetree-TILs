#include <iostream>
using namespace std;

int n,m,q,board[100][100],r,dr;
char d;

void propa(int row, int test, int dir, int mode);
void wind(int row, int dir, int mode);

void propa(int row, int test, int dir, int mode) {
    bool flag = false;
    for (int i=0; i<m; i++) {
        if (board[row][i]==board[test][i]) {
            flag=true;
            break;
        }
    }
    if (flag) {
        if (mode==1) wind(test,(dir+1)%2,1);
        else if (mode==2) wind(test,(dir+1)%2,2);
    }
}

void wind(int row, int dir, int mode) {
    if (dir == 1) {
        int tmp = board[row][m-1];
        for (int i=m-1; i>0; i--) board[row][i]=board[row][i-1];
        board[row][0] = tmp;
    }
    else {
        int tmp = board[row][0];
        for (int i=0; i<m-1; i++) board[row][i]=board[row][i+1];
        board[row][m-1] = tmp;
    }
    if (mode==0) {
        if (row-1>=0) propa(row,row-1,dir,1);
        if (row+1<n) propa(row,row+1,dir,2);
    }
    else if (mode==1) {
        if (row-1>=0) propa(row,row-1,dir,1);
    }
    else {
        if (row+1<n) propa(row,row+1,dir,2);
    }
}

int main() {
    cin >> n >> m >> q;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) cin >> board[i][j];
    cin >> r >> d;
    dr = (d=='L') ? 1 : 0;

    while (q--) {
        wind(r-1,dr,0);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cout << board[i][j] << ' ';
        cout << '\n';
    }
}