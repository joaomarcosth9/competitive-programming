template <typename T, typename U> pair<T, U> operator+(const pair<T, U>& l, const pair<T, U>& r) {
    return {l.first + r.first, l.second + r.second};
}
template <typename T, typename U> pair<T, U> operator-(const pair<T, U>& l, const pair<T, U>& r) {
    return {l.first - r.first, l.second - r.second};
}
template <typename T, typename U> pair<T, U> operator*(const pair<T, U>& l, const pair<T, U>& r) {
    return {l.first * r.first, l.second * r.second};
}
template <typename T, typename U> pair<T, U> operator/(const pair<T, U>& l, const pair<T, U>& r) {
    return {l.first / r.first, l.second / r.second};
}
template <typename T, typename U> pair<T, U>& operator+=(pair<T, U>& l, const pair<T, U>& r) {
    return l = l + r;
}
template <typename T, typename U> pair<T, U>& operator-=(pair<T, U>& l, const pair<T, U>& r) {
    return l = l - r;
}
template <typename T, typename U> pair<T, U>& operator*=(pair<T, U>& l, const pair<T, U>& r) {
    return l = l * r;
}
template <typename T, typename U> pair<T, U>& operator/=(pair<T, U>& l, const pair<T, U>& r) {
    return l = l / r;
}
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) {
    return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p) {
    return is >> p.first >> p.second;
}
template <typename T, typename U> pair<T, U> operator+(const pair<T, U>& l, const T& r) {
    return {l.first + r, l.second + r};
}
template <typename T, typename U> pair<T, U> operator-(const pair<T, U>& l, const T& r) {
    return {l.first - r, l.second - r};
}
template <typename T, typename U> pair<T, U> operator*(const pair<T, U>& l, const T& r) {
    return {l.first * r, l.second * r};
}
template <typename T, typename U> pair<T, U> operator/(const pair<T, U>& l, const T& r) {
    return {l.first / r, l.second / r};
}
template <typename T, typename U> pair<T, U>& operator+=(pair<T, U>& l, const T& r) {
    return l = l + r;
}
template <typename T, typename U> pair<T, U>& operator-=(pair<T, U>& l, const T& r) {
    return l = l - r;
}
template <typename T, typename U> pair<T, U>& operator*=(pair<T, U>& l, const T& r) {
    return l = l * r;
}
template <typename T, typename U> pair<T, U>& operator/=(pair<T, U>& l, const T& r) {
    return l = l / r;
}
