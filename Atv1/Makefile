#Nome do executavel
PROJ = exec

#arquivos dos .o .h e .cpp
FILE_OBJ = obj/
FILE_INC = includes/
FILE_CPP = cpp/

#verifica se a pasta obj existe
MKDIR = $(shell test ! -d obj && echo mkdir obj)

#compilador
CC = g++

#flags
FLAGS = -std=c++11 -Wall -pedantic -g -O0

#flags dos .o
OBJ_FLAG = -c -o $@ $<

#.o para criar o executavel
OBJS = $(FILE_OBJ)main.o $(FILE_OBJ)funcoes.o $(FILE_OBJ)concessionaria.o $(FILE_OBJ)automovel.o $(FILE_OBJ)tempo.o

all: create $(PROJ)

create:
	$(MKDIR)

$(PROJ): $(OBJS)
	$(CC) $(FLAGS) -o $@ $(OBJS)

$(FILE_OBJ)main.o: $(FILE_CPP)main.cpp $(FILE_INC)funcoes.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)funcoes.o:$(FILE_CPP)funcoes.cpp $(FILE_INC)funcoes.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)concessionaria.o: $(FILE_CPP)concessionaria.cpp $(FILE_INC)concessionaria.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)automovel.o: $(FILE_CPP)automovel.cpp $(FILE_INC)automovel.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

$(FILE_OBJ)tempo.o: $(FILE_CPP)tempo.cpp $(FILE_INC)tempo.h
	$(CC) $(FLAGS) $(OBJ_FLAG)

run:
	./$(PROJ)

clean:
	rm -rf $(FILE_OBJ)*.o $(PROJ)