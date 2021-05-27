#include<stdio.h>//Biblioteca responsável pelo uso do printf e do scanf.
#include<string.h>//Biblioteca para ler strings, strlen e stromp: http://linguagemc.com.br/a-biblioteca-string-h/
#include<stdlib.h>//Biblioteca para o uso do comando system("pause").
#include<ctype.h>//Biblioteca para o uso do toupper e tolower: http://linguagemc.com.br/ctype-h-toupper-tolower-isalpha-isdigit-em-c/
#include<locale.h>//Biblioteca para uso de acentuação dentro do printf. 

typedef struct{//Função struct onde definem tipos de dados que agrupam variáveis sob um mesmo tipo de dado. 
  char tituloFoto[50];
  float precoFoto;
  int quantidadeFoto;
}foto;//Novo tipo de dado.

typedef struct{
    char nome[50], endereco[100], email[50];
    int idade;
}pessoa;//Novo tipo de dado.

int main(){//Função main serve como o ponto de partida para a execução do programa.
    setlocale(LC_ALL, "Portuguese");//Direciona a biblioteca ao idioma que vai ser usado pelo <locale.h>.
    char opcaoPortifolio, opcaoFotos[10], nomeCliente[50], emailCliente[30], opcaoComprar, confirmacaoCadastro; 
    char emailPaypal[50], senhaPaypal[50];//Comando para declarar as variáveis e armazenar no espaço da memória, do tipo caractere.    
    int contador, album, fotosEscolhidas, x;//Comando para declarar as variáveis e armazenar no espaço da memória, do tipo inteiro.
    int numCliente, precoCarrinho=0;
    foto carrinho[10], tabela[10];//Declaração das váriaveis do tipo struct, criados a cima.
    
    tabela[0].precoFoto = 350;//Fazer com que o preço da foto 0 da tabela receba esse preço.
	    strcpy(tabela[0].tituloFoto, "Os Shelbys");//Uma string que faz o que está escrito a direita, seja o que foi declarado a esquerda.
    tabela[1].precoFoto = 250;
		strcpy(tabela[1].tituloFoto, "Relíquias da Morte");
    tabela[2].precoFoto = 250;
		strcpy(tabela[2].tituloFoto, "Invincible");
    tabela[3].precoFoto = 400;
		strcpy(tabela[3].tituloFoto, "The boys");
    tabela[4].precoFoto = 300;
		strcpy(tabela[4].tituloFoto, "Lucille");
    tabela[5].precoFoto = 350;
		strcpy(tabela[5].tituloFoto, "Bella Ciao");
    
    printf("----------------------------------------Bem vindo ao Protótipo do Portifólio!--------------------------------------------\n");//Comando que printa na tela o que foi escrito dentro dos parênteses, para o usuário.
    
    printf("Quantas pessoas desejam se cadastrar?\n");//Comando que printa na tela o que foi escrito dentro dos parênteses, para o usuário.
    scanf("%d", &numCliente);//Comando que salva as variáveis na memória onde foi declarado pelo int e char.
    fflush(stdin);//Comando para limpar o buffer de memória.
    pessoa cliente[numCliente];//Variável do novo tipo de dado.

    for(contador=0;contador<numCliente;contador++){// Função "para", é utilizada para um número específivo de repetições, diferente do "faça" ou "faça enquanto".
    	do{//Função "faça enquanto" onde se repete algo ate que a condição se torne falsa e obrigatoriamente deve ser realizado uma vez..
			printf("Precisaremos de seu cadastro para futuras operações dentro do site.\n");
    		printf("Digite seu nome completo:");
    		fgets(cliente[contador].nome, 50, stdin);//Comando para salvar uma variável na memória, é como o scanf, mas ele consegue salvar os espaços entre nomes, conseguindo dar mais nomes. 
    		fflush(stdin);
    		do{
    			printf("Digite sua idade (deve ser maior de 18 para se cadastrar): ");
    			scanf("%d", &cliente[contador].idade);
   				fflush(stdin);
			}while(cliente[contador].idade  < 18 || cliente[contador].idade > 120);//Função "enquanto", enquanto a condição se manter, o que está acima será executado, quando não estiver mais na condição encerra-se a repetição.
			printf("Digite seu email:");
    		scanf("%s", &cliente[contador].email);
    		fflush(stdin);
    		printf("Digite seu endereço:");
    		fgets(cliente[contador].endereco, 60, stdin);
    		fflush(stdin);
    		printf("Nome: %sIdade: %d \nEmail: %s \nEndereço: %s", cliente[contador].nome, cliente[contador].idade, cliente[contador].email, cliente[contador].endereco);
    		printf("Seus dados estão corretos S (sim) ou N (não)?\n");
    		scanf("%c", &confirmacaoCadastro);
    		fflush(stdin);
    	}while(confirmacaoCadastro == 'n' || confirmacaoCadastro == 'N');
    }
    
    system("cls");//Comando "system("cls")" para limpar a tela, deixando a janela sem nada.

    printf("Deseja ter acesso ao portifólio S (sim) ou N (não):\n");
    scanf("%c", &opcaoPortifolio);
    fflush(stdin);
    if(opcaoPortifolio == 's' || opcaoPortifolio == 'S'){//Comando "se" para executar algo, se a condição declarada entre parênteses for verdadeira ou falsa, dependendo da condição.
    	
		printf("FOTOS:\n");
        printf("id: 0, titulo: %s, preço: %.1f\n", tabela[0].tituloFoto, tabela[0].precoFoto);
        printf("id: 1, titulo: %s, preço: %.1f\n", tabela[1].tituloFoto, tabela[1].precoFoto);
        printf("id: 2, titulo: %s, preço: %.1f\n", tabela[2].tituloFoto, tabela[2].precoFoto);
        printf("id: 3, titulo: %s, preço: %.1f\n", tabela[3].tituloFoto, tabela[3].precoFoto);
        printf("id: 4, titulo: %s, preço: %.1f\n", tabela[4].tituloFoto, tabela[4].precoFoto);
        printf("id: 5, titulo: %s, preço: %.1f\n", tabela[5].tituloFoto, tabela[5].precoFoto);
    	
    	printf("Deseja comprar alguma dessas fotos S (sim) ou N (não)?\n");
    	scanf("%c", &opcaoComprar);
    	fflush(stdin);
    	while(opcaoComprar == 's' || opcaoComprar == 'S'){
    		printf("Qual o Id da foto desejada:");
            scanf("%d", &x);
            fflush(stdin);
            printf("Quantos quadros dessa foto você deseja:");
            scanf("%d", &carrinho[x].quantidadeFoto);
            fflush(stdin);
            carrinho[x].precoFoto=tabela[x].precoFoto;
            for(contador = 0; contador < 50; contador++){
                if(tabela[x].tituloFoto[contador] == '\n'){
                    contador = 50;//Ação para que se tenha todas as letras do filme.
                    continue;
                }
            	carrinho[x].tituloFoto[contador] = tabela[x].tituloFoto[contador];//Igualando os nomes das fotos do carrinho ao da tabela.
            }
            precoCarrinho += carrinho[x].quantidadeFoto * carrinho[x].precoFoto;//Código para a soma dos itens do carrinho.
            printf("Item(s) adicionados ao carrinho com sucesso.\n");
            
 			system("cls");//Comando "system("cls")" para limpar a tela, deixando a janela sem nada.       
            
        	printf("FOTOS:\n");
        	printf("Id: 0, título: %s, preço: %.1f\n", tabela[0].tituloFoto, tabela[0].precoFoto);
        	printf("Id: 1, título: %s, preço: %.1f\n", tabela[1].tituloFoto, tabela[1].precoFoto);
        	printf("Id: 2, título: %s, preço: %.1f\n", tabela[2].tituloFoto, tabela[2].precoFoto);
        	printf("Id: 3, título: %s, preço: %.1f\n", tabela[3].tituloFoto, tabela[3].precoFoto);
        	printf("Id: 4, título: %s, preço: %.1f\n", tabela[4].tituloFoto, tabela[4].precoFoto);
        	printf("Id: 5, título: %s, preço: %.1f\n", tabela[5].tituloFoto, tabela[5].precoFoto);
            
            printf("Deseja adicionar mais algum item em seu carrinho S (sim) ou N (não)?\n");
            scanf("%c", &opcaoComprar);
            fflush(stdin);
		}
	}
		
	system("cls");
		
	printf("O preço total do carrinho ficou: %d\n", precoCarrinho);
	printf("O pagamento será realizado com Paypal.\n");
	printf("Digite seu email do PayPal:");
	scanf("%s", &emailPaypal);
	fflush(stdin);
	printf("Digite sua senha do PayPal:");
	scanf("%s", &senhaPaypal);
	fflush(stdin);
	printf("Sua compra foi aprovada com sucesso!\n");
	printf("Simulação do protótipo finalizada!\n");
		
	system("pause");//Comando "system("pause")" para dar uma pausa no programa, saindo da pausa ao apertar qualquer tecla.
	return 0;//Comando para que o valor do algortimo retorne a zero.
	}
