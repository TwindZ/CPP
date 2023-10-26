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
	( void ) argv;
	( void ) argc;
	if(argc != 4)
	{
		cout << "Usage : ./ex04 <filepath> <to find> <to replace>" << endl;
		return -1 ;
	}
	string buffer;
	size_t index;
	ifstream ifs(argv[1]);
	ofstream ofs("testcopy.txt");
	string s1 = argv[2];
	string s2 = argv[3];
	do
	{
		index = buffer.find(s1);
		cout << index << endl;
		if(index != string::npos)
			buffer.erase(index, s1.length());
		cout << index << endl;
		
		buffer.insert(index, s2);
		ofs << buffer;
		if(std::getline(ifs, buffer).eof())
			break;
		ofs << endl;
	}while(42);
		

	

	return 0 ;

}
