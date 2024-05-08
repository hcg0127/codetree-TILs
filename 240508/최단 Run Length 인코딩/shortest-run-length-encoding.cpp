#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string a;
int ss,mn=100;
vector<char> v;

void cnt() {
    int tmp=1;
    for (int i=0; i<ss-1; i++) {
        if (a[i]==a[i+1]) {
            tmp++;
        }
        else {
            v.push_back(a[i]);
            if (tmp<10) v.push_back(tmp+'0');
            else {
                string str = to_string(tmp+'0');
                v.push_back(str[0]);
                v.push_back(str[1]);
            }
            tmp=1;
        }
    }
    v.push_back(a[ss-1]);
    if (tmp<10) v.push_back(tmp+'0');
    else {
        string str = to_string(tmp+'0');
        v.push_back(str[0]);
        v.push_back(str[1]);
    }
}

int main() {
    cin >> a;
    ss=a.size();
    
    for (int i=0; i<ss; i++) {
        cnt();
        int tmp = v.size();
        mn = min(mn,tmp);
        v.clear();
        char b = a[ss-1];
        a.pop_back();
        reverse(a.begin(),a.end());
        a.push_back(b);
        reverse(a.begin(),a.end());
    }
    cout << mn;
}