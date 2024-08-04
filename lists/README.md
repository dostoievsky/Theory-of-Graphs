<img 
    style="
        float: left; 
        height: 180px;
        margin-top: 28px;
    "
    align="left"
    src="../assets/ufop.png" 
/>

### Universidade Federal de Ouro Preto
#### Disciplina: BCC206 - Teoria dos Grafos
##### Professor: Marco Antonio M. Carvalho

<hr/>
<br/>

1.  Um escultor deseja criar uma escultura que represente a paz mundial. 
    Para isto, ele esculpirá 7 pilares (um para cada continente) e os 
    colocará em um círculo. Depois, ele esticará um fio de ouro entre os 
    pilares, de forma que, cada pilar estará conectado a 3 outros pilares.
    Embora a idéia seja boa, a escultura é impossível.
    Porquê?

Teorema do Aperto de Mãos:

```math
\displaystyle\sum_{i=1}^n d(i) = 2m
```

**O numero de vértices de grau impar em um GND é par.**

Ou seja este grafo deve ter ter grau par mas seu grau é 3*7 = 21

<hr/>

```mermaid
graph TB;
subgraph "(1)"
1((1)); 2((2)); 3((3));
4((4)); 5((5)); 6((6));
7((7)); 8((8)); 9((9));
10((10)); 11((11)); 12((12)); 
13((13)); 14((14)); 15((15)); 

1 --- 2 & 3 & 4;
2 --- 3 & 4 & 7;
3 --- 5 & 7;
4 --- 8 & 9;
5 --- 6;
6 --- 7 & 10;
7 --- 8 & 11 & 12;
8 --- 9 & 12;
10 --- 11 & 13;
11 --- 12 & 14;
12 --- 15; 
13 --- 14;
14 --- 15;
end
```

```mermaid
graph TB;
subgraph "(2)"
1((1)); 2((2)); 3((3));
4((4)); 5((5)); 6((6));
1 --- 2 & 4 & 6;
2 --- 3 & 5;
3 --- 4 & 5;
end
```

```mermaid
graph TB;
subgraph "(3)"
1((1)); 2((2)); 3((3));
4((4)); 5((5)); 6((6));
7((7)); 
1 --- 3 --- 4 --- 5 --- 6 --- 2
7 --- 1 & 2 & 3 & 5 & 6;
end
```

2.  Para os três grafos da figura acima, determine o fecho trasitivo do 
    vértice 1.

```math
f(1) = {2,3,4,5,6,7,8,9,10,11,12,13,14,15}
```

```math
f(1) = {2,3,4,5,6}
```

```math
f(1) = {2,3,4,5,6,7}
```
<hr/>

3.  Para os três grafos da figura acima, determine k(G).

```math
\kappa(K_{(n)})  n - 1
```

```math
\kappa(G)  \leq  n − 2  \forall  G {=}\mathllap{/\,}  K_{(n)}
```

```math
\kappa(G) = 2
```

```math
\kappa(G) = 1
```

```math
\kappa(G) = 1 
```

<hr/>

4.  Para os três grafos da figura acima, determine $\delta(G)$.

```math
\kappa(G)  \leq \delta(G)^a
```

```math
\delta(G) = 2  
```

```math
\delta(G) = 1
```

```math
\delta(G)  = 2 
```

<hr/>

5.  Para os três grafos da figura acima, determine o grafo complemento.


```mermaid
graph TB;
subgraph "(1)"
1((1)); 2((2)); 3((3));
4((4)); 5((5)); 6((6));
7((7)); 8((8)); 9((9));
10((10)); 11((11)); 12((12)); 
13((13)); 14((14)); 15((15)); 

1 --- 5 & 6 & 7 & 8 & 9 & 10 & 11 & 12 & 13 & 14 & 15;
2 --- 5 & 6 & 8 & 9 & 10 & 11 & 12 & 13 & 14 & 15;
3 --- 4 & 6 & 8 & 9 & 10 & 11 & 12 & 13 & 14 & 15;
4 --- 5 & 6 & 7 & 10 & 11 & 12 & 13 & 14 & 15;
5 --- 7 & 8 & 9 & 11 & 12 & 13 & 14 & 15;
6 --- 8 & 9 & 11 & 12 & 13 & 14 & 15;
7 --- 9 & 10 & 13 & 14 & 15;
8 --- 10 & 11 & 13 & 14 & 15;
9 --- 10 & 11 & 13 & 14 & 15;
10 --- 12 & 15;
11 --- 13 & 15;
12 --- 13 & 14;
13 --- 15;
14 --- 15;
end
```

```mermaid
graph TB;
subgraph "(2)"
1((1)); 2((2)); 3((3));
4((4)); 5((5)); 6((6));
1 --- 3 & 5;
2 --- 4 & 6;
3 --- 6;
end
```

```mermaid
graph TB;
subgraph "(3)"
1((1)); 2((2)); 3((3));
4((4)); 5((5)); 6((6));
7((7)); 
1 --- 2 & 4 & 5 & 6;
2 --- 3 & 4 & 6;
3 --- 5 & 6;
4 --- 7;
end
```

<hr/>

6.  Forneça um exemplo, se existir, de um grafo bipartido e regular.

```mermaid
graph TB;
subgraph "(1)"
A(( )); B(( )); 
C(( )); D(( )); 

A --- B;
B --- C 
C --- D;
D --- A;

style A fill:#0000FF
style B fill:#FF0000
style C fill:#0000FF
style D fill:#FF0000

end
```

7.  Forneça um exemplo, se existir, de um grafo em que k(G) < \delta(G).

8.  Prove que um grafo simples que contém n vértices é necessariamente
    conexo se ele tem mais de (n-1)(n-2)/2 arestas.

9.  Indique quais dos três grafos abaixo é bipartido.

```mermaid
graph TB;
subgraph "(1)"
A(( )); B(( )); C(( )); 
D(( )); E(( ));

A --- B;
B --- C & D;
C --- E;
D --- E;

style A fill:#0000FF
style C fill:#0000FF
style D fill:#0000FF

style B fill:#FF0000
style E fill:#FF0000

end
```

```mermaid
graph TB;
subgraph "(2)"
1(( )); 2(( )); 3(( ));
4(( )); 5(( )); 6(( ));
7(( )); 8(( )); 9(( ));

1 --- 2 & 4;
2 --- 3 & 5;
3 --- 6;

4 --- 5 & 7;
5 --- 6 & 8; 
6 --- 9; 

7 --- 8;
8 --- 9;

style 1 fill:#0000FF
style 3 fill:#0000FF
style 5 fill:#0000FF
style 7 fill:#0000FF
style 9 fill:#0000FF

style 2 fill:#FF0000
style 4 fill:#FF0000
style 6 fill:#FF0000
style 8 fill:#FF0000

end
```

```mermaid
graph TB;
subgraph "(2)"
1(( )); 2(( )); 3(( ));
4(( )); 5(( )); 6(( ));
7(( )); 8(( )); 


1 --- 2 & 3;
2 --- 4 & 5;
3 --- 4 & 6;
4 --- 7;
5 --- 8;
6 --- 7 & 8;
7 --- 8;

style 1 fill:#0000FF
style 4 fill:#0000FF
style 8 fill:#0000FF

style 2 fill:#FF0000
style 3 fill:#FF0000
style 5 fill:#FF0000
style 6 fill:#FF0000
style 7 fill:#FF0000

end
```

<hr/>

10. Construa dois grafos de 5 vértices e 8 arestad que não sejam 
    isomorfos. Prove que ambos não são isomorfos.

11. Dentre os grafos abaixo, determine se há pares de grafos isomorfos.

12. Prove que uma aresta e de um grafo é uma ponte se e somente se ela 
    não fizer parte de nenhum ciclo deste mesmo grafo.

13. Para o grafo da figura abaixo, apresente a sequência de vértices após
    a aplicação da BFS a partir do vértice 3. Considera a representação
    por listas de adjacências em ordem lexicográfica.

14. Para o grafo da figura abaixo, apresente a sequência de vértices após
    a aplicação da BFS a partir do vértice 3. Considere a representação
    por listas de adjacências em ordem lexicográficas.


15. Para o grafo da figura abaixo, apresente a sequência de vértices após
    a aplicação da DFS a partir do vértice 6. Considere a representação
    por listas de adjacências em ordem lexicográficas.

16. Para o grafo da figura abaixo, apresente a sequência de vértices após
    a aplicação da DFS a partir do vértice 6. Considere a representação
    por listas de adjacências em ordem lexicográficas.

17. Execute o algoritmo de Dijkstra para determinar especificamente os 
    menores caminhos a partir do vertice A do grafo abaixo.


18. Execute o algoritmo de Dijkstra para determinar especificamente os 
    menores caminhos a partir do vertice B do grafo abaixo.

19. Execute o algoritmo de Bellman-Ford para o grafo abaixo, a partir 
    do vertice 0.

20. Execute o algoritmo de Bellman-Ford para o grafo abaixo, a partir 
    do vertice 1.
    
21. Elabore um exemplo de um grafo com 6 vertices de tal maneira que o
    caminho mais curto entre os vertices 1 e 6 somente podera ser 
    calculado pelo algoritmo de Bellman-Ford. Justifique o exemplo.

22. Para a rede abaixo, nas quais os rotulos apresentam os limites minimos
    e maximos para o fluxo em cada arco, adicione (se necessario) vertices
    e arcos artificiais para que todo vertice possua fluxo conservativo.

        (a) determine um fluxo viavel

        (b) determine o valor do fluxo maximo, pela aplicacao do algoritmo
            de Ford \delta Fulkerson. Prove que o valor do fluxo maximo e
            otimo, apresentando o corte minimo associado.

23. Para a rede abaixo, nas quais os rotulos apresentam os limites minimos
    e maximos para o fluxo em cada arco, adicione (se necessario) vertices
    e arcos artificiais para que todo vertice possua fluxo conservativo.

        (a) determine um fluxo viavel

        (b) o valor do fluxo maximo, pela aplicaçao 
        
24. Para a rede abaixo, nas quais os rótulos apresentam os limites 
    mínimos e máximos para o fluxo em cada arco, adicione 
    (se necessário) vértices e arcos artificiais para que todo vértice 
    possua fluxo conservativo, 

        (a) determine um fluxo viável 

        (b) o valor do fluxo máximo, pela aplicação do algoritmo 
            de Ford \delta Fulkerson.

    Prove que o valor do fluxo máximo é ótimo, apresentando o corte 
    mínimo associado.
