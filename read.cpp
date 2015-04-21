#include <stdio.h>
#include "Mysql.h"

using namespace std;

int main(int argc, char *argv[])
{
  Mysql mysql("localhost", "root", "none", "process_control");

  // Run the query on the database
  mysql.query("SELECT * FROM mixer_temp");
  mysql.results();
  return 0;
}