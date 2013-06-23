/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Filename:	ByteFunctions.c	
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Author:		Jonathan Burrows
 |	Date:		November 15th 2012
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
#include "ByteFunctions.h"

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Subroutine:	print_byte_list
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
void print_byte_list(byte* head){
	byte* conductor;										/*Used to transverse the list.*/
	
	/*	Staring from the head of the list, the elements of the list are printed to the 
		screen sequencially.	*/
	conductor = head;
	/*	Continues to get next element in the list until the end is reached.	*/
	while(conductor!=NULL){
		fprintf(stdout, "%s ",conductor->bits);
		conductor = conductor->next;
	}
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	decimal_to_bits
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
char* decimal_to_bits(int* decimal){
	char* bits;					/*The array where the decimals bit values will be stored.*/
	int i;
	
	/*	Attempts to allocate memory for bits plus a null character, if not possible, 
		NULL is returned.	*/
	if((bits = malloc(9*sizeof(char)))==NULL){/*Room for the 8 bits plus a null terminator*/
		return NULL;
	}
	
	/*	Starting from the end of the array and least significant digit, the 8 most rightmost
		bits character values are stored in bits.	*/
	for(i=7; i >= 0; i--){
		/*	Since the integer values must be converted to character, the last bit value is 
			checked against one*/
		if( ( (*decimal) & 1) == 0){
			bits[i]	= '0';					/*Zero character is stored if bit is not one.*/
		}
		else{
			bits[i]	= '1';					/*One character is stored if bit is zero.*/
		}
		/*	Decimal is logically left shifted by 1 bit.	*/
		(*decimal)	>>= 1;
	}
	
	/*	Character array is ended with a null character.	*/
	bits[8] = '\0';
	
	return bits;
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	int_to_byte_string
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
byte* int_to_byte_string(int decimal, int byte_len){
	byte *head, *tail, *current;						/*Pointers for the list of bytes.*/
	int i;												/*Loop control.*/
	
	/*	The size is checked to be greater than zero.	*/
	if(byte_len > 0){
		/*	The first byte in the list is added.	*/
		current = malloc(sizeof(byte));
		current->bits = decimal_to_bits(&decimal);
		current->next = NULL;
		current->prev = NULL;
		head = current;
		tail = current;
	}
	
	/*	The rest of the nodes are added, starting from the end, until the length of the list
		matches byte_len.	*/
	for(i=1; i<byte_len; i++){
		/*	A new node is created and added to the front of the list.	*/
		current = malloc(sizeof(byte));
		current->bits = decimal_to_bits(&decimal);
		current->prev = NULL;
		current->next = head;
		
		head->prev = current;
		head = current;
	}
	/*	The first node in the list is returned.	*/
	return head;
}

/*-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 |	Function:	string_to_byte_string
 +-- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
 */
byte* string_to_byte_string(char* word, int byte_len){
	byte* head, *tail, *current;						/*Pointers used in linked list.*/
	int curr_character_value;
	int i;												/*Used for loop control.*/
	/*	Checks to make sure the desired list is not empty, and there is a first character.*/
	if(byte_len > 0 && strlen(word) > 0){
	
		/*	The integer value of the letter at position byte_len in the word is stored-1 
			in curr_character_value. It is checked to see if there is a letter at position 
			byte_len-1 in the word.	*/
		if(i < strlen(word)){
			/*	The integer value of the character is stored in curr_character_value	*/
			curr_character_value = 0;
			
		}
		else{
			/*	Otherwise there is not a letter, it is given a value of zero.	*/
			curr_character_value = (int) word[0];
		}
		/*	Initialises the list and sets the tail.	*/
		current = malloc(sizeof(byte));
		current->bits = decimal_to_bits(&curr_character_value);
		current->next = NULL;
		current->prev = NULL;
		
		head = current;
		tail = current;
	}
	/*	Adds links to the front of the list until the list is of size byte_len	*/
	for(i = 1; i < byte_len; i++){
	
		/*	The integer value of the letter at position i in the word is stored in 
			curr_character_value.	*/
		/*	It is checked to see if there is a letter at position i in the word.	*/
		if(i < strlen(word)){
			/*	The integer value of the character is stored in curr_character_value	*/
			curr_character_value = (int) word[i];
		}
		else{
			/*	Otherwise there is not a letter, it is given a value of zero.	*/
			curr_character_value = 0;
		}
		
		/*	A new node is added to the end of the list.	*/
		current = malloc(sizeof(byte));
		current->bits = decimal_to_bits(&curr_character_value);
		current->next = NULL;
		current->prev = tail;
		
		tail->next = current;
		tail = current;
	}
	
	/*	The start of the linked list is returned.	*/
	return head;
}

