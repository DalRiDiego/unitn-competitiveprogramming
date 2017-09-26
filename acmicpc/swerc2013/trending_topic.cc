#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<set>
#include<map>
#include<vector>
#include<stack>
#include<cmath>
#include<string>
#include<algorithm>

using namespace std;

typedef long long ll;

const int MAXN=200000+100;
int n;
string str;
vector<string>vec[7];
struct node{
    int cnt;
    string s;
}nod[MAXN];
map<string,int>mp;

bool cmp(node a,node b){
    if(a.cnt == b.cnt)
        return a.s<b.s;
    return a.cnt>b.cnt;
}
int main()
{

    int now=0;
    for(int i=0;i<7;i++) vec[i].clear();
    while(cin>>str){
        if(str=="<text>"){
            vec[now].clear();
            while(cin>>str){
                if(str=="</text>")
                    break;
                if(str.length()<4)
                    continue;
                vec[now].push_back(str);
            }
            now=(now+1)%7;
        }
        else{
            mp.clear();
            int cnt=0;
            cin>>n>>str;
            printf("<top %d>\n",n);
            for(int i=0;i<7;i++){
                for(int j=0;j<vec[i].size();j++){
                    int id=mp[vec[i][j]];
                    if(id)
                        nod[id].cnt++;
                    else{
                        mp[vec[i][j]]=++cnt;
                        nod[cnt].s=vec[i][j];
                        nod[cnt].cnt=1;
                    }
                }
            }
            sort(nod+1,nod+cnt+1,cmp);
            for(int i=1;i<=min(cnt,n);++i)
                cout<<nod[i].s<<" "<<nod[i].cnt<<endl;
            int num=nod[min(cnt,n)].cnt;
            for(int i=min(cnt,n)+1;i<=cnt;++i)
                if(nod[i].cnt==num)
                    cout<<nod[i].s<<" "<<nod[i].cnt<<endl;
            printf("</top>\n");
        }
    }
    return 0;
}
