import subprocess


def run(comandos):
  for comando in comandos:
    processo = subprocess.run(comando, shell=True, capture_output=True, text=True)
    
    if processo.returncode == 0:
        print(processo.stdout)
    else:
        print(processo.stderr)


cmds = [
  'gcc -fopenmp -o ompA OpenMP_A.c',
  'gcc -fopenmp -o ompB OpenMP_B.c',
  'ompA 2000 8',
  'ompA 2000 4',
  'ompA 2000 2',
  'ompA 2000 1',
  'ompB 2000 8',
  'ompB 2000 4',
  'ompB 2000 2',
  'ompB 2000 1'
]
run(cmds)