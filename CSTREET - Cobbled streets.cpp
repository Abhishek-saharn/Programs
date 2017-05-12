/* Problem Statement http://www.spoj.com/problems/CSTREET/
	The municipal chronicals of an unbelievable lordly major town in a land far, far away tell the following story:
Once upon a time the new crowned king Günther decided to visit all towns in his kingdom. The people of the unbelievable lordly major town expected that king Günther would like to see some of the most famous buildings in their town. For the lordly citizens it seemed neccessary that all streets in the town that the king would have to use had to be cobbled with stone. Unfortunately the unbelievable lordly major town had not much money at that time as they used most of their savings to erect the highest cathedral the world had ever seen.
Roumours were afloat that the real reason for their thriftiness was not that the town treasury was empty but that many people believed that king Günther came to the throne by deceiving his father king Erwin and that in his youth he made a pact with the devil. But anyway, the citizens of the unbelievable lordly major town decided to pave only as much streets as were absolutely necessary to reach every major building. 
Can you help the citizens of the unbelievable lordly major town to find out which streets should be paved?
It might be usefull to know that all major buildings are either at the end of a street or at an intersection. In addition to that you can assume that all buildings are connected by the given streets.

Input

t [number of testcases (1 <= t <= 100)]
p [price to pave one furlong of street (positive integer)]
n [number of main buildings in the town (1 <= n <= 1000)]
m [number of streets in the town (1 <= m <= 300000)]
a b c [street from building a to building b with length c (lengths are given in furlong and the buildings are numbered from 1 to n)]

Output

For each testcase output the price of the cheapest possibility to reach all main buildings in the city on paved streets. You can assume that the result will be smaller than 2^32.

Example

Input:
1
2
5
7
1 2 1
2 3 2
2 4 6
5 2 1
5 1 3
4 5 2
3 4 3

Output:
12
*/


#include <bits/stdc++.h>
using namespace std;
vector<int> parent;


int find(int x){
    if(x!=parent[x]){
        x=find(parent[x]);
    }
    return x;
}

void union1(int u,int v){
    u=find(u);
    v=find(v);
    parent[u]=parent[v];
}


int kruskal(vector<pair<int ,pair<int,int> > >& edges){
        int mincost=0;
          for(int i=1;i<=edges.size()-1;i++){ //edges.size()-1 because size of edge is greater than E.
              int u,v,w;
              u=edges[i].second.first;
              v=edges[i].second.second;
              w=edges[i].first;
              if(find(u)!=find(v)){
                  mincost+=w;
                  union1(u,v);
              }
              
          }
          return mincost;
}

int main() {
    int t;
    cin>>t;
    for(int s=0;s<t;s++){
        int p,V,E,u,v,w;

        cin>>p>>V>>E;
        parent.resize(V+1);
        for(int i=1;i<=V;i++){
            parent[i]=i;
        }
        vector<pair<int ,pair<int,int> > > edges(E+1);
        for(int i=1;i<=E;i++){
            cin>>u>>v>>w;
            edges[i]=make_pair(w,make_pair(u,v));
        }
        
        sort(edges.begin(),edges.end());
        
        int mindist=kruskal(edges);
         cout<<mindist*p;
    }
	return 0;
}
