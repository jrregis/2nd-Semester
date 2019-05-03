T2 Lab2 - Campeonato de Futebol

- O jogo foi desenvolvido no sistema operacional Ubuntu e compilado no GCC;
- Foram utlizadas bibliotecas especificas para o sistema operacional utilizado.

Requisitos do trabalho: 
1 - Os dados devem ser armazenados em listas em memória (não será usado acesso a BD neste trabalho).
Obs.: Para facilitar os testes, podem ser criadas várias listas no main, antes de iniciar o programa.
2 - Deve ser possível cadastrar times, treinadores, jogadores, rodadas e partidas. Cada cadastro deve possibilitar inclusão, exclusão e busca.
3 - Deve ser possível montar as escalações dos times de cada jogo.
4 - Deve ser possível narrar as partidas textualmente, informando o minuto e o lance e gravando informações relativas à gols, cartões amarelos,
vermelhos, faltas e substituições.
5 - Um time não pode ter mais de 25 jogadores relacionados.
6 - Cada time deve ter os ao menos seguintes dados: nome, estádio, cidade, data de fundacao.
7 - Cada treinador deve ter ao menos os seguintes dados: nome.
8 - Cada jogador deve ter ao menos os seguintes dados: nome, posicao, idade, nr camisa.
9 - Deve ser possível gerar um relatório contendo a classificação geral dos clubes, de acordo com as informações das partidas narradas.
10 - Deve ser possível gerar relatórios de artilharia, contendo uma lista ordenada de jogadores e seus respectivos gols.
11 - Deve ser possível gerar um relatório de estatísticas, com as seguintes informações (por time): gols feitos, gols sofridos, cartões amarelos,
cartões vermelhos e faltas cometidas.
12 - Deve ser possível gerar um relatório de estatísticas, com as seguintes informações (por jogador): gols feitos, cartões amarelos,
cartões vermelhos e faltas cometidas.

O que foi feito:
1 - Foram utilizadas listas genéricas.
2 - Times, jogadores, trinadores, rodadas, partidas são inclusos em suas respectivas listas, podendo ser posteriormente buscados e deletados.
3 - Ao narrar as partidas primeiramente é solicitado os times da partida e é feita a relação e escalação dos jogadores da partida.
As partidas são incluidas na sua respectiva lista ao encerrar a narração da partida.
4 - Ao narrar a partida podem ser marcados gols, faltas, cartões e substituições. Dados que são guardados no nó da partida em sua lista.
5 - Para cada partida o limite de jogadores relacionados é 25, e para escalar limitei como 5 para um campeonato de futebol de salão,
podendo facilmente ser modificado para futebol campo colocando 11.
6 - Os times possuem os dados solicitados e outros.
7 - Os treinadores possuem dados solicitados e outros.
8 - Os jogadores possuem os dados solicitados e outros.
9 - É gerado um relatório mostrando a classificação do campeonato baseado nos resultados das partidas narradas.
10 - É gerado um relatório de artilharia do campeonato baseado nos gols marcados nas partida narradas.
11 - É gerado um relatório de estatísticas de gols, cartões, faltas, por time baseado nas partidas narradas.
12 - é gerado um relatório de estatísticas de gols, cartões, faltas, por jogador baseado nas partidas narradas.
Os dados das narraçoes relativos a gols, cartões e falatas são salvos na lista de times e na lista de jogadores para a geração dos relatórios.

Compilação e execução:
- Abrir a pasta onde estão todos os arquivos do programa.
no terminal e executar os comandos abaixo:

$ gcc *.c
$ ./a.out


Régis dos Santos Jr.(201721760)