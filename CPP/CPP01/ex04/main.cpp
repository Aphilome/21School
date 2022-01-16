#include <iostream>
#include <fstream>

bool readArgc(int argc, char **argv,
			  std::string &filename, std::string &s1, std::string &s2)
{
	if (argc != 4)
	{
		std::cout	<< "Error: wrong arguments count"
					<< std::endl;
		return false;
	}
	filename = argv[1];
	s1 = argv[2];
	s2 = argv[3];
	if (filename.empty() || s1.empty() || s2.empty())
	{
		std::cout	<< "Error: argument(s) does not exist(s)"
					<< std::endl;
		return false;
	}
	return true;
}

bool getBuf(std::string filename, std::string &buf)
{
	std::ifstream ifile(filename);
	if (!ifile.is_open() || ifile.fail() || ifile.eof() || ifile.bad())
	{
		std::cout	<< "Error: open file"
					<< std::endl;
		return false;
	}
	buf.assign(std::istreambuf_iterator<char>(ifile),
			   std::istreambuf_iterator<char>());
	return true;
}

int main(int argc, char **argv)
{
	std::string filename;
	std::string s1;
	std::string s2;
	if (!readArgc(argc, argv, filename, s1, s2))
		return 1;
	std::string	buf;
	if (!getBuf(filename, buf))
		return 1;
	std::transform(filename.begin(), filename.end(), filename.begin(),::toupper);
	std::ofstream ofile(filename + ".replace");
	std::size_t found = buf.find(s1);
	while (found != std::string::npos)
	{
		buf.erase(found, s1.length());
		buf.insert(found, s2);
		found = buf.find(s1, found + s2.length());
	}
	ofile << buf;
	return 0;
}
