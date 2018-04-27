#include <bits/stdc++.h>


using namespace std;

float w[10];
float x[10][10];

int nos, nof;

int d[10];


void read_in()
{
    
    freopen("mse.txt","r",stdin);
    cout << "Enter num of samples , features" << endl;
    cin >> nos >> nof ;

    cout << "Enter samples" << endl;
    for(int i = 1; i <= nos; i++)
    {
        for(int j = 1; j <= nof; j++)
        {
            cin >> x[i][j];
        }
    }

    cout << "Enter label for given samples" << endl;
    for(int i = 1; i <= nos; i++)
    {
        cin >> d[i];
        //cout  << d[i] << endl;
    }


}

float equn(int sample)
{
	float sum = 0;
	sum += w[0];
	//cout << sum << endl;
	for(int i = 1; i <= nof; i++)
	{
		sum += (w[i] * x[sample][i]);

		//cout << sum << endl;

	}
	return sum;
}

int main()
{
	
	cout << "Enter number of sample and feature." << endl;
	int i = 0;

	float D, c = 0.1;

	w[0] = 0;
	w[1] = 0;
	w[2] = 0;


	read_in();



	while(i < 100)
	{
		for(int j = 1; j <= nos; j++)
		{
			cout << " wo " << w[0] << " w1: " << w[1] << " w2: " << w[2] << " " <<endl;
			D = equn(j);

			cout << D << endl;

			w[0] = w[0] - ( c * (D - d[j]) );

			for(int f = 1; f <= nof; f++)
			{
				w[f] = w[f] - ( c * (D-d[j]) * x[j][f] );
			}

			

		}
		
		i++;
	}

	float result = 0;
	result += w[0];
	//cout << sum << endl;
	//for(int i = 1; i <= nof; i++)
	//{
		result += (w[1] * 2);
		result += (w[2] * 1);
		//cout << sum << endl;

	//}

	cout << " wo " << w[0] << " w1: " << w[1] << " w2: " << w[2] << " " <<endl;

	cout << " D " <<  result << endl;

	return 0;
}