CC=gcc

#CFLAGS=-W -Wall -Wextra -g
CFLAGS=-W -Wall -Wextra  -O2 -g -fstack-protector-all
DFLAGS=-D_FORTIFY_SOURCE=2
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Darwin)
	LDFLAGS= -lpcre 
else
	LDFLAGS=-Wl,-z,relro,-z,now -lpcre 
endif


mosca: mosca.c 
	$(CC) $(CFLAGS) $(DFLAGS) -c *.c
	$(CC) -o mosca *.o $(LDFLAGS)

clean:
	rm -f *.o mosca
