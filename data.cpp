#include <stdio.h>
#include <fstream>
#include "data.h"
#include <string>
//#include <mysql.h>




data::data(File*filepointer){



}

data::~data(){



}

void data::dataReader(File*filepointer)
{

    File*filepointer;
	filepointer =fopen("mysql.result", "r");/* filepointer points to mysql.result */


	if (filepointer==NULL) { /* error opening file returns NULL */
	fprintf("Could not open mysql.result!\n"); /* error message */
	return 1; /* exit with failure */
}

