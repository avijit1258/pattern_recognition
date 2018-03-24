#include <bits/stdc++.h>

using namespace std;


float sample[20][10];
float distance_mat[20][20];
int nos, nof;

struct Cluster
{
	vector<int> element;
	int level;
};

vector<Cluster> cluster_pool;

double eucledian_distance(int m, int n)
{
	float sum = 0;
	for(int i = 0; i < nof; i++)
	{
		sum = sum + ((sample[m][i] - sample[n][i])*(sample[m][i] - sample[n][i])); 

	}

	return sqrt(sum);
}

void input()
{
	cout << "Enter number of sample, feature " << endl;
	cin >> nos >> nof;

	cout << "Sample " << endl;
	for(int i = 0; i < nos; i++)
		for(int j = 0; j < nof; j++)
			cin >> sample[i][j];


}

void calculate_distance()
{
	for(int i = 0; i < nos; i++)
	{

		for(int j = 0; j < nos; j++)
		{

			distance_mat[i][j] =  eucledian_distance(i, j);

		}

	}
}


void print_array()
{
	//cout << "Enter number of sample, feature, seed" << endl;
	//cin >> nos >> nof >> noseed;

	cout << "Distance Matrix " << endl;
	for(int i = 0; i < nos; i++)
	{

		for(int j = 0; j < nos; j++)
		{

			cout << distance_mat[i][j] << " " ;
		}
		cout << endl;

	}
		


}

void init_clusters()
{
	for(int i = 0; i < nos; i++)
	{
		Cluster cl;
		cl.element.push_back(i);
		cl.level = 0;
		cluster_pool.push_back(cl);
	}
}

void show_cluster_pool()
{

	for(int i = 0; i < cluster_pool.size(); i++)
	{
		cout << " { ";
		for(int j = 0; j < cluster_pool[i].element.size(); j++)
		{
			cout << cluster_pool[i].element[j]+1 << ",";
		}
		cout << " } ";
		
	}
	cout << endl;
}

float distance_between_two_cluster(int s, int t)
{
	float maxi = -100000, eucl;
	for(int i = 0; i < cluster_pool[s].element.size(); i++)
	{

		for (int j = 0; j < cluster_pool[t].element.size(); j++)
		{
			if(cluster_pool[s].element[i] == cluster_pool[t].element[j])
				continue;
			eucl = distance_mat[cluster_pool[s].element[i]][cluster_pool[t].element[j]];
			if(eucl > maxi)
			{
				maxi = eucl;
			}
		}
	}
	return maxi;
}

void merge_two_cluster(int R, int L)
{
	for(int i = 0; i < cluster_pool[L].element.size(); i++)
	{
		cluster_pool[R].element.push_back(cluster_pool[L].element[i]);


	}
	cluster_pool.erase(cluster_pool.begin()+L);

}

void iteration()
{

	while( cluster_pool.size() != 2)
	{
		int mR, mL;
		float mini = 100000, eucl;
		for(int i = 0; i < cluster_pool.size(); i++)
		{
			for(int j = i+1 ; j < cluster_pool.size(); j++)
			{
				eucl = distance_between_two_cluster(i, j);
				if(eucl < mini)
				{
					mini = eucl;
					mR = i;
					mL = j;
				}

			}
		}
		merge_two_cluster(mR, mL);
		show_cluster_pool();
	}

}




int main()
{
	
	// deletes element in position 1
	//test.erase(test.begin()+1);
	freopen("sl.txt", "r", stdin);
	input();
	calculate_distance();
	print_array();
	init_clusters();
	show_cluster_pool();
	iteration();

	return 0;
}