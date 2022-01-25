CC=g++
CFLAGS = -g -Wall
DFLAGS = -DDEBUG
TARGET = mypc
VPATH = .:model
SOURCE = grammar.tab.cpp lex.yy.cpp token.cpp tree.cpp node.cpp scope.cpp scopeMan.cpp
OBJECTS = grammar.tab.o lex.yy.o token.o tree.o node.o scope.o scopeMan.o
LIBS = -ll -ly

all: $(TARGET) $(OBJECTS)

$(TARGET): $(OBJECTS) 
	$(CC) $(CFLAGS) $(DFLAGS) -o $(TARGET) $(OBJECTS) $(LIBS)
.cpp.o:
	$(CC) $(CFLAGS) $(DFLAGS) -c $<
grammar.tab.cpp: grammar.y
	bison -dv -o grammar.tab.cpp grammar.y
lex.yy.cpp: scanner.l
	flex -l -o lex.yy.cpp scanner.l
clean:
	rm -rf grammar.tab.* lex.yy.*  *.o grammar.output
