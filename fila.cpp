#include <iostream>
#include <string>
#include <conio.h>
#define MaxTamanho 5

typedef struct
{
    int tamanho;
    int item[MaxTamanho];
}fila;

int Menu(const std::string& msg, std::string* opcoes, int tamanho)
{
    int escolhido = 0;
    char pressionado;
    do
    {
        system("cls");
        if(pressionado == 'w') escolhido--;
        else if(pressionado == 's') escolhido++;

        if(escolhido > tamanho - 1) escolhido = 0;
        else if (escolhido < 0) escolhido = tamanho - 1;

        std::cout << msg << std::endl;
        for(int i = 0; i < tamanho; i++)
        {
            std::cout << opcoes[i] << (i == escolhido ? "<\n":"\n");
        }
        pressionado = getch();
    } while (pressionado != 13);
    return escolhido;
}

bool FilaCheia(fila &f)
{
    return (f.tamanho == MaxTamanho);
}

bool FilaVazia(fila &f)
{
    return (f.tamanho == 0);
}

void Inicializar(fila &f)
{
    f.tamanho = 0;
}

void Adicionar(fila &f)
{
    system("cls");
    int temp;
    if(FilaCheia(f))
    {
        std::cout << "fila cheia" << std::endl;
    } else {
        std::cout << "Insira o numero a adicionar: ";
        std::cin >> temp;
        f.item[f.tamanho] = temp;
        f.tamanho++;
    }
}

void Remover(fila &f)
{
    system("cls");
    if(FilaVazia(f))
    {
        std::cout << "Fila vazia";
    } else {
        int item = f.item[0];
        for(int i = 1; i < f.tamanho; i++)
        {
            f.item[i-1] = f.item[i];
        }
        f.tamanho--;
        std::cout << item << " removido";
    }
}

void Listar(fila &f)
{
    system("cls");
    if(FilaVazia(f))
    {
        std::cout << "Fila vazia";
    } else {
        for(int i = 0; i < f.tamanho; i++)
        {
            std::cout << f.item[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main()
{
    fila f;
    Inicializar(f);

    std::string opcoes[] = {"Adicionar item","Remover item","Listar fila","Sair"};
    bool b = true;
    do
    {

        switch(Menu("Escolha o que fazer:", opcoes, 4))
        {
        case 0:
            Adicionar(f);
            break;
        case 1:
            Remover(f);
            break;
        case 2:
            Listar(f);
            break;
        case 3:
            b = false;
            break;
        }
        if(b) getch();
    } while(b);

    return 0;
}
