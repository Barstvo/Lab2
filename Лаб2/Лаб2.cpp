#include <iostream>
#include <cmath>
using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double x1, y1, x2, y2, x3, y3, a, b, c, p, s, ha, hb, hc;

    cout << "Введите координаты первой точки (x y): "; cin >> x1 >> y1;
    cout << "Введите координаты второй точки (x y): "; cin >> x2 >> y2;
    cout << "Введите координаты третьей точки (x y): "; cin >> x3 >> y3; 
    /
    a = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
    b = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    c = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));

    const double EPS = 1e-9;
    if (a + b <= c + EPS || a + c <= b + EPS || b + c <= a + EPS) {
        cout << "\nТочки не составляют треугольник\n ";
        return 1;
    }

    if (abs(a - b) < EPS && abs(b - c) < EPS)
        cout << "Вид треугольника: Равносторонний\n";
    else if (abs(a - b) < EPS || abs(b - c) < EPS || abs(a - c) < EPS)
        cout << "Вид треугольника: Равнобедренный\n";
    else
        cout << "Вид треугольника: Разносторонний\n";

    p = (a + b + c) / 2.0;
    s = sqrt(p * (p - a) * (p - b) * (p - c));
    ha = (2.0 * s) / a;
    hb = (2.0 * s) / b;
    hc = (2.0 * s) / c;

    if (ha < hb) { double d = ha; ha = hb; hb = d; }
    if (ha < hc) { double d = ha; ha = hc; hc = d; }
    if (hb < hc) { double d = hb; hb = hc; hc = d; }

    cout << "Длины высот в порядке убывания:" << ha << " " << hb << " " << hc << "\n";

    return 0;
}