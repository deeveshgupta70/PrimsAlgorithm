#include<bits/stdc++.h>

using namespace std;


#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define MOD 1000000007
#define MOD1 998244353
#define INF 1e18
#define nline "\n"
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define sz(x) ((int)(x).size())
#define FOR(a, c) for (int(a) = 0; (a) < (c); (a)++)
#define FORL(a, b, c) for (int(a) = (b); (a) <= (c); (a)++)
#define FORR(a, b, c) for (int(a) = (b); (a) >= (c); (a)--)
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define F first
#define S second
#define max(a, b) (a < b ? b : a)
#define min(a, b) ((a > b) ? b : a)

typedef vector<int> vi;
typedef pair<int, int> pi;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(vector<vector <T>> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.F); cerr << ","; _print(p.S); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(vector<vector<T>> v) {cerr << "\n"; for (auto i : v) { for( auto t : i){cerr<<t; cerr << " ";} cerr<<"\n";}}
	
int findMinVertex( vector<bool>& visited , int n, vector<int>& weight){

	int minVertex = -1;

	for( int i = 0; i < n ; i++){

		if( !visited[i] && ( minVertex == -1 || weight[i] <  weight[minVertex])) minVertex = i;
	}

	return minVertex ;
}


void PrimsAlgo( vector<vector<int>> &edges , int n){

	vector<int> parent(n , -1);
	vector<int> weight( n , INT_MAX);
	vector<bool> visited( n , 0);

	parent[0] = -1;
	weight[0] = 0;

	for( int i = 0; i < n - 1; i++){

		int minVertex = findMinVertex(visited , n ,weight);

		visited[minVertex ] = true;

		for( int j = 0; j < n ; j++){

			if( !visited[j] && edges[minVertex][j] && weight[j] > edges[minVertex][j] ){

				weight[j ] = edges[minVertex][j];
				parent[j] = minVertex;
			}
		}
	}

	for( int i = 1; i < n; i++){

		if( i < parent[i]){
			cout<< i << " "<<parent[i]<<" "<<weight[i];
		}
		else{
			cout<<parent[i]<<" "<<i<<" "<<weight[i];
		}
		cout<<"\n";
	}
}

///MST Prims Algorithim O(E*log(V));
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    vector<bool> visited( V ,0);
    vector<int> weight( V , INT_MAX);
    
    weight[0] = 0;
    
    priority_queue< pair<int, int> , vector<pair<int,int>> , greater< pair<int,int>> > pq;
    
    pq.push( {weight[0],0});
    
    while( !pq.empty()){
        
        int minVertex = pq.top().second;
        pq.pop();
        
        visited[minVertex] = true;
        
        for( auto i : adj[minVertex]){
            
            if( !visited[i[0]] && i[1] < weight[i[0]]){
                
                weight[i[0]] = i[1];
                pq.push({ i[1] , i[0]});
            }
        }
    }
    
    int sum = 0;

    return accumulate(weight.begin() , weight.end() , sum); ///gives sum;
    
    
    // return sum;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("Error.txt", "w", stderr);
#endif
fastio();
 int n , e;
 cin>>n>>e;

 vector<vector<int>> edges ( n , vector<int>( n , 0));
 vector<vector<int>> adj[n];

 for( int i = 0; i < e; i++){

 	int f,s , w;
 	cin>>f>>s>>w;

 	vector<int> t1,t2;

 	t1.push_back(f);
 	t1.push_back(w);
 	t2.push_back(s);
 	t2.push_back(w);


 	adj[s].push_back(t1);
 	adj[f].push_back( t2);

 	edges[f][s] = w;
 	edges[s][f] = w;
 }

 cout<<" Prims Algorithim : \n";
 PrimsAlgo( edges,n); /// This approach is of O(n*n) which is not suitable for our use 

 // To get an Efficient time complexity we use adjacency list instead of Adjacency Matrix;
// And also Priority Queue to get non-visited Minimum edge ;
cout<<"\n\n";
 // for( int i = 0; i < n; i++){

 // 	cout<< " Node "<<i<<" connected with : \n";

 // 	for( auto i : adj[i]){
 // 		cout<<"->"<<i[0]<<" "<<i[1]<<"\n";
 // 	}
 // }

cout<<" sum Of MST Weights : " <<spanningTree( n, adj);


return 0;

}

/*

Input:
5 7
0 1 4
0 2 8 
1 3 6
1 2 2
2 3 3
2 4 9
3 4 5

output:
Prims Algorithim : 
0 1 4
1 2 2
2 3 3
3 4 5

Input:

6 11
0 1 1
0 2 5
2 3 10
0 3 4
1 3 3
1 2 6
3 4 7
2 4 8 
4 5 2
2 5 9
3 5 6

Output:
Prims Algorithim : 
0 1 1
0 2 5
1 3 3
4 5 2
3 5 6

*/
