import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

random_data = pd.read_csv('quick_random_results.csv')
reverse_data = pd.read_csv('quick_reverse_results.csv')
almost_data = pd.read_csv('quick_almost_results.csv')

plt.figure(figsize=(12, 8))
plt.plot(random_data['Size'], random_data['StandardQuickSort'], 'r-', linewidth=2, label='Standard Quick Sort')
plt.plot(random_data['Size'], random_data['HybridQuickSort'], 'b-', linewidth=2, label='Hybrid Quick Sort (Introsort)')

plt.xlabel('Размер массива')
plt.ylabel('Время (микросекунды)')
plt.title('Сравнение алгоритмов быстрой сортировки - Случайные массивы')
plt.legend()
plt.grid(True, alpha=0.3)
plt.savefig('quick_random_comparison.png', dpi=300, bbox_inches='tight')
plt.show()

plt.figure(figsize=(12, 8))
plt.plot(reverse_data['Size'], reverse_data['StandardQuickSort'], 'r-', linewidth=2, label='Standard Quick Sort')
plt.plot(reverse_data['Size'], reverse_data['HybridQuickSort'], 'b-', linewidth=2, label='Hybrid Quick Sort (Introsort)')

plt.xlabel('Размер массива')
plt.ylabel('Время (микросекунды)')
plt.title('Сравнение алгоритмов быстрой сортировки - Обратно отсортированные массивы')
plt.legend()
plt.grid(True, alpha=0.3)
plt.savefig('quick_reverse_comparison.png', dpi=300, bbox_inches='tight')
plt.show()

plt.figure(figsize=(12, 8))
plt.plot(almost_data['Size'], almost_data['StandardQuickSort'], 'r-', linewidth=2, label='Standard Quick Sort')
plt.plot(almost_data['Size'], almost_data['HybridQuickSort'], 'b-', linewidth=2, label='Hybrid Quick Sort (Introsort)')

plt.xlabel('Размер массива')
plt.ylabel('Время (микросекунды)')
plt.title('Сравнение алгоритмов быстрой сортировки - Почти отсортированные массивы')
plt.legend()
plt.grid(True, alpha=0.3)
plt.savefig('quick_almost_comparison.png', dpi=300, bbox_inches='tight')
plt.show()

plt.figure(figsize=(12, 8))
ratio_random = random_data['HybridQuickSort'] / random_data['StandardQuickSort']
ratio_reverse = reverse_data['HybridQuickSort'] / reverse_data['StandardQuickSort']
ratio_almost = almost_data['HybridQuickSort'] / almost_data['StandardQuickSort']

plt.plot(random_data['Size'], ratio_random, 'o-', label='Случайные массивы', alpha=0.7)
plt.plot(reverse_data['Size'], ratio_reverse, 's-', label='Обратно отсортированные', alpha=0.7)
plt.plot(almost_data['Size'], ratio_almost, '^-', label='Почти отсортированные', alpha=0.7)

plt.axhline(y=1, color='k', linestyle='--', alpha=0.5)
plt.xlabel('Размер массива')
plt.ylabel('Отношение времени (Гибридный / Стандартный)')
plt.title('Эффективность гибридного алгоритма относительно стандартного')
plt.legend()
plt.grid(True, alpha=0.3)
plt.savefig('quick_efficiency_ratio.png', dpi=300, bbox_inches='tight')
plt.show()

print("Графики для Quick Sort созданы!")