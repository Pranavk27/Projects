#include <iostream>
#include <string>

using namespace std;

int Permutation(string strWord,string prefix, long ldepth, string strSp)
{
	long depth = ++ldepth;
	string strSpace = strSp + " ";

	if(strWord.length() == 0)
	{
		cout << "Prefix: " << prefix << endl;
	}
	else
	{
		cout << strSpace << ">> Permutation " << depth << endl;
		for( int i =0 ; i < strWord.length() ; i++)
		{
			cout << i <<"]" << endl;
			string rem = strWord.substr(0,i) + strWord.substr(i+1);
			cout << " Word: " << strWord << " Rem: " << rem << " Prefix: " << prefix  << endl;
			Permutation(rem ,prefix + strWord[i], depth, strSpace);
		}
	}
	cout << strSpace << "<< Permutation " << depth << endl;
	return 0;
}
int main(int argc, char *argv[])
{
	if ( argc == 2 )
	{
		string strWord = argv[1];
		Permutation(strWord,"",0,"");
	}
	return 0;
}
