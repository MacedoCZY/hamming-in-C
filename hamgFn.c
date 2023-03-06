#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* binConv(int n, int len)
{
    char* binary = (char*)malloc(sizeof(char) * len);
    int k = 0;
    for (unsigned i = (1 << len - 1); i > 0; i = i / 2) {
        binary[k++] = (n & i) ? '1' : '0';
    }
    binary[k] = '\0';
    return binary;
}


char* binConv(int n, int len);


int main(int argc, char * argv[]) {
	
	if (argc!=3)
    {
        printf("\tErro opcao invalida ou inexistente.\n");
        exit(1);
    }   
	
	char* binary;
	unsigned short M[8], C[4], G, newC[4], newG;
	FILE *opn, *cls;
	unsigned short wrdhamming;
	char x = 0, y = 0, aux[5];
    char wrd[100];
	unsigned short osAJUDANTES[4];
	unsigned short sindrome = 0;
	int msgout = 0;
	int msgout1 = 0;
    strcpy(wrd, argv[1]);
    strcpy(aux, argv[2]);  
    strcat(wrd,".wham"); 
    if(aux[0]=='-' && aux[1]=='w'){
        if((opn = fopen(argv[1],"rb")) == NULL)
		{	
            printf("\t\tERRO: Ao abrir arquivo %s.\n",argv[1]);
		}
		else if ((cls = fopen(wrd,"wb")) == NULL)
		{			
            printf("\t\tERRO: Ao abrir este arquivo.\n");
        }
		else
		{
			printf("\n\tCriando Hamming...\n");
			while(feof(opn) == 0)
            {
                wrdhamming = 0;
                fread(&x, 1, 1, opn);
				
				M[7] = x;
				M[6] = x;
				M[5] = x;
				M[4] = x;
				M[3] = x;
				M[2] = x;
				M[1] = x;
				M[0] = x;
				
				M[0] = M[0] & 1;
				//shift right (>>)
				M[1] >>= 1;
				M[1] &= 1;
				
				M[2] >>= 2;
				M[2] &= 1;
				
				M[3] >>= 3;
				M[3] &= 1;
				
				M[4] >>= 4;
				M[4] &= 1;
				
				M[5] >>= 5;
				M[5] &= 1;
				
				M[6] >>= 6;
				M[6] &= 1;
				
				M[7] >>= 7;
				M[7] &= 1;
				// (^) == XOR
				C[0] = M[0] ^ M[1] ^ M[3] ^ M[4] ^ M[6];
				C[1] = M[0] ^ M[2] ^ M[3] ^ M[5] ^ M[6];
				C[2] = M[1] ^ M[2] ^ M[3] ^ M[7];
				C[3] = M[4] ^ M[5] ^ M[6] ^ M[7];
				
				G = M[7] ^ M[6] ^ M[5] ^ M[4] ^ C[3] ^ M[3] ^ M[2] ^ M[1] ^ C[2] ^ M[0] ^ C[1] ^ C[0];
				
				wrdhamming |= M[7];
				wrdhamming <<= 1;
				
				wrdhamming |= M[6];
				wrdhamming <<= 1;
				
				wrdhamming |= M[5];
				wrdhamming <<= 1;
				
				wrdhamming |= M[4];
				wrdhamming <<= 1;
				
				wrdhamming |= C[3];
				wrdhamming <<= 1;
				
				wrdhamming |= M[3];
				wrdhamming <<= 1;
				
				wrdhamming |= M[2];
				wrdhamming <<= 1;
				
				wrdhamming |= M[1];
				wrdhamming <<= 1;
				
				wrdhamming |= C[2];
				wrdhamming <<= 1;
				
				wrdhamming |= M[0];
				wrdhamming <<= 1;
				
				wrdhamming |= C[1];
				wrdhamming <<= 1;
				
				wrdhamming |= C[0];
				wrdhamming <<= 1;
				
				wrdhamming |= G;
				
				if(feof(opn) == 0){
					//wrdhamming palavra salva 
					//cls -> ponteiro para fechar o arquivo
					fwrite(&wrdhamming, 1, sizeof(wrdhamming), cls);
				}
			}
		fclose(opn);
		fclose(cls);
		printf("\n\tHamming criado...\n");
		}
	}
	
	if(aux[0]=='-' && aux[1]=='r'){
		FILE *aPONTA;
		//refr = wrd
	
		strcpy(wrd, argv[1]);
        int o = strlen(wrd);
        unsigned short aGRAVACAO = 0, aPALAVRA = 0;
        unsigned short  aGRAVACAOFINAL = 0;
        
        
        for(short i = strlen(wrd); i >= o - 5;){
            wrd[i]='\0';
            i--;
        }
        if((opn = fopen(argv[1],"rb")) == NULL)
		{
            printf("\t\tERRO: ao abrir arquivo %s.\n",argv[1]);
            exit(1);
        }
		else 
			if ((cls = fopen(wrd,"wb")) == NULL){
            printf("\t\tERRO: ao abrir este arquivo .\n");
            exit(1);
        }else 
			if ((aPONTA = fopen("aPONTA","wb")) == NULL)
		{
            printf("\t\tERRO: ao abrir este arquivo temporario.\n");
            exit(1);
        }
		else
		{
			msgout = 0;
			int msgout3 = 0;
            printf("\n\tANALISANDO...\n\n");
            while(feof(opn) == 0)
			{
				msgout1 = 0;
				msgout = 0;
				sindrome = 0;
                aPALAVRA = 0;
                aGRAVACAO = 0;
				aGRAVACAOFINAL = 0;
                fread(&aPALAVRA, sizeof(aPALAVRA), 1, opn);
                if(feof(opn)) break;

				M[7] = aPALAVRA;
				M[6] = aPALAVRA;
				M[5] = aPALAVRA;
				M[4] = aPALAVRA;
				C[3] = aPALAVRA;
				M[3] = aPALAVRA;
				M[2] = aPALAVRA;
				M[1] = aPALAVRA;
				C[2] = aPALAVRA;
				M[0] = aPALAVRA;
				C[1] = aPALAVRA;
				C[0] = aPALAVRA;
				G 	 = aPALAVRA;
				
				G = G & 1;
				
				C[0] >>= 1;
				C[0] &= 1;
				
				C[1] >>= 2;
				C[1] &= 1;
				
				M[0] >>= 3;
				M[0] &= 1;
				
				C[2] >>= 4;
				C[2] &= 1;

				M[1] >>= 5;
				M[1] &= 1;
				
				M[2] >>= 6;
				M[2] &= 1;
				
				M[3] >>= 7;
				M[3] &= 1;
				
				C[3] >>= 8;
				C[3] &= 1;
				
				M[4] >>= 9;
				M[4] &= 1;
				
				M[5] >>= 10;
				M[5] &= 1;
				
				M[6] >>= 11;
				M[6] &= 1;
				
				M[7] >>= 12;
				M[7] &= 1;
			
				newC[0] = M[0] ^ M[1] ^ M[3] ^ M[4] ^ M[6];
				newC[1] = M[0] ^ M[2] ^ M[3] ^ M[5] ^ M[6];
				newC[2] = M[1] ^ M[2] ^ M[3] ^ M[7];
				newC[3] = M[4] ^ M[5] ^ M[6] ^ M[7];
				
				osAJUDANTES[0] = newC[0] ^ C[0];
				osAJUDANTES[1] = newC[1] ^ C[1];
				osAJUDANTES[2] = newC[2] ^ C[2];
				osAJUDANTES[3] = newC[3] ^ C[3];	
				
				sindrome |= osAJUDANTES[3];
				sindrome <<= 1;
				
				sindrome |= osAJUDANTES[2];
				sindrome <<= 1; 
				
				sindrome |= osAJUDANTES[1];
				sindrome <<= 1;
				
				sindrome |= osAJUDANTES[0];
				
				if(sindrome != 0){
					if(sindrome > 13){
						break;
					}else{ 
						msgout3++;
						switch(sindrome){
							case 1://c0 = bit 1;
								aGRAVACAO = aPALAVRA;
								aGRAVACAO >>= 1;
								aGRAVACAO &= 1;
								aGRAVACAO |= 0xFFFE; //para colocar 1 na parte alta para depois negar;
								aGRAVACAO = ~ aGRAVACAO;
								C[0] = aGRAVACAO;
								msgout1 += 1;
							break;
							
							case 2://c1 = bit 2;
								aGRAVACAO = aPALAVRA;
								aGRAVACAO >>= 2;
								aGRAVACAO &= 1;
								aGRAVACAO |= 0xFFFE; //para colocar 1 na parte alta para depois negar;
								aGRAVACAO = ~ aGRAVACAO;
								C[1] = aGRAVACAO;
								msgout1 += 2;
							break;
							
							case 3://m0 = bit 3;
								aGRAVACAO = aPALAVRA;
								aGRAVACAO >>= 3;
								aGRAVACAO &= 1;
								aGRAVACAO |= 0xFFFE; //para colocar 1 na parte alta para depois negar;
								aGRAVACAO = ~ aGRAVACAO;
								M[0] = aGRAVACAO;
								msgout1 += 3;
							break;
							
							case 4://c2 = bit 4;
								aGRAVACAO = aPALAVRA;
								aGRAVACAO >>= 4;
								aGRAVACAO &= 1;
								aGRAVACAO |= 0xFFFE; //para colocar 1 na parte alta para depois negar;
								aGRAVACAO = ~ aGRAVACAO;
								C[2] = aGRAVACAO;
								msgout1 += 4;
							break;
							
							case 5://m1 = bit 5;
								aGRAVACAO = aPALAVRA;
								aGRAVACAO >>= 5;
								aGRAVACAO &= 1;
								aGRAVACAO |= 0xFFFE; //para colocar 1 na parte alta para depois negar;
								aGRAVACAO = ~ aGRAVACAO;
								M[1] = aGRAVACAO;
								msgout1 += 5;
							break;
							
							case 6://m2 = bit 6;
								aGRAVACAO = aPALAVRA;
								aGRAVACAO >>= 6;
								aGRAVACAO &= 1;
								aGRAVACAO |= 0xFFFE; //para colocar 1 na parte alta para depois negar;
								aGRAVACAO = ~ aGRAVACAO;
								M[2] = aGRAVACAO;
								msgout1 += 6;
							break;
							
							case 7://m3 = bit 7;
								aGRAVACAO = aPALAVRA;
								aGRAVACAO >>= 7;
								aGRAVACAO &= 1;
								aGRAVACAO |= 0xFFFE; //para colocar 1 na parte alta para depois negar;
								aGRAVACAO = ~ aGRAVACAO;
								M[3] = aGRAVACAO;
								msgout1 += 7;
							break;
							
							case 8://c3 = bit 8;
								aGRAVACAO = aPALAVRA;
								aGRAVACAO >>= 8;
								aGRAVACAO &= 1;
								aGRAVACAO |= 0xFFFE; //para colocar 1 na parte alta para depois negar;
								aGRAVACAO = ~ aGRAVACAO;
								C[3] = aGRAVACAO;
								msgout1 += 8;
							break;
							
							case 9://m4 = bit 9;
								aGRAVACAO = aPALAVRA;
								aGRAVACAO >>= 9;
								aGRAVACAO &= 1;
								aGRAVACAO |= 0xFFFE; //para colocar 1 na parte alta para depois negar;
								aGRAVACAO = ~ aGRAVACAO;
								M[4] = aGRAVACAO;
								msgout1 += 9;
							break;
							
							case 10://m5 = bit 10;
								aGRAVACAO = aPALAVRA;
								aGRAVACAO >>= 10;
								aGRAVACAO &= 1;
								aGRAVACAO |= 0xFFFE; //para colocar 1 na parte alta para depois negar;
								aGRAVACAO = ~ aGRAVACAO;
								M[5] = aGRAVACAO;
								msgout1 += 10;
							break;
							
							case 11://m6 = bit 11;
								aGRAVACAO = aPALAVRA;
								aGRAVACAO >>= 11;
								aGRAVACAO &= 1;
								aGRAVACAO |= 0xFFFE; //para colocar 1 na parte alta para depois negar;
								aGRAVACAO = ~ aGRAVACAO;
								M[6] = aGRAVACAO;
								msgout1 += 11;
							break;
							
							case 12://m7 = bit 12;
								aGRAVACAO = aPALAVRA;
								aGRAVACAO >>= 12;
								aGRAVACAO &= 1;
								aGRAVACAO |= 0xFFFE; //para colocar 1 na parte alta para depois negar;
								aGRAVACAO = ~ aGRAVACAO;
								M[7] = aGRAVACAO;
								msgout1 += 12;
							break;
						}
					}
				}
				
				newG = M[7] ^ M[6] ^ M[5] ^ M[4] ^ C[3] ^ M[3] ^ M[2] ^ M[1] ^ C[2] ^ M[0] ^ C[1] ^ C[0];

				aGRAVACAOFINAL |= M[7];
				aGRAVACAOFINAL <<= 1;
				
				aGRAVACAOFINAL |= M[6];
				aGRAVACAOFINAL <<= 1;
				
				aGRAVACAOFINAL |= M[5];
				aGRAVACAOFINAL <<= 1;
				
				aGRAVACAOFINAL |= M[4];
				aGRAVACAOFINAL <<= 1;
				
				aGRAVACAOFINAL |= M[3];
				aGRAVACAOFINAL <<= 1;
				
				aGRAVACAOFINAL |= M[2];
				aGRAVACAOFINAL <<= 1;
				
				aGRAVACAOFINAL |= M[1];
				aGRAVACAOFINAL <<= 1;
				
				aGRAVACAOFINAL |= M[0];

				if(G != newG)
				{
					printf("\n ERRO DUPLO (dois bits flipados)\n");
					msgout++;
					msgout3++;
				}
				if(feof(opn) == 0){
					fwrite(&aGRAVACAOFINAL, (sizeof(aGRAVACAOFINAL))/2, 1, cls);
				}
				if(msgout == 0){
					if(msgout1 == 1){
						printf("\n Erro no bit 1 arrumado\n");
					}else if(msgout1 == 2){
						printf("\n Erro no bit 2 arrumado\n");
					}else if(msgout1 == 3){
						printf("\n Erro no bit 3 arrumado\n");
					}else if(msgout1 == 4){
						printf("\n Erro no bit 4 arrumado\n");
					}else if(msgout1 == 5){
						printf("\n Erro no bit 5 arrumado\n");
					}else if(msgout1 == 6){
						printf("\n Erro no bit 6 arrumado\n");
					}else if(msgout1 == 7){
						printf("\n Erro no bit 7 arrumado\n");
					}else if(msgout1 == 8){
						printf("\n Erro no bit 8 arrumado\n");
					}else if(msgout1 == 9){
						printf("\n Erro no bit 9 arrumado\n");
					}else if(msgout1 == 10){
						printf("\n Erro no bit 10 arrumado\n");
					}else if(msgout1 == 11){
						printf("\n Erro no bit 11 arrumado\n");
					}else if(msgout1 == 12){
						printf("\n Erro no bit 12 arrumado\n");
					}
				}
			}
			if(msgout3 == 0)
			{
				printf("\n\tNao houve erros\n\n");
			}
		}
		fclose(aPONTA);
		remove("aPONTA");
		fclose(opn);
		fclose(cls);
		printf("\n\n\tFINALIZADO...\n\n");
	}
	return 0;

}