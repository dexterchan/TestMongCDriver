#include "MyMongoClient.h"
#include <iostream>

int main (int argc, char *argv[])
{

	MyMongoClient* cl = MyMongoClient::createInstance("mongodb://ec2-54-244-75-252.us-west-2.compute.amazonaws.com:27017");

	cl->connect("SUSTP","live");
	std::string result=cl->pingDB();

	std::cout<<result<<std::endl;

	return 0;
}