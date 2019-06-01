                                                T3 LAB II - SISTEMA DE CADASTRO DE CARRROS
Régis dos Santos Jr. - 201721760
Sistemas de Informação

Requisitos do Trabalho:
1. A lista deve ser ordenada fisicamente pela placa dos carros.
2. Deve ser possivel incluir e excluir carros na lista.
3. Deve ser mantida em memória uma árvore binária relativa à placa dos carros.
4. Deve ser mantida em memória uma árvore binária cujo percurso seja equivalente à lista ordenada pelo marca.
5. Deve ser mantida em memória uma árvore binária cujo percurso seja equivalente à lista ordenada pela ano.
6. Deve ser possível buscar carros pela placa, usando a árvore binária auxiliar.
7. Deve ser possivel listar os carros ordenadamente pela placa, percorrendo a lista.
8. Deve ser possivel listar os carros ordenadamente pelo marca, através da árvore auxiliar.
9. Deve ser possivel listar os carros ordenadamente pela ano, através da árvore auxiliar.

O que foi feito:
Todos os Requisitos foram cumpridos.

*As arvores criadas são do tipo Arvores Binarias de Busca(ABB), e os percursos utilizados são simétricos.
*Crio as AABs na main, manipulo elas nas funções e são liberadas somente quando o usuario decide sair do sistema.
*O sistema foi feito para interação com o usuario, utilizando menus para navegação e assim escolhendo as operações.
*Para questões de testes criei 10 carros na main e já os insiro nas AABs e na LSE_CARROS, também deixei comentado um trecho de codigo para
testes rápidos sem precisar usar os menus.

SO: Ubuntu 18.04.2 LTS
Compilação: GCC.

Compilação e execução:
- Abrir a pasta onde estão todos os arquivos do programa no terminal e executar os comandos abaixo:
$ gcc *.c
$ ./a.out