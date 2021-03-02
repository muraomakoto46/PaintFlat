/* �ׂ��h��t���N�^��
����:������(v)(�O���O)(v)
*/
//
#include<stdio.h>
#include <string.h>
#define HEIGHT 20
#define WIDTH 20
#define WALL 8
#define BLACKINK 1
#define WHITE 0
#define DONOTPAINT 5

int block[HEIGHT][WIDTH];

int paintFractal_s(char direction,int y,int x);
int paintFractal(int y,int x);
void setFrame(void);
void displayBlock(void);
void displayBlockBlock(void);
char input_char(void);
int main()
{
	int y=4,x=4;//�ǂɈ͂܂ꂽ���Ȃ�ǂ��ł������B
	int count=0;
	char direction=' ';
	/*
	     North
	      ��
	West������East
	      ��
	     South
	*/
	setFrame();
	displayBlock();
	count=paintFractal(y,x);//����direction�͊m�F�̂��߂̂��̂ł����āA�h������ɂ͈�؊֌W�Ȃ��B
	printf("\n");
	displayBlock();
	printf("1��h������=%d",count);
	input_char();
	return 0;
}
/*
�V���V�� �Ay=4 x=4���n�_���ēh�肾���Ƃ�������
�ǕǕǕǕǕǕǕǕ�
�ǁ���������������
�ǁ���������������
�ǁ���������������
�ǁ���������������
�ǁ���������������
�ǁ���������������
�Ǆ���������������
�ǕǕǕǕǕǕǕǕ�
*/
//��肸�m�F�ł���悤�ɂ��Ă���B
int paintFractal_s(char direction,int y,int x){
		int count=1;
		if(block[y][x]!=WALL&& block[y][x]!=DONOTPAINT){
			block[y][x]=BLACKINK;//�h��I
		}
		//��North
		if(block[y-1][x]!=WALL && block[y-1][x]!=DONOTPAINT && block[y-1][x]==WHITE){
			printf("%c\n",direction);
			displayBlockBlock();
			input_char();
			count+=paintFractal_s('N',y-1,x);
		}
		//��East
		if(block[y][x+1]!=WALL && block[y][x+1]!=DONOTPAINT && block[y][x+1]==WHITE){
			printf("%c\n",direction);
			displayBlockBlock();
			input_char();
			count+=paintFractal_s('E',y,x+1);
		}
		//��South
		if(block[y+1][x]!=WALL && block[y+1][x]!=DONOTPAINT && block[y+1][x]==WHITE){
			printf("%c\n",direction);
			displayBlockBlock();
			input_char();
			count+=paintFractal_s('S',y+1,x);
		}
		//��West          ����            ���ق��̐F           ���܂��h���ĂȂ��ꏊ
		if(block[y][x-1]!=WALL && block[y][x-1]!=DONOTPAINT && block[y][x-1]==WHITE){
			printf("%c\n",direction);
			displayBlockBlock();
			input_char();
			count+=paintFractal_s('W',y,x-1);
		}
	return count;
}
//������� �m�F�̂��߂̕\�������Ȃ�����
int paintFractal(int y,int x){
	int count=1;
		//�ŏ��Ɉ�����xy���W���w�肵���� ���ꂪ block[][]�̂����ƊO����������H
	if(block[y][x]!=WALL&& block[y][x]!=DONOTPAINT && y>0 && y<HEIGHT && x>0 && x<WIDTH){
			block[y][x]=BLACKINK;//�h��I
		
		//��North
		if(block[y-1][x]!=DONOTPAINT && block[y-1][x]==WHITE){
			count+=paintFractal(y-1,x);
		}
		//��East
		if(block[y][x+1]!=DONOTPAINT && block[y][x+1]==WHITE){
			count+=paintFractal(y,x+1);
		}
		//��South
		if(block[y+1][x]!=DONOTPAINT && block[y+1][x]==WHITE){
			count+=paintFractal(y+1,x);
		}
		//��West       ���ق��̐F           ���܂��h���ĂȂ��ꏊ
		if(block[y][x-1]!=DONOTPAINT && block[y][x-1]==WHITE){
			count+=paintFractal(y,x-1);
		}
	}
	return count;
}


void setFrame(void){
	auto int y=0,x=0;
	for(y=0;y<HEIGHT-1;y++){
		for(x=0;x<WIDTH-1;x++){
			if(y==0||y==HEIGHT-2||x==0||x==WIDTH-2){
				block[y][x]=WALL;
			}else{
				block[y][x]=WHITE;
			}
		}
	}

}

void displayBlock(void){
	auto int y=0,x=0;
	for(y=0;y<HEIGHT-1;y++){
		for(x=0;x<WIDTH-1;x++){
			printf("%d",block[y][x]);		
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}
void displayBlockBlock(void){
	auto int y=0,x=0;
	for(y=0;y<HEIGHT-1;y++){
		for(x=0;x<WIDTH-1;x++){
			if(block[y][x]==BLACKINK){
				printf("��");
			}
			if(block[y][x]==WHITE){
				printf("��");
			}
			if(block[y][x]==WALL){
				printf("��");
			}
			if(block[y][x]==DONOTPAINT){
				printf("��");
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("\n");
}
char input_char(void){
	auto char str[255];
	auto char mozi=0;
	auto int hantei=0;
	auto int n=255;
	while(1){
		fgets(str,n,stdin);//stdin�Ƃ͕W�����͂�����ĈӖ��B����*fp�Ńt�@�C������ǂނ��ǂ�����stdin�ɂ���ƃL�[�{�[�h����ǂނ��Ƃ��ł���B
		if(str[strlen(str)-1]=='\n'){//����ɉ��s�����������P
			str[strlen(str)-1]='\0';
		}
		hantei=sscanf(str,"%c",&mozi);
		if(hantei!=0){
			break;
		}
		printf("���̓~�X�ł��B\n");
		printf("���̓f�[�^�F");
	}
	return mozi;
}
