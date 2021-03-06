#ifndef SOMEARCS3_H
#define SOMEARCS3_H

#include <Core/Constants.h>
#include <Core/LinearCombination3.h>

namespace cagd
{
    class SecondOrderHyperbolicArc: public LinearCombination3
    {
    private:
        GLdouble _alpha = PI / 2.0;

        GLdouble f0(GLdouble t) const;
        GLdouble f1(GLdouble t) const;
        GLdouble f2(GLdouble t) const;
        GLdouble f3(GLdouble t) const;

        GLdouble f0_1(GLdouble t) const;
        GLdouble f1_1(GLdouble t) const;
        GLdouble f2_1(GLdouble t) const;
        GLdouble f3_1(GLdouble t) const;

        GLdouble f0_2(GLdouble t) const;
        GLdouble f1_2(GLdouble t) const;
        GLdouble f2_2(GLdouble t) const;
        GLdouble f3_2(GLdouble t) const;

        GenericCurve3* _image = nullptr;

    public:
        // Variables for the interaction with curves
        SecondOrderHyperbolicArc *left = nullptr, *right = nullptr;
        int joinTypeLeft, joinTypeRight;

        GLuint image_index;

        // special/default constructor
        SecondOrderHyperbolicArc(GLdouble alpha = PI / 2.0, GLenum data_usage_flag = GL_STATIC_DRAW);

        // inherited pure virtual methods have to be redeclared and defined
        GLboolean BlendingFunctionValues(GLdouble u, RowMatrix<GLdouble> &values) const;
        GLboolean CalculateDerivatives(GLuint max_order_of_derivatives, GLdouble u, Derivatives& d) const;

        // project-dependent setters/getters, e.g.,
        void setImage(GenericCurve3* _image);
        GenericCurve3* getImage();

        // if exists, you will need to set/get the shape/tension parameter of the basis/blending functions
        GLboolean SetAlpha(GLdouble alpha);
        GLdouble GetAlpha() const;

        DCoordinate3& getPoint(GLuint index);
        void setPoint(GLuint index, GLdouble x, GLdouble y, GLdouble z);
        void setPoint(GLuint index, const DCoordinate3 &position);


        //Functions for manipulating arcs
        void translateX(GLdouble value);
        void translateY(GLdouble value);
        void translateZ(GLdouble value);

        SecondOrderHyperbolicArc* extendLeft(); //Continue
        SecondOrderHyperbolicArc* extendRight(); //Continue

        SecondOrderHyperbolicArc* joinLeftLeft(SecondOrderHyperbolicArc *arc);
        SecondOrderHyperbolicArc* joinLeftRight(SecondOrderHyperbolicArc *arc);
        SecondOrderHyperbolicArc* joinRightLeft(SecondOrderHyperbolicArc *arc);
        SecondOrderHyperbolicArc* joinRightRight(SecondOrderHyperbolicArc *arc);

        void mergeLeftLeft(SecondOrderHyperbolicArc *arc);
        void mergeLeftRight(SecondOrderHyperbolicArc *arc);
        void mergeRightLeft(SecondOrderHyperbolicArc *arc);
        void mergeRightRight(SecondOrderHyperbolicArc *arc);

        SecondOrderHyperbolicArc* preserveContinuity(GLuint index,int axis,GLdouble value);

        void PreserveAlpha(double alpha);
    };
}

#endif // SOMEARCS3_H
