//RANKIFY
//berdoa sebelum memulai:'

#include<stdio.h>
#include<string.h>

//struct
struct Player{
	char id[50];
	float point;
	bool isActive;
};

//global
Player players[100];
int TOT_PLAYER=0;

//prototypes
void showChoices();
void menu();
void addPlayer(Player s);
void ranks();

//main
int main() {
    menu();
    return 0;
}

void showChoices() {
    puts("Main Menu");
    puts("1. Add Player");
    puts("2. Show Ranking");
    puts("3. Exit");
    puts(">>");
}

//loop menu
void menu(){
	bool onApp=true;
	
	while(onApp){
		
		showChoices();
		int choice=-1;
		scanf("%d", &choice); getchar();
		
        
		if(choice==1){
			Player newPlayer;
			printf("id: ");
			scanf("%[^\n]", &newPlayer.id);
			printf("point: ");
			scanf("%lf", &newPlayer.point);
			addPlayer(newPlayer);
		}else if(choice==2){
			ranks();
		}else if(choice==3){
			printf("Adios! Happy Playing!");
			onApp=false;
		}
	}
}

//add player
void addPlayer(Player s){
	strcpy(players[TOT_PLAYER].id,s.id);
	players[TOT_PLAYER].point=s.point;
	players[TOT_PLAYER].isActive = true;
	TOT_PLAYER++;
} 

//display rankings
void ranks(){
	int point[10000000000];
	int TOT_PLAYER;
	int temp,i,j,k;
	for(j=0;j<TOT_PLAYER;j++){
		for(k=j+1;k<TOT_PLAYER;k++){
			if(point[j]>point[k]){
				temp=point[i];
				point[i]=point[k];
				point[k]=temp;
			}
		}
	}
	printf("Players Ranking: \n");
	for(i=0; i<TOT_PLAYER; i++){
		printf("%s %lf\n", players[i].id, players[i].point);
	}
}
