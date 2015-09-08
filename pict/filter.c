
/*	�e�t�B���^�������s�� */

#include  "bmp.c"


#define RED 0
#define GREEN 1
#define BLUE 2

/* �摜�f�[�^���i�[����\���̕ϐ����`����  */
img tmp1,tmp2;

void store( int pix[] ,int i, int j, int u, int d ,int right , int left ,int color){ //RGB�l�̊i�[
	
	switch(color){
		case 0 : pix[0] = tmp1.data[u][right].r;
			 pix[1] = tmp1.data[u][j].r;
			 pix[2] = tmp1.data[u][left].r;
			 pix[3] = tmp1.data[i][right].r;
			 pix[4] = tmp1.data[i][j].r;
			 pix[5] = tmp1.data[i][left].r;
			 pix[6] = tmp1.data[d][right].r;
			 pix[7] = tmp1.data[d][j].r;
			 pix[8] = tmp1.data[d][left].r;
			 break;
		case 1 : pix[0] = tmp1.data[u][right].g;
			 pix[1] = tmp1.data[u][j].g;
			 pix[2] = tmp1.data[u][left].g;
			 pix[3] = tmp1.data[i][right].g;
			 pix[4] = tmp1.data[i][j].g;
			 pix[5] = tmp1.data[i][left].g;
			 pix[6] = tmp1.data[d][right].g;
			 pix[7] = tmp1.data[d][j].g;
			 pix[8] = tmp1.data[d][left].g;
			 break;
		case 2 : pix[0] = tmp1.data[u][right].b;
			 pix[1] = tmp1.data[u][j].b;
			 pix[2] = tmp1.data[u][left].b;
			 pix[3] = tmp1.data[i][right].b;
			 pix[4] = tmp1.data[i][j].b;
			 pix[5] = tmp1.data[i][left].b;
			 pix[6] = tmp1.data[d][right].b;
			 pix[7] = tmp1.data[d][j].b;
			 pix[8] = tmp1.data[d][left].b;
			 break;
	}
}

void ave( void ){	//���ω��t�B���^
	int NewPixcel;
	int pix[9];
	int pix_1 , pix_2 , pix_3 ;
	int i , j;
	int u , d , right , left;
	
	for (i=1; i<=tmp2.height-2; ++i) {
		
		u = i-1;
		d = i+1;
		
		for (j=1; j<=tmp2.width-2; ++j) {
			
			left = j-1;
			right = j+1;
			
			// R
			store( pix,i,j,u,d,right,left,RED ); //9pixcel�̒l��pix[]�Ɋi�[
			pix_1 = pix[0] + pix[1] + pix[2];
			pix_2 = pix[3] + pix[4] + pix[5];
			pix_3 = pix[6] + pix[7] + pix[8];
			
			NewPixcel = (pix_1 + pix_2 + pix_3) / 9;//���ς��Ƃ�;
			
			tmp2.data[i][j].r = NewPixcel;
			
			//G
			store( pix,i,j,u,d,right,left, GREEN );
			pix_1 = pix[0] + pix[1] + pix[2];
			pix_2 = pix[3] + pix[4] + pix[5];
			pix_3 = pix[6] + pix[7] + pix[8];
			
			NewPixcel = (pix_1 + pix_2 + pix_3) / 9;
			
			tmp2.data[i][j].g = NewPixcel;
			
			//B
			store( pix,i,j,u,d,right,left, BLUE );
			pix_1 = pix[0] + pix[1] + pix[2];
			pix_2 = pix[3] + pix[4] + pix[5];
			pix_3 = pix[6] + pix[7] + pix[8];
			
			NewPixcel = (pix_1 + pix_2 + pix_3) / 9;
			
			tmp2.data[i][j].b = NewPixcel;
		}
	}
}

void aw_ave( void ){	//���d���ω��t�B���^�֐�
	
	int NewPixcel;
	int pix_1 , pix_2 , pix_3 ;
	int i , j;
	int u , d , right , left;
	int pix[9];
	
	for (i=1; i<=tmp2.height-2; ++i) {
		
		u = i-1;
		d = i+1;
		
		for (j=1; j<=tmp2.width-2; ++j) {
			
			left = j-1;
			right = j+1;
			
			// R
			store( pix,i,j,u,d,right,left,RED );
			pix_1 = pix[0] + 2 * pix[1] + pix[2];			//1 2 1
			pix_2 = 2 * pix[3] + 4 * pix[4] + 2 * pix[5];		//2 4 2
			pix_3 = pix[6] + 2 * pix[7] + pix[8];			//1 2 1
			
			NewPixcel = (pix_1 + pix_2 + pix_3) / 16;
			
			
			tmp2.data[i][j].r = NewPixcel;
			
			//G
			store( pix,i,j,u,d,right,left,GREEN );
			pix_1 = pix[0] + 2 * pix[1] + pix[2];			// 1 2 1
			pix_2 = 2 * pix[3] + 4 * pix[4] + 2 * pix[5];		// 2 4 2
			pix_3 = pix[6] + 2 * pix[7] + pix[8];			// 1 2 1
			
			NewPixcel = (pix_1 + pix_2 + pix_3) / 16;
			
			tmp2.data[i][j].g = NewPixcel;
			
			//B
			store( pix,i,j,u,d,right,left,BLUE );
			pix_1 = pix[0] + 2 * pix[1] + pix[2];			// 1 2 1
			pix_2 = 2 * pix[3] + 4 * pix[4] + 2 * pix[5];		// 2 4 2
			pix_3 = pix[6] + 2 * pix[7] + pix[8];			// 1 2 1
			
			NewPixcel = (pix_1 + pix_2 + pix_3) / 16;
			
			tmp2.data[i][j].b = NewPixcel;
		}
	}
}

int sort( int med[] ){ //���f�B�A���t�B���^ �\�[�g
	int best , comp;
	int i , j;
	
	best = med[0]; 
	for( i=1 ; i<9 ; ++i ){
		for( j=i ; j<9 ; ++j ){
			
			if( best < med[j] ){
				comp = med[j];
				med[j] = best;
				best = comp;
			}
		}
		med[i] = best;
		best = 0;
	}
	
	return( med[4] );
}

void median( void ){	//���f�B�A���t�B���^�֐�
	
	int NewPixcel;
	int pix_1 , pix_2 , pix_3 ;
	int i , j , k;
	int u , d , right , left;
	int med[9];
	
	for( i=1 ; i<=tmp2.height-2; ++i ){
		
		u = i-1;
		d = i+1;
		
		for( j=1 ; j<=tmp2.width-2 ; ++j ){
			
			left = j-1;
			right = j+1;
			
			//R
			store( med,i,j,u,d,right,left,RED );
			
			tmp2.data[i][j].r = sort( med );
			
			
			//G
			store( med,i,j,u,d,right,left,GREEN );
			
			tmp2.data[i][j].g = sort( med );
			
			//B
			store( med,i,j,u,d,right,left,BLUE );
			
			tmp2.data[i][j].b = sort( med );
			
		}
	}
	
}

void prewitt( void ){	//�P�������s���[�E�B�b�g�t�B���^
	
	int i, j;
	int u, d,left,right;
	int pix_1, pix_2, pix_3;
	int NewPixcel;
	int pix[9];
	
	for( i=1 ; i<=tmp2.height-2 ; i++ ){
		
		u = i-1;
		d = i+1;
		
		for( j=1 ; j<=tmp2.width-2 ; j++ ){
			
			left = j-1;
			right = j+1;
			
			store( pix,i,j,u,d,right,left,RED );
			pix_1 = -1 * pix[0] + 0 * pix[1] + 1 * pix[2];		// -1  0  1
			pix_2 = -1 * pix[3] + 0 * pix[4] + 1 * pix[5];		// -1  0  1
			pix_3 = -1 * pix[6] + 0 * pix[7] + 1 * pix[8];	// -1  0  1
			
			NewPixcel = abs(pix_1 + pix_2 + pix_3);
			//NewPixcel = abs(pix_1) + abs(pix_2) + abs(pix_3);
			//NewPixcel = NewPixcel / 9;
			tmp2.data[i][j].r = NewPixcel;
			
			store( pix,i,j,u,d,right,left,GREEN );
			pix_1 = -1 * pix[0] + 0 * pix[1] + 1 * pix[2];		// -1  0  1
			pix_2 = -1 * pix[3] + 0 * pix[4] + 1 * pix[5];		// -1  0  1
			pix_3 = -1 * pix[6] + 0 * pix[7] + 1 * pix[8];	// -1  0  1
			
			NewPixcel = abs(pix_1 + pix_2 + pix_3);
			//NewPixcel = abs(pix_1) + abs(pix_2) + abs(pix_3);
			//NewPixcel = NewPixcel / 9;
			tmp2.data[i][j].g = NewPixcel;
			
			store( pix,i,j,u,d,right,left,BLUE );
			pix_1 = -1 * pix[0] + 0 * pix[1] + 1 * pix[2];		// -1  0  1
			pix_2 = -1 * pix[3] + 0 * pix[4] + 1 * pix[5];		// -1  0  1
			pix_3 = -1 * pix[6] + 0 * pix[7] + 1 * pix[8];	// -1  0  1
			
			NewPixcel = abs(pix_1 + pix_2 + pix_3);
			//NewPixcel = abs(pix_1) + abs(pix_2) + abs(pix_3);
			//NewPixcel = NewPixcel / 9;
			tmp2.data[i][j].b = NewPixcel;
			
		}
	}
}

void sobel( void ){	//�P�������\�[�x���t�B���^
	
	int i, j;
	int u, d,left,right;
	int pix_1, pix_2, pix_3;
	int NewPixcel;
	int pix[9];
	
	for( i=1 ; i<=tmp2.height-2 ; i++ ){
		
		u = i-1;
		d = i+1;
		
		for( j=1 ; j<=tmp2.width-2 ; j++ ){
			
			left = j-1;
			right = j+1;
			
			store( pix,i,j,u,d,right,left,RED );
			pix_1 = -1 * pix[0] + 0 * pix[1] + 1 * pix[2];		//  -1  0   1
			pix_2 = -2 * pix[3] + 0 * pix[4] + 2 * pix[5];		//  -2  0   2
			pix_3 = -1 * pix[6] + 0 * pix[7] + 1 * pix[8];		// -1   0   1
			
			NewPixcel = abs(pix_1 + pix_2 + pix_3);
			//NewPixcel = abs(pix_1) + abs(pix_2) + abs(pix_3);
			//NewPixcel = NewPixcel / 9;
			tmp2.data[i][j].r = NewPixcel;
			
			store( pix,i,j,u,d,right,left,GREEN );
			pix_1 = -1 * pix[0] + 0 * pix[1] + 1 * pix[2];		//  -1  0   1
			pix_2 = -2 * pix[3] + 0 * pix[4] + 2 * pix[5];		//  -2  0   2
			pix_3 = -1 * pix[6] + 0 * pix[7] + 1 * pix[8];		// -1  0  1
			
			NewPixcel = abs(pix_1 + pix_2 + pix_3);
			//NewPixcel = abs(pix_1) + abs(pix_2) + abs(pix_3);
			//NewPixcel = NewPixcel / 9;
			tmp2.data[i][j].g = NewPixcel;
			
			store( pix,i,j,u,d,right,left,BLUE );
			pix_1 = -1 * pix[0] + 0 * pix[1] + 1 * pix[2];		//  -1 0  1
			pix_2 = -2 * pix[3] + 0 * pix[4] + 2 * pix[5];		//  -2  0   2
			pix_3 = -1 * pix[6] + 0 * pix[7] + 1 * pix[8];		// -1  0  1
			
			NewPixcel = abs(pix_1 + pix_2 + pix_3);
			//NewPixcel = abs(pix_1) + abs(pix_2) + abs(pix_3);
			//NewPixcel = NewPixcel / 9;
			tmp2.data[i][j].b = NewPixcel;
			
		}
	}
}

void laplacian( void ){ //�Q������ 
	
	int i, j;
	int u, d,left,right;
	int pix_1, pix_2, pix_3;
	int NewPixcel;
	int pix[9];
	
	for( i=1 ; i<=tmp2.height-2 ; i++ ){
		
		u = i-1;
		d = i+1;
		
		for( j=1 ; j<=tmp2.width-2 ; j++ ){
			
			left = j-1;
			right = j+1;
			
			store( pix,i,j,u,d,right,left,RED );
			pix_1 = 1 * pix[0] + 1 * pix[1] + 1 * pix[2];		// 1  1  1
			pix_2 = 1 * pix[3] + -8 * pix[4] + 1 * pix[5];		// 1 -8  1
			pix_3 = 1 * pix[6] + 1 * pix[7] + 1 * pix[8];		// 1  1  1
			
			NewPixcel = (pix_1 + pix_2 + pix_3) / 9;
			tmp2.data[i][j].r = NewPixcel;
			
			store( pix,i,j,u,d,right,left,GREEN );
			pix_1 = 1 * pix[0] + 1 * pix[1] + 1 * pix[2];		// 1  1  1
			pix_2 = 1 * pix[3] + -8 * pix[4] + 1 * pix[5];		// 1 -8  1
			pix_3 = 1 * pix[6] + 1 * pix[7] + 1 * pix[8];		// 1  1  1
			
			NewPixcel = (pix_1 + pix_2 + pix_3) / 9;
			tmp2.data[i][j].g = NewPixcel;
			
			store( pix,i,j,u,d,right,left,BLUE );
			pix_1 = 1 * pix[0] + 1 * pix[1] + 1 * pix[2];		// 1  1  1
			pix_2 = 1 * pix[3] + -8 * pix[4] + 1 * pix[5];		// 1 -8  1
			pix_3 = 1 * pix[6] + 1 * pix[7] + 1 * pix[8];		// 1  1  1
			
			NewPixcel = (pix_1 + pix_2 + pix_3) / 9;
			tmp2.data[i][j].b = NewPixcel;
			
		}
	}
}

void sharp( void ){	//�N�s�� 
	
	int i, j;
	int u, d,left,right;
	int pix_1, pix_2, pix_3;
	int NewPixcel;
	int pix[9];
	
	for( i=1 ; i<=tmp2.height-2 ; i++ ){
		
		u = i-1;
		d = i+1;
		
		for( j=1 ; j<=tmp2.width-2 ; j++ ){
			
			left = j-1;
			right = j+1;
			
			store( pix,i,j,u,d,right,left,RED );
			pix_1 = -1 * pix[0] + -1 * pix[1] +  -1* pix[2];	// -1  -1 -1
			pix_2 = -1 * pix[3] + 9 * pix[4] + -1 * pix[5];		// -1  9  -1
			pix_3 = -1 * pix[6] + -1 * pix[7] + -1 * pix[8];	// -1  -1 -1
			
			NewPixcel = (pix_1 + pix_2 + pix_3) / 9;
			tmp2.data[i][j].r = NewPixcel;
			
			store( pix,i,j,u,d,right,left,GREEN );
			pix_1 = -1 * pix[0] + -1 * pix[1] + -1 * pix[2];	// -1  -1 -1
			pix_2 = -1 * pix[3] + 9 * pix[4] + -1 * pix[5];		// -1  9  -1
			pix_3 = -1 * pix[6] + -1 * pix[7] + -1 * pix[8];	// -1  -1 -1
			
			NewPixcel = (pix_1 + pix_2 + pix_3) / 9;
			tmp2.data[i][j].g = NewPixcel;
			
			store( pix,i,j,u,d,right,left,BLUE );
			pix_1 = -1 * pix[0] + -1 * pix[1] + -1 * pix[2];	// -1  -1 -1
			pix_2 = -1 * pix[3] + 9 * pix[4] + -1 * pix[5];		// -1  9  -1
			pix_3 = -1 * pix[6] + -1 * pix[7] + -1 * pix[8];	// -1  -1 -1
			
			NewPixcel = (pix_1 + pix_2 + pix_3) / 9;
			tmp2.data[i][j].b = NewPixcel;
			
		}
	}
}

void main( void ){
	
	int fmode = 0;

	FILE *f;

	char *filename="stationery.bmp";

	ReadBmp(filename,&tmp1);


	printf("%d %d\n",tmp1.height,tmp1.width);
	
	while(1){
		
		
		printf(" 0:���ω��t�B���^\n 1:���d���ω��t�B���^\n 2:���f�B�A���t�B���^\n 3:�s���[�E�B�b�g�t�B���^\n 4:�\�[�x���t�B���^\n 5:�񎟔���\n 6:�N�s��\n 7:�I��\n");
		scanf("%d",&fmode);
		
		if(fmode > 6) break;

		tmp2=tmp1;     /* ���̉摜�t�@�C���̂��ׂẲ摜�f�[�^���R�s�[���� */

  		switch(fmode){
			case 0 : ave(); // ���ω��t�B���^
					break;
			case 1 : aw_ave(); //���d���ω��t�B���^
					break;
			case 2 : median(); //���f�B�A���t�B���^
					break;
			case 3 : prewitt();//�s���[�E�B�b�g�t�B���^
					break;
			case 4 : sobel();//�\�[�x���t�B���^
					break;
			case 5 : laplacian();//�񎟔���
					break;
			case 6 : sharp();//�N�s��
					break;
  		}
  			
		WriteBmp("filter.bmp",&tmp2);
		PrintBmpInfo("filter.bmp");
	}
	
}
