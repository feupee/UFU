.data
prompt_a: .asciiz "Digite o coeficiente 'a': "
prompt_b: .asciiz "Digite o coeficiente 'b': "
prompt_c: .asciiz "Digite o coeficiente 'c': "
result_msg: .asciiz "O polinômio é igual a zero para os seguintes valores de x: "
error_msg_a_is_zero: .asciiz "Erro: O coeficiente 'a' não pode ser zero."
error_msg_negative_discriminant: .asciiz "Erro: O discriminante é negativo, indicando raízes complexas."
espaco: .byte ' '
zero: .float 0.0
quatro: .float 4.0
dois: .float 2.0

.text
.globl main

main:
    # Exibir prompt para o coeficiente 'a' e ler o valor
    li $v0, 4
    la $a0, prompt_a
    syscall

    li $v0, 6   # código da syscall para ler um número real (float)
    syscall  
    lwc1 $f4, zero      # Carregar o valor zero em $f4
    add.s $f12,$f0,$f4  #adiciono ao $f12 o valor de 'a'
    c.eq.s $f12, $f4    # Comparar se 'a' é menor que zero
    bc1t error_a_is_zero   # Branch se 'a' for zero
    
    # Exibir prompt para o coeficiente 'b' e ler o valor
    li $v0, 4
    la $a0, prompt_b
    syscall

    li $v0, 6
    syscall
    add.s $f13,$f0,$f4 #adc ao $f13 o valor de 'b'

    # Exibir prompt para o coeficiente 'c' e ler o valor
    li $v0, 4
    la $a0, prompt_c
    syscall

    li $v0, 6
    syscall
    add.s $f14,$f0,$f4 #adiciono ao $f14 o valor de 'c'
    
    
    # -------------------------- CALCULOS -----------------
    

    # Calcular o discriminante (DELTA /\) = b^2 - 4ac
    lwc1 $f4, quatro
    mul.s $f2, $f13, $f13   # b^2
    mul.s $f3, $f12, $f14   # a*c
    mul.s $f3, $f3, $f4     # Multiplicar por 4
    sub.s $f0, $f2, $f3     # Calcular b^2 - 4ac
    lwc1 $f4, dois
    mul.s $f12, $f12,$f4   # 2*'a'
    mul.s $f14, $f14,$f4   # 2*'c'

    # Verificar o valor do discriminante
    c.lt.s $f0, $f4 #DISCRIMANTEN MENOR QUE 0
    bc1t negative_discriminant

    # Calcular as raízes do polinômio
    sqrt.s $f2, $f0         # Calcular a raiz quadrada do discriminante
    
    # Verificar se b < 0 para usar modo2
    c.lt.s $f13, $f0  # Comparar se $f13 'b' é menor que zero
    bc1t modo2  # Se verdadeiro (b < 0), vá para modo2
    
    	neg.s $f13, $f13        # Negar o coeficiente 'b'
    	
    	# Calcular x1 = 2c/(-b - sqrt(delta))
    	sub.s $f1, $f13, $f2    # -b - sqrt(delta)
    	div.s $f1, $f14, $f1    # 2c dividido por -b - sqrt(delta)
    	
    	
    	# Calcular x2 = (-b - sqrt(delta)) / 2a
    	sub.s $f3, $f13, $f2    # -b - sqrt(delta)
    	div.s $f3, $f3, $f12    # Dividir por 2a
    	
    	j exibe_raiz
    
    modo2:
        neg.s $f13, $f13        # Negar o coeficiente 'b'
        
    	# Calcular x1 = (-b + sqrt(delta)) / 2a
    	add.s $f1, $f13, $f2    # -b + sqrt(delta)
    	div.s $f1, $f1, $f12    # Dividir por 2a

    	# Calcular x2 = 2c/(-b - sqrt(delta))
    	add.s $f3, $f13, $f2    # -b + sqrt(delta)
    	
    	div.s $f3, $f14, $f3    # 2c dividido por -b - sqrt(delta)
    	
exibe_raiz:   
    # Exibir as raízes do polinômio
    li $v0, 4
    la $a0, result_msg
    syscall

    # Exibir x1
    li $v0, 2
    mov.s $f12, $f1
    syscall
    
    li $v0,4
    la $a0, espaco
    syscall

    # Exibir x2
    li $v0, 2
    mov.s $f12, $f3
    syscall

    j exit_program

error_a_is_zero:
    # Exibir mensagem de erro se 'a' for zero
    li $v0, 4
    la $a0, error_msg_a_is_zero
    syscall

    j exit_program

negative_discriminant:
    # Exibir mensagem de raízes complexas se o discriminante for negativo
    li $v0, 4
    la $a0, error_msg_negative_discriminant
    syscall

exit_program:
    li $v0, 10  # código da syscall para sair do programa
    syscall
