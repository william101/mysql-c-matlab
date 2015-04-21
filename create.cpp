#include <stdio.h>
#include "Mysql.h"

using namespace std;

int main(int argc, char *argv[])
{
  Mysql mysql("localhost", "root", "none", "process_control");
  float value;
  char sql[100];

  // Generate and Insert random data into the database
  for (int i = 0; i < 100; i++) {
    value = sin(2.0*3.141592 * (double)i/100.0);
    sprintf(sql,"INSERT INTO mixer_temp (`date`, `mixer_temp`) VALUES (NOW(),%f)",value);
    printf("%s\n", sql);
    mysql.query(sql);
  }
  return 0;
}