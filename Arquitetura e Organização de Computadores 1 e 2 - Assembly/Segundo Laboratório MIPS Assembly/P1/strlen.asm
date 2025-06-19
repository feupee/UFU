    				.data
vetor:				.space 100    				# vetor para armazenar a entrada do usu�rio
mensagem_Receber_Palavra:	.asciiz "Digite uma palavra: "  	# mensagem para receber a palavra

    	.text
    	.globl main

main:
    									# imprimir a mensage para o usu�rio
	li 	$v0, 4           		
    	la 	$a0, mensagem_Receber_Palavra    
    	syscall

    									# lendo a entrada do usu�rio
    	li 	$v0, 8           
    	la 	$a0, vetor      
    	li 	$a1, 100         
    	syscall

    									# chamando a fun��o string_length
    	la 	$a0, vetor      					# carrega o endere�o do buffer contendo a entrada do usu�rio
    	jal 	string_length
    
    									# imprimindo o resultado
    
Resultado:
    	move 	$a0, $v0						# carrega o resultado (tamanho da string) em $a0
    	li 	$v0, 1           
    	syscall             
    
    									# sair do programa
    	li 	$v0, 10          
    	syscall

									# fun��o para calcular o comprimento da string
string_length:
    									# definindo os registradores
    	move 	$t0, $a0       						# $t0 = $a0 (Endere�o inicial da string)
    	move 	$t1, $zero						# t1 = 0 (Inicializando o contador de comprimento)

loop:
    	lb 	$t2, 0($t0)      					# carrega o byte apontado por $t0 em $t2
    	beqz 	$t2, end       						# se $t2 == 0, vai para o final da fun��o
    
    	addi 	$t0, $t0, 1    						# avan�a para o pr�ximo byte da string
    	addi 	$t1, $t1, 1    						# incrementa o contador de comprimento
    	j 	loop              					# loop
    
end:
    	sub 	$v0, $t1, 1     					# $v0 = $t1 (tamanho da string) - 1 (descontando o caractere nulo)
    	jr 	$ra              					# retorna