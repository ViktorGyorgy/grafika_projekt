#include <cmath>
#include "TestFunctions.h"
#include "../Core/Constants.h"

using namespace cagd;
using namespace std;


//
GLdouble spiral_on_cone::u_min = -2;
GLdouble spiral_on_cone::u_max = +2;
DCoordinate3 spiral_on_cone::d0(GLdouble u)
{
    return DCoordinate3(u,
                        0.5 * u * sin(u),
                        0.5 * u * cos(u));
}

DCoordinate3 spiral_on_cone::d1(GLdouble u)
{
    GLdouble c = cos(u), s = sin(u);
    return DCoordinate3(1.0,
                        (s + u * c) / 2,
                        - (u * s - c) / 2);
}

DCoordinate3 spiral_on_cone::d2(GLdouble u)
{
    GLdouble c = cos(u), s = sin(u);
    return DCoordinate3(0.0,
                        (2.0 * c - u * s) / 2,
                        - (2 * s + u * c) / 2);
}

GLdouble torus_knot::u_min = 0.0;
GLdouble torus_knot::u_max = TWO_PI;

DCoordinate3 torus_knot::d0(GLdouble u)
{
    GLdouble c = cos(u), s = sin(u);
    return DCoordinate3( (1.0 + 0.5 * c) * c,
                         (1.0 + 0.5 * c) * s,
                         0.5 * s
                       );
}

DCoordinate3 torus_knot::d1(GLdouble u)
{
    GLdouble c = cos(u), s = sin(u);
    return DCoordinate3( (- c - 1) * s,
                         (c / 2 + 1) * c - s * s / 2,
                         0.5 * c
                       );
}

DCoordinate3 torus_knot::d2(GLdouble u)
{
    GLdouble c = cos(u), s = sin(u);
    return DCoordinate3( s * s + (- c - 1) * c,
                         (-2 * c - 1) * s,
                         - 0.5 * s
                       );
}

GLdouble spiral_on_sphere::u_min = -PI;
GLdouble spiral_on_sphere::u_max = PI;

DCoordinate3 spiral_on_sphere::d0(GLdouble u)
{
    GLdouble c = cos(u), s = sin(u);
    return DCoordinate3( 2.0 * c * s,
                         2.0 * s * s,
                         2.0 * c);
}

DCoordinate3 spiral_on_sphere::d1(GLdouble u)
{
    GLdouble c = cos(u), s = sin(u), c2 = cos(2 * u), s2 = sin(2 * u);
    return DCoordinate3( 2 * c2,
                         2 * s2,
                         -2 * s);
}

DCoordinate3 spiral_on_sphere::d2(GLdouble u)
{
    GLdouble c = cos(u), s = sin(u), c2 = cos(2 * u), s2 = sin(2 * u);
    return DCoordinate3( -4.0 * s2,
                         4 * c2,
                         -2 * c);
}



GLdouble viviani::u_min = -PI;
GLdouble viviani::u_max = PI;

DCoordinate3 viviani::d0(GLdouble u)
{
    GLdouble s = sin(u), c = cos(u);
    return DCoordinate3( s * c,
                         s * s,
                         c);
}

DCoordinate3 viviani::d1(GLdouble u)
{
    GLdouble s = sin(u), c = cos(u);
    return DCoordinate3( c*c - s*s,
                         2.0 * s * c,
                         -s);
}

DCoordinate3 viviani::d2(GLdouble u)
{
    GLdouble s = sin(u), c = cos(u);
    return DCoordinate3( -4.0 * c * s,
                         2.0 * (c*c - s*s),
                         -c);
}

GLdouble butterfly_curves::u_min = 0;
GLdouble  butterfly_curves::u_max = 3 *TWO_PI;

DCoordinate3  butterfly_curves::d0(GLdouble u){
    return DCoordinate3(sin(u) * ( exp(cos(u)) - 2 * cos(4*u) - pow(sin(u/12.0), 5) ),
                        cos(u) * (exp(cos(u)) - 2 * cos(4*u) - pow(sin(u/12.0), 5) ),
                        0);
}

DCoordinate3  butterfly_curves::d1(GLdouble u){
    return DCoordinate3(sin(u) * (8 * sin(4*u) - exp(cos(u)) * sin(u) - 5 * cos(u/12) * pow(sin(u/12), 4) / 12) + cos(u) * ( exp(cos(u)) - 2 * cos(4*u) - pow(sin(u/12.0), 5) ),
                        cos(u) * (8*sin(4*u) - exp(cos(u)) * sin(u) - 5 * cos(u/12) * pow(sin(u/12), 4) / 12) - sin(u) * (exp(cos(u)) - 2 * cos(4*u) - pow(sin(u/12.0), 5)) ,
                        0);
}

DCoordinate3  butterfly_curves::d2 (GLdouble u){
    GLdouble s = sin(u), c = cos(u), c4 = cos(4 * u), s4 = sin(4 * u), c_12 = cos(u/12), s_12 = sin(u/12);
    return DCoordinate3(2 * c * (8 * s4 - exp(c) * s - (5 * c_12 * pow(s_12, 4)) / 12) +   s * (32 * c4 +   exp(c) * s * s   - exp(c) * c +    5 * pow(s_12, 5) / 144 -   5 * pow(c_12, 2) * pow(s_12, 3) / 36)  - s * (-2 * c4 + exp(c) - pow(s_12, 5)),
                        -2 * s * (8 * s4 - exp(c) * s - (5 * c_12 * pow(s_12, 4)) / 12) + c * (32 * c4 +   exp(c) * s * s   - exp(c) * c +    5 * pow(s_12, 5) / 144 -   5 * pow(c_12, 2) * pow(s_12, 3) / 36) - c * (-2 * c4 + exp(c) - pow(s_12, 5)),
                        0);
}


GLdouble rose_curves::u_min = 0;
GLdouble  rose_curves::u_max = TWO_PI;

DCoordinate3  rose_curves::d0(GLdouble u){
    return DCoordinate3(5 * cos(12 * u) * cos(u), 5 * cos(12 * u) * sin(u), 0);
}

DCoordinate3  rose_curves::d1(GLdouble u){
    GLdouble s = sin(u), c = cos(u), c12 = cos(12 * u), s12 = sin(12 * u);
    return DCoordinate3(-5 * (12 * c * s12 + s * c12),
                        5 * c * c12 - 60 * s * s12,
                        0);
}

DCoordinate3  rose_curves::d2 (GLdouble u){
    GLdouble s = sin(u), c = cos(u), c12 = cos(12 * u), s12 = sin(12 * u);
    return DCoordinate3(120 * s * s12 - 725 * c * c12,
                        -120 * c * s12 - 725 * s * c12,
                        0);
}

GLdouble helix::u_min = 0;
GLdouble  helix::u_max = 6 * TWO_PI;

DCoordinate3  helix::d0(GLdouble u){
    return DCoordinate3(cos(u), sin(u), u);
}

DCoordinate3  helix::d1(GLdouble u){
    return DCoordinate3(-sin(u), cos(u), 1.0);
}

DCoordinate3  helix::d2 (GLdouble u){
    return DCoordinate3(-cos(u), -sin(u), 0.0);
}

//surfaces
GLdouble torus::R = 1.0;
GLdouble torus::r = 0.5;

GLdouble torus::u_min = 0.0;
GLdouble torus::u_max = TWO_PI;
GLdouble torus::v_min = 0.0;
GLdouble torus::v_max = TWO_PI;

DCoordinate3 torus::d00(GLdouble u, GLdouble v)
{
    return DCoordinate3((R + r * cos(v)) * cos(u),
                        (R + r * cos(v)) * sin(u),
                        r * sin(v)
                        );
}

DCoordinate3 torus::d10(GLdouble u, GLdouble v)
{
    return DCoordinate3(-(R + r * cos(v)) * sin(u),
                        (R + r * cos(v)) * cos(u),
                        0.0
                        );
}

DCoordinate3 torus::d01(GLdouble u, GLdouble v)
{
    return DCoordinate3(-r * sin(v) * cos(u),
                        -r * sin(v) * sin(u),
                        r * cos(v)
                        );
}

GLdouble dupin_cyclide::a = 1.0;
GLdouble dupin_cyclide::b = 0.98;
GLdouble dupin_cyclide::c = 0.199;
GLdouble dupin_cyclide::d = 0.3;

GLdouble dupin_cyclide::u_min = 0.0;
GLdouble dupin_cyclide::u_max = TWO_PI;
GLdouble dupin_cyclide::v_min = 0.0;
GLdouble dupin_cyclide::v_max = TWO_PI;

DCoordinate3 dupin_cyclide::d00(GLdouble u, GLdouble v)
{
    GLdouble cu = cos(u), cv = cos(v), denom = (a - c * cu * cv);
    return DCoordinate3((d * (c - a * cu * cv) + b*b * cu) / denom,
                        b * sin(u) * (a - d * cv) / denom,
                        b * sin(v) * (c * cu - d) / denom
                        );
}

DCoordinate3 dupin_cyclide::d10(GLdouble u, GLdouble v)
{
    GLdouble cu = cos(u), cv = cos(v), su = sin(u), sv = sin(v), denom = (a - c * cu * cv);
    denom *= denom;
    return DCoordinate3(- ((c*c - a*a) * d * cv + a * b*b) * su / denom,
                        b * (d * cv - a) * (c * cv * su*su + c * cv * cu*cu - a * cu) / denom,
                        b * c * (d * cv - a) * sv * su / denom
                        );
}

DCoordinate3 dupin_cyclide::d01(GLdouble u, GLdouble v)
{
    GLdouble cu = cos(u), cv = cos(v), su = sin(u), sv = sin(v), denom = (a - c * cu * cv);
    denom *= denom;
    return DCoordinate3(- cu * (b*b * c * cu + (c*c - a*a) * d) * sv / denom,
                        - a * b * (c * cu - d) * su * sv / denom,
                        - b * (c * cu - d) * (c * cu * sv*sv + c * cu * cv*cv - a * cv) / denom
                        );
}

GLdouble sphere::R = 2.0;

GLdouble sphere::u_min = 0.0;
GLdouble sphere::u_max = TWO_PI;
GLdouble sphere::v_min = EPS;
GLdouble sphere::v_max = PI - EPS;

DCoordinate3 sphere::d00(GLdouble u, GLdouble v)
{
    return DCoordinate3(R * cos(u) * sin(v),
                        R * sin(u) * sin(v),
                        R * cos(v)
                        );
}

DCoordinate3 sphere::d01(GLdouble u, GLdouble v)
{
    return DCoordinate3(- R * sin(u) * sin(v),
                        R * cos(u) * sin(v),
                        0.0
                        );
}

DCoordinate3 sphere::d10(GLdouble u, GLdouble v)
{
    return DCoordinate3(R * cos(u) * cos(v),
                        R * sin(u) * cos(v),
                        - R * sin(v)
                        );
}

GLdouble cylinder::R = 1.8;

GLdouble cylinder::u_min = 0.0;
GLdouble cylinder::u_max = TWO_PI;
GLdouble cylinder::v_min = -2.0;
GLdouble cylinder::v_max = 2.0;

DCoordinate3 cylinder::d00(GLdouble u, GLdouble v)
{
    return DCoordinate3(R * sin(u), v, R * cos(u));
}

DCoordinate3 cylinder::d10(GLdouble u, GLdouble v)
{
    return DCoordinate3(R * cos(u), 0.0, -R * sin(u));
}

DCoordinate3 cylinder::d01(GLdouble u, GLdouble v)
{
    return DCoordinate3(0.0, 1.0, 0.0);
}

GLdouble cone::R = 0.5;

GLdouble cone::u_min = 0.0;
GLdouble cone::u_max = TWO_PI;
GLdouble cone::v_min = -2.0;
GLdouble cone::v_max = 2.0;

DCoordinate3 cone::d00(GLdouble u, GLdouble v)
{
    return DCoordinate3(v, R * v * sin(u), R * v * cos(u));
}

DCoordinate3 cone::d10(GLdouble u, GLdouble v)
{
    return DCoordinate3(0.0, R * v * cos(u), -R * v * sin(u));
}

DCoordinate3 cone::d01(GLdouble u, GLdouble v)
{
    return DCoordinate3(1.0, R * sin(u), R * cos(u));
}


GLdouble seashell::c = 5.0/4.0;

GLdouble seashell::u_min = 0.0;
GLdouble seashell::u_max = TWO_PI;
GLdouble seashell::v_min = -TWO_PI;
GLdouble seashell::v_max = TWO_PI;

DCoordinate3 seashell::d00(GLdouble u, GLdouble v)
{
    return DCoordinate3(c * (1.0 - v / TWO_PI) * sin(2.0*v) * (1 + cos(u)) + sin(2.0*v),
                        c * (1.0 - v / TWO_PI) * cos(2.0*v) * (1 + cos(u)) + cos(2.0*v),
                        c * v + c * (1.0 - v / TWO_PI) * sin(u)
                        );
}

DCoordinate3 seashell::d10(GLdouble u, GLdouble v)
{
    return DCoordinate3(- c * (1.0 - v / TWO_PI) * sin(2.0*v) * sin(u),
                        - c * (1.0 - v / TWO_PI) * cos(2.0*v) * sin(u),
                        c * (1.0 - v / TWO_PI) * cos(u)
                        );
}

DCoordinate3 seashell::d01(GLdouble u, GLdouble v)
{
    return DCoordinate3(c * (1 + cos(u)) * (sin(2.0*v) / TWO_PI + (1.0 - v / TWO_PI) * 2.0 * cos(2.0*v)) + 2.0 * cos(2.0*v),
                        c * (1 + cos(u)) * (cos(2.0*v) / TWO_PI - (1.0 - v / TWO_PI) * 2.0 * sin(2.0*v)) - 2.0 * sin(2.0*v),
                        (1.0 - c * sin(u)) / TWO_PI
                        );
}
