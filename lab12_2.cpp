#include<iostream>
#include<string>
#include<ctime>

using namespace std;

string cardNames[] = {"","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
int cardScores[] = {0,1,2,3,4,5,6,7,8,9,10,10,10,10};

int drawCard(void){
	int card =rand()%13+1;
	return card ;
}

int calScore(int x,int y,int z){
	if(x>10) x=10;
	else if(y>10) y=10;
	else if(z>10) z=10;
	int sum =(x+y+z)%10;
	return sum;
}
	

int findYugiAction(int s){	
	if(s == 9) return 2; 
	else if(s < 6) return 1;
	else{
		int prob =rand()%100+1;
		if(0<prob&&prob<70){
			return 1;
		}else return 2;
	}
}

void checkWinner(int p, int y){
	cout << "\n---------------------------------\n";
	if (p==y) cout <<   "|             Draw!!!           |"; 
	else if (p>y) cout <<   "|         Player wins!!!        |";
	else cout <<   "|          Yugi wins!!!         |";
	cout << "\n---------------------------------\n";
}

int main(){	
	srand(time(0));
	int playerScore, yugiScore, playerAction, yugiAction;
	int playerCards[3] = {drawCard(), drawCard(), 0};
	int yugiCards[3] = {drawCard(), drawCard(), 0};

	
	
	cout << "---------ORE NO TURN, DRAW!!!------------\n";
	cout << "Your cards: " << cardNames[playerCards[0]] << " " << cardNames[playerCards[1]] << "\n";
	playerScore = calScore(playerCards[0],playerCards[1],0);
	cout << "Your score: " << playerScore << "\n";
	do{
		cout << "(1) Destiny draw (2) Stay, SELECT: ";
		cin >> playerAction;
	}while(playerAction!=1&&playerAction!=2); 
	if(playerAction == 1){
		int card3 = drawCard();
		cout << "Player draws the 3rd card!!!" << "\n";
		playerCards[2]=card3;
		cout << "Your 3rd card: " << cardNames[playerCards[2]]<< "\n";
		playerScore = calScore(playerCards[0],playerCards[1],playerCards[2]);
		cout << "Your new score: " << playerScore << "\n";
		
	}
	cout << "------------ Turn end -------------------\n\n";
	
	

	cout << "---------YUGI'S TURN, DRAW!!!------------\n";
	cout << "Yugi's cards: " << cardNames[yugiCards[0]] << " " << cardNames[yugiCards[1]]<< "\n";
	yugiScore = calScore(yugiCards[0],yugiCards[1],0);
	cout << "Yugi's score: " << yugiScore << "\n";
	yugiAction = findYugiAction(yugiScore);
	if(yugiAction == 1){
		int card3 = drawCard();
		cout << "Yugi draws the 3rd card!!!\n";
		yugiCards[2]=card3;
		cout << "Yugi's 3rd card: " << cardNames[yugiCards[2]]<< "\n";
		yugiScore = calScore(yugiCards[0],yugiCards[1],yugiCards[2]);
		cout << "Yugi's new score: "<<yugiScore << "\n";
	}
	cout << "------------ Turn end -------------------\n";
	
	
	checkWinner(playerScore,yugiScore);
}
