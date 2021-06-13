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

int main(int argc, char const *argv[]) {
	file_i_o();

	ll t;
	cin >> t;

	while (t--) {

		ll L; string str;

		cin >> L;
		cin >> str;

		ll one_cnt = 0;

		for (ll i = 0; i < L; i++) {
			if (str[i] == '1')
				one_cnt++;
		}

		ld ans = (ld)(one_cnt * 100) / L;
		//log(ans);
		if (ans >= 50.0) {
			cout << "YES" << endl;
		}
		else {

			ll cnt = 0;
			int flag = 0;
			for (ll i = 0; i < L  ; i++) {
				//cout << "Suraj" << endl;
				if (str[i] == '1') {
					cnt++;
					ld ans = (ld)(cnt * 100) / (i + 1);
					// log(i + 1);
					// log(ans);
					// log(one_cnt);
					if (ans >= 50.0) {
						cout << "YES" << endl;
						flag = 1;
					}
				}
				if (flag)
					break;
			}
			if (!flag) {
				cout << "NO" << endl;
			}
		}
	}




	return 0;
}
