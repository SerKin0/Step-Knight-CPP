#include <iostream>
#include <vector>
#include "algoritm.h"
using namespace std;

int main() {
	// Объявление объекта класса
	Algoritm alg;
	MyData data;

	// Размеры доски
	int size_x = 20, size_y = 20;
	// Координаты начала пути коня
	int kn_x = 2, kn_y = 0;
	// Координаты конца пути коня
	int fn_x = 6, fn_y = 18;

	// Создание двумерного массива/доски
	vector<vector<int> > mass(size_y, vector<int>(size_x, 0));

	// Ставим начало и конец пути коня на доске
	mass[kn_y][kn_x] = 1;
	mass[fn_y][fn_x] = -1;

	int min_int = 0;
	MyData result = alg.BFS(mass, 100);
	cout << "Count step: " << result.min_step << endl << "Array: " << endl;
	alg.print_mass(result.mass);
	cout << endl;
	vector <Position> path = alg.path_start(result.mass, result.min_step, fn_x, fn_y);
	for (const auto& pos : path) {
		std::cout << "x: " << pos.x << ", y: " << pos.y << std::endl;
	}
}