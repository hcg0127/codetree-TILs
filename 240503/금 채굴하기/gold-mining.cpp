#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n,m,board[20][20],k=0,ans=0,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int bfs(int a, int b, int d) {
    queue<pair<int,int>> q;
    bool visit[20][20]={};
    int coin = (board[a][b]==1 ? 1 : 0);
    fill(&visit[0][0],&visit[20][0],false);
    q.push({a,b});
    visit[a][b]=true;
    while (d--) {
        auto [x,y] = q.front();
        q.pop();
        for (int i=0; i<4; i++) {
            int cx=x+dx[i],cy=y+dy[i];
            if (cx<0 || cy<0 || cx>=n || cy>=n || visit[cx][cy]) continue;
            q.push({cx,cy});
            visit[cx][cy]=true;
            if (board[cx][cy]==1) coin++;
        }
    }
    return coin;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++) cin >> board[i][j];
    while (k<n) {
        int tmp;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                tmp = bfs(i,j,k);
                if (m*tmp >= k*k + (k+1)*(k+1))
                    ans = max(ans,tmp);
            }
        }
        k++;
    }
    cout << ans;
}