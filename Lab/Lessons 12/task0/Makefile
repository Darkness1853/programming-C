# Собрать многофайловый проект
# Подсказка: Опция -I в gcc помогает решить проблему с поиском заголовочных файлов. (#include "" No such file or directory)
# Для использования make его необходимо установить: sudo apt install make 
.PHONY: clean run

start: main.o background.o read_pipe.o write_pipe.o
	gcc -o start main.o background.o read_pipe.o write_pipe.o

main.o: app/main.c background/background.h
	gcc -I background -c app/main.c -o main.o

background.o: background/background.c background/background.h
	gcc -I pipes -c background/background.c -o background.o

read_pipe.o: pipes/read_pipe.c pipes/pipes.h
	gcc -c pipes/read_pipe.c -o read_pipe.o

write_pipe.o: pipes/write_pipe.c pipes/pipes.h
	gcc -c pipes/write_pipe.c -o write_pipe.o

run: start
	./start

clean:
	rm -rf *.o start