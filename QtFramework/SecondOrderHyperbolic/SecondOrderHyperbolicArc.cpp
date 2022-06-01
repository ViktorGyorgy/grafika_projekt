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

DCoordinate3& SecondOrderHyperbolicArc::getPoint(GLuint index){
    return _data[index];
}
void SecondOrderHyperbolicArc::setPoint(GLuint index, GLdouble x, GLdouble y, GLdouble z){
    setPoint(index,DCoordinate3(x,y,z));
}
void SecondOrderHyperbolicArc::setPoint(GLuint index, const DCoordinate3 &position){
    _data[index]=position;
}



//Functions for manipulating arcs
void SecondOrderHyperbolicArc::translateX(GLdouble value){
    for(int i=0;i<4;i++){
        _data[i].x()+=value;
    }
}
void SecondOrderHyperbolicArc::translateY(GLdouble value){
    for(int i=0;i<4;i++){
        _data[i].y()+=value;
    }
}
void SecondOrderHyperbolicArc::translateZ(GLdouble value){
    for(int i=0;i<4;i++){
        _data[i].z()+=value;
    }
}

SecondOrderHyperbolicArc* SecondOrderHyperbolicArc::extendLeft(){  //Continue
    SecondOrderHyperbolicArc *extension = new SecondOrderHyperbolicArc();
    extension->setPoint(3,getPoint(0));
    extension->setPoint(2,2*getPoint(0)-getPoint(1));
    extension->setPoint(1,2*extension->getPoint(2)-extension->getPoint(3));
    extension->setPoint(0,2*extension->getPoint(1)-extension->getPoint(2));
    this->left=extension;
    extension->right=this;

    return extension;
}
SecondOrderHyperbolicArc* SecondOrderHyperbolicArc::extendRight(){ //Continue
    SecondOrderHyperbolicArc *extension = new SecondOrderHyperbolicArc();
    extension->setPoint(0,getPoint(3));
    extension->setPoint(1,2*getPoint(3)-getPoint(2));
    extension->setPoint(2,2*extension->getPoint(1)-extension->getPoint(0));
    extension->setPoint(3,2*extension->getPoint(2)-extension->getPoint(1));
    this->right=extension;
    extension->left=this;

    return extension;
}

SecondOrderHyperbolicArc* SecondOrderHyperbolicArc::joinLeftLeft(SecondOrderHyperbolicArc *arc){
    SecondOrderHyperbolicArc *joinArc = new SecondOrderHyperbolicArc();
    joinArc->setPoint(3,getPoint(0));
    joinArc->setPoint(0,arc->getPoint(0));
    joinArc->setPoint(2,2*getPoint(0)-getPoint(1));
    joinArc->setPoint(1,2*arc->getPoint(0)-arc->getPoint(1));
    this->left=joinArc;
    arc->left=joinArc;
    joinArc->right=this;
    joinArc->left=arc;

    return joinArc;
}
SecondOrderHyperbolicArc* SecondOrderHyperbolicArc::joinLeftRight(SecondOrderHyperbolicArc *arc){
    SecondOrderHyperbolicArc *joinArc = new SecondOrderHyperbolicArc();
    joinArc->setPoint(3,getPoint(0));
    joinArc->setPoint(0,arc->getPoint(3));
    joinArc->setPoint(2,2*getPoint(0)-getPoint(1));
    joinArc->setPoint(1,2*arc->getPoint(3)-arc->getPoint(2));
    this->left=joinArc;
    arc->right=joinArc;
    joinArc->right=this;
    joinArc->left=arc;

    return joinArc;
}
SecondOrderHyperbolicArc* SecondOrderHyperbolicArc::joinRightLeft(SecondOrderHyperbolicArc *arc){
    SecondOrderHyperbolicArc *joinArc = new SecondOrderHyperbolicArc();
    joinArc->setPoint(3,getPoint(3));
    joinArc->setPoint(0,arc->getPoint(0));
    joinArc->setPoint(2,2*getPoint(3)-getPoint(2));
    joinArc->setPoint(1,2*arc->getPoint(0)-arc->getPoint(1));
    this->right=joinArc;
    arc->left=joinArc;
    joinArc->right=this;
    joinArc->left=arc;

    return joinArc;

}
SecondOrderHyperbolicArc* SecondOrderHyperbolicArc::joinRightRight(SecondOrderHyperbolicArc *arc){
    SecondOrderHyperbolicArc *joinArc = new SecondOrderHyperbolicArc();
    joinArc->setPoint(3,getPoint(3));
    joinArc->setPoint(0,arc->getPoint(3));
    joinArc->setPoint(2,2*getPoint(3)-getPoint(2));
    joinArc->setPoint(1,2*arc->getPoint(3)-arc->getPoint(2));
    this->right=joinArc;
    arc->right=joinArc;
    joinArc->right=this;
    joinArc->left=arc;

    return joinArc;
}

void SecondOrderHyperbolicArc::mergeLeftLeft(SecondOrderHyperbolicArc *arc){
    setPoint(0,(getPoint(1)+arc->getPoint(1))/2);
    arc->setPoint(0,(getPoint(1)+arc->getPoint(1))/2);
    this->left=arc;
    arc->left=this;
}
void SecondOrderHyperbolicArc::mergeLeftRight(SecondOrderHyperbolicArc *arc){
    setPoint(0,(getPoint(1)+arc->getPoint(2))/2);
    arc->setPoint(3,(getPoint(1)+arc->getPoint(2))/2);
    this->left=arc;
    arc->right=this;
}
void SecondOrderHyperbolicArc::mergeRightLeft(SecondOrderHyperbolicArc *arc){
    setPoint(3,(getPoint(2)+arc->getPoint(1))/2);
    arc->setPoint(0,(getPoint(2)+arc->getPoint(1))/2);
    this->right=arc;
    arc->left=this;
}
void SecondOrderHyperbolicArc::mergeRightRight(SecondOrderHyperbolicArc *arc){
    setPoint(3,(getPoint(2)+arc->getPoint(2))/2);
    arc->setPoint(3,(getPoint(2)+arc->getPoint(2))/2);
    this->right=arc;
    arc->right=this;
}

SecondOrderHyperbolicArc* SecondOrderHyperbolicArc::preserveContinuity(GLuint index,int axis,GLdouble value){
    DCoordinate3 movement;
    movement[axis] = value;
    switch (index) {
        case 0:
            if (left != NULL){
                setPoint(1,getPoint(1)+movement);
                if (left->left == this){
                    left->setPoint(0,getPoint(0));
                    left->setPoint(1,2*getPoint(0)-getPoint(1));
                }
                else{
                    left->setPoint(3,getPoint(0));
                    left->setPoint(2,2*getPoint(0)-getPoint(1));
                }
                return left;
            }
            break;
        case 1:
            if (left != NULL){
                if (left->left == this){
                    left->setPoint(1,2*getPoint(0)-getPoint(1));
                }
                else{
                    left->setPoint(2,2*getPoint(0)-getPoint(1));
                }
                return left;
            }
            break;
        case 2:
            if (right != NULL){
                if (right->left == this){
                    right->setPoint(1,2*getPoint(3)-getPoint(2));
                }
                else{
                    right->setPoint(2,2*getPoint(3)-getPoint(2));
                }
                return right;
            }
            break;
        case 3:
            if (right != NULL){
                setPoint(2,getPoint(2)+movement);
                if (right->left == this){
                    right->setPoint(0,getPoint(3));
                    right->setPoint(1,2*getPoint(3)-getPoint(2));
                }
                else{
                    right->setPoint(3,getPoint(3));
                    right->setPoint(2,2*getPoint(3)-getPoint(2));
                }
                return right;
            }
            break;
        default:
            std::cout<<"Error in preserving continuity";
    }
    return NULL;
}


void SecondOrderHyperbolicArc::PreserveAlpha(double alpha) {
    if (_alpha == alpha) return;
    _alpha = alpha;
    _u_max = alpha;

    DeleteVertexBufferObjectsOfData();
    if(!UpdateVertexBufferObjectsOfData(GL_STATIC_DRAW))
    {

    }

//    if (_image) _image->DeleteVertexBufferObjects();
    _image = GenerateImage(2, 100, GL_STATIC_DRAW);

    if(!_image)
    {
        return;
    }

    if(!_image->UpdateVertexBufferObjects())
    {
//        cout << "Could_not_create_the_vertex_buffer_object_of_the_cyclic_curve!" << endl;
    }

    if (left) left->PreserveAlpha(alpha);
    if (right) right->PreserveAlpha(alpha);
}
