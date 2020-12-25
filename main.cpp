// Полюбин Арсений
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>


// Шаблонная структура для Квадрата
template <class T>
struct Square {
    using type = T;
    using vertex = std::pair<T, T>;

    vertex center;
    T h;
    bool b;
    std::vector<vertex> path;

    Square() : center(), h(), b(false) {}

    Square(vertex center, T h) : center(center), h(h) {
        if (h > 0) {
            b = true;
            count_vertexes(*this);
        } else {
            b = false;
        }
    }

    ~Square() = default;
};

template <class T>
void count_vertexes(Square<T>& Sq) {
    const double epsilon = 0.00001;
    double vertex_x1 = Sq.center.first - Sq.h/2;
    double vertex_y1 = Sq.center.second + Sq.h/2;
    if (abs(vertex_x1 - static_cast<T>(vertex_x1)) > epsilon || abs(vertex_y1 - static_cast<T>(vertex_y1)) > epsilon ) {
        Sq.b = false;
    }
    Sq.path.push_back(std::make_pair(static_cast<T>(vertex_x1), static_cast<T>(vertex_y1)));

    double vertex_x2 = Sq.center.first + Sq.h/2;
    double vertex_y2 = Sq.center.second + Sq.h/2;
    if ( abs(vertex_x2 - static_cast<T>(vertex_x2)) > epsilon || abs(vertex_y2 - static_cast<T>(vertex_y2)) > epsilon ) {
        Sq.b = false;
    }
    Sq.path.push_back(std::make_pair(static_cast<T>(vertex_x2), static_cast<T>(vertex_y2)));

    double vertex_x3 = Sq.center.first - Sq.h/2;
    double vertex_y3 = Sq.center.second + Sq.h/2;
    if (abs(vertex_x3 - static_cast<T>(vertex_x3)) > epsilon || abs(vertex_y3 - static_cast<T>(vertex_y3)) > epsilon ) {
        Sq.b = false;
    }
    Sq.path.push_back(std::make_pair(static_cast<T>(vertex_x3), static_cast<T>(vertex_y3)));

    double vertex_x4 = Sq.center.first - Sq.h/2;
    double vertex_y4 = Sq.center.second + Sq.h/2;
    if ( abs(vertex_x4 - static_cast<T>(vertex_x4)) > epsilon || abs(vertex_y4 - static_cast<T>(vertex_y4)) > epsilon ) {
        Sq.b = false;
    }
    Sq.path.push_back(std::make_pair(static_cast<T>(vertex_x4), static_cast<T>(vertex_y4)));
}




// Шаблонная структура для Прямоугольника
template <class T>
struct Rectangle {
    using type = T;
    using vertex = std::pair<T, T>;

    vertex center;
    T h;
    T wide;
    bool b;
    std::vector<vertex> path;

    Rectangle() : center(), h(),wide(), b(false) {}

    Rectangle(vertex center, T h,T wide) : center(center), h(h), wide(wide) {
        if (h > 0 && wide > 0) {
            b = true;
            count_vertexes(*this);
        } else {
            b = false;
        }
    }

    ~Rectangle() = default;
};

template <class T>
void count_vertexes(Rectangle<T>& Rec) {
    const double epsilon = 0.00001;

    double vertex_x1 = Rec.center.first - Rec.wide/2;
    double vertex_y1 = Rec.center.second + Rec.h/2;
    if ( abs(vertex_x1 - static_cast<T>(vertex_x1)) > epsilon || abs(vertex_y1 - static_cast<T>(vertex_y1)) > epsilon ) {
        Rec.b = false;
    }
    Rec.path.push_back(std::make_pair(static_cast<T>(vertex_x1), static_cast<T>(vertex_y1)));

    double vertex_x2 = Rec.center.first + Rec.wide/2;
    double vertex_y2 = Rec.center.second + Rec.h/2;
    if ( abs(vertex_x2 - static_cast<T>(vertex_x2)) > epsilon || abs(vertex_y2 - static_cast<T>(vertex_y2)) > epsilon ) {
        Rec.b = false;
    }
    Rec.path.push_back(std::make_pair(static_cast<T>(vertex_x2), static_cast<T>(vertex_y2)));

    double vertex_x3 = Rec.center.first + Rec.wide/2;
    double vertex_y3 = Rec.center.second - Rec.h/2;
    if ( abs(vertex_x3 - static_cast<T>(vertex_x3)) > epsilon || abs(vertex_y3 - static_cast<T>(vertex_y3)) > epsilon ) {
        Rec.b = false;
    }
    Rec.path.push_back(std::make_pair(static_cast<T>(vertex_x3), static_cast<T>(vertex_y3)));

    double vertex_x4 = Rec.center.first - Rec.wide/2;
    double vertex_y4 = Rec.center.second - Rec.h/2;
    if (abs(vertex_x4 - static_cast<T>(vertex_x4)) > epsilon || abs(vertex_y4 - static_cast<T>(vertex_y4)) > epsilon ) {
        Rec.b = false;
    }
    Rec.path.push_back(std::make_pair(static_cast<T>(vertex_x4), static_cast<T>(vertex_y4)));


}

// Шаблонная структура для Трапеции
template <class T>
struct Trapeze {
    using type = T;
    using vertex = std::pair<T, T>;

    vertex center;
    T up;
    T down;
    T h;
    bool b;
    std::vector<vertex> path;

    Trapeze() : center(), up(),down(), b(false), h() {}

    Trapeze(vertex center,T h,  T up,T down) : center(center), h(h), up(up), down(down) {
        if (up > 0 && down > 0) {
            b = true;
            count_vertexes(*this);
        } else {
            b = false;
        }
    }

    ~Trapeze() = default;
};

template <class T>
void count_vertexes(Trapeze<T>& trap) {

    const double epsilon = 0.00001;

    double vertex_x1 = trap.center.first - trap.up / 2;
    double vertex_y1 = trap.center.second + trap.down / 2;
    if (abs(vertex_x1 - static_cast<T>(vertex_x1)) > epsilon || abs(vertex_y1 - static_cast<T>(vertex_y1)) > epsilon) {
        trap.b = false;
    }
    trap.path.push_back(std::make_pair(static_cast<T>(vertex_x1), static_cast<T>(vertex_y1)));

    double vertex_x2 = trap.center.first - trap.up / 2;
    double vertex_y2 = trap.center.second + trap.down / 2;
    if (abs(vertex_x2 - static_cast<T>(vertex_x2)) > epsilon || abs(vertex_y2 - static_cast<T>(vertex_y2)) > epsilon) {
        trap.b = false;
    }
    trap.path.push_back(std::make_pair(static_cast<T>(vertex_x2), static_cast<T>(vertex_y2)));

    double vertex_x3 = trap.center.first + trap.up / 2;
    double vertex_y3 = trap.center.second - trap.down / 2;
    if (abs(vertex_x3 - static_cast<T>(vertex_x3)) > epsilon || abs(vertex_y3 - static_cast<T>(vertex_y3)) > epsilon) {
        trap.b = false;
    }
    trap.path.push_back(std::make_pair(static_cast<T>(vertex_x3), static_cast<T>(vertex_y3)));

    double vertex_x4 = trap.center.first - trap.up / 2;
    double vertex_y4 = trap.center.second - trap.down / 2;
    if (abs(vertex_x4 - static_cast<T>(vertex_x4)) > epsilon || abs(vertex_y4 - static_cast<T>(vertex_y4)) > epsilon) {
        trap.b = false;
    }
    trap.path.push_back(std::make_pair(static_cast<T>(vertex_x4), static_cast<T>(vertex_y4)));
}

// Печать Square
template <class T>
typename std::enable_if<std::is_same<T, Square<typename T::type>>::value, void>::type print(T& figure) {
    if (figure.b) {
        for (auto vertex : figure.path)
            std::cout << "(" << vertex.first << ", " << vertex.second << ") ";
        std::cout << std::endl;
    } else {
        std::cout << "Not Square" << std::endl;
    }
}
// Площадь Square
template<class T>
typename std::enable_if<std::is_same<T, Square<typename T::type>>::value, typename T::type>::type square(T& figure) {
    if (figure.b) {
        return figure.h*figure.h;
    } else {
        return 0;
    }
}

// Печать Rectangle
template<class T>
typename std::enable_if<std::is_same<T, Rectangle<typename T::type>>::value, void>::type print(T& figure) {
    if (figure.b) {
        for (auto vertex : figure.path)
            std::cout << "(" << vertex.first << ", " << vertex.second << ") ";
        std::cout << std::endl;
    } else {
        std::cout << "Not Rectangle" << std::endl;
    }
}
// Площадь Rectangle
template<class T>
typename std::enable_if<std::is_same<T, Rectangle<typename T::type>>::value, typename T::type>::type square(T& figure) {
    if (figure.b) {
        return figure.h * figure.wide;
    } else {
        return 0;
    }
}

// Печать Trapeze
template<class T>
typename std::enable_if<std::is_same<T, Trapeze<typename T::type>>::value, void>::type print(T& figure) {
    if (figure.b) {
        for (auto vertex : figure.path)
            std::cout << "(" << vertex.first << ", " << vertex.second << ") ";
        std::cout << std::endl;
    } else {
        std::cout << "Not Trapeze" << std::endl;
    }
}
// Площадь Trapeze
template<class T>
typename std::enable_if<std::is_same<T, Trapeze<typename T::type>>::value, typename T::type>::type square(T& figure) {
    if (figure.b) {
        return (figure.up +figure.down)/2 * figure.h;
    } else {
        return 0;
    }
}

// Печать Tuple
template <class T, size_t index>
typename std::enable_if<index >= std::tuple_size<T>::value, void>::type print_tuple(T&){
    std::cout << std::endl;
}

template <class T, size_t index>
typename std::enable_if<index < std::tuple_size<T>::value, void>::type print_tuple(T& tuple){
    auto figure = std::get<index>(tuple);
    print(figure);
    print_tuple<T,index+1>(tuple);
}

// Площадь Tuple
template <class T, size_t index>
double square_tuple(T& tuple){
    auto item = std::get<index>(tuple);
    double value = square(item);

    if constexpr ((index+1) < std::tuple_size<T>::value) {
        return value + square_tuple<T,index+1>(tuple);
    }
    return value;
}

int main() {
    Square<float> sq1({5,5},3);
    Square<char> sq2({10,10}, 0);
    Rectangle<double> rec1({3,3}, 6,5);
    Rectangle<size_t > rec2({2,2},4,0);
    Trapeze<double > trap1({0,0}, 1,2,1);
    Trapeze<char> trap2({5,5}, 7,5,0);

    std::tuple < decltype(sq1), decltype(sq2), decltype(rec1), decltype(rec2), decltype(trap1), decltype(trap2) > tuple {
            sq1, sq2, rec1, rec2, trap1, trap2
    };
    print_tuple<decltype(tuple), 0>(tuple);
    std::cout << "Total square = " << square_tuple<decltype(tuple), 0>(tuple) << std::endl;
    return 0;
}