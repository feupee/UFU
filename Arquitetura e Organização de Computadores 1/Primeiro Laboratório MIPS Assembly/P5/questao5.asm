.data
	msg: .asciiz "Bem vindo a Função phi de Euler!\nInsira um inteiro: "
	# ------   QUESTAO 5 FUNÇÃO PHI DE EULER  ------
	
.text
	.main: #rotulo main principal
		la $a0, msg #$a0 tem msg
		jal imprimeString #chama a função imprimeString
		
		jal lerInteiro #chama a função lerInteiro,  SALTO para rotulo Ler inteiro
		
		move $a0, $v0 # $a0 agora tem o valor do inteiro lido
		#argumentos de função: $a0 
		jal euler_phi 
		volta:
		# armazena em $v0 o valor do retorno da funcao (euler_phi).
		move $a0, $v0
		#coloco em $a0 o valor de $v0 para imprimir.
		
		jal imprimeInteiro
		
		jal encerrarPrograma
		
	
	imprimeString: #rotulo para imprimir uma string, imprime o que está em $a0
		li $v0, 4 
		syscall 
		jr $ra
	imprimeInteiro: #rotulo para imprimir um inteiro, imprime o que está em $a0
		li $v0, 1
		syscall
		jr $ra
		
	encerrarPrograma:
		li $v0, 10
		syscall
		jr $ra
	lerInteiro: #rotulo para ler inteiro
		li $v0, 5 # prepara o sistema para LER INTEIRO
		syscall
		jr $ra
		
	mdc: #Espera como argumento $a0, $a1, retorna em $v0
		beq $a1, $zero,mdc2  #se $a1 for igual a 0 CONDIÇAO DE PARADA, retorna o que esta em $a0
	
		# se nao, ele vai fazer o $a0 receber $a1, e $a1 recebe o resto da div de A por B
		div $a0, $a1 #divisao de $a0 por $a1
		move $a0, $a1 # A0 recebe $a1
		mfhi $a1 # $a1 recebe o resto da divisao
		
		#chamada recursiva a mdc
		j mdc
		# Caso base para quando $a1 é zero
		mdc2:
    			move $v0, $a0          # Retorna $a0 em $v0
    			jr $ra                 # Retorna para o endereço de retorno
    			
    	euler_phi:
    		li $t1, 0 # CONTADOR. Conta a qtd de CO-PRIMOS entre N e X
    		li $t0, 1 # IGUALDADE, mdc() == 1
    		li $t2, 1 # X PARA MDC(N,X) numero natural <= N 
    		move $t4, $a0 # valor de N para garantir que ele nao mude durante a execucao
    		while:
    			# Começa $t2 == 1, e vai incrementando ate N
    			bgt $t2, $t4, saida #condição de parada do while, Se $t2 > $t4 PULA pro rotulo SAIDA
    			#passo argumentos para mdc e chamo:
    			move $a1, $t2 # X 
    			move $a0, $t4 # N
    			jal mdc
    			
    			# $v0 esta armazenando o resultado de mdc(A ,B)
    			addi $t2, $t2, 1 # $t2 ++ Incrementa $t2 é o X.
    			
    			beq $v0, $t0,incrementa # se $v0(mdc(a,b) == 1 execute a partir de incrementa
 
    			j while
    			
    			incrementa:
    				addi $t1,$t1, 1 # $t1 ++ Incrementa $t1 que é o Resultado QTD
    				j while
    			
    		saida:
    			move $v0, $t1 #Retorna em v0 o que esta em t1
    			j volta	