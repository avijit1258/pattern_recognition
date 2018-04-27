#include <bits/stdc++.h>





using namespace std;


vector<string> clauses;

int num_of_clause;
int num_of_clause_in_query;

void read()
{
	freopen("fc.txt","r",stdin);
	cout << "Enter number of clauses in KB : ";
	cin >> num_of_clause;
	string s;
	for(int i = 0; i < num_of_clause; i++)
	{
		cin >> s;
		clauses.push_back(s);
	}

	cout << "Enter number of clause in query : ";
	cin >> num_of_clause_in_query;
	for(int i = 0; i < num_of_clause_in_query; i++)
	{
		cin >> s;	
		clauses.push_back(s);
	}


}

string PL_RESOLVE(int ci, int cj)
{


	for(int i = 0; i < clauses[ci].size(); i++)
	{
		for(int j = 0; j < clauses[cj].size(); j++)
		{
			cout << abs( (clauses[ci][i]-'a') - (clauses[cj][j]-'a')) << endl;
			if(abs( (clauses[ci][i]-'a') - (clauses[cj][j]-'a')) == 32)
				cout << "yes" << endl;

		}
	}
	return "hello";
}


int main()
{
	read();
	PL_RESOLVE(0, 1);

	return 0;
}