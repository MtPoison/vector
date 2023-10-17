#include <iostream>
#include <cmath>
#include <algorithm>

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

    Vector<T, U> scaleVector(Vector<T, U>& a, double choix) {

        T nouveauX = a.x * choix;
        U nouveauY = a.y * choix;

        return Vector<T, U>(nouveauX, nouveauY);
    }

    Vector<T, U> perpendiculaireVector(Vector<T, U>& a, char choix) {
        T newX;
        U newY;

        if (choix == 'x') {
            T newX = -a.x;
            U newY = a.y;
        }
        else {
            T newX = a.x;
            U newY = -a.y;
        }

        return Vector<T, U>(newX, newY);
    }
    

    Vector<T, U> reflectVector(Vector<T, U>& a, char choix) {
        T newX;
        U newY;

        if (choix == 'x') {
            T newX = a.x;
            U newY = -a.y;
        }
        else {
            T newX = -a.x;
            U newY = a.y;
        }

        return Vector<T, U>(newX, newY);
    }

    Vector<T, U> dotVector(Vector<T, U>& Left, Vector<T, U>& Right) {

        Vector<T, U> result = Left.x * Right.x + Left.y * Right.x;

        return Vector<T, U>(result);
    }

    Vector<T, U> lepVector(Vector<T, U>& Left, Vector<T, U>& Right, double t) {

        t = std::max(0.0, std::min(1.0, t));

        Vector<T, U> result = Left + t * (Right - Left);
        
        return Vector<T, U>(result);

    }

    Vector<T, U> lepCamptedVector(Vector<T, U>& Left, Vector<T, U>& Right, double t) {

        t = std::clamp(t, 0.0, 1.0);;

        Vector<T, U> result = Left + t * (Right - Left);

        return Vector<T, U>(result);

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
    Vector<int, int> resultat = vector.scaleVector(Left, 4);

    std::cout << "Vecteur 1 : (" << Left.x << ", " << Left.y << ")" << std::endl;
    std::cout << "Vecteur 2 : (" << Right.x << ", " << Right.y << ")" << std::endl;
    std::cout << "Magnitude du vecteur de distance : " << resultat.x << std::endl;

    return 0;
}
