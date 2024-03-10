#include <map>
#include <list>
#include <string>
#include <iostream>
#include <fstream>

#define bufsize 4096
#define Login "admin"
#define Password "admin"

	// void jsonParser(const std::string & json);

	int main(int argc, char *argv[])
	{
		std::string str;
		std::ifstream fin;
		std::ofstream fout;

		std::cin >> str;	

		fout.open("auth.txt", std::ios_base::trunc | std::ios_base::out);
		if(!fout.is_open())
		{
			std::cout << "Content-type: application/json\n\n";
			std::cout << "{'status':'false'}\n";
		}

		fout << str << '\n';
		fout.close();		
		
		std::cout << "Content-type: application/json\n\n";
		std::cout << "{\"status\":\"true\"}\n";

		return 0;
	}

/*	void jsonParser(const std::string & json)
	{
		std::size_t posBegin = 0;
		std::size_t posEnd = 0;
		list<std::size_t> colons;

		posBegin = json.find('{');
		if(posBegin == std::string::npos)
		{
			std::cout << "Content-type: application/json\n\n";
			std::cout << "{ status: 'parser_error!' }\n";
			return 1;				
		}

		posEnd = json.find('}');
		if(posEnd == std::string::npos)
		{
			std::cout << "Content-type: application/json\n\n";
			std::cout << "{ status: 'Parser error!' }\n";
			return 1;				
		}

		if(posEnd < posBegin)
		{
			std::cout << "Content-type: application/json\n\n";
			std::cout << "{ status: 'Parser error!' }\n";
			return 1;				
		}

		for(std::size_t i = posBegin; i < posEnd; ++i)
		{
			if(json[i] == ':') colons << i;
		}
	}

*/
