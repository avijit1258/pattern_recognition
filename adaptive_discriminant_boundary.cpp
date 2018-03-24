#include <bits/stdc++.h>

using namespace std;

float x[100][100];
float w[10][100];
float d[100];
int num_of_samples, num_of_features, c = 1, k =  1, num_of_class;


void read_in()
{
    
    freopen("410.txt","r",stdin);
    cout << "Enter num of samples , features and classes" << endl;
    cin >> num_of_samples >> num_of_features >> num_of_class;

    cout << "Enter samples" << endl;
    for(int i = 0; i < num_of_samples; i++)
    {
        for(int j = 0; j < num_of_features; j++)
        {
            cin >> x[i][j];
        }
    }

    cout << "Enter label for given samples" << endl;
    for(int i = 0; i < num_of_samples; i++)
    {
        cin >> d[i];
        cout  << d[i] << endl;
    }


}

float decision_func(int sample)
{
    float sum = 0;
    float arrayD[10];

    for(int j = 0; j < num_of_class; j++)
    {
        sum = w[j][0];
        for(int i = 1; i < num_of_features+1; i++)
        {
            //cout << w[0][i] << " " << x[sample][i-1] << endl;
            sum += (w[j][i] * x[sample][i-1]);

        }

        arrayD[j] = sum;
        //cout << " "<<  arrayD[j] ;
    }
    int maxI = distance(arrayD,max_element(arrayD, arrayD+num_of_class));
    //cout << "decision_func" << maxI << endl;

    return maxI;
}

void weight_init()
{
    cout << "Initial weight" << endl;
    for(int j = 0; j < num_of_class; j++)
    {
        for(int i = 0; i < num_of_features+1; i++)
        {
            //cin >> w[j][i];
            w[j][i] = i+1;            
        }

    }

}

void weigh_update(int sample, int incr, int decr)
{
    w[incr][0] = w[incr][0] + c * k;
    for(int i = 1; i < num_of_features+1; i++)
    {
        //cout <<  w[incr][i] << "  " << x[sample][i-1] << endl;
        w[incr][i] = w[incr][i] + c * x[sample][i-1];
    }
    //cout << "Increase" << endl;
    for(int i = 0; i < num_of_features+1; i++)
     {
        
        //cout << w[incr][i] << " ";
     }
     //cout << endl;
     //cout << "Decrease" << endl;
     w[decr][0] = w[decr][0] - c * k;
    for(int i = 1; i < num_of_features+1; i++)
    {
        //cout <<  w[incr][i] << "  " << x[sample][i-1] << endl;
        w[decr][i] = w[decr][i] - (c  * x[sample][i-1]);
    }
    for(int i = 0; i < num_of_features+1; i++)
     {
        
        //cout << w[decr][i] << " ";
     }
     //cout << endl;

}

void weight_adaption()
{
    for(int f = 0; f < 100; f++)
    {

        for(int j = 0; j < num_of_samples; j++)
        {
            int D = decision_func(j);
            cout << D << " " << d[j] << endl;
            bool classified = false;
            if(D == d[j])
            {
                classified = true;
            }

            if(!classified)
            {
                weigh_update(j, d[j], D);
                //cout << "In update" << d[j] << " " << D << endl;
            }
            //cout << "hello" << endl;

        }

    }

}

int main()
{
    read_in();
    //weight_adaption(0);
    //weight_adaption(1);
    weight_init();

    //cout << decision_func(0) << " " << decision_func(1) << endl;

    weight_adaption();
    for(int i = 0; i < num_of_class; i++)
    {
        for(int j = 0; j < num_of_features+1; j++)
        {
            cout << w[i][j] << " ";

        }
        cout << endl;    
    }
    
    
    return 0;
}
