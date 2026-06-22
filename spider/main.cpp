#include <iostream>
#include "http_utils.h"
#include "parser.h"
#include "database.h"
#include "crauler.h"




int main()
{   
	
	try {

   
	ParcerIni ini("/home/nikita/Desktop/FinalProject/config.ini");
	 
	std::string host     = ini.getParam("database", "host");
	 
	std::string port     = ini.getParam("database", "port");
	 
	std::string dbname   = ini.getParam("database", "name");
	 
	std::string user     = ini.getParam("database", "user");
	
	std::string password = ini.getParam("database", "password");
	 

	std::string data = "host=" + host
                 + " port=" + port
                 + " dbname=" + dbname
                 + " user=" + user
                 + " password=" + password;
    Database db(data);
	
	Crauler spider(ini, db);
	 
	spider.run();
	}
	catch(const std::exception & error){
		std::cout << error.what() << std::endl;
	}

	return 0;
}
