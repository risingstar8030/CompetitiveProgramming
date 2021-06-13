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

int path = 0;

void display(vector<vector<char>> & grid) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

bool is_safe(vector<vector<char>> & grid, int row, int col, int n) {

	for (int i = row; i >= 0; i--) {
		if (grid[i][col] == 'Q')
			return false;
	}

	for (int i = row, j = col; i >= 0 and j >= 0; i--, j--) {
		if (grid[i][j] == 'Q' )
			return false;
	}

	for (int i = row, j = col; i >= 0 and j < n; i--, j++) {
		if (grid[i][j] == 'Q' )
			return false;
	}

	return true;
}

void nqueen(vector<vector<char>>& grid, int curr_row, int n) {

	if (curr_row == n) {
		path++;
		//display(grid);
		//cout << endl;
		return;
	}

	for (int i = 0; i < n; i++) {
		if (is_safe(grid, curr_row, i, n) and grid[curr_row][i] != '*') {
			grid[curr_row][i] = 'Q';
			nqueen(grid, curr_row + 1, n);
			grid[curr_row][i] = '.';
		}
	}

}

int main(int argc, char const *argv[]) {
	file_i_o();

	vector<vector<char>> grid (8, vector<char>(8)) ;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cin >> grid[i][j];
		}
	}


	nqueen(grid, 0, 8);
	cout << path << endl;


	return 0;
}
