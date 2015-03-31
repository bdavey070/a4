
# Flags that are sent to the compiler
# Do not change these
CFLAGS      =	-Wall  -pedantic -g -Iinclude


diary:
	gcc $(CFLAGS)  src/foodDiary.c src/foodDiaryFunctions.c src/linkedList.c -o bin/foodDiary

test: 
	gcc $(CFLAGS) src/test.c src/linkedList.c -o bin/listTest

clean:
	@ rm *.o

testRun:
	./bin/listTest docs/testFile.txt

diaryRun:
	./bin/foodDiary docs/diaryTest.txt
