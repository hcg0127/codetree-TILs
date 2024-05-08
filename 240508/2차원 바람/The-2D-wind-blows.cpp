#include <iostream>
#include <algorithm>
using namespace std;

int n,m,q,board[100][100],r1,r2,c1,c2,visit[100][100],dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};

void wind(int x1, int y1, int x2, int y2) {
    int lu=board[x1][y1],ru=board[x1][y2],ld=board[x2][y1],rd=board[x2][y2];
    for (int i=y2; i>y1; i--) board[x1][i]=board[x1][i-1];
    for (int i=x2; i>x1; i--) board[i][y2]=board[i-1][y2];
    for (int i=y1; i<y2; i++) board[x2][i]=board[x2][i+1];
    for (int i=x1; i<x2; i++) board[i][y1]=board[i+1][y1];
    
    board[x1][y1+1]=lu;
    board[x1+1][y2]=ru;
    board[x2-1][y1]=ld;
    board[x2][y2-1]=rd;
}

void mean(int x, int y) {
    int cnt=1,sum=board[x][y];
    for (int i=0; i<4; i++) {
        int cx=x+dx[i],cy=y+dy[i];
        if (cx<0 || cy<0 || cx>=n || cy>=m) continue;
        cnt++;
        sum+=board[cx][cy];
    }
    visit[x][y]=sum/cnt;
}

int main() {
    cin >> n >> m >> q;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) cin >> board[i][j];
    while (q--) {
        cin >> r1 >> c1 >> r2 >> c2;
        wind(r1-1,c1-1,r2-1,c2-1);
        fill(&visit[0][0],&visit[100][0],0);
        for (int i=r1; i<=r2; i++) {
            for (int j=c1; j<=c2; j++) {
                mean(i-1,j-1);
            }
        }
        for (int i=r1; i<=r2; i++) {
            for (int j=c1; j<=c2; j++) {
                board[i-1][j-1]=visit[i-1][j-1];
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) cout << board[i][j] << ' ';
        cout << '\n';
    }
}