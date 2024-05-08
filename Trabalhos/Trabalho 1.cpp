#include <stdio.h>    
#include <stdlib.h>  //random
#include <time.h>  //tempo e hora
#include <math.h>

void  MatrizEnt(int mat[10][10]) // Matriz Principal de 10x10
{
	int i,j;
		srand(time(0));
			 for(i=0;i<10;i++){
	 			for(j=0;j<10;j++){
	 				mat[i][j]= rand()%100;
				 }
	 	 	
			 }
	
}


void vetorParam(int n, int vetorP[10], int mat[10][10]) // criacao do vetor do parametro
{
	int t, i, j;
	srand(time(0));
	for(t=0; t<n; t++) {
		i = rand()%10;
		j = rand()%10;
		vetorP[t] = mat[i][j];
	}
	printf("-----------------");
	printf("\n      VETOR  \n");
	printf("-----------------\n");
	for(t=0; t<n; t++) {
		printf(" %d", vetorP[t]);
	}	
}


void gerarmatrizInd(int n,int vetorP[10],int MatrizEntrada[10][10],int MatrizInd[10][10]) // matriz dos Indices
{
    int i,j,t,menorInd,dist,distmin;
     
     for(i=0;i<10;i++)
	   {
     	for(j=0;j<10;j++)
		   {
     		distmin = 300;
     		for(t=0;t<n;t++)
			   {
     			dist = abs(MatrizEntrada[i][j]- vetorP[t]);
     			if(distmin>dist)
				 {
     				distmin=dist;
     				menorInd=t;
				 }
			    }
		    MatrizInd[i][j]= menorInd;
		    }
	 }
}



void calculoParam(int n,int res[10],int matrizEntrada[10][10],int matrizInd[10][10])  //funcao para calcular a media da matriz de indices
{
	int i,j,t,r,cont[10];
	
	   for(t=0;t<n;t++) 
	   {
	   	cont[t]=0;
	   	res[t]=0;  }
	   	
	   	for(i=0;i<10;i++)
	   	{
	   		for(j=0;j<10;j++)
			{
	   			r=matrizInd[i][j];
	   			res[r]+= matrizEntrada[i][j];
	   			cont[r]+=1;
			    
			}
		}
		for(i=0;i<n;i++){
			res[i]/=(float)cont[i];
		}

		  
}


int calculardistancia(int n,int vetorP[10],int res[10]) //calculo da distancia entre os valores de cada indice do vetor
{
   int i,distancia=0;
   
   for(i=0;i<n;i++){
   	distancia+=fabs(res[i]-vetorP[i]);
   }
   	return distancia;	
}


void copia(int n,int vetorP[10], int res[10]) // copiar o vetor res no vetor vetorP
{
	int i;
	 
	 for(i=0;i<n;i++){
	 	vetorP[i]=res[i];
	 }
	
	
}




void exibirres(int res[10],int n)  // exibir o vetor res(da media)
{
	int t;
    printf("\n-----------------");
	printf("\n  NOVO  VETOR   \n");
	printf("-----------------\n");
	for(t=0; t<n; t++) {
		printf(" %d", res[t]);
	}	
}





void Matrizsaida(int vetorP[10], int n, int matrizS[10][10], int matrizInd[10][10]) // matriz final
{
    int i, j;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int indice = matrizInd[i][j];
            matrizS[i][j] = vetorP[indice];
        }
    }

}

void  exibir(int mat[10][10]) // Funcao para Exibir a Matriz Principal e Final
{
	int i, j;
	        printf("----------------------");
			printf("\n  Matriz de Entrada \n"); 
			printf("----------------------\n");
			 	for(i=0; i<10; i++){
			 		printf("\n");
			 		  for(j=0; j<10; j++){
			 		    printf(" %d",mat[i][j]);
			 		}
				 }
	
}
void  exibirInd(int mat[10][10]) // Funcao para Exibir a Matriz Principal e dos indices
{
	int i, j;
	        printf("----------------------");
			printf("\n  Matriz de Indices \n"); 
			printf("----------------------\n");
			 	for(i=0; i<10; i++){
			 		printf("\n");
			 		  for(j=0; j<10; j++){
			 		  
			 		    printf(" %d",mat[i][j]);
			 		}
				 }
	
}

void  exibirS(int mat[10][10]) // Funcao para Exibir a Matriz Principal e Final
{
	int i, j;
	        printf("----------------------");
			printf("\n  Matriz de Saida \n"); 
			printf("----------------------\n");
			 	for(i=0; i<10; i++){
			 		printf("\n");
			 		  for(j=0; j<10; j++){
			 		    printf(" %d",mat[i][j]);
			 		}
				 }
	
}

int main()
{
	int matrizEntrada[10][10],vetorP[10],n,matrizInd[10][10],AC[10],matrizS[10][10],res[10],limite=5,d ;
	
       MatrizEnt(matrizEntrada);
       exibir(matrizEntrada);   //funcoes da matriz de entrada
       
       printf("\n");
       
       printf("\n Digite valor de n (Inteiro):");
       scanf("%d",&n);               // numero de casas do vetor do parametro

	   vetorParam(n,vetorP,matrizEntrada);	//funcao do parametro
	   
	   printf("\n");
	   
	   
	while(1){
	printf("\n");
	   gerarmatrizInd(n,vetorP,matrizEntrada,matrizInd);  // funcao da matriz de indices
	   exibirInd(matrizInd); //funcao para exibir a matrizes dos indices
	   calculoParam(n,res,matrizEntrada,matrizInd); //calcular o novo vetor da matriz dos indices
	   exibirres(res,n);  //funcao para exibir o novo vetor 
	   d=calculardistancia(n,vetorP,res); //calcular a distancia dos valores do vetor
	   if(d<limite) //comparando com o erro limite
	     break;
	    else
	       copia(n,vetorP,res); // copiando o vetor res para o vetorP
	   
}
	   Matrizsaida(res, n, matrizS, matrizInd);  // Matriz final
	   printf("\n");
	   exibirS(matrizS); 
	   
		
}
