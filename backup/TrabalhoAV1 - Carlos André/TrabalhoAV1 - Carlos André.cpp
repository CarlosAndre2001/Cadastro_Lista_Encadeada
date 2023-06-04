
#include <iostream>
#include "..\Processos\Processos.h"
#include <stdlib.h>
#include <string.h>
#include <fstream>






using namespace std;



int comparaInteiro(int a, int b) {
	return a - b;
}




int main()
{
	lista<int> lista1;
	add(lista1, 10);
	add(lista1, 11);
	add(lista1, 17);
	add(lista1, 14);

	organizarBubble(lista1, comparaInteiro);

	listar(lista1, printInteiro);
	
	limpar(lista1);

	lista<cadastro> lista2;
	add(lista2,{"carlos", 195, 4, 'm'});
	add(lista2, { "andre", 196, 3, 's' });
	add(lista2, { "dias", 197, 2, 's' });
	add(lista2, { "maximiano", 198, 1, 'm' });
	add(lista2, { "silva", 199, 0, 'm' });

	
	//organizarBubble(lista2, comparaPessoaNome);
	quickSort(lista2.inicio, lista2.fim );
	

	//trocar(lista2, 1, 4);

	

	listar(lista2, printPessoa);

	listarindividuo(lista2, printPessoaIndividual, 4);

    removedaLista(lista2, 3);

	listar(lista2, printPessoa);


	//quick_sort(lista2.inicio, lista2.fim);

	//listar(lista2, printPessoa);

	limpar(lista2);


}

