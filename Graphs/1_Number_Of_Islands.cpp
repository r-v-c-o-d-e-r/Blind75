#include<vector>
using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited,
    vector<int>& delRow, vector<int>& delCol, int n, int m, int r, int c){
        visited[r][c] = 1;

        for(int i=0; i<4; i++){
            int newRow = r + delRow[i];
            int newCol = c + delCol[i];

            if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m
            && !visited[newRow][newCol] && grid[newRow][newCol] != '0'){
                dfs(grid,visited,delRow,delCol,n,m,newRow,newCol);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n,vector<int>(m,0));
        int count = 0;

        vector<int> delRow = {0,0,-1,1};
        vector<int> delCol = {-1,1,0,0};

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    count++;
                    dfs(grid,visited,delRow,delCol,n,m,i,j);
                }
            }
        }
        return count;
    }
};
    