# Binary-Number-Representation-Project
This project helps to understand how the different number representations (long long, unsigned long long, single precision floating point numbers, and double precision floating point numbers) are stored in binary and can be converted to their respective formats.

## running the program
compiled with: make all
run test_getbytes test_getbits test_bits2ull test_bits2ll test_spff test_dpff by adding ./prefix e.g. ./test_getbytes

## test_getbytes
Tests the function test_getbytes that copies a string to a destination in either normal or reverse order

## test_getbits
Tests the test_getbits function that converts an integer to a string containing its binary representation within a range specified

## test_bits2ull
Tests the function test_bits2ull that converts string with the binary representation of an unsigned long long to an unsigned long long

## test_bits2ll
Tests the function test_bits2ll that converts string with the binary representation of a long long to a long long

## test_spff
tests the function test_spff that takes a long number and returns the strings of the binary representations of the sign bit, exponent and significand

## test_dpff
tests the function test_dpff that takes a double number and returns the strings of the binary representations of the sign bit, exponent and significand
