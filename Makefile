CC = gcc
CFLAG = -std=c99 -Wall -pedantic

all: test_getbytes test_getbits test_bits2ull test_bits2ll test_spff test_dpff

test_getbytes: test_getbytes.o bandb.o
	$(CC) $(CFLAG) -o test_getbytes test_getbytes.o bandb.o
test_getbits: test_getbits.o bandb.o
	$(CC) $(CFLAG) -o test_getbits test_getbits.o bandb.o
test_bits2ull: test_bits2ull.o bandb.o
	$(CC) $(CFLAG) -o test_bits2ull test_bits2ull.o bandb.o
test_bits2ll: test_bits2ll.o bandb.o
	$(CC) $(CFLAG) -o test_bits2ll test_bits2ll.o bandb.o
test_spff: test_spff.o bandb.o
	$(CC) $(CFLAG) -o test_spff test_spff.o bandb.o
test_dpff:	test_dpff.o bandb.o
	$(CC) $(CFLAG) -o test_dpff test_dpff.o bandb.o

test_getbytes.o: test_getbytes.c
	$(CC) $(CFLAG) -c test_getbytes.c -o test_getbytes.o
test_getbits.o: test_getbits.c
	$(CC) $(CFLAG) -c test_getbits.c -o test_getbits.o
test_bits2ull.o: test_bits2ull.c
	$(CC) $(CFLAG) -c test_bits2ull.c -o test_bits2ull.o
test_bits2ll.o: test_bits2ll.c
	$(CC) $(CFLAG) -c test_bits2ll.c -o test_bits2ll.o
test_spff.o: test_spff.c
	$(CC) $(CFLAG) -c test_spff.c -o test_spff.o
test_dpff.o: test_dpff.c
	$(CC) $(CFLAG) -c test_dpff.c -o test_dpff.o
bandb.o: bandb.c
	$(CC) $(CFLAG) -c bandb.c -o bandb.o

clean:
	rm *.o test_getbytes test_getbits test_bits2ull test_bits2ll test_spff test_dpff