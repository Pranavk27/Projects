#include <iostream>
#include <ParserHandler>

using namespace Parser;

main(int argc,char *argv[]){
	if ( argc != 2 )
		return 1;
	std::string word = argv[1];
	std::string filename = "livescores.xml";
	std::string filetype = "RSS";
	FileParser* ph = new FileParser(filename,FileType(filetype));
	auto ret = ph->ParseFile(word);
	std::cout << "return value = " << ret << std::endl;
	return 0;
}
