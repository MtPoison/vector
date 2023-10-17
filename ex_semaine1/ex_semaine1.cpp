#include <iostream>
#include <cmath>

template<typename T, typename U>
class Vector {
public:
    T x;
    U y;

    Vector(T x, U y) : x(x), y(y) {}

    Vector(double magnitude) {
        x = static_cast<T>(magnitude);
        y = static_cast<U>(magnitude);
    }

    double magnetude() {
        return sqrt(x * x + y * y);
    }

    Vector<T, U> minVector(Vector<T, U>& Left, Vector<T, U>& Right) {
        T nouveauX;
        U nouveauY;
        if (Left.x < Right.x) {
            nouveauX = Left.x;
        }
        else {
            nouveauX = Right.x;
        }

        if (Left.y < Right.y) {
            nouveauY = Left.y;
        }
        else {
            nouveauY = Right.y;
        }

        return Vector<T, U>(nouveauX, nouveauY);
    }

    Vector<T, U> maxVector(Vector<T, U>& Left, Vector<T, U>& Right) {
        T nouveauX;
        U nouveauY;
        if (Left.x > Right.x) {
            nouveauX = Left.x;
        }
        else {
            nouveauX = Right.x;
        }

        if (Left.y > Right.y) {
            nouveauY = Left.y;
        }
        else {
            nouveauY = Right.y;
        }

        return Vector<T, U>(nouveauX, nouveauY);
    }

    double distanceVector(Vector<T, U>& Left, Vector<T, U>& Right) {
        Vector<T, U> result = Left - Right;
        return result.magnetude();
    }

    template<typename T, typename U>
    Vector<T, U> scaleVector(Vector<T, U>& a) {
        double choix = 0;
        std::cout << "Combien veux-tu multiplier ton vecteur ?" << std::endl;
        std::cin >> choix;

        T nouveauX = a.x * choix;
        U nouveauY = a.y * choix;

        return Vector<T, U>(nouveauX, nouveauY);
    }

};

template<typename T, typename U>
Vector<T, U> operator+(Vector<T, U>& Left, Vector<T, U>& Right) {
    T nouveauX = Left.x + Right.x;
    U nouveauY = Left.y + Right.y;
    return Vector<T, U>(nouveauX, nouveauY);
}

template<typename T, typename U>
Vector<T, U> operator-(Vector<T, U>& Left, Vector<T, U>& Right) {
    T nouveauX = Left.x - Right.x;
    U nouveauY = Left.y - Right.y;
    return Vector<T, U>(nouveauX, nouveauY);
}

template<typename T, typename U>
Vector<T, U> operator/(Vector<T, U>& Left, Vector<T, U>& Right) {
    T nouveauX = Left.x / Right.x;
    U nouveauY = Left.y / Right.y;
    return Vector<T, U>(nouveauX, nouveauY);
}

int main() {
    Vector<int, int> vector(1, 2);

    Vector<int, int> Left(1, 2);
    Vector<int, int> Right(2, 2);
    Vector<int, int> resultat = vector.scaleVector(Left);

    std::cout << "Vecteur 1 : (" << Left.x << ", " << Left.y << ")" << std::endl;
    std::cout << "Vecteur 2 : (" << Right.x << ", " << Right.y << ")" << std::endl;
    std::cout << "Magnitude du vecteur de distance : " << resultat.x << std::endl;

    return 0;
}
