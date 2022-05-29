#include "SecondOrderHyperbolicArc.h"
#include "../Core/Constants.h"

using namespace cagd;

GLdouble SecondOrderHyperbolicArc::f0(GLdouble t) const
{
    return f3(_alpha - t);
}

GLdouble SecondOrderHyperbolicArc::f1(GLdouble t) const
{
    return f2(_alpha - t);
}

GLdouble SecondOrderHyperbolicArc::f2(GLdouble t) const
{
    GLdouble firstPart = 4 * cosh(_alpha / 2) / pow(sinh(_alpha / 2), 4)
                                * sinh((_alpha - t) / 2)
                                * pow(sinh(t / 2), 3);

    GLdouble secondPart = (1 + 2 * pow(cosh(_alpha / 2) , 2)) / pow(sinh(_alpha / 2), 4)
                            * pow(sinh((_alpha - t) / 2), 2)
                            * pow(sinh(t / 2), 2);

    return firstPart + secondPart;
}

GLdouble SecondOrderHyperbolicArc::f3(GLdouble t) const
{
    return pow(sinh(t / 2), 4) / pow(sinh(_alpha / 2), 4);
}

GLdouble SecondOrderHyperbolicArc::f0_1(GLdouble t) const
{
    return -f3_1(_alpha - t);
}

GLdouble SecondOrderHyperbolicArc::f1_1(GLdouble t) const
{
    return -f2_1(_alpha - t);
}

GLdouble SecondOrderHyperbolicArc::f2_1(GLdouble t) const
{
    GLdouble firstPart = sinh((_alpha - t) / 2)
                            * (2 * cosh(_alpha / 2) * cosh(t / 2) - (2 * pow(cosh(_alpha/2), 2) + 1) * cosh((_alpha - t) / 2) / 2)
                        * pow(sinh(t / 2), 2)
                        / pow(sinh(_alpha / 2), 4);

    GLdouble secondPart = cosh((_alpha -t ) / 2) * pow(sinh(t / 2), 2)
                            * (4 * cosh(_alpha / 2) * sinh(t / 2) + (2 * pow(cosh(_alpha / 2), 2) + 1)
                            * sinh((_alpha - t) /2))
                            / (2 * pow(sinh(_alpha / 2), 4));

   GLdouble thirdPart = sinh((_alpha - t) / 2) * cosh(t / 2) * sinh(t / 2)
                            * (4 * cosh(_alpha / 2) * sinh(t / 2) + (2 * pow(cosh(_alpha / 2), 2) + 1) * sinh ((_alpha - t) /2 ))
                            / pow(sinh(_alpha/2), 4);


    return firstPart - secondPart + thirdPart;
}

GLdouble SecondOrderHyperbolicArc::f3_1(GLdouble t) const
{
    return (cosh(t) - 1) * sinh(t) / (2 * pow(sinh(_alpha / 2), 4));
}

GLdouble SecondOrderHyperbolicArc::f0_2(GLdouble t) const
{
    return f3_2(_alpha - t);
}

GLdouble SecondOrderHyperbolicArc::f1_2(GLdouble t) const
{
    return f2_2(_alpha - t);
}

GLdouble SecondOrderHyperbolicArc::f2_2(GLdouble t) const
{
    //csch(a) = 1 / sinh(a);
    return  (8.0 * cosh(_alpha / 2.0) * sinh((_alpha - t) / 2.0) * pow(sinh(t / 2.0), 3.0)

                       + (-12.0 * cosh(_alpha / 2.0) * cosh ((_alpha - t) / 2.0) * cosh(t / 2.0 )
                          + (4.0 * pow(cosh(_alpha / 2.0) , 2.0) + 2.0) * pow(sinh((_alpha -  t) / 2.0), 2.0)
                           + (2.0 * pow(cosh(_alpha / 2.0), 2.0) + 1.0) * pow(cosh((_alpha - t) / 2.0), 2.0))
                           * pow(sinh(t / 2.0), 2.0)

                       + (12.0 * cosh(_alpha / 2.0) * sinh((_alpha - t) / 2.0) * pow(cosh(t/2.0), 2.0)
                           + (- 8.0 * pow(cosh(_alpha / 2.0), 2.0) - 4.0) * cosh((_alpha - t) / 2.0) * sinh((_alpha - t) / 2.0) * cosh(t / 2.0))
                           * sinh(t / 2.0)

                       + (2.0 * pow(cosh(_alpha / 2.0), 2.0) + 1.0) * pow(sinh((_alpha - t) / 2.0), 2.0) * pow(cosh(t / 2.0), 2.0)
                       )
                       / (2.0 * pow(sinh(_alpha / 2.0), 4.0));
}

GLdouble SecondOrderHyperbolicArc::f3_2(GLdouble t) const
{
      return (pow(sinh(t / 2.0), 4.0) + 3.0 * pow(cosh(t/2.0), 2.0) * pow(sinh(t/2.0), 2.0))
                / pow(sinh(_alpha / 2.0), 4.0);
//    return pow(1 / sinh(_alpha / 2), 4)
//            * (cosh(2 * t) - cosh(t))
//            / 2;
}


GLboolean SecondOrderHyperbolicArc::BlendingFunctionValues(GLdouble u, RowMatrix<GLdouble> &values) const
{
    values.ResizeColumns(4);

    values[0] = f0(u);
    values[1] = f1(u);
    values[2] = f2(u);
    values[3] = f3(u);

    return GL_TRUE;
}

GLboolean SecondOrderHyperbolicArc::CalculateDerivatives(GLuint max_order_of_derivatives, GLdouble u, Derivatives &d) const
{
    d.ResizeRows(max_order_of_derivatives + 1);
    d.LoadNullVectors();

    d[0] = f0(u) * _data[0] + f1(u) * _data[1] + f2(u) * _data[2] + f3(u) * _data[3];

    if(max_order_of_derivatives >= 1) {
        d[1] = f0_1(u) * _data[0] + f1_1(u) * _data[1] + f2_1(u) * _data[2] + f3_1(u) * _data[3];
    }

    if(max_order_of_derivatives == 2) {
        d[2] = f0_2(u) * _data[0] + f1_2(u) * _data[1] + f2_2(u) * _data[2] + f3_2(u) * _data[3];
    }
    return GL_TRUE;
}

GLboolean SecondOrderHyperbolicArc::SetAlpha(GLdouble alpha) {
    _u_max = alpha;
    return _alpha = alpha;
}
GLdouble SecondOrderHyperbolicArc::GetAlpha() const {
    return _alpha;
}

SecondOrderHyperbolicArc::SecondOrderHyperbolicArc(GLdouble alpha, GLenum data_usage_flag):LinearCombination3(0.0, alpha, 4, data_usage_flag)
{
    _alpha = alpha;
}
