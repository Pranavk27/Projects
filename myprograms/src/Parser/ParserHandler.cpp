#include <ParserHandler>

using Parser::ParserHandler;
using Parser::FileParser;
using Parser::FileType;
using Parser::RSSFeed;
using Parser::RSSFeedParser;

ParserHandler::ParserHandler(){
}

ParserHandler::~ParserHandler(){
}

RSSFeed::RSSFeed(){
}

RSSFeed::~RSSFeed(){
}

int RSSFeed::RSSFeedAddToList(std::string Key, std::string Value){
	std::cout << "Appending " << Key << " " << Value << std::endl; 
	RssFeedInfo.insert(std::pair<std::string,std::string>(Key,Value));
	return 0;
}

RSSFeedParser::RSSFeedParser(std::string FileName){
	std::string FileLine;
	std::vector<std::string> vec;
	std::ifstream  infile;      // create stream
	auto start = 0;
	auto i = 0;
	infile.open(("/home/inpkumbhar/myprograms/bin/" + FileName).c_str());
	std::cout << FileName << std::endl; 
	infile.seekg(0,std::ios::beg);
	char c;
	FileLine="";
	while(infile.get(c))
	{
		if ( c == '<' )
		{
			FileLine.erase(std::remove_if(FileLine.begin(), FileLine.end(), isspace),FileLine.end());
			if ( !FileLine.empty() )
			{
				vec.push_back(FileLine);
				std::cout << "FileLine: " << FileLine << std::endl;
			}
			FileLine.erase();
		}
		if ( c != '\n' && c != ' ' )
		{
			FileLine += c;
		}
		if ( c == '>' )
		{
			vec.push_back(FileLine);
			std::cout <<  "FileLine: " << FileLine << std::endl;
			FileLine.erase();
		}
	}
	for (auto line: vec)
	{
		std::cout << "Vec to Map" << line << " " << start << std::endl; 
		if ( line.front() == '<' && line[1] == '/' && line.find("title") != std::string::npos )
		 start--;
		if ( start )
		{
			i++;
			RSSFeedAddToList("Title" + std::to_string(i), line);
		}
		if ( line.front() == '<' && line[1] != '/' && line.find("title") != std::string::npos )
			start++;
	}
	infile.close();
}

RSSFeedParser::~RSSFeedParser(){
}

std::string RSSFeedParser::RSSSearchWord(std::string Search){
	for (auto value: RssFeedInfo)
	{
		std::cout << "Map: " << value.first << " " << value.second << std::endl; 
		std::size_t found = (value.second).find(Search);
		std::cout << found;
		if ( found != std::string::npos )
			return value.second;
	}
	return "None";
}

FileType::FileType(){
}

FileType::FileType(string filetype){
	this->filetype = filetype;
}

FileType::~FileType(){
}

std::string FileType::GetFileType(){
	return filetype;
}

int FileParser::ParseFile(std::string Word){
	std::cout << "Parsing file " << filename << " of file type "
		<< filetype.GetFileType() << std::endl;
	if ( ! filetype.GetFileType().compare("RSS") )
	{
		RSSFeedParser* RssParser = new RSSFeedParser(filename);
		std::cout << RssParser->RSSSearchWord(Word);
	}
		
	return 0;
}

FileParser::FileParser(std::string filename,FileType ft){
	this->filename = filename;
	filetype = ft;
}

FileParser::~FileParser(){
}
