#include <fstream>
using std::ofstream;
#include <string>
using std::string;
//bad form, but for now, since its only 1 pin being used
//we just never export
//exporting when already exported might throw

int main(int argc, char **argv)
{

	int status=0;

	if(argc < 2)
	{
		status=1;
		return status;
	}
	string pin=argv[0];
	string command=argv[1];

	string p1="/sys/class/gpio";
	string p2=p1+"/gpio"+pin;

	ofstream gpio;

	try
	{
		string path=p1+"export";
		gpio.open(path.c_str());
		gpio<<pin;
		gpio.close();
	}
	catch(...)	//catch all no throw
	{}

	path=p2+"/direction";
	gpio.open(path.c_string());
	gpio<<"out";
	gpio.close();

	path=p2+"/value";
	gpio.open(path.c_string());
	gpio<<command;
	gpio.close();

	return status;
}
