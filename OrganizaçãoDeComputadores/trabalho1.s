# Trabalho 1 - Processor MIPS simulado para o exercício 12
# Disciplina: ELC1011/Organização de Computadores
# Professor: Giovani Baratto
# Autores: Hierro Duarte, Régis dos Santos Jr.
# Matrículas: 201820134, 201721760
# E-mails: hierrodscherer@gmail.com, rdjunior@inf.ufsm.br

# Serviços
.eqv svc_print_integer 1 # Imprime um inteiro (usado no código 12)
.eqv svc_read_integer 5 # Lê um inteiro
.eqv svc_print_str 4 # Imprime uma string (usado no código 12)
.eqv svc_exit 10 # Finaliza o programa (usado no código 12)
.eqv svc_print_char 11 # Imprime um char (usado no código 12)
.eqv svc_open_file 13 # Abre um arquivo
.eqv svc_read_file 14 # Lê um arquivo
.eqv svc_close_file 16 # Fecha um arquivo
.eqv svc_print_hex 34 # Imprime hexadecimal

# Máscaras
.eqv mask_op 0XFC000000 # Máscara do OPCODE
.eqv shift_op 26 # Número de bits deslocados

.eqv mask_rs 0x03E00000 #  Máscara do RS
.eqv shift_rs 21 # Número de bits deslocados

.eqv mask_rt 0X001F0000 # Máscara do RT
.eqv shift_rt 16 # Número de bits deslocados

.eqv mask_rd 0X0000F800 # Máscara do RD
.eqv shift_rd 11 # Número de bits deslocados

.eqv mask_imm16 0x0000FFFF # Máscara do imediato de 16 bits
.eqv mask_imm26 0x03FFFFFF # Máscara do imediato de 26 bits

.eqv mask_shamt 0x000007C0 # Máscara do SHAMT
.eqv shift_shamt 6 # Número de bits deslocados

.eqv mask_funct 0x0000003F # Máscara do FUNCT

# Constantes de comparação
.eqv syscall_value 0x0000000C # Word equivalente ao SYSCALL
.eqv J_limit 4 # A partir de 4, as instruções deixam de ser do tipo J

# Comandos TIPO-R (valor do funct)
.eqv r_add 0x20 # FUNCT da instrução ADD (tipo R)
.eqv r_addu 0x21 # FUNCT da instrução ADDU (tipo R)
.eqv r_jr 0x08 # FUNCT da instrução JR (tipo R)
# Exceção
.eqv r_mul 0x1c # OPCODE da instrução MUL (tipo R)

# Comandos TIPO-I (valor do opcode)
.eqv i_addiu 0x09 # OPCODE da instrução ADDIU (tipo I)
.eqv i_lw 0x23 # OPCODE da instrução LW (tipo I)
.eqv i_sw 0x2B # OPCODE da instrução SW (tipo I)
.eqv i_bne 0x05 # OPCODE da instrução BNE (tipo I)
.eqv i_lui 0x0F # OPCODE da instrução LUI (tipo I)
.eqv i_ori 0x0D # OPCODE da instrução ORI (tipo I)
.eqv i_addi 0x08 # OPCODE da instrução ADDI (tipo I)

# Comandos TIPO-J (valor do opcode)
.eqv j_jal 0x03 # OPCODE da instrução JAL (tipo J)
.eqv j_jump 0x02 # OPCODE da instrução J (tipo J)

# Endereços inicial de memória de dados
.eqv text_adress_ini 0x00100000 # Inicío padrão do segmento de texto (instruções)

# Tamanho da pilha
.eqv stack_size 128 # Valor do tamanho pilha

# Tamanho máximo do buffer
.eqv max_buffer_size 4096

.text # Diretiva que indica o código-fonte
           
main:
    # Insere o valor inicial de text_buffer para pc
    la $t0, text_buffer # Carrega o endereço inicial de text_buffer para $a0
    sw $t0, pc # Salva o valor de $t0 em pc

    # Insere o endereço da pilha em sp
    la $t0, stack # Carrega o endereço da pilha para o stack
    li $t1, stack_size # Carrega o imediato do tamanho da pilha
    add $t0, $t0, $t1 # Soma ambos e pega o endereço do topo da pilha
    
    la $t2, regs # Recebe o endereço inicial dos registradores simulados
    la $t2, 116($t2) # Carrega o endereço do $sp dos registradores simulados

    sw $t0, 0($t2) # Salva o endereço final de pilha dentro $sp

    # Carrega o conteúdo do arquivo text.bin para a memória de texto
    la $a1, text_file_adress # Passa o endereço do text_file_adress (string que indica local do arquivo) como $a1
    la $a2, text_descriptor # Passa o endereço de text_descriptor como $a2
    la $a3, text_buffer # Passa o endereço de text_buffer como $a3
    jal loadFile # Passa ($a1, $a2, $a3) para o procedimento que carrega o arquivo

    # Carrega o conteúdo do arquivo data.bin para a memória
    la $a1, data_file_adress # Passa o endereço do data_file_adress (string que indica local do arquivo) como $a1
    la $a2, data_descriptor # Passa o endereço de data_descriptor como $a2
    la $a3, data_buffer # Passa o endereço de data_buffer como $a3
    jal loadFile # Passa ($a1, $a2, $a3) para o procedimento que carrega o arquivo

    # Imprime o título e a mensagem de abertura
    jal printOpeningMsg

    # Leitura do numero de instruções
    jal getInstructionNumber # Chama procedimento que lê o numero de instruções a serem executadas

    # Busca, decodifica e executa as instruções
    jal printOutputStr # Chama procedimento que imprime "OUTPUT DO PROGRAMA: "
    jal handleInstruction # Chama procedimento que trata a busca/decodificação/execução das instruções

    # Imprime o número de execuções do programa
    jal printExecutions # Chama procedimento que imprime o número de instruções que foram executadas

    # Imprime registradores modificados durante a execução
    jal printRegistersStr # Chama procedimento que imprime "REGISTRADORES: (número, valor)\n" 
    jal printRegisters # Chama procedimento que imprime os registradores simulados e seus respectivos valores

    # Encerra o programa
    j exit # Chama procedimento que finaliza programa

loadFile: #Leitura de arquivo para a vetores que emulam a memória
    # Transfere os valores recebidos como argumentos para registradores temporários
    move $t5, $a1 # Passa o argumento $a1 para $t5 (file adress)
    move $t6, $a2 # Passa o argumento $a2 para $t6 (descriptor)
    move $t7, $a3 # Passa o argumento $a3 para $t7 (buffer)

    # Abre o arquivo através de uma syscall
    li $v0, svc_open_file  # $v0 <- 13 (svc_open_file)
    move $a0, $t5 # $a0 <- $t5
    li $a1, 0 # $a1 <- 0
    li $a2, 0 # $a1 <- 0
    syscall # Faz uma chamada ao serviço 13: abrir arquivo
    
    sw $v0, 0($t6) # Salva o valor do descriptor em $v0
    
    # Checa se o arquivo foi aberto corretamente
    bltz $v0, errorOpeningFile # Chama o procedimento errorOpeningFile caso $v0 seja negativo

    # Lê o arquivo através de uma syscall
    li $v0, svc_read_file # $v0 <- 14 (svc_read_file)
    lw $t0, 0($t6) # $t0 <- valor($t6)
    move $a0, $t0 # $a0 <- $t6
    move $a1, $t7 # $a1 <- $t7
    li $a2, max_buffer_size # $a2 <- imediato(4096)
    syscall # Faz uma chamada ao serviço 14: ler arquivo

    # Checa se o arquivo foi lido corretamente
    bltz $v0, errorReadingFile # Chama o procedimento errorReadingFile caso $v0 seja negativo

    # Fecha o arquivo (tem de guardar o $ra na pilha já que utiliza jal)
    addi $sp, $sp, -4 # Reserva uma word na pilha
    sw $ra, 0($sp) # Salva o $ra na pilha

    jal closeFile # Chama procedimento que fecha arquivo

    lw $ra, 0($sp) # Recebe o valor anterior de $ra
    addi $sp, $sp, 4 # Restaura pilha após fechar arquivo

    jr $ra # Retorna para o procedimento main

errorOpeningFile: # Declara que houve erro ao abrir um arquivo, fecha o arquivo e termina o programa
    li $v0, svc_print_str # $v0 <- 4 (svc_print_str)
    la $a0, str_open_error # $a0 <- Endereço de "ERRO: Erro ao abrir o arquivo\n" (str_open_error)
    syscall # Faz uma chamada ao serviço 4: imprimir string

    # $ra não é tratado porque o programa é fechado logo em seguida
    jal closeFile # Chama o procedimento que fecha o arquivo
    
    j exit # Fecha o programa

errorReadingFile: # Declara que houve erro ao ler um arquivo, fecha o arquivo e termina o programa
    li $v0, svc_print_str # $v0 <- 4 (svc_print_str)
    la $a0, str_read_error # $a0 <- Endereço de "ERRO: Erro ao abrir o arquivo\n" (str_open_error)
    syscall # Faz uma chamada ao serviço 4: imprimir string

    jal closeFile # Chama o procedimento que fecha o arquivo
    
    j exit # Fecha o programa

closeFile: # Fecha arquivo
    move $t1, $a1 # $t1 <- $a1
    li $v0, svc_close_file # $v0 <- 16 (svc_close_file)
    move $a0, $t1 # $a0 <- $t1
    syscall # Faz uma chamada ao serviço 16: fechar arquivo 

    jr $ra # Retorna para o procedimento caller

getInstructionNumber: # Leitura do numero de instruções a serem printadas
    li $v0, svc_print_str  # $v0 <- 4 (svc_print_str)
    la $a0, str_user_input # $a0 <- Endereço de "Insira o n° de instrucoes a serem executadas: " (str_user_input)
    syscall # Faz uma chamada ao serviço 4: imprimir string               

    li $v0, svc_read_integer # $v0 <- 5 (svc_read_integer)
    syscall # Faz uma chamada ao serviço 5: ler inteiro

    blez $v0, getInstructionNumber # Se o usuário inserir um valor inferior ou igual a zero, a função é chamada novamente
    
    la $t0, instruction_number # $t0 <- Endereço de instruction_number
    sw $v0, 0($t0) # Salva em instruction_number o valor lido

    jr $ra # Retorna para o procedimento main

handleInstruction: # Busca, decodifica e executa instrução
    # Busca
    lw $s0, pc # $t1 <- pc (Valor do endereço da instrução a ser executada)
    lw $t0, 0($s0) # $t0 <- instrução a ser executada
    sw $t0, instruction # instruction <- $t1

    # Incremento do loop
    lw $t0, pc
    addi $t0, $t0, 4 # Incrementa o índice do array text_buffer (program counter)
    sw $t0, pc

    lw $t1, instruction_counter # $s2 <- valor de instruction_counter

    addi $t1, $t1, 1 # Incrementa contador de instruções executadas
    sw  $t1, instruction_counter # Salva o novo valor de instruction_counter

    # Decodificação
    lw $t0, instruction # $t0 <- instruction

    move $t1, $t0 # $t1 <- $t0 

    andi $t1, $t1, mask_op # Aplica a máscara do OPCODE à instrução 
    srl $t1, $t1, shift_op # Executa um shift para alinhar os bits à direita

    sw $t1, op # Salva na memória o valor de OPCODE
	
    # Verificação de qual tipo é a instrução
    li $t2, syscall_value # $t2 <- syscall_value
    li $t3, r_mul # $t3 <- OPCODE da operação mul

    beq $t0, $t2, handleSyscall # Se for igual a syscall_value, é do tipo Syscall
    beq $t1, $zero, handleTypeR # Se for igual a zero, é do tipo R
    beq $t1, $t3, handleTypeR # Se for igual ao OPCODE de mul, também é do tipo R (ele é uma exceção)

    slti $t2, $t1, J_limit # Compara se é menor que 4, se for, $t2 <- 1, caso contrário, $t2 <- 0
    bne $t2, $zero, handleTypeJ # Se $t2 não for igual a zero, é do tipo J, caso contrário, tipo I
    
    handleTypeI:
        move $t1, $t0 # Copia o valor original da instrução para $t1
        andi $t1, $t1, mask_rs # Aplica a máscara de RS à instrução
        srl $t1, $t1, shift_rs # Desloca os bits necessários
        sw $t1, rs # Salva o valor de RS da instrução na memória

        move $t1, $t0 # Copia o valor original da instrução para $t1
        andi $t1, $t1, mask_rt # Aplica a máscara de RT à instrução
        srl $t1, $t1, shift_rt # Desloca os bits necessários
        sw $t1, rt # Salva o valor de RT da instrução

        move $t1, $t0 # Copia o valor original da instrução para $t1
        andi $t1, $t1, mask_imm16 # Aplica a máscara de IMM16 à instrução
        sw $t1, imm16 # Salva o valor de IMM16 da instrução
        
        # Verifica campo OPCODE e salta para a execução do seu tipo
        lw $t0, op # $t0 <- funct
        beq $t0, i_bne, bneProcedureI # if (funct == r_jr) jrProcedureR
        beq $t0, i_lui, luiProcedureI # if (funct == r_addu) adduProcedure
        beq $t0, i_ori, oriProcedureI # if (funct == r_addu) adduProcedure
        beq $t0, i_lw, lwProcedureI # if (funct == r_addu) adduProcedure
        beq $t0, i_sw, swProcedureI # if (funct == r_addu) adduProcedure
        beq $t0, i_addiu, addiuProcedureI # if (funct == i_addi) adduProcedure

        # Se não for nenhum dos dois, entra em addiuProcedureI
        #Execuções dos procedimentos do tipo I nos registradores simulados
        addiProcedureI: # rt = rs + imm16
            # Carrega valores da instrução
            lw $t0, rt # $t0 <- rt
            lw $t1, rs # $t1 <- rs
            lw $t2, imm16 # $t2 <- imm16

            # Calcula o endereço do registrador simulado
            la $t3, regs # Carrega o endereço do vetor regs

            sll $t0, $t0, 2 # Multiplica por 4 o endereço de $t0 (rt)
            add $t0, $t3, $t0 # Calcula o endereço do registrador recebido em rt

            sll $t1, $t1, 2 # Multiplica por 4 o endereço de $t0 (rs)
            add $t1, $t3, $t1 # Calcula o endereço do registrador recebido em rs

            move $t3, $zero # Zera o valor do registrador
            
            # Extensão de sinal do imediato de 16 bits
            addi $sp, $sp, -4 # Reserva uma word na pilha
            sw $ra, 0($sp) # Salva o $ra na pilha

            move $a0, $t2 # Passa o imediato de 16 bits
            jal extendSignal # Extende o sinal do imediato
            move $t2, $v0 # Recebe o imediato de 16 bits com sinal extendido

            lw $ra, 0($sp) # Carrega o $ra da pilha
            addi $sp, $sp, 4 # Corrige a pilha para o valor original

            lw $t4, 0($t1) # Carrega o valor do registrador $t1 (rs)
            add $t3, $t4, $t2 # Realiza SOMA do valor de rs com valor imediato de 16 bits e coloca no rt
            sw $t3, 0($t0) # 0($t0) = $t3, sendo que $t0 é o valor de rd dentro de regs

            j continue # Pula para a função que continua o loop
        addiuProcedureI: # rt = rs + imm16 (unsigned)
            # Carrega valores da instrução
            lw $t0, rt # $t0 <- rt
            lw $t1, rs # $t1 <- rs
            lw $t2, imm16 # $t2 <- imm16

            # Calcula o endereço do registrador simulado
            la $t3, regs # Carrega o endereço do vetor regs

            sll $t0, $t0, 2 # Multiplica por 4 o endereço de $t0 (rt)
            add $t0, $t3, $t0 # Calcula o endereço do registrador recebido em rt

            sll $t1, $t1, 2 # Multiplica por 4 o endereço de $t0 (rs)
            add $t1, $t3, $t1 # Calcula o endereço do registrador recebido em rs

            move $t3, $zero # Zera o valor do registrador
        
            # Extensão de sinal do imediato de 16 bits
            addi $sp, $sp, -4 # Reserva uma word na pilha
            sw $ra, 0($sp) # Salva o $ra na pilha

            move $a0, $t2 # Passa o imediato de 16 bits
            jal extendSignal # Extende o sinal do imediato
            move $t2, $v0 # Recebe o imediato de 16 bits com sinal extendido

            lw $ra, 0($sp) # Carrega o $ra da pilha
            addi $sp, $sp, 4 # Corrige a pilha para o valor original

            lw $t4, 0($t1) # Carrega o valor do registrador $t1 (rs)
            addu $t3, $t4, $t2 # Realiza SOMA do valor de rs com valor imediato de 16 bits e coloca no rt

            sw $t3, 0($t0) # 0($t0) = $t3, sendo que $t0 é o valor de rd dentro de regs

            j continue # Pula para a função que continua o loop
        
        bneProcedureI: # branch not equal rt, rs, imm16
            # Carrega valores da instrução
            lw $t0, rt # $t0 <- rt
            lw $t1, rs # $t1 <- rs
            lw $t2, imm16 # $t2 <- imm16

            # Calcula o endereço do registrador simulado
            la $t3, regs # Carrega o endereço do vetor regs

            sll $t0, $t0, 2 # Multiplica por 4 o endereço de $t0 (rt)
            add $t0, $t3, $t0 # Calcula o endereço do registrador recebido em rt

            sll $t1, $t1, 2 # Multiplica por 4 o endereço de $t0 (rs)
            add $t1, $t3, $t1 # Calcula o endereço do registrador recebido em rs

            lw $t0, 0($t0) # Carrega valor de rt para $t0
            lw $t1, 0($t1) # Carrega valor de rs para $t1
            beq $t1, $t0, continue

            advancePC:
                # Recebe o início do segmento de texto
                lw $t3, pc # $t3 <- pc
            
                sll $t2, $t2, 2

                add $t2, $t2, $t3 # Soma $t2 a $t3 para encontrar a posição dentro do segmento de dados simulado
                sw $t2, pc # pc <- $t2, endereço simulado a partir do label recebido em imm16
                                
                j continue # Pula para a função que continua o loop

        luiProcedureI: # rt = imm16 << 16
            # Carrega valores da instrução
            lw $t0, rt # $t0 <- rt
            lw $t1, imm16 # $t2 <- imm16

            # Calcula o endereço do registrador simulado
            la $t3, regs # Carrega o endereço do vetor regs

            sll $t0, $t0, 2 # Multiplica por 4 o endereço de $t0 (rt)
            add $t0, $t3, $t0 # Calcula o endereço do registrador recebido em rt

            sll $t1, $t1, 16 # Desloca 16 bits desse imediato para a esquerda
            
            sw $t1, 0($t0) # Salva no registrador do campo rt

            j continue # Pula para a função que continua o loop

        oriProcedureI: # rt = rs | imm16
            # Carrega valores da instrução
            lw $t0, rt # $t0 <- rt
            lw $t1, rs # $t1 <- imm16
            lw $t2, imm16 # $t2 <- rs

            # Calcula o endereço do registrador simulado
            la $t3, regs # Carrega o endereço do vetor regs

            sll $t0, $t0, 2 # Multiplica por 4 o endereço de $t0 (rt)
            add $t0, $t3, $t0 # Calcula o endereço do registrador recebido em rt

            sll $t1, $t1, 2 # Multiplica por 4 o endereço de $t0 (rs)
            add $t1, $t3, $t1 # Calcula o endereço do registrador recebido em rs

            lw $t1, 0($t1) # Carrega o valor de rs para $t1

            or $t2, $t1, $t2 # $t2 | $t1 , or entre valor de rs e valor calculado e guarda em $t0 (rt)

            sw $t2, 0($t0) # Salva no registrador de rt

            j continue # Pula para a função que continua o loop  

        lwProcedureI: # rt = valor(rs + imm16)
            # Carrega valores da instrução
            lw $t0, rt # $t0 <- rt
            lw $t1, rs # $t1 <- imm16
            lw $t2, imm16 # $t2 <- rs

            # Calcula o endereço do registrador simulado
            la $t3, regs # Carrega o endereço do vetor regs

            sll $t0, $t0, 2 # Multiplica por 4 o endereço de $t0 (rt)
            add $t0, $t3, $t0 # Calcula o endereço do registrador recebido em rt

            sll $t1, $t1, 2 # Multiplica por 4 o endereço de $t1 (rs)
            add $t1, $t3, $t1 # Calcula o endereço do registrador recebido em rs

            lw $t4, 0($t1) # Recebe o valor do rs (que é um endereço)

            add $t4, $t4, $t2 # Soma o valor do rs + offset

            lw $t5, 0($t4) # Carrega para $t4 o valor do endereço calculado previamente em $t4 (rs + offset)

            sw $t5, 0($t0) # Salva o valor do rs no registrador rt (simulado)

            j continue # Pula para a função que continua o loop

        swProcedureI: # valor(rs + imm16) = rt
            # Carrega valores da instrução
            lw $t0, rt # $t0 <- rt (passa esse valor)
            lw $t1, rs # $t1 <- rs (salva esse)
            lw $t2, imm16 # $t2 <- imm16

            # Calcula o endereço do registrador simulado
            la $t3, regs # Carrega o endereço do vetor regs

            sll $t0, $t0, 2 # Multiplica por 4 o endereço de $t0 (rt)
            add $t0, $t3, $t0 # Calcula o endereço do registrador recebido em rt

            sll $t1, $t1, 2 # Multiplica por 4 o endereço de $t1 (rs)
            add $t1, $t3, $t1 # Calcula o endereço do registrador recebido em rs
            
            lw $t4, 0($t0) # Carrega o valor de rt
            lw $t5, 0($t1) # Carrega o valor de rs

            add $t5, $t5, $t2 # rs + offset

            sw $t4, 0($t5) # Salva o valor do rs + offset no registrador rt (simulado)

            j continue # Pula para a função que continua o loop

    handleSyscall:
        la $t0, regs # Carrega o endereço do vetor de registradores
        lw $v0, 8($t0) # Carrega o endereço de $v0 simulado para $v0
        lw $a0, 16($t0) # Carrega o endereço de $a0 simulado para $a0
        lw $a1, 20($t0) # Carrega o endereço de $a1 simulado para $a1
        lw $a2, 24($t0) # Carrega o endereço de $a2 simulado para $a2

        beq $v0, svc_exit, handleExit

        syscall # Faz uma chamada ao sistema simulada (os valores carregados para os argumentos são simulados)
        
        sw $v0, 8($t0) # Salva o valor de $v0 no $v0 simulado

        j continue # Pula para a função que continua o loop

        # Trata a chamada ao serviço 10 (exit) no programa simulado
        handleExit:

            jr $ra # Retorna para o procedimento main

    handleTypeR:
        move $t1, $t0 # Copia o valor original da instrução para $t1
        andi $t1, $t1, mask_rs # Aplica a máscara de RS à instrução
        srl $t1, $t1, shift_rs # Desloca os bits necessários
        sw $t1, rs # Salva o valor de RS da instrução na memória

        move $t1, $t0 # Copia o valor original da instrução para $t1
        andi $t1, $t1, mask_rt # Aplica a máscara de RT à instrução
        srl $t1, $t1, shift_rt # Desloca os bits necessários
        sw $t1, rt # Salva o valor de RT da instrução na memória

        move $t1, $t0 # Copia o valor original da instrução para $t1
        andi $t1, $t1, mask_rd # Aplica a máscara de RD à instrução
        srl $t1, $t1, shift_rd # Desloca os bits necessários
        sw $t1, rd # Salva o valor de RD da instrução na memória

        move $t1, $t0 # Copia o valor original da instrução para $t1
        andi $t1, $t1, mask_shamt # Aplica a máscara de SHAMT à instrução
        srl $t1, $t1, shift_shamt # Desloca os bits necessários
        sw $t1, shamt # Salva o valor de SHAMT da instrução na memória
        
        move $t1, $t0 # Copia o valor original da instrução para $t1
        andi $t1, $t1, mask_funct # Aplica a máscara de FUNCT à instrução
        sw $t1, funct # Salva o valor de FUNCT da instrução na memória

        # Verifica campo FUNCT e salta para a execução do seu tipo
        lw $t0, funct # $t0 <- FUNCT
        lw $t1, op # $t1 <- OPCODE
        beq $t0, r_jr, jrProcedureR # if(funct == r_jr) jrProcedureR
        beq $t0, r_addu, adduProcedureR # if(funct == r_addu) adduProcedureR
        beq $t1, r_mul, mulProcedureR # if(funct == r_mul) mulProcedureR

        # Se não for nenhum dos dois, entra em addProcedureR
        #Execuções dos procedimentos do tipo R nos registradores simulados
        addProcedureR: # rd = rs + rt
        # Carrega valores da instrução
            lw $t0, rd # $t0 <- rd
            lw $t1, rs # $t1 <- rs
            lw $t2, rt # $t2 <- rt

            # Calcula o endereço do registrador simulado
            la $t3, regs # Carrega o endereço do vetor regs

            sll $t0, $t0, 2 # Multiplica por 4 o endereço de $t0 (rd)
            add $t0, $t3, $t0 # Calcula o endereço do registrador recebido em rd

            sll $t1, $t1, 2 # Multiplica por 4 o endereço de $t0 (rs)
            add $t1, $t3, $t1 # Calcula o endereço do registrador recebido em rs

            sll $t2, $t2, 2 # Multiplica por 4 o endereço de $t0 (rt)
            add $t2, $t3, $t2 # Calcula o endereço do registrador recebido em rt

            move $t3, $zero # Zera o valor do registrador

            lw $t4, 0($t1) # Carrega o valor do registrador $t1 (rs)
            lw $t5, 0($t2) # Carrega o valor do registrador $t1 (rt)
            add $t3, $t4, $t5 # Realiza SOMA o valor de rs e rt e coloca em $t3
    
            sw $t3, 0($t0) # 0($t0) = $t3, sendo que $t0 é o valor de rd dentro de regs

            j continue # Pula para a função que continua o loop

        adduProcedureR: # rd = rs + rt (unsigned)
            # Carrega valores da instrução
            lw $t0, rd # $t5 <- rd
            lw $t1, rs # $t6 <- rs
            lw $t2, rt # $t7 <- rt

            # Calcula o endereço do registrador simulado
            la $t3, regs # Carrega o endereço do vetor regs

            sll $t0, $t0, 2 # Multiplica por 4 o endereço de $t0 (rd)
            add $t0, $t3, $t0 # Calcula o endereço do registrador recebido em rd

            sll $t1, $t1, 2 # Multiplica por 4 o endereço de $t0 (rs)
            add $t1, $t3, $t1 # Calcula o endereço do registrador recebido em rs

            sll $t2, $t2, 2 # Multiplica por 4 o endereço de $t0 (rt)
            add $t2, $t3, $t2 # Calcula o endereço do registrador recebido em rt

            move $t3, $zero # Zera o valor do registrador

            lw $t4, 0($t1) # Carrega o valor do registrador $t1 (rs)
            lw $t5, 0($t2) # Carrega o valor do registrador $t1 (rt)

            addu $t3, $t4, $t5 # Realiza SOMA UNSIGNED com o valor de rs e rt e coloca em $t3
    
            sw $t3, 0($t0) # 0($t0) = $t3, sendo que $t0 é o valor de rd dentro de regs

            j continue # Pula para a função que continua o loop

        jrProcedureR: # j -> rs
            # Carrega valores da instrução
            lw $t0, rs # $t0 <- rs

            # Calcula o endereço do registrador simulado
            la $t3, regs # Carrega o endereço do vetor regs

            sll $t0, $t0, 2 # Multiplica por 4 o endereço de $t0 (rd)
            add $t0, $t3, $t0 # Calcula o endereço do registrador recebido em rs

            lw $t4, 0($t0) # Carrega o valor do registrador $t1 (rs)
    
            sw $t4, pc # 0($t0) = $t3, sendo que $t0 é o valor de rd dentro de regs

            j continue # Pula para a função que continua o loop
        mulProcedureR: # rd = rs * rt
            # Carrega valores da instrução
            lw $t0, rd # $t0 <- rd
            lw $t1, rs # $t1 <- rs
            lw $t2, rt # $t2 <- rt
            #Calcula endereços dentro dos registradores simulados
             la $t3, regs # Carrega o endereço do vetor regs

            sll $t0, $t0, 2 # Multiplica por 4 o endereço de $t0 (rd)
            add $t0, $t3, $t0 # Calcula o endereço do registrador recebido em rd

            sll $t1, $t1, 2 # Multiplica por 4 o endereço de $t0 (rs)
            add $t1, $t3, $t1 # Calcula o endereço do registrador recebido em rs

            sll $t2, $t2, 2 # Multiplica por 4 o endereço de $t0 (rt)
            add $t2, $t3, $t2 # Calcula o endereço do registrador recebido em rt

            move $t3, $zero # Zera o valor do registrador

            lw $t4, 0($t1) # Carrega o valor do registrador $t1 (rs)
            lw $t5, 0($t2) # Carrega o valor do registrador $t1 (rt)

            mul $t3, $t4, $t5 # Multiplica $t1 (rs) por $t2 (rt) e salva $t3

            sw $t3, 0($t0) # Salva valor da multiplicação em $t0 (rd)

            j continue # Pula para a função que continua o loop

    handleTypeJ:
        move $t1, $t0 # Copia o valor original da instrução para $t1
        andi $t1, $t1, mask_imm26 # Aplica a máscara de RT à instrução
        sw $t1, imm26 # Salva o valor de IMM26 da instrução

        lw $t2, op
        #if (funct == j_jump) salta para jProcedureJ, else executa jalProcedureJ
        beq $t2, j_jump, jProcedureJ

        jalProcedureJ: # j -> imm26; $ra = pc+4
            # Carrega valores da instrução
            lw $t0, imm26 # $t0 <- imm26

            # Recebe o início do segmento de texto
            la $t1, text_buffer # $t1 <- início de text_buffer

            li $t2, text_adress_ini # $t2 <- 0x00100000
            sub $t0, $t0, $t2 # Calcula $t0 - 0x0010000 e descobre quantas words precisamos pular
            sll $t0, $t0, 2 # Multiplica por 4 para pular os bytes necessários
            add $t0, $t0, $t1 # Soma $t0 a $t1 para encontrar a posição dentro do segmento de dados simulado
            
            # Calcula novo endereço de pc
            lw $t3, pc # $t3 <- adress pc
            la $t4, regs# $t4 <- adress do vetor de registradores simulados
            sw $t3, 124($t4) # Salva no registrador simulado de RA o valor de pc incrementado

            sw $t0, pc # pc <- $t0, endereço simulado a partir do label recebido em imm26

            j continue # Pula para a função que continua o loop
        
        jProcedureJ: # j -> imm26
            # Carrega valores da instrução
            lw $t0, imm26 # $t0 <- rs

            # Recebe o início do segmento de texto
            la $t1, text_buffer # $t1 <- início de text_buffer

            li $t2, text_adress_ini # $t2 <- 0x00400000
            sub $t0, $t0, $t2 # Calcula $t0 - 0x0040000 e atribui a $t0
            sll $t0, $t0, 2 # Multiplica por 4 para pular os bytes necessários
            add $t0, $t0, $t1 # Soma $t0 a $t1 para encontrar a posição dentro do segmento de dados simulado
            
            sw $t0, pc # pc <- $t0, endereço simulado a partir do label recebido em imm26

            j continue # Pula para a função que continua o loop

    continue:

    # Comparação para ver se continua o loop
    lw $s1, instruction_number # $s1 <- valor de instruction_number
    lw $s2, instruction_counter # $s2 <- valor de instruction_counter

    bne $s1, $s2, handleInstruction #if (instruction_counter != instruction_number) handleInstruction

    jr $ra # Retorna para main

extendSignal: # Extende o sinal dos números de 16 bits
    move $t9, $a0 # Pega o valor do argumento

    sll $t9, $t9, 16 # Desloca 16 bits logicamente para a esquerda
    sra $t9, $t9, 16 # Desloca 16 bits aritmeticamente para a direita

    move $v0, $t9 # Salva o retorno

    jr $ra # Retorna para o procedimento caller

printOpeningMsg:
    li $v0, svc_print_str  # $v0 <- 4 (svc_print_str)
    la $a0, str_opening_title # $a0 <- Endereço de "Número de execuções: " (str_exec_number)
    syscall # Faz uma chamada ao serviço 4: imprimir string

    li $v0, svc_print_str  # $v0 <- 4 (svc_print_str)
    la $a0, str_opening_msg # $a0 <- Endereço de "Número de execuções: " (str_exec_number)
    syscall # Faz uma chamada ao serviço 4: imprimir string

    jr $ra # Retorna para o procedimento caller

printExecutions: # Imprime o número de execuções do programa
    li $v0, svc_print_char  # $v0 <- 11 (svc_print_char)
    li $a0, '\n' # $a0 <- '\n'
    syscall # Faz uma chamada ao serviço 11: imprimir caracter

    li $v0, svc_print_str  # $v0 <- 4 (svc_print_str)
    la $a0, str_exec_number # $a0 <- Endereço de "Número de execuções: " (str_exec_number)
    syscall # Faz uma chamada ao serviço 4: imprimir string

    li $v0, svc_print_integer  # $v0 <- 1 (svc_print_integer)
    lw $a0, instruction_counter # $a0 <- valor de instruction_number
    syscall # Faz uma chamada ao serviço 1: imprimir inteiro

    li $v0, svc_print_char # $v0 <- 11 (svc_print_char)
    li $a0, '\n' # $a0 <- '\n'
    syscall # Faz uma chamada ao serviço 11: imprimir caracter

    jr $ra # Retorna para o procedimento caller

printOutputStr: # Imprime label de output do programa simulado
    li $v0, svc_print_char  # $v0 <- 11 (svc_print_char)
    li $a0, '\n' # $a0 <- '\n'
    syscall # Faz uma chamada ao serviço 11: imprimir caracter

    li $v0, svc_print_str  # $v0 <- 4 (svc_print_str)
    la $a0, str_program_output # $a0 <- Endereço de "OUTPUT DO PROGRAMA: " (str_program_output)
    syscall # Faz uma chamada ao serviço 4: imprimir string    

    jr $ra # Retorna para o procedimento caller

printRegistersStr: # Imprime label de texto para registradores no output
    # Imprime um espaço entre o output do programa e os registradores
    li $v0, svc_print_char  # $v0 <- serviço de impressão de char (11)
    li $a0, '\n' # $a0 <- quebra de linha
    syscall # Faz uma chamada ao SO 

    li $v0, svc_print_str  # $v0 <- 4 (svc_print_str)
    la $a0, str_regs # $a0 <- Endereço de "REGISTRADORES: (número, valor)\n" (str_regs)
    syscall # Faz uma chamada ao serviço 4: imprimir string

    jr $ra # Retorna para o procedimento caller

printRegisters: # Imprime os registradores alterados durante o programa
    la $t0, print_counter
    lw $t1, 0($t0)
    li $t2, 128

    srl $t3, $t1, 2

    li $v0, svc_print_integer
    move $a0, $t3
    syscall # Faz uma chamada ao SO

    li $v0, svc_print_char 
    li $a0, ':'
    syscall # Faz uma chamada ao SO

    li $v0, svc_print_char 
    li $a0, ' '
    syscall # Faz uma chamada ao SO

    li $v0, svc_print_hex # Serviço de imprimir hexadecimal
    la $t4, regs # $t0 <- instruction
    add $t4, $t4, $t1
    lw $t5, 0($t4)
    move $a0, $t5 # Passa instruction para ser impresso	                  
    syscall # Faz uma chamada ao SO
    
    li $v0, svc_print_char 
    li $a0, '\n'
    syscall # Faz uma chamada ao SO

    add $t1, $t1, 4
    sw $t1, 0($t0)

    bne $t1, $t2, printRegisters # if ($t1 != $t2) printRegisters

    jr $ra # Retorna para o procedimento caller

exit: # Termina a execução do programa
    li $v0, svc_exit # $v0 <- 4 (svc_exit)
    syscall # Faz uma chamada ao serviço 10: terminar execução
          	
.data # Diretiva dos dados a serem usados

# Dados referentes as diretivas simuladas (.text e .data). Seus endereços são declarados por último para evitar problemas de alinhamento de word.
data_buffer: .space 4096 # Vetor de dados data.bin (contém uma string de 4096 bytes)
text_buffer: .space 192 # Vetor de instruções text.bin 
data_descriptor: .space 4 # Descritor do data.bin
text_descriptor: .space 4 # Descritor do text.bin

# Campos simulados
pc: .space 4 # Program counter
instruction: .space 4 # Campo da instrução
op: .space 4 # Campo da operação
rs: .space 4 # Campo rs
rt: .space 4 # Campo rt
rd: .space 4 # Campo rd
imm16: .space 4 # Campo imediato de 16 bits
imm26: .space 4 # Campo imediato de 26 bits
shamt: .space 4 # Campo shift amount
funct: .space 4 # Campo funct (auxiliar da operação)

# Registradores simulados (transformar em vetor)
regs: .space 128 # Vetor que simula os registradores do mips

# Stack
stack: .space stack_size # Vetor que simula a pilha (valor de memória da pilha arbitrário)

# Contadores
instruction_number: .word 0 # Número de instruções a serem executadas
instruction_counter: .word 0 # Contador de instruções executadas
print_counter: .word 0 # Contador pra impressão

# É necessário declarar as strings aqui
# Necessário inserir o endereço completo da pasta antes do arquivo
text_file_adress: .asciiz "/home/hierror/Documents/Projects/mips-processor/text.bin"
#text_file_adress: .asciiz "/media/regis/3EBC771EBC76D03F/Doc/Ufsm/mips-processor/text.bin"
data_file_adress: .asciiz "/home/hierror/Documents/Projects/mips-processor/data.bin"
#data_file_adress: .asciiz "/media/regis/3EBC771EBC76D03F/Doc/Ufsm/mips-processor/data.bin"

# Strings usadas pelo programa
str_opening_title: .asciiz "SIMULADOR DO PROCESSADOR MIPS\n(Simulando instruções do exercicio12.s)\n\n"
str_opening_msg: .asciiz "Esse programa tem o objetivo de simular um processador MIPS executando o exercicio12.s.\n"
str_user_input: .asciiz "Insira o n° de instruções a serem executadas (1-98): " # String para input do usuário
str_open_error: .asciiz "ERRO: Erro ao abrir o arquivo\n" # String de erro ao abrir arquivo
str_read_error: .asciiz "ERRO: Erro ao ler o arquivo\n" # String de erro ao ler arquivo
str_exec_number: .asciiz "Número de execuções: " # String de label do número de instruções que serão executas
str_program_output: .asciiz "OUTPUT DO PROGRAMA: " # String de label do output do exercicio012.s
str_regs: .asciiz "REGISTRADORES: (número, valor)\n" # String de label para registradores e seus valores
