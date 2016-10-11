linkedList: linkedList.c
	gcc linkedList.c -o linkedList.out

clean: 
	rm *~

run: linkedList.out
	./linkedList.out
