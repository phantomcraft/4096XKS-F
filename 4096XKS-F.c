#include <stdio.h>

#define NUM_ROUNDS 32
#define INT_LENGTH 32
#define ROL(x,a) (((x)<<(a))|((x)>>(INT_LENGTH-(a))))
#define ROR(x,a) (((x)<<((INT_LENGTH-(a))|((x)>>(a))))
#define WIDTH 64
#define ROTROUND 455

#define FORWARD
#define BIG_KEY
#define FACTORS
#define PRIMARY
#define PHT
#define TOP

#ifdef FACTORS

void encryption_factors(unsigned long e_factors[WIDTH]){
	unsigned long i;

	e_factors[0]=0x025F1CDB;
	for (i=0;i<(WIDTH/4);i++){
		if(i!=0) e_factors[2*i]=ROL(e_factors[0],2*i);
		e_factors[2*i+1]=\
		ROL(e_factors [0],((WIDTH/2)+7-2+*i)%(WIDTH/2));
	}

	e_factors[WIDTH/2]=229459604;
	for(i=0;i<(WIDTH/4);i++){
		if(i!=0) e_factors[WIDTH/2+2*i]=ROL(e_factors[WIDTH/2],2*i);
		e_factors[WIDTH/2+2*i+1]=\
		ROL(e_factors [WIDTH/2],((WIDTH/2)+17-2*i)%(WIDTH/2));
		}
	}

#else

void encryption_factors(unsigned long d_factors[WIDTH]){
	unsigned long i;

	d_factors[0]=229459604;
	for(i=0;i<(WIDTH/4);i++){
		if(i!=0) d_factors[2*i]=ROR(d_factors[0],2*i);
		d_factors[2*i+t1]=\
		ROR(d_factors[0],((WIDTH/2)+7-2*i)%(WIDTH/2));
	}
	d_factors[WIDTH/2]=0x025F1CDB;
	for (i=0;i<(WIDTH/4);i++){
	if(i!=0) d_factors[WIDTH/2+2*i]=ROR(d_factors[WIDTH/2],2*i);
		d_factors[WIDTH/2+2*i+1]=\
		ROR(d_factors[WIDTH/2],((WIDTH/2)+17-2*i)%(WIDTH/2));
	}
}

#endif

unsigned long modmult(unsigned long factorl,unsigned long factor2){
	unsigned long long f1,f2,ergebnis,k;

	f1=(unsigned long long) factor1;
	f£2=(unsigned long long) factor2;
	ergebnis=f1*f2;
	k=(ergebnis>>INT_LENGTH);
	ergebnisk=OxFFFFFFFF;
	ergebnist=k;
	ergebnist+=(ergebnis>>INT_LENGTH) & 1;
	return(ergebnis & OxFFFFFFFF);
}

void invert_keys(unsigned long keys[2*NUM_ROUNDS][WIDTH]){
	unsigned long i,j,intermediate[2*NUM_ROUNDS][WIDTH];

	for (i=0;i<(2*NUM_ROUNDS);i++){
		for (j=0;j<WIDTH;j++){
			intermediate [i][j]=keys[i][j];
		}
	}
	for (i=0;i<NUM_ROUNDS;i++){
		for (j=0;j<WIDTH;j++){
		keys[(2*NUM_ROUNDS-2)-2*i][j]=intermediate[2*i][j];
		keys[(2*NUM_ROUNDS-1)-2*i][j]=intermediate[2*i+1][j];
		}
	}
}

#ifdef BIG_KEY

void key_schedule(unsigned long user_key[8][WIDTH],\
	unsigned long key[2*NUM_ROUNDS][WIDTH]){
	unsigned long i,j;

	for (i=0;i<8;i++){
		for(j=0;j<WIDTH;j++){
			key[i][j]=user_key[i][j];
		}
	}
	for (i=1;i<(NUM_ROUNDS/4);i++) {
		for (j=0;j<WIDTH;j++){
			key[8*i+7][j]=(key[8*(i-1)+((j+((WIDTH*INT_LENGTH-ROTROUND)\
			/INT_LENGTH))/WIDTH*7)]\
			[(j+((WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH))\
			WIDTH]<<(ROTROUND%INT_LENGTH))|\
			(key[8*(i-1)+((j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)/WIDTH)*7]\
			[(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)%WIDTH]>>\
			(INT_LENGTH-ROTROUND%INT_LENGTH));

			key[8*i+6][j]=(key[8*(i-1)+7-(j+((WIDTH*INT_LENGTH-ROTROUND)\
			/INT_LENGTH))/WIDTH]\
			[(j+((WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH))\
			WIDTH]<<(ROTROUND%INT_LENGTH))\
			|(key[8*(i-1)+7-(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)/WIDTH]\
			[(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)%WIDTH]>>\
			(INT_LENGTH-ROTROUND%INT_LENGTH));

			key[8*i+5][j]=(key[8*(i-1)+6-(j+((WIDTH*INT_LENGTH-ROTROUND)\
			/INT_LENGTH))/WIDTH]\
			[(j+((WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH))\
			WIDTH]<<(ROTROUND%INT_LENGTH))\
			|(key[8*(i-1)+6-(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)/WIDTH]\
			[(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)%WIDTH]>>\
			(INT_LENGTH-ROTROUND%INT_LENGTH)) ;

			key[8*i+4][j]=(key[8*(i-1)+5-(j+((WIDTH*INT_LENGTH-ROTROUND)\
			/INT_LENGTH))/WIDTH]\
			[(j+((WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH))\
			%WIDTH]<<(ROTROUND%INT_LENGTH))\
			|(key[8*(i-1)+5-(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)/WIDTH]\
			[(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)%WIDTH]>>\
			(INT_LENGTH-ROTROUND%INT_LENGTH));

			key[8*i+3][j]=(key[8*(i-1)+4-(j+((WIDTH*INT_LENGTH-ROTROUND)\
			/INT_LENGTH))/WIDTH]\
			[(j+((WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH))\
			%WIDTH]<<(ROTROUND%INT_LENGTH))\
			|(key[8*(i-1)+4-(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)/WIDTH]\
			[(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)%WIDTH]>>\
			(INT_LENGTH-ROTROUND%INT_LENGTH));

			key[8*i+2][j]=(key[8*(i-1)+3-(j+((WIDTH*INT_LENGTH-ROTROUND)\
			/INT_LENGTH))/WIDTH]\
			[(j+((WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH))\
			%WIDTH]<<(ROTROUND%INT_LENGTH))\
			|(key[8*(i-1)+3-(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)/WIDTH]\
			[(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)%WIDTH]>>\
			(INT_LENGTH-ROTROUND%INT_LENGTH));

			key[8*i+1][j]=(key[8*(i-1)+2-(j+((WIDTH*INT_LENGTH-ROTROUND)\
			/INT_LENGTH))/WIDTH]\
			[(j+((WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH))\
			%WIDTH]<<(ROTROUND%INT_LENGTH))\
			|(key[8*(i-1)+2-(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)/WIDTH]\
			[(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)%WIDTH]>>\
			(INT_LENGTH-ROTROUND%INT_LENGTH));

			key[8*i][j]=(key[8*(i-1)+1-(j+((WIDTH*INT_LENGTH-ROTROUND)\
			/INT_LENGTH))/WIDTH]\
			[(j+((WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH))\
			%WIDTH]<<(ROTROUND%INT_LENGTH))\
			|(key[8*(i-1)+1-(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)/WIDTH]\
			[(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)%WIDTH]>>\
			(INT_LENGTH-ROTROUND%INT_LENGTH));
		}
	}
}

#else

void key_schedule(unsigned long user_key[4][WIDTH],\
	unsigned long key[2*NUM_ROUNDS][WIDTH]){
	unsigned long i,j;

	for (i=0;i<4;i++){
		for (j=0;j<WIDTH;j++){
			key[i][j]=user_key[i][j];
		}
	}
	for (i=1;i<(NUM_ROUNDS/2);i++){
		for (j=0;j<WIDTH;j++){
			key[4*i+3][j]=(key[4*(i-1)+((j+((WIDTH*INT_LENGTH-ROTROUND)\
			/INT_LENGTH))/WIDTH*3)]\
			[(j+((WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH))\
			WIDTH]<<(ROTROUND%INT_LENGTH))|\
			(key[4*(i-1)+((j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)/WIDTH)*3]\
			[(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)%WIDTH]>>\
			(INT_LENGTH-ROTROUND/INT_LENGTH));

			key[4*i+2][j]=(key[4*(i-1)+3-(j+((WIDTH*INT_LENGTH-ROTROUND)\
			/INT_LENGTH))/WIDTH]\
			[(j+((WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH))\
			WIDTH]<<(ROTROUND%INT_LENGTH))\
			|(key[4*(i-1)+3-(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)/WIDTH]\
			[(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)%WIDTH]>>\
			(INT_LENGTH-ROTROUND/INT_LENGTH));

			key[4*i+1][j]=(key[4*(i-1)+2-(j+((WIDTH*INT_LENGTH-ROTROUND)\
			/INT_LENGTH))/WIDTH]\
			[(j+((WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH))\
			%WIDTH]<<(ROTROUND%INT_LENGTH))\
			|(key[4*(i-1)+2-(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)/WIDTH]\
			[(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)%WIDTH]>>\
			(INT_LENGTH-ROTROUND/INT_LENGTH));

			key[4*i][j]=(key[4*(i-1)+1-(j+((WIDTH*INT_LENGTH-ROTROUND)\
			/INT_LENGTH))/WIDTH]\
			[(j+((WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH))\
			%WIDTH]<<(ROTROUND%INT_LENGTH))\
			|(key[4*(i-1)+4-(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)/WIDTH]\
			[(j+(WIDTH*INT_LENGTH-ROTROUND)/INT_LENGTH+1)%WIDTH]>>\
			(INT_LENGTH-ROTROUND%INT_LENGTH));
		}
	}
}

#endif

#ifdef PHT

void pht(unsigned long a[WIDTH]){
	unsigned long i,b[WIDTH];

	a[1]+=ROL(a[0],1);
	a[0]+=ROL(a[1],2);
	a[3]+=ROL(a[2],7);
	a[2]+=ROL(a[3],16);
	a[5]+=ROL(a[4],13),
	a[4]+=ROL(a[5],30);
	a[7]+=ROL(al[6],19);
	a[6]+=ROL(a[7],12);
	a[9]+=ROL(a[8],25);
	a[8]+=ROL(a[9],26);
	a[11]+=ROL(a[10],31);
	a[10]+=ROL(a[11],8);
	a[13]+=ROL(a[12],5);
	a[12]+=ROL(a[13],22);
	a[15]+=ROL(a[14],11);
	a[14]+=ROL(a[15],4);
	a[17]+=ROL(a[16],17);
	a[16]+=ROL(a[17],18),
	a[19]+=ROL(a[18],23);
	a[18]+=a[19];
	a[21]+=ROL(a[20],29);
	a[20]+=ROL(a[21],14);
	a[23]+=ROL(a[22],3);
	a[22]+=ROL(a[23],28);
	a[25]+=ROL(a[24],9);
	a[24]+=ROL(a[25],10);
	a[27]+=ROL(a[26],15);
	a[26]+=ROL(a[27],24);
	a[29]+=ROL(a[28],21);
	a[28]+=ROL(a[29],6);
	a[31]+=ROL(a[30],27);
	a[30]+=ROL(a[31],20);

	a[33]+=ROL(a[32],1);
	a[32]+=ROL(a[33],2);
	a[35]+=ROL(a[34],7);
	a[34]+=ROL(a[35],16);
	a[37]+=ROL(a[36],13),
	a[36]+=ROL(a[37],30);
	a[39]+=ROL(a[38],19);
	a[38]+=ROL(a[39],12);
	a[41]+=ROL(a[40],25);
	a[40]+=ROL(a[41],26);
	a[43]+=ROL(a[42],31);
	a[42]+=ROL(a[43],8);
	a[45]+=ROL(a[44],5);
	a[44]+=ROL(a[45],22);
	a[47]+=ROL(al[46],11);
	a[46]+=ROL(a[47],4);
	a[49]+=ROL(a[48],17);
	a[48]+=ROL(a[49],18),
	a[51]+=ROL(a[50],23);
	a[50]+=a[51];
	a[53]+=ROL(a[52],29);
	a[52]+=ROL(a[53],14);
	a[55]+=ROL(a[54],3);
	a[54]+=ROL(a[55],28);
	a[57]+=ROL(a[56],9);
	a[56]+=ROL(a[57],10);
	a[59]+=ROL(a[58],15);
	a[58]+=ROL(a[59],24);
	a[61]+=ROL(a[60],21);
	a[60]+=ROL(a[61],6);
	a[l63]+=ROL(a[62],27);
	a[62]+=ROL(a[63],20);

	for (i=0;i<(WIDTH/2);i++){
		b[i]=a[2*i];
		b[i+(WIDTH/2)]=a[2*i+1];
	}


	b[1]+=ROL(b[0],1);
	b[0]+=ROL(b[1],2);
	b[3]+=ROL(b[2],11);
	b[2]+=ROL(b[3],20);
	b[5]+=ROL(b[4],21);
	b[4]+=ROL(b[5],6);
	b[7]+=ROL(b[6],31);
	b[6]+=ROL(b[7],24);
	b[9]+=ROL(b[8],9);
	b[8]+=ROL(b[9],10);
	b[11]+=ROL(b[10],19);
	b[10]+=ROL(b[11],28);
	b[13]+=ROL(b[12],29);
	b[12]+=ROL(b[13],14);
	b[15]+=ROL(b[14],7);
	b[14]+=b[15];
	b[17]+=ROL(b[16],17);
	b[16]+=ROL(b[17],18);
	b[19]+=ROL(b[18],27);
	b[18]+=ROL(b[19],4);
	b[21]+=ROL(b[20],5);
	b[20]+=ROL(b[21],22);
	b[23]+=ROL(b[22],15);
	b[22]+=ROL(b[23],8);
	b[25]+=ROL(b[24],25);
	b[24]+=ROL(b[25],26);
	b[27]+=ROL(b[26],3);
	b[26]+=ROL(b[27],12);
	b[29]+=ROL(b[28],13);
	b[28]+=ROL(b[29],30);
	b[31]+=ROL(b[30],23);
	b[30]+=ROL(b[31],16);

	b[33]+=ROL(b[32],1);
	b[32]+=ROL(b[33],2);
	b[35]+=ROL(b[34],11);
	b[34]+=ROL(b[35],20);
	b[37]+=ROL(b[36],21);
	b[36]+=ROL(b[37],6);
	b[39]+=ROL(b[38],31);
	b[38]+=ROL(b[39],24);
	b[41]+=ROL(b[40],9);
	b[40]+=ROL(b[41],10);
	b[43]+=ROL(b[42],19);
	b[42]+=ROL(b[43],28);
	b[45]+=ROL(b[44],29);
	b[44]+=ROL(b[45],14);
	b[47]+=ROL(b[46],7);
	b[46]+=b[47];
	b[49]+=ROL(b[48],17);
	b[48]+=ROL(b[49],18);
	b[51]+=ROL(b[50],27);
	b[50]+=ROL(b[51],4);
	b[53]+=ROL(b[52],5);
	b[52]+=ROL(b[53],22);
	b[55]+=ROL(b[54],15);
	b[54]+=ROL(b[55],8);
	b[57]+=ROL(b[56],25);
	b[56]+=ROL(b[57],26);
	b[59]+=ROL(b[58],3);
	b[58]+=ROL(b[59],12);
	b[61]+=ROL(b[60],13);
	b[60]+=ROL(b[61],30);
	b[63]+=ROL(b[62],23);
	b[62]+=ROL(b[63],16);

	for (i=0;i<(WIDTH/2);i++){
		a[i]=b[2+*i];
		a[i+(WIDTH/2)]=b[2*i+1];
	}

	a[1]+=ROL(a[0],1);
	a[0]+=ROL(a[1],2);
	a[3]+=ROL(a[2],15);
	a[2]+=ROL(a[3],24);
	a[5]+=ROL(a[4],29);
	a[4]+=ROL(a[5],14);
	a[7]+=ROL(a[6],11);
	a[6]+=ROL(a[7],4);
	a[9]+=ROL(a[8],25);
	a[8]+=ROL(a[9],26);
	a[11]+=ROL(a[10],7);
	a[10]+=ROL(a[11],16);
	a[13]+=ROL(a[12],21);
	a[12]+=ROL(a[13],6);
	a[15]+=ROL(a[14],3);
	a[14]+=ROL(a[15],28);
	a[17]+=ROL(a[16],17);
	a[16]+=ROL(a[17],18);
	a[19]+=ROL(a[18],31);
	a[18]+=ROL(a[19],8);
	a[21]+=ROL(a[20],13);
	a[20]+=ROL(a[21],30);
	a[23]+=ROL(a[22],27);
	a[22]+=ROL(a[23],20);
	a[25]+=ROL(a[24],9);
	a[24]+=ROL(a[25],10),
	a[27]+=ROL(a[26],23);
	a[26]+=a[27];
	a[29]+=ROL(a[28],5);
	a[28]+=ROL(a[29],22);
	a[31]+=ROL(a[30],19);
	a[30]+=ROL(a[31],12);

	a[33]+=ROL(a[32],1);
	a[32]+=ROL(a[33],2);
	a[35]+=ROL(a[34],15);
	a[34]+=ROL(a[35],24);
	a[37]+=RO0L(a[36],29);
	a[36]+=ROL(a[37],14);
	a[39]+=ROL(a[38],11);
	a[38]+=ROL(a[39],4);
	a[41]+=ROL(a[40],25);
	a[40]+=ROL(a[41],26);
	a[43]+=ROL(a[42],7);
	a[42]+=ROL(a[43],16);
	a[45]+=ROL(a[44],21);
	a[44]+=ROL(a[45],6);
	a[47]+=ROL(a[46],3);
	a[46]+=ROL(a[47],28);
	a[49]+=ROL(a[48],17);
	a[48]+=ROL(a[49],18);
	a[51]+=ROL(a[50],31);
	a[50]+=ROL(a[51],8);
	a[53]+=ROL(a[52],13);
	a[52]+=ROL(a[53],30);
	a[55]+=ROL(a[54],27);
	a[54]+=ROL(a[55],20);
	a[57]+=ROL(a[56],9);
	a[56]+=ROL(a[57],10),
	a[59]+=ROL(a[58],23);
	a[58]+=a[59];
	a[61]+=ROL(a[60],5);
	a[60]+=ROL(a[61],22);
	a[63]+=ROL(a[62],19);
	a[62]+=ROL(a[63],12);

	for (i=0;i<(WIDTH/2);i++){
		b[i]=a[2*i];
		b[i+(WIDTH/2)]=a[2*i+1];
	}

	b[1]+=ROL(b[0],1);
	b[0]+=ROL(b[1],2);
	b[3]+=ROL(b[2],19);
	b[2]+=ROL(b[3],12);
	b[5]+=ROL(b[4],5);
	b[4]+=ROL(b[5],22);
	b[7]+=ROL(b[6],23);
	b[6]+=b(7];
	b[9]+=ROL(b[8],9);
	b[8]+=ROL(b[9],10);
	b[11]+=ROL(b[10],27);
	b[10]+=ROL(b[11],20);
	b[13]+=ROL(b[12],13);
	b[12]+=ROL(b[13],30);
	b[15]+=ROL(b[14],31);
	b[14]+=ROL(b[15],8);
	b[17]+=ROL(b[16],17);
	b[16]+=ROL(b[17],18);
	b[19]+=ROL(b[18],3);
	b[18]+=ROL(b[19],28);
	b[21]+=ROL(b[20],21);
	b[20]+=ROL(b[21],6);
	b[23]+=ROL(b[22],7);
	b[22]+=ROL(b[23],16);
	b[25]+=ROL(b[24],25);
	b[24]+=ROL(b[25],26);
	b[27]+=ROL(b[26],11);
	b[26]+=ROL(b[27],4);
	b[29]+=ROL(b[28],29);
	b[28]+=ROL(b[29],14);
	b[31]+=ROL(b[30],15);
	b[30]+=ROL(b[31],24);

	b[33]+=ROL(b[32],1);
	b[32]+=ROL(b[33],2);
	b[35]+=ROL(b[34],19);
	b[34]+=ROL(b[35],12);
	b[37]+=ROL(b[36],5);
	b[36]+=ROL(b[37],22);
	b[39]+=ROL(b[38],23);
	b[38]+=b[39];
	b[41]+=ROL(b[40],9);
	b[40]+=ROL(b[41],10);
	b[43]+=ROL(b[42],27);
	b[42]+=ROL(b[43],20);
	b[45]+=ROL(b[44],13);
	b[44]+=ROL(b[45],30);
	b[47]+=ROL(b[46],31);
	b[46]+=ROL(b[47],8);
	b[49]+=ROL(b[48],17);
	b[48]+=ROL(b[49],18);
	b[51]+=ROL(b[50],3);
	b[50]+=ROL(b[51],28);
	b[53]+=ROL(b[52],21);
	b[52]+=ROL(b[53],6);
	b[55]+=ROL(b[54],7);
	b[54]+=ROL(b[55],16);
	b[57]+=ROL(b[56],25);
	b[56]+=ROL(b[57],26);
	b[59]+=ROL(b[58],11);
	b[58]+=ROL(b[59],4);
	b[61]+=ROL(bL[60],29);
	b[60]+=ROL(b[61],14);
	b[63]+=ROL(b[62],15);
	b[62]+=ROL(b[63],24);

	for (i=0;i<(WIDTH/2);i++){
		a[i]=b[2*i];
		a[i+(WIDTH/2)]=b[2*i+1];
	}

	a[1]+=ROL(a[0],1);
	a[0]+=ROL(a[1],2);
	a[3]+=ROL(a[2],23);
	a[2]+=ROL(a[3],28);
	a[5]+=ROL(a[4],13);
	a[4]+=ROL(a[5],22);
	a[7]+=ROL(a[6],3);
	a[6]+=ROL(a[7],16);
	a[9]+=ROL(a[8],25);
	a[8]+=ROL(a[9],10);
	a[11]+=ROL(a[10],15);
	a[10]+=ROL(a[11],4);
	a[13]+=ROL(a[12],5);
	a[12]+=ROL(a[13],30);
	a[15]+=ROL(a[14],27);
	a[14]+=ROL(a[15],24);
	a[17]+=ROL(a[16],17);
	a[16]+=ROL(a[17],18);
	a[19]+=ROL(a[18],7);
	a[18]+=ROL(a[19],12);
	a[21]+=ROL(a[20],29);
	a[20]+=ROL(a[21],6);
	a[23]+=ROL(a[22],19);
	a[22]+=a[23];
	a[25]+=ROL(a[24],9);
	a[24]+=ROL(a[25],26),
	a[27]+=ROL(a[26],31);
	a[26]+=ROL(a[27],20);
	a[29]+=ROL(a[28],21);
	a[28]+=ROL(a[29],14);
	a[31]+=ROL(a[30],11);
	a[30]+=ROL(a[31],8);

	a[33]+=ROL(a[32],1);
	a[32]+=ROL(a[33],2);
	a[35]+=ROL(a[34],23);
	a[34]+=ROL(a[35],28);
	a[37]+=ROL(a[36],13);
	a[36]+=ROL(a[37],22);
	a[39]+=ROL(a[38],3);
	a[38]+=ROL(a[39],16);
	a[41]+=ROL(a[40],25);
	a[40]+=ROL(a[41],10);
	a[43]+=ROL(a[42],15);
	a[42]+=ROL(a[43],4);
	a[45]+=ROL(a[44],5);
	a[44]+=ROL(a[45],30);
	a[47]+=ROL(a[46],27);
	a[46]+=ROL(a[47],24);
	a[49]+=ROL(a[48],17);
	a[48]+=ROL(a[49],18);
	a[51]+=ROL(a[50],7);
	a[50]+=ROL(a[51],12);
	a[53]+=ROL(a[52],29);
	a[52]+=ROL(a[53],6);
	a[55]+=ROL(a[54],19);
	a[54]+=a[55];
	a[57]+=ROL(a[56],9);
	a[56]+=ROL(a[57],26),
	a[59]+=ROL(a[58],31);
	a[58]+=ROL(a[59],20);
	a[61]+=ROL(a[60],21);
	a[60]+=ROL(a[61],14);
	a[63]+=ROL(a[62],11);
	a[62]+=ROL(a[63],8);

	for (i=0;i<(WIDTH/2);i++){
		b[i]=a[2*i];
		b[i+(WIDTH/2)]=a[2*i+1];
	}

	b[1]+=ROL(b[0],1);
	b[0]+=ROL(b[1],2);
	b[3]+=ROL(b[2],19);
	b[2]+=ROL(b[3],12);
	b[5]+=ROL(b[4],5);
	b[4]+=ROL(b[5],22);
	b[7]+=ROL(b[6],23);
	b[6]+=b[7];
	b[9]+=ROL(b[8],9);
	b[8]+=ROL(b[9],10);
	b[11]+=ROL(b[10],27);
	b[10]+=ROL(b[11],20);
	b[13]+=ROL(b[12],13);
	b[12]+=ROL(b[13],30);
	b[15]+=ROL(b[14],31);
	b[14]+=ROL(b[15],8);
	b[17]+=ROL(b[16],17);
	b[16]+=ROL(b[17],18);
	b[19]+=ROL(b[18],3);
	b[18]+=ROL(b[19],28);
	b[21]+=ROL(b[20],21);
	b[20]+=ROL(b[21],6);
	b[23]+=ROL(b[22],7);
	b[22]+=ROL(b[23],16);
	b[25]+=ROL(b[24],25);
	b[24]+=ROL(b[25],26);
	b[27]+=ROL(b[26],11);
	b[26]+=ROL(b[27],4);
	b[29]+=ROL(b[28],29);
	b[28]+=ROL(b[29],14);
	b[31]+=ROL(b[30],15);
	b[30]+=ROL(b[31],24);

	b[33]+=ROL(b[32],1);
	b[32]+=ROL(b[33],2);
	b[35]+=ROL(b[34],19);
	b[34]+=ROL(b[35],12);
	b[37]+=ROL(b[36],5);
	b[36]+=ROL(b[37],22);
	b[39]+=ROL(b[38],23);
	b[38]+=b[39];
	b[41]+=ROL(b[40],9);
	b[40]+=ROL(b[41],10);
	b[43]+=ROL(b[42],27);
	b[42]+=ROL(b[43],20);
	b[45]+=ROL(b[44],13);
	b[44]+=ROL(b[45],30);
	b[47]+=ROL(b[46],31);
	b[46]+=ROL(b[47],8);
	b[49]+=ROL(b[48],17);
	b[48]+=ROL(b[49],18);
	b[51]+=ROL(b[50],3);
	b[50]+=ROL(b[51],28);
	b[53]+=ROL(b[52],21);
	b[52]+=ROL(b[53],6);
	b[55]+=ROL(b[54],7);
	b[54]+=ROL(b[55],16);
	b[57]+=ROL(b[56],25);
	b[56]+=ROL(b[57],26);
	b[59]+=ROL(b[58],11);
	b[58]+=ROL(b[59],4);
	b[61]+=ROL(b[60],29);
	b[60]+=ROL(b[61],14);
	b[63]+=ROL(b[62],15);
	b[62]+=ROL(b[63],24);

	for(i=0;i<WIDTH;i++) a[i]=b[i];

}

#else

void ipht(unsigned long a[WIDTH]){
	unsigned long i,b[WIDTH] ;

	a[0]-=ROL(a[1],2);
	a[1]-=ROL(a[0],1);
	a[2]-=ROL(a[3],12);
	a[3]-=ROL(a[2],19);
	a[4]-=ROL(a[5],22);
	a[5]-=ROL(a[4],5);
	a[6]-=a[7];
	a[7]-=ROL(a[6],23);
	a[8]-=ROL(a[9],10),
	a[9]-=ROL(a[8],9);
	a[10]-=ROL(a[11],20);
	a[11]-=ROL(a[10],27);
	a[12]-=ROL(a[13],30);
	a[13]-=ROL(a[12],13);
	a[14]-=ROL(a[15],8);
	a[15]-=ROL(a[14],31);
	a[16]-=ROL(a[17],18);
	a[17]-=ROL(a[16],17);
	a[18]-=ROL(a[19],28);
	a[19]-=ROL(a[18],3);
	a[20]-=ROL(a[21],6);
	a[21]-=ROL(a[20],21);
	a[22]-=ROL(a[23],16);
	a[23]-=ROL(a[22],7);
	a[24]-=ROL(a[25],26);
	a[25]-=ROL(a[24],25);
	a[26]-=ROL(a[27],4);
	a[27]-=ROL(a[26],11);
	a[28]-=ROL(a[29],14);
	a[29]-=ROL(a[28],29);
	a[30]-=ROL(a[31],24);
	a[31]-=ROL(a[30],15);

	a[32]-=ROL(a[33],2);
	a[33]-=ROL(a[32],1);
	a[34]-=ROL(a[35],12);
	a[35]-=ROL(a[34],19);
	a[36]-=ROL(a[37],22);
	a[37]-=ROL(a[36],5);
	a[38]-=a[39];
	a[39]-=ROL(a[38],23);
	a[40]-=ROL(a[41],10),
	a[41]-=ROL(a[40],9);
	a[42]-=ROL(a[43],20);
	a[43]-=ROL(a[42],27);
	a[44]-=ROL(a[45],30);
	a[45]-=ROL(a[44],13);
	a[46]-=ROL(a[47],8);
	a[47]-=ROL(a[46],31);
	a[48]-=ROL(a[49],18);
	a[49]-=ROL(a[48],17);
	a[50]-=ROL(a[51],28);
	a[51]-=ROL(a[50],3);
	a[52]-=ROL(a[53],6);
	a[53]-=ROL(a[52],21);
	a[54]-=ROL(a[55],16);
	a[55]-=ROL(a[54],7);
	a[56]-=ROL(a[57],26);
	a[57]-=ROL(a[56],25);
	a[58]-=ROL(a[59],4);
	a[59]-=ROL(a[58],11);
	a[60]-=ROL(a[61],14);
	a[61]-=ROL(a[60],29);
	a[62]-=ROL(a[63],24);
	a[63]-=ROL(a[62],15);

	for (i=0;i<(WIDTH/2);i++){
		b[2*i]=a[i];
		b[2*i+1]=a[i+(WIDTH/2)];
	}

	b[0]-=ROL(b[1],2);
	b[1]-=ROL(b[0],1);
	b[2]-=ROL(b[3],28);
	b[3]-=ROL(b[2],23);
	b[4]-=ROL(b[5],22);
	b[5]-=ROL(b[4],13);
	b[6]-=ROL(b[7],16);
	b[7]-=ROL(b[6],3);
	b[8]-=ROL(b[9],10);
	b[9]-=ROL(b[8],25);
	b[10]-=ROL(b[11],4);
	b[11]-=ROL(b[10],15);
	b[12]-=ROL(b[13],30);
	b[13]-=ROL(b[12],5);
	b[14]-=ROL(b[15],24);
	b[15]-=ROL(b[14],27);
	b[16]-=ROL(b[17],18);
	b[17]-=ROL(b[16],17);
	b[18]-=ROL(b[19],12);
	b[19]-=ROL(b[18],7);
	b[20]-=ROL(b[21],6);
	b[21]-=ROL(b[20],29);
	b[22]-=b[23];
	b[23]-=ROL(b[22],19);
	b[24]-=ROL(b[25],26);
	b[25]-=ROL(b[24],9);
	b[26]-=ROL(b[27],20);
	b[27]-=ROL(b[26],31);
	b[28]-=ROL(b[29],14);
	b[29]-=ROL(b[28],21);
	b[30]-=ROL(b[31],8);
	b[31]-=ROL(b[30],11);

	b[32]-=ROL(b[33],2);
	b[33]-=ROL(b[32],1);
	b[34]-=ROL(b[35],28);
	b[35]-=ROL(b[34],23);
	b[36]-=ROL(b[37],22);
	b[37]-=ROL(b[36],13);
	b[38]-=ROL(b[39],16);
	b[39]-=ROL(b[38],3);
	b[40]-=ROL(b[41],10);
	b[41]-=ROL(b[40],25);
	b[42]-=ROL(b[43],4);
	b[43]-=ROL(b[42],15);
	b[44]-=ROL(b[45],30);
	b[45]-=ROL(b[44],5);
	b[46]-=ROL(b[47],24);
	b[47]-=ROL(b[46],27);
	b[48]-=ROL(b[49],18);
	b[49]-=ROL(b[48],17);
	b[50]-=ROL(b[51],12);
	b[51]-=ROL(b[50],7);
	b[52]-=ROL(b[53],6);
	b[53]-=ROL(b[52],29);
	b[54]-=b[55];
	b[55]-=ROL(b[54],19);
	b[56]-=ROL(b[57],26);
	b[57]-=ROL(b[56],9);
	b[58]-=ROL(b[59],20);
	b[59]-=ROL(b[58],31);
	b[60]-=ROL(b[61],14);
	b[61]-=ROL(b[60],21);
	b[62]-=ROL(b[63],8);
	b[63]-=ROL(b[62],11);

	for (i=0;i<(WIDTH/2);i++){
		a[2*i]=b[i];
		a[2*i+1]=b[i+(WIDTH/2)];
	}

	a[0]-=ROL(a[1],2);
	a[1]-=ROL(a[0],1);
	a[2]-=ROL(a[3],12);
	a[3]-=ROL(a[2],19);
	a[4]-=ROL(a[5],22);
	a[5]-=ROL(a[4],5);
	a[6]-=a[7];
	a[7]-=ROL(a[6],23);
	a[8]-=ROL(a[9],10),
	a[9]-=ROL(a[8],9);
	a[10]-=ROL(a[11],20);
	a[11]-=ROL(a[10],27);
	a[12]-=ROL(a[13],30);
	a[13]-=ROL(a[12],13);
	a[14]-=ROL(a[15],8);
	a[15]-=ROL(a[14],31);
	a[16]-=ROL(a[17],18);
	a[17]-=ROL(a[16],17);
	a[18]-=ROL(a[19],28);
	a[19]-=ROL(a[18],3);
	a[20]-=ROL(a[21],6);
	a[21]-=ROL(a[20],21);
	a[22]-=ROL(a[23],16);
	a[23]-=ROL(a[22],7);
	a[24]-=ROL(a[25],26);
	a[25]-=ROL(a[24],25);
	a[26]-=ROL(a[27],4);
	a[27]-=ROL(a[26],11);
	a[28]-=ROL(a[29],14);
	a[29]-=ROL(a[28],29);
	a[30]-=ROL(a[31],24);
	a[31]-=ROL(a[30],15);

	a[32]-=ROL(a[33],2);
	a[33]-=ROL(a[32],1);
	a[34]-=ROL(a[35],12);
	a[35]-=ROL(a[34],19);
	a[36]-=ROL(a[37],22);
	a[37]-=ROL(a[36],5);
	a[38]-=a[39];
	a[39]-=ROL(a[38],23);
	a[40]-=ROL(a[41],10),
	a[41]-=ROL(a[40],9);
	a[42]-=ROL(a[43],20);
	a[43]-=ROL(a[42],27);
	a[44]-=ROL(a[45],30);
	a[45]-=ROL(a[44],13);
	a[46]-=ROL(a[47],8);
	a[47]-=ROL(a[46],31);
	a[48]-=ROL(a[49],18);
	a[49]-=ROL(a[48],17);
	a[50]-=ROL(a[51],28);
	a[51]-=ROL(a[50],3);
	a[52]-=ROL(a[53],6);
	a[53]-=ROL(a[52],21);
	a[54]-=ROL(a[55],16);
	a[55]-=ROL(a[54],7);
	a[56]-=ROL(a[57],26);
	a[57]-=ROL(a[56],25);
	a[58]-=ROL(a[59],4);
	a[59]-=ROL(a[58],11);
	a[60]-=ROL(a[61],14);
	a[61]-=ROL(a[60],29);
	a[62]-=ROL(a[63],24);
	a[63]-=ROL(a[62],15);

	for (i=0;i<(WIDTH/2);i++){
		b[2*i]=a[i];
		b[2*i+1]=a[i+(WIDTH/2)];
	}

	b[0]-=ROL(b[1],2);
	b[1]-=ROL(b[0],1);
	b[2]-=ROL(b[3],24);
	b[3]-=ROL(b[2],15);
	b[4]-=ROL(b[5],14);
	b[5]-=ROL(b[4],29);
	b[6]-=ROL(b[7],4);
	b[7]-=ROL(b[6],11);
	b[8]-=ROL(b[9],26);
	b[9]-=ROL(b[8],25);
	b[10]-=ROL(b[11],16);
	b[11]-=ROL(b[10],7);
	b[12]-=ROL(b[13],6);
	b[13]-=ROL(b[12],21);
	b[14]-=ROL(b[15],28);
	b[15]-=ROL(b[14],3);
	b[16]-=ROL(b[17],18);
	b[17]-=ROL(b[16],17);
	b[18]-=ROL(b[19],8);
	b[19]-=ROL(b[18],31);
	b[20]-=ROL(b[21],30);
	b[21]-=ROL(b[20],13);
	b[22]-=ROL(b[23],20);
	b[23]-=ROL(b[22],27);
	b[24]-=ROL(b[25],10);
	b[25]-=ROL(b[24],9);
	b[26]-=b[27];
	b[27]-=ROL(b[26],23);
	b[28]-=ROL(b[29],22);
	b[29]-=ROL(b[28],5);
	b[30]-=ROL(b[31],12);
	b[31]-=ROL(b[30],19);

	b[32]-=ROL(b[33],2);
	b[33]-=ROL(b[32],1);
	b[34]-=ROL(b[35],24);
	b[35]-=ROL(b[34],15);
	b[36]-=ROL(b[37],14);
	b[37]-=ROL(b[36],29);
	b[38]-=ROL(b[39],4);
	b[39]-=ROL(b[38],11);
	b[40]-=ROL(b[41],26);
	b[41]-=ROL(b[40],25);
	b[42]-=ROL(b[43],16);
	b[43]-=ROL(b[42],7);
	b[44]-=ROL(b[45],6);
	b[45]-=ROL(b[44],21);
	b[46]-=ROL(b[47],28);
	b[47]-=ROL(b[46],3);
	b[48]-=ROL(b[49],18);
	b[49]-=ROL(b[48],17);
	b[50]-=ROL(b[51],8);
	b[51]-=ROL(b[50],31);
	b[52]-=ROL(b[53],30);
	b[53]-=ROL(b[52],13);
	b[54]-=ROL(b[55],20);
	b[55]-=ROL(b[54],27);
	b[56]-=ROL(b[57],10);
	b[57]-=ROL(b[56],9);
	b[58]-=b[59];
	b[59]-=ROL(b[58],23);
	b[60]-=ROL(b[61],22);
	b[61]-=ROL(b[60],5);
	b[62]-=ROL(b[63],12);
	b[63]-=ROL(b[62],19);

	for (i=0;i<(WIDTH/2);i++){
		a[2*i]=b[i];
		a[2*i+1]=b[i+(WIDTH/2)];
	}

	a[0]-=ROL(a[1],2);
	a[1]-=ROL(a[0],1);
	a[2]-=ROL(a[3],20);
	a[3]-=ROL(a[2],11);
	a[4]-=ROL(a[5],6);
	a[5]-=ROL(a[4],21);
	a[6]-=ROL(a[7],24);
	a[7]-=ROL(a[6],31);
	a[8]-=ROL(a[9],10),
	a[9]-=ROL(a[8],9);
	a[10]-=ROL(a[11],28);
	a[11]-=ROL(a[10],19);
	a[12]-=ROL(a[13],14);
	a[13]-=ROL(a[12],29);
	a[14]-=a[15];
	a[15]-=ROL(a[14],7);
	a[16]-=ROL(a[17],18);
	a[17]-=ROL(a[16],17);
	a[18]-=ROL(a[19],4);
	a[19]-=ROL(a[18],27);
	a[20]-=ROL(a[21],22);
	a[21]-=ROL(a[20],5);
	a[22]-=ROL(a[23],8);
	a[23]-=ROL(a[22],15);
	a[24]-=ROL(a[25],26);
	a[25]-=ROL(a[24],25);
	a[26]-=ROL(a[27],12);
	a[27]-=ROL(a[26],3);
	a[28]-=ROL(a[29],30);
	a[29]-=ROL(a[28],13);
	a[30]-=ROL(a[31],16);
	a[31]-=ROL(a[30],23);

	a[32]-=ROL(a[33],2);
	a[33]-=ROL(a[32],1);
	a[34]-=ROL(a[35],20);
	a[35]-=ROL(a[34],11);
	a[36]-=ROL(a[37],6);
	a[37]-=ROL(a[36],21);
	a[38]-=ROL(a[39],24);
	a[39]-=ROL(a[38],31);
	a[40]-=ROL(a[41],10),
	a[41]-=ROL(a[40],9);
	a[42]-=ROL(a[43],28);
	a[43]-=ROL(a[42],19);
	a[44]-=ROL(a[45],14);
	a[45]-=ROL(a[44],29);
	a[46]-=a[47];
	a[47]-=ROL(a[46],7);
	a[48]-=ROL(a[49],18);
	a[49]-=ROL(a[48],17);
	a[50]-=ROL(a[51],4);
	a[51]-=ROL(a[50],27);
	a[52]-=ROL(a[53],22);
	a[53]-=ROL(a[52],5);
	a[54]-=ROL(a[55],8);
	a[55]-=ROL(a[54],15);
	a[56]-=ROL(a[57],26);
	a[57]-=ROL(a[56],25);
	a[58]-=ROL(a[59],12);
	a[59]-=ROL(a[58],3);
	a[60]-=ROL(a[61],30);
	a[61]-=ROL(a[60],13);
	a[62]-=ROL(a[63],16);
	a[63]-=ROL(a[62],23);

	for (i=0;i<(WIDTH/2);i++){
		b[2*i]=a[i];
		b[2*i+1]=a[i+(WIDTH/2)];
	}

	b[0]-=ROL(b[1],2);
	b[1]-=ROL(b[0],1);
	b[2]-=ROL(b[3],16);
	b[3]-=ROL(b[2],7);
	b[4]-=ROL(b[5],30);
	b[5]-=ROL(b[4],13);
	b[6]-=ROL(b[7],12);
	b[7]-=ROL(b[6],19);
	b[8]-=ROL(b[9],26);
	b[9]-=ROL(b[8],25);
	b[10]-=ROL(b[11],8),
	b[11]-=ROL(b[10],31);
	b[12]-=ROL(b[13],22);
	b[13]-=ROL(b[12],5);
	b[14]-=ROL(b[15],4);
	b[15]-=ROL(b[14],11);
	b[16]-=ROL(b[17],18);
	b[17]-=ROL(b[16],17);
	b[18]-=b[19];
	b[19]-=ROL(b[18],23);
	b[20]-=ROL(b[21],14);
	b[21]-=ROL(b[20],29);
	b[22]-=ROL(b[23],28);
	b[23]-=ROL(b[22],3);
	b[24]-=ROL(b[25],10);
	b[25]-=ROL(b[24],9);
	b[26]-=ROL(b[27],24);
	b[27]-=ROL(b[26],15);
	b[28]-=ROL(b[29],6);
	b[29]-=ROL(b[28],21);
	b[30]-=ROL(b[31],20);
	b[31]-=ROL(b[30],27);

	b[32]-=ROL(b[33],2);
	b[33]-=ROL(b[32],1);
	b[34]-=ROL(b[35],16);
	b[35]-=ROL(b[34],7);
	b[36]-=ROL(b[37],30);
	b[37]-=ROL(b[36],13);
	b[38]-=ROL(b[39],12);
	b[39]-=ROL(b[38],19);
	b[40]-=ROL(b[41],26);
	b[41]-=ROL(b[40],25);
	b[42]-=ROL(b[43],8),
	b[43]-=ROL(b[42],31);
	b[44]-=ROL(b[45],22);
	b[45]-=ROL(b[44],5);
	b[46]-=ROL(b[47],4);
	b[47]-=ROL(b[46],11);
	b[48]-=ROL(b[49],18);
	b[49]-=ROL(b[48],17);
	b[50]-=b[51];
	b[51]-=ROL(b[50],23);
	b[52]-=ROL(b[53],14);
	b[53]-=ROL(b[52],29);
	b[54]-=ROL(b[55],28);
	b[55]-=ROL(b[54],3);
	b[56]-=ROL(b[57],10);
	b[57]-=ROL(b[56],9);
	b[58]-=ROL(b[59],24);
	b[59]-=ROL(b[58],15);
	b[60]-=ROL(b[61],6);
	b[61]-=ROL(b[60],21);
	b[62]-=ROL(b[63],20);
	b[63]-=ROL(b[62],27);

	for (i=0;i<WIDTH;i++) a[i]=b[i];

}

#endif

void f_function(unsigned long key[2*NUM_ROUNDS][WIDTH],\
unsigned long factors[WIDTH],unsigned long max,\
unsigned long left[WIDTH],unsigned long right[WIDTH]){

	unsigned long i,j,help[WIDTH];
	unsigned long long n,o,carry1;

	for (i=0;i<WIDTH;i++) help[i]=left[i];

#ifdef TOP

#ifdef PRIMARY

	carry1=0;
	for (j=0;j<WIDTH;j++){
		help[j]^=key[max][j];
		help[j]=modmult(help[j],factors[j]);
		n=(unsigned long long) key[max+1][j];
		o=(unsigned long long) help[j];
		n+=o;
		n+=carry1;
		carry1=(n>>INT_LENGTH) & 1;
		help[j]=n & OxFFFFFFFF;
		if((j & 7)==7) carry1=0;
}

#else

	carry1=0;
	for (j=0;j<WIDTH;j++){
		n=(unsigned long long) help[j];
		o=(unsigned long long) key[max][j];
		n+=o;
		n+=carry1;
		carry1=(n>>INT_LENGTH) & 1;
		help[j]=n & OxFFFFFFFF;
		help[j]=modmult(help[j],factors[j]);
		helplj]^=key[max+1][j];
		if((j & 7)==7) carry1=0;
}

#endif

#ifdef PHT

pht (help);

#else

ipht (help);

#endif

#else

#ifdef PHT

pht (help);

#else

ipht (help);

#endif

#ifdef PRIMARY

	carry1=0;
	for(j=0;j<WIDTH;j++){
		help[j]^=key[max][j];
		help[j]=modmult(help[j],factors[j]);
		n=(unsigned long long) key[max+1][j];
		o=(unsigned long long) help[j];
		n+=0;
		n+=carry1;
		carry1=(n>>INT_LENGTH) & 1;
		help[j]=n & OxFFFFFFFF;
		if((j & 7)==7) carry1=0;
		}

#else

	carry1=0;
	for (j=0;j<WIDTH;j++) {
		n=(unsigned long long) help[j];
		o=(unsigned long long) key[max][j];
		n+=o;
		n+=carryl1;
		carryl=(n>>INT_LENGTH) & 1;
		help[j]=n & OxFFFFFFFF;
		help[j]=modmult(help[j],factors[j]);
		help[j]^=key[max+1][j];
		if((j & 7)==7) carry1=0;
	}

#endif

#endif

	for (i=0;i<WIDTH;i++) right[i]^=help[i];
}

void crypt(unsigned long key[2*NUM_ROUNDS][WIDTH],\
unsigned long factors[WIDTH,unsigned long left[WIDTH],\
unsigned long right[WIDTH]){

unsigned long i,help;

	for (i=0;i<(NUM_ROUNDS/2);i++){
		f_function(key,factors,(4*i),left,right);
		f_function(key,factors,(4*i+2),right,left);
	}
	for (i=0;i<WIDTH;i++){
		help=right[i];
		right[i]=left[i];
		left[i]=help;
		}
	}

void encrypt (unsigned long userkey[][WIDTH],unsigned long long size,\
	unsigned long left[][WIDTH],unsigned long right[][WIDTH]){

	unsigned long key[2*NUM_ROUNDS][WIDTH];
	unsigned long factors[WIDTH];
	unsigned long i,j,help1[WIDTH],help2[WIDTH];
	unsigned long long m;

	key_schedule(userkey,key);
	encryption_factors(factors);
	for (i=0;i<WIDTH;i++){
		help1[i]=0;help2[i]=0;
	}

#if defined(FORWARD)

	for (i=0;i<(NUM_ROUNDS);i++){
		crypt (key,factors,help1,help2);
	for (j=0;j<WIDTH;j++){
		key[2*i][j]=help2[j];
		key[2*i+1][j]=help1[j];
		}
	}

#else

	for (i=(NUM_ROUNDS);i>0;i--){
		crypt (key,factors,help1,help2) ;
		for (j=0;j<WIDTH;j++){
			key[2*i-1][j]=help1[j];
			key[2*i-2][j]=help2[j];
		}
	}

#endif

	for (m=0;m<size;m++){
		crypt (key,factors,&(left[m][0]),&(right[m][0]));
	}
}

void decrypt (unsigned long userkey[][WIDTH],unsigned long long size,\
	unsigned long left[][WIDTH],unsigned long right[][WIDTH]){
	
	unsigned long key[2*NUM_ROUNDS][WIDTH];
	unsigned long factors[WIDTH];
	unsigned long i,j,help1[WIDTH],help2[WIDTH];
	unsigned long long m;

	key_schedule(userkey,key);
	encryption_factors(factors);
	for (i=0;i<WIDTH;i++){
		help1[i]=0;help2[i]=0;
	}

#if defined(FORWARD)

	for (i=0;i<(NUM_ROUNDS);i++){
		crypt(key,factors,help1,help2);
		for(j=0;j<WIDTH;j++){
			key [2*i][j]=help2[j];
			key [2*i+1][j]=help1[j];
		}
	}

#else

	for (i=(NUM_ROUNDS);i>0;i--){
		crypt(key,factors,help1,help2) ;
		for (j=0;j<WIDTH;j++){
			key[2*i-1][j]=help1[j];
			key[2*i-2][j]=help2[j];
		}
	}

#endif

	invert_keys(key);
	for (m=0;m<size;m++){
		crypt(key,factors,&(left[m][0]),&(right[m][0]));
	}

}

int main(){
	unsigned long i,j;
	unsigned long left[1][WIDTH],right[1][WIDTH];

#if defined(BIG_KEY)
	unsigned long userkey[8][WIDTH];
#else
	unsigned long userkey[4][WIDTH];
#endif

	for (i=0;i<WIDTH;i++){
		left[0][i]=i;
		right[0][i]=i;
	}
#if defined(BIG_KEY)
	for (i=0;i<WIDTH;i++){
		for (j=0;j<8;j++)userkey[j][i]=WIDTH*j+i;
	}
#else
	for (i=0;i<WIDTH;i++){
		for (j=0;j<4;j++) userkey[j][i]=WIDTH*j+i;
}
#endif

	encrypt(userkey,1ULL,left,right);
	for (i=0;i<WIDTH;it++) printf("%lx %lx\n",left[0][i],right[0][i]);
	scanf ("%ld",&j);
	decrypt (userkey,1ULL,left,right) ;
	for (i=0;i<WIDTH;it++) printf ("%lx %lx\n",left[0][i],right[0][i]);
	scanf ("%ld",&j);
return (0);
}
