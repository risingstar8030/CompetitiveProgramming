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
#define loop(i,a,b) 	for(int i=(a);i<(b);i++)
#define loopeq(i,a,b) 	for(int i=(a);i<=(b);i++)
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


	int n1, s, n2;
	cin >> n1;
	vector<int> arr(n1 + 1);

	for (int i = 1; i <= n1; i++) {
		cin >> arr[i];
	}

	cin >> n2 >> s;

	int noOfsubsets = arr.size() / s;
	int cnt = 0;

	unordered_set<int> st;

	for (int i = 1; i <= n1; i++) {

		st.insert(arr[i]);

		if (i % s == 0) {

			if (st.count(n2))
				cnt++;

			st.clear();
		}

	}

	noOfsubsets == cnt ? cout << "1" << endl : cout << "0" << endl;



	return 0;



	String arr[] = input1.split(" ");
	String ans = "";
	for (int i = arr.length - 1; i >= 0; i--)
	{
		ans += arr[i] + " ";
	}

	return ans.substring(0, ans.length() - 1)
}
