VPATH=src:include
main:main.o LinkList.o DataList.o
	gcc -o $@ $<
main.o:main.c
	gcc -o $@ $^
LinkList.o:LinkList.c
	gcc -o $@ $<
DataList.o:DataList.c
	gcc -o $@ $<