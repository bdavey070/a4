
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall  -pedantic -std=c99 -g -Iinclude -lm 


diary:
	gcc $(CFLAGS)  src/foodDiary.c src/foodDiaryFunctions.c src/linkedList.c -lm -o bin/foodDiary

test: 
	gcc $(CFLAGS) src/test.c src/linkedList.c -o bin/listTest

clean:
	@ rm *.o

testRun:
	./bin/listTest docs/testFile.txt

diaryRun:
	./bin/foodDiary docs/test3.txt
