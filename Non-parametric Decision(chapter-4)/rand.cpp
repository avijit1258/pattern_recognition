#include <bits/stdc++.h>



using namespace std;

int main()
{
    freopen("hello.txt", "w", stdout);

    for(int i = 0; i < 50; i++)
    {
        double q = 0 + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/8.0));
        cout << q << " " ;

    }
    cout << endl;
    cout << endl;
    for(int i = 0; i < 50; i++)
    {
        double q = 3 + static_cast <double> (rand()) /( static_cast <double> (RAND_MAX/7.0));
        cout << q << " " ;

    }

    return 0;
}
