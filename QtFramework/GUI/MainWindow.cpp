#include "MainWindow.h"

namespace cagd
{
    MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
    {
        setupUi(this);

    /*

      the structure of the main window's central widget

     *---------------------------------------------------*
     |                 central widget                    |
     |                                                   |
     |  *---------------------------*-----------------*  |
     |  |     rendering context     |   scroll area   |  |
     |  |       OpenGL widget       | *-------------* |  |
     |  |                           | | side widget | |  |
     |  |                           | |             | |  |
     |  |                           | |             | |  |
     |  |                           | *-------------* |  |
     |  *---------------------------*-----------------*  |
     |                                                   |
     *---------------------------------------------------*

    */
        _side_widget = new SideWidget(this);

        _scroll_area = new QScrollArea(this);
        _scroll_area->setWidget(_side_widget);
        _scroll_area->setSizePolicy(_side_widget->sizePolicy());
        _scroll_area->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

        _gl_widget = new GLWidget(this);

        centralWidget()->setLayout(new QHBoxLayout());
        centralWidget()->layout()->addWidget(_gl_widget);
        centralWidget()->layout()->addWidget(_scroll_area);

        // creating a signal slot mechanism between the rendering context and the side widget
        connect(_side_widget->rotate_x_slider, SIGNAL(valueChanged(int)), _gl_widget, SLOT(set_angle_x(int)));
        connect(_side_widget->rotate_y_slider, SIGNAL(valueChanged(int)), _gl_widget, SLOT(set_angle_y(int)));
        connect(_side_widget->rotate_z_slider, SIGNAL(valueChanged(int)), _gl_widget, SLOT(set_angle_z(int)));

        connect(_side_widget->zoom_factor_spin_box, SIGNAL(valueChanged(double)), _gl_widget, SLOT(set_zoom_factor(double)));

        connect(_side_widget->trans_x_spin_box, SIGNAL(valueChanged(double)), _gl_widget, SLOT(set_trans_x(double)));
        connect(_side_widget->trans_y_spin_box, SIGNAL(valueChanged(double)), _gl_widget, SLOT(set_trans_y(double)));
        connect(_side_widget->trans_z_spin_box, SIGNAL(valueChanged(double)), _gl_widget, SLOT(set_trans_z(double)));

        //project stuff
        connect(_side_widget->toolBox, SIGNAL(currentChanged(int)), _gl_widget, SLOT(setArcOrPatch(int)));

        //arc stuff
        //sidewidget to GLwidget
        connect(_side_widget->checkBoxShowArcDerivatives1, SIGNAL(stateChanged(int)), _gl_widget, SLOT(setShowArcDerivatives1(int)));
        connect(_side_widget->checkBoxShowArcDerivatives2, SIGNAL(stateChanged(int)), _gl_widget, SLOT(setShowArcDerivatives2(int)));
        connect(_side_widget->checkBoxShowArcControlPolygon, SIGNAL(stateChanged(int)), _gl_widget, SLOT(setShowArcControlPolygon(int)));
        connect(_side_widget->checkBoxShowArcDataPoints, SIGNAL(stateChanged(int)), _gl_widget, SLOT(setShowArcDataPoints(int)));
        connect(_side_widget->comboBoxSelectedArc, SIGNAL(currentIndexChanged(int)), _gl_widget, SLOT(setSelectedArc(int)));
        connect(_side_widget->comboBoxSelectedArcPoint, SIGNAL(currentIndexChanged(int)), _gl_widget, SLOT(setSelectedArcPoint(int)));
        connect(_side_widget->doubleSpinBoxScaleArcDerivatives, SIGNAL(valueChanged(double)), _gl_widget, SLOT(setScaleArcDerivatives(double)));
        connect(_side_widget->comboBoxSelectedArcJoinType, SIGNAL(currentIndexChanged(int)), _gl_widget, SLOT(setSelectedArcJoinType(int)));

        connect(_side_widget->doubleSpinBoxArcX, SIGNAL(valueChanged(double)), _gl_widget, SLOT(setArcPointX(double)));
        connect(_side_widget->doubleSpinBoxArcY, SIGNAL(valueChanged(double)), _gl_widget, SLOT(setArcPointY(double)));
        connect(_side_widget->doubleSpinBoxArcZ, SIGNAL(valueChanged(double)), _gl_widget, SLOT(setArcPointZ(double)));

        //arc extend, merge, join
        connect(_side_widget->pushButtonExtendLeftArc, SIGNAL(clicked()), _gl_widget, SLOT(extendArcLeft()));
        connect(_side_widget->pushButtonExtendRightArc, SIGNAL(clicked()), _gl_widget, SLOT(extendArcRight()));
        connect(_side_widget->pushButtonMergeArcs, SIGNAL(clicked()), _gl_widget, SLOT(mergeArcs()));
        connect(_side_widget->pushButtonJoinArcs, SIGNAL(clicked()), _gl_widget, SLOT(joinArcs()));

        //GLwidget to mainWindow
        connect(_gl_widget, SIGNAL(sendArcPointX(double)), this, SLOT(setArcPointX(double)));
        connect(_gl_widget, SIGNAL(sendArcPointY(double)), this, SLOT(setArcPointY(double)));
        connect(_gl_widget, SIGNAL(sendArcPointZ(double)), this, SLOT(setArcPointZ(double)));



        //patches stuff
        connect(_side_widget->checkBoxShowPatchControlPolygon, SIGNAL(stateChanged(int)), _gl_widget, SLOT(setShowPatchControlPolygon(int)));
        connect(_side_widget->checkBoxShowPatchDataPoints, SIGNAL(stateChanged(int)), _gl_widget, SLOT(setShowPatchDataPoints(int)));
        connect(_side_widget->checkBoxShowInterpolatingSurface, SIGNAL(stateChanged(int)), _gl_widget, SLOT(setShowInterpolatingSurface(int)));
        connect(_side_widget->checkBoxShowNormalVectors, SIGNAL(stateChanged(int)), _gl_widget, SLOT(setShowNormalVectors(int)));
        connect(_side_widget->checkBoxShowIsoparametricCurvesU, SIGNAL(stateChanged(int)), _gl_widget, SLOT(setshowUIsometricCurves(int)));
        connect(_side_widget->checkBoxShowIsoparametricCurvesV, SIGNAL(stateChanged(int)), _gl_widget, SLOT(setshowVIsometricCurves(int)));
        connect(_side_widget->checkBoxShowIsometricDerivatives, SIGNAL(stateChanged(int)), _gl_widget, SLOT(setshowIsometricCurvesDerivatives(int)));
        connect(_side_widget->checkBoxShowPatchDerivatives, SIGNAL(stateChanged(int)), _gl_widget, SLOT(setshowPatchDerivatives(int)));
        connect(_side_widget->checkBoxShowPatchPartialDerivatives, SIGNAL(stateChanged(int)), _gl_widget, SLOT(setshowPatchPartialDerivatives(int)));
        connect(_side_widget->checkBoxApplyLight, SIGNAL(stateChanged(int)), _gl_widget, SLOT(setTurnOnSelectedLight(int)));
        connect(_side_widget->comboBoxSelectedArcJoinType, SIGNAL(currentIndexChanged(int)), _gl_widget, SLOT(setSelectedArcJoinType(int)));
        connect(_side_widget->comboBoxSelectedJoiningArc, SIGNAL(currentIndexChanged(int)), _gl_widget, SLOT(setSelectedJoiningArc(int)));

        connect(_side_widget->comboBoxSelectedPatch, SIGNAL(currentIndexChanged(int)), _gl_widget, SLOT(setSelectedPatch(int)));
        connect(_side_widget->comboBoxSelectedPatchPoint, SIGNAL(currentIndexChanged(int)), _gl_widget, SLOT(setSelectedPatchPoint(int)));
        connect(_side_widget->comboBoxMaterial, SIGNAL(currentIndexChanged(int)), _gl_widget, SLOT(setSelectedMaterialOfSelectedPatch(int)));
        connect(_side_widget->comboBoxLight, SIGNAL(currentIndexChanged(int)), _gl_widget, SLOT(setSelectedLight(int)));
        connect(_side_widget->comboBoxSelectedPatchJoinType, SIGNAL(currentIndexChanged(int)), _gl_widget, SLOT(setSelectedPatchJoinType(int)));
        connect(_side_widget->comboBoxSelectedJoiningPatch, SIGNAL(currentIndexChanged(int)), _gl_widget, SLOT(setSelectedJoiningPatch(int)));

        connect(_side_widget->doubleSpinBoxPatchX, SIGNAL(valueChanged(double)), _gl_widget, SLOT(setPatchPointX(double)));
        connect(_side_widget->doubleSpinBoxPatchY, SIGNAL(valueChanged(double)), _gl_widget, SLOT(setPatchPointY(double)));
        connect(_side_widget->doubleSpinBoxPatchZ, SIGNAL(valueChanged(double)), _gl_widget, SLOT(setPatchPointZ(double)));

        //GLwidget to mainWindow
        connect(_gl_widget, SIGNAL(sendPatchPointX(double)), this, SLOT(setPatchPointX(double)));
        connect(_gl_widget, SIGNAL(sendPatchPointY(double)), this, SLOT(setPatchPointY(double)));
        connect(_gl_widget, SIGNAL(sendPatchPointZ(double)), this, SLOT(setPatchPointZ(double)));

        //extend
        connect(_side_widget->pushButtonExtendWest, SIGNAL(clicked()), _gl_widget, SLOT(extendPatchWest()));
        connect(_side_widget->pushButtonExtendEast, SIGNAL(clicked()), _gl_widget, SLOT(extendPatchEast()));
        connect(_side_widget->pushButtonExtendNorth, SIGNAL(clicked()), _gl_widget, SLOT(extendPatchNorth()));
        connect(_side_widget->pushButtonExtendSouth, SIGNAL(clicked()), _gl_widget, SLOT(extendPatchSouth()));

        //join
        connect(_side_widget->pushButtonJoinPatches, SIGNAL(clicked()), _gl_widget, SLOT(joinPatches()));
        connect(_side_widget->pushButtonMergePatches, SIGNAL(clicked()), _gl_widget, SLOT(mergePatches()));
    }

    //--------------------------------
    // implementation of private slots
    //--------------------------------
    void MainWindow::on_action_Quit_triggered()
    {
        qApp->exit(0);
    }

    void MainWindow::setArcPointX(double value){
        _side_widget->doubleSpinBoxArcX->setValue(value);
    }

    void MainWindow::setArcPointY(double value){
        _side_widget->doubleSpinBoxArcY->setValue(value);
    }

    void MainWindow::setArcPointZ(double value){
        _side_widget->doubleSpinBoxArcZ->setValue(value);
    }

    void MainWindow::setPatchPointX(double value){
        _side_widget->doubleSpinBoxPatchX->setValue(value);
    }

    void MainWindow::setPatchPointY(double value){
        _side_widget->doubleSpinBoxPatchY->setValue(value);
    }

    void MainWindow::setPatchPointZ(double value){
        _side_widget->doubleSpinBoxPatchZ->setValue(value);
    }
}
