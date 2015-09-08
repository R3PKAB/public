
/*臒l����*/

#include "bmp.c"

/* �摜�f�[�^���i�[����\���̕ϐ����`����  */
img tmp1,tmp2;

void reset( int red[], int green[], int blue[] ){		//���ׂĂ̗v�f�Œl��0
	
	int i;
	for( i=0 ; i<256 ; ++i ){
		red[i] = 0;
		green[i] = 0;
		blue[i] = 0;
		
	}
}

void set( int red[] , int green[] , int blue[] ){		//�e�v�f�̐��𐔂��グ��
	
	int i,j,k;
	
	for( k=0 ; k<256 ; ++k ){
		for( i=0 ; i<=tmp2.height-1 ; ++i ){
			for( j=0 ; j<=tmp2.width-1 ; ++j ){
				
				if( tmp1.data[i][j].r == k ){
					red[k]++;
					green[k]++;
					blue[k]++;
				}
			}
		}
	}
	
}

void line( int border ){							//2�l��
	
	int i,j;
	
	for( i=0 ; i<=tmp2.height-1 ; ++i ){
		for( j=0 ; j<=tmp2.width-1 ; ++j ){
			if( tmp2.data[i][j].r < border ){
				tmp2.data[i][j].r = 0;
				tmp2.data[i][j].g = 0;
				tmp2.data[i][j].b = 0;
			} else {
				tmp2.data[i][j].r = 255;
				tmp2.data[i][j].g = 255;
				tmp2.data[i][j].b = 255;
			}
		}
	}
	
	printf("Please wait...\n");
}


void mode( int red[] ){
	
	int i,j;
	int border;
	int min, max, best;
	int top;
	
	best = 0;
	
	for( i=0 ; i<128 ; ++i ){
		
		if( best <= red[i] ){
			best = red[i];
			min = i;
		}
	}
	
	best = 0;
	
	for( i=128 ; i<256 ; ++i ){
		
		if( best <= red[i] ){
			best = red[i];
			max = i;
		}
	}
	
	best = tmp1.height * tmp1.width;;
	
	for( i=min ; i<max ; ++i ){
		
		if( best > red[i] ){
			best = red[i];
			border = i;
		}
	}
	
	line( border );
}

void sweep( int red[] ){
	
	int i,j,k ;
	double pix_black, ave_black;	//���̉�f��,���ϒl
	double pix_white, ave_white;	//���̉�f��,���ϒl
	int border = 0;				//臒l
	double variance[256];			//���U�x�ő�𔻒f���邽�߂̔z��
	double wandb; 					//pix_white * pix_black �̌v�Z���ʂ��i�[����ϐ�
	
	double best;
	
	for( k=0 ; k<256 ; ++k ){
		
		pix_white = 0;
		pix_black = 0;
		ave_white = 0;
		ave_black = 0;
		
		for( i=0 ; i<=tmp2.height-1 ; ++i ){
			for( j=0 ; j<=tmp2.width-1 ; ++j ){
				
				if( tmp1.data[i][j].r <= k ){
					pix_black++;
					ave_black = tmp1.data[i][j].r + ave_black;
					
				}else {
					pix_white++;
					ave_white = tmp1.data[i][j].r + ave_white;
				}
				
			}
		}
		
		if( pix_black == 0 ) ave_black = 0;
		else ave_black = ave_black / pix_black;
		
		if( pix_white == 0 ) ave_white = 0;
		else ave_white = ave_white / pix_white;
		
		variance[k] = ave_black - ave_white;
		variance[k] = variance[k] * variance[k];
		wandb = pix_black * pix_white;
		variance[k] = wandb * variance[k];
		
	}
	
	best = 0;
	
	for( i=0 ; i<256 ; ++i ){
		
		if( best < variance[i] ) {
			best = variance[i];
			border = i;
		}
	}
	
	
	printf("%d\n", border );
	line( border );
	
}

void mov_ave( int red[] ){ //�ړ����ϖ@
	
	int i, j, k, m, n;
	int si, sj;
	int NewPixcel;
	int border;		//臒l
	int ave_black, ave_white;
	int pix_black, pix_white;
	int variance[256];
	int wandb;
	
	int best;
	
	for( i=51 ; i<tmp2.height-51 ; ++i ){
		for( j=51 ; j<tmp2.width-51 ; ++j ){
			
			
			for( k=0 ; k<256 ; ++k ){
				
				pix_white = 0;
				pix_black = 0;
				ave_white = 0;
				ave_black = 0;
				
				for( m=-26 ; m<25 ; ++m ){
					for( n=-26 ; n<25 ; ++n ){
						
						if( tmp1.data[i+m][j+n].r < k ){
							pix_black++;
							ave_black = tmp1.data[i+m][j+n].r + ave_black;
						} else {
							pix_white++;
							ave_white = tmp1.data[i+m][j+n].r + ave_white;
						}
					}
				}
				
				if( pix_black == 0 ) ave_black = 0;
				else ave_black = ave_black / pix_black;
				
				if( pix_white == 0 ) ave_white = 0;
				else ave_white = ave_white / pix_white;
				
				variance[k] = ave_black - ave_white;
				variance[k] = variance[k] * variance[k];
				wandb = pix_black * pix_white;
				variance[k] = wandb * variance[k];
			}
			
			best = 0;
			
			for( k=0 ; k<256 ; ++k ){
				
				if( best < variance[k] ){
					best = variance[k];
					border = k;
				}
			}
			
			
			if( tmp1.data[i][j].r < border ){
				tmp2.data[i][j].r = 0;
				tmp2.data[i][j].b = 0;
				tmp2.data[i][j].g = 0;
			} else {
				tmp2.data[i][j].r = 255;
				tmp2.data[i][j].b = 255;
				tmp2.data[i][j].g = 255;
			}
		}
	}
}

void main()
{
	int fmode=0;
	int i,j;
	int red[256];
	int green[256];
	int blue[256];

	FILE *f;

	
	char *filename="text_gray.bmp";
	
	ReadBmp(filename,&tmp1);
	
	printf("%d %d\n",tmp1.height,tmp1.width);
	
	while(1){
	
		printf(" 0:���[�h�@\n 1:���ʕ��͖@\n 2:�ړ����ϖ@\n 3:�I��\n");
		scanf("%d",&fmode);
		
		if(fmode > 2) break;
		
		tmp2=tmp1;     /* ���̉摜�t�@�C���̂��ׂẲ摜�f�[�^���R�s�[���� */
	
		reset( red, green, blue );
	
		Gray( &tmp2 , &tmp1 );
	
		set( red , green , blue );
	
		switch(fmode){
			case 0 : mode(red);		//���[�h�@
					 break;
			case 1 : sweep(red);	//���ʕ��͖@
					 break;
			case 2 : mov_ave(red);	//�ړ����ϖ@
					 break;
		}
	WriteBmp("border.bmp",&tmp2);
	
	PrintBmpInfo("border.bmp");
	}
}
