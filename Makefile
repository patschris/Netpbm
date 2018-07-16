CC		= gcc
CFLAGS	= -g -Wall
EXEC 	= netpbm
OBJS 	= convertion.o main.o readimage.o whitespaces.o writeimage.o
SRCS 	= convertion.c main.c readimage.c whitespaces.c writeimage.c
HEADERS	= convertion.h readimage.h whitespaces.h writeimage.h

.PHONY : all

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

convertion.o: convertion.c
	$(CC) $(CFLAGS) -c convertion.c

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

readimage.o: readimage.c
	$(CC) $(CFLAGS) -c readimage.c

whitespaces.o: whitespaces.c
	$(CC) $(CFLAGS) -c whitespaces.c

writeimage.o: writeimage.c
	$(CC) $(CFLAGS) -c writeimage.c


.PHONY: clean

clean:
	rm -f $(OBJS) $(EXEC)