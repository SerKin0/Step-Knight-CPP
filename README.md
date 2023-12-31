# Step Knight С++
Данная программа реализует поиск наикратчайшего пути для коня на шахматной доске от стартовой позиции до финишной позиции за определенное количество ходов N. Программа написана на языке программирования C++.

## Содержание
- [Установка](#установка)
- [Использование](#Использование)
- [To do](#to-do)
- [Результат](#результат)

## Установка
Для установки программы вам потребуется:

1. Убедитесь, что на вашем компьютере установлен компилятор C++ (например, GCC или Clang) и библиотека SFML (если вы хотите использовать графическое отображение).

2. Склонируйте репозиторий на свой компьютер:
```
git clone https://github.com/your-username/your-repository.git
```

3. Соберите программу, используя выбранный компилятор. Например, с использованием GCC:
```
g++ main.cpp -o knight_path
```

## Использование
1. Запустите программу, указав стартовые и конечные координаты на шахматной доске и необходимое количество ходов N:

```C++
// Размеры доски
int size_x = 20, size_y = 20;
// Координаты начала пути коня
int kn_x = 2, kn_y = 0;
// Координаты конца пути коня
int fn_x = 6, fn_y = 18;
```


2. Программа найдет наикратчайший путь для коня на шахматной доске согласно заданным параметрам и выведет его в консоль.
## To do
- [x] Сделать алгоритм BFS
- [ ] Сделать визуализацию доски
- [ ] Сделать это для других фигур

## Результат
Вводим размеры доски, координаты начала и конца пути в файле main.cpp.
```С++
# Размеры доски
size_x, size_y = 20, 20
# Координаты начала пути коня
kn_x, kn_y = 2, 0
# Координаты конца пути коня
fn_x, fn_y = 6, 18
```
Если конь должен двигаться немного по другому, то можно изменить патерны его движения в файле algoritm.h.
```C++
// Патерны движения коня на доске
vector <int> pattern_x = { 1, 2, 2, 1, -1, -2, -2, -1 };
vector <int> pattern_y = { -2, -1, 1, 2, 2, 1, -1, -2 };
```
Эти переменные есть каки в функции BFS, так в path_start. Учитывайте это.

```
Count step: 11
Array:
3 4 1 4 3 4 3 4 5 6 5 6 7 8 7 8 9 10 9 10
2 3 4 3 2 3 4 5 4 5 6 7 6 7 8 9 8 9 10 11
5 2 3 2 5 4 3 4 5 6 5 6 7 8 7 8 9 10 9 10
4 3 4 3 4 3 4 5 4 5 6 7 6 7 8 9 8 9 10 11
3 4 3 4 3 4 5 4 5 6 5 6 7 8 7 8 9 10 9 10
4 5 4 5 4 5 4 5 6 5 6 7 6 7 8 9 8 9 10 11
5 4 5 4 5 4 5 6 5 6 7 6 7 8 7 8 9 10 9 10
6 5 6 5 6 5 6 5 6 7 6 7 8 7 8 9 8 9 10 11
5 6 5 6 5 6 5 6 7 6 7 8 7 8 9 8 9 10 9 10
6 7 6 7 6 7 6 7 6 7 8 7 8 9 8 9 10 9 10 11
7 6 7 6 7 6 7 6 7 8 7 8 9 8 9 10 9 10 11 10
8 7 8 7 8 7 8 7 8 7 8 9 8 9 10 9 10 11 10 11
7 8 7 8 7 8 7 8 7 8 9 8 9 10 9 10 11 10 11 0
8 9 8 9 8 9 8 9 8 9 8 9 10 9 10 11 10 11 0 11
9 8 9 8 9 8 9 8 9 8 9 10 9 10 11 10 11 0 11 0
10 9 10 9 10 9 10 9 10 9 10 9 10 11 10 11 0 11 0 0
9 10 9 10 9 10 9 10 9 10 9 10 11 10 11 0 11 0 0 0
10 11 10 11 10 11 10 11 10 11 10 11 10 11 0 11 0 0 0 0
11 10 11 10 11 10 -1 10 0 10 0 10 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

x: 6, y: 18
x: 7, y: 16
x: 8, y: 14
x: 9, y: 12
x: 10, y: 10
x: 8, y: 9
x: 6, y: 8
x: 5, y: 6
x: 4, y: 4
x: 3, y: 2
x: 2, y: 0
```
