#include<bits/stdc++.h>
using namespace std;
#define ll 				long long int
#define ld				long double
#define mod             1000000007
#define inf             1e18
#define endl			"\n"
#define setbits(x)		__builtin_popcountll(x)
#define pb 				emplace_back
#define vi              vector<ll>
#define vs				vector<string>
#define pii             pair<ll,ll>
#define ump				unordered_map
#define mp 				map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 				first
#define ss 				second
#define mid(l,r)        (l+(r-l)/2)
#define loop(i,a,b) 	for(int i=(a);i<=(b);i++)
#define looprev(i,a,b) 	for(int i=(a);i>=(b);i--)
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str, char ch) {std::istringstream var((str)); vs v; string t; while (getline((var), t, (ch))) {v.pb(t);} return v;}


void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cout << *it << " = " << a << endl;
	err(++it, args...);
}
//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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


vector<pair<int, int>> sides {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};





int bfs(vector< string >& grid, vector< vector<bool> >& visited, int i, int j, int n, int m) {


	int size = 0;
	queue<pair<int, int>> q;
	q.push({i, j});
	visited[i][j] = true;

	while (!q.empty()) {

		auto current_node = q.front();
		q.pop();
		size++;

		for (int i = 0; i < sides.size(); i++) {
			auto side = sides[i];
			int x = current_node.ff + side.ff;
			int y = current_node.ss + side.ss;
			if (x >= 0 and y >= 0 and x < n and y < m and !visited[x][y] and grid[x][y] == '1') {
				q.push({x, y});
				visited[x][y] = true;
			}
		}
	}

	return size;
}

int main(int argc, char const *argv[]) {
	file_i_o();

	ll t;

	cin >> t;

	while (t--) {

		ll n, m;
		int ans = 0;

		cin >> n >> m;

		vector< string > grid;
		vector< vector<bool> > visited (n, vector<bool> (m , false));
		vector<int> componets_size;

		for (int i = 0; i < n; i++) {
			string ip;
			cin >> ip;
			grid.push_back(ip);
		}


		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == '1' and  !visited[i][j]) {
					componets_size.push_back(bfs(grid, visited, i, j, n, m));
				}
			}
		}

		sort(componets_size.begin(), componets_size.end(), greater<int>());

		for (int i = 1; i < componets_size.size(); i += 2)
			ans += componets_size[i];


		cout << ans << endl;

	}




	return 0;
}
