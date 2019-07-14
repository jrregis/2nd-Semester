# Trabalho 2 - Questão 4 (Cálculo de raízes de uma equação de segundo grau)
# Disciplina: ELC1011/Organização de Computadores
# Professor: Giovani Baratto
# Autores: Hierro Duarte, Régis dos Santos Jr.
# Matrículas: 201820134, 201721760
# E-mails: hierrodscherer@gmail.com, rdjunior@inf.ufsm.br

# Serviços
.eqv svc_print_str 4 # Imprime uma string
.eqv svc_print_double 3 # Imprime uma string
.eqv svc_exit 10 # Finaliza o programa
.eqv svc_print_char 11 # Imprime um char
.eqv svc_read_double  7 # Lê float (sempre utiliza dois registradores do coprocessador)

.text
   
   main:
        # Leitura do A
        la $a0, str_a # Passa endereço de str_a como argumento para procedimento que imprime string
        jal printStr # Chama a função que imprime a string de input

        jal readDouble # Lê o valor double
        mov.d $f4, $f0 # Passa o valor lido para $f4

        # Leitura do B
        la $a0, str_b # Passa endereço de str_b como argumento para procedimento que imprime string
        jal printStr # Chama a função que imprime a string de input

        jal readDouble # Lê o valor double
        mov.d $f6, $f0 # Passa o valor lido para $f6
        
        # Leitura do C
        la $a0, str_c # Passa endereço de str_c como argumento para procedimento que imprime string
        jal printStr # Chama a função que imprime a string de input
        
        jal readDouble # Lê o valor double
        mov.d $f8, $f0 # Passa o valor lido para $f8

        # Imprime nova linha
        jal printNewLine

        # Calcula o DELTA
        jal calculateDelta

        # Carrega o valor 0 para um registrador com precisão dupla para fazer a comparação
        mtc1 $zero, $f18 # $f18 <- 0
        cvt.d.w $f2, $f18 # Converte valor em $f18 de word para double e salva em $f2

        c.lt.d $f10, $f2
	bc1t negativeDelta

    calculateRoots: # Calcula as raízes
        # Calcula a raíz do delta e atribui ao mesmo registrador
        sqrt.d $f10, $f10

        # Carrega o valor imediato 2 registrador com precisão dupla para utilizar na multiplicação
        li $t0, 2 # $t0 <- 2
        mtc1 $t0, $f18 # $f18 <- $t0
        cvt.d.w $f20, $f18 # Converte valor em $f18 de word para double e salva em f$20

        # Calcula 2 * a
        mul.d $f20, $f20, $f4 # $f16 = 2 * a

        # Multiplica b por -1 (subtrai o valor de b de zero)
        sub.d $f6, $f2, $f6

        # Calcula x'
        add.d $f26, $f6, $f10 # $f26 = -b + delta
        div.d $f26, $f26, $f20 # $f26 = $f26 /  2 * a 

	# Checa se o delta é 0
	c.eq.d $f10, $f2 # Realiza a comparação
	bc1t equalRoots # Pula para imprimir as raízes iguais
	
        # Calcula x"
        sub.d $f28, $f6, $f10 # $f28 = -b - delta
        div.d $f28, $f28, $f20 # $f28 = $f28 / 2 * a
       
        # Imprime x'
        la $a0, str_x1 # Carrega o endereço da string
        mov.d $f0, $f26 # Move o valor calculado para $f0
        jal printRoot # Chama o procedimento que imprime uma raíz (dada a string acima)
        jal printNewLine # Imprime uma nova linha
        
        # Imprime x"
        la $a0, str_x2 # Carrega o endereço da string
        mov.d $f0, $f28 # Move o valor calculado para $f0
        jal printRoot # Chama o procedimento que imprime uma raíz (dada a string acima)
        jal printNewLine # Imprime uma nova linha

        jal exit # Chama o procedimento que fecha o programa
        
    equalRoots: # Faz a impressão quando as raízes são iguais
        # Imprime x' e x''
        la $a0, str_x # Carrega o endereço da string
        mov.d $f0, $f26 # Move o valor calculado para $f0
        jal printRoot # Chama o procedimento que imprime uma raíz (dada a string acima)
        jal printNewLine # Imprime uma nova linha

        j exit # Chama o procedimento que fecha o programa
        
    printRoot:
        move $t0, $a0 # $t0 <- $a0
        li $v0, svc_print_str  # $v0 <- 4 (svc_print_str)
        move $a0, $t0 # $a0 <- $t0
        syscall # Faz uma chamada ao SO

        mov.d $f12, $f0 # $f12 <- $f0
        li $v0, svc_print_double # $v0 <- 3 (svc_print_double)
        syscall # Faz uma chamada ao SO

        jr $ra # Retorna para $ra

    calculateDelta:
        mul.d $f10, $f6, $f6 # Calcula b²

	# Carrega o valor imediato 4 registrador com precisão dupla para utilizar na multiplicação
        li $t0, 4 # $t0 <- 4
        mtc1 $t0, $f12 # $f12 <- $t0
        cvt.d.w $f14, $f12 # Converte valor em $f12 de word para double e salva em f$14
        
        # Calcula 4 * a * c
        mul.d $f16, $f4, $f8 # $f16 <- (a*c)
        mul.d $f16, $f14, $f16 # $f16 <- 4*(a*c)
        
        # Calcula b² - (4 * a * c)
        sub.d $f10, $f10, $f16 # $f10 <- $f10 - $f16

        jr $ra # Retorna para $ra

    readDouble:
        li $v0, svc_read_double # $v0 <- 37 (svc_read_double)
        syscall # Faz uma chamada ao SO
        
        jr $ra # Retorna para $ra

    printStr:
        move $t0, $a0 # $t0 <- $a0
        li $v0, svc_print_str  # $v0 <- 4 (svc_print_str)
        move $a0, $t0 # $a0 <- $t0
        syscall # Faz uma chamada ao SO    
         
        jr $ra # Retorna para $ra

    printNewLine:
        li $v0, svc_print_char  # $v0 <- serviço de impressão de char (11)
        li $a0, '\n' # $a0 <- quebra de linha
        syscall # Faz uma chamada ao SO
        
        jr $ra # Retorna para $ra

    negativeDelta:
        li $v0, svc_print_str  # $v0 <- 4 (svc_print_str)
        la $t0, str_negative_delta # Carrega o endereço de str_negative_delta
        move $a0, $t0 # $a0 <- $t0
        syscall # Faz uma chamada ao SO     

    exit: # Termina a execução do programa
        li $v0, svc_exit # Passa o valor 10 para o $v0
        syscall # Faz uma chamada ao SO


.data
str_a: .asciiz "Insira o valor do coeficiente a: " # String para input do usuário
str_b: .asciiz "Insira o valor do coeficiente b: " # String para input do usuário
str_c: .asciiz "Insira o valor do coeficiente c: " # String para input do usuário
str_x: .asciiz "Raíz x' = x'' = " # String para output do resultado de x' (com delta = 0)
str_x1: .asciiz "Raíz x'  = " # String para output do resultado de x'
str_x2: .asciiz "Raíz x'' = " # String para output do resultado de x"
str_negative_delta: .asciiz "Essa equação não tem raízes reais (o delta é negativo).\n" # String para dizer que delta é negativo