#include<bits/stdc++.h>
using namespace std;
#define ll             long long int
#define ld            long double
#define mod             1000000007
#define inf             1e18
#define endl         "\n"
#define setbits(x)      __builtin_popcountll(x)
#define pb             emplace_back
#define vi              vector<ll>
#define vs            vector<string>
#define pii             pair<ll,ll>
#define ump            unordered_map
#define mp             map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff             first
#define ss             second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b)    for(int i=(a);i<(b);i++)
#define loopeq(i,a,b)    for(int i=(a);i<=(b);i++)
#define looprev(i,a,b)    for(int i=(a);i>=(b);i--)
#define log(args...)    { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)   for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define token(str,ch)   (std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str, char ch) {std::istringstream var((str)); vs v; string t; while (getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
   cout << *it << " = " << a << endl;
   err(++it, args...);
}

void file_i_o()
{
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
#ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
#endif
}

int main(int argc, char const *argv[]) {
   file_i_o();

   int queries;
   cin >> queries;



   for (int i = 0; i < queries; i++) {
      int n, m;
      cin >> n >> m;

      vector<int> adj[n + 1];

      for (int j = 0; j < m; j++) {
         int u, v;
         cin >> u >> v;
         adj[u].push_back(v);
         adj[v].push_back(u);
      }

      int src;
      cin >> src;

      vector<int> d(n + 1, -1);
      vector<bool> vis(n + 1, false);
      queue<int>q;

      q.push(src);
      vis[src] = true;
      d[src] = 0;

      while (!q.empty()) {
         int u = q.front();
         q.pop();

         for (int v : adj[u]) {
            if (vis[v])
               continue;
            vis[v] = true;
            d[v] = d[u] + 6;
            q.push(v);
         }
      }

      for (int i = 1; i <= n; i++) {
         if (src != i)
            cout << d[i] << " ";
      }
      cout << endl;
   }



   return 0;
}
