#include <stdio.h>
/* These are notes


--------------
  Bit Fields
--------------

You can specify the number of bits that a variable uses to store information.
Card example:*/

enum cardSuit
{
	CLUBS = 0,
	SPADES,
	DIAMONDS,
	HEARTS
};

struct Card
{
	unsigned int face;  /*4 bytes \                                */
	enum cardSuit suit; //4 bytes  > 12 bytes total
	unsigned int color; //4 bytes /
};

/* but of course, there are only 13 possibilities for face, so you only
need 4 bits, not bytes:*/

struct bitCard
{
	unsigned char face:4;
	unsigned char suit:2;
	unsigned char color:1;
};

/*face uses four bits of the char, suit 2, color 1:

 _______________________________________________________
|      |      |      |      |      |      |      |  \/  |
|______|______|______|______|______|______|______|__/\__|

------------face------------ -----suit---- -color-

(this could be stored in different ways within the byte depending on the machine)


-> BIT FIELDS ARE MACHINE DEPENDENT
-> Bit fields do not have addresses
-> Bit fields save space but may be slower

Basically, no guarantees with bitfields.

Example with bit fields as opposed to bit manipulation (I think?):*/


typedef struct Cards
{
	unsigned char face;
	unsigned char suit;
	unsigned char color;
} cards_t;

typedef struct bfCards
{
	unsigned char face:4;
	unsigned char suit:2;
	unsigned char color:1;
} bfCards_t;


//now he's gonna use a union

typedef union Deck
{
	unsigned char card;
	bfCards_t fields;
} deck_t;

/* we're gonna make an assumption that it's like this:

 _______________________________________________________
|  \/  |      |      |      |      |      |      |      |
|__/\__|______|______|______|______|______|______|______|

       ------------face------------ -----suit---- -color-

	   let black be 0, red 1
	   let clubs 0;
	   spades 1;
	   diamonds 2;
	   hearts 3;

For instance, a Jack of Spades:

Face of 0d11, suit of 0d2, color of 0d0:

 _______________________________________________________
|  \/  |      |      |      |      |      |      |      |
|__/\__|______|______|______|______|______|______|______|
          1      0      1      1      0      1      0    
       ------------face------------ -----suit---- -color-

	   0b1011010 = 0x5A

*/

int main(void)
{
	deck_t deck;
//now we can do each field:
	deck.fields.face = 11;
	deck.fields.suit = 1;
	deck.fields.color = 0;

// or we can do the whole thing at one go:
	deck.card = 0x5A;
}

