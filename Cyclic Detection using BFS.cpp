//CYCLE DETECTION using BREADTH FIRST SEARCH for undirected

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
bool bfs(vector<int> l[],int n){

queue<pair<int,int>> q;
bool visited[n]={0};

for(int i=0;i<n;++i){    //this loop is necessary if there is connected components of graph
        if(!visited[i]){
q.push({i,-1});
visited[i]=1;    //we mark as visited if it is entered in queue

while(!q.empty())
{
    int node=q.front().first;     //print front element of queue
   parent=q.front().second;
    q.pop();            //remove front element of the queue
    for(auto x:l[node])  //push all the visited adjacent node of front element in the queue
    {
        if(visited[x]!=1){   //insert in queue if it is not already visited
           q.push({x,node});
        visited[x]=1;}
        else if( x!=parent)   //if node is visited & not a parent of it then cycle present
         return true;
    }

}
}}
return false;    //return false if for every node there is not find any cycle
}
int main(){
int n,m,x,y;
cin>>n>>m;
vector<int> l[n];
for(int i=0;i<m;i++)
 {  cin>>x>>y;
    if(x!=y){
    l[x].push_back(y);
    //if undirected
    l[y].push_back(x);}
}

if(bfs(l,n)==true) cout<<"CYCLE IS PRESENT";
else cout<<"CYCLE IS NOT PRESENT";

}
