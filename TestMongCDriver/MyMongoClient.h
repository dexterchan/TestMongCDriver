#include <memory>
#include <string>
#include <bson.h>
#include <bcon.h>
#include <mongoc.h>
#include <exception>

class MyMongoClient{
	std::string connStr;
	static bool initialized;
	mongoc_client_t      *client;
	mongoc_database_t    *mydatabase;
	mongoc_collection_t  *mycollection;
private:
	MyMongoClient();
public:
	//Get a instance of client with a connection string of Mongo
	//e.g.mongodb://<hostname>:<port>
	static MyMongoClient* createInstance(std::string conn);

	//Connect database "db_name" and collection "coll_name"
	bool connect(std::string database,std::string collection);

	//throw exception when connect failed
	std::string pingDB() ;

};