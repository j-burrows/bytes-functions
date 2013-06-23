/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	ByteFunctions.h
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Author:		Jonathan Burrows
 |	Date:		November 15th 2012
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#ifndef BYTE_FUNCTIONS_H
#define BYTE_FUNCTIONS_H 1

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Byte.h"

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	print_byte_list
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 | 	Purpose:	Print out an list of byte's bit contents.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		head,	the starting node of the linked list of bytes that will be printed.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	Starting at the head, the list is traversed until the conductor reads NULL. 
 |				Every bytes character string of bits is printed to screen.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
void print_byte_list(byte* head);

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	decimal_to_bits
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Returns the 8 leftmost bits of a decimal in a character array.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		decimal, 	a reference to a decimal number whos rightmost 8 bits will be 
 |							stored in an character array.
 |	@return		bits, 		an array of characters whos contents match the rightmost bits 
 |							of a decimals binary digits. 
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	For eight itterations, the decimal is checked to see if it is one. If it is, 
 |				the rightmost digit is a zero, otherwise, it is z one. The character 
 |				representation is put into the furthest unfilled spot of the character 
 |				array bits. The decimal is logically left shifted by 1 bit. 8 itterations 
 |				are made, the character array is ended with a null character and returned.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Notes:		In order to get the bits in correct order of significance, the bits must be 
 |				added from the end of the array, with still room for the null character.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
char* decimal_to_bits(int* decimal);

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	int_to_byte_string
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Converts a decimal into a linked list of binary bytes and return the 
 |				reference to the start of the list.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		decimal, 	the value whos bit value will be stored in the bits of the list.
 |				byte_len,	the length of the list that will be returned.
 |	@return:	head,		a reference to the head of the created linked list of bytes.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	3 pointers are made for a linked list. If list size is greater than zero, a
 |				new byte is made, and the tail and head are pointed to it. Links then are 
 |				continously added to the front of the list until the list size matches 
 |				byte_len. Each itteration creates a new node whos next is head, and the 
 |				head's prev is it. The head of the list is then returned.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Notes:		To get the list of bytes in the correct order of significance, the list must 
 |				be a doubly linked list, and characters must be added to the front of list.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
byte* int_to_byte_string(int decimal, int byte_len);

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	string_to_byte_string
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Purpose:	Converts a string of characters into a linked list of binary bits and returns
 |				the reference to the start of the list.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	@param:		word,	the string of characters that will be converted into a linked list 
 |				of bytes. byte_len, the length of the linked list that will be made.
 |	@return:	head, a reference to the start of the linked list who holds the byte value 
 |				of the given word.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Algorithm:	A linked list head and current are declared with the heads bit value equal 
 |				to the integer value of the words value at the first position. Until the 
 |				list is of size byte_len, links are added to the end of with byte values 
 |				equal to the integer values of the character at the current position in 
 |				the word. A reference to the head of the list is then returned.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Notes:		There is a chance that the word's size is less than the byte_len. For that 
 |				reason, if the position of the list trying to be filled is greater or equal 
 |				to the size, the value is simply zero.
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
byte* string_to_byte_string(char* word, int byte_len);


#endif
