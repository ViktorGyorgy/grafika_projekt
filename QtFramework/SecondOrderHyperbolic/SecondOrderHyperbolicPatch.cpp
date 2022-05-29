#include "SecondOrderHyperbolicPatch.h"

using namespace cagd;

GLdouble SecHypPatch3::f0(GLdouble alpha, GLdouble t) const
{
    return f3(alpha, alpha - t);
}

GLdouble SecHypPatch3::f1(GLdouble alpha, GLdouble t) const
{
    return f2(alpha, alpha - t);
}

GLdouble SecHypPatch3::f2(GLdouble alpha, GLdouble t) const
{
    GLdouble firstPart = 4 * cosh(alpha / 2) / pow(sinh(alpha / 2), 4)
                                * sinh((alpha - t) / 2)
                                * pow(sinh(t / 2), 3);

    GLdouble secondPart = (1 + 2 * pow(cosh(alpha / 2) , 2)) / pow(sinh(alpha / 2), 4)
                            * pow(sinh((alpha - t) / 2), 2)
                            * pow(sinh(t / 2), 2);

    return firstPart + secondPart;
}

GLdouble SecHypPatch3::f3(GLdouble alpha, GLdouble t) const
{
    return pow(sinh(t / 2), 4) / pow(sinh(alpha / 2), 4);
}

GLdouble SecHypPatch3::f0_1(GLdouble alpha, GLdouble t) const
{
    return -f3_1(alpha, alpha - t);
}

GLdouble SecHypPatch3::f1_1(GLdouble alpha, GLdouble t) const
{
    return -f2_1(alpha, alpha - t);
}

GLdouble SecHypPatch3::f2_1(GLdouble alpha, GLdouble t) const
{
    GLdouble firstPart = sinh((alpha - t) / 2)
                            * (2 * cosh(alpha / 2) * cosh(t / 2) - (2 * pow(cosh(alpha/2), 2) + 1) * cosh((alpha - t) / 2) / 2)
                        * pow(sinh(t / 2), 2)
                        / pow(sinh(alpha / 2), 4);

    GLdouble secondPart = cosh((alpha -t ) / 2) * pow(sinh(t / 2), 2)
                            * (4 * cosh(alpha / 2) * sinh(t / 2) + (2 * pow(cosh(alpha / 2), 2) + 1)
                            * sinh((alpha - t) /2))
                            / (2 * pow(sinh(alpha / 2), 4));

   GLdouble thirdPart = sinh((alpha - t) / 2) * cosh(t / 2) * sinh(t / 2)
                            * (4 * cosh(alpha / 2) * sinh(t / 2) + (2 * pow(cosh(alpha / 2), 2) + 1) * sinh ((alpha - t) /2 ))
                            / pow(sinh(alpha/2), 4);


    return firstPart - secondPart + thirdPart;
}

GLdouble SecHypPatch3::f3_1(GLdouble alpha, GLdouble t) const
{
    return (cosh(t) - 1) * sinh(t) / (2 * pow(sinh(alpha / 2), 4));
}

GLdouble SecHypPatch3::f0_2(GLdouble alpha, GLdouble t) const
{
    return f3_2(alpha, alpha - t);
}

GLdouble SecHypPatch3::f1_2(GLdouble alpha, GLdouble t) const
{
    return f2_2(alpha, alpha - t);
}

GLdouble SecHypPatch3::f2_2(GLdouble alpha, GLdouble t) const
{
    return (8 * cosh(alpha / 2) * sinh((alpha - t) / 2) * pow(sinh(t / 2), 3)
            + (-12 * cosh(alpha / 2) * cosh ((alpha - t) / 2) * cosh(t / 2 )
               + (4 * pow(cosh(alpha / 2) , 2) + 2) * pow(sinh((alpha -  t) / 2), 2)
                + (2 * pow(cosh(alpha / 2), 2) + 1) * pow(cosh((alpha - t) / 2), 2))
                * pow(sinh(t / 2), 2)
            + (12 * cosh(alpha / 2) * sinh((alpha - t) / 2) * pow(cosh(t/2), 2)
                + (- 8 * pow(cosh(alpha / 2), 2) - 4) * cosh((alpha - t) / 2) * sinh((alpha - t) / 2) * cosh(t / 2))
                * sinh(t / 2)
            + (2 * pow(cosh(alpha / 2), 2) + 1) * pow(sinh((alpha - t) / 2), 2) * pow(cosh(t / 2), 2)
            )
            / 2 * pow(sinh(alpha / 2), 4);
}

GLdouble SecHypPatch3::f3_2(GLdouble alpha, GLdouble t) const
{
    return pow(1.0 / sinh(alpha / 2), 4)
            * (cosh(2 * t) - cosh(t))
            / 2.0;
}

SecHypPatch3::SecHypPatch3(GLdouble u, GLdouble v):TensorProductSurface3(0.0, u, 0.0, v){ _alpha[0] = u; _alpha[1] = v; }

GLboolean SecHypPatch3::UBlendingFunctionValues(
        GLdouble u_knot, RowMatrix<GLdouble>& blending_values) const
{
    blending_values.ResizeColumns(4);

    blending_values[0] = f0(_alpha[0], u_knot);
    blending_values[1] = f1(_alpha[0], u_knot);
    blending_values[2] = f2(_alpha[0], u_knot);
    blending_values[3] = f3(_alpha[0], u_knot);

    return GL_TRUE;
}

GLboolean SecHypPatch3::VBlendingFunctionValues(
        GLdouble v_knot, RowMatrix<GLdouble>& blending_values) const
{
    blending_values.ResizeColumns(4);

    blending_values[0] = f0(_alpha[1], v_knot);
    blending_values[1] = f1(_alpha[1], v_knot);
    blending_values[2] = f2(_alpha[1], v_knot);
    blending_values[3] = f3(_alpha[1], v_knot);

    return GL_TRUE;
}

GLboolean SecHypPatch3::CalculatePartialDerivatives(
        GLuint maximum_order_of_partial_derivatives,
        GLdouble u, GLdouble v, PartialDerivatives& pd) const
{
    if (u < 0.0 || u > _alpha[0] || v < 0.0 || v > _alpha[1] || maximum_order_of_partial_derivatives > 1)
        return GL_FALSE;

    RowMatrix<GLdouble> u_blending_values(4), d1_u_blending_values(4);
    RowMatrix<GLdouble> v_blending_values(4), d1_v_blending_values(4);

    UBlendingFunctionValues(u, u_blending_values);
    VBlendingFunctionValues(v, v_blending_values);

    d1_u_blending_values(0) = f0_1(_alpha[0], u);
    d1_u_blending_values(1) = f1_1(_alpha[0], u);
    d1_u_blending_values(2) = f2_1(_alpha[0], u);
    d1_u_blending_values(3) = f3_1(_alpha[0], u);

    d1_v_blending_values(0) = f0_1(_alpha[1], v);
    d1_v_blending_values(1) = f1_1(_alpha[1], v);
    d1_v_blending_values(2) = f2_1(_alpha[1], v);
    d1_v_blending_values(3) = f3_1(_alpha[1], v);

    pd.ResizeRows(2);
    pd.LoadNullVectors();

    for(GLuint row = 0; row < 4; ++row)
    {
        DCoordinate3 aux_d0_v, aux_d1_v;
        for (GLuint column = 0; column < 4; ++column)
        {
            aux_d0_v += _data(row,column) * v_blending_values(column);
            aux_d1_v += _data(row, column) * d1_v_blending_values(column);
        }
        pd(0,0) += aux_d0_v * u_blending_values(row);
        pd(1,0) += aux_d0_v * d1_u_blending_values(row);
        pd(1,1) += aux_d1_v * u_blending_values(row);
    }

    return GL_TRUE;
}

GLboolean SecHypPatch3::SetUAlpha(GLdouble alpha) {
    _alpha[0] = alpha;
    _u_max = alpha;
    return true;
}
GLdouble SecHypPatch3::GetUAlpha() {
    return _alpha[0];
}

GLboolean SecHypPatch3::SetVAlpha(GLdouble alpha) {
    _alpha[1] = alpha;
    _v_max = alpha;
    return true;
}
GLdouble SecHypPatch3::GetVAlpha() {
    return _alpha[1];
}
