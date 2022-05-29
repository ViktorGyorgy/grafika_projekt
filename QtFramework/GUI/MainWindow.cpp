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
        connect(_side_widget->comboBoxSelectedArc, SIGNAL(currentIndexChanged(int)), _gl_widget, SLOT(setSelectedArc(int)));
        connect(_side_widget->comboBoxSelectedArcPoint, SIGNAL(currentIndexChanged(int)), _gl_widget, SLOT(setSelectedArcPoint(int)));
        connect(_side_widget->doubleSpinBoxScaleArcDerivatives, SIGNAL(valueChanged(double)), _gl_widget, SLOT(setScaleArcDerivatives(double)));

        connect(_side_widget->doubleSpinBoxArcX, SIGNAL(valueChanged(double)), _gl_widget, SLOT(setArcPointX(double)));
        connect(_side_widget->doubleSpinBoxArcY, SIGNAL(valueChanged(double)), _gl_widget, SLOT(setArcPointY(double)));
        connect(_side_widget->doubleSpinBoxArcZ, SIGNAL(valueChanged(double)), _gl_widget, SLOT(setArcPointZ(double)));

        //GLwidget to mainWindow
        connect(_gl_widget, SIGNAL(sendArcPointX(double)), this, SLOT(setArcPointX(double)));
        connect(_gl_widget, SIGNAL(sendArcPointY(double)), this, SLOT(setArcPointY(double)));
        connect(_gl_widget, SIGNAL(sendArcPointZ(double)), this, SLOT(setArcPointZ(double)));



        //patches stuff

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
}
