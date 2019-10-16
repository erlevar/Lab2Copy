

#MakeFile to build and deploy the Sample US CENSUS Name Data using ajax
# For CSC3004 Software Development

# Put your user name below:
USER= guidotti1

CC= g++

#For Optimization
#CFLAGS= -O2
#For debugging
CFLAGS= -g

RM= /bin/rm -f

all:  xmlTesting 

xmlParser.o: xmlParser.cpp xmlParser.h
	g++ -c xmlParser.cpp


	
xmlTesting.o: xmlTesting.cpp xmlParser.h
	$(CC) -c xmlTesting.cpp
	
xmlTesting: xmlTesting.o xmlParser.o
	$(CC) xmlTesting.o xmlParser.o -o xmlTesting -L/usr/local/lib
	


clean:
	rm -f *.o  xmlTesting
