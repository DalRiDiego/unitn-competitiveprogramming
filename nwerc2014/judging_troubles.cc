#include<iostream>
#include<unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> m;
    int N;
    while(cin>>N) {
        m.clear();
        string a;
        int res = 0;
        for(int i=0;i<N;i++) {
            cin>>a;
            m[a]++;
        }
        for(int i=0;i<N;i++) {
            cin>>a;
            if(m[a]>0) { m[a]--; res++; }
        }
        cout<<res<<endl;
    }
    return 0;
}
