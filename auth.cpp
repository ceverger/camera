#include <string>
#include <iostream>
#include <fstream>

	int main(int argc, char *argv[])
	{
		std::string str;
		std::ifstream fin;
		std::ofstream fout;

		std::cin >> str; // Get json from web-server	

		fout.open("auth.txt", std::ios_base::trunc | std::ios_base::out);
		if(!fout.is_open())
		{
			std::cout << "Content-type: application/json\n\n";
			std::cout << "{'status':'false'}\n";
		}

		fout << str << '\n'; // Write json in auth.txt
		fout.close();		
		
		// Send json to web-server
		std::cout << "Content-type: application/json\n\n";
		std::cout << "{\"status\":\"true\"}\n";

		return 0;
	}

