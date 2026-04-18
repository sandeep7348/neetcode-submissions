class Solution {
    int *parent;
    int *size;

public:
int findParent(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        return parent[x]=findParent(parent[x]);
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

    int countComponents(int n, vector<vector<int>>& edges) {
        parent=new int[n];
        size=new int[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
            size[i]=1;
            
        }
        for(auto p:edges)
        {
            int node1=p[0];
            int node2=p[1];
            unionBySize(node1,node2);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(findParent(i)==i)
            {
                count++;
            }
            
            
        }
        return count;

    }
};
