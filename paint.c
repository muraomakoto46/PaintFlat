/* べた塗りフラクタル
制作:村尾誠(v)(＾あ＾)(v)
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
	int y=4,x=4;//壁に囲まれた中ならどこでもいい。
	int count=0;
	char direction=' ';
	/*
	     North
	      ↑
	West←┼→East
	      ↓
	     South
	*/
	setFrame();
	displayBlock();
	count=paintFractal(y,x);//引数directionは確認のためのものであって、塗装動作には一切関係ない。
	printf("\n");
	displayBlock();
	printf("1を塗った回数=%d",count);
	input_char();
	return 0;
}
/*
７ｘ７で 、y=4 x=4を始点して塗りだすとこう動く
壁壁壁壁壁壁壁壁壁
壁↑┌┐┌→→┐壁
壁↑↓↑↑┌┐↓壁
壁↑↓↑↑↓↑↓壁
壁↑↓↑●↓↑↓壁
壁↑↓└┐↓↑↓壁
壁↑└┐↑↓↑↓壁
壁└←┘└┘└┘壁
壁壁壁壁壁壁壁壁壁
*/
//一手ずつ確認できるようにしてある。
int paintFractal_s(char direction,int y,int x){
		int count=1;
		if(block[y][x]!=WALL&& block[y][x]!=DONOTPAINT){
			block[y][x]=BLACKINK;//塗る！
		}
		//↑North
		if(block[y-1][x]!=WALL && block[y-1][x]!=DONOTPAINT && block[y-1][x]==WHITE){
			printf("%c\n",direction);
			displayBlockBlock();
			input_char();
			count+=paintFractal_s('N',y-1,x);
		}
		//→East
		if(block[y][x+1]!=WALL && block[y][x+1]!=DONOTPAINT && block[y][x+1]==WHITE){
			printf("%c\n",direction);
			displayBlockBlock();
			input_char();
			count+=paintFractal_s('E',y,x+1);
		}
		//↓South
		if(block[y+1][x]!=WALL && block[y+1][x]!=DONOTPAINT && block[y+1][x]==WHITE){
			printf("%c\n",direction);
			displayBlockBlock();
			input_char();
			count+=paintFractal_s('S',y+1,x);
		}
		//←West          ↓壁            ↓ほかの色           ↓まだ塗ってない場所
		if(block[y][x-1]!=WALL && block[y][x-1]!=DONOTPAINT && block[y][x-1]==WHITE){
			printf("%c\n",direction);
			displayBlockBlock();
			input_char();
			count+=paintFractal_s('W',y,x-1);
		}
	return count;
}
//こちらは 確認のための表示をしないもの
int paintFractal(int y,int x){
	int count=1;
		//最初に引数でxy座標を指定したが それが block[][]のずっと外側だったら？
	if(block[y][x]!=WALL&& block[y][x]!=DONOTPAINT && y>0 && y<HEIGHT && x>0 && x<WIDTH){
			block[y][x]=BLACKINK;//塗る！
		
		//↑North
		if(block[y-1][x]!=DONOTPAINT && block[y-1][x]==WHITE){
			count+=paintFractal(y-1,x);
		}
		//→East
		if(block[y][x+1]!=DONOTPAINT && block[y][x+1]==WHITE){
			count+=paintFractal(y,x+1);
		}
		//↓South
		if(block[y+1][x]!=DONOTPAINT && block[y+1][x]==WHITE){
			count+=paintFractal(y+1,x);
		}
		//←West       ↓ほかの色           ↓まだ塗ってない場所
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
				printf("■");
			}
			if(block[y][x]==WHITE){
				printf("□");
			}
			if(block[y][x]==WALL){
				printf("壁");
			}
			if(block[y][x]==DONOTPAINT){
				printf("○");
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
		fgets(str,n,stdin);//stdinとは標準入力からって意味。普通*fpでファイルから読むけどここをstdinにするとキーボードから読むことができる。
		if(str[strlen(str)-1]=='\n'){//勝手に改行される問題を改善
			str[strlen(str)-1]='\0';
		}
		hantei=sscanf(str,"%c",&mozi);
		if(hantei!=0){
			break;
		}
		printf("入力ミスです。\n");
		printf("入力データ：");
	}
	return mozi;
}
