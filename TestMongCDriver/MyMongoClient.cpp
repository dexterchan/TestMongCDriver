#include "MyMongoClient.h"
#include <bson.h>
#include <bcon.h>
#include <mongoc.h>

bool MyMongoClient::initialized=false;

MyMongoClient::MyMongoClient(){
	mongoc_init ();
}
bool MyMongoClient::connect(std::string conn){
	bool result=false;



	return result;
}