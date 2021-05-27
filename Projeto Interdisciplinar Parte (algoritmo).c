#include<stdio.h>//Biblioteca respons�vel pelo uso do printf e do scanf.
#include<string.h>//Biblioteca para ler strings, strlen e stromp: http://linguagemc.com.br/a-biblioteca-string-h/
#include<stdlib.h>//Biblioteca para o uso do comando system("pause").
#include<ctype.h>//Biblioteca para o uso do toupper e tolower: http://linguagemc.com.br/ctype-h-toupper-tolower-isalpha-isdigit-em-c/
#include<locale.h>//Biblioteca para uso de acentua��o dentro do printf. 

typedef struct{//Fun��o struct onde definem tipos de dados que agrupam vari�veis sob um mesmo tipo de dado. 
  char tituloFoto[50];
  float precoFoto;
  int quantidadeFoto;
}foto;//Novo tipo de dado.

typedef struct{
    char nome[50], endereco[100], email[50];
    int idade;
}pessoa;//Novo tipo de dado.

int main(){//Fun��o main serve como o ponto de partida para a execu��o do programa.
    setlocale(LC_ALL, "Portuguese");//Direciona a biblioteca ao idioma que vai ser usado pelo <locale.h>.
    char opcaoPortifolio, opcaoFotos[10], nomeCliente[50], emailCliente[30], opcaoComprar, confirmacaoCadastro; 
    char emailPaypal[50], senhaPaypal[50];//Comando para declarar as vari�veis e armazenar no espa�o da mem�ria, do tipo caractere.    
    int contador, album, fotosEscolhidas, x;//Comando para declarar as vari�veis e armazenar no espa�o da mem�ria, do tipo inteiro.
    int numCliente, precoCarrinho=0;
    foto carrinho[10], tabela[10];//Declara��o das v�riaveis do tipo struct, criados a cima.
    
    tabela[0].precoFoto = 350;//Fazer com que o pre�o da foto 0 da tabela receba esse pre�o.
	    strcpy(tabela[0].tituloFoto, "Os Shelbys");//Uma string que faz o que est� escrito a direita, seja o que foi declarado a esquerda.
    tabela[1].precoFoto = 250;
		strcpy(tabela[1].tituloFoto, "Rel�quias da Morte");
    tabela[2].precoFoto = 250;
		strcpy(tabela[2].tituloFoto, "Invincible");
    tabela[3].precoFoto = 400;
		strcpy(tabela[3].tituloFoto, "The boys");
    tabela[4].precoFoto = 300;
		strcpy(tabela[4].tituloFoto, "Lucille");
    tabela[5].precoFoto = 350;
		strcpy(tabela[5].tituloFoto, "Bella Ciao");
    
    printf("----------------------------------------Bem vindo ao Prot�tipo do Portf�lio!--------------------------------------------\n");//Comando que printa na tela o que foi escrito dentro dos par�nteses, para o usu�rio.
    
    printf("Quantas pessoas desejam se cadastrar?\n");//Comando que printa na tela o que foi escrito dentro dos par�nteses, para o usu�rio.
    scanf("%d", &numCliente);//Comando que salva as vari�veis na mem�ria onde foi declarado pelo int e char.
    fflush(stdin);//Comando para limpar o buffer de mem�ria.
    pessoa cliente[numCliente];//Vari�vel do novo tipo de dado.

    for(contador=0;contador<numCliente;contador++){// Fun��o "para", � utilizada para um n�mero espec�fivo de repeti��es, diferente do "fa�a" ou "fa�a enquanto".
    	do{//Fun��o "fa�a enquanto" onde se repete algo ate que a condi��o se torne falsa e obrigatoriamente deve ser realizado uma vez..
			printf("Precisaremos de seu cadastro para futuras opera��es dentro do site.\n");
    		printf("Digite seu nome completo:");
    		fgets(cliente[contador].nome, 50, stdin);//Comando para salvar uma vari�vel na mem�ria, � como o scanf, mas ele consegue salvar os espa�os entre nomes, conseguindo dar mais nomes. 
    		fflush(stdin);
    		do{
    			printf("Digite sua idade (deve ser maior de 18 para se cadastrar): ");
    			scanf("%d", &cliente[contador].idade);
   				fflush(stdin);
			}while(cliente[contador].idade  < 18 || cliente[contador].idade > 120);//Fun��o "enquanto", enquanto a condi��o se manter, o que est� acima ser� executado, quando n�o estiver mais na condi��o encerra-se a repeti��o.
			printf("Digite seu email:");
    		scanf("%s", &cliente[contador].email);
    		fflush(stdin);
    		printf("Digite seu endere�o:");
    		fgets(cliente[contador].endereco, 60, stdin);
    		fflush(stdin);
    		printf("Nome: %sIdade: %d \nEmail: %s \nEndere�o: %s", cliente[contador].nome, cliente[contador].idade, cliente[contador].email, cliente[contador].endereco);
    		printf("Seus dados est�o corretos S (sim) ou N (n�o)?\n");
    		scanf("%c", &confirmacaoCadastro);
    		fflush(stdin);
    	}while(confirmacaoCadastro == 'n' || confirmacaoCadastro == 'N');
    }
    
    system("cls");//Comando "system("cls")" para limpar a tela, deixando a janela sem nada.

    printf("Deseja ter acesso ao portif�lio S (sim) ou N (n�o):\n");
    scanf("%c", &opcaoPortifolio);
    fflush(stdin);
    if(opcaoPortifolio == 's' || opcaoPortifolio == 'S'){//Comando "se" para executar algo, se a condi��o declarada entre par�nteses for verdadeira ou falsa, dependendo da condi��o.
    	
		printf("FOTOS:\n");
        printf("id: 0, titulo: %s, pre�o: %.1f\n", tabela[0].tituloFoto, tabela[0].precoFoto);
        printf("id: 1, titulo: %s, pre�o: %.1f\n", tabela[1].tituloFoto, tabela[1].precoFoto);
        printf("id: 2, titulo: %s, pre�o: %.1f\n", tabela[2].tituloFoto, tabela[2].precoFoto);
        printf("id: 3, titulo: %s, pre�o: %.1f\n", tabela[3].tituloFoto, tabela[3].precoFoto);
        printf("id: 4, titulo: %s, pre�o: %.1f\n", tabela[4].tituloFoto, tabela[4].precoFoto);
        printf("id: 5, titulo: %s, pre�o: %.1f\n", tabela[5].tituloFoto, tabela[5].precoFoto);
    	
    	printf("Deseja comprar alguma dessas fotos S (sim) ou N (n�o)?\n");
    	scanf("%c", &opcaoComprar);
    	fflush(stdin);
    	while(opcaoComprar == 's' || opcaoComprar == 'S'){
    		printf("Qual o Id da foto desejada:");
            scanf("%d", &x);
            fflush(stdin);
            printf("Quantos quadros dessa foto voc� deseja:");
            scanf("%d", &carrinho[x].quantidadeFoto);
            fflush(stdin);
            carrinho[x].precoFoto=tabela[x].precoFoto;
            for(contador = 0; contador < 50; contador++){
                if(tabela[x].tituloFoto[contador] == '\n'){
                    contador = 50;//A��o para que se tenha todas as letras do filme.
                    continue;
                }
            	carrinho[x].tituloFoto[contador] = tabela[x].tituloFoto[contador];//Igualando os nomes das fotos do carrinho ao da tabela.
            }
            precoCarrinho += carrinho[x].quantidadeFoto * carrinho[x].precoFoto;//C�digo para a soma dos itens do carrinho.
            printf("Item(s) adicionados ao carrinho com sucesso.\n");
            
 			system("cls");//Comando "system("cls")" para limpar a tela, deixando a janela sem nada.       
            
        	printf("FOTOS:\n");
        	printf("Id: 0, t�tulo: %s, pre�o: %.1f\n", tabela[0].tituloFoto, tabela[0].precoFoto);
        	printf("Id: 1, t�tulo: %s, pre�o: %.1f\n", tabela[1].tituloFoto, tabela[1].precoFoto);
        	printf("Id: 2, t�tulo: %s, pre�o: %.1f\n", tabela[2].tituloFoto, tabela[2].precoFoto);
        	printf("Id: 3, t�tulo: %s, pre�o: %.1f\n", tabela[3].tituloFoto, tabela[3].precoFoto);
        	printf("Id: 4, t�tulo: %s, pre�o: %.1f\n", tabela[4].tituloFoto, tabela[4].precoFoto);
        	printf("Id: 5, t�tulo: %s, pre�o: %.1f\n", tabela[5].tituloFoto, tabela[5].precoFoto);
            
            printf("Deseja adicionar mais algum item em seu carrinho S (sim) ou N (n�o)?\n");
            scanf("%c", &opcaoComprar);
            fflush(stdin);
		}
	}
		
	system("cls");
		
	printf("O pre�o total do carrinho ficou: %d\n", precoCarrinho);
	printf("O pagamento ser� realizado com Paypal.\n");
	printf("Digite seu email do PayPal:");
	scanf("%s", &emailPaypal);
	fflush(stdin);
	printf("Digite sua senha do PayPal:");
	scanf("%s", &senhaPaypal);
	fflush(stdin);
	printf("Sua compra foi aprovada com sucesso!\n");
	printf("Simula��o do prot�tipo finalizada!\n");
		
	system("pause");//Comando "system("pause")" para dar uma pausa no programa, saindo da pausa ao apertar qualquer tecla.
	return 0;//Comando para que o valor do algortimo retorne a zero.
	}
