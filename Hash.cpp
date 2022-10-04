#include <iostream>
#include <string>
#include <conio.h>

//a estrutura de dados aluno
typedef struct Aluno
{
	int matricula;
	std::string nome;
} aluno;

//menu, msg � a frase inicial, opcoes � um vetor das op��es a se escolher e � necessario mandar seu tamanho
int Menu(const std::string& msg, std::string* opcoes, int tamanho)
{
	//inicializa a variavel para 0
    int escolhido = 0;
    //isso armazenar� qual foi a tecla precionada
    char pressionado;
    do
    {
    	//limpa a tela
        system("cls");
        
        //verifica se w ou s foram precionados, e dependendo aumenta ou diminui a variavel escolhido
        if(pressionado == 'w') escolhido--;
        else if(pressionado == 's') escolhido++;

		//escolhido s�o as op��es, ent�o deve ser limitado ao tamanho do vetor
        if(escolhido > tamanho - 1) escolhido = 0;
        else if (escolhido < 0) escolhido = tamanho - 1;

		//imprime a msg inicial
        std::cout << msg << std::endl;
        //imprime as op��es
        for(int i = 0; i < tamanho; i++)
        {
        	//para cada op��o ele verifica se � o escolhido antes de imprimir, caso seja ele coloca um < do lado
            std::cout << opcoes[i] << (i == escolhido ? "<\n":"\n");
        }
        //pega a tecla que o usu�rio pressionou e armazena
        pressionado = getch();
        //verifica se pressionado � o enter, esse 13 � o codigo do enter
    } while (pressionado != 13);
    //caso seja enter ele retorna o numero do escolhido, caso n ele volta ao come�o
    return escolhido;
}

//coloca todos as matriculas da tabela em -1
void Inicializar(aluno* tabela)
{
	for(int i = 0; i < 100; i++)
	{
		tabela[i].matricula = -1;
	}
}

//devolve o resto de matricula dividido por 100
int CalcularPosicao(int matricula)
{
	return matricula % 100;
}

int main()
{
	//a tabela hash
	aluno tabela[100];
	//variavel de controle
	bool running = true;
	
	//inicializar a tabela
	Inicializar(tabela);
	
	do
	{
		//limpa  atela
		system("cls");
		//o vetor das op��es
		std::string opcoes[] = {"Incluir", "Achar Aluno", "Mostrar", "Sair"};
		//como menu retorna um int ele pode ser colocado no switch
		//os parametros s�o a msg inicial, o vetor de op��es e o tamanho
		//para achar o tamanho pega o tamanho do vetor "sizeof(opcoes)" mas isso retorna em bytes
		//ent�o divide-se pelo tamanho da primeira op��o em bytes "sizeof(opcoes[0])"
		//o resultado � quantas opcoes tem;
		//tipo isso 16/4 = 4 ent�o num vetor de tamanho 16 com coisas de tamanho 4 tem 4 delas no vetor
		switch(Menu("Escolha o que fazer.", opcoes, sizeof(opcoes)/sizeof(opcoes[0])))
		{
			case 0:
				//essas chaves s�o para pode criar uma variavel dentro do switch
				{
					//limpa tela
					system("cls");
					//cria a variavel temporaria
					aluno novo;
					//pede os valores
					std::cout << "Digite a matricula e o nome" << std::endl;
					//armazena no aluno temporario
					std::cin >> novo.matricula >> novo.nome;
					//calcula o index do aluno na tabela e insere o temporario na posi��o
					int posicao = CalcularPosicao(novo.matricula);
					//enquanto a matricula da posi��o encontrada n estiver livre
					while(tabela[posicao].matricula != -1)
					{
						//ele aumenta a posi��o por 1 caso seja menor que 100
						if(posicao < 100)
							posicao++;
						else
						//caso tenha passado de 100 ele volta pro 0
							posicao = 0;
					}
					//coloca a matricula como a nova posi��o
					novo.matricula = posicao;
					//depois de encontrar uma posi��o livre ele armazena
					tabela[posicao] = novo;
					//feedback de sucesso
					std::cout << "Aluno adicionado." << std::endl;
					break;
				}
			case 1:
				{
					//limpa tela
					system("cls");
					//variavel temporaria
					int matricula;
					//pede a matricula
					std::cout << "Qual a matricula do aluno?" << std::endl;
					//armazena
					std::cin >> matricula;
					//retorna o nome que o aluno da posi��o dessa matricula tem
					std::cout << "O nome do aluno de matricula " << matricula << " e "<< tabela[CalcularPosicao(matricula)].nome << std::endl;
					break;
				}
			case 2:
				//limpa tela
				system("cls");
				for(int i = 0; i < 100; i++)
					//verifica se o aluno na posi��o existe
					if(tabela[i].matricula != -1)
						//se existe imprime os dados
						std::cout << "Matricula: " << tabela[i].matricula << " Nome: " << tabela[i].nome << std::endl;
				break;
			case 3:
				//caso queira sair a variavel de controle vira falso
				running = false;
				break;
		}
		//se ainda estiver rodando ele espera pelo precionamento de uma tecla
		if(running) getch();
		//se ainda estiver rodando ele volta pro come�o, se n o programa acaba
	} while(running);
	
	
}
