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
        int lightIndex = -1;

        bool _createDl();
        bool _createPl();
        bool _createSl();
        void _destroyDl();
        void _destroyPl();
        void _destroySl();

        //materials
        RowMatrix<Material> _materials;
        void _create_materials();
        int selectedMaterial = 0;
        void applyMaterial();

        // your other declarations
        int arcOrPatch = 0;
        RowMatrix<Color4> colors;

        //everything with arcs
        int numberOfArcs = 9;
        float scaleArcDerivatives = 1;
        RowMatrix<SecondOrderHyperbolicArc> arcs;
        RowMatrix<GenericCurve3*> arcImages;
        int showArcDerivative1 = 0, showArcDerivative2 = 0;
        int selectedArc = 0;
        int selectedArcPoint = 0;

        //patches
        int numberOfPatches = 9;
        int showPatchDerivatives1 = 0, showPatchDerivatives2 = 0;
        float scalePatchDerivatives = 1;
        RowMatrix<SecHypPatch3*> patches;
        RowMatrix<TriangulatedMesh3*> beforeInterpolation, afterInterpolation;
        RowMatrix<RowMatrix<GLdouble>>	uKnotVectors;
        RowMatrix<ColumnMatrix<GLdouble>> vKnotVectors;
        RowMatrix<RowMatrix<GenericCurve3*> *> uCurves, vCurves;

        int selectedPatch = 0;
        int selectedPatchPointI = 0;
        int selectedPatchPointJ = 0;




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
        void sendArcPointCoordinates();

        //patches
        void createPatches();
        void renderPatches();

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
        void setArcOrPatch(int value);
        void setSelectedArc(int value);
        void setSelectedArcPoint(int value);
        void setShowArcDerivatives1(int value);
        void setShowArcDerivatives2(int value);
        void setScaleArcDerivatives(double value);
        void setArcPointX(double);
        void setArcPointY(double);
        void setArcPointZ(double);
        bool updateCurrentArcImage();


        //patches

   signals:
        void sendArcPointX(double);
        void sendArcPointY(double);
        void sendArcPointZ(double);
    };
}
