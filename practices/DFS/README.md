
<img 
    style="
        float: left; 
        height: 220px;
        margin-top: 28px;
    "
    align="left"
    height="220"
    src="../assets/ufop.png" 
/>

### Universidade Federal de Ouro Preto
#### Disciplina: BCC206 - Teoria dos Grafos
##### Professor: Marco Antonio M. Carvalho

<hr/>
<br/>

# Estudo Dirigido - Teoria dos grafos - BCC204

## Busca em Profundidade

De modo geral, pode-se dizer que o projeto de bons algoritmos para a determinação de estruturas ou propriedades dos grafos depende do domínio de técnicas que permitam examinar com eficiência vértices e arestas. A
esse tipo de procedimento denomina-se, genericamente, “busca em grafos” ou “percurso em grafos”.
Neste estudo dirigido é pedido ao aluno que implemente um dos algoritmos de percurso mais populares para
grafos: a Busca em Profundidade. A implementação deve utilizar uma ****matriz de adjacências* como representação
computacional.

### Especificação da Entrada
A primeira linha da entrada contém quatro inteiros n, m b e i, indicando a quantidade de vértices, a quantidade
de arestas/arcos, um valor binário indicando se o grafo é direcionado (valor 1) ou não (valor 0) e um índice do
vértice (enumerados de 1 a n) a partir do qual será realizada a busca.
Em seguida haverá m linhas, cada uma contendo três inteiros, indicando o vértice de origem (enumerados
de 1 a n), o vértice de destino e o peso das arestas/arcos.

### Especificação da Saída
Após realizar a busca, indique a ordem de visitação dos vértices a partir do vértice i, um vértice por linha. Por
padronização, os vizinhos de um vértice qualquer devem ser explorados em ordem crescente de índice. No
caso de grafos desconectados, não é necessário reiniciar a busca. Cada linha da saída deve ser terminada com
’\n’.

### Exemplo de Entrada

``` shell
4 6 0 1
1 2 1
1 3 1
1 4 1
2 3 1
2 4 1
3 4 1
```

### Exemplo de Saída

``` shell
1
2
3
4
```

### Estrutura do código
O código-fonte deve ser modularizado corretamente em três arquivos: principal.(c, cpp), DFS.(h, hpp) e DFS.(c,
cp). O arquivo principal.(c, cpp) deve apenas invocar as funções e procedimentos definidos no arquivo DFS.(h,
hpp). A separação das operações em funções e procedimentos está a cargo do aluno, porém, não deve haver
acúmulo de operações dentro uma mesma função/procedimento.

### Diretivas de Compilação C

``` shell
$ gcc DFS.c -c
$ gcc principal.c -c
$ gcc DFS.o principal.o -o programa
```
