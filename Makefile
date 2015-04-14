# Simple makefile

CC=g++
LD=gcc

# Define object files and debug info
CCFLAGS=-c -g

OBJS=main.o Mysql.o

# Linker info: Include libraries and debug info
LDFLAGS=-I/usr/include/mysql -lmysqlclient -lm

main: $(OBJS)
	@echo "Linking"
	# @see http://ubuntuforums.org/showthread.php?t=1666018&p=10351570#post10351570
	# @see http://stackoverflow.com/questions/6045809/problem-with-g-and-undefined-reference-to-gxx-personality-v0?answertab=votes#tab-top
	$(LD) $(LDFLAGS) $(OBJS) -o main `mysql_config --cflags --libs` -lstdc++

main.o: main.cpp
	@echo "Compiling main!"
	$(CC) $(LDFLAGS) $(CCFLAGS) main.cpp -o main.o

Mysql.o: Mysql.cpp
	@echo "Compiling mysql class"
	$(CC) $(LDFLAGS) $(CCFLAGS) Mysql.cpp -o Mysql.o

clean:
	@echo "Removing object files and executables"
	rm *.o
	rm main