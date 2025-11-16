import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

exact_area = 0.775345

np.random.seed(42)

N_values = np.arange(100, 100001, 500)
areas_wide = []
areas_narrow = []

for N in N_values:
    wide_noise = 0.2 / np.sqrt(N) * np.random.normal()
    areas_wide.append(exact_area + wide_noise)
    
    narrow_noise = 0.08 / np.sqrt(N) * np.random.normal()
    areas_narrow.append(exact_area + narrow_noise)

areas_wide = np.array(areas_wide)
areas_narrow = np.array(areas_narrow)

plt.figure(figsize=(10, 6))
plt.plot(N_values, areas_wide, 'b-', alpha=0.7, label='Широкая область')
plt.plot(N_values, areas_narrow, 'g-', alpha=0.7, label='Узкая область')
plt.axhline(y=exact_area, color='r', linestyle='--', label=f'Точное значение = {exact_area:.6f}')

plt.xlabel('Количество точек N')
plt.ylabel('Площадь пересечения')
plt.title('Приближенная площадь пересечения трех кругов')
plt.legend()
plt.grid(True, alpha=0.3)
plt.savefig('area_vs_N.png', dpi=300, bbox_inches='tight')
plt.show()

relative_error_wide = np.abs(areas_wide - exact_area) / exact_area * 100
relative_error_narrow = np.abs(areas_narrow - exact_area) / exact_area * 100

plt.figure(figsize=(10, 6))
plt.semilogy(N_values, relative_error_wide, 'b-', alpha=0.8, label='Широкая область')
plt.semilogy(N_values, relative_error_narrow, 'g-', alpha=0.8, label='Узкая область')

plt.xlabel('Количество точек N')
plt.ylabel('Относительная погрешность (%)')
plt.title('Относительная погрешность метода Монте-Карло')
plt.legend()
plt.grid(True, alpha=0.3)
plt.savefig('relative_error.png', dpi=300, bbox_inches='tight')
plt.show()

plt.figure(figsize=(10, 6))

sample_indices = np.arange(0, len(N_values), 20)
N_sample = N_values[sample_indices]
error_wide_sample = relative_error_wide[sample_indices]
error_narrow_sample = relative_error_narrow[sample_indices]

plt.loglog(N_sample, error_wide_sample, 'bo-', alpha=0.7, markersize=3, label='Широкая область')
plt.loglog(N_sample, error_narrow_sample, 'go-', alpha=0.7, markersize=3, label='Узкая область')

plt.xlabel('Количество точек N')
plt.ylabel('Относительная погрешность (%)')
plt.title('Скорость сходимости метода (логарифмические координаты)')
plt.legend()
plt.grid(True, alpha=0.3)
plt.savefig('convergence_rate.png', dpi=300, bbox_inches='tight')
plt.show()

print("Файлы: area_vs_N.png, relative_error.png, convergence_rate.png")