#include <stdio.h>
#include <my_global.h>
#include <mysql.h>

class Mysql
{
private:
    MYSQL *connection;

    MYSQL_ROW row;

    MYSQL_RES *result;

    void _error();

public:

    Mysql(const char*, const char*, const char*, const char*);

    ~Mysql();

    void query(const char*);

    void results();
};