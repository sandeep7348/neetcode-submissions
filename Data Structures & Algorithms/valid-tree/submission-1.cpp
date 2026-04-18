class Solution {
 int * parent;
 int * size;
public:
      int findParent(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        return findParent(parent[x]);
    }
   void unionBySize(int x, int y)
   {
    int parentX = findParent(x);
    int parentY = findParent(y);

    if(parentX == parentY) return;

    if(size[parentX] >= size[parentY])
    {
        parent[parentY] = parentX;
        size[parentX] += size[parentY];
    }
    else
    {
        parent[parentX] = parentY;
        size[parentY] += size[parentX];
    }
   }
    bool validTree(int n, vector<vector<int>>& edges) {
       parent=new int[n];
       size=new int[n];
       for(int i=0;i<n;i++)
       {
        parent[i]=i;
        size[i]=1;
       }
       for(auto p:edges)
       {
        if(findParent(p[0])!=findParent(p[1]))
        {
            unionBySize(p[0],p[1]);
            
        }
        else{
            return false;
        }
       }
       int count=0;
       for(int i=0;i<n;i++)
       {
        if(findParent(i)==i)
        {
            count++;
        }
       }
       return count==1?true:false;
    }
};
