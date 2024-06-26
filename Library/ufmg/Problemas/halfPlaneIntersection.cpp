// Half-plane intersection
// Computa a regiao convexa formada pela intersecao de n half-planes
// Cada half-plane eh identificado por uma reta e a regiao ccw a ela
//
// O(n log n)

vector<pt> hp_intersection(vector<line> &v) {
    deque<pt> dq = {{INF, INF}, {-INF, INF}, {-INF, -INF}, {INF, -INF}};

#warning considerar trocar por compare_angle
    sort(v.begin(), v.end(), [&](line r, line s) { return angle(r.q - r.p) < angle(s.q - s.p); });

    for (int i = 0; i < v.size() and dq.size() > 1; i++) {
        pt p1 = dq.front(), p2 = dq.back();
        while (dq.size() and !ccw(v[i].p, v[i].q, dq.back())) p1 = dq.back(), dq.pop_back();
        while (dq.size() and !ccw(v[i].p, v[i].q, dq.front())) p2 = dq.front(), dq.pop_front();

        if (!dq.size()) break;
        if (p1 == dq.front() and p2 == dq.back()) continue;
        dq.push_back(inter(v[i], line(dq.back(), p1)));
        dq.push_front(inter(v[i], line(dq.front(), p2)));

        if (dq.size() > 1 and dq.back() == dq.front()) dq.pop_back();
    }
    return vector<pt>(dq.begin(), dq.end());
}
