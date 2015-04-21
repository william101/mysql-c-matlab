#include <stdio.h>
#include <fstream>
#include <my_global.h>
#include <data.h>
#include <string>


class data
{
private:
   File *filepointer;

   OurData dataReader;

public:

    data();

    ~data();
     void dataReader();

};


