#include <iostream>
using namespace std;

int n,board[100][100],r,c,m1,m2,m3,m4,dir;

void rot(int x, int y) {
    int tmp=board[x][y];
    if (dir==1) { //시계
        int dx[4]={-1,-1,1,1},dy[4]={1,-1,-1,1};
        for (int i=0; i<m1; i++) {
            board[x][y]=board[x+dx[0]][y+dy[0]];
            x+=dx[0];
            y+=dy[0];
        }
        for (int i=0; i<m2; i++) {
            board[x][y]=board[x+dx[1]][y+dy[1]];
            x+=dx[1];
            y+=dy[1];
        }
        for (int i=0; i<m3; i++) {
            board[x][y]=board[x+dx[2]][y+dy[2]];
            x+=dx[2];
            y+=dy[2];
        }
        for (int i=0; i<m4; i++) {
            board[x][y]=board[x+dx[3]][y+dy[3]];
            x+=dx[3];
            y+=dy[3];
        }
        board[x-1][y-1]=tmp;
    }
    else { //반시계
        int dx[4]={-1,-1,1,1},dy[4]={-1,1,1,-1};
        for (int i=0; i<m4; i++) {
            board[x][y]=board[x+dx[0]][y+dy[0]];
            x+=dx[0];
            y+=dy[0];
        }
        for (int i=0; i<m3; i++) {
            board[x][y]=board[x+dx[1]][y+dy[1]];
            x+=dx[1];
            y+=dy[1];
        }
        for (int i=0; i<m2; i++) {
            board[x][y]=board[x+dx[2]][y+dy[2]];
            x+=dx[2];
            y+=dy[2];
        }
        for (int i=0; i<m1; i++) {
            board[x][y]=board[x+dx[3]][y+dy[3]];
            x+=dx[3];
            y+=dy[3];
        }
        board[x-1][y+1]=tmp;
    }
    
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) cin >> board[i][j];
    cin >> r >> c >> m1 >> m2 >> m3 >> m4 >> dir;
    rot(r-1,c-1);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++) cout << board[i][j] << ' ';
        cout << '\n';
    }
}