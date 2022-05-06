#include <iostream>
#include <fstream>

void replace_all(std::string &src, std::string old_str, std::string new_str)
{
	while (src.find(old_str) != std::string::npos)
	{
		std::size_t found = src.find(old_str);
		std::string back = src.substr(0, found);
		std::string front = src.substr(found + old_str.length());
		src.clear();
		src = back + new_str + front;
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cerr << "Wrong arguments!" << std::endl;
		return (-1);
	}
	std::fstream file;
	file.open(argv[1], std::ios::in);
	if (file.fail())
	{
		std::cerr << "file could not be read!" << std::endl;
		return (-1);
	}
	char in;
	std::string context;
	while ((in = file.get()) != EOF)
		context += in;
	replace_all(context, argv[2], argv[3]);
	file.close();
	file.open(std::string(argv[1]) + ".repleace", std::ios::out);
	if (file.fail())
	{
		std::cerr << "file could not be read!" << std::endl;
		return (-1);
	}
	file << context;
	file.close();
}
