//this needs cleaned up, just recycled output program to get input


#include <iostream>
using std::cout;
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
	string pin=argv[1];
	string command=argv[2];

//	cout<<"Debug - commands = "<<pin<<" "<<command<<"\n";

	string p1="/sys/class/gpio";
	string p2=p1+"/gpio"+pin;
	string path;

	ofstream gpio;

	try
	{
		path=p1+"/export";
		cout<<"Debug - path = "+path;
		gpio.open(path.c_str());
		gpio<<pin;
		gpio.close();
	}
	catch(...)	//catch all no throw
	{
		cout<<"caught something\n";
	}

	path=p2+"/direction";	
//	cout<<"Debug - path = "+path;
	gpio.open(path.c_str());
	gpio<<"in";
	gpio.close();


	ifstream gpioIn;
	int value;

	path=p2+"/value";
	//cout<<"Debug - path = "+path;	
	gpioIn.open(path.c_str());
	gpioIn>>value;

	gpioIn.close();

	return value;
}
