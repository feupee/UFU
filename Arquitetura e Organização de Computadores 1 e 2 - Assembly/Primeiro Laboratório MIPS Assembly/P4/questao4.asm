.data
M:      .word 2, 1, 1, 2     # Matriz 2x2
	msg: .asciiz "Eh quadrado magico\n"
	msg2: .asciiz "NAO eh quadrado magico\n"
.text
main:
    # Configurações iniciais
    li $t0, 2               # Definindo o tamanho da matriz (n = 2)
    li $t1, 0               # Inicializando índice das linhas
    li $t2, 0               # Inicializando índice das colunas

    # Calculando o deslocamento base da matriz
    la $t3, M               # Carrega o endereço base da matriz

    # Acessando os elementos da matriz e calculando a soma das linhas e colunas
    lw $t4, 0($t3)          # Carrega o primeiro elemento da matriz
    lw $t5, 4($t3)          # Carrega o segundo elemento da matriz
    lw $t6, 8($t3)          # Carrega o terceiro elemento da matriz
    lw $t7, 12($t3)         # Carrega o quarto elemento da matriz

    # Cálculo das somas das linhas
    add $t8, $t4, $t5       # Soma dos elementos da primeira linha
    add $t9, $t6, $t7       # Soma dos elementos da segunda linha

    # Verificando se é um quadrado mágico
    beq $t8, $t9, check_diagonals    # Compara a soma das linhas
    j not_magic_square

check_diagonals:
    add $t9, $t4, $t6  
    beq $t8, $t9, check_sec_diagonal # Compara a soma das linhas com a soma das colunas
    j not_magic_square

check_sec_diagonal:
    add $t9, $t5, $t7
    beq $t8, $t9, magic_square       # Compara a soma das linhas com a soma da diagonal secundária
    j not_magic_square

magic_square:
    # Se chegou aqui, é um quadrado mágico
  
    li $v0, 4
    la $a0, msg       
    syscall        # Código de saída bem-sucedida
    j end_program

not_magic_square:
    # Se chegou aqui, não é um quadrado mágico
     li $v0, 4
    la $a0, msg2       
    syscall        # Código de saída bem-sucedida
    j end_program

end_program:
    # Saída do programa
    li $v0, 10              # Chamada do sistema para finalizar o programa
    syscall
