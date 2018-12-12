#include <stdio.h>

#include <conio.h>

#include <stdlib.h>

#include <time.h>

#include <windows.h>

#include <unistd.h>

#include <ctype.h>

const int N = 10;      // amount of lines and columns
const int amount = 10; // amount of bomb

int Zero(int array[N][N], int Main[N][N], int i, int j)
{
	if ((i > 0) 
		 && (j > 0) 
		 && (i < N-1) 
		 && (j < N-1))
	{
		if (Main[i-1][j-1]==0) array[i-1][j-1]=100;
		if (Main[i-1][j]==0) array[i-1][j]=100;
		if (Main[i-1][j+1]==0) array[i-1][j+1]=100;
		if (Main[i][j-1]==0) array[i][j-1]=100;
		if (Main[i][j+1]==0) array[i][j+1]=100;
		if (Main[i+1][j-1]==0) array[i+1][j-1]=100;
		if (Main[i+1][j]==0) array[i+1][j]=100;
		if (Main[i+1][j+1]==0) array[i+1][j+1]=100;
	}
				
	if ((i == 0) && (j > 0) && (j < N-1))
	{
		if (Main[i][j-1]==0) array[i][j-1]=100;
		if (Main[i][j+1]==0) array[i][j+1]=100;
		if (Main[i+1][j-1]==0) array[i+1][j-1]=100;
		if (Main[i+1][j]==0) array[i+1][j]=100;
		if (Main[i+1][j+1]==0) array[i+1][j+1]=100;
	}
				
	if ((i == N-1) && (j > 0) && (j < N-1))
	{
		if (Main[i-1][j-1]==0) array[i-1][j-1]=100;
		if (Main[i-1][j]==0) array[i-1][j]=100;
		if (Main[i-1][j+1]==0) array[i-1][j+1]=100;
		if (Main[i][j-1]==0) array[i][j-1]=100;
		if (Main[i][j+1]==0) array[i][j+1]=100;
	}
				
	if ((j == 0) && (i > 0) && (i < N-1))
	{
		if (Main[i-1][j]==0) array[i-1][j]=100;
		if (Main[i-1][j+1]==0) array[i-1][j+1]=100;
		if (Main[i][j+1]==0) array[i][j+1]=100;
		if (Main[i+1][j]==0) array[i+1][j]=100;
		if (Main[i+1][j+1]==0) array[i+1][j+1]=100;
	}
				
	if ((j == N-1) && (i > 0) && (i < N-1))
	{
		if (Main[i-1][j-1]==0) array[i-1][j-1]=100;
		if (Main[i-1][j]==0) array[i-1][j]=100;
		if (Main[i][j-1]==0) array[i][j-1]=100;
		if (Main[i+1][j-1]==0) array[i+1][j-1]=100;
		if (Main[i+1][j]==0) array[i+1][j]=100;
	}
				
	if ((i == 0) && (j == 0))
	{
		if (Main[i][j+1]==0) array[i][j+1]=100;
		if (Main[i+1][j+1]==0) array[i][j+1]=100;
		if (Main[i+1][j]==0) array[i+1][j]=100;
	}
				
	if ((i == 0) && (j == N-1))
	{
		if (Main[i][j-1]==0) array[i][j-1]=100;
		if (Main[i+1][j-1]==0) array[i+1][j-1]=100;
		if (Main[i+1][j]==0) array[i+1][j]=100;
	}
				
	if ((i == N-1) && (j == 0))
	{
		if (Main[i-1][j]==0) array[i-1][j]=100;
		if (Main[i-1][j+1]==0) array[i-1][j+1]=100;
		if (Main[i][j+1]==0) array[i][j+1]=100;
	}
			
	if ((i == N-1) && (j == N-1))
	{
		if (Main[i-1][j]==0) array[i-1][j]=100;
		if (Main[i-1][j-1]==0) array[i-1][j-1]=100;
		if (Main[i][j-1]==0) array[i][j-1]=100;
	}
	
	return array[N][N];
}

int Initialisation(int array[N][N])
{
	for(int i=0; i<N; i++)
    {
    	for(int j=0;j<N;j++)
    	{
    		array[i][j]=0;
		}
	}
	return array[N][N];
}

void Lighting(int array[N][N], int Main[N][N], int i, int j)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);            //Getting descriptor
	system("cls");
	int k,l;
	
	printf("%c", 201);      
 	for (int p = 0; p < N-1; p++)                 //PRINT TO N-1 ARRAYS
   		printf("%c%c%c%c", 205,205,205,209);
 	printf("%c%c%c%c\n",205,205, 205, 187);
 
  	for (int k=0; k<N-1; k++)
  	{
   		printf("%c", 186);
     	for (int l=0; l<N; l++)
     	{
     		if( (k==i) && (l==j) )
			  SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 0));
			else
			{
     			switch(array[k][l])
			   	{
			    	case 0:
						SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15)); break;
				        
				    case 9: 
				   	SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 4)); break;
				
				    case 100:  switch(Main[k][l])
					        	{
				    	            case 0 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));break; 
	  			   		            case 1 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 3)); break;  //
	  		   			            case 2 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2)); break;  //
	  			                    case 3 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 13));break;  //
	  			                    case 4 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 1)); break;  //
	  			                    case 5 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 8)); break;  // colors of amount mines
	  			                    case 6 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 11));break;  //
	  			  	                case 7 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 6)); break;  //
		  		                    case 8 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 12));break;  //
       		                        default:SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15)); break;
						        } break;
				
                }
       		}
    
      		if (l == N-1) // HERE IT IS, PRINT
  	   		{
        	 	SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
			       switch(array[k][l])
			       {
				        case 0: 
				        printf(" %c ", 178); break;
				        
				        case 9: printf(" %c ", 178); break;
				
				        case 100:  switch(Main[k][l])
				                   {
				                        case 0:printf(" %c ", 48);break; 
	  			        	            case 1:printf(" %c ", 49);break;  //
	  		        		            case 2:printf(" %c ", 50);break;  //
	  				                    case 3:printf(" %c ", 51);break;  //
	  				                    case 4:printf(" %c ", 52);break;  //
	  				                    case 5:printf(" %c ", 53);break;  // colors of amount mines
	  				                    case 6:printf(" %c ", 54);break;  //
	  				                    case 7:printf(" %c ", 55);break;  //
	  				                    case 8:printf(" %c ", 56);break;  //
                                        default: printf(" %c ", 178); break;
					               } break;
                    }
        		SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
        		printf("%c\n", 186);
    		} 
       		else
        	{
        		switch(array[k][l])
			       {
				        case 0: 
				        printf(" %c ", 178); break;
				        
				        case 9: printf(" %c ", 178); break;
				
				        case 100:  switch(Main[k][l])
				                   {
				                        case 0:printf(" %c ", 48);break; 
	  			        	            case 1:printf(" %c ", 49);break;  //
	  		        		            case 2:printf(" %c ", 50);break;  //
	  				                    case 3:printf(" %c ", 51);break;  //
	  				                    case 4:printf(" %c ", 52);break;  //
	  				                    case 5:printf(" %c ", 53);break;  // colors of amount mines
	  				                    case 6:printf(" %c ", 54);break;  //
	  				                    case 7:printf(" %c ", 55);break;  //
	  				                    case 8:printf(" %c ", 56);break;  //
                                        default: printf(" %c ", 178); break;
					               } break;
                    } 
    			
    			SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
        		printf("%c", 179);
    		}
    	}
   		  
   		
		printf("%c", 199);
    	for (int l = 0; l < N; l++)
    	{
      		if (l == N-1)
       			printf("%c%c%c%c\n",196,196,196,182);
      		else
       			printf("%c%c%c%c",196,196,196,197);
		}	
	} // PRINT THE LAST STRING
	printf("%c", 186);
     		for (int l=0; l<N; l++)
     		{
     			if( (N-1==i) && (l==j) )
			    	SetConsoleTextAttribute(hConsole, (WORD) ((14 << 4) | 0));
				else
				{
     				switch(array[N-1][l])
			   		{
			    		case 0:
							SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15)); break;
				        
				    	case 9: 
				   			SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 4)); break;
				
				    		case 100:  switch(Main[N-1][l])
					       	{
				    	        case 0 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));break; 
	  		   		            case 1 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 3)); break;  //
	  	   			            case 2 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 2)); break;  //
	  		                    case 3 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 13));break;  //
	  		                    case 4 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 1)); break;  //
	  		                    case 5 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 8)); break;  // colors of amount mines
	  		                    case 6 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 11));break;  //
	  		  	                case 7 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 6)); break;  //
		  	                    case 8 :SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 12));break;  //
       	                        default:SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15)); break;
						    } break;
					}
       			}
    
      			if (l == N-1)
  	   			{
        	 		switch(array[N-1][l])
					{
						case 0: 
					    printf(" %c ", 178); break;
					        
						case 9: 
						printf(" %c ", 178); break;
				
						case 100:  printf(" %d ", Main[N-1][l]); break;
         	  	  	}
        			SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
        			printf("%c\n", 186);
    			} 
       			else
        		{
        			switch(array[N-1][l])
					{
				  	  case 0: 
						    printf(" %c ", 178); break;
				        
				  	 	case 9: 
						    printf(" %c ", 178); break;
					
				 	   case 100:  printf(" %d ", Main[N-1][l]); break;
    				} 
    			
    				SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
        			printf("%c", 179);
    			}
 			}
		
    	
 
 
 	printf("%c", 200);
 	for (int p = 0; p < N-1; p++)
   		printf("%c%c%c%c",205,205,205,207);
 	printf("%c%c%c%c\n",205,205, 205, 188);
}

int Arrow(int array[N][N], int Main[N][N])
{
	int input;
	int i=0, j=0;
	bool end=false;
	while(end==false)
	{
		input=getch();
		switch(input)
		{
			case 87:  --i; if (i<0) i=N; Lighting(array, Main, i, j); break;                                                         //UP
			case 65:  --j; if (j<0) j=N; Lighting(array, Main, i, j); break;                                                         //LEFT
			case 68:  ++j; if (j>N) j=0; Lighting(array, Main, i, j); break;                                                         //RIGHT
			case 83:  ++i; if (i>N) i=0; Lighting(array, Main, i, j); break;                                                         //DOWN 
			case 119: --i; if (i<0) i=N; Lighting(array, Main, i, j); break;                                                         //UP
			case 97:  --j; if (i<0) i=N; Lighting(array, Main, i, j); break;                                                         //LEFT
			case 100: ++j; if (j>N) j=0;  Lighting(array, Main, i, j);break;                                                         //RIGHT
			case 115: ++i; if (i>N) i=0; Lighting(array, Main, i, j); break;                                                         //DOWN
			case 13: array[i][j]=100; if (Main[i][j]==0) Zero(array, Main, i, j); end=true; break;                                   //ENTER
			case 9: array[i][j]=9; end=true; break;                                                                                  //TAB
			default: printf("Please, use 'w','a','s','d' for moving\n"); break;
		}
	}	
	return array[N][N];
}

int Boom(int Matrix[N][N], int kolicestvo)
{
	int k = 0;
	int i = 0;
	int j = 0;
	
	srand(time (NULL));
	while (k < kolicestvo)            //initialization of amount bombs
    {
		i = rand() % N;
		j = rand() % N;
		
		if (Matrix[i][j] != 10)
		{   
        Matrix[i][j] = 10;
        k++;
        }
	}
	return Matrix[N][N];
}

int BombAmount(int Matrix[N][N])
{
	
	for (int i=0; i<N; i++)
	{
		for (int j=0; j<N; j++)
		{
			if (Matrix[i][j] >= 10)
			{
				if ((i > 0) 
				 && (j > 0) 
				 && (i < N-1) 
				 && (j < N-1))
				{
					Matrix[i-1][j-1]++;
   					Matrix[i-1][j]++;
    				Matrix[i-1][j+1]++;
    				Matrix[i][j-1]++;
    				Matrix[i][j+1]++;
    				Matrix[i+1][j-1]++;
    				Matrix[i+1][j]++;
    				Matrix[i+1][j+1]++;
				}
				
				if ((i == 0) && (j > 0) && (j < N-1))
				{
					Matrix[i][j-1]++;
					Matrix[i][j+1]++;
					Matrix[i+1][j-1]++;
					Matrix[i+1][j]++;
					Matrix[i+1][j+1]++;
				}
				
				if ((i == N-1) && (j > 0) && (j < N-1))
				{
					Matrix[i-1][j-1]++;
   				 	Matrix[i-1][j]++;
    				Matrix[i-1][j+1]++;
    				Matrix[i][j-1]++;
    				Matrix[i][j+1]++;
				}
				
				if ((j == 0) && (i > 0) && (i < N-1))
				{
					Matrix[i-1][j]++;
					Matrix[i-1][j+1]++;
					Matrix[i][j+1]++;
					Matrix[i+1][j]++;
					Matrix[i+1][j+1]++;
				}
				
				if ((j == N-1) && (i > 0) && (i < N-1))
				{
					Matrix[i-1][j]++;
					Matrix[i-1][j-1]++;
					Matrix[i][j-1]++;
					Matrix[i+1][j-1]++;
					Matrix[i+1][j]++;
				}
				
				if ((i == 0) && (j == 0))
				{
					Matrix[i][j+1]++;
					Matrix[i+1][j+1]++;
					Matrix[i+1][j]++;
				}
				
				if ((i == 0) && (j == N-1))
				{
					Matrix[i][j-1]++;
					Matrix[i+1][j-1]++;
					Matrix[i+1][j]++;
				}
				
				if ((i == N-1) && (j == 0))
				{
					Matrix[i-1][j]++;
					Matrix[i-1][j+1]++;
					Matrix[i][j+1]++;
				}
				
				if ((i == N-1) && (j == N-1))
				{
					Matrix[i-1][j]++;
					Matrix[i-1][j-1]++;
					Matrix[i][j-1]++;
				}
				
			}
		}
	}
	return Matrix[N][N];
}

int BombHider(int Main[N][N], int i, int j)
{
 if ((i < N) && (j < N) && (i>=0) && (j>=0))      
  {
   if (Main[i][j] >= 10)
   { 
    Main[i-1][j-1]--;
    Main[i-1][j]--;
    Main[i-1][j+1]--;
    Main[i][j-1]--;
    Main[i][j+1]--;
    Main[i+1][j-1]--;
    Main[i+1][j]--;
    Main[i+1][j+1]--;
    Main[i][j] -= 10;
   
    bool change = false;
    srand(time (NULL));
    while (change != true)            
    {
    i = rand() % N;
    j = rand() % N;

    if (Main[i][j] < 10)
        {   
           Main[i][j] += 10;
           change = true;
        }
    }
    Main[i-1][j-1]++;
    Main[i-1][j]++;
    Main[i-1][j+1]++;
    Main[i][j-1]++;
    Main[i][j+1]++;
    Main[i+1][j-1]++;
    Main[i+1][j]++;
    Main[i+1][j+1]++;
   }
  } return Main[N][N];
}

void Rules()
{
	system("cls");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); /*Getting out of descriptor*/
	system("color 3");
	printf("Quick Start:\n\n\n\n\n");
	printf("*\t    You are presented with a board of squares. Some squares contain mines (bombs), others don't.  \n");
	printf("\t     If you click on a square containing a bomb, you'll lose.\n");
	printf("\t     If you manage to click all the squares (without clicking on any bombs) you'll win.\n");
	printf("*\t   Clicking a square which doesn't have a bomb reveals the number of neighbouring squares containing bombs.\n");
	printf("\t     Use this information plus some guess work to avoid the bombs.\n");
	printf("*\t   Choose the square and press 'ENTER' to open the cell.\n");
	printf("\t     To mark a square you think is a bomb, point and click 'TAB' on your keyboard.\n");
	printf("\t     Use 'w','a','s','d' for navigation.\n");
	printf("\t     Press 'TAB'  to create a flag.\n");
	printf("\t     Use UP and DOWN for menu navigation.\n");
	getch();

	SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
}
  
void Welcome()
{
        HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); /*Getting out of descriptor*/
	    system("color 3");	
        printf("$$___$_$$$$$$_$$__$$_$$$$$___$$$$__$$___$_$$$$$__$$$$$__$$$$$__$$$$$__$$$$$\n");
        printf("$$$_$$___$$___$$$_$$_$$_____$$_____$$___$_$$_____$$_____$$__$$_$$_____$$__$$\n");
	    printf("$$_$_$___$$___$$_$$$_$$$$____$$$$__$$_$_$_$$$$___$$$$___$$$$$__$$$$___$$$$$\n");
        printf("$$___$___$$___$$__$$_$$_________$$_$$$$$$_$$_____$$_____$$_____$$_____$$__$$\n");
        printf("$$___$_$$$$$$_$$__$$_$$$$$___$$$$___$$_$$_$$$$$__$$$$$__$$_____$$$$$__$$__$$\n\n");
        
        SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
}

void Menu(int iItem)
{
    system("cls");
	printf("\nMENU: \n\n\n");
    printf("\t%s1 - Start game\n",iItem == 1 ? ">" : " ");
    printf("\t%s2 - Rules\n",iItem == 2 ? ">" : " ");
    printf("\t%s3 - EXIT\n",iItem == 3 ? ">" : " ");
    
    //SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));
}

void Board (int Main[N][N])
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if (Main[i][j]>=10) 
			{
				SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 4)); printf("  X");
			}
			else
			{
				SetConsoleTextAttribute(hConsole, (WORD) ((0 << 4) | 15));	printf("%3d", Main[i][j]);
			}
		}
		printf("\n");
	}
}

void StrelkaMenu()
{
    int Main[N][N];    //The main matrix which stored all bobms and vallue of all elements
    int array[N][N];   //Matrix which the user will play with
    int iItem = 1;
    int nLast = 3;
    int i, j;
    int highscore, score=0;
    int exit2=0;
    char answer;
    BOOL bRUN = TRUE;
    bool newgame=true;
	bool game;
    Menu(iItem);
    while(bRUN)
    {   
        if(GetAsyncKeyState(VK_UP))
        if(GetAsyncKeyState(VK_UP))
		{
            if(0 < iItem - 1)
                iItem = iItem - 1;
            else
                iItem = nLast;
            Menu(iItem);
        }
        if(GetAsyncKeyState(VK_DOWN))
        if(GetAsyncKeyState(VK_DOWN))
		{
            if(iItem < nLast)
                iItem = iItem + 1;
            else
                iItem = 1;
            Menu(iItem);
        }
        if(GetAsyncKeyState(VK_RETURN))
        if(GetAsyncKeyState(VK_RETURN))
		{
            Menu(iItem);
            switch(iItem)
            {
            case 1: highscore=(N*N)-amount;
					while(newgame==true)
                    {		
						game=true;
						system("cls");
						getch();
	    				printf("Please, use 'w','a','s','d' for moving\n");
						Initialisation(Main);
    					Boom(Main, amount);
    					BombAmount(Main);
						Initialisation(array);
						i=j=0;
						Arrow(array, Main);
						for(i=0;i<N;i++)
							{
								for( j=0;j<N;j++)
									{
										if ( (array[i][j]==100) && (Main[i][j]>=10) ) BombHider(Main, i, j);
									}
							}
						score++;			
        	            while(game==true)
            	        {
							i=j=0;
							Lighting(array, Main, i ,j);  
							Arrow(array, Main);
							for(i=0;i<N;i++)
							{
								for( j=0;j<N;j++)
								{		
									if ( (array[i][j]==100) && (Main[i][j]>=10) )
            	        			{               	    		
										printf("\n\nYOU HIT A BOMB, better luck next time\n\n\n");
										Board(Main);
                  						printf("\nWanna play again? y/n \n");
                    					scanf("%c", &answer);
             	       					if ((answer=='y') || (answer=='Y')) newgame=true;
             	       					else newgame=false; 
										game=false;	 
                   					}
                   					else score++;
								}
							}
							if (score==highscore) 
							{
								printf("! ! ! CONGRATULATIONS ! ! !\n\n");
								game=false; newgame=false;
							}
                        }
					}
				printf("See you soon)0))\n\n");	
				break;
            case 2:
                    system("cls"); Rules();
                break;
            case 3: 
                    printf("\n\nSEE YOU SOON\n");
                    exit(0);
			    break;    
            }
        }
        if(GetAsyncKeyState(VK_RETURN))
            bRUN = FALSE;
        Sleep(100);
    }   
   	getch();
}

int main()
{
	Welcome();
	printf("\n\n\n\n\n\n\n\n\n\n\n\nDON'T    TOUCH    ENTER\n\n");
	printf("!   P L E A S E   !\n\n");
	getch();
	StrelkaMenu();
	return 0;
}
