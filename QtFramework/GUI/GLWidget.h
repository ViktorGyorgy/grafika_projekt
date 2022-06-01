#pragma once

#include <GL/glew.h>
#include <QOpenGLWidget>
#include <QOpenGLTexture>
#include <Parametric/ParametricCurves3.h>
#include <Parametric/ParametricSurfaces3.h>
#include <Core/TriangulatedMeshes3.h>
#include <Core/ModelProperties.h>
#include <Core/Materials.h>
#include <Core/HCoordinates3.h>
#include <Core/Lights.h>
#include <Cyclic/CyclicCurves3.h>
#include "../Core/ShaderPrograms.h"
#include "SecondOrderHyperbolic/SecondOrderHyperbolicArc.h"
#include "SecondOrderHyperbolic/SecondOrderHyperbolicPatch.h"
#include <vector>

namespace cagd
{
    class GLWidget: public QOpenGLWidget
    {
        Q_OBJECT

    private:

        // variables defining the projection matrix
        double       _aspect;            // aspect ratio of the rendering window
        double       _fovy;              // field of view in direction y
        double       _z_near, _z_far;    // distance of near and far clipping planes

        // variables defining the model-view matrix
        double       _eye[3], _center[3], _up[3];

        // variables needed by transformations
        int         _angle_x, _angle_y, _angle_z;
        double      _zoom;
        double      _trans_x, _trans_y, _trans_z;

        //lights
        DirectionalLight * _dl;
        PointLight * _pl;
        Spotlight * _sl;
        int turnOnLight = 0;
        int selectedLight = 0;

        bool _createDl();
        bool _createPl();
        bool _createSl();
        void _destroyDl();
        void _destroyPl();
        void _destroySl();

        void enableSelectedLight();
        void disableSelectedLight();

        //materials

        RowMatrix<Material> materials;
        RowMatrix<int> selectedMaterial;
        void initSelectedMaterial();
        void createMaterials();

        // your other declarations
        int arcOrPatch = 0;
        RowMatrix<Color4> colors;

        //everything with arcs
        int numberOfArcs = 9;
        float scaleArcDerivatives = 1;
        RowMatrix<SecondOrderHyperbolicArc> arcs;
        RowMatrix<GenericCurve3*> arcImages;
        int showArcDerivative1 = 0;
        int showArcDerivative2 = 0;
        int showArcControlPolygon = 0;
        int showArcDataPoints = 0;
        int selectedArc = 0;
        int selectedArcPoint = 0;
        int selectedArcJoinType = 0;
        int selectedJoiningArc = 0;

        vector<SecondOrderHyperbolicArc> otherArcs;
        vector<GenericCurve3*> otherArcImages;

        //patches
        int numberOfPatches = 9;

        int showPatchControlPolygon = 0;
        int showPatchDataPoints = 0;
        int showInterpolatingSurface = 0;
        int showNormalVectors = 0;
        int showUIsometricCurves = 0;
        int showVIsometricCurves = 0;
        int showIsometricDerivatives = 0;
        int showPatchDerivatives = 0;
        int showPatchPartialDerivatives = 0;


        float scalePatchDerivatives = 1;
        RowMatrix<SecHypPatch3*> patches;
        RowMatrix<TriangulatedMesh3*> beforeInterpolation, afterInterpolation;
        RowMatrix<RowMatrix<GLdouble>>	uKnotVectors;
        RowMatrix<ColumnMatrix<GLdouble>> vKnotVectors;
        RowMatrix<RowMatrix<GenericCurve3*> *> uCurves, vCurves;
        RowMatrix<Matrix<DCoordinate3>> _data_points_to_interpolate;

        vector<SecHypPatch3> otherPatches;

        int selectedPatch = 0;
        int selectedPatchPoint = 0;
        int selectedPatchPointI = 0;
        int selectedPatchPointJ = 0;

        int selectedPatchJoinType = 0;
        int selectedJoiningPatch = 0;

    public:
        // special and default constructor
        // the format specifies the properties of the rendering window
        GLWidget(QWidget* parent = 0);

        // redeclared virtual functions
        void initializeGL();
        void paintGL();
        void resizeGL(int w, int h);

        void initializeColors();
        //arc stuff
        void createArcs();
        void updateArcs();
        void renderArcs();
        void renderOtherArcs();
        void sendArcPointCoordinates();



        //patches
        void createPatches();
        void renderPatches();
        void renderOtherPatches();
        void sendPatchPointCoordinates();

    public slots:
        // public event handling methods/slots
        void set_angle_x(int value);
        void set_angle_y(int value);
        void set_angle_z(int value);

        void set_zoom_factor(double value);

        void set_trans_x(double value);
        void set_trans_y(double value);
        void set_trans_z(double value);

        //from here our code
        //arcs
        void setArcOrPatch(int value);
        void setSelectedArc(int value);
        void setSelectedArcPoint(int value);
        void setShowArcDerivatives1(int value);
        void setShowArcDerivatives2(int value);
        void setShowArcControlPolygon(int value);
        void setShowArcDataPoints(int value);
        void setScaleArcDerivatives(double value);
        void setArcPointX(double value);
        void setArcPointY(double value);
        void setArcPointZ(double value);
        bool updateCurrentArcImage();
        bool updateSelectedJoiningArcImage();
        void setSelectedArcJoinType(int value);
        void setSelectedJoiningArc(int value);
        void setArcAlpha(double value);

        //arc join merge extend
        void extendArcLeft();
        void extendArcRight();
        void mergeArcs();
        void joinArcs();


        //patches
        void setSelectedPatch(int value);
        void setSelectedPatchPoint(int value);
        void setPatchPointX(double value);
        void setPatchPointY(double value);
        void setPatchPointZ(double value);
        void setShowPatchControlPolygon(int value);
        void setShowPatchDataPoints(int value);
        void setShowInterpolatingSurface(int value);
        void setShowNormalVectors(int value);
        void setSelectedMaterialOfSelectedPatch(int value);
        void setSelectedLight(int value);
        void setTurnOnSelectedLight(int value);
        void setshowUIsometricCurves(int value);
        void setshowVIsometricCurves(int value);
        void setshowIsometricCurvesDerivatives(int value);
        void setshowPatchDerivatives(int value);
        void setshowPatchPartialDerivatives(int value);
        void updateCurrentPatchImage();
        void setSelectedPatchJoinType(int value);
        void setSelectedJoiningPatch(int value);
        void setPatchUalpha(double);
        void setScalePatchDerivatives(double);
        void updatePatches();

        //extend patches
        void extendPatchWest();
        void extendPatchEast();
        void extendPatchNorth();
        void extendPatchSouth();

        void joinPatches();
        void mergePatches();

   signals:
        void sendArcPointX(double);
        void sendArcPointY(double);
        void sendArcPointZ(double);

        void sendPatchPointX(double);
        void sendPatchPointY(double);
        void sendPatchPointZ(double);
    };
}
