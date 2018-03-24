#include <bits/stdc++.h>

using namespace std;

float x[100][100];
float w[2][100];
float d[100];
int num_of_samples, num_of_features, c = 1, k =  1;


void read_in()
{
    
    freopen("48.txt","r",stdin);
    cout << "Enter num of samples and features " << endl;
    cin >> num_of_samples >> num_of_features;

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
    }


}

float decision_func(int sample)
{
    float sum = 0;
    sum = w[0][0];
    for(int i = 1; i < num_of_features+1; i++)
    {
        cout << w[0][i] << " " << x[sample][i-1] << endl;
        sum += (w[0][i] * x[sample][i-1]);

    }

    return sum;
}

void weight_init()
{
    for(int i = 0; i < num_of_features+1; i++)
    {
        w[0][i] = 0;
        //w[1][i] = 0;
    }

}

void weigh_update(int sample)
{
    w[0][0] = w[0][0] + c * d[sample] * k;
    for(int i = 1; i < num_of_features+1; i++)
    {
        w[0][i] = w[0][i] + c * d[sample] * x[sample][i-1];
    }
    for(int i = 0; i < num_of_features+1; i++)
     {

         //w[0][i] = w[1][i];
        cout << w[0][i] << " ";
     }
    cout << endl;

}

void weight_adaption()
{
    for(int i = 0; i <  100; i++)
    {

        for(int j = 0; j < num_of_samples; j++)
        {
            float D = decision_func(j);
            bool classified = false;
            if(D > 0 && d[j] == 1)
            {
                classified = true;
            }else if(D < 0 && d[j] == -1)
            {
                classified = true;    
            }

            if(!classified)
            {
                weigh_update(j);
            }

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
    for(int i = 0; i < num_of_features+1; i++)
    {

        //w[0][i] = w[1][i];
        //cout << w[1][i] << " ";
    }
    cout << endl;
    
    return 0;
}
