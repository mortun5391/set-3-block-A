import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

random_data = pd.read_csv('random_results.csv')
reverse_data = pd.read_csv('reverse_results.csv')
almost_data = pd.read_csv('almost_results.csv')

plt.figure(figsize=(12, 8))
plt.plot(random_data['Size'], random_data['Standard'], 'k-', linewidth=2, label='Standard Merge Sort')
for threshold in [5, 15, 30, 50]:
    plt.plot(random_data['Size'], random_data[f'Hybrid_{threshold}'], 
             label=f'Hybrid (threshold={threshold})')

plt.xlabel('Размер массива')
plt.ylabel('Время (микросекунды)')
plt.title('Сравнение алгоритмов сортировки - Случайные массивы')
plt.legend()
plt.grid(True, alpha=0.3)
plt.savefig('random_comparison.png', dpi=300, bbox_inches='tight')
plt.show()

plt.figure(figsize=(12, 8))
plt.plot(reverse_data['Size'], reverse_data['Standard'], 'k-', linewidth=2, label='Standard Merge Sort')
for threshold in [5, 15, 30, 50]:
    plt.plot(reverse_data['Size'], reverse_data[f'Hybrid_{threshold}'], 
             label=f'Hybrid (threshold={threshold})')

plt.xlabel('Размер массива')
plt.ylabel('Время (микросекунды)')
plt.title('Сравнение алгоритмов сортировки - Обратно отсортированные массивы')
plt.legend()
plt.grid(True, alpha=0.3)
plt.savefig('reverse_comparison.png', dpi=300, bbox_inches='tight')
plt.show()

plt.figure(figsize=(12, 8))
plt.plot(almost_data['Size'], almost_data['Standard'], 'k-', linewidth=2, label='Standard Merge Sort')
for threshold in [5, 15, 30, 50]:
    plt.plot(almost_data['Size'], almost_data[f'Hybrid_{threshold}'], 
             label=f'Hybrid (threshold={threshold})')

plt.xlabel('Размер массива')
plt.ylabel('Время (микросекунды)')
plt.title('Сравнение алгоритмов сортировки - Почти отсортированные массивы')
plt.legend()
plt.grid(True, alpha=0.3)
plt.savefig('almost_comparison.png', dpi=300, bbox_inches='tight')
plt.show()

plt.figure(figsize=(12, 8))
thresholds = [5, 10, 15, 20, 30, 50]

avg_times_random = [random_data[f'Hybrid_{t}'].mean() for t in thresholds]
avg_times_reverse = [reverse_data[f'Hybrid_{t}'].mean() for t in thresholds]
avg_times_almost = [almost_data[f'Hybrid_{t}'].mean() for t in thresholds]

plt.plot(thresholds, avg_times_random, 'o-', label='Случайные массивы')
plt.plot(thresholds, avg_times_reverse, 's-', label='Обратно отсортированные')
plt.plot(thresholds, avg_times_almost, '^-', label='Почти отсортированные')

plt.xlabel('Порог переключения')
plt.ylabel('Среднее время (микросекунды)')
plt.title('Оптимальный порог переключения на Insertion Sort')
plt.legend()
plt.grid(True, alpha=0.3)
plt.savefig('optimal_threshold.png', dpi=300, bbox_inches='tight')
plt.show()

print("Графики успешно созданы!")