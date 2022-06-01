#include "GLWidget.h"

#if !defined(__APPLE__)
#include <GL/glu.h>
#endif

#include <iostream>
using namespace std;

#include <Core/Exceptions.h>

namespace cagd
{
    //--------------------------------
    // special and default constructor
    //--------------------------------
    GLWidget::GLWidget(QWidget *parent): QOpenGLWidget(parent)
    {
    }

    //--------------------------------------------------------------------------------------
    // this virtual function is called once before the first call to paintGL() or resizeGL()
    //--------------------------------------------------------------------------------------
    void GLWidget::initializeGL()
    {
        // creating a perspective projection matrix
        glMatrixMode(GL_PROJECTION);

        glLoadIdentity();

        _aspect = static_cast<double>(width()) / static_cast<double>(height());
        _z_near = 1.0;
        _z_far  = 1000.0;
        _fovy   = 45.0;

        gluPerspective(_fovy, _aspect, _z_near, _z_far);

        // setting the model view matrix
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        _eye[0] = _eye[1] = 0.0; _eye[2] = 6.0;
        _center[0] = _center[1] = _center[2] = 0.0;
        _up[0] = _up[2] = 0.0; _up[1] = 1.0;

        gluLookAt(_eye[0], _eye[1], _eye[2], _center[0], _center[1], _center[2], _up[0], _up[1], _up[2]);

        // enabling the depth test
        glEnable(GL_DEPTH_TEST);

        // setting the background color
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

        // initial values of transformation parameters
        _angle_x = _angle_y = _angle_z = 0.0;
        _trans_x = _trans_y = _trans_z = 0.0;
        _zoom = 1.0;

        // ...

        try
        {
            // initializing the OpenGL Extension Wrangler library
            GLenum error = glewInit();

            if (error != GLEW_OK)
            {
                throw Exception("Could not initialize the OpenGL Extension Wrangler Library!");
            }

            if (!glewIsSupported("GL_VERSION_2_0"))
            {
                throw Exception("Your graphics card is not compatible with OpenGL 2.0+! "
                                "Try to update your driver or buy a new graphics adapter!");
            }

            // create and store your geometry in display lists or vertex buffer objects
            // ...

            //lights
            _createDl();
            _createPl();
            _createSl();

            initializeColors();
            createArcs();
            sendArcPointCoordinates();


            //patches
            initSelectedMaterial();
            createMaterials();
            createPatches();
            sendPatchPointCoordinates();
        }
        catch (Exception &e)
        {
            cout << e << endl;
        }
    }

    //-----------------------
    // the rendering function
    //-----------------------
    void GLWidget::paintGL()
    {
        // clears the color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // stores/duplicates the original model view matrix
        glPushMatrix();

            // applying transformations
            glRotatef(_angle_x, 1.0, 0.0, 0.0);
            glRotatef(_angle_y, 0.0, 1.0, 0.0);
            glRotatef(_angle_z, 0.0, 0.0, 1.0);
            glTranslated(_trans_x, _trans_y, _trans_z);
            glScaled(_zoom, _zoom, _zoom);

            // render your geometry (this is oldest OpenGL rendering technique, later we will use some advanced methods)


            if(arcOrPatch == 0)
            {
                renderArcs();
                renderOtherArcs();
            }
            else
            {
                renderPatches();
                renderOtherPatches();
            }



        // pops the current matrix stack, replacing the current matrix with the one below it on the stack,
        // i.e., the original model view matrix is restored
        glPopMatrix();
    }

    //----------------------------------------------------------------------------
    // when the main window is resized one needs to redefine the projection matrix
    //----------------------------------------------------------------------------
    void GLWidget::resizeGL(int w, int h)
    {
        // setting the new size of the rendering context
        glViewport(0, 0, w, h);

        // redefining the projection matrix
        glMatrixMode(GL_PROJECTION);

        glLoadIdentity();

        _aspect = static_cast<double>(w) / static_cast<double>(h);

        gluPerspective(_fovy, _aspect, _z_near, _z_far);

        // switching back to the model view matrix
        glMatrixMode(GL_MODELVIEW);

        update();
    }

    //-----------------------------------
    // implementation of the public slots
    //-----------------------------------

    void GLWidget::set_angle_x(int value)
    {
        if (_angle_x != value)
        {
            _angle_x = value;
            update();
        }
    }

    void GLWidget::set_angle_y(int value)
    {
        if (_angle_y != value)
        {
            _angle_y = value;
            update();
        }
    }

    void GLWidget::set_angle_z(int value)
    {
        if (_angle_z != value)
        {
            _angle_z = value;
            update();
        }
    }

    void GLWidget::set_zoom_factor(double value)
    {
        if (_zoom != value)
        {
            _zoom = value;
            update();
        }
    }

    void GLWidget::set_trans_x(double value)
    {
        if (_trans_x != value)
        {
            _trans_x = value;
            update();
        }
    }

    void GLWidget::set_trans_y(double value)
    {
        if (_trans_y != value)
        {
            _trans_y = value;
            update();
        }
    }

    void GLWidget::set_trans_z(double value)
    {
        if (_trans_z != value)
        {
            _trans_z = value;
            update();
        }
    }

    //lights
    bool GLWidget::_createDl()
    {
        // creating a white directional light source
        HCoordinate3    direction   (0.0, 0.0, 1.0, 0.0);
        Color4          ambient     (0.4f, 0.4f, 0.4f, 1.0f);
        Color4          diffuse     (0.8f, 0.8f, 0.8f, 1.0f);
        Color4          specular    (1.0, 1.0, 1.0, 1.0);

        _dl = new (nothrow) DirectionalLight(GL_LIGHT0, direction, ambient, diffuse, specular);

        if (!_dl)
        {
            return false;
        }

        return true;
    }

    void GLWidget::_destroyDl()
    {
        if (_dl)
        {
            delete _dl;
            _dl = nullptr;
        }
    }

    bool GLWidget::_createPl()
    {
        // creating a white directional light source
        HCoordinate3    direction   (0.0, 0.0, 1.0, 1.0);
        Color4          ambient     (0.4f, 0.4f, 0.4f, 1.0f);
        Color4          diffuse     (0.8f, 0.8f, 0.8f, 1.0f);
        Color4          specular    (1.0, 1.0, 1.0, 1.0);
        GLfloat         constant_attenuation(1.0);
        GLfloat         linear_attenuation(0.0);
        GLfloat         quadratic_attenuation(0.0);
        HCoordinate3    spot_direction(0.0, 0.0, -1.0);

        _pl = new (nothrow) PointLight(GL_LIGHT1, direction, ambient, diffuse, specular, constant_attenuation, linear_attenuation, quadratic_attenuation);

        if (!_pl)
        {
            return false;
        }

        return true;
    }

    void GLWidget::_destroyPl()
    {
        if (_pl)
        {
            delete _pl;
            _pl = nullptr;
        }
    }

    bool GLWidget::_createSl()
    {
        HCoordinate3    direction   (0.0f, 0.0f, 1.0f, 0.1f);
        Color4          ambient     (0.4f, 0.4f, 0.4f, 1.0f);
        Color4          diffuse     (0.8f, 0.8f, 0.8f, 1.0f);
        Color4          specular    (1.0, 1.0, 1.0, 1.0);
        GLfloat         constant_attenuation(0.1f);
        GLfloat         linear_attenuation(0.1f);
        GLfloat         quadratic_attenuation(0.01f);
        HCoordinate3    spot_direction(0.0f, 0.0f, -1.0f, 1.0f);
        GLfloat         spot_cutoff(4.5f);
        GLfloat         spot_exponent(2.0f);

        _sl = new (nothrow) Spotlight(GL_LIGHT2, direction, ambient, diffuse, specular, constant_attenuation, linear_attenuation, quadratic_attenuation, spot_direction, spot_cutoff, spot_exponent);

        if (!_sl)
        {
            return false;
        }

        return true;
    }

    void GLWidget::_destroySl()
    {
        if (_sl)
        {
            delete _sl;
            _sl = nullptr;
        }
    }

    void GLWidget::enableSelectedLight(){
        switch(selectedLight){
            case 0:
                _dl->Enable();
                return;
            case 1:
                _sl->Enable();
                return;
            case 2:
                _pl->Enable();
                return;
        }
    };

    void GLWidget::disableSelectedLight(){
        switch(selectedLight){
            case 0:
                _dl->Disable();
                return;
            case 1:
                _sl->Disable();
                return;
            case 2:
                _pl->Disable();
                return;
        }
    };



    //materials
    void GLWidget::createMaterials()
    {
        materials.ResizeColumns(7);
        materials[0] = MatFBBrass;
        materials[1] = MatFBGold;
        materials[2] = MatFBSilver;
        materials[3] = MatFBEmerald;
        materials[4] = MatFBPearl;
        materials[5] = MatFBTurquoise;
        materials[6] = MatFBRuby;
    }

    void GLWidget::initSelectedMaterial()
    {
        selectedMaterial.ResizeColumns(numberOfPatches);

        for (int i = 0;  i < numberOfPatches; i++) {
            selectedMaterial[i] = 0;
        }
    }

    //project part
    void GLWidget::setArcOrPatch(int value)
    {
        arcOrPatch = value;
        update();
    }

    void GLWidget::initializeColors()
    {
        colors.ResizeColumns(9);

        colors[0].r() = 0.7f;
        colors[0].g() = 0.73f;
        colors[0].b() = 0.71f;
        colors[0].a() = 1.0f;

        colors[1].r() = 0.74f;
        colors[1].g() = 0.13f;
        colors[1].b() = 0.66f;
        colors[1].a() = 1.0f;

        colors[2].r() = 0.42f;
        colors[2].g() = 0.25f;
        colors[2].b() = 0.5f;
        colors[2].a() = 1.0f;

        colors[3].r() = 0.26f;
        colors[3].g() = 0.52f;
        colors[3].b() = 0.95f;
        colors[3].a() = 1.0f;

        colors[4].r() = 0.1f;
        colors[4].g() = 0.43f;
        colors[4].b() = 0.25f;
        colors[4].a() = 1.0f;

        colors[5].r() = 0.26f;
        colors[5].g() = 0.28f;
        colors[5].b() = 0.33f;
        colors[5].a() = 1.0f;

        colors[6].r() = 0.40f;
        colors[6].g() = 0.95f;
        colors[6].b() = 0.33f;
        colors[6].a() = 1.0f;

        colors[7].r() = 0.92f;
        colors[7].g() = 0.88f;
        colors[7].b() = 0.18f;
        colors[7].a() = 1.0f;

        colors[8].r() = 0.32f;
        colors[8].g() = 0.23f;
        colors[8].b() = 0.01f;
        colors[0].a() = 1.0f;
    }


    //arc part

    //setters
    void GLWidget::setSelectedArc(int value)
    {
        selectedArc = value;
        sendArcPointCoordinates();
        updateArcs();
        update();
    }

    void GLWidget::setSelectedArcPoint(int value)
    {
        selectedArcPoint = value;
        sendArcPointCoordinates();
        updateArcs();
        update();
    }

    void GLWidget::setShowArcDerivatives1(int value)
    {
        showArcDerivative1 = value;
        update();
    }

    void GLWidget::setShowArcDerivatives2(int value)
    {
        showArcDerivative2 = value;
        update();
    }

    void GLWidget::setShowArcControlPolygon(int value)
    {
        showArcControlPolygon = value;
        update();
    }

    void GLWidget::setShowArcDataPoints(int value)
    {
        showArcDataPoints = value;
        update();
    }

    void GLWidget::setScaleArcDerivatives(double value)
    {
        scaleArcDerivatives = value;
        updateArcs();
        update();
    }

    void GLWidget::setArcPointX(double value)
    {
        arcs[selectedArc][selectedArcPoint][0] = value;
        updateCurrentArcImage();
        update();
    }

    void GLWidget::setArcPointY(double value)
    {
        arcs[selectedArc][selectedArcPoint][1] = value;
        updateCurrentArcImage();
        update();
    }

    void GLWidget::setArcPointZ(double value)
    {
        arcs[selectedArc][selectedArcPoint][2] = value;
        updateCurrentArcImage();
        update();
    }

    void GLWidget::setSelectedArcJoinType(int value)
    {
        selectedArcJoinType = value;
        update();
    }
    void GLWidget::setSelectedJoiningArc(int value)
    {
        selectedJoiningArc = value;
        update();
    }

    //the real arc part
    void GLWidget::createArcs()
    {
        //initialize arcVKnotVectors
        ColumnMatrix<GLdouble> arcVKnotVector;
        arcVKnotVector.ResizeRows(4);
        arcVKnotVector(0) = 0.0;
        arcVKnotVector(1) = 1.0 / 3.0;
        arcVKnotVector(2) = 2.0 / 3.0;
        arcVKnotVector(3) = 1.0;


        arcs.ResizeColumns(numberOfArcs);
        arcImages.ResizeColumns(numberOfArcs);
        GLdouble offsetX = 3;
        GLdouble offsetY = -2;
        for(int i = 0; i < numberOfArcs; i++)
        {
            GLdouble offsetXNow = offsetX * (i % 3);
            GLdouble offsetYNow = offsetY * (i / 3);
            ColumnMatrix<DCoordinate3> points_to_interpolate(4);
            points_to_interpolate[0] = DCoordinate3(-3 + offsetXNow, 1 + offsetYNow, 0);
            points_to_interpolate[1] = DCoordinate3(-2.833 + offsetXNow, 1.33 + offsetYNow, 0);
            points_to_interpolate[2] = DCoordinate3(-2.66 + offsetXNow, 1.33 + offsetYNow, 0);
            points_to_interpolate[3] = DCoordinate3(-2.5 + offsetXNow, 1.33 + offsetYNow, 0);

            if (arcs[i].UpdateDataForInterpolation(arcVKnotVector, points_to_interpolate))
            {
                arcImages[i] = arcs[i].GenerateImage(2, 100, GL_STATIC_DRAW);
                arcs[i].UpdateVertexBufferObjectsOfData();

                if (arcImages[i])
                    arcImages[i]->UpdateVertexBufferObjects(scaleArcDerivatives);
            }
        }
    }

    void GLWidget::updateArcs(){
        for(int i = 0; i < numberOfArcs; i++)
        {
            arcImages[i]->UpdateVertexBufferObjects(scaleArcDerivatives);
        }
    }

    bool GLWidget::updateCurrentArcImage()
    {

        if (!arcs[selectedArc].UpdateVertexBufferObjectsOfData())
        {
            return false;
        }

        // generating image
        if (arcImages[selectedArc])
        {
            delete arcImages[selectedArc];
        }


        arcImages[selectedArc] = arcs[selectedArc].GenerateImage(2, 100, GL_STATIC_DRAW);

        if (!arcImages[selectedArc] || !arcImages[selectedArc]->UpdateVertexBufferObjects())
        {
            return false;
        }
        return true;
    }

    bool GLWidget::updateSelectedJoiningArcImage()
    {

        if (!arcs[selectedJoiningArc].UpdateVertexBufferObjectsOfData())
        {
            return false;
        }

        // generating image
        if (arcImages[selectedJoiningArc])
        {
            delete arcImages[selectedJoiningArc];
        }


        arcImages[selectedJoiningArc] = arcs[selectedJoiningArc].GenerateImage(2, 100, GL_STATIC_DRAW);

        if (!arcImages[selectedJoiningArc] || !arcImages[selectedJoiningArc]->UpdateVertexBufferObjects())
        {
            return false;
        }
        return true;
    }

    void GLWidget::renderArcs()
    {
        glPushMatrix();

        DCoordinate3 sp = arcs[selectedArc][selectedArcPoint];
        glPointSize(10.0f);
        glColor3f(1.0f, 0.0f, 0.0f);
        glBegin (GL_POINTS);
        glVertex3f(sp[0], sp[1], sp[2]);
        glEnd ();
        glFlush();

        for(int i = 0; i < numberOfArcs; i++)
        {

            glDisable(GL_LIGHTING);

            if (showArcControlPolygon)
            {
                glColor3f(1.0f, 0.0f, 0.0f);
                arcs[i].RenderData(GL_LINE_STRIP);
            }

            if (showArcDataPoints)
            {
                glPointSize(10.0);
                arcs[i].RenderData(GL_POINTS);
            }

            glColor3f(colors[i][0], colors[i][1], colors[i][2]);
            arcImages[i]->RenderDerivatives(0, GL_LINE_STRIP);

            if (showArcDerivative1)
            {
                glColor3f(0.0f, 0.5f, 0.0f);
                arcImages[i]->RenderDerivatives(1, GL_LINES);
            }

            if (showArcDerivative2)
            {
                glColor3f(0.0f, 0.0f, 0.5f);
                arcImages[i]->RenderDerivatives(2, GL_LINES);
            }
        }


        glPopMatrix();
    }

    void GLWidget::renderOtherArcs(){
        glPushMatrix();
        for(int i = 0; i < otherArcs.size(); i++)
        {

            glDisable(GL_LIGHTING);

            if (showArcControlPolygon)
            {
                glColor3f(1.0f, 0.0f, 0.0f);
                otherArcs[i].RenderData(GL_LINE_STRIP);
            }

            if (showArcDataPoints)
            {
                glPointSize(10.0);
                otherArcs[i].RenderData(GL_POINTS);
            }

            glColor3f(1.0f, 0.0f, 0.0f);
            otherArcImages[i]->RenderDerivatives(0, GL_LINE_STRIP);

            if (showArcDerivative1)
            {
                glColor3f(0.0f, 0.5f, 0.0f);
                otherArcImages[i]->RenderDerivatives(1, GL_LINES);
            }

            if (showArcDerivative2)
            {
                glColor3f(0.0f, 0.0f, 0.5f);
                otherArcImages[i]->RenderDerivatives(2, GL_LINES);
            }
        }


        glPopMatrix();
    }

    void GLWidget::extendArcLeft(){
        SecondOrderHyperbolicArc* a = arcs[selectedArc].extendLeft();
        otherArcs.push_back(*a);
        GenericCurve3* i = a->GenerateImage(2, 100, GL_STATIC_DRAW);
        i->UpdateVertexBufferObjects();
        otherArcImages.push_back(i);
        update();
    }

    void GLWidget::extendArcRight(){
        SecondOrderHyperbolicArc* a = arcs[selectedArc].extendRight();
        otherArcs.push_back(*a);
        GenericCurve3* i = a->GenerateImage(2, 100, GL_STATIC_DRAW);
        i->UpdateVertexBufferObjects();
        otherArcImages.push_back(i);
        update();
    }

    void GLWidget::mergeArcs(){
        switch(selectedArcJoinType){
            case 0:
                arcs[selectedArc].mergeRightRight(&arcs[selectedJoiningArc]);
                break;
            case 1:
                arcs[selectedArc].mergeLeftLeft(&arcs[selectedJoiningArc]);
                break;
            case 2:
                arcs[selectedArc].mergeRightLeft(&arcs[selectedJoiningArc]);
                break;
            case 3:
                arcs[selectedArc].mergeLeftRight(&arcs[selectedJoiningArc]);
                break;
        }

        updateCurrentArcImage();
        updateSelectedJoiningArcImage();
        update();
    }

    void GLWidget::joinArcs(){
        SecondOrderHyperbolicArc* a = nullptr;
        switch(selectedArcJoinType){
            case 0:
                a = arcs[selectedArc].joinRightRight(&arcs[selectedJoiningArc]);
                break;
            case 1:
                a = arcs[selectedArc].joinLeftLeft(&arcs[selectedJoiningArc]);
                break;
            case 2:
                a = arcs[selectedArc].joinRightLeft(&arcs[selectedJoiningArc]);
                break;
            case 3:
                a = arcs[selectedArc].joinLeftRight(&arcs[selectedJoiningArc]);
                break;
        }
        otherArcs.push_back(*a);
        GenericCurve3* i = a->GenerateImage(2, 100, GL_STATIC_DRAW);
        i->UpdateVertexBufferObjects();
        otherArcImages.push_back(i);
        update();

    }

    void GLWidget::sendArcPointCoordinates()
    {
        DCoordinate3 sp = arcs[selectedArc][selectedArcPoint];
        emit sendArcPointX(sp[0]);
        emit sendArcPointY(sp[1]);
        emit sendArcPointZ(sp[2]);
    }



    //patches stuff
    //setters
    void GLWidget::setSelectedPatch(int value)
    {
        selectedPatch = value;
        sendPatchPointCoordinates();
        update();
    }

    void GLWidget::setSelectedPatchPoint(int value)
    {
        selectedPatchPoint = value;
        sendPatchPointCoordinates();
        update();
    }

    void GLWidget::setShowPatchControlPolygon(int value)
    {
        showPatchControlPolygon = value;
        update();
    }

    void GLWidget::setShowPatchDataPoints(int value)
    {
        showPatchDataPoints = value;
        update();
    }

    void GLWidget::setShowInterpolatingSurface(int value)
    {
        showInterpolatingSurface = value;
        update();
    }

    void GLWidget::setShowNormalVectors(int value)
    {
        // TODO: find out what are normal vectors
        update();
    }

    void GLWidget::setSelectedMaterialOfSelectedPatch(int value)
    {
        selectedMaterial[selectedPatch] = value;
        update();
    }

    void GLWidget::setSelectedLight(int value)
    {
        selectedLight = value;
        update();
    }

    void GLWidget::setTurnOnSelectedLight(int value)
    {
        turnOnLight = value;
        update();
    }

    void GLWidget::setshowUIsometricCurves(int value)
    {
        showUIsometricCurves = value;
        update();
    }

    void GLWidget::setshowVIsometricCurves(int value)
    {
        showVIsometricCurves = value;
        update();
    }

    void GLWidget::setshowIsometricCurvesDerivatives(int value)
    {
        showIsometricDerivatives = value;
        update();
    }

    void GLWidget::setshowPatchDerivatives(int value)
    {
        showPatchDerivatives = value;
        //TODO: find out what are patch derivatives
        update();
    }

    void GLWidget::setshowPatchPartialDerivatives(int value)
    {
        showPatchPartialDerivatives = value;
        //TO DO find out what are patch partial derivatives
        update();
    }

    void GLWidget::setPatchPointX(double value)
    {
        _data_points_to_interpolate[selectedPatch](selectedPatchPoint / 4, selectedPatchPoint % 4)[0] = value;
        updateCurrentPatchImage();
        update();
    }

    void GLWidget::setPatchPointY(double value)
    {
        _data_points_to_interpolate[selectedPatch](selectedPatchPoint / 4, selectedPatchPoint % 4)[1] = value;
        updateCurrentPatchImage();
        update();
    }

    void GLWidget::setPatchPointZ(double value)
    {
        _data_points_to_interpolate[selectedPatch](selectedPatchPoint / 4, selectedPatchPoint % 4)[2] = value;
        updateCurrentPatchImage();
        update();
    }

    void GLWidget::setSelectedPatchJoinType(int value)
    {
        selectedPatchJoinType = value;
        update();
    }
    void GLWidget::setSelectedJoiningPatch(int value)
    {
        selectedJoiningPatch = value;
        update();
    }

    //other
    void GLWidget::createPatches()
    {
        _data_points_to_interpolate.ResizeColumns(numberOfPatches);
        for(int i = 0; i < numberOfPatches; i++)
        {
            _data_points_to_interpolate[i].ResizeColumns(4);
            _data_points_to_interpolate[i].ResizeRows(4);
        }

        patches.ResizeColumns(numberOfPatches);
        beforeInterpolation.ResizeColumns(numberOfPatches);

        afterInterpolation.ResizeColumns(numberOfPatches);
        uKnotVectors.ResizeColumns(numberOfPatches);
        vKnotVectors.ResizeColumns(numberOfPatches);
        uCurves.ResizeColumns(numberOfPatches);
        vCurves.ResizeColumns(numberOfPatches);

        GLdouble offsetX = 3;
        GLdouble offsetY = -2;
        for(int i = 0; i < numberOfPatches; i++)
        {
            GLdouble offsetXNow = offsetX * (i % 3) - 3;
            GLdouble offsetYNow = offsetY * (i / 3) + 2;

            patches[i] = new SecHypPatch3();
            patches[i]->SetData(0, 0, -0.33 + offsetXNow, -0.33 + offsetYNow, 0.0);
            patches[i]->SetData(0, 1, -0.33 + offsetXNow, -0.166 + offsetYNow, 0.0);
            patches[i]->SetData(0, 2, -0.33 + offsetXNow, 0.166 + offsetYNow, 0.0);
            patches[i]->SetData(0, 3, -0.33 + offsetXNow, 0.33 + offsetYNow, 0.0);

            patches[i]->SetData(1, 0, -0.166 + offsetXNow, -0.33 + offsetYNow, 0.0);
            patches[i]->SetData(1, 1, -0.166 + offsetXNow, -0.166 + offsetYNow, 0.33);
            patches[i]->SetData(1, 2, -0.166 + offsetXNow, 0.166 + offsetYNow, 0.33);
            patches[i]->SetData(1, 3, -0.166 + offsetXNow, 0.33 + offsetYNow, 0.0);

            patches[i]->SetData(2, 0, 0.166 + offsetXNow, -0.33 + offsetYNow, 0.0);
            patches[i]->SetData(2, 1, 0.166 + offsetXNow, -0.166 + offsetYNow, 0.33);
            patches[i]->SetData(2, 2, 0.166 + offsetXNow, 0.166 + offsetYNow, 0.33);
            patches[i]->SetData(2, 3, 0.166 + offsetXNow, 0.33 + offsetYNow, 0.0);

            patches[i]->SetData(3, 0, 0.33 + offsetXNow, -0.33 + offsetYNow, 0.0);
            patches[i]->SetData(3, 1, 0.33 + offsetXNow, -0.166 + offsetYNow, 0.0);
            patches[i]->SetData(3, 2, 0.33 + offsetXNow, 0.166 + offsetYNow, 0.0);
            patches[i]->SetData(3, 3, 0.33 + offsetXNow, 0.33 + offsetYNow, 0.0);

            patches[i]->UpdateVertexBufferObjectsOfData();


            beforeInterpolation[i] = patches[i]->GenerateImage(30, 30, GL_STATIC_DRAW);
            if(beforeInterpolation[i])
            {
                beforeInterpolation[i]->UpdateVertexBufferObjects();
            }

            uKnotVectors[i].ResizeColumns(4);
            uKnotVectors[i](0) = 0.0;
            uKnotVectors[i](1) = PI / 6.0;
            uKnotVectors[i](2) = PI / 3.0;
            uKnotVectors[i](3) = PI / 2.0;

            vKnotVectors[i].ResizeRows(4);
            vKnotVectors[i](0) = 0.0;
            vKnotVectors[i](1) = 1.0 / 3.0;
            vKnotVectors[i](2) = 2.0 / 3.0;
            vKnotVectors[i](3) = 1.0;

            for (GLuint row = 0; row < 4; ++row)
                for (GLuint column = 0; column < 4; ++column)
                    patches[i]->GetData(row, column, _data_points_to_interpolate[i](row, column));

            if (patches[i]->UpdateDataForInterpolation(uKnotVectors[i], vKnotVectors[i], _data_points_to_interpolate[i]))
            {
                afterInterpolation[i] = patches[i]->GenerateImage(30, 30, GL_STATIC_DRAW);

                if(afterInterpolation[i])
                    afterInterpolation[i]->UpdateVertexBufferObjects();
            }

            uCurves[i] = patches[i]->GenerateUIsoparametricLines(4, 2, 200, GL_STATIC_DRAW);
            vCurves[i] = patches[i]->GenerateVIsoparametricLines(4, 2, 200, GL_STATIC_DRAW);


            for(GLuint  j = 0; j < uCurves[i]->GetColumnCount(); ++j)
                (*uCurves[i])[j]->UpdateVertexBufferObjects(scalePatchDerivatives, GL_STATIC_DRAW);

            for(GLuint  j = 0; j < vCurves[i]->GetColumnCount(); ++j)
                (*vCurves[i])[j]->UpdateVertexBufferObjects(scalePatchDerivatives, GL_STATIC_DRAW);
        }
    }

    void GLWidget::updateCurrentPatchImage()
    {
        for (int i = 0; i < 4; i++){
            for (int j = 0; j < 4; j++){
                patches[selectedPatch]->SetData(i,j,_data_points_to_interpolate[selectedPatch](i,j));
            }
        }

        patches[selectedPatch]->UpdateVertexBufferObjectsOfData();

        beforeInterpolation[selectedPatch] = patches[selectedPatch]->GenerateImage(30, 30, GL_STATIC_DRAW);
        if(beforeInterpolation[selectedPatch])
        {
            beforeInterpolation[selectedPatch]->UpdateVertexBufferObjects();
        }

        if (patches[selectedPatch]->UpdateDataForInterpolation(uKnotVectors[selectedPatch], vKnotVectors[selectedPatch], _data_points_to_interpolate[selectedPatch]))
        {
            afterInterpolation[selectedPatch] = patches[selectedPatch]->GenerateImage(30, 30, GL_STATIC_DRAW);

            if(afterInterpolation[selectedPatch])
                afterInterpolation[selectedPatch]->UpdateVertexBufferObjects();
        }

        uCurves[selectedPatch] = patches[selectedPatch]->GenerateUIsoparametricLines(4, 2, 200, GL_STATIC_DRAW);
        vCurves[selectedPatch] = patches[selectedPatch]->GenerateVIsoparametricLines(4, 2, 200, GL_STATIC_DRAW);


        for(GLuint  j = 0; j < uCurves[selectedPatch]->GetColumnCount(); ++j)
            (*uCurves[selectedPatch])[j]->UpdateVertexBufferObjects(scalePatchDerivatives, GL_STATIC_DRAW);

        for(GLuint  j = 0; j < vCurves[selectedPatch]->GetColumnCount(); ++j)
            (*vCurves[selectedPatch])[j]->UpdateVertexBufferObjects(scalePatchDerivatives, GL_STATIC_DRAW);
    }

    void GLWidget::renderPatches()
    {
        glPushMatrix();
            DCoordinate3 sp = _data_points_to_interpolate[selectedPatch](selectedPatchPoint / 4, selectedPatchPoint % 4);
            glPointSize(10.0f);
            glColor3f(0.0f, 0.5f, 0.0f);
            glBegin (GL_POINTS);
            glVertex3f(sp[0], sp[1], sp[2]);
            glEnd ();
            glFlush();

            for(int i = 0; i < numberOfPatches; i++)
            {
                glDisable(GL_LIGHTING);

                if (showPatchControlPolygon)
                {
                    glColor3f(1.0f, 0.0f, 0.0f);
                    patches[i]->RenderData();
                }

                if (showPatchDataPoints)
                {
                    glColor4f(0.5f, 1.0f, 0.5f, 0.4f);
                    glPointSize(10.0);
                    patches[i]->RenderData(GL_POINTS);
                }

                glPointSize(5.0f);
                for(GLuint j = 0; j < 4; ++j){
                    if(showUIsometricCurves)
                    {
                        glColor4f(0.0f, 0.2f, 0.8f, 0.6f);
                        (*uCurves[i])[j]->RenderDerivatives(0, GL_LINE_STRIP);
                    }

                    if(showIsometricDerivatives)
                    {
                        glColor3f(0.0f, 0.5f, 0.0f);
                        (*uCurves[i])[j]->RenderDerivatives(1, GL_LINES);
                        glColor3f(0.0f, 0.0f, 0.5f);
                        (*uCurves[i])[j]->RenderDerivatives(2, GL_LINES);
                    }
                }


                for(GLuint j = 0; j < 4; ++j){
                    if(showVIsometricCurves)
                    {
                        glColor4f(0.0f, 0.2f, 0.8f, 0.6f);
                        (*vCurves[i])[j]->RenderDerivatives(0, GL_LINE_STRIP);
                    }

                    if(showIsometricDerivatives)
                    {
                        glColor3f(0.0f, 0.5f, 0.0f);
                        (*vCurves[i])[j]->RenderDerivatives(1, GL_LINES);
                        glColor3f(0.0f, 0.0f, 0.5f);
                        (*vCurves[i])[j]->RenderDerivatives(2, GL_LINES);
                    }
                }

                if(turnOnLight)
                {

                    glEnable(GL_LIGHTING);
                    enableSelectedLight();
                }

                glPointSize(1.0);
                glColor3f(colors[i][0], colors[i][1], colors[i][2]);
                if(beforeInterpolation[i])
                {
                    materials[selectedMaterial[i]].Apply();
                    beforeInterpolation[i]->Render();
                }

                glColor3f(0.0f, 1.0f, 0.0f);
                if(afterInterpolation[i] && showInterpolatingSurface)
                {

                    glEnable(GL_LIGHTING);
                    enableSelectedLight();
                    glEnable(GL_BLEND);
                    glDepthMask(GL_FALSE);
                    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
                        MatFBEmerald.Apply();
                        afterInterpolation[i]->Render();
                    glDepthMask(GL_TRUE);
                    glDisable(GL_BLEND);
                    disableSelectedLight();
                    glDisable(GL_LIGHTING);
                }

                if (turnOnLight)
                {
                    disableSelectedLight();
                    glDisable(GL_LIGHTING);
                }
            }
        glPopMatrix();
    }

    void GLWidget::renderOtherPatches()
    {
        glPushMatrix();

            for(int i = 0; i < otherPatches.size(); i++)
            {
                glDisable(GL_LIGHTING);

                if (showPatchControlPolygon)
                {
                    glColor3f(1.0f, 0.0f, 0.0f);
                    patches[i]->RenderData();
                }

                if (showPatchDataPoints)
                {
                    glColor4f(0.5f, 1.0f, 0.5f, 0.4f);
                    glPointSize(10.0);
                    patches[i]->RenderData(GL_POINTS);
                }

                glPointSize(5.0f);
                for(GLuint j = 0; j < 4; ++j){
                    if(showUIsometricCurves)
                    {
                        glColor4f(0.0f, 0.2f, 0.8f, 0.6f);
                        (*uCurves[i])[j]->RenderDerivatives(0, GL_LINE_STRIP);
                    }

                    if(showIsometricDerivatives)
                    {
                        glColor3f(0.0f, 0.5f, 0.0f);
                        (*uCurves[i])[j]->RenderDerivatives(1, GL_LINES);
                    }
                }


                for(GLuint j = 0; j < 4; ++j){
                    if(showVIsometricCurves)
                    {
                        glColor4f(0.0f, 0.2f, 0.8f, 0.6f);
                        (*vCurves[i])[j]->RenderDerivatives(0, GL_LINE_STRIP);
                    }

                    if(showIsometricDerivatives)
                    {
                        glColor3f(0.0f, 0.5f, 0.0f);
                        (*vCurves[i])[j]->RenderDerivatives(1, GL_LINES);
                    }
                }

                if(turnOnLight)
                {

                    glEnable(GL_LIGHTING);
                    enableSelectedLight();
                }

                glPointSize(1.0);
                glColor3f(1.0f, 0.0f, 0.0f);
//                if(beforeInterpolation[i])
//                {
//
//                    beforeInterpolation[i]->Render();
//                }
                MatFBBrass.Apply();
                otherPatches[i].GetImage()->Render();

//                glColor3f(0.0f, 1.0f, 0.0f);
//                if(afterInterpolation[i] && showInterpolatingSurface)
//                {
//                    glEnable(GL_BLEND);
//                    glDepthMask(GL_FALSE);
//                    glBlendFunc(GL_SRC_ALPHA, GL_ONE);
//                        MatFBEmerald.Apply();
//                        afterInterpolation[i]->Render();
//                    glDepthMask(GL_TRUE);
//                    glDisable(GL_BLEND);
//                }

                if (turnOnLight)
                {
                    disableSelectedLight();
                    glDisable(GL_LIGHTING);
                }
            }
        glPopMatrix();
    }

    void GLWidget::sendPatchPointCoordinates()
    {
        DCoordinate3 sp = _data_points_to_interpolate[selectedPatch](selectedPatchPoint / 4, selectedPatchPoint % 4);
        emit sendPatchPointX(sp[0]);
        emit sendPatchPointY(sp[1]);
        emit sendPatchPointZ(sp[2]);
    }


    //extends
    void GLWidget::extendPatchWest(){
        SecHypPatch3 p;
        patches[selectedPatch]->ExtendWest(p);
        p.SetImage(p.GenerateImage(30, 30, GL_STATIC_DRAW));
        otherPatches.push_back(p);
        update();
    };

    void GLWidget::extendPatchEast(){
        SecHypPatch3 p;
        patches[selectedPatch]->ExtendEast(p);
        p.SetImage(p.GenerateImage(30, 30, GL_STATIC_DRAW));
        otherPatches.push_back(p);
        update();
    };

    void GLWidget::extendPatchNorth(){
        SecHypPatch3 p;
        patches[selectedPatch]->ExtendNorth(p);
        p.SetImage(p.GenerateImage(30, 30, GL_STATIC_DRAW));
        otherPatches.push_back(p);
        update();
    };

    void GLWidget::extendPatchSouth(){
        SecHypPatch3 p;
        patches[selectedPatch]->ExtendSouth(p);
        p.SetImage(p.GenerateImage(30, 30, GL_STATIC_DRAW));
        otherPatches.push_back(p);
        update();
    };

    void GLWidget::mergePatches(){
        if(selectedPatch == selectedJoiningPatch) return;
        switch(selectedPatchJoinType){
            case 0:
                patches[selectedPatch]->MergeNorthEast(*patches[selectedJoiningPatch]);
                break;
            case 1:
                patches[selectedPatch]->MergeWestWest(*patches[selectedJoiningPatch]);
                break;
            case 2:
                patches[selectedPatch]->MergeSouthSouth(*patches[selectedJoiningPatch]);
                break;
        }

        beforeInterpolation[selectedPatch] = patches[selectedPatch]->GenerateImage(30, 30, GL_STATIC_DRAW);
        beforeInterpolation[selectedPatch]->UpdateVertexBufferObjects();
        beforeInterpolation[selectedJoiningPatch] = patches[selectedJoiningPatch]->GenerateImage(30, 30, GL_STATIC_DRAW);
        beforeInterpolation[selectedJoiningPatch]->UpdateVertexBufferObjects();
        //TODO: afterInterpolation

        update();
    };

    void GLWidget::joinPatches(){
        SecHypPatch3 p;
        switch(selectedPatchJoinType){
            case 0:
                patches[selectedPatch]->JoinNorthEast(*patches[selectedJoiningPatch], p);
                break;
            case 1:
                patches[selectedPatch]->JoinWestWest(*patches[selectedJoiningPatch], p);
                break;
            case 2:
                patches[selectedPatch]->JoinSouthSouth(*patches[selectedJoiningPatch], p);
                break;
        }
        p.SetImage(p.GenerateImage(30, 30, GL_STATIC_DRAW));
        otherPatches.push_back(p);
        update();
    };

}
