#include <bits/stdc++.h>


using namespace std;


float sample[20][5], seed[10][5], bond[20];
int nos, nof, noseed;
bool is_end = false;


double eucledian_distance(int smpl, int sd);
void update_seed(int sd);

void input()
{
	cout << "Enter number of sample, feature, seed" << endl;
	cin >> nos >> nof >> noseed;

	cout << "Sample " << endl;
	for(int i = 0; i < nos; i++)
		for(int j = 0; j < nof; j++)
			cin >> sample[i][j];

	cout << "Seed " << endl;
	for(int i = 0; i < noseed; i++)
		for(int j = 0; j < nof; j++)
			cin >> seed[i][j];


}

void print_array()
{
	//cout << "Enter number of sample, feature, seed" << endl;
	//cin >> nos >> nof >> noseed;

	cout << "Sample " << endl;
	for(int i = 0; i < nos; i++)
	{

		for(int j = 0; j < nof; j++)
		{

			cout << sample[i][j] << " " ;
		}
		cout <<  bond[i] << endl;

	}
		

	cout << "Seed " << endl;
	for(int i = 0; i < noseed; i++)
	{

		for(int j = 0; j < nof; j++)
		{

			cout << seed[i][j] << " " ;
		}
		cout << endl;
	}


}

void label_update()
{
	is_end = true;
	for(int i = 0; i < nos; i++)
	{
		float mini = 1000000, im;
		for(int j = 0; j < noseed; j++)
		{
			float eucl = eucledian_distance(i, j);
			if(eucl < mini)
			{
				mini = eucl;
				im = j;
			}
		}
		if(bond[i] != im)
		{
			is_end = false;
		}
		bond[i] = im;
		cout << "For sample " << i << " ";
		update_seed(im);
	}


}

void final_label_update()
{
	is_end = true;
	for(int i = 0; i < nos; i++)
	{
		float mini = 1000000, im;
		for(int j = 0; j < noseed; j++)
		{
			float eucl = eucledian_distance(i, j);
			if(eucl < mini)
			{
				mini = eucl;
				im = j;
			}
		}
		if(bond[i] != im)
		{
			is_end = false;
		}
		bond[i] = im;
	}


}

void update_seed(int sd)
{
	
		float temp[nof] = {0};
		int cou = 0;
		for(int j = 0; j < nos; j++)
		{
			if(sd == bond[j])
			{
				cou++;
				for(int k = 0; k < nof; k++)
				{
					temp[k] += sample[j][k];

				}
			}


		}
		for(int k = 0; k < nof; k++)
		{
			seed[sd][k] = (temp[k]/cou);
			cout << seed[sd][k] << " ";
		}
		cout << endl;

	
}
void update_all_seed()
{
	for(int i = 0; i < noseed; i++)
	{
		float temp[nof] = {0};
		int cou = 0;
		for(int j = 0; j < nos; j++)
		{
			if(i == bond[j])
			{
				cou++;
				for(int k = 0; k < nof; k++)
				{
					temp[k] += sample[j][k];

				}
			}


		}
		for(int k = 0; k < nof; k++)
		{
			seed[i][k] = (temp[k]/cou);
			//cout << seed[k] << " ";
		}
		//cout << endl;

	}
}



double eucledian_distance(int smpl, int sd)
{
	float sum = 0;
	for(int i = 0; i < nof; i++)
	{
		sum = sum + ((sample[smpl][i] - seed[sd][i])*(sample[smpl][i] - seed[sd][i])); 

	}

	return sqrt(sum);
}



int main()
{
	freopen("km.txt", "r", stdin);
	input();

	for(int i = 0; i < nos; i++)
		bond[i] = -5;
	
		label_update();

		update_all_seed();

		final_label_update();
		print_array();
	

	return 0;
}