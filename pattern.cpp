#include<bits/stdc++.h>
using namespace std;
int x[100][100]={0};
int d[100]={0};
int [100]={0};
int ans[101]={0};
bool check(int n)
{
    for(int i=1;i<=n;i++)
    {
        if(ans[i])
            return false;
    }
    return true;
}
int main()
{
    freopen("Adaptive.txt","w",stdout);
    int n,m,i,j,k,l,c;
    cout<<"Enter number of row"<<endl;
    cin>>n;
    cout<<"Enter number of x's"<<endl;
    cin>>m;
    for(i=1;i<=n;i++)
    {
        x[i][0]=1;
        for(j=1;j<=m;j++)
        {
            cout<<"Enter row "<<i<<": X"<<j<<": ";
            cin>>x[i][j];
        }
        cout<<"Enter d: ";
        cin>>d[i];
        ans[i]=1;
    }


    cout<<"Enter K:";
    cin>>k;
    cout<<"Enter C:";
    cin>>c;

    int t=0,idx=1;

    int res=0;

    cout<<endl<<endl;
    printf("%4s%4s","t","i");
    for(i=1;i<=m;i++)
    {
        printf("%3s%d","x",i);
    }
    for(i=0;i<=m;i++)
    {
        printf("%6s%d","o w",i);
    }
    printf("%4s%9s","D","Error?");
    for(i=0;i<=m;i++)
    {
        printf("%6s%d","n w",i);
    }
    cout<<endl;

    while(1)
    {
        if(t%n==0 && check(n)==true)
        {
            break;
        }
        res=0;
        for(i=0;i<=m;i++)
            res=res+w[i]*x[idx][i];

        printf("%4d%4d",t+1,idx);

        for(i=1;i<=m;i++)
            printf("%4d",x[idx][i]);

        for(i=0;i<=m;i++)
            printf("%7d",w[i]);

        printf("%4d",res);

        if( (d[idx]<0 && res<0) || (d[idx]>=0 && res>=0))
        {
            cout<<"    No   ";
            for(i=0;i<=m;i++)
                printf("%7d",w[i]);
            cout<<endl;
            ans[idx]=0;
        }

        else
        {
            cout<<"    Yes  ";
            w[0]=w[0]+c*d[idx]*k;
            for(i=1;i<=m;i++)
                w[i]+=c*d[idx]*x[idx][i];

            for(i=0;i<=m;i++)
                printf("%7d",w[i]);
            cout<<endl;

            ans[idx]=1;
        }
        t++;
        idx++;
        if(idx>n)
            idx=1;
    }
    cout<<w[0]<<" ";
    for(i=1;i<=m;i++)
    {
        if(w[i]>0)
            cout<<'+';
        cout<<w[i];
        cout<<'x'<<i<<" ";
    }
    cout<<endl;

}
