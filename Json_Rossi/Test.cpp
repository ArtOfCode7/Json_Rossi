#include <string>
#include <set>
#include <iostream>
#include "Json_Rossi.h"

static void testJson()			//°×ºĞ²âÊÔ
{

}

static void parseStdin()		//ºÚºĞ²âÊÔ
{

}

int main(int argc, char **argv)
{
	if (argc == 2 && argv[1] == std::string("--stdin"))
	{
		parseStdin();
		return 0;
	}
	testJson();
}