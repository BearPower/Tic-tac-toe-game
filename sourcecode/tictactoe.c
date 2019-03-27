#include <stdio.h>
#include <conio.h>
#include <string.h>

//making history matrix holding the history fo the game(like triple stack stack)
int history[4][11];
int movecount = 1;
int lastmove;


int main ()
{
	Manu();
}

int Manu(){
	int control;
	int choice=1;
	char indicator[2];
	indicator[1]=' ';
	
	
	while(1){
		system("cls");
		indicator[choice]='>';
		printf("\n");
		printf("	BEARPOWERS Tic Tac Toe\n");
		printf("\n");
		printf("	Main Manu\n\n		%cPlay ( 2 Player mode ).\n",indicator[1]);
		printf("\n");
		printf("	Navigate the manu with up and down arrow keys \n	 and press Enter to select\n");
		control=_getch();
		switch(control){
				case 72://up
					if(choice>1){
					indicator[choice]=' ';
					choice--;
					}
					break;
				case 80://down
					if(choice<1){
					indicator[choice]=' ';
					choice++;
					}
					break;
				case 13://enter
					if(choice==1){
						Game();
					}
		}
	}
	return 1;
}

int Game(){
	//seting the enitial history move vall
	history[0][0]=0;
	history[1][0]=0;
	history[2][0]=0;
	history[3][0]=0;
	movecount = 1;
	
//initialize the map
	char map[3][3];
	char nav[6][3];
	int ver = 0;
	int hor = 0;
	int win = 0;
	int player = 1;
	int  pos[2];
	pos[0]=0;
	pos[1]=0;
	int control;
	char mark;
	int	vicposchek[2];
	int victorycounter=0;
	char worr[50] = "";
	
//populate navigation
	while(ver<=5){
		while(hor<=2){
			nav[ver][hor]=' ';
			hor++;
		}
		hor=0;
		ver++;
	}
//reset the population counter for x and y
	hor=0;
	ver=0;
//populate the map
	while(ver<=2){
		while(hor<=2){
			map[ver][hor]=' ';
			hor++;
		}
		hor=0;
		ver++;
	}
//mail loop of the game
	while(win==0){	
		system("cls");
		
//initialize player position from top rigth corner
		nav[pos[0]*2][pos[1]]='>';
		nav[pos[0]*2+1][pos[1]]='<';
//print the map
		printf("\n");
		printf("	BEARPOWERS Tic Tac Toe\n");
		printf("\n");
		printf("		Game board\n");
		printf("\n");
		printf("\n");
		printf("		+-----------+\n");
		printf("		|%c%c%c|%c%c%c|%c%c%c|\n",nav[0][0],map[0][0],nav[1][0],nav[2][0],map[1][0],nav[3][0],nav[4][0],map[2][0],nav[5][0]);
		printf("		|---|---|---|\n");
		printf("		|%c%c%c|%c%c%c|%c%c%c|		%s\n",nav[0][1],map[0][1],nav[1][1],nav[2][1],map[1][1],nav[3][1],nav[4][1],map[2][1],nav[5][1],worr);
		printf("		|---|---|---|\n");
		printf("		|%c%c%c|%c%c%c|%c%c%c|\n",nav[0][2],map[0][2],nav[1][2],nav[2][2],map[1][2],nav[3][2],nav[4][2],map[2][2],nav[5][2]);
		printf("		+-----------+\n");
		printf("\n");
		printf("\n");
//player making move
		printf("	Player %i move.\n",player);
		printf("\n");
		printf("Player 1 is 'X'\n");
		printf("Player 2 is 'O'\n");
		printf("\n");
		printf("Use the arrow keys to navigate the game board and Enter to confirm your choice.\n");
		printf("Use backspace to reverse one move.\n");
// take user position
		control=_getch();
//movements
		int postest;
		switch(control){
			case 8://reverse(backspase)
				if(movecount>1){
			printf("%i\n",history[0][movecount-1]);
			printf("%i\n",history[1][movecount-1]);
			printf("%i\n",history[2][movecount-1]);
			printf("%i\n",movecount);
			getchar();
					movecount--;
					map[history[0][movecount]][history[1][movecount]]=' ';
					if(history[2][movecount-1]==1){
						mark='X';
					}else{
						if(history[2][movecount-1]==0){
							mark=' ';
						}else{
							mark='O';
						}
						
					}
					map[history[0][movecount-1]][history[1][movecount-1]]=mark;
					if(player == 1){
						player = 2;
					}else{
						player = 1;
					}
				}
			case 72://up
				postest = pos[1];
				postest --;
				if(postest>=0&&postest<=2){
					nav[pos[0]*2][pos[1]]=' ';
					nav[pos[0]*2+1][pos[1]]=' ';
					pos[1]=postest;
					break;
				}
				break;
			case 80://down
				postest = pos[1];
				postest ++;
				if(postest>=0&&postest<=2){
					nav[pos[0]*2][pos[1]]=' ';
					nav[pos[0]*2+1][pos[1]]=' ';
					pos[1]=postest;
					break;
				}
				break;
			case 75://left
				postest = pos[0];
				postest --;
				if(postest>=0&&postest<=2){
					nav[pos[0]*2][pos[1]]=' ';
					nav[pos[0]*2+1][pos[1]]=' ';
					pos[0]=postest;
					break;
				}
				break;
			case 77://right
				postest = pos[0];
				postest ++;
				if(postest>=0&&postest<=2){
					nav[pos[0]*2][pos[1]]=' ';
					nav[pos[0]*2+1][pos[1]]=' ';
					pos[0]=postest;
					break;
				}
				break;
			case 13://enter
				// plase the mark
				if(map[pos[0]][pos[1]]==' '){
					worr[0] = '\0';
					if(player==1){
						mark='X';
					}else{
						mark='O';
					}
//place the mark on the map
					map[pos[0]][pos[1]]=mark;
//saving the move in history
					history[0][movecount]=pos[0];
					history[1][movecount]=pos[1];
					history[2][movecount]=player;
					lastmove=movecount;
					movecount++;
//copy coordinates for victory check
					vicposchek[0]=pos[0];
					vicposchek[1]=pos[1];
//plases the next user on a free spot
					nav[pos[0]*2][pos[1]]=' ';
					nav[pos[0]*2+1][pos[1]]=' ';
					pos[0]=0;
					pos[1]=0;
					while(map[pos[0]][pos[1]]!=' '){
						if(pos[0]<=2){
							pos[0]++;
						}else{
							if(pos[1]<=2){
								pos[0]=0;
								pos[1]++;
							}else{
							Tie();
							}
						}
					}
//change the player
					if(player == 1){
						player = 2;
					}else{
						player = 1;
					}
				}else{
					strcpy(worr,"That spot is taken !!!");
				}				
//chek if the player wins algoritam
				for(int i = 0;i<=2;i++){
					if(map[i][vicposchek[1]] == mark){
						victorycounter++;
					}
					if(victorycounter == 3){
						if(player == 1){
							player = 2;
						}else{
							player = 1;
						}
						Victory(player);
					}	
				}
				victorycounter=0;
				for(int i = 0;i<=2;i++){
					if(map[vicposchek[0]][i] == mark){
						victorycounter++;
				
					}
					if(victorycounter == 3){
						if(player == 1){
							player = 2;
						}else{
							player = 1;
						}
						Victory(player);
					}	
				}
				victorycounter=0;
				for(int i = 0;i<=2;i++){
					if(map[i][i] == mark){
						victorycounter++;
				
					}
					if(victorycounter == 3){
						if(player == 1){
							player = 2;
						}else{
							player = 1;
						}
						Victory(player);
					}	
				}
				victorycounter=0;
				for(int i = 0;i<=2;i++){
					if(map[2-i][i] == mark){
						victorycounter++;
				
					}
					if(victorycounter == 3){
						if(player == 1){
							player = 2;
						}else{
							player = 1;
						}
						Victory(player);
					}	
				}
			victorycounter=0;
		}
	}
	return 1;
}
int Victory(int player){
	int control;
	int choice=1;
	char indicator[4];
	indicator[1]=' ';
	indicator[2]=' ';
	indicator[3]=' ';
	
	
	while(1){
		system("cls");
		indicator[choice]='>';
		printf("\n");
		printf("	BEARPOWERS Tic Tac Toe\n");
		printf("\n");
		printf("	Congratulations\n	Player %i wins the game.\n\n		%c Play again.\n		%c Replay of the game\n		%c Back to the menu\n",player,indicator[1],indicator[2],indicator[3]);
		printf("\n");
				printf("	Navigate the manu with up and down arrow keys \n	 and press Enter to select\n");
		control=_getch();
		switch(control){
				case 72://up
					if(choice>1){
					indicator[choice]=' ';
					choice--;
					}
					break;
				case 80://down
					if(choice<3){
					indicator[choice]=' ';
					choice++;
					}
					break;
				case 13://enter
					if(choice==1){
						Game();
					}
					if(choice==2){
						Replay();
						getchar();
					}
					if(choice==3){
						Manu();
					}
		}
	}
	return 1;
} 

int Tie(int player){
	int control;
	int choice=1;
	char indicator[3];
	indicator[0]=' ';
	indicator[1]=' ';
	indicator[2]=' ';
	
	
	while(1){
		system("cls");
		indicator[choice]='>';
		printf("\n");
		printf("	BEARPOWERS Tic Tac Toe\n");
		printf("\n");
		printf("	No player win, its a tie.\n\n		%c Play again.\n		%c Back to the menu\n",indicator[1],indicator[2]);
		printf("\n");
		printf("	Navigate the manu with up and down arrow keys \n	 and press Enter to select\n");
		control=_getch();
		switch(control){
				case 72://up
					if(choice>1){
					indicator[choice]=' ';
					choice--;
					}
					break;
				case 80://down
					if(choice<2){
					indicator[choice]=' ';
					choice++;
					}
					break;
				case 13://enter
					if(choice==1){
						Game();
					}
					if(choice==2){
						Manu();
					}
		}
	}
	return 1;
} 
int Replay(){
	history[0][0]=0;
	history[1][0]=0;
	history[2][0]=0;
	history[3][0]=0;
	movecount = 0;
	char mark;
	int control;
	
	char map[3][3];
	int ver = 0;
	int hor = 0;
	while(ver<=2){
		while(hor<=2){
			map[ver][hor]=' ';
			hor++;
		}
		hor=0;
		ver++;
	}
	while(1){	
		system("cls");
//print the map
		printf("\n");
		printf("	BEARPOWERS Tic Tac Toe\n");
		printf("\n");
		printf("		Game board\n");
		printf("\n");
		printf("\n");
		printf("		Replay\n");
		printf("\n");
		printf("\n");
		printf("		+-----------+\n");
		printf("		| %c | %c | %c |\n",map[0][0],map[1][0],map[2][0]);
		printf("		|---|---|---|\n");
		printf("		| %c | %c | %c |\n",map[0][1],map[1][1],map[2][1]);
		printf("		|---|---|---|\n");
		printf("		| %c | %c | %c |\n",map[0][2],map[1][2],map[2][2]);
		printf("		+-----------+\n");
		printf("\n");
		printf("\n");
		printf("	Player %i move.\n",history[2][movecount]);
		printf("\n");
		printf("Player 1 is 'X'\n");
		printf("Player 2 is 'O'\n");
		printf("\n");
		printf("Use left and right keys to navigate the recording.\n");
		printf("Press Enter to go back.\n");
		//control
		control=_getch();
		int postest;
		switch(control){
			case 13:
				Victory(history[2][lastmove-2]);
				break;
			case 75://left
				if(movecount>0){
					map[history[0][movecount]][history[1][movecount]]=' ';
					movecount--;
					if(history[2][movecount]==1){
						mark='X';
					}else{
						if(history[2][movecount]==0){
							mark=' ';
						}else{
							mark='O';
						}
					}
					map[history[0][movecount]][history[1][movecount]]=mark;
				}
				break;
			case 77://right
				if(movecount<=lastmove-1){
					movecount++;
					if(history[2][movecount]==1){
						mark='X';
					}else{
						if(history[2][movecount]==0){
							mark=' ';
						}else{
							mark='O';
						}
					}
					map[history[0][movecount]][history[1][movecount]]=mark;
				}
				break;
		}
	}	
}