bool dfs(char** b,int m,int n,char* w,int idx,int r,int c){ if(!w[idx]) return true; if(r<0||r>=m||c<0||c>=n||b[r][c]!=w[idx]) return false; char tmp=b[r][c]; b[r][c]='#';
bool found=dfs(b,m,n,w,idx+1,r+1,c)||dfs(b,m,n,w,idx+1,r-1,c)|| dfs(b,m,n,w,idx+1,r,c+1)||dfs(b,m,n,w,idx+1,r,c-1);
b[r][c]=tmp; return found;
 
}
bool exist(char** board,int m,int* rSz,char* word){ int n=rSz[0];
for(int r=0;r<m;r++) for(int c=0;c<n;c++) if(dfs(board,m,n,word,0,r,c)) return true;
return false;
}
