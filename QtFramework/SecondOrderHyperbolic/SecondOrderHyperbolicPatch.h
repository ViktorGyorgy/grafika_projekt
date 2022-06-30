#ifndef SECONDORDERHYPERBOLICPATCH_H
#define SECONDORDERHYPERBOLICPATCH_H
#include <Core/TensorProductSurfaces3.h>
#include "../Core/Constants.h"

namespace cagd
{
    enum Variable{U, V};

    class SecHypPatch3: public TensorProductSurface3
    {
    private:
        GLdouble _alpha[2]; // _alpha[U], _alpha[V], i.e., possible shape parameters in directions u and v, respective

        GLdouble _translatedX;
        GLdouble _translatedY;
        GLdouble _translatedZ;

        GLboolean _has_neighbours;


        GLboolean _updated;


        int                _connected_side[8];



        RowMatrix<GenericCurve3*>* _uip;
        RowMatrix<GenericCurve3*>* _vip;

        GLdouble f0(GLdouble alpha, GLdouble t) const;
        GLdouble f1(GLdouble alpha, GLdouble t) const;
        GLdouble f2(GLdouble alpha, GLdouble t) const;
        GLdouble f3(GLdouble alpha, GLdouble t) const;

        GLdouble f0_1(GLdouble alpha, GLdouble t) const;
        GLdouble f1_1(GLdouble alpha, GLdouble t) const;
        GLdouble f2_1(GLdouble alpha, GLdouble t) const;
        GLdouble f3_1(GLdouble alpha, GLdouble t) const;

        GLdouble f0_2(GLdouble alpha, GLdouble t) const;
        GLdouble f1_2(GLdouble alpha, GLdouble t) const;
        GLdouble f2_2(GLdouble alpha, GLdouble t) const;
        GLdouble f3_2(GLdouble alpha, GLdouble t) const;



    public:
        SecHypPatch3*      _neighbours[8];
        TriangulatedMesh3*  _image = nullptr;
        SecHypPatch3(GLdouble u_alpha = PI / 2.0, GLdouble v_alpha = 1.0);

        // inherited pure virtual methods have to be redeclared and defined
        GLboolean UBlendingFunctionValues(GLdouble u, RowMatrix<GLdouble> &blending_values) const;
        GLboolean VBlendingFunctionValues(GLdouble v, RowMatrix<GLdouble> &blending_values) const;
        GLboolean CalculatePartialDerivatives(
                        GLuint maximum_order_of_partial_derivatives,
                        GLdouble u, GLdouble v, PartialDerivatives &pd) const;

        GLboolean SetUAlpha(GLdouble alpha);
        GLdouble GetUAlpha();

        GLboolean SetVAlpha(GLdouble alpha);
        GLdouble GetVAlpha();

        GLboolean   translateX(double value);
        GLboolean   translateY(double value);
        GLboolean   translateZ(double value);

        GLboolean   SetNeighbour(int neighbour, int side, SecHypPatch3 *patch);

        double      GetTranslatedX();
        double      GetTranslatedY();
        double      GetTranslatedZ();

        GLvoid      SetImage(TriangulatedMesh3* image);
        TriangulatedMesh3* GetImage();

        GLboolean   ExtendPatch(int dir, SecHypPatch3 &patch);
        GLboolean   JoinPatch(SecHypPatch3 &patch, int side1, int side2, SecHypPatch3 &result);
        GLboolean   MergePatch(SecHypPatch3 &patch, int side1, int side2);

        GLvoid      PreserveContinuity(int row, int col, DCoordinate3 point);

        GLboolean   SetUip(RowMatrix<GenericCurve3*>* uip);
        GLboolean   SetVip(RowMatrix<GenericCurve3*>* vip);

        RowMatrix<GenericCurve3*>*      GetUip();
        RowMatrix<GenericCurve3*>*      GetVip();

        GLboolean ExtendNorth(SecHypPatch3 &patch);
        GLboolean ExtendEast(SecHypPatch3 &patch);
        GLboolean ExtendSouth(SecHypPatch3 &patch);
        GLboolean ExtendWest(SecHypPatch3 &patch);

        GLboolean ExtendNorthEast(SecHypPatch3 &patch);
        GLboolean ExtendSouthEast(SecHypPatch3 &patch);
        GLboolean ExtendSouthWest(SecHypPatch3 &patch);
        GLboolean ExtendNorthWest(SecHypPatch3 &patch);

        GLboolean JoinEastWest(SecHypPatch3 &patch, int side1, int side2, SecHypPatch3 &result);
        GLboolean JoinNorthSouth(SecHypPatch3 &patch, int side1, int side2, SecHypPatch3 &result);

        GLboolean JoinEastEast(SecHypPatch3 &patch, SecHypPatch3 &result);
        GLboolean JoinWestWest(SecHypPatch3 &patch, SecHypPatch3 &result);

        GLboolean JoinSouthSouth(SecHypPatch3 &patch, SecHypPatch3 &result);
        GLboolean JoinNorthNorth(SecHypPatch3 &patch, SecHypPatch3 &result);

        GLboolean JoinNorthEast(SecHypPatch3 &patch, SecHypPatch3 &result);
        GLboolean JoinNorthWest(SecHypPatch3 &patch, SecHypPatch3 &result);

        GLboolean JoinSouthWest(SecHypPatch3 &patch, SecHypPatch3 &result);
        GLboolean JoinSouthEast(SecHypPatch3 &patch, SecHypPatch3 &result);

        GLboolean MergeEastWest(SecHypPatch3 &patch, int side1, int side2);
        GLboolean MergeNorthSouth(SecHypPatch3 &patch, int side1, int side2);

        GLboolean MergeEastEast(SecHypPatch3 &patch);
        GLboolean MergeWestWest(SecHypPatch3 &patch);

        GLboolean MergeNorthNorth(SecHypPatch3 &patch);
        GLboolean MergeSouthSouth(SecHypPatch3 &patch);

        GLboolean MergeNorthWest(SecHypPatch3 &patch);
        GLboolean MergeNorthEast(SecHypPatch3 &patch);
        GLboolean MergeSouthWest(SecHypPatch3 &patch);
        GLboolean MergeSouthEast(SecHypPatch3 &patch);

        GLvoid    PreserveNorth(int row, int col, DCoordinate3 point);
        GLvoid    PreserveEast(int row, int col, DCoordinate3 point);
        GLvoid    PreserveSouth(int row, int col, DCoordinate3 point);
        GLvoid    PreserveWest(int row, int col, DCoordinate3 point);

        GLvoid    PreserveNorthEast(int row, int col, DCoordinate3 point);
        GLvoid    PreserveSouthEast(int row, int col, DCoordinate3 point);
        GLvoid    PreserveSouthWest(int row, int col, DCoordinate3 point);
        GLvoid    PreserveNorthWest(int row, int col, DCoordinate3 point);

        GLvoid    PreserveAlphaU(double u_alpha);
        GLvoid    PreserveAlphaV(double v_alpha);

    };
}
#endif // SECONDORDERHYPERBOLICPATCH_H
