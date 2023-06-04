void setZeros(vector<vector<int>> &matrix)
{
	int n = matrix.size();
	int m = matrix[0].size();
	vector<bool> x(n,false);
	vector<bool> y(m,false);

	for(int i = 0;i < n;i++)
	{
		for(int j = 0;j < m;j++)
		{
			if(matrix[i][j] == 0)
			{
				x[i] = true;
				y[j] = true;
			}
		}
	}

	for(int i = 0;i < n;i++)
	{
		if(x[i] == true)
		{
			for(int j = 0;j < m;j++)
			{
				matrix[i][j] = 0;
			}
		}
	}

	for(int i = 0;i < m;i++)
	{
		if(y[i] == true)
		{
			for(int j = 0;j < n;j++)
			{
				matrix[j][i] = 0;
			}
		}
	}


}
