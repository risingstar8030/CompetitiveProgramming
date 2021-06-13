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

string int_to_bits(ll num) {

	string str = "";

	while (num) {
		if ((num & 1) == 1)
			str = "1" + str;
		else
			str = "0" + str;
		num >>= 1;
	}
	return str;
}

ll bits_to_int(string str) {

	ll ans = 0;

	for (ll i = 0; i < str.size(); i++)
	{
		if (str[i] == '1')
			ans += 1 << (str.size() - i - 1);
	}
	return ans;
}

int main(int argc, char const *argv[]) {
	file_i_o();

	ll t;
	cin >> t;

	while (t--) {

		ll c;
		cin >> c;

		string c_str = int_to_bits(c);

		string a_str = "", b_str = "";

		bool msb_set = false;

		for (ll i = 0; i < c_str.size(); ++i)
		{
			if (c_str[i] == '0') {
				a_str += "1" ;
				b_str += "1" ;
			}
			else {

				if (msb_set) {
					a_str += "0" ;
					b_str += "1" ;
				}
				else {
					a_str += "1" ;
					b_str += "0" ;
					msb_set = true;
				}
			}
		}

		ll ans = bits_to_int(a_str) * bits_to_int(b_str);
		cout << ans << endl;

	}




	return 0;
}
