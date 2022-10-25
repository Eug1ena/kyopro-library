const double EPS = 1e-10;

int sgn(double a){
    return (a < -EPS ? -1: (a > EPS ? 1 : 0));
}

using Point = complex<double>;

istream& operator >>(istream &in, Point &p){
    double x, y;
    cin >> x >> y;
    p = Point(x, y);
    return in;
}

bool operator <(Point a, Point b){
    if(sgn(a.real() - b.real()) != 0) return sgn(a.real() - b.real()) < 0;
    return sgn(a.imag() - b.imag()) < 0;
}

double dot(Point a, Point b){
    return (conj(a) * b).real();
}

double cross(Point a, Point b){
    return (conj(a) * b).imag();
}

int ccw(Point a, Point b, Point c){
    int flag = sgn(cross(b - a, c - a));
    if(flag == 1) return 1;
    if(flag == -1) return -1;
    if(sgn(dot(b - a, c - b)) > 0) return 2;
    if(sgn(dot(a - c, b - a)) > 0) return -2;
    return 0;
}

int angletype(Point a, Point b, Point c){
    int flag = sgn(dot(a - b, c - b));
    if(flag == 1) return 0;
    if(flag == 0) return 1;
    return 2;
}

double distance(Point a, Point b){
    return abs(b - a);
}

struct Line{
    Point s, t;
    
    Line() = default;
    Line(Point s, Point t): s(s), t(t) {}
    
    Point vec(){ return t - s; }
};
using Segment = Line;

istream& operator >>(istream &in, Line &l){
    Point p, q;
    cin >> p >> q;
    l = Line(p, q);
    return in;
}

double length(Line l){
    return abs(l.vec());
}

const Point error_val = Point(31415, 92653);

Point line_intersection(Line l1, Line l2){
    if(sgn(cross(l1.vec(), l2.vec())) == 0) return error_val;
    
    return l1.s + l1.vec() * (abs(cross(l2.t - l1.s, l2.vec())) / abs(cross(l1.vec(), l2.vec())));
}

pair<bool, Point> segment_intersection(Segment s1, Segment s2){
    if(ccw(s1.s, s1.t, s2.s) * ccw(s1.s, s1.t, s2.t) <= 0 &&
       ccw(s2.s, s2.t, s1.s) * ccw(s2.s, s2.t, s1.t) <= 0){
        if(sgn(cross(s1.vec(), s2.vec())) == 0){
            return {true, error_val};
        }else{
            return {true, line_intersection(s1, s2)};
        }
    }else{
        return {false, error_val};
    }
}

double distance_between_point_and_line(Point p, Line l){
    return abs(cross(p - l.s, l.vec())) / length(l);
}

double distance_between_point_and_segment(Point p, Segment s){
    if(angletype(s.t, s.s, p) == 2) return distance(p, s.s);
    if(angletype(s.s, s.t, p) == 2) return distance(p, s.t);
    return distance_between_point_and_line(p, s);
}

double distance_between_segments(Segment s1, Segment s2){
    if(segment_intersection(s1, s2).first == true) return 0;
    return min({distance_between_point_and_segment(s1.s, s2),
                distance_between_point_and_segment(s1.t, s2),
                distance_between_point_and_segment(s2.s, s1),
                distance_between_point_and_segment(s2.t, s1)});
}

Point projection(Point p, Line l){
    return l.s + (l.vec() / length(l)) * (dot(l.vec(), p - l.s) / length(l));
}

Point reflection(Point p, Line l){
    Point proj = projection(p, l);
    return proj + (proj - p);
}
