#include <iostream>

template<typename T, typename U>
class Vector {
public:
    T x;
    U y;


    Vector(T x, U y) : x(x), y(y){}
    
    Vector<T, U>minVector(Vector<T, U>& Left, Vector<T, U>& Right) {

        T nouveauX ;
        U nouveauY ;
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

    Vector<T, U>maxVector(Vector<T, U>& Left, Vector<T, U>& Right) {

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

    Vector<T, U>distanceVector(Vector<T, U>& Left, Vector<T, U>& Right) {
        Vector<T, U> resultat = Left - Right;
        return Vector<T, U>(resultat);
    };

};
template<typename T, typename U>
Vector<T, U>operator+(Vector<T, U>& Left, Vector<T, U>& Right) {

    T nouveauX = Left.x + Right.x;
    U nouveauY = Left.y + Right.y;

    return Vector<T, U>(nouveauX, nouveauY);
};

template<typename T, typename U>
Vector<T, U>operator-(Vector<T, U>& Left, Vector<T, U>& Right) {

    T nouveauX = Left.x - Right.x;
    U nouveauY = Left.y - Right.y;

    return Vector<T, U>(nouveauX, nouveauY);
};

template<typename T, typename U>
Vector<T, U>operator/(Vector<T, U>& Left, Vector<T, U>& Right) {

    T nouveauX = Left.x / Right.x;
    U nouveauY = Left.y / Right.y;

    return Vector<T, U>(nouveauX, nouveauY);
};


int main() {

    Vector<int, int> vector(1,2);

    Vector<int, int> Left(1, 2);
    Vector<int, int> Right(2, 2);
    Vector<int, int> resultat = vector.distanceVector(Left, Right);
    //Vector<int, int> resultat = Left - Right;

    std::cout << "Vecteur 1 : (" << Left.x << ", " << Left.y << ")" << std::endl;
    std::cout << "Vecteur 2 : (" << Right.x << ", " << Right.y << ")" << std::endl;
    std::cout << "Résultat de l'addition : (" << resultat.x << ", " << resultat.y << ")" << std::endl;

    return 0;
}

