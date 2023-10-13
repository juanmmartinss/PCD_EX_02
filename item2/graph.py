
# Daniel Ferreira Martins, RA: 156.369
# Savio Augusto Machado Araujo, RA: 156.584
# Juan Marcos Martins, RA: 156.470


import matplotlib.pyplot as plt

n_thread = [1, 2, 4, 8]

time_critical = [472.346, 247.187, 149.155, 102.834]
time_reduction = [472.258, 251.320, 148.138, 102.618]

plt.figure(figsize=(10, 6))
plt.plot(n_thread, time_critical, marker='o', color='r', label='Critical')
plt.plot(n_thread, time_reduction, marker='o', color='b', label='Reduction')

plt.xlabel('Número de Threads')
plt.ylabel('Tempo de Execução (s)')
plt.title('')
plt.xticks(n_thread)
plt.legend()
plt.grid()
plt.show()

speedup_critical = []
speedup_reduction = []

for i in range(4):
    speedup_critical.append(time_critical[0]/time_critical[i])
    speedup_reduction.append(time_reduction[0]/time_reduction[i])

plt.figure(figsize=(10, 6))
plt.plot(n_thread, speedup_critical, marker='o', color='r', label='Critical')
plt.plot(n_thread, speedup_reduction, marker='o', color='b', label='Reduction')

plt.xlabel('Número de Threads')
plt.ylabel('Speedup')
plt.title('')
plt.xticks(n_thread)
plt.legend()
plt.grid()
plt.show()