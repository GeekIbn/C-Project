#include<stdio.h>
#include<stdlib.h>
#include<string.h> 
#include<time.h>
#include<windows.h>
#define LEN sizeof (struct map)

struct players
{
	char name[10];
	int money;
	int location;
	char status;		//P-暂停一回合，G-正常，L-破产； 
}playernum[4];

struct map
{
	char name[20];
	int price;
	int buildings;
	int empty;
	int onehouse;
	int twohouses;
	int threehouses;
	int pledge;
	int build;
	char owner[10];
}real_estate[30];

int bank=300000;

int main()
{
	int num;
	int i;
	
	int process(int players);		//游戏过程处理函数
	
	FILE *fp;
	fp=fopen("estate.dat","rb");
	for(i=0;i<30;i++)
	{
		fread(&real_estate[i],LEN,1,fp);		//读取地图数据 
	}
	fclose(fp);
	
	printf("----------------------------------------\n");
	printf("|                                      |\n");
	printf("|             $ MILLIONAR $            |\n");
	printf("|                                      |\n");
	printf("----------------------------------------\n");
	Sleep(2000);
	printf("\n");
	printf("Map resource ready!\n");
	printf("\n");
	Sleep(1000);
	printf("----------------------------------------\n");
	printf("Enter players number:");
	scanf("%d",&num);
	while(num>4&&num<2)		//检查玩家数量是否符合要求 
	{
		printf("Error! (Players should between TWO and FOUR!)\n");
		scanf("%d",&num);
	}
	for(i=0;i<num;i++)
	{
		printf("Enter %d's name：\n",i+1); 
		scanf("%s",playernum[i].name);
		playernum[i].money=25000;
		playernum[i].status='G';
		playernum[i].location=0;
	}
	printf("----------------------------------------\n");
	Sleep(1000);
	printf("\n");
	printf("Ready! Have a nice trip!\n");
	printf("\n");
	Sleep(1000);
	process(num);
}

int process(int players)
{
	int i=0;
	int p=0;
	int tempn;
	int steps;
	int status_num;
	char pledge[10];
	char status[10];
	char judge;
	
	void moneychange(int i,int players);		//金钱变动函数 
	void buy_or_not(int i);		//地产交易函数 
	int estate_or_tax(int i);		//功能性方块判断函数 
	void tax_chance_destiny(int i);		//地产税、机会、命运函数 
	
	while(i<=players)
	{		
		int count_normal=0;		//正常角色计数变量 
		int count_loss=0;		//失败角色计数变量			
		char winner[10];		//获胜角色名称 
		
		for(p=0;p<players;p++)		//遍历角色 
		{
			if(playernum[p].status=='L')		//计数失败角色数 
			{
				count_loss++;
			}
			else if(playernum[p].status!='L')		//计数正常角色数 
			{
				count_normal++;
				strcpy(winner,playernum[p].name);
			}
		}
		
		if(count_normal==1&&count_loss==(players-1))		//得出获胜者，游戏结束 
		{
			printf("Game Over!\n%s Win!\n",winner);
			exit(0);
		}
		
		if(i==players)		//判断是否进入下一轮 
		{
			i=0;
		}
		
		scanf("%c",&judge);
		while(judge!='\n')		//判断进入下一回合或退出游戏 
		{
			if(judge=='#')
			{
				exit(0);
			}
			else
			{
				printf("Error!\n");
			}
			scanf("%c",&judge);
		} 
			
		printf("\n(%s's) Turn:\n",playernum[i].name);
		if(playernum[i].status=='P'||playernum[i].status=='L')		//判断角色状态 
		{
			if(playernum[i].status=='P')
			{
				playernum[i].status='G';
				printf("Have a rest!\n");
				i++;
				continue;
			}
			else if(playernum[i].status=='L')
			{
				i++;
				continue;
			}
		}
		Sleep(1000);
		printf("------------------------------------------------------------------\n");
		printf("Role status:\n");
		printf("Money: %d | Location: %s |",playernum[i].money,real_estate[playernum[i].location].name); 

		srand((unsigned)time(0));
		steps=rand()%6+1;		//生成1-6的随机数 
		
		while(playernum[i].location+steps>29)		//判断是否走完一圈 
		{
			playernum[i].location=(playernum[i].location+steps-30);
			if(playernum[i].location!=0)		//判断是否经过起点奖励1000 
			{
				playernum[i].money+=1000;		
			}
		}
		
		playernum[i].location+=steps;
		printf(" Move forward (%d) steps |\n",steps);
		printf("------------------------------------------------------------------\n");
		Sleep(1000);
		if(strcmp(real_estate[playernum[i].location].name,"Prison")==0||strcmp(real_estate[playernum[i].location].name,"Parking")==0)
		{
			playernum[i].status='P';
		}
		
		printf("Block imformation:\n");
		
		if(real_estate[playernum[i].location].pledge!=9999)		//判断是否抵押 
		{
			strcpy(pledge,"No");
		}
		else
		{
			strcpy(pledge,"Yes");
		}
		
		if(strcmp(real_estate[playernum[i].location].owner,"Bank")==0)		//判断是否可以购买 
		{
			int temp;		//中间变量用于Switch判断 
			
			temp=estate_or_tax(i); 
			if(temp==1) 
			{
				strcpy(status,"Free");
				status_num=1;
			}
			else if(temp==2)
			{
				strcpy(status,"No estate");
				status_num=2;
			}
			else if(temp==3)
			{
				strcpy(status,"No estate");
				status_num=3;
			}
		}
		else if(strcmp(real_estate[playernum[i].location].owner,"Bank")!=0)
		{
			strcpy(status,"Purchased");
			status_num=0;
		}
		printf("Name: %s | Owner: %s | Pledge: %s | Status: %s |\n",real_estate[playernum[i].location].name,real_estate[playernum[i].location].owner,pledge,status);
		printf("Buildings:%d |\n",real_estate[playernum[i].location].buildings);
		printf("------------------------------------------------------------------\n");
		Sleep(1000);
		switch (status_num)
		{
			case 0:
				moneychange(i,players);
				break;
			
			case 1:
				buy_or_not(i);
				break;
				
			case 2:
				tax_chance_destiny(i);
				break;
			
			case 3:
				break;
		}
		
		int count=0;
		for(tempn=0;tempn<30;tempn++)
		{
						
			if(strcmp(real_estate[tempn].owner,playernum[i].name)==0)
			{
				count++;
			}
		}
		printf("------------------------------------------------------------------\n");
		printf("Money(After): %d | Estate: %d | \n",playernum[i].money,count);
		printf("------------------------------------------------------------------\n");
		Sleep(1000);
		i++;
	}	
}

void moneychange(int i,int players)
{
	int n=0;
	
	if(strcmp(real_estate[playernum[i].location].owner,playernum[i].name)!=0)		//判断地产拥有者 
	{
		if(strcmp(real_estate[playernum[i].location].name,"Electric-Cor")==0||strcmp(real_estate[playernum[i].location].name,"Water-Works")==0)
		{
			playernum[i].money-=300;
			for(n=0;n<players;n++)		//判断地产所有者，并增加其收益 
			{
				if(strcmp(playernum[n].name,real_estate[playernum[i].location].owner)==0)
				{
					playernum[n].money+=300;
					printf("Affair: You lose %d for passing by %s's estate\n",300,real_estate[playernum[n].location].owner);
				}
			}
		}
		else
		{
		switch (real_estate[playernum[i].location].buildings)		//判断过路费金额 
		{
			case 0:
			if(playernum[i].money<real_estate[playernum[i].location].empty)
			{
				playernum[i].status='L';
				printf("Affair: You Loss!\n");
			}
			else
			{
				playernum[i].money-=real_estate[playernum[i].location].empty;
				for(n=0;n<players;n++)		//判断地产所有者，并增加其收益 
				{
				if(strcmp(playernum[n].name,real_estate[playernum[i].location].owner)==0)
				{
					playernum[n].money+=real_estate[playernum[i].location].empty;
				}
				}
				printf("Affair: You lose %d for passing by %s's estate\n",real_estate[playernum[i].location].empty,real_estate[playernum[i].location].owner);
			}
			break;
			
			case 1:
			if(playernum[i].money<real_estate[playernum[i].location].onehouse)
			{
				playernum[i].status='L';
				printf("Affair: You Loss!\n");
			}
			else
			{
				playernum[i].money-=real_estate[playernum[i].location].onehouse;
				for(n=0;n<players;n++)		//判断地产所有者，并增加其收益 
				{
				if(strcmp(playernum[n].name,real_estate[playernum[i].location].owner)==0)
				{
					playernum[n].money+=real_estate[playernum[i].location].onehouse;
				}
				}			
				printf("Affair: You lose %d for passing by %s's estate\n",real_estate[playernum[i].location].onehouse,real_estate[playernum[i].location].owner);
			}
			break;

			case 2:
			if(playernum[i].money<real_estate[playernum[i].location].twohouses)
			{
				playernum[i].status='L';
				printf("Affair: You Loss!\n");
			}
			else
			{
				playernum[i].money-=real_estate[playernum[i].location].twohouses;
				for(n=0;n<players;n++)		//判断地产所有者，并增加其收益 
				{
				if(strcmp(playernum[n].name,real_estate[playernum[i].location].owner)==0)
				{
					playernum[n].money+=real_estate[playernum[i].location].twohouses;
				}
				}			
				printf("Affair: You lose %d for passing by %s's estate\n",real_estate[playernum[i].location].twohouses,real_estate[playernum[i].location].owner);
			}		
			break;

			case 3:
			if(playernum[i].money<real_estate[playernum[i].location].threehouses)
			{
				playernum[i].status='L';
				printf("Affair: You Loss!\n");
			}
			else
			{
				playernum[i].money-=real_estate[playernum[i].location].threehouses;
				for(n=0;n<players;n++)		//判断地产所有者，并增加其收益 
				{
				if(strcmp(playernum[n].name,real_estate[playernum[i].location].owner)==0)
				{
					playernum[n].money+=real_estate[playernum[i].location].threehouses;
				}
				}			
				printf("Affair: You lose %d for passing by %s's estate\n",real_estate[playernum[i].location].threehouses,real_estate[playernum[i].location].owner);
			}			
			break;
		}	
		}
	}
	else
	{
		printf("Affair: This location is your estate, Welcome!\n");
		if(real_estate[playernum[i].location].buildings<3&&playernum[i].money>real_estate[playernum[i].location].build)
		{		//判断是否可以增加建筑，角色金钱是否足够
			if(strcmp(real_estate[playernum[i].location].name,"Electric-Cor")==0||strcmp(real_estate[playernum[i].location].name,"Water-Works")==0||strcmp(real_estate[playernum[i].location].name,"Hawaii-Airport")==0||strcmp(real_estate[playernum[i].location].name,"London-Airport")==0)			
			{
				printf("Affair: Can't construct here!\n");
			}
			else
			{
				printf("Affair: You have %d builing in these area, construct it?\n1.Do it.\n2.Don't do it.\n",real_estate[playernum[i].location].buildings);
				int judge;
				scanf("%d",&judge);
			
				switch (judge)		//选择建筑物处理方式 
				{
					case 1:
						playernum[i].money-=real_estate[playernum[i].location].build;
						real_estate[playernum[i].location].buildings++;
						bank+=real_estate[playernum[i].location].build;
						break;
					case 2:
						break;
				}				
			}
		}
		else
		printf("Affair: You don't have enough money to construct!\n");
	}
}

void buy_or_not(int i)
{
	if(playernum[i].money<real_estate[playernum[i].location].price)
	{
		printf("Affair: You don't have enough money to buy this estate!\n");
	}
	else
	{
		int choice;
		
		printf("Affair: Purchase this real estate or not?\n\t1.Purchase\n\t2.Don't purchase\n");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1:
				playernum[i].money-=real_estate[playernum[i].location].price;
				bank+=real_estate[playernum[i].location].price;
				strcpy(real_estate[playernum[i].location].owner,playernum[i].name);
				break;
				
			case 2:
				break;
		}
	}
}

int estate_or_tax(int i)
{
	if(strcmp(real_estate[playernum[i].location].name,"Prison-Passby")==0)
	return 3;
	else if(strcmp(real_estate[playernum[i].location].name,"Prison")==0)
	return 3;
	else if(strcmp(real_estate[playernum[i].location].name,"Parking")==0)
	return 3;
	else if(strcmp(real_estate[playernum[i].location].name,"Tax")==0)
	return 2;
	else if(strcmp(real_estate[playernum[i].location].name,"Chance")==0)
	return 2;
	else if(strcmp(real_estate[playernum[i].location].name,"Destiny")==0)
	return 2;
	else if(strcmp(real_estate[playernum[i].location].name,"Start")==0)
	return 3;
	else 
	return 1;
}

void tax_chance_destiny(int i)
{
	if(strcmp(real_estate[playernum[i].location].name,"Tax")==0)
	{
		if(playernum[i].money<real_estate[playernum[i].location].price)
		{
			playernum[i].status='L';
			printf("Affair: You Loss!\n");
		}
		else
		{
			playernum[i].money-=real_estate[playernum[i].location].price;
			bank+=real_estate[playernum[i].location].price;	
			printf("Affair: You lose %d for tax\n",real_estate[playernum[i].location].price);		
		}
	}
	else if(strcmp(real_estate[playernum[i].location].name,"Destiny")==0)
	{
		int temp;		//创建临时变量作为随机数载体抽取卡片 
		
		srand((unsigned)time(0));
		temp=rand()%10+1;
		if((temp>=1&&temp<=6)&&playernum[i].money<500)		//判断角色金钱是否足够 
		{
			playernum[i].status='L';
			printf("Affair: You Loss!\n");
		}
		else if((temp>=7&&temp<=8)&&playernum[i].money<600)
		{
			playernum[i].status='L';
			printf("Affair: You Loss!\n");
		}
		else if(temp==9&&playernum[i].money<800)
		{
			playernum[i].status='L';
			printf("Affair: You Loss!\n");
		}
		else if(temp==10&&playernum[i].money<1000)
		{
			playernum[i].status='L';
			printf("Affair: You Loss!\n");
		}
		else		//根据情景对角色进行操作 
		{
			switch(temp)
			{
			case 1:
				printf("Affair: Drinking cause trouble fine 500 and been detained\n");
				playernum[i].money-=500;
				playernum[i].status='P';
				bank+=500;
				break;
			
			case 2:
				printf("Affair: Attackede by terrorist lose 500\n");
				playernum[i].money-=500;
				bank+=500;
				break;
			
			case 3:
				printf("Affair: Donate to refugees 500\n");
				playernum[i].money-=500;
				bank+=500;
				break;

			case 4:
				printf("Affair: Play in Disneyland cost 500\n");
				playernum[i].money-=500;
				bank+=500;
				break;	
				
			case 5:
				printf("Affair: Spitted illegaly fined 500\n");
				playernum[i].money-=500;
				bank+=500;
				break;	
				
			case 6:
				printf("Affair: Pay 500 for a big meal\n");
				playernum[i].money-=500;
				bank+=500;
				break;
								
			case 7:
				printf("Affair: Travel to Taiwan Ali mountain cost 600\n");
				playernum[i].money-=600;
				bank+=600;	
				break;			
		
			case 8:
				printf("Affair: Exploration in Sahara desert pay 600 for guide\n");
				playernum[i].money-=600;
				bank+=600;
				break;
			
			case 9:
				printf("Affair: Travel to Egypt cost 800\n");
				playernum[i].money-=800;
				bank+=800;
				break;
				
			case 10:
				printf("Affair: Been robbed lost 1000\n");
				playernum[i].money-=1000;
				bank+=1000;
				break;																						
			}
		}
	}
	else if(strcmp(real_estate[playernum[i].location].name,"Chance")==0)
	{
		int temp;		//创建临时变量作为随机数载体抽取卡片 
		
		srand((unsigned)time(0));		
		temp=rand()%10+1;
		switch(temp)
		{
			case 1:
				printf("Affair: Win Nobel Price 700\n");
				playernum[i].money+=700;
				bank-=700;
				break;
			
			case 2:
				printf("Affair: Go to start block and award 1000\n");
				playernum[i].money+=1000;
				bank-=1000;
				playernum[i].location=0;
				break;
			
			case 3:
				printf("Affair: Become Olympics champion award 800\n");
				playernum[i].money+=800;
				bank-=800;
				break;

			case 4:
				printf("Affair: Strike crime award 800\n");
				playernum[i].money+=800;
				bank-=800;
				break;	
				
			case 5:
				printf("Affair: Direct a Hollywood movie and win a price award 800\n");
				playernum[i].money+=800;
				bank-=800;
				break;	
				
			case 6:
				printf("Affair: Interest income 500 form bank\n");
				playernum[i].money+=500;
				bank-=500;
				break;
								
			case 7:
				printf("Affair: Draw a lottery win 1000\n");
				playernum[i].money+=1000;
				bank-=600;
				break;				
		
			case 8:
				printf("Affair: Explorate historical sites get 700\n");
				playernum[i].money+=700;
				bank-=600;
				break;
			
			case 9:
				printf("Affair: Gambling win 500\n");
				playernum[i].money+=500;
				bank-=500;
				break;
				
			case 10:
				printf("Affair: Stock award 800\n");
				playernum[i].money+=800;
				bank-=800;
				break;																						
		}	
	}
}
