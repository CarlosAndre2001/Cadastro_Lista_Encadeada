#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;



template <typename T>
struct no {
	T dado;
	no<T>* anterior = nullptr;
	no<T>* proximo = nullptr;
};

template <typename T>

struct lista {

	no<T>* inicio = nullptr;
	no<T>* fim = nullptr;
	int contagem = 0;

};

template <typename T>

void add(lista<T>& lst, T valor) {

	no<T>* novo = new no<T>;
	novo->dado = valor;
	if (lst.contagem == 0) {
		lst.inicio = lst.fim = novo;
	}
	else {
		novo->anterior = lst.fim;
		lst.fim->proximo = novo;
		lst.fim = novo;
	}
	lst.contagem++;
}


template <typename T>

void listar(lista<T>& lst, void(*funcPrint)(T)) {
	no<T>* aux = lst.inicio;
	int id = 0;

	cout << endl;

	while (aux != nullptr) {
		funcPrint(aux->dado);
		aux = aux->proximo;
	}

	cout << endl;
}





template <typename T>

void printInteiro(T valor) {
	cout << valor << endl;
}

/*template <typename T>

void printPessoa(T valor) {
	cout << valor.nome << " :: " << valor.cpf << " :: " << valor.id << " :: " << valor.sexo << endl;
}*/

template <typename T>

void printPessoaIndividual(T valor) {
	cout << valor.nome << " :: " << valor.cpf << " :: " << valor.id << " :: " << valor.sexo << endl;
}



template <typename T>
void trocar(lista<T>& lst, int pos1, int pos2)
{
	no<T>* no1 = get(lst, pos1);
	no<T>* no2 = get(lst, pos2);
	T aux = no1->dado;
	no1->dado = no2->dado;
	no2->dado = aux;
}

template <typename T>
void limpar(lista<T>& lst) {

	while (lst.contagem > 0) {
		no<T>* aux = lst.fim;
		lst.fim = lst.fim->anterior;
		delete aux;
		lst.contagem--;
	}
	lst.inicio = lst.fim = nullptr;
}


template <typename T>

no<T>* get(lista<T>& lst, int pos)
{


	no<T>* aux = lst.inicio;
	for (int i = 0; i < pos; i++)
		aux = aux->proximo;

	return aux;
}



template <typename T>

void organizarBubble(lista<T>& lst, int(*funcComp)(T, T)) {
	bool ordenado = false;

	while (!ordenado) {
		ordenado = true;
		for (int i = 1; i < lst.contagem; i++) {
			no<T>* no1 = get(lst, i - 1);
			no<T>* no2 = get(lst, i);
			if (funcComp(no1->dado, no2->dado) > 0) {
				ordenado = false;
				trocar(lst, i, i - 1);
			}
		}
	}
}

template <typename T>

void listarindividuo(lista<T>& lst, void(*funcPrint)(T), int pos1) {
	int i = -1;
	no<T>* aux = lst.inicio;

	cout << endl;

	while (++i < pos1)aux = aux->proximo;

	funcPrint(aux->dado);

	cout << endl;
}
/*
template <typename T>

void printPessoaIndividual(T valor) {
	cout << valor.nome << " :: " << valor.cpf << " :: " << valor.id << " :: " << valor.sexo << endl;
}*/

void leNum(int* valor) {
	cout << "digite: ";
	while (!(cin >> *valor)) {
		cout << "digite um valor \n";
		cin.clear();
		cin.ignore(123, '\n');
	}
}

template <typename T>

void removedaLista(lista<T>& lst, int pos1) {
	if (pos1 >= lst.contagem) {
		cout << "Posição maior do que a lista" << endl;
		return;
	}
	if (pos1 < 0) {
		cout << "A Lista está vazia" << endl;
		return;
	}

	no<T>* aux = get(lst, pos1);
	(aux->proximo != nullptr) ? aux->proximo->anterior = aux->anterior : lst.fim = aux->anterior;
	(aux->anterior != nullptr) ? aux->anterior->proximo = aux->proximo : lst.inicio = aux->proximo;
	delete aux;
	lst.contagem--;

}
//pra usar o quicksort tive q recorrer a ajuda do gabriel, ele me mostro as fontes de onde pegou as formas de resolver so problemas, então se estiver parecido
// é porque realmete é.


template <typename T>

void trocaNo(no<T>* no1, no<T>* no2) {
	T aux = no1->dado;
	no1->dado = no2->dado;
	no2->dado = aux;
}

template <typename T>

no<T>* particao(no<T>* ini, no<T>* fi) {
	int pivo = fi->dado.id;
	no<T>* aux1 = ini->anterior;

	for (no<T>* aux2 = ini; aux2 != fi; aux2 = aux2->proximo) {
		if (aux2->dado.id <= pivo) {
			aux1 = (aux1 == nullptr) ? ini : aux1->proximo;
			trocaNo(aux1, aux2);
		}
	}
	aux1 = (aux1 == nullptr) ? ini : aux1->proximo;
	trocaNo(aux1, fi);

	return aux1;
}

template <typename T>

void quickSort(no<T>* ini, no<T>* fi) {


	if (fi != nullptr && ini != fi && ini != fi->proximo)
	{
		no<T>* pivo = particao(ini, fi);

		quickSort(ini, pivo->anterior);
		quickSort(pivo->proximo, fi);
	}
}

template <typename T>
no<T>* buscaBinariaRecursiva(no<T>* ini, no<T>* fi, const T& procuraDado, bool procuraNome) {
	if (ini == nullptr || fi == nullptr || ini == fi->proximo)
		return nullptr;

	no<T>* meio = ini;
	int cmp;

	if (procuraNome) {
		cmp = strcasecmp(meio->dado.id) ? 0 : (meio->dado.id < procuraDado.id) ? -1 : 1;

	}
	else
		cmp = (meio->dado.id == procuraDado.id) ? 0 : (meio->dado.id < procuraDado) ? -1 : 1;

	if (cmp == 0)
		return meio;
	else if (cmp < 0)
		return buscaBinariaRecursiva(meio->proximo, fi, procuraDado, procuraNome);
	else
		return buscaBinariaRecursiva(ini, meio->anterior, procuraDado, procuraNome);
}

template<typename T>
no<T>* buscaBinaria(lista<T>& lst, const T& procuraDado, bool procuraNome) {
	no<T>* ini = lst.inicio;
	no<T>* fi = lst.fim;

	return buscaBinariaRecursiva(ini, fi, procuraDado, procuraNome);
}

