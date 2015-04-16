#include <my_global.h>
#include <mysql.h>
#include "Mysql.h"

/**
 * Constructor
 */
Mysql::Mysql(const char* host, const char* user, const char* password, const char* database)
{
    connection = mysql_init(NULL);

    if (connection == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        exit(1);
    }

    // Create a new connection
    if (mysql_real_connect(connection, host, user, password, database, 0, NULL, 0) == NULL) {
        _error();
    }

}

/**
 * Destructor
 */
Mysql::~Mysql()
{
    mysql_close(connection);
}

/**
 * Run a query on the database
 */
void Mysql::query(const char* sql)
{
    if (mysql_query(connection, sql)) {
        _error();
    }
}

/**
 * Fetch results from the database from the database
 */
void Mysql::results()
{
    result = mysql_store_result(connection);

    if (result == NULL) {
        _error();
    }

    int num_fields = mysql_num_fields(result);

    while ((row = mysql_fetch_row(result))) {
        for(int i = 0; i < num_fields; i++) {
            printf("%s ", row[i] ? row[i] : "NULL");
        }
        printf("\n");
    }

    mysql_free_result(result);

}

/**
 * Display an error message
 */
void Mysql::_error()
{
    fprintf(stderr, "%s\n", mysql_error(connection));
    mysql_close(connection);
    exit(1);
}