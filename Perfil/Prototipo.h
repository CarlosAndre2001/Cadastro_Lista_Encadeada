#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<fstream>

using namespace std;

#define TAM 100
#define LOCAL "Infos/Alunos.csv"

struct Cadastro {
	int id;
	char nome[TAM];
	int cpf;
	char sexo[TAM];
};

void printPessoa(const Cadastro cadastro) {
	//cout << valor.nome << " :: " << valor.cpf << " :: " << valor.id << " :: " << valor.sexo << endl;
	cout << endl;
	cout << "====================================" << endl;
	cout << endl;
	cout << "Nome   :: " << cadastro.nome << endl;
	cout << "CPF    :: " << cadastro.cpf << endl;
	cout << "Codigo :: " << cadastro.id << endl;
	cout << "Sexo   :: " << cadastro.sexo << endl;
	cout << "====================================" << endl;
	cout << endl;
}

void printRemoveLista(const Cadastro cadastro) {
	cout << cadastro.nome << endl;
}

int procuraChar(char letra, int posicao, char* linha) {
	int posatual = posicao;
	while (linha[posatual] != letra) {
		posatual++;
	}
	return posatual;
}

void leCadastros(lista<Cadastro>& lst) {
	FILE* fptr;

	fptr = fopen(LOCAL, "r");

	if (fptr == NULL) {
		cout << "Não foi possivel localizar a sua pasta";
		fclose(fptr);
		return;
	}

	char str[TAM];
	while (fgets(str, TAM, fptr))
	{
		Cadastro atual;
		char temp[TAM];
		
		
		memset(temp, 0, TAM);
		int pos = procuraChar(';', 0, str);
		strncpy(temp, str, pos);
		atual.id = atoi(temp);

		
		memset(temp, 0, TAM);
		int pos_old = ++pos;
		pos = procuraChar(';', pos, str);
		strncpy(temp, str + pos_old, pos - pos_old);
		strcpy(atual.nome, temp);

		memset(temp, 0, TAM);
		pos = procuraChar(';', pos, str);
		strcpy(temp, pos + str + 5);
		strcpy(atual.sexo, temp);

		memset(temp, 0, TAM);
		strcpy(temp, str + pos + 1);
		atual.cpf = atoi(temp);

		add(lst, atual);
	}
	fclose(fptr);
}

void mostrarTodosCadastros(lista<Cadastro>& lst)
{
	quickSort(lst.inicio, lst.fim);
	listar(lst, printPessoa);
}


int comparaPessoaNome(const Cadastro p1, const Cadastro p2) {
	return strcmp(p1.nome, p2.nome);
}

void printCadastro(const Cadastro cadastro) {
	cout << cadastro.nome << endl;
}

void listaumaPessoa(lista<Cadastro>& lst) {
	int temp;
	quickSort(lst.inicio, lst.fim);
	listar(lst, printCadastro);
	cout << "Deseja ver o dado de Qual cadastro?:" << endl;
	leNum(&temp);
	removedaLista(lst, temp+2);
	no<Cadastro> *aux = get(lst, temp);
	printPessoa((aux->dado));
	cin.ignore();
}




