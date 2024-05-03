#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,board[20][20],k=0,ans=0,dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};

int dia(int a, int b, int d) {
    queue<pair<int,int>> q;
    int visit[20][20];
    fill(&visit[0][0],&visit[20][0],0);
    int coin = board[a][b]==1 ? 1 : 0;
    q.push({a,b});
    visit[a][b]=1;
    while (!q.empty()) {
        auto [x,y] = q.front();
        q.pop();
        if (visit[x][y]>d) continue;
        for (int i=0; i<4; i++) {
            int cx=x+dx[i],cy=y+dy[i];
            if (cx<0 || cy<0 || cx>=n || cy>=n || visit[cx][cy]!=0) continue;
            q.push({cx,cy});
            visit[cx][cy]=visit[x][y]+1;
            if (board[cx][cy]==1) coin++;
        }
    }
    return coin;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            cin >> board[i][j];

    while (k<=n) {
        int tmp;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                tmp = dia(i,j,k);
                if (m*tmp >= k*k + (k+1)*(k+1))
                    ans = max(ans,tmp);
            }
        }
        k++;
    }
    cout << ans;
}