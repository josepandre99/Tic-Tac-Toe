#include <stdio.h>
#include "boolean.h"
#include <string.h>


void Tulis(char *board);

static FILE * filepf;
static FILE * filecf;
typedef struct {
	char Tab[30];
} Type;

int main() {
  Type MPF[300][10];
	Type MCF[300][10];
	Type Simbol[3];
	Type Final[100];
  int Turn,Step;
  char board[10];
  Type state[10];
	boolean EndGame;
  int i,j,k;

	//Mengisi Matrix dengan data dari File Eksternal
	  filepf = fopen("TTTPlayerFirst.txt", "r");
		filecf = fopen("TTTComFirst.txt", "r");
	  for (i=1; i<=68; i++){
	    for (int j=0; j<=9; j++){
	      fscanf(filepf,"%s",&MPF[i][j].Tab);
			}
	  }
		for (i=1; i<=87; i++){
	    for (int j=0; j<=9; j++){
	      fscanf(filecf,"%s",&MCF[i][j].Tab);
			}
	  }
		for (i=1; i<=6; i++){
			fgets(Simbol[i].Tab,30,filecf);
		}
		for (i=7; i<=12; i++){
			fgets(Simbol[i].Tab,30,filepf);
		}
		for (i=1; i<=35; i++){
			fscanf(filepf,"%s",&Final[i].Tab);
		}
		for (i=36; i<=99; i++){
			fscanf(filecf,"%s",&Final[i].Tab);
		}


  printf("Pilih Giliran Main (1/2)\n1 Untuk Main Pertama\n2 Untuk Main Kedua\n\nMasukkan Pilihan : ");
  scanf("%d",&Turn);
  while (Turn!=1 && Turn!=2) {
    printf("Pilihan Salah \nMasukkan Ulang Pilihan : ");
		scanf("%d",&Turn);
  }

  while (Turn!=3) {

		printf("\n%s%s%s\n",Simbol[4],Simbol[5],Simbol[6]);
		EndGame = false;
    strcpy(state[0].Tab,MPF[2][0].Tab);
      //Jika Pemain Memilih Untuk Melangkah Lebih Dulu
        if (Turn==1){
          j=1;
          printf("Main Pertama Harus Ditengah Ya !!!\n");
          strcpy(board,MPF[2][5].Tab);
          strcpy(state[j].Tab,board);
          printf("Giliran Komputer\n");
          Tulis(board);
					int i=1;
          while (!EndGame){
              while (strcmp(board,MPF[i][0].Tab)!=0) {
                i++;
              }
              printf("Giliran Anda\nMasukkan Langkah (1..9) : ");
              scanf("%d",&Step);
					while (Step!=1&&Step!=2&&Step!=3&&Step!=4&&Step!=5&&Step!=6&&Step!=7&&Step!=8&&Step!=9) {
						printf("Input Langkah Salah !!!!\nMasukkan Langkah Lagi (1..9) : ");
						scanf("%d",&Step );
					}
					if (strcmp(board,state[j].Tab)!=0) {
						j++;
						strcpy(state[j].Tab,board);
					}
              strcpy(board,MPF[i][Step].Tab);
              printf("Giliran Komputer\n");
              Tulis(board);
					for (k=1; k<=99; k++){
						if (strcmp(board,Final[k].Tab)==0){
							EndGame = true;
						}
					}
          }
        }

        //Jika Pemain Memilih Komputer Untuk Melangkah Lebih Dulu
				if (Turn==2){
          j=1;
          strcpy(board,MCF[2][5].Tab);
          strcpy(state[j].Tab,board);
          printf("Giliran Komputer\n");
          Tulis(board);
					int i=1;
          while (!EndGame){
              while (strcmp(board,MCF[i][0].Tab)!=0) {
                i++;
              }
              printf("Giliran Anda\nMasukkan Langkah (1..9) : ");
              scanf("%d",&Step);
					while (Step!=1&&Step!=2&&Step!=3&&Step!=4&&Step!=5&&Step!=6&&Step!=7&&Step!=8&&Step!=9) {
                printf("Input Langkah Salah !!!!\nMasukkan Langkah Lagi (1..9) : ");
                scanf("%d",&Step );
              }
					if (strcmp(board,state[j].Tab)!=0) {
						j++;
						strcpy(state[j].Tab,board);
					}
              strcpy(board,MCF[i][Step].Tab);
              printf("Giliran Komputer\n");
              Tulis(board);
					for (k=1; k<=99; k++){
						if (strcmp(board,Final[k].Tab)==0){
							EndGame = true;
						}
					}
          }
        }

          if (board[9]=='w'){printf("Permainan Selesai Komputer Menang !!!\n");}
          else if (board[9]=='d') {printf("Permainan Seri !!!\n");}

          if(board[9]=='w' || board[9]=='d'){
            printf("State Yang Sudah Dilalui\n");
						j++;
						strcpy(state[j].Tab,board);
            for(int k=0; k<=j; k++){
              printf("%s\n",state[k].Tab);
            }
          }

          printf("\n==================================================\n\n");
          printf("Mau Main Lagi ?? \n1 Untuk Main Pertama\n2 Untuk Main Kedua\n3 Untuk Keluar Game\n\nMasukkan Pilihan : ");
          scanf("%d",&Turn);
          while (Turn!=1 && Turn!=2 && Turn!=3) {
            printf("Pilihan Salah, Masukkan Ulang : \n");
						scanf("%d",&Turn);
          }

    }
    //Pilihan Untuk Keluar Dari Permainan
    if (Turn==3){printf("Terima Kasih Telah Bermain, Sampai Ketemu Lagi\n");}



			  fclose(filepf);
				fclose(filecf);

  return 0;
}


void Tulis(char *board){
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c \n",board[0],board[1],board[2]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c \n",board[3],board[4],board[5]);
  printf("_____|_____|_____\n");
  printf("     |     |     \n");
  printf("  %c  |  %c  |  %c \n",board[6],board[7],board[8]);
  printf("     |     |     \n\n");
}
