# Trabalho PAA
A implementação do GGST utilizada para os testes se encontra no repositorio acima, com o nome de 'gabow'.
A implementação do algoritmo de Edmonds foi adaptada para se adequar a mesma interface propósta pelo artigo original, o nome da implementação esta denominado como "Spagheti" (nome do repósitorio de onde o código foi tirado).
Dentro do projeto:
source/arbok/include/arbok/gabow/gabow.h -> GGST
source/arbok/include/arbok/others/spaghetti.h -> Edmonds

1. Compilar o projeto usando os comandos abaixo:

cmake -B build -S . -DCMAKE_BUILD_TYPE=Release
cmake --build build/

2. Para baixar os datasets, basta escolher o dataset desejado encontrado dentro do Makefile (deixamos uma parte do konect pré-baixado para rodar o quickbench).

3. Para utilizar o teste rápido, basta acessar a pasta "Data" e rodar o script:
quick_bench.py

OBS: Esse script irá fazer um teste rápido utilizando uma parte do dataset "konect" já pré-baixado no arquivo.

4. Para os testes reais utilizados no relatório, foi utilizado o script benchmark.py.
4.1. Dentro da pasta benchmark, basta alterar a variável "dirnames" com os datasets desejados para os testes.
OBS: Como padrão, deixamos apenas o dataset antilemon, mas no relatório, utilizamos todos os datasets do Makefile nos testes do relatório.

Os scripts que realizam os testes assim como o download das instâncias se encontram na pasta /data.
Os resultados obtidos descritos no artigo estão na pasta 'results', onde consta um arquivo csv por conjunto de dados.

OBS: Poderá ser necessário instalar a dependência lxml através do PIP:
pip install lxml

Link direto das implementações utilizadas:
GGSTS: https://github.com/chistopher/arbok/tree/master/source/arbok/src/gabow
Edmonds: https://github.com/spaghetti-source/algorithm/blob/master/graph/arborescence2.cc