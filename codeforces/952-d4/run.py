#!/usr/bin/env python3

import subprocess
import os
import sys
import select

# Verifica se um arquivo foi passado como argumento
if len(sys.argv) < 2:
    print("Uso: python3 run.py <arquivo.cpp>")
    sys.exit(1)

# Compila o código C++
source_file = sys.argv[1]
compile_command = ["g++", "-std=c++20", "-Wall", "-Wfatal-errors", "-fsanitize=address,undefined", source_file, "-o", "/tmp/out"]
compile_process = subprocess.run(compile_command)

# Verifica se a compilação foi bem-sucedida
if compile_process.returncode != 0:
    print("Compilação falhou.")
    sys.exit(1)

# Executa o programa compilado
program = subprocess.Popen(["/tmp/out"], stdin=subprocess.PIPE, stdout=sys.stdout, stderr=sys.stderr, text=True)

# Função para ler a entrada caractere por caractere e enviar ao programa
def read_input_to_program(proc):
    while True:
        # Usa select para esperar por entrada disponível
        rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
        if rlist:
            char = sys.stdin.read(1)
            if char:
                try:
                    proc.stdin.write(char)
                    proc.stdin.flush()
                except BrokenPipeError:
                    # Se o programa falhou, pare de enviar entrada
                    break
            else:
                # EOF
                break
        # Verifica se o programa ainda está rodando
        if proc.poll() is not None:
            break

# Lê a entrada e envia ao programa
read_input_to_program(program)

# Aguarda o término do processo
program.wait()

