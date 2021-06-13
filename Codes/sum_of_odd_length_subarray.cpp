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

int sumOddLengthSubarrays(vector<int>& arr) {


	int sum = arr[0];
	vector<int> prefix;
	prefix.push_back(arr[0]);
	for (int i = 1; i < arr.size(); i++) {
		sum += arr[i];
		prefix.push_back(sum);
	}
	if (arr.size() == 3) {
		sum *= 2;
	}
	if (arr.size() > 3) {
		// int k=3;
		int window = 3;
		for (int window = 3; window <= prefix.size(); window += 2) {
			for (int k = window - 1; k < prefix.size(); k++) {
				if (k - window < 0) {
					sum += prefix[k];
				}
				else {
					sum += prefix[k] - prefix[k - window];
				}
			}
		}
	}

	return sum;
}

int main(int argc, char const *argv[]) {
	file_i_o();


	vector<int> arr = {1, 4, 2, 5, 3};
	cout << sumOddLengthSubarrays(arr) << endl;



	return 0;
}
