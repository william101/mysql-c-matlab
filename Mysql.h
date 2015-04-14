#include <my_global.h>
#include <Mysql.h>
#include <string>

class Mysql
{
private:
    MYSQL *connection;

    MYSQL_ROW row;

    MYSQL_RES *result;

    void _error();

public:

    Mysql(string, string, string, database);

    ~Mysql();

    void query(string);

    void results();
}