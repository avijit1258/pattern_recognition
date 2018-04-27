#include <bits/stdc++.h>


using namespace std;



void histogram()
{
    freopen("hello.txt", "r", stdin);
    int nClass;
    float test, low, high, sumFreq = 0, sumPClass = 0;
    float classData[10][100];
    float tLow = 100000, tHigh = -10000000;
    float range = 0;

    //cout << "Enter number of classes" << endl;
    cin >> nClass;

    float classFreq[nClass];
    float classProb[nClass];
    float XgivenC[nClass];
    float priorClassProb[nClass];
    float pClass[nClass];
    for(int i = 0; i < nClass; i++)
    {
        //cout << "Enter class" << i + 1 << "Frequency" << endl;
        cin >> classFreq[i];
        sumFreq += classFreq[i];
        for(int j = 0; j < classFreq[i]; j++)
        {
            cin >> classData[i][j];
            if(classData[i][j] > tHigh)
                tHigh = classData[i][j];
            if(classData[i][j] < tLow)
                tLow = classData[i][j];
        }

    }
    //cout << "SumFrequency" << sumFreq << endl;
    //cout << "Enter test data" << endl;
    cin >> test;
    range = ceil((tHigh - tLow)/ceil(sqrt(sumFreq)));

    cout << "Number of bins : " << ceil(sqrt(sumFreq)) << "Sum freq " << sumFreq << endl;
    range = ceil(range);
    //high = ceil(test);
    //low = floor(test);

    high = test + range;
    low =  test - range;

    cout << low << " " <<high;

    for(int i = 0; i < nClass; i++)
    {
        priorClassProb[i] = (classFreq[i] / sumFreq);

    }

    for(int i = 0; i < nClass; i++)
    {
        float cnt = 0.0;
        for(int j = 0; j < classFreq[i]; j++)
        {
            if( (low <= classData[i][j]) && (high >= classData[i][j]) )
                cnt++;

        }
        XgivenC[i] = (cnt / classFreq[i]);
        cout << "XgivenC "<< i << " " << XgivenC[i] << " count " <<cnt << endl;

    }

    for(int i = 0; i < nClass; i++)
    {
        pClass[i] = (XgivenC[i] * priorClassProb[i]);
        //cout << "PClass" << pClass[i] << endl;
        sumPClass += pClass[i];

    }
    float maxi = -1000034.0;
    int mi;
    for(int i = 0; i < nClass; i++)
    {

        cout << "Class " << i+1 << " " << (pClass[i]/sumPClass) << endl;
        if( (pClass[i]/sumPClass) > maxi )
        {
            maxi = (pClass[i]/sumPClass);
            mi = i;
        }
    }
    cout << "Class" << mi+1 << "Probability " << maxi <<endl;

}

void rect_tri()
{
    freopen("inputT.txt", "r", stdin);
    float n, base, area, test, low , high;
    float data[20];
    cout << "Enter base " << endl;
    cin >> base;
    cout << "Enter number of datapoints" << endl;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> data[i];

    float l1, l, h1, ht, hr;

    area = (1.0/n);
    cout << "Enter sample data" << endl;
    cin >> test;
    low = test - (base/2.0);
    high = test + (base/2.0);
    l = (base / 2.0);
    ht = (2.0 * area) / base;
    hr = area / base;

    float sumT = 0, sumR = 0;
    for(int i = 0; i < n; i++)
    {
        if( (low <= data[i]) && (high >= data[i]))
        {
            sumT += (ht * abs(data[i] - test) / (base/2.0));
            //sumR += (hr * abs(data[i] - test) / (base/2.0));
            sumR += hr ;

        }

    }
    cout << "Rectangle " << sumR << ", Triangle " << sumT << endl;

}

int main()
{


    histogram();
    //rect_tri();


    return 0;
}
