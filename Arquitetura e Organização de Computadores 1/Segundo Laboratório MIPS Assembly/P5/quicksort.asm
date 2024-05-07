	.data 
stack: 	.word 0:1000     								# Declara��o de uma pilha com 1000 palavras
vetor:  .word 22,89,1,34,100,55,42,82,66,21,332,52,23,48,17,14,97,53,72,102  		# Array de inteiros
espaco: .asciiz " "     								# String representando um espa�o

	.text

    	li 	$a0, 0               		# Carrega o valor imediato 0 em $a0 (limite inferior do array)
    	li 	$a1, 19              		# Carrega o valor imediato 19 em $a1 (limite superior do array)
    	li 	$t9, 0               		# Carrega o valor imediato 0 em $t9 (�ndice para a pilha)
    	jal 	quick_sort          		# Salta e faz link para a fun��o quick_sort
    	li 	$t7, 0               		# Carrega o valor imediato 0 em $t7 (�ndice para impress�o do vetor)
    	la 	$t6, vetor           		# Carrega o endere�o do vetor em $t6
    	jal 	print_vetor         		# Salta e faz link para a fun��o print_vetor
    	jal 	fim                 		# Salta para o fim do programa

loop_arrayj_maior_pivot: 
    	ble 	$t3, $a2, return    		# Se $t3 <= $a2, retorna
    	subi 	$t5, $t5, 1        		# Subtrai 1 de $t5 (�ndice de $a2)
    	subi 	$t4, $t4, 4        		# Subtrai 4 de $t4 (�ndice do vetor)
    	la 	$t6, vetor           		# Carrega o endere�o do vetor em $t6
    	add 	$t6, $t6, $t4       		# Adiciona $t4 a $t6
    	lw 	$t3, 0($t6)          		# Carrega o valor da posi��o atual do vetor em $t3
    	j 	loop_arrayj_maior_pivot  	# Salta para loop_arrayj_maior_pivot

primeiro_if:
    	move 	$t8, $t1           		# Move o valor de $t1 para $t8
    	la 	$t6, vetor           		# Carrega o endere�o do vetor em $t6
    	add 	$t6, $t6, $t2       		# Adiciona $t2 a $t6
    	sw 	$t3, 0($t6)          		# Armazena o valor de $t3 na posi��o atual do vetor
    	la 	$t6, vetor           		# Carrega o endere�o do vetor em $t6
    	add 	$t6, $t6, $t4       		# Adiciona $t4 a $t6
    	sw 	$t8, 0($t6)          		# Armazena o valor de $t8 na posi��o atual do vetor
    	addi 	$t0, $t0, 1        		# Adiciona 1 a $t0 (�ndice de $a0)
    	addi 	$t2, $t2, 4        		# Adiciona 4 a $t2 (�ndice do vetor)
    	la 	$t6, vetor           		# Carrega o endere�o do vetor em $t6
    	add 	$t6, $t6, $t2       		# Adiciona $t2 a $t6
    	lw 	$t1, 0($t6)          		# Carrega o valor da nova posi��o do vetor em $t1
    	subi 	$t5, $t5, 1        		# Subtrai 1 de $t5 (�ndice de $a2)
    	subi 	$t4, $t4, 4        		# Subtrai 4 de $t4 (�ndice do vetor)
    	la 	$t6, vetor           		# Carrega o endere�o do vetor em $t6
	add 	$t6, $t6, $t4       		# Adiciona $t4 a $t6
    	lw 	$t3, 0($t6)          		# Carrega o valor da posi��o atual do vetor em $t3
    	j 	loop_i_menorigual_j  		# Salta para loop_i_menorigual_j

segundo_if:
    	bge 	$a0, $t5, return    		# Se $a0 >= $t5, retorna
    	la 	$t6, stack           		# Carrega o endere�o da pilha em $t6
    	add 	$t6, $t6, $t9       		# Adiciona $t9 a $t6
    	sw 	$ra, 0($t6)          		# Armazena o valor de $ra na pilha
    	addi 	$t6, $t6, 4        		# Adiciona 4 a $t6
    	sw 	$t0, 0($t6)          		# Armazena o valor de $t0 na pilha
    	addi 	$t6, $t6, 4        		# Adiciona 4 a $t6
    	sw 	$t5, 0($t6)          		# Armazena o valor de $t5 na pilha
    	addi 	$t6, $t6, 4        		# Adiciona 4 a $t6
    	sw 	$a0, 0($t6)          		# Armazena o valor de $a0 na pilha
    	addi 	$t6, $t6, 4        		# Adiciona 4 a $t6
    	sw 	$a1, 0($t6)          		# Armazena o valor de $a1 na pilha
    	addi 	$t6, $t6, 4        		# Adiciona 4 a $t6
    	addi 	$t9, $t9, 20      		# Adiciona 20 a $t9 (avan�a o �ndice da pilha)
    	move 	$a1, $t5           		# Move o valor de $t5 para $a1
    	jal 	quick_sort          		# Salta e faz link para a fun��o quick_sort
    	la 	$t6, stack           		# Carrega o endere�o da pilha em $t6
    	add 	$t6, $t6, $t9       		# Adiciona $t9 a $t6
    	subi 	$t6, $t6, 4        		# Subtrai 4 de $t6
    	lw 	$a1, 0($t6)          		# Carrega o valor de $a1 da pilha
    	subi 	$t6, $t6, 4        		# Subtrai 4 de $t6
    	lw 	$a0, 0($t6)          		# Carrega o valor de $a0 da pilha
    	subi 	$t6, $t6, 4        		# Subtrai 4 de $t6
    	lw 	$t5, 0($t6)          		# Carrega o valor de $t5 da pilha
    	subi 	$t6, $t6, 4        		# Subtrai 4 de $t6
    	lw 	$t0, 0($t6)          		# Carrega o valor de $t0 da pilha
    	subi 	$t6, $t6, 4        		# Subtrai 4 de $t6
    	lw 	$ra, 0($t6)          		# Carrega o valor de $ra da pilha
    	subi 	$t9, $t9, 20       		# Subtrai 20 de $t9 (retrocede o �ndice da pilha)
    	jr 	$ra                  		# Retorna para a instru��o de chamada

loop_i_menorigual_j:    
    	bgt 	$t0, $t5, return    		# Se $t0 > $t5, retorna
    	move 	$s1, $ra           		# Move o valor de $ra para $s1
    	jal 	loop_arrayi_menor_pivot  	# Salta e faz link para a fun��o loop_arrayi_menor_pivot
    	jal 	loop_arrayj_maior_pivot  	# Salta e faz link para a fun��o loop_arrayj_maior_pivot
    	move 	$ra, $s1           		# Move o valor de $s1 para $ra
    	ble 	$t0, $t5, primeiro_if  		# Se $t0 <= $t5, salta para primeiro_if
    	j 	loop_i_menorigual_j  		# Salta para loop_i_menorigual_j

loop_arrayi_menor_pivot:
    	bge 	$t1, $a2, return    		# Se $t1 >= $a2, retorna
    	addi 	$t0, $t0, 1        		# Adiciona 1 a $t0 (�ndice de $a0)
    	addi 	$t2, $t2, 4        		# Adiciona 4 a $t2 (�ndice do vetor)
    	la 	$t6, vetor           		# Carrega o endere�o do vetor em $t6
    	add 	$t6, $t6, $t2       		# Adiciona $t2 a $t6
    	lw 	$t1, 0($t6)          		# Carrega o valor da nova posi��o do vetor em $t1
    	j 	loop_arrayi_menor_pivot  	# Salta para loop_arrayi_menor_pivot

quick_sort:        
    	move 	$t8, $a0           		# Move o valor de $a0 para $t8
    	add 	$a2, $zero, $a0     		# Adiciona 0 a $a2 (inicializa o pivot)
    	move 	$t8, $a1           		# Move o valor de $a1 para $t8
    	add 	$a2, $a2,  $t8      		# Adiciona $t8 a $a2 (calcula o �ndice do pivot)
    	srl 	$a2, $a2, 1         		# Desloca aritm�ticamente $a2 para a direita em 1 bit (divide por 2)
    	mul 	$a2, $a2, 4         		# Multiplica $a2 por 4 (calcula o deslocamento do pivot no vetor)
    	la 	$t6, vetor           		# Carrega o endere�o do vetor em $t6
    	add 	$t6, $t6, $a2       		# Adiciona $a2 a $t6
    	lw 	$a2, 0($t6)          		# Carrega o valor da posi��o do pivot no vetor em $a2
    	move 	$t0, $a0           		# Move o valor de $a0 para $t0 (inicializa o �ndice inferior)
    	mul 	$t2, $t0, 4         		# Multiplica $t0 por 4 (calcula o deslocamento do �ndice inferior no vetor)
    	la 	$t6, vetor           		# Carrega o endere�o do vetor em $t6
    	add 	$t6, $t6, $t2       		# Adiciona $t2 a $t6
    	lw 	$t1, 0($t6)          		# Carrega o valor da posi��o do �ndice inferior no vetor em $t1
    	move 	$t5, $a1           		# Move o valor de $a1 para $t5 (inicializa o �ndice superior)
    	mul 	$t4, $t5, 4         		# Multiplica $t5 por 4 (calcula o deslocamento do �ndice superior no vetor)
    	la 	$t6, vetor           		# Carrega o endere�o do vetor em $t6
    	add 	$t6, $t6, $t4       		# Adiciona $t4 a $t6
    	lw 	$t3, 0($t6)          		# Carrega o valor da posi��o do �ndice superior no vetor em $t3
    	la 	$t6, stack           		# Carrega o endere�o da pilha em $t6
    	add 	$t6, $t6, $t9       		# Adiciona $t9 a $t6
    	sw 	$ra, 0($t6)          		# Armazena o valor de $ra na pilha
    	addi 	$t6, $t6, 4        		# Adiciona 4 a $t6
    	sw 	$t0, 0($t6)         		# Armazena o valor de $t0 na pilha
    	addi 	$t6, $t6, 4        		# Adiciona 4 a $t6
    	sw 	$t5, 0($t6)          		# Armazena o valor de $t5 na pilha
    	addi 	$t6, $t6, 4        		# Adiciona 4 a $t6
    	sw 	$a0, 0($t6)          		# Armazena o valor de $a0 na pilha
    	addi 	$t6, $t6, 4        		# Adiciona 4 a $t6
    	sw 	$a1, 0($t6)          		# Armazena o valor de $a1 na pilha
    	addi 	$t6, $t6, 4        		# Adiciona 4 a $t6
    	addi 	$t9, $t9, 20       		# Adiciona 20 a $t9 (avan�a o �ndice da pilha)
    	jal 	loop_i_menorigual_j  		# Salta e faz link para a fun��o loop_i_menorigual_j
    	jal 	segundo_if          		# Salta e faz link para a fun��o segundo_if
    	jal 	terceiro_if         		# Salta e faz link para a fun��o terceiro_if
    	la 	$t6, stack           		# Carrega o endere�o da pilha em $t6
    	add 	$t6, $t6, $t9       		# Adiciona $t9 a $t6
    	subi 	$t6, $t6, 4        		# Subtrai 4 de $t6
    	lw 	$a1, 0($t6)          		# Carrega o valor de $a1 da pilha
    	subi 	$t6, $t6, 4        		# Subtrai 4 de $t6
    	lw 	$a0, 0($t6)          		# Carrega o valor de $a0 da pilha
    	subi 	$t6, $t6, 4        		# Subtrai 4 de $t6
    	lw 	$t5, 0($t6)          		# Carrega o valor de $t5 da pilha
    	subi 	$t6, $t6, 4        		# Subtrai 4 de $t6
    	lw 	$t0, 0($t6)          		# Carrega o valor de $t0 da pilha
    	subi 	$t6, $t6, 4        		# Subtrai 4 de $t6
    	lw 	$ra, 0($t6)          		# Carrega o valor de $ra da pilha
    	subi 	$t9, $t9, 20       		# Subtrai 20 de $t9 (retrocede o �ndice da pilha)
    	jr 	$ra                  		# Retorna para a instru��o de chamada

terceiro_if:
    	bge 	$t0, $a1, return   		# Se $t0 >= $a1, retorna
    	la 	$t6, stack          		# Carrega o endere�o da pilha em $t6
    	add 	$t6, $t6, $t9      		# Adiciona $t9 a $t6
    	sw 	$ra, 0($t6)         		# Armazena o valor de $ra na pilha
    	addi 	$t6, $t6, 4       		# Adiciona 4 a $t6
    	sw 	$t0, 0($t6)         		# Armazena o valor de $t0 na pilha
    	addi 	$t6, $t6, 4       		# Adiciona 4 a $t6
    	sw 	$t5, 0($t6)         		# Armazena o valor de $t5 na pilha
    	addi 	$t6, $t6, 4       		# Adiciona 4 a $t6
    	sw 	$a0, 0($t6)         		# Armazena o valor de $a0 na pilha
    	addi 	$t6, $t6, 4       		# Adiciona 4 a $t6
    	sw 	$a1, 0($t6)         		# Armazena o valor de $a1 na pilha
    	addi 	$t6, $t6, 4       		# Adiciona 4 a $t6
    	addi 	$t9, $t9, 20      		# Adiciona 20 a $t9 (avan�a o �ndice da pilha)
    	move 	$a0, $t0          		# Move o valor de $t0 para $a0
    	jal 	quick_sort         		# Salta e faz link para a fun��o quick_sort
    	la 	$t6, stack          		# Carrega o endere�o da pilha em $t6
    	add 	$t6, $t6, $t9      		# Adiciona $t9 a $t6
    	subi 	$t6, $t6, 4       		# Subtrai 4 de $t6
    	lw 	$a1, 0($t6)         		# Carrega o valor de $a1 da pilha
    	subi 	$t6, $t6, 4       		# Subtrai 4 de $t6
    	lw 	$a0, 0($t6)         		# Carrega o valor de $a0 da pilha
    	subi 	$t6, $t6, 4       		# Subtrai 4 de $t6
    	lw 	$t5, 0($t6)         		# Carrega o valor de $t5 da pilha
    	subi	t6, $t6, 4       		# Subtrai 4 de $t6
    	lw 	$t0, 0($t6)         		# Carrega o valor de $t0 da pilha
    	subi 	$t6, $t6, 4      		# Subtrai 4 de $t6
    	lw 	$ra, 0($t6)         		# Carrega o valor de $ra da pilha
    	subi 	$t9, $t9, 20      		# Subtrai 20 de $t9 (retrocede o �ndice da pilha)
    	jr 	$ra                 		# Retorna para a instru��o de chamada

fim: 
    	li 	$v0, 10             		# Carrega o valor imediato 10 em $v0 (syscall para finalizar o programa)
    	syscall                			# Chama a syscall para finalizar o programa

print_vetor: 
    	bgt 	$t7, $a1, return   		# Se $t7 > $a1, retorna
    	li 	$v0, 1             		# Carrega o valor imediato 1 em $v0 (syscall para imprimir inteiro)
    	lw 	$a0, 0($t6)         		# Carrega o valor da posi��o atual do vetor em $a0
    	syscall                			# Chama a syscall para imprimir inteiro
    	li 	$v0, 4              		# Carrega o valor imediato 4 em $v0 (syscall para imprimir string)
    	la 	$a0, espaco         		# Carrega o endere�o da string espaco em $a0
    	syscall                			# Chama a syscall para imprimir string
    	addi 	$t6, $t6, 4       		# Adiciona 4 a $t6 (avan�a para a pr�xima posi��o do vetor)
    	addi 	$t7, $t7, 1       		# Adiciona 1 a $t7 (incrementa o contador)
    	j 	print_vetor          		# Salta para print_vetor

return: 
    	jr 	$ra                 		# Retorna para a instru��o de chamada