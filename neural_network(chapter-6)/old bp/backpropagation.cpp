#include <bits/stdc++.h>

using namespace std;

int node_in_layer[10];
float x[5][5];
float w[5][5][5];
float dl[5][5];
float sample[10][10];

int nos, nof;
float c = 0.25;

int d[10];

void read_in()
{
    
    freopen("bp.txt","r",stdin);
    cout << "Enter num of samples , features" << endl;
    cin >> nos >> nof ;

    cout << "Enter samples" << endl;
    for(int i = 1; i <= nos; i++)
    {
        for(int j = 1; j <= nof; j++)
        {
            cin >> sample[i][j];
        }
    }

    cout << "Enter label for given samples" << endl;
    for(int i = 1; i <= nos; i++)
    {
        cin >> d[i];
        //cout  << d[i] << endl;
    }


}


float sigmoid(float num)
{
	return 1 / (1 + exp(-num));
}

void backPropagation()
{
	node_in_layer[0] = 2;
	node_in_layer[1] = 2;
	node_in_layer[2] = 1;

	//cout << "Nos : " << nos << endl;
	
	for(int it = 1; it <= nos; it++)
	{

		//initialize
		for(int k = 1; k <= 2; k++)
		{

			for(int i = 1; i <= node_in_layer[k-1]; i++)
			{
				//srand(time(NULL));
				for(int j = 1; j <= node_in_layer[k]; j++)
				{

					// w ij (K)

					//w[k][i][j] = (rand() % 10) / 10.0;
					cin >> w[k][i][j];
					//cout << "weight init" << w[k][i][j] << " " ; 
				}

			}
			cout << endl;

		}

		//feature initialize
		for(int i = 1; i <= node_in_layer[0]; i++)
		{
			x[0][i] = sample[it][i];
		}

		cout << "here" << endl;
		//feed-forward
		//k == K -1 = 1 as K = 2
		for(int k = 0; k <= 1  ;k++)
		{
			for(int j = 1; j <= node_in_layer[k+1]; j++)
			{
				float y = 0;
				for(int i = 0; i <= node_in_layer[k]; i++)
				{

					y += (w[k+1][i][j] * x[k][i]);
				}
				//sigmoid
				x[k+1][j] = sigmoid(y);
			}

		}

		cout << "here" << endl;

		//back propagation for output layer
		for(int j = 1; j <= node_in_layer[2]; j++)
		{

			dl[2][j] = ( x[2][j] * (1 - x[2][j]) * (x[2][j] - d[j]) );
		}

		//back propagation for hidden layers
		for(int k = 2-1; k >= 1; k--)
		{

			for(int i = 1; i <= node_in_layer[k]; i++)
			{
				float s = 0;

				for(int j = 1; j <= node_in_layer[k+1]; j++)
				{
					s += (dl[k+1][j]*w[k+1][i][j]);

				}

				dl[k][i] = ( x[k][i] * (1 - x[k][i]) * s);
			}

		}


		//weight update	
		for(int k = 1; k <= 2; k++)
		{


			for(int i = 1; i <= node_in_layer[k-1]; i++)
			{
				//cout << "here" << endl;

				for(int j = 1; j <= node_in_layer[k]; j++)
				{
					//cout << w[k][i][j] << " " << c << " " << dl[k][j] << " " << x[k-1][i] << endl;
					//cout << "C is here " << c << endl;
					w[k][i][j] = w[k][i][j] - ( c * dl[k][j] * x[k-1][i] );

					//cout << endl;

				}
			}
		}


	}

	

	

}


int main()
{
	

	read_in();
	for(int y = 0; y < 5000; y++)
	{
		backPropagation();	
	}
	
	// for(int k = 1; k <= 2; k++)
	// 	{

	// 		for(int i = 1; i <= node_in_layer[k-1]; i++)
	// 		{

	// 			for(int j = 1; j <= node_in_layer[k]; j++)
	// 			{
	// 				cout << "W" << i << " " << j << " K " << k << " : " << w[k][i][j] << endl; 
	// 				//w[k][i][j] = w[k][i][j] - ( c * dl[k][j] * x[k-1][i] );

	// 			}
	// 		}
	// 	}
	float p = 0;
	for(int j = 1; j <= node_in_layer[2]; j++)
	{
		p += ( (x[2][j] - d[j])*(x[2][j] - d[j]) );
	}

	cout << "Error " << p << endl;


	return 0;
}