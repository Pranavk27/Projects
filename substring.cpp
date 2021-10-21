#include <iostream>

using namespace std;

const char *mystrstr(const char *source, const char *pattern)
{
	const char *pBegin = pattern;
	while(*source)
	{
		while(*source != *pattern)
			source++;
		while(*source && *pattern && *source == *pattern)
		{
			source++;
			pattern++;
		}
		if(!*pattern)
			return source;
		else
			pattern = pBegin;
	}
	return NULL;
}

int main()
{
	char *source = "abdgcaabdab";
	cout << mystrstr(source, "abc");
	return 0;
}
