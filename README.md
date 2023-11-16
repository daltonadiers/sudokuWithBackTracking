# Sudoku resolvido com BackTracking
  Esse projeto visa resolver qualquer sudoku contido em uma matriz 9x9, utilizando da técnica de BackTrackin. Esta técnica consiste em voltar atrás sempre que não houverem mais soluções a partir do ponto em que se encontra, e tentar um caminho diferente.

  ## Descrição
  O algoritmo utiliza de dois arquivos, sendo um deles `sudoku.cpp`, apenas para inicializar a classe `mySudo`, contida no arquivo `sudokusolve.cpp`. Utilizando de uma estrutura stack, cada vez que nos encontrarmos "sem saída", desfizemos o último passo, contido no topo da stack e tentamos novamente seguindo outro caminho. Temos algumas funções principais, responsáveis por verificar linhas, colunas e blocos, tal qual tradicionalmente no sudoku, afim de garantir que a solução esteja correta. Caso o algoritmo tente voltar atrás, e não haja nada contido na stack, significa que não há solução posível para o sudoku atual.

## Compilação e execução
#### Recomenda-se ambiente linux para execução do projeto
  1. Clone o repositório em um diretório de sua preferência
  2. Navegue via terminal até o diretório escolhido
  3. Compile o arquivo `sudoku.cpp` utilizando no terminal a linha `g++ sudoku.cpp -o nomedoarquivo` (substitua "nomedoarquivo" por um nome de sua preferência.)
  4. No arquivo `sudoku.txt` você deve escrever o jogo sudoku que deseja resolver. Lembre-se de preencher os espaços inicialmente vazios com zeros.
  5. Execute utilizando no terminal a linha `./nomedoarquivo` (substitua "nomedoarquivo" pelo nome escolhido no passo anterior.)
  6. Caso haja solução possível, você verá em seu terminal a matriz com a solução do sudoku escolhido. Caso contrário, receberá o aviso de que não existe solução para o problema atual.
## Linguagem de programação e compilador 
- **Linguagem:** C++
- **Compilador:** G++17 (Padrão C++17)
## Autores
- **Dalton Oberdan Adiers**@daltonadiers
- **Bruna Baldissera**@brunabaldissera

