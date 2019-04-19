T1 Lab2 - Campo Minado

- O jogo foi desenvolvido no sistema operacional Ubuntu e compilado no GCC;
- Foram utlizadas bibliotecas especificas para o sistema operacional utilizado.

Requistos PDF:
1 - Deve ser usada alocação dinâmica para a(s) matriz(es).
2 - O programa deve ser organizado em diferentes arquivos e funções, se ne-
cessário.
3 - O usuário escolhe a dimensão da matriz e o número de bombas.
4 - Deve ser contado o tempo decorrido desde o inı́cio do jogo.
5 - Deve haver uma opção na qual o computador tenta resolver o jogo (de
maneira inteligente, não simplesmente aleatória).

O que foi feito:
1 - A matriz foi alocada dinâmicamente com um vetor de ponteiros;
2 - O programa é organizado no main.c, board.c e board.h;
3 - O usuario entra com o tamanho do tabuleiro e o numero de bombas. Os mesmos são validados
pelo sistema. O tabuleiro não pode ser menor que 4x4 e o numero de bombas não pode ultrapassar
o numero de linhas*colunas-1;
4 - Ao final do jogo é exibido o tempo decorrido desde o momento que o usuario começa a jogar,
não contando o tempo de configuração do jogo;
5 - O computador resolve o jogo por meio de força bruta, não consegui desenvolver um algoritmo inteligente.

Compilação e execução:
- Abrir a pasta onde estão todos os arquivos do jogo(main.c ; board.c ; board.h) 
no terminal e executar os comandos abaixo:

$ gcc *.c
$ ./a.out


Régis dos Santos Jr.(201721760)
