# Simple makefile
# @author William Tabi <c11342646@mydit.ie>

CC=g++
LD=gcc

# Define object files and debug info
CCFLAGS=-c -g

# Linker info: Include libraries and debug info
LDFLAGS=-I/usr/include/mysql -lmysqlclient -lm

create: create.o Mysql.o
	@echo "Linking Database seeder"
	# @see http://ubuntuforums.org/showthread.php?t=1666018&p=10351570#post10351570
	# @see http://stackoverflow.com/questions/6045809/problem-with-g-and-undefined-reference-to-gxx-personality-v0?answertab=votes#tab-top
	$(LD) $(LDFLAGS) create.o Mysql.o -o create `mysql_config --cflags --libs` -lstdc++

read: read.o Mysql.o
	@echo "Linking Reader"
	# @see http://ubuntuforums.org/showthread.php?t=1666018&p=10351570#post10351570
	# @see http://stackoverflow.com/questions/6045809/problem-with-g-and-undefined-reference-to-gxx-personality-v0?answertab=votes#tab-top
	$(LD) $(LDFLAGS) read.o Mysql.o -o read `mysql_config --cflags --libs` -lstdc++

create.o: create.cpp
	@echo "Compiling database seed!"
	$(CC) $(LDFLAGS) $(CCFLAGS) create.cpp -o create.o

read.o: read.cpp
	@echo "Compiling database reader!"
	$(CC) $(LDFLAGS) $(CCFLAGS) read.cpp -o read.o

Mysql.o: Mysql.cpp
	@echo "Compiling mysql class"
	$(CC) $(LDFLAGS) $(CCFLAGS) Mysql.cpp -o Mysql.o

clean:
	@echo "Removing object files and executables"
	rm *.o
	rm create
	rm read