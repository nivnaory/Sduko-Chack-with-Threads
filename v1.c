
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define ROW 9
#define COL 9
#define NUM_THREADS	27
void *checkRowSuduko(void *param);
void *checkColSuduko(void *param);
void *checksubMatrixSuduko(void *param);
int resultArray[NUM_THREADS];
int matrixToCheak[ROW][COL];
int helpArr[ROW][COL]={0};
int helpArr1[ROW][COL]={0};
int helpArr2[ROW][COL]={0};

int main(int argc,char  *argv[]) {
	// access to parameters passed to this thread
		pthread_t threads[NUM_THREADS];
		int tid[NUM_THREADS];
		FILE *fp;
		int rc;
		int t;
                //open file to  read  the  possible solution  from file
		fp=fopen(argv[1],"r");
		for (int i=0;i<ROW;i++){
			for (int j=0;j<COL;j++){
				fscanf(fp,"%d",&matrixToCheak[i][j]);
			}
		}

		// Launch threads and pass the thread id as a parameter
		for (t = 0; t < NUM_THREADS; t++) {
			printf("In main: creating thread %d\n", t);
			tid[t] = t;
			if (t>=0 &&t<9){
				rc = pthread_create(&threads[t], NULL, checkRowSuduko, (void *) (&tid[t]));
			}else if (t>=9 &&t<18){
				rc = pthread_create(&threads[t], NULL, checkColSuduko, (void *) (&tid[t]));
			}else {
				rc = pthread_create(&threads[t], NULL, checksubMatrixSuduko, (void *) (&tid[t]));
			}
			if (rc) {
				printf("ERROR; return code from pthread_create() is %d\n", rc);
				exit(-1);
			}
		}
		for  (int i=0;i<NUM_THREADS;i++){
			pthread_join(threads[i],NULL);
		}
		for (int j=0;j<NUM_THREADS;j++){
			if (resultArray[j]==0){
				printf("SULUTION IN NOT CORRECT!!!");
				exit (0);
			}
		}
		printf("SULUTION IS CORRECT!!!");

		/* Last thing that main() should do */
		pthread_exit(NULL);
	}
       // check the row of the Possible solution
	void *checkRowSuduko(void *param) {
		// access to parameters passed to this thread
		int tid = *(int *) param;
		switch(tid){
		case 0:
			for (int i=0;i<ROW;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[i][0]==helpArr[0][j]){
						resultArray[0]=0;
						return NULL;
					}
				}
				helpArr[0][i]=matrixToCheak[i][0];
			}
			resultArray[0]=1;
			break;

		case 1:
			for (int i=0;i<ROW;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[i][1]==helpArr[1][j]){
						resultArray[1]=0;
						return NULL;

					}
				}
				helpArr[1][i]=matrixToCheak[i][1];
			}
			resultArray[1]=1;
			break;

		case 2:
			for (int i=0;i<ROW;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[i][2]==helpArr[2][j]){
						resultArray[2]=0;
						return NULL;

					}
				}
				helpArr[2][i]=matrixToCheak[i][2];
			}
			resultArray[2]=1;
			break;



		case 3:
			for (int i=0;i<ROW;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[i][3]==helpArr[3][j]){
						resultArray[3]=0;
						return NULL;

					}
				}
				helpArr[3][i]=matrixToCheak[i][3];
			}
			resultArray[3]=1;
			break;

		case 4:
			for (int i=0;i<ROW;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[i][4]==helpArr[4][j]){
						resultArray[4]=0;
						return NULL;

					}
				}
				helpArr[4][i]=matrixToCheak[i][4];
			}
			resultArray[4]=1;
			break;
		case 5:
			for (int i=0;i<ROW;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[i][5]==helpArr[5][j]){
						resultArray[5]=0;
						return NULL;

					}
				}
				helpArr[5][i]=matrixToCheak[i][5];
			}
			resultArray[5]=1;
			break;
		case 6:
			for (int i=0;i<ROW;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[i][6]==helpArr[6][j]){
						resultArray[6]=0;
						return NULL;

					}
				}
				helpArr[6][i]=matrixToCheak[i][6];
			}
			resultArray[6]=1;
			break;
		case 7:
			for (int i=0;i<ROW;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[i][7]==helpArr[7][j]){
						resultArray[7]=0;
						return NULL;

					}
				}
				helpArr[7][i]=matrixToCheak[i][7];
			}
			resultArray[7]=1;
			break;
		case 8:
			for (int i=0;i<ROW;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[i][8]==helpArr[8][j]){
						resultArray[8]=0;
						return NULL;

					}
				}
				helpArr[8][i]=matrixToCheak[i][8];
			}
			resultArray[8]=1;
			break;

		}




		// Clean exit

	}
// check the column of the Possible solution

	void *checkColSuduko(void *param){
		int tid = *(int *) param;
		switch(tid){
		case 9:
			for (int i=0;i<COL;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[0][i]==helpArr1[0][j]){
						resultArray[9]=0;
						return NULL;
					}
				}
				helpArr1[0][i]=matrixToCheak[0][i];
			}
			resultArray[9]=1;
			break;
		case 10:
			for (int i=0;i<COL;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[1][i]==helpArr1[1][j]){
						resultArray[10]=0;
						return NULL;
					}
				}
				helpArr1[1][i]=matrixToCheak[1][i];
			}
			resultArray[10]=1;
			break;

		case 11:
			for (int i=0;i<COL;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[2][i]==helpArr1[2][j]){
						resultArray[11]=0;
						return NULL;
					}
				}
				helpArr1[2][i]=matrixToCheak[2][i];
			}
			resultArray[11]=1;
			break;
		case 12:
			for (int i=0;i<COL;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[3][i]==helpArr1[3][j]){
						resultArray[12]=0;
						return NULL;
					}
				}
				helpArr1[3][i]=matrixToCheak[3][i];
			}
			resultArray[12]=1;
			break;
		case 13:
			for (int i=0;i<COL;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[4][i]==helpArr1[4][j]){
						resultArray[14]=0;
						return NULL;
					}
				}
				helpArr1[4][i]=matrixToCheak[4][i];
			}
			resultArray[13]=1;
			break;
		case 14:
			for (int i=0;i<COL;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[5][i]==helpArr1[5][j]){
						resultArray[14]=0;
						return NULL;
					}
				}
				helpArr1[5][i]=matrixToCheak[5][i];
			}
			resultArray[14]=1;
			break;
		case 15:
			for (int i=0;i<COL;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[6][i]==helpArr1[6][j]){
						resultArray[15]=0;
						return NULL;
					}
				}
				helpArr1[6][i]=matrixToCheak[6][i];
			}
			resultArray[15]=1;
			break;
		case 16:
			for (int i=0;i<COL;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[7][i]==helpArr1[7][j]){
						resultArray[16]=0;
						return NULL;
					}
				}
				helpArr1[7][i]=matrixToCheak[7][i];
			}
			resultArray[16]=1;
			break;
		case 17:
			for (int i=0;i<COL;i++){
				for (int j=0;j<i;j++){
					if (matrixToCheak[8][i]==helpArr1[8][j]){
						resultArray[17]=0;
						return NULL;
					}
				}
				helpArr1[8][i]=matrixToCheak[8][i];
			}
			resultArray[17]=1;
			break;

		}
	}
       //check sub matrix of the possible solution 
	void *checksubMatrixSuduko(void *param){
		int tid = *(int *) param;
		switch(tid){
		case 18:
			for (int i=0;i<3;i++){
				for (int j=0;j<3;j++){
					for (int k=0;k<i*3+j;k++){
						if (matrixToCheak[i][j]==helpArr2[0][k]){
							resultArray[18]=0;
							return NULL;
						}
					}
					helpArr2[0][i*3+j]=matrixToCheak[i][j];
				}
			}
			resultArray[18]=1;
			break;
		case 19:
			for (int i=0;i<3;i++){
				for (int j=0;j<3;j++){
					for (int k=0;k<i*3+j;k++){
						if (matrixToCheak[i][j+3]==helpArr2[1][k]){
							resultArray[19]=0;
							return NULL;
						}
					}
					helpArr2[1][i*3+j]=matrixToCheak[i][j+3];
				}
			}
			resultArray[19]=1;
			break;
		case 20:
			for (int i=0;i<3;i++){
				for (int j=0;j<3;j++){
					for (int k=0;k<i*3+j;k++){
						if (matrixToCheak[i][j+6]==helpArr2[2][k]){
							resultArray[20]=0;
							return NULL;
						}
					}
					helpArr2[2][i*3+j]=matrixToCheak[i][j+6];
				}
			}
			resultArray[20]=1;
			break;
		case 21:
			for (int i=0;i<3;i++){
				for (int j=0;j<3;j++){
					for (int k=0;k<i*3+j;k++){
						if (matrixToCheak[i+3][j]==helpArr2[3][k]){
							resultArray[21]=0;
							return NULL;
						}
					}
					helpArr2[3][i*3+j]=matrixToCheak[i+3][j];
				}
			}
			resultArray[21]=1;
			break;
		case 22:
			for (int i=0;i<3;i++){
				for (int j=0;j<3;j++){
					for (int k=0;k<i*3+j;k++){
						if (matrixToCheak[i+3][j+3]==helpArr2[4][k]){
							resultArray[22]=0;
							return NULL;
						}
					}
					helpArr2[4][i*3+j]=matrixToCheak[i+3][j+3];
				}
			}
			resultArray[22]=1;
			break;
		case 23:
			for (int i=0;i<3;i++){
				for (int j=0;j<3;j++){
					for (int k=0;k<i*3+j;k++){
						if (matrixToCheak[i+3][j+6]==helpArr2[5][k]){
							resultArray[23]=0;
							return NULL;
						}
					}
					helpArr2[5][i*3+j]=matrixToCheak[i+3][j+6];
				}
			}
			resultArray[23]=1;
			break;
		case 24:
			for (int i=0;i<3;i++){
				for (int j=0;j<3;j++){
					for (int k=0;k<i*3+j;k++){
						if (matrixToCheak[i+6][j]==helpArr2[6][k]){
							resultArray[24]=0;
							return NULL;
						}
					}
					helpArr2[6][i*3+j]=matrixToCheak[i+6][j];
				}
			}
			resultArray[24]=1;
			break;
		case 25:
			for (int i=0;i<3;i++){
				for (int j=0;j<3;j++){
					for (int k=0;k<i*3+j;k++){
						if (matrixToCheak[i+6][j+3]==helpArr2[7][k]){
							resultArray[25]=0;
							return NULL;
						}
					}
					helpArr2[7][i*3+j]=matrixToCheak[i+6][j+3];
				}
			}
			resultArray[25]=1;
			break;
		case 26:
			for (int i=0;i<3;i++){
				for (int j=0;j<3;j++){
					for (int k=0;k<i*3+j;k++){
						if (matrixToCheak[i+6][j+6]==helpArr2[8][k]){
							resultArray[26]=0;
							return NULL;
						}
					}
					helpArr2[8][i*3+j]=matrixToCheak[i+6][j+6];
				}
			}
			resultArray[26]=1;
			break;

		}
	}


