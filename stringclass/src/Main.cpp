#include <iostream>
#include <mystring>


int main ()
{
 
  myspace::string s0("Initial string");


  // constructors used in the same order as described above:
  myspace::string s2(s0);
  myspace::string s3(s0,8,3);
  myspace::string s1;
  myspace::string s4 ("A character sequence", 6);
  myspace::string s5 ("Another character sequence");
  myspace::string s6a (10, 'x');
  myspace::string s6b (10, 42);      // 42 is the ASCII code for '*'
  myspace::string s7 (s0.begin(), s0.begin()+7);
  myspace::string s8 = (s6b+s6a)+(s3+s2)+(s4+s5); 
  myspace::string s9("HS9"); 
  myspace::string s10("HS10");
  myspace::string firstlevel ("com");
  myspace::string secondlevel ("cplusplus");
  myspace::string scheme ("http://");
  myspace::string hostname ("as");
  myspace::string url;
  s1 = s6a;

   
  std::cout << "\ns1: " << s1.size() << "\ns2: " << s2 << "\ns3: " << s3;
  std::cout << "\ns4: " << s4 << "\ns5: " << s5 << "\ns6a: " << s6a;
  std::cout << "\ns6b: " << s6b << "\ns7: " << '\n';
  std::cout << "\ns8: " << s8<< '\n';
  std::cout << "\ns9: " << s9<< '\n';
  std::cout << "\ns10: " << s10<< '\n';

  hostname = "www." + secondlevel + '.' + firstlevel + 'c';
  url = scheme + hostname;
  std::cout << url << '\n';
  return 0;
}
