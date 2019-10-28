

#MakeFile to build and deploy the Sample US CENSUS Name Data using ajax
# For CSC3004 Software Development

# Put your user name below:
USER= guidotti1

#hi this is savannah making an edit to the makefile! i like cats

CC= g++

#For Optimization
#CFLAGS= -O2
#For debugging
CFLAGS= -std=c++14

RM= /bin/rm -f

all:  main

xmlParser.o: xmlParser.cpp xmlParser.h
	$(CC) $(CFLAGS) xmlParser.cpp -c
	
turnon.o: turnon.cpp turnon.h xmlParser.h
	$(CC) $(CFLAGS) turnon.cpp -c
	
condition.o: condition.cpp condition.h xmlParser.h 
	$(CC) $(CFLAGS) condition.cpp -c
		
item.o: item.cpp item.h xmlParser.h turnon.h extraFunctions.h
	$(CC) $(CFLAGS) item.cpp -c
	
attack.o: attack.cpp attack.h xmlParser.h
	$(CC) $(CFLAGS) attack.cpp -c
	
border.o: border.cpp border.h xmlParser.h
	$(CC) $(CFLAGS) border.cpp -c
	
trigger.o: trigger.cpp condition.h xmlParser.h 
	$(CC) $(CFLAGS) trigger.cpp -c

extraFunctions.o: extraFunctions.cpp extraFunctions.h xmlParser.h trigger.h item.h
	$(CC) $(CFLAGS) extraFunctions.cpp -c
	
container.o: container.cpp container.h xmlParser.h item.h trigger.h extraFunctions.h
	$(CC) $(CFLAGS) container.cpp -c
	
creature.o: creature.cpp xmlParser.h attack.h trigger.h item.h
	$(CC) $(CFLAGS) creature.cpp -c
	
room.o: room.cpp room.h xmlParser.h extraFunctions.h trigger.h container.h creature.h border.h item.h turnon.h
	$(CC) $(CFLAGS) room.cpp -c
	
player.o: player.cpp player.h xmlParser.h item.h room.h
	$(CC) $(CFLAGS) player.cpp -c

main.o: main.cpp xmlParser.h room.h container.h extraFunctions.h item.h trigger.h condition.h border.h attack.h turnon.h player.h
	$(CC) -c $(CFLAGS) main.cpp 
	
main: main.o xmlParser.o room.o container.o extraFunctions.o item.o trigger.o condition.o border.o attack.o turnon.o creature.o player.o 
	$(CC) $(CFLAGS) main.o xmlParser.o room.o container.o extraFunctions.o item.o trigger.o condition.o border.o attack.o turnon.o creature.o player.o -o main -L/usr/local/lib
	

clean:
	rm -f *.o  main
