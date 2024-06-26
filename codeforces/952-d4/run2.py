#!/usr/bin/env python3
import subprocess
import os
import sys
import select
import termios
import tty

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

# Função para ler a entrada caractere por caractere e enviar ao programa
def read_input_to_program(proc):
    old_settings = termios.tcgetattr(sys.stdin)
    tty.setcbreak(sys.stdin.fileno())
    try:
        while True:
            rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
            if rlist:
                char = os.read(sys.stdin.fileno(), 1)
                if char:
                    proc.stdin.write(char.decode())
                    proc.stdin.flush()
                else:
                    break
            if proc.poll() is not None:
                break
    except BrokenPipeError:
        pass
    finally:
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_settings)
        consume_input()

# Função para consumir a entrada e ignorar o restante
def consume_input():
    old_settings = termios.tcgetattr(sys.stdin)
    tty.setcbreak(sys.stdin.fileno())
    try:
        while True:
            rlist, _, _ = select.select([sys.stdin], [], [], 0.1)
            if rlist:
                char = os.read(sys.stdin.fileno(), 1)
                if not char:
                    break
    finally:
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, old_settings)

# Executa o programa compilado
program = subprocess.Popen(["/tmp/out"], stdin=subprocess.PIPE, stdout=sys.stdout, stderr=sys.stderr, text=True)

# Lê a entrada e envia ao programa
read_input_to_program(program)

# Aguarda o término do processo
program.wait()

