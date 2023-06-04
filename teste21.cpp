
#include <iostream>
#include "../teste21/Processos/Processos.h"
#include "Perfil/Prototipo.h"

using namespace std;

int main()
{
	lista<Cadastro> cadastros;

	leCadastros(cadastros);

	mostrarTodosCadastros(cadastros);

	removedaLista(cadastros, 0);

	mostrarTodosCadastros(cadastros);

    listaumaPessoa(cadastros);
   
	limpar(cadastros);

	

	return 0;
}
