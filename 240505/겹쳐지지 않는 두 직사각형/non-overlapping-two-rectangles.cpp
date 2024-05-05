#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,board[5][5],ans=-300000,r1,r2;


int sol(int a, int b, int c, int d) {
    int tmp=0;
    for (int i=a; i<=c; i++) {
        for (int j=b; j<=d; j++) {
            tmp+=board[i][j];
        }
    }
    return tmp;
}

int rec(int a, int b, int mode) {
    int tmp = -300000;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=i; k<n; k++) {
                for (int l=j; l<m; l++) {
                    if (mode==0) {
                        r1 = sol(i,j,k,l);
                        r2 = rec(k,l,1);
                        if (r2!=-300000) ans = max(ans,r1 + r2);
                    }
                    else {
                        if (a<i || b<j) tmp = max(tmp,sol(i,j,k,l));
                    }
                }
            }
        }
    }
    if (mode==0) return ans;
    else return tmp;
}

int main() {
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) cin >> board[i][j];
    cout << rec(0,0,0);
}