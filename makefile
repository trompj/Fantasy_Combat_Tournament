#Author: Justin Tromp
#01/10/2019
#Title: makefile

#Project name
PROJECT = Project_4

#Compiler
#C=g++                                  #Use for C
CXX=g++

#Options to be passed/compiler flags
#CFLAGS=-pedantic -std=gnu++11 -Wall    #Use for C
LDFLAGS=-lboost_date_time
CXXFLAGS=-pedantic
CXXFLAGS+=-std=gnu++11
CXXFLAGS+=-Wall
#CXXFLAGS+=-03

#Source files
SOURCES=main.cpp Barbarian.cpp BlueMen.cpp Character.cpp FantasyGame.cpp HarryPotter.cpp inputValidation.cpp Medusa.cpp Menu.cpp Vampire.cpp Queue.cpp

#Header files
HEADERS=Barbarian.hpp BlueMen.hpp Character.hpp FantasyGame.hpp HarryPotter.hpp inputValidation.hpp Medusa.hpp Menu.hpp Vampire.hpp Queue.hpp

#Objects
OBJECTS=$(SOURCES:.cpp=.o)

#Output Binary
BINARY=$(PROJECT).bin

#Valgrind Options
VALGRIND= --leak-check=full --show-leak-kinds=all --tool=memcheck --track-origins=yes

#Executable name
EXECUTABLE=Project_4


.PHONY: default debug clean zip

default: clean $(BINARY) debug


debug: $(BINARY)
	@valgrind $(VALGRIND) ./$(BINARY)

$(BINARY): $(OBJECTS)
	@echo "CXX	$@"
	@$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	@echo "CXX	$^"
	@$(CXX) $(CXXFLAGS) -c $^

zip:
	zip $(PROJECT).zip *.cpp *.hpp makefile *.pdf *.txt

clean: $(CLEAN)
	@echo "RM	*.o"
	@echo "RM	$(BINARY)"
	@rm -f *.o $(BINARY)