//Cortex M4 stuff

#define NVIC_REGISTERS ((uint32_t)0xE000E100)

typedef struct
{
	reg32bit ISER0; //0x100
	reg32bit ISER1; //0x104
	reg32bit ISER2; //0x108
	reg32bit ISER3; //0x10C
	reg32bit ISER4; //0x110
	reg32bit ISER5; //0x114
	reg32bit ISER6; //0x118
	reg32bit ISER7; //0x11C

	reg32bit RESERVED1[24];

	reg32bit ICER0; //0x180
	reg32bit ICER1; //0x184
	reg32bit ICER2; //0x188
	reg32bit ICER3; //0x18C
	reg32bit ICER4; //0x190
	reg32bit ICER5; //0x194
	reg32bit ICER6; //0x198
	reg32bit ICER7; //0x19C

	reg32bit RESERVED2[24];

	reg32bit ISPR0; //0x200
	reg32bit ISPR1; //0x204
	reg32bit ISPR2; //0x208
	reg32bit ISPR3; //0x20C
	reg32bit ISPR4; //0x210
	reg32bit ISPR5; //0x214
	reg32bit ISPR6; //0x218
	reg32bit ISPR7; //0x21C

	reg32bit RESERVED3[24];

	reg32bit ICPR0; //0x280
	reg32bit ICPR1; //0x284
	reg32bit ICPR2; //0x288
	reg32bit ICPR3; //0x28C
	reg32bit ICPR4; //0x290
	reg32bit ICPR5; //0x294
	reg32bit ICPR6; //0x298
	reg32bit ICPR7; //0x29C

	reg32bit RESERVED4[24];

	reg32bit IABR0; //0x300
	reg32bit IABR1; //0x304
	reg32bit IABR2; //0x308
	reg32bit IABR3; //0x30C
	reg32bit IABR4; //0x310
	reg32bit IABR5; //0x314
	reg32bit IABR6; //0x318
	reg32bit IABR7; //0x31C

	reg32bit RESERVED5[56];

	reg32bit IPR[60];

} NVIC_TypeDef;


#define NVIC (( NVIC_TypeDef *)NVIC_REGISTERS )
