// C++ program to implement wildcard pattern matching algorithm
#include <iostream>
#include <string.h>
using namespace std;

bool isWildcardMatch(char str[], char pattern[], int n, int m)
{
	// empty pattern can only match with empty string
	if (m == 0)
		return (n == 0);

	// 2d array for storing results of subproblems
	bool table[n + 1][m + 1];

	// initailze table to false
	memset(table, false, sizeof(table));

	// empty pattern can match with empty string
	table[0][0] = true;

	// Only '%' can match with empty string
	for (int j = 1; j <= m; j++)
		if (pattern[j - 1] == '%')
			table[0][j] = table[0][j - 1];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			/* 	Two cases if we see a '%'
				a) We ignore ‘%’ character and move to next character in the pattern(‘%’ indicates an empty sequence ).
			 	b) '%' character matches with ith character in input
			*/
			if (pattern[j - 1] == '%')
			{
				table[i][j] = table[i][j - 1] || table[i - 1][j];
			}

			/* Current characters are considered as matching in two cases
				(a) current character of pattern is '_'
				(b) characters are matched
			*/
			else if (pattern[j - 1] == '_' || str[i - 1] == pattern[j - 1])
			{
				table[i][j] = table[i - 1][j - 1];
			}

			// If the characters are not matched
			else
				table[i][j] = false;
		}
	}

	return table[n][m];
}

int main()
{
	char str[100];
	char pattern[100];
	scanf("%s", str);
	scanf("%s", pattern);

	bool check = false;
	check = isWildcardMatch(str, pattern, strlen(str), strlen(pattern));
	
	if (check)
		cout << "Matched" << endl;
	else
		cout << "Not Matched" << endl;

	return 0;
}
