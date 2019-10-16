

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
	
turnon.o: turnon.cpp turnon.h xmlParser.h
	g++ -c turnon.cpp
	
attack.o: attack.cpp attack.h xmlParser.h
	g++ -c attack.cpp
	
border.o: border.cpp border.h xmlParser.h
	g++ -c border.cpp

condition.o: condition.cpp condition.h xmlParser.h
	g++ -c condition.cpp

trigger.o: trigger.cpp condition.h xmlParser.h
	g++ -c trigger.cpp
	
item.o: item.cpp item.h xmlParser.h  turnon.h
	g++ -c item.cpp

extraFunctions.o: extraFunctions.cpp extraFunctions.h xmlParser.h trigger.h item.h
	g++ -c extraFunctions.cpp
	
container.o: container.cpp container.h xmlParser.h item.h trigger.h extraFunctions.h
	g++ -c container.cpp
	
room.o: room.cpp room.h xmlParser.h extraFunctions.h trigger.h container.h creature.h border.h item.h
	g++ -c room.cpp

xmlTesting.o: xmlTesting.cpp xmlParser.h room.h container.h extraFunctions.h item.h trigger.h condition.h border.h attack.h turnon.h
	$(CC) -c xmlTesting.cpp
	
xmlTesting: xmlTesting.o xmlParser.o
	$(CC) xmlTesting.o -o xmlParser.o room.o container.o extraFunctions.o item.o trigger.o condition.o border.o attack.o turnon.o  xmlTesting -L/usr/local/lib
	

clean:
	rm -f *.o  xmlTesting
