
<img 
    style="
        float: left; 
        height: 220px;
        margin-top: 28px;
    "
    align="left"
    height="220"
    src="../../assets/ufop.png" 
/>

### Universidade Federal de Ouro Preto
#### Disciplina: BCC204 - Teoria dos Grafos
##### Professor: Marco Antonio M. Carvalho

<hr/>
<br/>

# Estudo Dirigido - Teoria dos grafos - BCC204

## Algoritmo de Dijkstra 

Dijsktra apresentou em 1959 um algoritmo de rotulação de vértices para encontrar os caminhos mais curtos
de uma origem para todos os demais vértices em grafos com custos positivos nos arcos. Nest estudo dirigido
é pedido ao aluno que implmente ese algoritmo.

### Especificação da Entrada
A primeira linha da entrada contém quatro inteiros n, m b e i, indicando a quantidade de vértices, a quantidade
de arestas/arcos, um valor binário indicando se o grafo é direcionado (valor 1) ou não (valor 0) e um índice do
vértice (enumerados de 1 a n) a partir do qual será executado o algoritmo.
Em seguida haverá m linhas, cada uma contendo três inteiros, indicando o vértice de origem (enumerados
de 1 a n), o vértice de destino e o peso das arestas/arcos.

### Especificação da Saída
Após realizar a busca, impra o vértice de destino, o comprimento dos caminhos mais curtos entre parênteses e 
a estrutura do caminho do vértice i para cada um dos vértices do grafo, usando uma linha para cada destino. 
Cada linha da saida deve ser terminada com '\n'. 

### Exemplo de Entrada

``` shell
5 7 1 1
1 2 2
1 3 6
1 4 7
2 4 3
2 5 6
3 5 1
4 5 5
```

### Exemplo de Saída

``` shell
2 (2): 1 2
3 (6): 1 3
4 (5): 1 2 4
5 (7): 1 3 5
```

### Estrutura do código
O código-fonte deve ser modularizado corretamente em três arquivos: principal.(c, cpp), dijkstra.(h, hpp) 
e dijkstra.(c,cpp). O arquivo principal.(c, cpp) deve apenas invocar as funções e procedimentos definidos 
no arquivo BFS.(h, hpp). A separação das operações em funções e procedimentos está a cargo do aluno, porém, 
não deve haver acúmulo de operações dentro uma mesma função/procedimento. A implementação deve se basear 
*obrigatoriamente** no código da BFS desenvolvido na parte anterior do estudo dirigido.

### Diretivas de Compilação C

``` shell
$ gcc dijkstra.c -c
$ gcc principal.c -c
$ gcc dijkstra.o principal.o -o programa
```
