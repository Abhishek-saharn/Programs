/* 	 Problem Statement http://www.spoj.com/problems/BLINNET/
	
BLINNET - Bytelandian Blingors Network
#kruskal-s-algorithm #mst
We have discovered the fastest communication medium Bytelandian scientists announced, and they called it blingors. The blingors are incomparably better than other media known before. Many companies in Byteland started to build blingors networks, so the information society in the kingdom of Bytes is fact! The priority is to build the core of the blingors network, joinig main cities in the country. Assume there is some number of cities that will be connected at the beginning. The cost of building blingors connection between two cities depends on many elements, but it has been successfully estimated. Your task is to design the blingors network connections between some cities in this way that between any pair of cities is a communication route. The cost of this network should be as small as possible.

Remarks

The name of the city is a string of at most 10 letters from a,...,z.
The cost of the connection between two cities is a positive integer.
The sum of all connections is not greater than 232-1.
The number of cities is not greater than 10 000.
Input



s [number of test cases <= 10]
n [number of cities <= 10 000]
NAME [city name]
p [number of neigbouring cities to the city NAME]
neigh cost 
     [neigh - the unique number of  city from the main list
      cost - the cost of building the blingors connection from NAME to neigh]
[empty line between test cases]


Output

[separate lines] cost [the minimum cost of building the blingors network]

Example

Input:
2

4
gdansk
2
2 1
3 3
bydgoszcz
3
1 1
3 1
4 4
torun
3
1 3
2 1
4 1
warszawa
2
2 4
3 1

3
ixowo
2
2 1
3 3
iyekowo
2
1 1
3 7
zetowo
2
1 3 
2 7


Output:
3
4

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
int find(int x){
    if(x!=parent[x]){
        x=find(parent[x]);
    }
    return x;
}
void union1(int x,int y){
    x=find(x);
    y=find(y);
    parent[x]=parent[y];
}
int kruskal(vector<pair<int ,pair<int,int> > >& edges){
    int minweight=0;
    for(int i=1;i<=edges.size();i++){
        int u,v,cost;
        u=edges[i-1].second.first;
        v=edges[i-1].second.second;
        cost=edges[i-1].first;
        if(find(u)!=find(v)){
            minweight+=cost;
            union1(u,v);
        }
    }
    return minweight;
    
}

int main() {
	int s;
	cin>>s;
	for(int x=0;x<s;x++){
		
		int V;
		cin>>V;
		vector<pair<int ,pair<int,int> > > edges;
		parent.resize(V+1);
		for(int p=1;p<=V;p++){
		    parent[p]=p;
		}
		for(int u=1;u<=V;u++){
			int n;
			string name;
			cin>>name;
			cin>>n;
			for(int i=1;i<=n;i++){
				int v,w;
				cin>>v>>w;
				if(v>u){
					edges.push_back(make_pair(w,make_pair(u,v))); //pair is inserted from 0 index. 
				// 	cout<<"Edge added"<<u<<"-"<<v<<"\n";
				}

			}
		}
//		cout<<"Total edges="<<edges.size()<<"\n";
        int E=edges.size();
		sort(edges.begin(),edges.end());
// 		for(int i=0;i<E;i++){
// 		    cout<<edges[i].second.first<<"-"<<edges[i].second.second<<" W="<<edges[i].first<<"\n";
// 		}
		int res=kruskal(edges);
		
		cout<<res<<"\n";
		
		
	}
return 0;

}
