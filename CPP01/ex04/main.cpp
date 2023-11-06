#include <iostream>
#include <fstream>
#include <string>

using std::endl;
using std::cout;
using std::string;
using std::ofstream;
using std::ifstream;

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		cout << "Usage : ./ex04 <filename> <to find> <to replace>" << endl;
		return -1 ;
	}
	string		filename = argv[1];
	ifstream	ifs(argv[1]);
	if(ifs.fail())
	{
		cout << "Error : invalid filename" << endl;
		return -1 ;
	}
	string		buffer;
	size_t		index;
	ofstream	ofs(filename + ".replace");
	string		s1 = argv[2];
	while (!std::getline(ifs, buffer).eof())
	{
		index = buffer.find(s1);
		while(index != string::npos)
		{
			buffer.erase(index, s1.length());
			buffer.insert(index, argv[3]);
			index = buffer.find(s1);
		}
		ofs << buffer;
		ofs << endl;
	}
	ofs.close();
	ifs.close();
	return 0 ;
}
