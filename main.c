#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <limits.h>

typedef struct Data
{
    int frequencia;
    char letra;
} data;

typedef struct Lista
{
    data *dados;
    unsigned char codigo;
    struct Lista *proximo;
} lista;

typedef struct Arvore
{
    data *dados;
    struct Arvore *menor, *maior;
} arvore;

int menu(const char*, const char**, const int);

lista* criarFrequencia(char*);
arvore* criarArvore(lista*);
void criarCodigos(lista*, arvore*, unsigned char);

int main()
{
    char running = 1;
    char* original = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua";
    size_t size = 0;
    lista *letras = NULL;
    arvore *arv = NULL;

    while(running)
    {
        switch(menu("Selecione o que deseja fazer, \"w\" e \"s\" para selecionar.",(const char* []){"Digitar os dados", "Mostrar os dados","Compactar","Mostrar o dado compactado","Descompactar", "Sair"}, 6))
        {
            case 0:
                system("cls");
                free(original);
                original = NULL;
                size = 0;
                getline(&original, &size, stdin);
                break;
            case 1:
                system("cls");
                printf(original);
                getch();
                break;
            case 2:
                letras = criarFrequencia(original);
                arv = criarArvore(letras);
                criarCodigos(letras, arv, 1);
                lista *temp = letras;
                printf("isso mostra o codigo de cada letra ao contrario, 110 eh na verdade 011, so tive tempo de chegar ate aqui.\n");
                while(temp)
                {
                    int n = temp->codigo;
                    printf("%c, ", temp->dados->letra);
                    while(n>1)
                    {
                        if(n & 1) printf("1");
                        else printf("0");
                        n>>=1;
                    }printf("\n");
                    temp = temp->proximo;
                }
                getch();
                break;
            case 3:
                break;
            case 4:
                break;
            default:
                running = 0;
                break;
        }
    }

    free(original);
    return 0;
}

lista* criarFrequencia(char* texto)
{

    lista *l = NULL, *temp;
    char procurando;
    for(int i = 0; texto[i] != '\0'; i++)
    {
        temp = l;
        procurando = 1;
        while(procurando)
        {
            if(!temp) procurando = 0;
            else
            {
                if(temp->dados->letra == texto[i])
                {
                    temp->dados->frequencia++;
                    procurando = 0;
                }
                else temp = temp->proximo;
            }
        }
        if(!temp)
        {
            temp = malloc(sizeof(lista));
            temp->dados = malloc(sizeof(data));
            temp->dados->letra = texto[i];
            temp->dados->frequencia = 1;
            temp->codigo = 0;
            temp->proximo = l;
            l = temp;
        }
    }
    return l;
}

arvore* criarArvore(lista* l)
{
    lista *temp = l;
    int n = 0, n2;
    while(temp)
    {
        temp = temp->proximo;
        n++;
    }
    n2 = n;

    temp = l;
    arvore **folhas = malloc(n*sizeof(arvore*));
    for(int i = 0; i < n; i++)
    {
        folhas[i] = malloc(sizeof(arvore));
        folhas[i]->dados = temp->dados;
        folhas[i]->menor = NULL;
        folhas[i]->maior = NULL;
        temp = temp->proximo;
    }
    arvore *temp2;
    int ip, is, primeiro, segundo;
    while(n2 > 1)
    {
        primeiro = segundo = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            if(folhas[i]->dados->frequencia < primeiro && folhas[i]->dados->frequencia > 0)
            {
                segundo = primeiro;
                primeiro = folhas[i]->dados->frequencia;
                is = ip;
                ip = i;
            }
            if(folhas[i]->dados->frequencia < segundo && folhas[i]->dados->frequencia > primeiro && folhas[i]->dados->frequencia > 0)
            {
                segundo = folhas[i]->dados->frequencia;
                is = i;
            }
        }

        temp2 = folhas[ip];
        folhas[ip] = malloc(sizeof(arvore));
        folhas[ip]->dados = malloc(sizeof(data));
        folhas[ip]->dados->frequencia = temp2->dados->frequencia + folhas[is]->dados->frequencia;
        folhas[ip]->dados->letra = 0;
        folhas[ip]->menor = temp2;
        folhas[ip]->maior = folhas[is];
        folhas[is]->dados->frequencia = 0;

        n2--;
    }

    return folhas[ip];
}

void criarCodigos(lista *l, arvore *a, unsigned char codigo)
{
    if(!(a->menor || a->maior))
    {
        while(l->dados->letra != a->dados->letra) l = l->proximo;
        l->codigo = codigo;
    }else
    {
        if(a->menor) criarCodigos(l, a->menor, codigo<<1);
        if(a->maior) criarCodigos(l, a->maior, (codigo<<1) | 1);
    }
}

int menu(const char* msg, const char** opcoes, const int length)
{
    int selecionada = 0, pressionada = -1;
    do
    {
        if(pressionada == 'w') selecionada--;
        else if(pressionada == 's') selecionada++;

        if(selecionada < 0) selecionada = length-1;
        else if (selecionada > length-1) selecionada = 0;

        system("cls");
        printf(msg);
        for(int i = 0; i < length; i++)
        {
            printf(i == selecionada ? "\n%s<" : "\n%s", opcoes[i]);
        }
        printf("\n");
        pressionada = getch();
    } while(pressionada != 13);
    return selecionada;
}