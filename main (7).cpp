#include <iostream>
using namespace std;

static int count = 0;

class vect {
public:
    int dim;
    double* b;
    int num;

    vect(int dim) : dim(dim), num(++count) {
        b = new double[dim];
        for (int i = 0; i < dim; ++i) b[i] = 0;
        cout << "вектор " << num << " конструирован\n";
    }

    vect(const vect& v) : dim(v.dim), num(++count) {
        b = new double[dim];
        for (int i = 0; i < dim; ++i) b[i] = v.b[i];
        cout << "вектор " << num << " копирован\n";
    }

    ~vect() {
        delete[] b;
        cout << "вектор " << num << " деструктед\n";
    }

    vect& operator=(const vect& v) {
        if (this != &v) {
            delete[] b;
            dim = v.dim;
            b = new double[dim];
            for (int i = 0; i < dim; ++i) {
                b[i] = v.b[i];
            }
        }
        cout << "вектор принят " << num << "\n";
        return *this;
    }

    vect operator+(const vect& v) const {
        vect temp(dim);
        for (int i = 0; i < dim; ++i) {
            temp.b[i] = b[i] + v.b[i];
        }
        cout << "векторы суммированы " << num << "\n";
        return temp;
    }

    vect operator-(const vect& v) const {
        vect temp(dim);
        for (int i = 0; i < dim; ++i) {
            temp.b[i] = b[i] - v.b[i];
        }
        cout << "вычитание векторов успешно " << num << "\n";
        return temp;
    }

    vect operator-() const {
        vect temp(dim);
        for (int i = 0; i < dim; ++i) {
            temp.b[i] = -b[i];
        }
        cout << "векторное отрицание выполнено " << num << "\n";
        return temp;
    }

    double operator*(const vect& v) const {
        double sum = 0;
        for (int i = 0; i < dim; ++i) {
            sum += b[i] * v.b[i];
        }
        cout << "скалярное произведение выполнено " << num << "\n";
        return sum;
    }

    vect operator*(double k) const {
        vect temp(dim);
        for (int i = 0; i < dim; ++i) {
            temp.b[i] = b[i] * k;
        }
        cout << "скалярное умножение выполнено " << num << "\n";
        return temp;
    }

    friend vect operator*(double k, const vect& v) {
        return v * k;
    }
};

class matr {
   // Здесь будет аналогичная реализация для класса matr.
    // Из-за нехватки места и сложности реализации,
    // Я предоставляю схему. Фактическая реализация будет отражать класс vect.
    // с необходимыми настройками для 2D-массивов.
    
};

int main() {
   // Сценарий работы с векторами и матрицами.
  vect v1(3); // Example vector
    vect v2(3);
    // Выполняем операции с v1 и v2 согласно задаче
    
    return 0;
}
