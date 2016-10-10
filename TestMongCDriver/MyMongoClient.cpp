#include "MyMongoClient.h"


bool MyMongoClient::initialized=false;

MyMongoClient::MyMongoClient(){
	if(!initialized){
		if(!initialized){
			mongoc_init ();
		}
	}
	client=NULL;
}

MyMongoClient* MyMongoClient::createInstance(std::string conn){
	MyMongoClient * cl = new MyMongoClient();

	cl->client = mongoc_client_new (conn.c_str());

	return cl;
}
bool MyMongoClient::connect(std::string database,std::string collection){
	bool result=false;

	mydatabase = mongoc_client_get_database (client, database.c_str ());
	mycollection = mongoc_client_get_collection (client, database.c_str (), collection.c_str());

	return result;
}

std::string MyMongoClient::pingDB() {
	bson_t  *command, reply;
	bson_error_t          error;

	command = BCON_NEW ("ping", BCON_INT32 (1));

	bool retval = mongoc_client_command_simple (client, "admin", command, NULL, &reply, &error);

	if (!retval) {
		throw new std::exception(error.message);
	}

	char* str = bson_as_json (&reply, NULL);
	return str;
}