#include <functional>
#include <iostream>
#include <queue>
#include <vector>

/*
 * graph: v-vertex
 *        e-edge
 *    u->v with direction
 *    u-v no direction
 */

 using namespace std;

 /*
  * we kick off with bfs
  */
  void bfs(vector<vector<int>>& adj_list){
      auto size = adj_list.size();

      queue<int> q;
      vector<int> vis(size, 0);

      q.push(0);
      vis[0] = 1;
      cout << 0 << " ";

      while (!q.empty()) {
          auto u = q.front(); q.pop();
          for(auto v: adj_list[u]) {
              if (!vis[v]) {
                  vis[v] = 1;
                  cout << v << " ";
                  q.push(v);
              }
          }
      }
      cout << "\n";
  }

  void _dfs(vector<int>& vis,vector<vector<int>>& adj_list, int u){
        vis[u] = 1;
        cout << u << " ";
        for(auto v: adj_list[u]){
            if(!vis[v]){
                _dfs(vis, adj_list, v);
            }
        }
    }

  void dfs(vector<vector<int>>& adj_list, int u){
      auto size = adj_list.size();
      auto visited = vector<int>(size, 0);

      function<void(int)> dfs_rec = [&](int u) {
          visited[u] = 1;
          cout << u << " ";
          for(auto v: adj_list[u]){
              if(!visited[v]){
                  dfs_rec(v);
              }
          }
      };

      dfs_rec(u);
      cout << "\n";
  }


 int main(){
     // 衔接表 adj list
     vector<vector<int>> g(5);
     // we need to reserve the memory first
     g[0].push_back(1); g[0].push_back(3);
     g[1].push_back(0); g[1].push_back(2); g[1].push_back(4);
     g[2].push_back(1);
     g[3].push_back(0); g[3].push_back(4);
     g[4].push_back(1); g[4].push_back(3);

     // bfs(g);
     dfs(g, 0);

     return 0;
 }
