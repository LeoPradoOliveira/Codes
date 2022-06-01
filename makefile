TARGET = listas

all:
	make compilar
	make run
	make clean

compilar: main.c leo.c leo.h
	gcc -o $(TARGET) main.c leo.c leo.h

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)
