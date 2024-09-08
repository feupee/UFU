.data
    mensagem_escolha_metodo: .asciiz "Escolha o método de cálculo do polinômio:\n 1. Método de Horner\n 2. Método Tradicional\nEscolha: "
    mensagem_Numero_polinomio: .asciiz "Entre com o grau do polinômio n: "
    mensagem_Numero_X: .asciiz "Entre com o valor de X: "
    mensagem_escolha_polinomio: .asciiz "Digite o coeficiente de grau "
    errorMessage: .asciiz "Valor inválido(Diferente de 1 ou 2, método de escolha). Encerrando o programa.\n"
    myArray_Coeficientes:
        .align 2 # Alinha palavra na posição correta
        .space 44 # Array de 10 elementos(pode ser mudado)
    resultado: .word 0

.text
main:
    # Imprime Mensagem perguntando qual método quer usar 
    li $v0, 4
    la $a0, mensagem_escolha_metodo 
    syscall

    # Lê qual método quer usar
    li $v0, 5 
    syscall

    # Armazena o valor da escolha em $t7
    move $t7, $v0 

    # Entrar com grau do polinomio N
    li $v0, 4
    la $a0, mensagem_Numero_polinomio 
    syscall

    # Lê o grau do polinômio
    li $v0, 5  
    syscall

    # Incrementa o grau do polinômio
    addi $s0, $v0, 1

    # Entrar com valor de X
    li $v0, 4
    la $a0, mensagem_Numero_X
    syscall

    # Lê o valor de X
    li $v0, 5  
    syscall

    # Armazena o valor de X em $s1
    move $s1, $v0  

    # Inicializa o índice do array em $t0 e o valor a ser colocado no array em $t1
    move $t0, $zero
    move $t1, $zero

    # Define o tamanho do array
    li $t5, 4  
    mul $t2, $s0, $t5 

    # Inicializa o contador de índice em $t4 com o tamanho do polinômio
    move $t4, $s0

    # Loop para receber os coeficientes do polinômio
loop_receber_coeficientes:
    # Verifica se o valor do índice é igual ao tamanho do array
    beq $t0, $t2, SaiDoLoop

    # Imprime Mensagem perguntando o coeficiente de grau N
    li $v0, 4
    la $a0, mensagem_escolha_polinomio
    syscall

    # Decrementa o contador de grau
    subi $t4, $t4, 1

    # Imprime o número do grau
    move $a0, $t4      
    li $v0, 1
    syscall

    # Lê o coeficiente
    li $v0, 5 
    syscall

    # Armazena o coeficiente no array
    move $t1, $v0
    sw $t1, myArray_Coeficientes($t0)
    addi $t0, $t0, 4
    j loop_receber_coeficientes

SaiDoLoop:
    # Verifica se o valor é igual a 1
    li $t1, 1
    beq $t7, $t1, Metodo_de_Horner

    # Verifica se o valor é igual a 2
    li $t1, 2
    beq $t7, $t1, Metodo_Tradicional

    # Exibe mensagem de erro e encerra o programa
    li $v0, 4
    la $a0, errorMessage
    syscall
    li $v0, 10
    syscall

# Método de Horner
Metodo_de_Horner:
    move $t0, $zero         # Inicia a base do array com 0
    lw $a3, myArray_Coeficientes($t0)   # $a3 funciona como o polinômio
    addi $t0, $t0, 4        	# Passa para a próxima posição

while_Horner:
    beq $t0, $t2, MostraResultadoHorner
    mul $a3, $a3, $s1    # Multiplica o valor do polinômio por x
    lw $t5, myArray_Coeficientes($t0)   # Carrega o valor do array
    add $a3, $a3, $t5    # Soma o valor da posição do array em poly*x
    addi $t0, $t0, 4     # Passa para a próxima posição
    j while_Horner

MostraResultadoHorner:
    li $v0, 1
    move $a0, $a3
    syscall

j exit_program

# Método Tradicional
Metodo_Tradicional:
    move $t0, $zero         # Inicia a base do array com 0
    move $a3, $zero         # $a3 funciona como o polinômio
    move $t4, $zero         # Inicializa o contador de índice

while_tradicional:
    beq $t0, $t2, MostraResultadoTradicional
    lw $t5, myArray_Coeficientes($t0)
    subi $a1, $s0, 1       # Expoente = n - 1 - i
    sub $a1, $a1, $t4      # Subtrai o índice atual
    move $a0, $s1          # Base = valor de x

    jal pow                # Chama a função pow

    mul $t6, $t5, $v0
    add $a3, $a3, $t6

    addi $t0, $t0, 4      # Passa para a próxima posição
    addi $t4, $t4, 1
    j while_tradicional

MostraResultadoTradicional:
    li $v0, 1
    move $a0, $a3
    syscall

j exit_program

exit_program:
    li $v0, 10
    syscall

pow:
    # Inicializa o resultado com 1
    li $v0, 1

    # Verifica se o expoente é zero
    beq $a1, $zero, pow_done

pow_loop:
    # Multiplica a base pelo resultado atual
    mul $v0, $v0, $a0

    # Decrementa o expoente
    addi $a1, $a1, -1

    # Verifica se o expoente é maior que zero
    bgtz $a1, pow_loop

pow_done:
    jr $ra
