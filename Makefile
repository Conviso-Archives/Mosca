CC=gcc

#CFLAGS=-W -Wall -Wextra -g
CFLAGS=-W -Wall -Wextra  -Ofast -fstack-protector-all
#DFLAGS=-D_FORTIFY_SOURCE=2

#LDFLAGS=-lpcre 
LDFLAGS=-Wl,-z,relro,-z,now -lpcre 

mosca: mosca.c 
	$(CC) $(CFLAGS) $(DFLAGS) -c *.c
	$(CC) -o mosca *.o $(LDFLAGS)

clean:
	rm -f *.o mosca
