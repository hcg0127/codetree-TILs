#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,board[100],s1,e1,s2,e2,tmp[100];
vector<int> v;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> board[i];
    cin >> s1 >> e1 >> s2 >> e2;
    for (int i=s1; i<=e1; i++) board[i-1]=0;
    
    int idx=0;
    for (int i=0; i<n; i++) {
        if (board[i]!=0) {
            tmp[idx]=board[i];
            idx++;
        }
    }
    copy(tmp,tmp+100,board);
    n-=e1-s1+1;
    for (int i=s2; i<=e2; i++) board[i-1]=0;
    for (int i=0; i<n; i++) {
        if (board[i]!=0) v.push_back(board[i]);
    }
    n-=e2-s2+1;
    cout << n << '\n';
    for (auto i:v) cout << i << '\n';
}