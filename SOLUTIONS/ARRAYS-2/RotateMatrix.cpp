#include <bits/stdc++.h>

void rotateMatrixHelper(vector<vector<int>> &mat, int rs, int cs, int re, int ce)
{

    if(rs >= re or cs >= ce)
    {
        return; 
    }

    if (rs >= re - 1 || cs >= ce - 1)
    { 
        return; 
    }

    int previous = mat[rs + 1][cs]; 
    int current;
        

    for (int i = cs; i < ce; i++) 
    { 
        current = mat[rs][i]; 
        mat[rs][i] = previous; 
        previous = current; 
    } 

    rs++; 

    for (int i = rs; i < re; i++) 
    { 
        current = mat[i][ce-1]; 
        mat[i][ce-1] = previous; 
        previous = current; 
    } 
    ce--; 

    if (rs < re) 
    { 
        for (int i = ce - 1; i >= cs; i--) 
        { 
            current = mat[re-1][i]; 
            mat[re-1][i] = previous; 
            previous = current; 
        } 
    } 
    re--; 

    if (cs < ce) 
    { 
        for (int i = re-1; i >= rs; i--) 
        { 
            current = mat[i][cs]; 
            mat[i][cs] = previous; 
            previous = current; 
        } 
    } 
    cs++; 

    rotateMatrixHelper(mat, rs, cs, re, ce);

}

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
	rotateMatrixHelper(mat, 0, 0, n, m);
}
