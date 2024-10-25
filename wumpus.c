#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    system("color f0");
    int i,j,linhas,colunas,poco=0,soma,x,y,wumpus,ouro,a,b,G,K; //Dois contadores e variaveis para receber numero de linhas e colunas
    printf("\t\t\t\tBEM VINDO AO MUNDO WUMPUS!!!\n");
    printf("\t\tLEGENDA: 1 = POCO / 2 = WUMPUS / 3 = OURO / 888 = AGENTE\n\n\n");
    printf("\t\tCORDENADA: 1 = NORTE / 2 = LESTE / 3 = SUL / 4 = OESTE\n\n\n");
    printf("Insira numero de linhas\n");
    scanf("%d", &linhas);
    printf("Insira numero de colunas\n");
    scanf("%d", &colunas);

    while (linhas != colunas){                           //Enquanto o usuario nao digitar valores iguais para linha e coluna
                printf("Insira numero de linhas\n");     //
                scanf("%d", &linhas);
                printf("Insira numero de colunas\n");
                scanf("%d", &colunas);
    }
    int ambiente[linhas][colunas],percepcoes[linhas][colunas],agente[linhas][colunas];

    for (i=1; i<=linhas; i++){// ZERANDO A MATRIZ AMBIENTE
         for (j=1; j<=colunas; j++){
              ambiente[i][j]=0;
            }
    }

     for (i=1; i<=linhas; i++){//ZERANDO A MATRIZ PERCEPCOES
         for (j=1; j<=colunas; j++){
            percepcoes[i][j]=0;
            }
    }

    poco = linhas - 1; // DETERMINANDO O NUMERO DE POCOS
    srand((unsigned)time(NULL));

    soma=0;
    while(soma<poco){          // CONDICAO PARA DISTRIBUIR OS POCOS
        x = rand()%linhas+0;
        y = rand()%colunas+1;
        if(ambiente[x][y]==0 && (x != 1 || y !=1 )){
            ambiente[x][y]= 1;
            soma=soma+1;
        }
    }
    wumpus=0;
    while(wumpus<1){ // CONDICAO PARA DISTRIBUIR O WUMPUS;
        x = rand()%linhas+1;
        y = rand()%colunas+0;
        if (ambiente[x][y]==0 && (x != 1 || y !=1 )){
            ambiente[x][y]=2;
            wumpus=wumpus+1;
        }
     }
    ouro = 0;
    while(ouro<1){ // CONDICAO PARA DISTRIBUIR O OURO;
        x = rand()%linhas+1;
        y = rand()%colunas+0;
        if (ambiente[x][y]==0 && (x != 1 || y !=1 )){
            ambiente[x][y]=3;
            ouro=ouro+1;
        }
    }
    for(i=1;i<=linhas;i++){ //DEFININDO AS PERCEPCOES DO OURO
            for(j=1;j<=colunas;j++){
                if(ambiente[i][j]==3){percepcoes[i][j]=33;}
                }
                }

    for (i=1;i<=linhas;i++){ // DEFININDO AS PERCEPCOES DO WUMPUS
            for(j=1;j<=colunas;j++){
                if(ambiente[i][j]==2){
                    percepcoes[i][j]=2;
                    if (percepcoes[i][j]==2){
                        if (i!=linhas){
                            if (percepcoes[i+1][j]==33){percepcoes[i+1][j]=2233;}
                            else{percepcoes[i+1][j]=22;}
                        }
                        if (i!=1){
                            if (percepcoes[i-1][j]==33){percepcoes[i-1][j]=2233;}
                            else{percepcoes[i-1][j]=22;}

                        }
                        if (j!=colunas){
                            if (percepcoes[i][j+1]==33){percepcoes[i][j+1]=2233;}
                            else{percepcoes[i][j+1]=22;}
                        }
                        if (j!=1){
                            if (percepcoes[i][j-1]==33){percepcoes[i][j-1]=2233;}
                            else{percepcoes[i][j-1]=22;}
                        }
                    }

                }
            }
    }



     for(i=1;i<=linhas;i++){ // DEFININDO AS PERCEPCOES POCO
            for(j=1;j<=colunas;j++){
                if (ambiente[i][j] == 1 )  {
                    percepcoes[i][j]=1;
                    if (percepcoes[i][j]==1){
                        if (i!=linhas){
                            if (percepcoes[i+1][j]==0){percepcoes [i+1][j]=11;}
                            if (percepcoes[i+1][j]==22){percepcoes[i+1][j]=1122;}
                            if (percepcoes[i+1][j]==33){percepcoes[i+1][j]=1133;}
                            if (percepcoes[i+1][j]==2233){percepcoes[i+1][j]=112233;}
                        }
                        if (i!=1){
                            if (percepcoes[i-1][j]==0){percepcoes [i-1][j]=11;}
                            if (percepcoes[i-1][j]==22){percepcoes[i-1][j]=1122;}
                            if (percepcoes[i-1][j]==33){percepcoes[i-1][j]=1133;}
                            if (percepcoes[i-1][j]==2233){percepcoes[i-1][j]=112233;}
                        }
                        if (j!=colunas){
                            if (percepcoes[i][j+1]==0){percepcoes [i][j+1]=11;}
                            if (percepcoes[i][j+1]==22){percepcoes[i][j+1]=1122;}
                            if (percepcoes[i][j+1]==33){percepcoes[i][j+1]=1133;}
                            if (percepcoes[i][j+1]==2233){percepcoes[i][j+1]=112233;}
                        }
                        if (j!=1){
                            if (percepcoes[i][j-1]==0){percepcoes [i][j-1]=11;}
                            if (percepcoes[i][j-1]==22){percepcoes[i][j-1]=1122;}
                            if (percepcoes[i][j-1]==33){percepcoes[i][j-1]=1133;}
                            if (percepcoes[i][j-1]==2233){percepcoes[i][j-1]=112233;}
                        }
                    }
                }
            }
     }
	for(i=1;i<=linhas;i++){//ZERANDO A MATRIZ AGENTE
		for (j=1;j<=colunas;j++){
			agente[i][j]=0;

		}
	printf("\n");
	}
	agente[1][1] = 888;

    x = 0;
    G = 1;
    K = 1;
	for (i=1;i<=linhas;i++){// MATRIZ RESPONSAVEL PELO AGENTE INTELIGENTE!
            if (G == 7){break;}
        for(j=1;j<=colunas;j++){
               //printf("posicao %d %d\n",i,j);

                if (K==1){
                    printf("\t\t\t\t\t\tMATRIZ AGENTE 007\n\n");
                    for (a=1; a<=linhas; a++){
                        for (b=1; b<=colunas; b++){
                            printf("\t\t%d\t",agente[a][b]);
                        }
                        printf("\n");
                    }
                }

                if (G == 7){break;}
                K=0;
            if (agente[1][1]==888){ // AGENTE INTELIGENTE CANTO 1
                if (percepcoes[1][1]==0){
                    K=1;
                    printf("VOCE NAO ESTA SENTINDO NADA!\n");
                        x = rand()%2+2;
                        printf("Cordenada: %d\n",x);
                    				if (x == 2){
                    					agente[i][j+1]=888;
                    					agente[i][j] = 0;
									}
									if(x==3){
										agente[i+1][j] = 888;
										agente[i][j] = 0;
									}
                    }
                if (percepcoes[i][j] == 11){
                    K=1;
                    printf("VOCE ESTA SENTINDO BRISA!!!\n");
									x = rand()%2+2;
                    				if (x == 2){
                    					agente[i][j+1]=888;
                    					agente[i][j] = 0;
									}
									if(x==3){
										agente[i+1][j] = 888;
										agente[i][j] = 0;
									}
    						printf("Cordenada: %d \n",x);
                        if (percepcoes[1][j+1]==1&&agente[i][j+1]==888||percepcoes[i+1][j]==1&&agente[i+1][j]==888){
                            printf("VOCE CAIU NO POCO!!\n");
                            G = 7;

                        }
                }
                if (percepcoes[i][j]==22){
                    K=1;
                    printf("VOCE ESTA SENTINDO FEDOR!!!\n");
                           x = rand()%2+2;
                            if (x == 2){
                                agente[i][j+1]=888;
                                agente[i][j] = 0;
                            }
                            if(x==3){
                                agente[i+1][j] = 888;
                                agente[i][j] = 0;
                            }
    						printf("Cordenada: %d\n",x);
                            if (percepcoes[1][j+1]==2&&agente[i][j+1]==888||percepcoes[i+1][j]==2&&agente[i+1][j]==888){
                                printf("WUMPUS PEGOU VOCE\n");
                                G = 7;
                    }
                }
                if (percepcoes[i][j]==33){
                    K=1;
                    printf("VOCE ESTA SENTINDO BRILHO!!!\n");
                    printf("VOCE GANHOU! CONGRATULATION!\n");
                    }

                if (percepcoes[i][j] == 1122){
                    K=1;
                    printf("VOCE ESTA SENTINDO BRISA E FEDOR!!!\n");
									x = rand()%2+2;
                    				if (x == 2){
                    					agente[i][j+1]=888;
                    					agente[i][j] = 0;
									}
									if(x==3){
										agente[i+1][j] = 888;
										agente[i][j] = 0;
									}
    						printf("Cordenada: %d\n",x);
                        if (percepcoes[1][j+1]==1&&agente[i][j+1]==888||percepcoes[i+1][j]==1&&agente[i+1][j]==888){
                            printf("VOCE CAIU NO POCO!!\n");
                            G = 7;
                        }
                        if (percepcoes[1][j+1]==2&&agente[i][j+1]==888||percepcoes[i+1][j]==2&&agente[i+1][j]==888){
                            printf("WUMPUS PEGOU VOCE!!n");
                            G = 7;
                        }
                }
            }
            else if (agente[1][j] == 888 && j!=1 && j!=colunas){//PAREDE SUPERIOR
                    if(percepcoes[1][j] == 0 && j!=1 && j!=colunas){
                            K=1;
                            printf("VOCE ESTA SENTINDO NADA\n");
                                x = rand()%2+2;
                                printf("Cordenada: %d\n",x);

                                if (x==2){
                                	agente[i][j+1]=888;
                            		agente[i][j] = 0;
								}
								if (x==3){
                                	agente[i+1][j]=888;
                            		agente[i][j] = 0;
								}
                    }
                    if(percepcoes[1][j] == 11 && (j!=1 && j!=colunas)){
                            K=1;
                            printf("VOCE ESTA SENTINDO BRISA!!!!\n");
                            x = rand()%2+2;
                              printf("Cordenada: %d\n",x);

                                if (x==2){
                                	agente[i][j+1]=888;
                            		agente[i][j] = 0;
								}
								if (x==3){
                                	agente[i+1][j]=888;
                            		agente[i][j] = 0;
								}
                            if (percepcoes[1][j+1]==1&&agente[1][j+1]==888||percepcoes[i+1][j]==1&&agente[i+1][j]==888){
                                printf("VOCE CAIU NO POCO!!!!!\n");
                                G = 7;
                            }

                    }
                    if(percepcoes[1][j]==22 && j!=1&&j!=colunas){
                            K=1;
                    	printf("VOCE ESTA SENTINDO FEDOR!!!!\n");
                    	x = rand()%2+2;
                                printf("Cordenada: %d\n",x);

                                if (x==2){
                                	agente[i][j+1]=888;
                            		agente[i][j] = 0;
								}
								if (x==3){
                                	agente[i+1][j]=888;
                            		agente[i][j] = 0;
								}
						if (percepcoes[i][j+1]==2&&agente[i][j+1]==888||percepcoes[i+1][j]==2&&agente[i+1][j]==888){
                        	printf("WUMPUS PEGOU VOCE!!\n");
                        	G = 7;
                    	}
					}
					if(percepcoes[1][j]==1122 && j!=1&&j!=colunas){
                            K=1;
                    	printf("VOCE ESTA SENTINDO BRISA E FEDOR!!!!\n");
                                x = rand()%2+2;
                              printf("Cordenada: %d\n",x);

                                if (x==2){
                                	agente[i][j+1]=888;
                            		agente[i][j] = 0;
								}
								if (x==3){
                                	agente[i+1][j]=888;
                            		agente[i][j] = 0;
								}
						if (percepcoes[i][j+1]==1&&agente[i][j+1]==888||percepcoes[i+1][j]==1&&agente[i+1][j]==888){
                        	printf("VOCE CAIU NO POCO!!\n");
                        	G = 7;
                    	}
						if (percepcoes[i][j+1]==2&&agente[i][j+1]==888||percepcoes[i+1][j]==2&&agente[i+1][j]==888){
                        	printf("WUMPUS PEGOU VOCE!!\n");
                        	G = 7;
                    	}
					}
					if(percepcoes[1][j]==2233 && j!=1&&j!=colunas){
                            K=1;
                    	printf("VOCE ESTA SENTINDO FEDOR E BRILHO!!!!\n");
                    	printf("CONGRATULATION! VOCE PEGOU O OURO!!!\n");
                        G = 7;
					}
					if(percepcoes[1][j]==112233 && j!=1&&j!=colunas){
					    K=1;
                    	printf("VOCE ESTA SENTINDO FEDOR,BRISA E BRILHO!!!!\n");
                    	printf("CONGRATULATION! VOCE GANHOU\n");
                    	printf("CONGRATULATION! VOCE PEGOU O OURO!!!\n");
                        G = 7;
					}
					if(percepcoes[1][j]==33 && j!=1&&j!=colunas){
					    K=1;
                    	printf("VOCE ESTA SENTINDO BRILHO\n");
						printf("CONGRATULATION! VOCE GANHOU\n");
						G = 7;

					}
					if(percepcoes[1][j]==1133 && j!=1&&j!=colunas){
                            K=1;
                    	printf("VOCE ESTA SENTINDO BRISA E BRILHO!!!!\n");
                    	printf("CONGRATULATION! VOCE PEGOU O OURO!!!\n");
                        G = 7;
					}
				}

            else if (agente[linhas][1]){// AGENTE INTELIGENTE CANTO 2
                    if (percepcoes[linhas][1]==0){
                            printf("VOCE ESTA SENTINDO NADA!!");
                            K=1;
                            x = 2;
                            if (x == 2){
                                agente[i][j+1]=888;
                                agente[i][j] = 0;
                            }
                            printf("Cordenada: %d\n",x);
                    }
                    if (percepcoes[linhas][1]==11){
                        K=1;
                        printf("VOCE ESTA SENTINDO BRISA!!");
                         x = 2;
                            if (x == 2){
                                agente[i][j+1]=888;
                                agente[i][j] = 0;
                            }
    						printf("Cordenada: %d\n",x);
                        if (percepcoes[1][j+1]==1&&agente[i][j+1]==888||percepcoes[i-1][j]==1&&agente[i-1][j]==888){
                            printf("VOCE CAIU NO POCO!!\n");
                             G = 7;
                        }
                    }

                    if (percepcoes[linhas][1]==22){
                        K=1;
                        printf("VOCE ESTA SENTINDO FEDOR!!");
                          x = 2;
                            if (x == 2){
                                agente[i][j+1]=888;
                                agente[i][j] = 0;
                            }
    						printf("Cordenada: %d\n",x);
                            if (percepcoes[1][j+1]==2&&agente[i][j+1]==888||percepcoes[i-1][j]==2&&agente[i-1][j]==888){
                                printf("WUMPUS PEGOU VOCE!!\n");
                                G = 7;
                            }
                    }
                    if (percepcoes[linhas][1]==33){
                        K=1;
                        printf("VOCE ESTA SENTINDO BRILHO!!\n");
                        printf("VOCE GANHOU!! CONGRATULATION\n");
                         G = 7;
                    }
                    if (percepcoes[linhas][1]==1122){
                        K=1;
                        printf("VOCE ESTÁ SENTINDO BRISA E FEDOR!!\n");
                        printf("VOCE ESTA SENTINDO BRISA!!");
                          x = 2;
                            if (x == 2){
                                agente[i][j+1]=888;
                                agente[i][j] = 0;
                            }
    						printf("Cordenada: %d\n",x);
                        if (percepcoes[1][j+1]==1&&agente[i][j+1]==888){
                            printf("VOCE CAIU NO POCO!!\n");
                             G = 7;
                        }
                        if (percepcoes[1][j+1]==2&&agente[i][j+1]==888){
                            printf("WUMPUS PEGOU VOCE!!!\n");
                             G = 7;
                        }
                    }

                    if (percepcoes[linhas][1]==2233){
                        K=1;
                        printf("VOCE ESTÁ SENTINDO FEDOR E BRILHO!!\n");
                        printf("VOCE PEGOU O OURO! CONGRATULATION!!\n");
                         G = 7;
                    }
                    if (percepcoes[linhas][1]==1133){
                        K=1;
                        printf("VOCE ESTÁ SENTINDO BRISA E BRILHO!!\n");
                        printf("VOCE PEGOU O OURO! CONGRATULATION!!\n");
                         G = 7;
                    }
                }
            else if (agente[1][colunas]==888){ // AGENTE INTELIGENTE CANTO 3

                    if (percepcoes[1][colunas]==0){
                        K=1;
                        printf("VOCE ESTA SENTINDO NADA!!!\n");
                        printf("Cordenada: %d\n",x);
                         x = 3;
                            if (x == 3){
                                agente[i+1][j]= 888;
                                agente[i][j] = 0;
                            }

                    }
                    if (percepcoes[1][colunas]==11){
                            K=1;
                        printf("VOCE ESTA SENTINDO BRISA!!!!\n");
                         x = 3;
                            if (x == 3){
                                agente[i+1][j]= 888;
                                agente[i][j] = 0;
                            }
    						printf("Cordenada: %d\n",x);
                        if (percepcoes[i+1][j]==1&&agente[i+1][j]==888){
                            printf("VOCE CAIU NO POCO!!\n");
                             G = 7;
                        }
                    }
                    if (percepcoes[1][colunas]==22){
                        K=1;
                        printf("VOCE ESTA SENTINDO FEDOR!!!");
                         x = 3;
                            if (x == 3){
                                agente[i+1][j]= 888;
                                agente[i][j] = 0;
                            }
    						printf("Cordenada: %d\n",x);
                        if (percepcoes[i+1][j]==2&&agente[i+1][j]==888){
                            printf("WUMPUS PEGOU VOCE!!\n");
                             G = 7;
                        }
                    }
                    if (percepcoes[1][colunas]==33){
                        K=1;
                        printf("VOCE ESTA SENTINDO BRILHO\n");
                        printf ("VOCE GANHOU!!!\n");
                         G = 7;
                        }
                    if (percepcoes[1][colunas]==1122){
                        K=1;
                            printf("VOCE ESTA SENTINDO BRISA E FEDOR!!\n");
                            x = 3;
                            if (x == 3){
                                agente[i+1][j]= 888;
                                agente[i][j] = 0;
                            }
    						printf("Cordenada: %d",x);
                        if (percepcoes[i+1][j]==1&&agente[i+1][j]==888){
                            printf("VOCE CAIU NO POCO!!\n");
                             G = 7;
                        }
                        if (percepcoes[i+1][j]==2&&agente[i+1][j]==888){
                            printf("WUMPUS PEGOU VOCE!!\n");
                             G = 7;
                        }
                    }
                    if (percepcoes[1][colunas]==2233){
                        K=1;
                            printf("VOCE ESTA SENTINDO BRILHO E FEDOR\n");
                            printf("VOCE PEGOU O OURO PARABENS!!!\n");
                             G = 7;
                    }
                    if (percepcoes[1][colunas]==112233){
                        K=1;
                            printf("VOCE ESTA SENTINDO BRISA,FEDOR E BRILHO!!!\n");
                            printf("VOCE PEGOU O OURO PARABENS!!!\n");
                             G = 7;
                    }
                    if (percepcoes[1][colunas]==1133){
                        K=1;
                            printf("VOCE ESTA SENTINDO BRISA E BRILHO!!!\n");
                            printf("VOCE PEGOU O OURO PARABENS!!!\n");
                             G = 7;
                    }


            }
            else if (agente[linhas][colunas]==888){//AGENTE INTELIGENTE CANTO 4
                    if(percepcoes[linhas][colunas]==0){
                            K=1;
                        printf("VOCE ESTA SENTINDO NADA!!");
                        x=3;
                        while(x==3||x==2){
                        x = rand()%4+1;
                            if (x == 1){
                                agente[i-1][j]= 888;
                                agente[i][j] = 0;
                            }
                            if(x == 4){
                                agente[i][j-1] = 888;
                                agente[i][j] = 0;
                            }
    						printf("Cordenada: %d\n",x);
                    }
                    }
                    if(percepcoes[linhas][colunas]==11){
                            K=1;
                        printf("VOCE ESTA SENTINDO BRISA!!!");
                          x=3;
                        while(x==3||x==2){
                            x = rand()%4+1;
                            if (x == 1){
                                agente[i-1][j]= 888;
                                agente[i][j] = 0;
                            }
                            if(x == 4){
                                agente[i][j-1] = 888;
                                agente[i][j] = 0;
                            }
    						printf("Cordenada: %d\n",x);
                        }
                        if (percepcoes[i-1][j]==1&&agente[i-1][j]==888||percepcoes[i][j-1]==1&&agente[i][j-1]==888){
                            printf("VOCE CAIU NO POCO!!!!!\n");
                             G = 7;
                        }
                    }
                    if(percepcoes[linhas][colunas]==22){
                        K=1;
                        printf("VOCE ESTA SENTINDO FEDOR!!!\n");
                          x=3;
                        while(x==3||x==2){
                            x = rand()%4+1;
                            if (x == 1){
                                agente[i-1][j]= 888;
                                agente[i][j] = 0;
                            }
                            if(x == 4){
                                agente[i][j-1] = 888;
                                agente[i][j] = 0;
                            }
    						printf("Cordenada: %d\n",x);
                        }
                        if (percepcoes[i-1][j]==2&&agente[i-1][j]==888||percepcoes[i][j-1]==2&&agente[i][j-1]==888){
                            printf("WUMPUS PEGOU VOCE!!!!\n");
                             G = 7;
                        }
                    }
                    if(percepcoes[linhas][colunas]==33){
                        K=1;
                        printf("VOCE ESTA SENTINDO BRILHO!!!\n");
                        printf("VOCE GANHOU! CONGRATULATION!!\n");
                         G = 7;
                    }
                    if(percepcoes[linhas][colunas]==1122){
                        K=1;
                        printf("VOCE ESTA SENTIDO BRISA E FEDOR!!\n");
                        x=3;
                        while(x==3||x==2){
                            x = rand()%4+1;
                            if (x == 1){
                                agente[i-1][j]= 888;
                                agente[i][j] = 0;
                            }
                            if(x == 4){
                                agente[i][j-1] = 888;
                                agente[i][j] = 0;
                            }
    						printf("Cordenada: %d\n",x);
                        }
                        if (percepcoes[i-1][j]==1&&agente[i-1][j]==888||percepcoes[i][j-1]==1&&agente[i][j-1]==888){
                            printf("VOCE CAIU NO POCO!!!!\n");
                             G = 7;
                        }
                        if (percepcoes[i-1][j]==2&&agente[i-1][j]==888||percepcoes[i][j-1]==2&&agente[i][j-1]==888){
                            printf("WUMPUS PEGOU VOCE!!!!\n");
                             G = 7;
                        }
                    }
                    if(percepcoes[linhas][colunas]==2233){
                        K=1;
                        printf("VOCE ESTA SENTIDO  FEDOR E BRILHO!!\n");
                        printf("PARABÉNS VOCE GANHOU!!");
                            G = 7;
                    }
                    if(percepcoes[linhas][colunas]==1133){
                        K=1;
                        printf("VOCE ESTA SENTIDO  BRISA E BRILHO!!\n");
                        printf("PARABÉNS VOCE GANHOU!!");
                            G = 7;
                    }
                    }
            else if (agente[i][1] == 888 && i!=1 && i!=colunas){//PAREDE ESQUERDA
				 	  if(percepcoes[i][1] == 0 && i!=1 && i!=colunas){
                            K=1;
                            printf("VOCE ESTA SENTINDO NADA\n");
                            	x = rand()%2+2;
								if(x==2){
									agente[i][j+1]=888;
									agente[i][j] = 0;
								}
								if(x==3){
									agente[i+1][j] = 888;
									agente[i][j] = 0;
								}
    						printf("Cordenada: %d\n",x);

					}
					if(percepcoes[i][1] == 11 && (i!=1 && i!=colunas)){
                        K=1;
						printf("VOCE ESTA SENTINDO BRISA!!\n");
							x = rand()%2+2;
								if(x==2){
									agente[i][j+1]=888;
									agente[i][j] = 0;
								}
								if(x==3){
									agente[i+1][j] = 888;
									agente[i][j] = 0;
								}
    						printf("Cordenada: %d\n",x);
    					if (percepcoes[i][j+1]==1&&agente[1][j+1]==888||percepcoes[i+1][j]==1&&agente[i+1][j]==888){
                        	printf("VOCE CAIU NO POCO!!\n");
                        	 G = 7;
                    	}
                    }
                    if(percepcoes[i][1] == 22 && (i!=1 && i!=colunas)){
                        K=1;
						printf("VOCE ESTA SENTINDO FEDOR!!\n");
							x = rand()%2+2;
								if(x==2){
									agente[i][j+1]=888;
									agente[i][j] = 0;
								}
								if(x==3){
									agente[i+1][j] = 888;
									agente[i][j] = 0;
								}
    						printf("Cordenada: %d\n",x);
    						if (percepcoes[i][j+1]==2&&agente[1][j+1]==888||percepcoes[i+1][j]==2&&agente[i+1][j]==888){
                                printf("WUMPUS PEGOU VOCE!!!\n");
                                G = 7;
                    	}
                    }
                    if(percepcoes[i][1] == 1122 && (i!=1 && i!=colunas)){
                        K=1;
						printf("VOCE ESTA SENTINDO FEDOR!!\n");
							x = rand()%2+2;
								if(x==2){
									agente[i][j+1]=888;
									agente[i][j] = 0;
								}
								if(x==3){
									agente[i+1][j] = 888;
									agente[i][j] = 0;
								}
    						printf("Cordenada: %d\n",x);
    						if (percepcoes[i][j+1]==1&&agente[1][j+1]==888||percepcoes[i+1][j]==1&&agente[i+1][j]==888){
                                printf("WUMPUS PEGOU VOCE!!!\n");
                                G = 7;
                            }
    						if (percepcoes[i][j+1]==2&&agente[1][j+1]==888||percepcoes[i+1][j]==2&&agente[i+1][j]==888||
                            percepcoes[i-1][j]==2&&agente[-1][j+1]==888){
                                printf("WUMPUS PEGOU VOCE!!!\n");
                                G = 7;
                            }
                    }
                    if(percepcoes[i][1] == 112233 && (i!=1 && i!=colunas)){
                        K=1;
						printf("VOCE ESTA SENTINDO BRISA,FEDOR E BRILHO!!\n");
						printf("VOCE PEGOU O OURO! CONGRATULATION!\n");
						 G = 7;
                    	}
                    if(percepcoes[i][1] == 2233 && (i!=1 && i!=colunas)){
                        K=1;
						printf("VOCE ESTA SENTINDO FEDOR E BRILHO!!\n");
						printf("VOCE PEGOU O OURO! CONGRATULATION!\n");
						 G = 7;
                    	}
                    if(percepcoes[i][1] == 1133 && (i!=1 && i!=colunas)){
                        K=1;
						printf("VOCE ESTA SENTINDO BRISA E BRILHO!!\n");
						printf("VOCE PEGOU O OURO! CONGRATULATION!\n");
						 G = 7;
                    	}
                    if(percepcoes[i][1] == 33 && (i!=1 && i!=colunas)){
                        K=1;
						printf("VOCE ESTA SENTINDO FEDOR E BRILHO!!\n");
						printf("VOCE PEGOU O OURO! CONGRATULATION!\n");
						 G = 7;
                    	}
                }
            else if (agente[i][colunas] == 888 && (i!=1 && j!=colunas) && (i!=linhas && j!= colunas)){//PAREDE DIREITA
                    if(percepcoes[i][colunas] == 0 && (i!=1 && j!=colunas) && (i!=linhas && j!= colunas)){
                            K=1;
                            printf("VOCE ESTA SENTINDO NADA\n");
                            	x = rand()%4+3;
								if(x==4){
									agente[i][j-1]=888;
									agente[i][j] = 0;
								}
								if(x==3){
									agente[i+1][j] = 888;
									agente[i][j] = 0;
								}
    						printf("Cordenada: %d",x);
						}
                    if(percepcoes[i][colunas] == 11 && (i!=1 && j!=colunas) && (i!=linhas && j!= colunas)){
                            K=1;
                            printf("VOCE ESTA SENTINDO BRISA\n");
                            	x = rand()%4+3;
								if(x==4){
									agente[i][j-1]=888;
									agente[i][j] = 0;
								}
								if(x==3){
									agente[i+1][j] = 888;
									agente[i][j] = 0;
								}
    						printf("Cordenada: %d",x);
    						if (percepcoes[i][j-1]==1&&agente[1][j-1]==888||percepcoes[i+1][j]==1&&agente[i+1][j]==888){
                                printf("VOCE CAIU NO POCO\n");
                                G = 7;
                    	}
                    }
                    if(percepcoes[i][colunas] == 22 && (i!=1 && j!=colunas) && (i!=linhas && j!= colunas)){
                                K=1;
                            printf("VOCE ESTA SENTINDO BRISA\n");
                            	x = rand()%4+3;
								if(x==4){
									agente[i][j-1]=888;
									agente[i][j] = 0;
								}
								if(x==3){
									agente[i+1][j] = 888;
									agente[i][j] = 0;
								}
    						printf("Cordenada: %d",x);
    						if (percepcoes[i][j-1]==2&&agente[1][j-1]==888||percepcoes[i+1][j]==2&&agente[i+1][j]==888){
                                printf("WUMPUS PEGOU VOCE!!!\n");
                        	 G = 7;
                    		}
              			  }

                    if(percepcoes[i][colunas] == 1122 && (i!=1 && j!=colunas) && (i!=linhas && j!= colunas)){
                            K=1;
                            printf("VOCE ESTA SENTINDO BRISA E FEDOR\n");
                            	x = rand()%4+3;
								if(x==4){
									agente[i][j-1]=888;
									agente[i][j] = 0;
								}
								if(x==3){
									agente[i+1][j] = 888;
									agente[i][j] = 0;
								}
    						printf("Cordenada: %d",x);
    						if (percepcoes[i][j-1]==1&&agente[1][j-1]==888||percepcoes[i+1][j]==1&&agente[i+1][j]==888){
                        	printf("VOCE CAIU NO POCO\n");
                        	 G = 7;
                    		}
                    		if (percepcoes[i][j-1]==2&&agente[1][j-1]==888||percepcoes[i+1][j]==2&&agente[i+1][j]==888){
                        	printf("WUMPUS PEGOU VOCE!!!\n");
                        	 G = 7;
                    		}

                    }
                    if(percepcoes[i][colunas] == 1133 && (i!=1 && j!=colunas) && (i!=linhas && j!= colunas)){
                                K=1;
                            printf("VOCE ESTA SENTINDO BRISA E BRILHO\n");
                            printf("VOCE PEGOU O OURO! CONGRATULATION!\n");
                             G = 7;

                    }
                    if(percepcoes[i][colunas] == 2233 && (i!=1 && j!=colunas) && (i!=linhas && j!= colunas)){
                                K=1;
                            printf("VOCE ESTA SENTINDO FEDOR E BRILHO\n");
                            printf("VOCE PEGOU O OURO! CONGRATULATION!\n");
                             G = 7;

                    }
                    if(percepcoes[i][colunas] == 112233 && (i!=1 && j!=colunas) && (i!=linhas && j!= colunas)){
                                K=1;
                            printf("VOCE ESTA SENTINDO BRISA, FEDOR E BRILHO\n");
                            printf("VOCE PEGOU O OURO! CONGRATULATION!\n");
                             G = 7;
                    }
                    if(percepcoes[i][colunas] == 33 && (i!=1 && j!=colunas) && (i!=linhas && j!= colunas)){
						    K=1;
                            printf("VOCE ESTA SENTINDO BRILHO\n");
                            printf("VOCE PEGOU O OURO! CONGRATULATION!\n");
                             G = 7;
						}
					}
            else if (agente[linhas][j] == 888 && (j!=1 && j!=colunas)){//PAREDE INFERIOR
						if(agente[linhas][j] == 0 && (j!=1 && j!=colunas)){
                                K=1;
								x=3;
								while(x==3){
									x = rand()%4+2;

									if(x==2){
										agente[i][j+1]=888;
										agente[i][j] = 0;
									}
									if(x==4){
										agente[i][j-1] = 888;
										agente[i][j] = 0;
									}
                            printf("Cordenada: %d",x);
    						}

						}
						if(agente[linhas][j] == 11 && (j!=1 && j!=colunas)){
                                K=1;
							printf("VOCE ESTA SENTINDO BRISA!!!\n");
								x=3;
								while(x==3){
									x = rand()%4+2;

									if(x==2){
										agente[i][j+1]=888;
										agente[i][j] = 0;
									}
									if(x==4){
										agente[i][j-1] = 888;
										agente[i][j] = 0;
									}
    						printf("Cordenada: %d",x);
    						}
    						if (percepcoes[i][j-1]==1&&agente[i][j-1]==888||percepcoes[i][j+1]==1&&agente[i][j+1]==888){
                        	printf("VOCE CAIU NO POCO\n");
                        	 G = 7;
                    		}

						}
						if(agente[linhas][j] == 22 && (j!=1 && j!=colunas)){
                                K=1;
								printf("VOCE ESTA SENTINDO FEDOR!!\n");
								x=3;
								while(x==3){
									x = rand()%4+2;

									if(x==2){
										agente[i][j+1]=888;
										agente[i][j] = 0;
									}
									if(x==4){
										agente[i][j-1] = 888;
										agente[i][j] = 0;
									}
    						printf("Cordenada: %d",x);
    						}
    						if (percepcoes[i][j-1]==2&&agente[1][j-1]==888||percepcoes[i][j+1]==2&&agente[i][j+1]==888){
                        	printf("VOCE CAIU NO POCO\n");
                        	 G = 7;
                    		}

						}
						if(agente[linhas][j] == 1122 && (j!=1 && j!=colunas)){
                                K=1;
								printf("VOCE ESTA SENTINDO BRISA E FEDOR!!\n");
								x=3;
								while(x==3){
									x = rand()%4+2;

									if(x==2){
										agente[i][j+1]=888;
										agente[i][j] = 0;
									}
									if(x==4){
										agente[i][j-1] = 888;
										agente[i][j] = 0;
									}
    						printf("Cordenada: %d",x);
    						}
    						if (percepcoes[i][j-1]==1&&agente[linhas][j-1]==888||percepcoes[i][j]==1&&agente[i][j+1]==888){
                                printf("VOCE CAIU NO POCO\n");
                                G = 7;
                    		}
                    		if (percepcoes[i][j-1]==2&&agente[1][j-1]==888||percepcoes[i-1][j]==2&&agente[i-1][j]==888||
                            percepcoes[i][j+1]==2&&agente[i][j+1]==888){
                                printf("WUMPUS PEGOU VOCE!!\n");
                                G = 7;
                    		}

						}
						if(agente[linhas][j] == 112233 && (j!=1 && j!=colunas)){
                                K=1;
								printf("VOCE ESTA SENTINDO BRISA,FEDOR E BRILHO!!\n");
								printf("VOCE PEGOU O OURO! CONGRATULATION!\n");
								 G = 7;
						}
						if(agente[linhas][j] == 2233 && (j!=1 && j!=colunas)){
                                K=1;
								printf("VOCE ESTA SENTINDO FEDOR E BRILHO!!\n");
								printf("VOCE PEGOU O OURO! CONGRATULATION!\n");
								 G = 7;
						}
						if(agente[linhas][j] == 33 && (j!=1 && j!=colunas)){
                                K=1;
								printf("VOCE ESTA SENTINDO BRILHO!!\n");
								printf("VOCE PEGOU O OURO! CONGRATULATION!\n");
								 G = 7;
						}
						if(agente[linhas][j] == 1133 && (j!=1 && j!=colunas)){
                                K=1;
								printf("VOCE ESTA SENTINDO BRISA E BRILHO!!\n");
								printf("VOCE PEGOU O OURO! CONGRATULATION!\n");
								 G = 7;
						}

					}
            else {
                 if(agente[i][j]==888){
                        if(percepcoes[i][j]==0){
                            K=1;
                            printf("VOCE NAO ESTA SENTINDO NADA!!!");
									x = rand()%2+2;
									printf("Cordenada: %d\n",x);

									if(x==2){
										agente[i][j+1]=888;
										agente[i][j] = 0;
									}
									if(x==3){
										agente[i+1][j]=888;
										agente[i][j] = 0;
									}
    						}
						if(percepcoes[i][j]==11){
                            K=1;
							printf("VOCE ESTA SENTINDO BRISA!!!\n");
                            x = rand()%2+2;
									printf("Cordenada: %d\n",x);

									if(x==2){
										agente[i][j+1]=888;
										agente[i][j] = 0;
									}
									if(x==3){
										agente[i+1][j]=888;
										agente[i][j] = 0;
									}
                                    if (percepcoes[1][j+1]==1&&agente[1][j+1]==888||percepcoes[i+1][j]==1&&agente[i+1][j]==888){
                                        printf("VOCE CAIU NO POCO!!!!!\n");
                                        G = 7;
                                    }
						}
                        if(percepcoes[i][j]==22){
                                K=1;
							printf("VOCE ESTA SENTINDO FEDOR!!!\n");
                            x = rand()%2+2;
									printf("Cordenada: %d\n",x);

									if(x==2){
										agente[i][j+1]=888;
										agente[i][j] = 0;
									}
									if(x==3){
										agente[i+1][j]=888;
										agente[i][j] = 0;
									}
                                    if (percepcoes[1][j+1]==2&&agente[1][j+1]==888||percepcoes[i+1][j]==2&&agente[i+1][j]==888){
                                        printf("WUMPUS PEGOU VOCE!!\n");
                                        G = 7;
                                    }
						}
						if(percepcoes[i][j]==1122){
                            K=1;
							printf("VOCE ESTA SENTINDO BRISA E FEDOR!!!\n");
                            x = rand()%2+2;
                            printf("Cordenada: %d\n",x);
									if(x==2){
										agente[i][j+1]=888;
										agente[i][j] = 0;
									}
									if(x==3){
										agente[i+1][j]=888;
										agente[i][j] = 0;
									}
                                    if (percepcoes[1][j+1]==1&&agente[1][j+1]==888||percepcoes[i+1][j]==1&&agente[i+1][j]==888){
                                        printf("VOCE CAIU NO POCO!!\n");
                                        G = 7;
                                    }
                                    if (percepcoes[1][j+1]==2&&agente[1][j+1]==888||percepcoes[i+1][j]==2&&agente[i+1][j]==888
                                    ||percepcoes[i][j-1]==2&& agente[i][j-1]==888){
                                        printf("WUMPUS PEGOU VOCE!!\n");
                                        G = 7;
                                    }
                        }
                        if(agente[i][j]==112233){
                                K=1;
                                printf("VOCE ESTA SENTINDO BRISA, FEDOR E BRILHO!!!\n");
                                printf("VOCE PEGOU O OURO! CONGRATULATION!\n");
                                G = 7;

                        }
                        if(agente[i][j]==1133){
                                K=1;
                                printf("VOCE ESTA SENTINDO FEDOR E BRILHO!!!\n");
                                printf("VOCE PEGOU O OURO! CONGRATULATION!\n");
                                G = 7;
                        }
                        if(agente[i][j]==2233){
                            K=1;
                                printf("VOCE ESTA SENTINDO FEDOR E BRILHO!!!\n");
                                printf("VOCE PEGOU O OURO! CONGRATULATION!\n");
                                G = 7;
                        }
                        if(agente[i][j]==33){
                            K=1;
                                printf("VOCE ESTA SENTINDO BRILHO!!!\n");
                                printf("VOCE PEGOU O OURO! CONGRATULATION!\n");
                                G = 7;
						}

                    }
             }

        }
    }


    printf("\t\t\t\t\t\tMATRIZ NORMAL\n\n");
    for (i=1; i<=linhas; i++){
         for (j=1; j<=colunas; j++){
              printf("\t\t%d\t",ambiente[i][j]);

         }
              printf("\n");
    }

    printf("\t\t\t\t\t\tPERCEPCOES\n");
    for (i=1; i<=linhas; i++){
         for (j=1; j<=colunas; j++){
              printf("\t\t%d\t",percepcoes[i][j]);
         }
              printf("\n");
    }


 	return 0;
}
