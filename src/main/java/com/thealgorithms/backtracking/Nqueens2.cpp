class Solution {
public:
    bool isSafe(vector<string>v, int row, int col) {
      int i=row,j = col;
      while(j>=0)
      {
        if(v[row][j] == 'Q')
          return false;
        j--;
      }
      i=row;
      j = col;
      while(i>=0 && j>=0)
      {
        if(v[i][j] == 'Q')
          return false;
        j--;
        i--;
      }
      i=row;
      j = col;
      while(i<v.size() && j>=0)
      {
        if(v[i][j] == 'Q')
          return false;
        j--;
        i++;
      }
      return true;
    }
    void fun(vector<vector<string>>&res, vector<string>&v, int col)
    {
      if(col == v.size())
      {
        res.push_back(v);
        return;
      }
      for(int i=0;i<v.size();i++)
      {
        if(isSafe(v,i,col) == true)
        {
          v[i][col]='Q';
          fun(res,v,col+1);
          v[i][col]='.';
        }
      }
    }
    int totalNQueens(int n) {
      vector<vector<string>>res;
      vector<string>s;
      string temp="";
      for(int i = 0; i < n;i++ )
      {
        temp+=".";
      }
      for(int i=0;i<n;i++)
        s.push_back(temp);
      
      fun(res,s,0);
      return res.size();
        
    }
};
