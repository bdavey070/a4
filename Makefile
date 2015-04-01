
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall  -pedantic -std=c99 -g -Iinclude -lm 


diary:
	gcc $(CFLAGS)  src/main.c src/diary.c src/linkedList.c -lm -o bin/foodDiary

test: 
	gcc $(CFLAGS) src/testMain.c src/linkedList.c -o bin/listTest

clean:
	@ rm *.o

testRun:
	./bin/listTest 

diaryRun:
	./bin/foodDiary assets/test.txt
