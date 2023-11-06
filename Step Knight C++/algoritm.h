#include <vector>
#include <iostream>
using namespace std;


struct MyData {
    int min_step;
    vector<vector<int>> mass;
};


struct Position {
    int x;
    int y;
};


class Algoritm
{
private:
    /*
    ���������, ����� �� ������� � ������������ �����. �������:
        1) ���������� �� ������� �� ������� ���������� �������
        2) � ����� ���� �� ����� ������� ��� ���� ����� ��������
    */
    bool check(int x, int y, vector <vector<int>> mass) {
        if ((0 <= x) and (x < mass[0].size()) and ((0 <= y) and (y < mass.size())) and ((mass[y][x] == 0) or (mass[y][x] == -1))) return true;
        else return false;
    }

    bool check_on_size(vector <vector<int>> mass, int x_next, int y_next) {
        if ((0 <= x_next) and (x_next < mass[0].size()) and ((0 <= y_next) and (y_next < mass.size()))) return true;
        else return false;
    }


public:
    // ������� � ������� ��������� ������
	void print_mass(vector<vector<int>> mass) {
        for (auto row : mass) {
            for (const auto& elem : row) cout << elem << "\t";
            cout << endl;
        }
	}

    MyData BFS(vector <vector<int>> mass, int max_step = 10) {
        MyData data;
        int step = 1, pat_x, pat_y, tmp_x, tmp_y;
        // ������� �������� ���� �� �����
        vector <int> pattern_x = { 1, 2, 2, 1, -1, -2, -2, -1 };
        vector <int> pattern_y = { -2, -1, 1, 2, 2, 1, -1, -2 };
        // ���� �� ���������� ���������� ����� ���� ����
        while (step < max_step) {
            // ���������� �� ����� �������, ����� ����� ����� � ������ �����
            for (int y = 0; y < mass.size(); y++) {
                for (int x = 0; x < mass[0].size(); x++) {
                    // ���� �� �������, ��...
                    if (step == mass[y][x]) {
                        // ������ �� ��� ������ ����� �������, ��� �� ����� ���� �������
                        for (int i = 0; i < pattern_x.size(); i++) {
                            tmp_x = x + pattern_x[i];
                            tmp_y = y + pattern_y[i];
                            if (check(tmp_x, tmp_y, mass)) {
                                // ���� �� �� ������� �� �����, �� ���������� ����������� ���������� ����� � ������
                                if (mass[tmp_y][tmp_x] == -1) {
                                    data.min_step = step + 1;
                                    data.mass = mass;
                                    return data;
                                }
                                // ���� ���, �� ������ ���������� ������
                                mass[tmp_y][tmp_x] = step + 1;
                            }
                        }
                    }
                }
            }
            step++;
        }
        // ���� ���� �� ��� ������ �� n ���������� �����, �� ���������� -1
        data.min_step = -1;
        data.mass = mass;
        return data;
    }

    vector<Position> path_start(vector <vector<int>> mass, int min_step, int fin_x, int fin_y) {
        int x = fin_x, y = fin_y, tmp_x, tmp_y;
        vector<Position> path;
        path.push_back({ x, y });
        vector <int> pattern_x = { 1, 2, 2, 1, -1, -2, -2, -1 };
        vector <int> pattern_y = { -2, -1, 1, 2, 2, 1, -1, -2 };
        for (int i = min_step - 1; i > 0; i--) {
            for (int j = 0; j < pattern_x.size(); j++) {
                tmp_x = x + pattern_x[j];
                tmp_y = y + pattern_y[j];
                // ���� ����� ���� � ��������� ��� ������������� ���������� ����, �� ��������� � ���� �� ������
                if (check_on_size(mass, tmp_x, tmp_y) and (mass[tmp_y][tmp_x] == i)) {
                    path.push_back({ tmp_x, tmp_y });
                    x = tmp_x;
                    y = tmp_y;
                }
            }
        }
        return path;
    }
};

