#include <mystring>

//using myspace::string;
namespace myspace{

string::string(
		)
{
	str = NULL;
	length = 0;
}

string::string(
		const char *strings
		)
{
	length = strlen(strings);
	str = new char[length+1];
	strcpy(str,strings);
}


string::string(
		const string& objstr
	      )
{
	length = objstr.length;
	str = new char[length+1];
	strcpy(str,objstr.str);
}

string::string(
		const string& objstr,
		int start,
		int cnt
	      )
{
	//length = cnt;
	//str = new char[cnt+1];
	//str = (char*)memcpy(str,&objstr.str[start],cnt);
	//str[length] = '\0';
	str = new char[cnt+1];
	string::iterator it(str);
	string::iterator sit(objstr.str + start);
	string::iterator eit(objstr.str + start + cnt);
	//std::copy(sit, eit, it);
	for(; sit != eit ; sit++ )
	{
		it = sit;
		it++;
	}
	length = cnt;
	it = '\0';
}

string::string(const char *string,int initcnt)
{
	length = initcnt;
	str = new char[initcnt+1];
	str = (char*)memcpy(str,string,initcnt);
	str[length] = '\0';
}

string::string(int lstr,const char chstr)
{
	length = lstr;
	str = new char[lstr+1];
	str = (char*)memset(str,chstr,lstr);
	str[length] = '\0';
}
 
string::string(int lstr,int chstr)
{
	length = lstr;
	str = new char[lstr+1];
	str = (char*)memset(str,chstr,lstr);
	str[length] = '\0';
}

string::string(char *start,char *end)
{
	length=end-start;
	str = new char[length+1];
	str = (char*)memcpy(str,&start,length);
	str[length] = '\0';
}

string::~string(
		)
{
	delete[] str;
	str=NULL;
}

std::ostream& operator<<(std::ostream& output,const string& objstr)
{
	if(objstr.str==NULL) output << "";
	else{
	       	output << objstr.str;
	       	output << " : " << objstr.length;
	}
	return output;
}

std::istream& operator>>(std::istream& output,string& objstr)
{
	output >> objstr.str;
	objstr.length=strlen(objstr.str);
	return output;
}

string& string::operator=(const string& src)
{
	delete[] this->str;
	length = src.length;
	str = new char[length + 1];
	strcpy(str,src.str);
	return *this;
}

string& string::operator=(const char* src)
{
	delete[] this->str;
	length = strlen(src);
	str = new char[length + 1];
	str = strcpy(str,src);
	return *this;
}
string& string::operator=(char c)
{
	delete[] this->str;
	length=sizeof(char);
	str = new char[length + 1];
	str[0] = c;
	str[1] = '\0';
	return *this;
}

string& string::operator+=(const string& src)
{
	operator=(operator+( this->str ,src));
	return *this;
}

string& string::operator+=(const char * src)
{
	operator=(operator+( *this ,src));
	return *this;
}

string& string::operator+=(char src)
{
	operator=(operator+( *this ,src));
	return *this;
}


string operator+(const string& fst,const string& src)
{
	string temp;
	temp.length = fst.length + src.length;
	temp.str = new char[temp.length + 1];
	strcpy(temp.str,fst.str);
	strcpy(&temp.str[fst.length],src.str);
	return temp;
}
string operator+ (const string& fst, const char*   src)
{
	string temp;
	temp.length = fst.length + strlen(src);
	temp.str = new char[temp.length + 1];
	strcpy(temp.str,fst.str);
	strcpy(&temp.str[fst.length],src);
	return temp;
}
string operator+ (const char*   fst, const string& src)
{
	string temp;
	temp.length = strlen(fst) + src.length;
	temp.str = new char[temp.length + 1];
	strcpy(temp.str,fst);
	strcpy(&temp.str[strlen(fst)],(char *)src.str);
	return temp;
}
string operator+ (const string& fst, char src)
{
	string temp;
	temp.length = fst.length + 1;
	temp.str = new char[temp.length + 1];
	strcpy(temp.str,fst.str);
	temp.str[fst.length]=src;
	temp.str[temp.length]='\0';
	return temp;
}
string operator+ (char fst, const string& src)
{
	string temp;
	temp.length = 1 + src.length;
	temp.str = new char[temp.length + 1];
	temp.str[0]=fst;
	strcpy(&temp.str[1],src.str);
	return temp;
}

char* string::begin()
{
	return this->str;
}
size_t string::size() const
{
	return this->length;
}

};
