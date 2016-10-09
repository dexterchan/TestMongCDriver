#include <memory>
#include <string>
class MyMongoClient{
	std::string connStr;
	static bool initialized;
private:
	MyMongoClient();
public:
	static MyMongoClient* createInstance(std::string conn);
	bool connect(std::string conn);

};