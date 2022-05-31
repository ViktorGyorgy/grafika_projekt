/********************************************************************************
** Form generated from reading UI file 'SideWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDEWIDGET_H
#define UI_SIDEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SideWidget
{
public:
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QSlider *rotate_x_slider;
    QLabel *label_2;
    QSlider *rotate_y_slider;
    QLabel *label_3;
    QSlider *rotate_z_slider;
    QLabel *label_4;
    QDoubleSpinBox *zoom_factor_spin_box;
    QLabel *label_5;
    QDoubleSpinBox *trans_x_spin_box;
    QLabel *label_6;
    QDoubleSpinBox *trans_y_spin_box;
    QLabel *label_7;
    QDoubleSpinBox *trans_z_spin_box;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout_2;
    QLabel *label_8;
    QLabel *label_9;
    QComboBox *comboBoxSelectedArcPoint;
    QCheckBox *checkBoxShowArcDerivatives1;
    QCheckBox *checkBoxShowArcDerivatives2;
    QDoubleSpinBox *doubleSpinBoxScaleArcDerivatives;
    QLabel *label_11;
    QDoubleSpinBox *doubleSpinBoxArcX;
    QLabel *label_12;
    QDoubleSpinBox *doubleSpinBoxArcY;
    QLabel *label_13;
    QDoubleSpinBox *doubleSpinBoxArcZ;
    QLabel *label_10;
    QComboBox *comboBoxSelectedArc;
    QCheckBox *checkBoxShowArcControlPolygon;
    QCheckBox *checkBoxShowArcDataPoints;
    QLabel *label_22;
    QComboBox *comboBoxSelectedJoiningArc;
    QComboBox *comboBoxSelectedArcJoinType;
    QLabel *label_23;
    QWidget *page_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_3;
    QLabel *label_14;
    QComboBox *comboBoxSelectedPatch;
    QLabel *label_15;
    QComboBox *comboBoxSelectedPatchPoint;
    QCheckBox *checkBoxShowPatchControlPolygon;
    QCheckBox *checkBoxShowPatchDataPoints;
    QCheckBox *checkBoxShowInterpolatingSurface;
    QCheckBox *checkBoxShowNormalVectors;
    QLabel *label_16;
    QComboBox *comboBoxMaterial;
    QLabel *label_17;
    QComboBox *comboBoxLight;
    QCheckBox *checkBoxShowPatchDerivatives;
    QCheckBox *checkBoxShowPatchPartialDerivatives;
    QLabel *label_18;
    QDoubleSpinBox *doubleSpinBoxScalePatchDerivatives;
    QCheckBox *checkBoxApplyLight;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QDoubleSpinBox *doubleSpinBoxPatchX;
    QDoubleSpinBox *doubleSpinBoxPatchY;
    QDoubleSpinBox *doubleSpinBoxPatchZ;
    QComboBox *comboBoxSelectedJoiningPatch;
    QComboBox *comboBoxSelectedPatchJoinType;
    QLabel *label_24;
    QLabel *label_25;
    QGroupBox *groupBox_2;
    QWidget *formLayoutWidget_3;
    QFormLayout *formLayout_4;
    QCheckBox *checkBoxShowIsoparametricCurvesU;
    QCheckBox *checkBoxShowIsoparametricCurvesV;
    QCheckBox *checkBoxShowIsometricDerivatives;

    void setupUi(QWidget *SideWidget)
    {
        if (SideWidget->objectName().isEmpty())
            SideWidget->setObjectName(QString::fromUtf8("SideWidget"));
        SideWidget->resize(373, 1143);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SideWidget->sizePolicy().hasHeightForWidth());
        SideWidget->setSizePolicy(sizePolicy);
        SideWidget->setMinimumSize(QSize(269, 0));
        groupBox = new QGroupBox(SideWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 331, 261));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(23, 21, 291, 230));
        formLayout = new QFormLayout(layoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        rotate_x_slider = new QSlider(layoutWidget);
        rotate_x_slider->setObjectName(QString::fromUtf8("rotate_x_slider"));
        rotate_x_slider->setMinimum(-180);
        rotate_x_slider->setMaximum(180);
        rotate_x_slider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, rotate_x_slider);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        rotate_y_slider = new QSlider(layoutWidget);
        rotate_y_slider->setObjectName(QString::fromUtf8("rotate_y_slider"));
        rotate_y_slider->setMinimum(-180);
        rotate_y_slider->setMaximum(180);
        rotate_y_slider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, rotate_y_slider);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        rotate_z_slider = new QSlider(layoutWidget);
        rotate_z_slider->setObjectName(QString::fromUtf8("rotate_z_slider"));
        rotate_z_slider->setMinimum(-180);
        rotate_z_slider->setMaximum(180);
        rotate_z_slider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(2, QFormLayout::FieldRole, rotate_z_slider);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        zoom_factor_spin_box = new QDoubleSpinBox(layoutWidget);
        zoom_factor_spin_box->setObjectName(QString::fromUtf8("zoom_factor_spin_box"));
        zoom_factor_spin_box->setDecimals(5);
        zoom_factor_spin_box->setMinimum(0.000100000000000);
        zoom_factor_spin_box->setMaximum(10000.000000000000000);
        zoom_factor_spin_box->setSingleStep(0.100000000000000);
        zoom_factor_spin_box->setValue(1.000000000000000);

        formLayout->setWidget(3, QFormLayout::FieldRole, zoom_factor_spin_box);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        trans_x_spin_box = new QDoubleSpinBox(layoutWidget);
        trans_x_spin_box->setObjectName(QString::fromUtf8("trans_x_spin_box"));
        trans_x_spin_box->setMinimum(-100.000000000000000);
        trans_x_spin_box->setMaximum(100.000000000000000);
        trans_x_spin_box->setSingleStep(0.100000000000000);

        formLayout->setWidget(4, QFormLayout::FieldRole, trans_x_spin_box);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        trans_y_spin_box = new QDoubleSpinBox(layoutWidget);
        trans_y_spin_box->setObjectName(QString::fromUtf8("trans_y_spin_box"));
        trans_y_spin_box->setMinimum(-100.000000000000000);
        trans_y_spin_box->setMaximum(100.000000000000000);
        trans_y_spin_box->setSingleStep(0.100000000000000);

        formLayout->setWidget(5, QFormLayout::FieldRole, trans_y_spin_box);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        trans_z_spin_box = new QDoubleSpinBox(layoutWidget);
        trans_z_spin_box->setObjectName(QString::fromUtf8("trans_z_spin_box"));
        trans_z_spin_box->setMinimum(-100.000000000000000);
        trans_z_spin_box->setMaximum(100.000000000000000);
        trans_z_spin_box->setSingleStep(0.100000000000000);

        formLayout->setWidget(6, QFormLayout::FieldRole, trans_z_spin_box);

        toolBox = new QToolBox(SideWidget);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        toolBox->setGeometry(QRect(10, 290, 331, 721));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 331, 651));
        formLayoutWidget = new QWidget(page);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 291, 345));
        formLayout_2 = new QFormLayout(formLayoutWidget);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(formLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_9);

        comboBoxSelectedArcPoint = new QComboBox(formLayoutWidget);
        comboBoxSelectedArcPoint->addItem(QString());
        comboBoxSelectedArcPoint->addItem(QString());
        comboBoxSelectedArcPoint->addItem(QString());
        comboBoxSelectedArcPoint->addItem(QString());
        comboBoxSelectedArcPoint->setObjectName(QString::fromUtf8("comboBoxSelectedArcPoint"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, comboBoxSelectedArcPoint);

        checkBoxShowArcDerivatives1 = new QCheckBox(formLayoutWidget);
        checkBoxShowArcDerivatives1->setObjectName(QString::fromUtf8("checkBoxShowArcDerivatives1"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, checkBoxShowArcDerivatives1);

        checkBoxShowArcDerivatives2 = new QCheckBox(formLayoutWidget);
        checkBoxShowArcDerivatives2->setObjectName(QString::fromUtf8("checkBoxShowArcDerivatives2"));

        formLayout_2->setWidget(5, QFormLayout::FieldRole, checkBoxShowArcDerivatives2);

        doubleSpinBoxScaleArcDerivatives = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBoxScaleArcDerivatives->setObjectName(QString::fromUtf8("doubleSpinBoxScaleArcDerivatives"));
        doubleSpinBoxScaleArcDerivatives->setMaximum(5.000000000000000);
        doubleSpinBoxScaleArcDerivatives->setSingleStep(0.050000000000000);
        doubleSpinBoxScaleArcDerivatives->setValue(1.000000000000000);

        formLayout_2->setWidget(7, QFormLayout::FieldRole, doubleSpinBoxScaleArcDerivatives);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_11);

        doubleSpinBoxArcX = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBoxArcX->setObjectName(QString::fromUtf8("doubleSpinBoxArcX"));
        doubleSpinBoxArcX->setDecimals(3);
        doubleSpinBoxArcX->setMinimum(-99.000000000000000);
        doubleSpinBoxArcX->setSingleStep(0.100000000000000);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, doubleSpinBoxArcX);

        label_12 = new QLabel(formLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_12);

        doubleSpinBoxArcY = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBoxArcY->setObjectName(QString::fromUtf8("doubleSpinBoxArcY"));
        doubleSpinBoxArcY->setDecimals(3);
        doubleSpinBoxArcY->setMinimum(-99.000000000000000);
        doubleSpinBoxArcY->setSingleStep(0.100000000000000);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, doubleSpinBoxArcY);

        label_13 = new QLabel(formLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_13);

        doubleSpinBoxArcZ = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBoxArcZ->setObjectName(QString::fromUtf8("doubleSpinBoxArcZ"));
        doubleSpinBoxArcZ->setDecimals(3);
        doubleSpinBoxArcZ->setMinimum(-104.000000000000000);
        doubleSpinBoxArcZ->setSingleStep(0.100000000000000);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, doubleSpinBoxArcZ);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_2->setWidget(7, QFormLayout::LabelRole, label_10);

        comboBoxSelectedArc = new QComboBox(formLayoutWidget);
        comboBoxSelectedArc->addItem(QString());
        comboBoxSelectedArc->addItem(QString());
        comboBoxSelectedArc->addItem(QString());
        comboBoxSelectedArc->addItem(QString());
        comboBoxSelectedArc->addItem(QString());
        comboBoxSelectedArc->addItem(QString());
        comboBoxSelectedArc->addItem(QString());
        comboBoxSelectedArc->addItem(QString());
        comboBoxSelectedArc->addItem(QString());
        comboBoxSelectedArc->setObjectName(QString::fromUtf8("comboBoxSelectedArc"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, comboBoxSelectedArc);

        checkBoxShowArcControlPolygon = new QCheckBox(formLayoutWidget);
        checkBoxShowArcControlPolygon->setObjectName(QString::fromUtf8("checkBoxShowArcControlPolygon"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, checkBoxShowArcControlPolygon);

        checkBoxShowArcDataPoints = new QCheckBox(formLayoutWidget);
        checkBoxShowArcDataPoints->setObjectName(QString::fromUtf8("checkBoxShowArcDataPoints"));

        formLayout_2->setWidget(6, QFormLayout::FieldRole, checkBoxShowArcDataPoints);

        label_22 = new QLabel(formLayoutWidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        formLayout_2->setWidget(8, QFormLayout::LabelRole, label_22);

        comboBoxSelectedJoiningArc = new QComboBox(formLayoutWidget);
        comboBoxSelectedJoiningArc->addItem(QString());
        comboBoxSelectedJoiningArc->addItem(QString());
        comboBoxSelectedJoiningArc->addItem(QString());
        comboBoxSelectedJoiningArc->addItem(QString());
        comboBoxSelectedJoiningArc->addItem(QString());
        comboBoxSelectedJoiningArc->addItem(QString());
        comboBoxSelectedJoiningArc->addItem(QString());
        comboBoxSelectedJoiningArc->addItem(QString());
        comboBoxSelectedJoiningArc->addItem(QString());
        comboBoxSelectedJoiningArc->setObjectName(QString::fromUtf8("comboBoxSelectedJoiningArc"));

        formLayout_2->setWidget(8, QFormLayout::FieldRole, comboBoxSelectedJoiningArc);

        comboBoxSelectedArcJoinType = new QComboBox(formLayoutWidget);
        comboBoxSelectedArcJoinType->addItem(QString());
        comboBoxSelectedArcJoinType->addItem(QString());
        comboBoxSelectedArcJoinType->addItem(QString());
        comboBoxSelectedArcJoinType->addItem(QString());
        comboBoxSelectedArcJoinType->setObjectName(QString::fromUtf8("comboBoxSelectedArcJoinType"));

        formLayout_2->setWidget(9, QFormLayout::FieldRole, comboBoxSelectedArcJoinType);

        label_23 = new QLabel(formLayoutWidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        formLayout_2->setWidget(9, QFormLayout::LabelRole, label_23);

        toolBox->addItem(page, QString::fromUtf8("Arcs"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 331, 651));
        formLayoutWidget_2 = new QWidget(page_2);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(10, 10, 317, 481));
        formLayout_3 = new QFormLayout(formLayoutWidget_2);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(formLayoutWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_14);

        comboBoxSelectedPatch = new QComboBox(formLayoutWidget_2);
        comboBoxSelectedPatch->addItem(QString());
        comboBoxSelectedPatch->addItem(QString());
        comboBoxSelectedPatch->addItem(QString());
        comboBoxSelectedPatch->addItem(QString());
        comboBoxSelectedPatch->addItem(QString());
        comboBoxSelectedPatch->addItem(QString());
        comboBoxSelectedPatch->addItem(QString());
        comboBoxSelectedPatch->addItem(QString());
        comboBoxSelectedPatch->addItem(QString());
        comboBoxSelectedPatch->setObjectName(QString::fromUtf8("comboBoxSelectedPatch"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, comboBoxSelectedPatch);

        label_15 = new QLabel(formLayoutWidget_2);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_15);

        comboBoxSelectedPatchPoint = new QComboBox(formLayoutWidget_2);
        comboBoxSelectedPatchPoint->addItem(QString());
        comboBoxSelectedPatchPoint->addItem(QString());
        comboBoxSelectedPatchPoint->addItem(QString());
        comboBoxSelectedPatchPoint->addItem(QString());
        comboBoxSelectedPatchPoint->addItem(QString());
        comboBoxSelectedPatchPoint->addItem(QString());
        comboBoxSelectedPatchPoint->addItem(QString());
        comboBoxSelectedPatchPoint->addItem(QString());
        comboBoxSelectedPatchPoint->addItem(QString());
        comboBoxSelectedPatchPoint->addItem(QString());
        comboBoxSelectedPatchPoint->addItem(QString());
        comboBoxSelectedPatchPoint->addItem(QString());
        comboBoxSelectedPatchPoint->addItem(QString());
        comboBoxSelectedPatchPoint->addItem(QString());
        comboBoxSelectedPatchPoint->addItem(QString());
        comboBoxSelectedPatchPoint->addItem(QString());
        comboBoxSelectedPatchPoint->setObjectName(QString::fromUtf8("comboBoxSelectedPatchPoint"));

        formLayout_3->setWidget(1, QFormLayout::FieldRole, comboBoxSelectedPatchPoint);

        checkBoxShowPatchControlPolygon = new QCheckBox(formLayoutWidget_2);
        checkBoxShowPatchControlPolygon->setObjectName(QString::fromUtf8("checkBoxShowPatchControlPolygon"));

        formLayout_3->setWidget(5, QFormLayout::LabelRole, checkBoxShowPatchControlPolygon);

        checkBoxShowPatchDataPoints = new QCheckBox(formLayoutWidget_2);
        checkBoxShowPatchDataPoints->setObjectName(QString::fromUtf8("checkBoxShowPatchDataPoints"));

        formLayout_3->setWidget(5, QFormLayout::FieldRole, checkBoxShowPatchDataPoints);

        checkBoxShowInterpolatingSurface = new QCheckBox(formLayoutWidget_2);
        checkBoxShowInterpolatingSurface->setObjectName(QString::fromUtf8("checkBoxShowInterpolatingSurface"));

        formLayout_3->setWidget(6, QFormLayout::LabelRole, checkBoxShowInterpolatingSurface);

        checkBoxShowNormalVectors = new QCheckBox(formLayoutWidget_2);
        checkBoxShowNormalVectors->setObjectName(QString::fromUtf8("checkBoxShowNormalVectors"));

        formLayout_3->setWidget(6, QFormLayout::FieldRole, checkBoxShowNormalVectors);

        label_16 = new QLabel(formLayoutWidget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        formLayout_3->setWidget(7, QFormLayout::LabelRole, label_16);

        comboBoxMaterial = new QComboBox(formLayoutWidget_2);
        comboBoxMaterial->addItem(QString());
        comboBoxMaterial->addItem(QString());
        comboBoxMaterial->addItem(QString());
        comboBoxMaterial->addItem(QString());
        comboBoxMaterial->addItem(QString());
        comboBoxMaterial->addItem(QString());
        comboBoxMaterial->addItem(QString());
        comboBoxMaterial->setObjectName(QString::fromUtf8("comboBoxMaterial"));

        formLayout_3->setWidget(7, QFormLayout::FieldRole, comboBoxMaterial);

        label_17 = new QLabel(formLayoutWidget_2);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        formLayout_3->setWidget(8, QFormLayout::LabelRole, label_17);

        comboBoxLight = new QComboBox(formLayoutWidget_2);
        comboBoxLight->addItem(QString());
        comboBoxLight->addItem(QString());
        comboBoxLight->addItem(QString());
        comboBoxLight->setObjectName(QString::fromUtf8("comboBoxLight"));

        formLayout_3->setWidget(8, QFormLayout::FieldRole, comboBoxLight);

        checkBoxShowPatchDerivatives = new QCheckBox(formLayoutWidget_2);
        checkBoxShowPatchDerivatives->setObjectName(QString::fromUtf8("checkBoxShowPatchDerivatives"));

        formLayout_3->setWidget(10, QFormLayout::LabelRole, checkBoxShowPatchDerivatives);

        checkBoxShowPatchPartialDerivatives = new QCheckBox(formLayoutWidget_2);
        checkBoxShowPatchPartialDerivatives->setObjectName(QString::fromUtf8("checkBoxShowPatchPartialDerivatives"));

        formLayout_3->setWidget(10, QFormLayout::FieldRole, checkBoxShowPatchPartialDerivatives);

        label_18 = new QLabel(formLayoutWidget_2);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        formLayout_3->setWidget(11, QFormLayout::LabelRole, label_18);

        doubleSpinBoxScalePatchDerivatives = new QDoubleSpinBox(formLayoutWidget_2);
        doubleSpinBoxScalePatchDerivatives->setObjectName(QString::fromUtf8("doubleSpinBoxScalePatchDerivatives"));
        doubleSpinBoxScalePatchDerivatives->setMaximum(5.000000000000000);
        doubleSpinBoxScalePatchDerivatives->setSingleStep(0.050000000000000);
        doubleSpinBoxScalePatchDerivatives->setValue(1.000000000000000);

        formLayout_3->setWidget(11, QFormLayout::FieldRole, doubleSpinBoxScalePatchDerivatives);

        checkBoxApplyLight = new QCheckBox(formLayoutWidget_2);
        checkBoxApplyLight->setObjectName(QString::fromUtf8("checkBoxApplyLight"));

        formLayout_3->setWidget(9, QFormLayout::LabelRole, checkBoxApplyLight);

        label_19 = new QLabel(formLayoutWidget_2);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, label_19);

        label_20 = new QLabel(formLayoutWidget_2);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        formLayout_3->setWidget(3, QFormLayout::LabelRole, label_20);

        label_21 = new QLabel(formLayoutWidget_2);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        formLayout_3->setWidget(4, QFormLayout::LabelRole, label_21);

        doubleSpinBoxPatchX = new QDoubleSpinBox(formLayoutWidget_2);
        doubleSpinBoxPatchX->setObjectName(QString::fromUtf8("doubleSpinBoxPatchX"));
        doubleSpinBoxPatchX->setDecimals(3);
        doubleSpinBoxPatchX->setMinimum(-99.989999999999995);
        doubleSpinBoxPatchX->setSingleStep(0.100000000000000);

        formLayout_3->setWidget(2, QFormLayout::FieldRole, doubleSpinBoxPatchX);

        doubleSpinBoxPatchY = new QDoubleSpinBox(formLayoutWidget_2);
        doubleSpinBoxPatchY->setObjectName(QString::fromUtf8("doubleSpinBoxPatchY"));
        doubleSpinBoxPatchY->setDecimals(3);
        doubleSpinBoxPatchY->setMinimum(-99.989999999999995);
        doubleSpinBoxPatchY->setSingleStep(0.100000000000000);

        formLayout_3->setWidget(3, QFormLayout::FieldRole, doubleSpinBoxPatchY);

        doubleSpinBoxPatchZ = new QDoubleSpinBox(formLayoutWidget_2);
        doubleSpinBoxPatchZ->setObjectName(QString::fromUtf8("doubleSpinBoxPatchZ"));
        doubleSpinBoxPatchZ->setDecimals(3);
        doubleSpinBoxPatchZ->setMinimum(-99.989999999999995);
        doubleSpinBoxPatchZ->setSingleStep(0.100000000000000);

        formLayout_3->setWidget(4, QFormLayout::FieldRole, doubleSpinBoxPatchZ);

        comboBoxSelectedJoiningPatch = new QComboBox(formLayoutWidget_2);
        comboBoxSelectedJoiningPatch->addItem(QString());
        comboBoxSelectedJoiningPatch->addItem(QString());
        comboBoxSelectedJoiningPatch->addItem(QString());
        comboBoxSelectedJoiningPatch->addItem(QString());
        comboBoxSelectedJoiningPatch->addItem(QString());
        comboBoxSelectedJoiningPatch->addItem(QString());
        comboBoxSelectedJoiningPatch->addItem(QString());
        comboBoxSelectedJoiningPatch->addItem(QString());
        comboBoxSelectedJoiningPatch->addItem(QString());
        comboBoxSelectedJoiningPatch->setObjectName(QString::fromUtf8("comboBoxSelectedJoiningPatch"));

        formLayout_3->setWidget(12, QFormLayout::FieldRole, comboBoxSelectedJoiningPatch);

        comboBoxSelectedPatchJoinType = new QComboBox(formLayoutWidget_2);
        comboBoxSelectedPatchJoinType->addItem(QString());
        comboBoxSelectedPatchJoinType->addItem(QString());
        comboBoxSelectedPatchJoinType->addItem(QString());
        comboBoxSelectedPatchJoinType->setObjectName(QString::fromUtf8("comboBoxSelectedPatchJoinType"));

        formLayout_3->setWidget(13, QFormLayout::FieldRole, comboBoxSelectedPatchJoinType);

        label_24 = new QLabel(formLayoutWidget_2);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        formLayout_3->setWidget(12, QFormLayout::LabelRole, label_24);

        label_25 = new QLabel(formLayoutWidget_2);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        formLayout_3->setWidget(13, QFormLayout::LabelRole, label_25);

        groupBox_2 = new QGroupBox(page_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 500, 311, 121));
        formLayoutWidget_3 = new QWidget(groupBox_2);
        formLayoutWidget_3->setObjectName(QString::fromUtf8("formLayoutWidget_3"));
        formLayoutWidget_3->setGeometry(QRect(10, 30, 291, 81));
        formLayout_4 = new QFormLayout(formLayoutWidget_3);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        formLayout_4->setContentsMargins(0, 0, 0, 0);
        checkBoxShowIsoparametricCurvesU = new QCheckBox(formLayoutWidget_3);
        checkBoxShowIsoparametricCurvesU->setObjectName(QString::fromUtf8("checkBoxShowIsoparametricCurvesU"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, checkBoxShowIsoparametricCurvesU);

        checkBoxShowIsoparametricCurvesV = new QCheckBox(formLayoutWidget_3);
        checkBoxShowIsoparametricCurvesV->setObjectName(QString::fromUtf8("checkBoxShowIsoparametricCurvesV"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, checkBoxShowIsoparametricCurvesV);

        checkBoxShowIsometricDerivatives = new QCheckBox(formLayoutWidget_3);
        checkBoxShowIsometricDerivatives->setObjectName(QString::fromUtf8("checkBoxShowIsometricDerivatives"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, checkBoxShowIsometricDerivatives);

        toolBox->addItem(page_2, QString::fromUtf8("Patches"));
#if QT_CONFIG(shortcut)
        label->setBuddy(rotate_x_slider);
        label_2->setBuddy(rotate_y_slider);
        label_3->setBuddy(rotate_z_slider);
        label_4->setBuddy(zoom_factor_spin_box);
        label_5->setBuddy(trans_x_spin_box);
        label_6->setBuddy(trans_y_spin_box);
        label_7->setBuddy(trans_z_spin_box);
#endif // QT_CONFIG(shortcut)

        retranslateUi(SideWidget);

        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SideWidget);
    } // setupUi

    void retranslateUi(QWidget *SideWidget)
    {
        SideWidget->setWindowTitle(QCoreApplication::translate("SideWidget", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SideWidget", "Transformations", nullptr));
        label->setText(QCoreApplication::translate("SideWidget", "Rotate around x", nullptr));
        label_2->setText(QCoreApplication::translate("SideWidget", "Rotate around y", nullptr));
        label_3->setText(QCoreApplication::translate("SideWidget", "Rotate around z", nullptr));
        label_4->setText(QCoreApplication::translate("SideWidget", "Zoom factor", nullptr));
#if QT_CONFIG(tooltip)
        zoom_factor_spin_box->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_5->setText(QCoreApplication::translate("SideWidget", "Translate along x", nullptr));
        label_6->setText(QCoreApplication::translate("SideWidget", "Translate along y", nullptr));
        label_7->setText(QCoreApplication::translate("SideWidget", "Translate along z", nullptr));
        label_8->setText(QCoreApplication::translate("SideWidget", "selected arc", nullptr));
        label_9->setText(QCoreApplication::translate("SideWidget", "selected point", nullptr));
        comboBoxSelectedArcPoint->setItemText(0, QCoreApplication::translate("SideWidget", "0", nullptr));
        comboBoxSelectedArcPoint->setItemText(1, QCoreApplication::translate("SideWidget", "1", nullptr));
        comboBoxSelectedArcPoint->setItemText(2, QCoreApplication::translate("SideWidget", "2", nullptr));
        comboBoxSelectedArcPoint->setItemText(3, QCoreApplication::translate("SideWidget", "3", nullptr));

        checkBoxShowArcDerivatives1->setText(QCoreApplication::translate("SideWidget", "show derivative1", nullptr));
        checkBoxShowArcDerivatives2->setText(QCoreApplication::translate("SideWidget", "show derivative2", nullptr));
        label_11->setText(QCoreApplication::translate("SideWidget", "x", nullptr));
        label_12->setText(QCoreApplication::translate("SideWidget", "y", nullptr));
        label_13->setText(QCoreApplication::translate("SideWidget", "z", nullptr));
        label_10->setText(QCoreApplication::translate("SideWidget", "derivative scale", nullptr));
        comboBoxSelectedArc->setItemText(0, QCoreApplication::translate("SideWidget", "white", nullptr));
        comboBoxSelectedArc->setItemText(1, QCoreApplication::translate("SideWidget", "pink", nullptr));
        comboBoxSelectedArc->setItemText(2, QCoreApplication::translate("SideWidget", "purple", nullptr));
        comboBoxSelectedArc->setItemText(3, QCoreApplication::translate("SideWidget", "blue", nullptr));
        comboBoxSelectedArc->setItemText(4, QCoreApplication::translate("SideWidget", "green", nullptr));
        comboBoxSelectedArc->setItemText(5, QCoreApplication::translate("SideWidget", "gray", nullptr));
        comboBoxSelectedArc->setItemText(6, QCoreApplication::translate("SideWidget", "lime", nullptr));
        comboBoxSelectedArc->setItemText(7, QCoreApplication::translate("SideWidget", "yellow", nullptr));
        comboBoxSelectedArc->setItemText(8, QCoreApplication::translate("SideWidget", "brown", nullptr));

        checkBoxShowArcControlPolygon->setText(QCoreApplication::translate("SideWidget", "control polygon", nullptr));
        checkBoxShowArcDataPoints->setText(QCoreApplication::translate("SideWidget", "data points", nullptr));
        label_22->setText(QCoreApplication::translate("SideWidget", "join with", nullptr));
        comboBoxSelectedJoiningArc->setItemText(0, QCoreApplication::translate("SideWidget", "white", nullptr));
        comboBoxSelectedJoiningArc->setItemText(1, QCoreApplication::translate("SideWidget", "pink", nullptr));
        comboBoxSelectedJoiningArc->setItemText(2, QCoreApplication::translate("SideWidget", "purple", nullptr));
        comboBoxSelectedJoiningArc->setItemText(3, QCoreApplication::translate("SideWidget", "blue", nullptr));
        comboBoxSelectedJoiningArc->setItemText(4, QCoreApplication::translate("SideWidget", "green", nullptr));
        comboBoxSelectedJoiningArc->setItemText(5, QCoreApplication::translate("SideWidget", "gray", nullptr));
        comboBoxSelectedJoiningArc->setItemText(6, QCoreApplication::translate("SideWidget", "lime", nullptr));
        comboBoxSelectedJoiningArc->setItemText(7, QCoreApplication::translate("SideWidget", "yellow", nullptr));
        comboBoxSelectedJoiningArc->setItemText(8, QCoreApplication::translate("SideWidget", "brown", nullptr));

        comboBoxSelectedArcJoinType->setItemText(0, QCoreApplication::translate("SideWidget", "right-right", nullptr));
        comboBoxSelectedArcJoinType->setItemText(1, QCoreApplication::translate("SideWidget", "left-left", nullptr));
        comboBoxSelectedArcJoinType->setItemText(2, QCoreApplication::translate("SideWidget", "right-left", nullptr));
        comboBoxSelectedArcJoinType->setItemText(3, QCoreApplication::translate("SideWidget", "left-right", nullptr));

        label_23->setText(QCoreApplication::translate("SideWidget", "join type", nullptr));
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("SideWidget", "Arcs", nullptr));
        label_14->setText(QCoreApplication::translate("SideWidget", "selected patch", nullptr));
        comboBoxSelectedPatch->setItemText(0, QCoreApplication::translate("SideWidget", "white", nullptr));
        comboBoxSelectedPatch->setItemText(1, QCoreApplication::translate("SideWidget", "pink", nullptr));
        comboBoxSelectedPatch->setItemText(2, QCoreApplication::translate("SideWidget", "purple", nullptr));
        comboBoxSelectedPatch->setItemText(3, QCoreApplication::translate("SideWidget", "blue", nullptr));
        comboBoxSelectedPatch->setItemText(4, QCoreApplication::translate("SideWidget", "green", nullptr));
        comboBoxSelectedPatch->setItemText(5, QCoreApplication::translate("SideWidget", "gray", nullptr));
        comboBoxSelectedPatch->setItemText(6, QCoreApplication::translate("SideWidget", "lime", nullptr));
        comboBoxSelectedPatch->setItemText(7, QCoreApplication::translate("SideWidget", "yellow", nullptr));
        comboBoxSelectedPatch->setItemText(8, QCoreApplication::translate("SideWidget", "brown", nullptr));

        label_15->setText(QCoreApplication::translate("SideWidget", "selected point", nullptr));
        comboBoxSelectedPatchPoint->setItemText(0, QCoreApplication::translate("SideWidget", "0", nullptr));
        comboBoxSelectedPatchPoint->setItemText(1, QCoreApplication::translate("SideWidget", "1", nullptr));
        comboBoxSelectedPatchPoint->setItemText(2, QCoreApplication::translate("SideWidget", "2", nullptr));
        comboBoxSelectedPatchPoint->setItemText(3, QCoreApplication::translate("SideWidget", "3", nullptr));
        comboBoxSelectedPatchPoint->setItemText(4, QCoreApplication::translate("SideWidget", "4", nullptr));
        comboBoxSelectedPatchPoint->setItemText(5, QCoreApplication::translate("SideWidget", "5", nullptr));
        comboBoxSelectedPatchPoint->setItemText(6, QCoreApplication::translate("SideWidget", "6", nullptr));
        comboBoxSelectedPatchPoint->setItemText(7, QCoreApplication::translate("SideWidget", "7", nullptr));
        comboBoxSelectedPatchPoint->setItemText(8, QCoreApplication::translate("SideWidget", "8", nullptr));
        comboBoxSelectedPatchPoint->setItemText(9, QCoreApplication::translate("SideWidget", "9", nullptr));
        comboBoxSelectedPatchPoint->setItemText(10, QCoreApplication::translate("SideWidget", "10", nullptr));
        comboBoxSelectedPatchPoint->setItemText(11, QCoreApplication::translate("SideWidget", "11", nullptr));
        comboBoxSelectedPatchPoint->setItemText(12, QCoreApplication::translate("SideWidget", "12", nullptr));
        comboBoxSelectedPatchPoint->setItemText(13, QCoreApplication::translate("SideWidget", "13", nullptr));
        comboBoxSelectedPatchPoint->setItemText(14, QCoreApplication::translate("SideWidget", "14", nullptr));
        comboBoxSelectedPatchPoint->setItemText(15, QCoreApplication::translate("SideWidget", "15", nullptr));

        checkBoxShowPatchControlPolygon->setText(QCoreApplication::translate("SideWidget", "control polygon", nullptr));
        checkBoxShowPatchDataPoints->setText(QCoreApplication::translate("SideWidget", "data points", nullptr));
        checkBoxShowInterpolatingSurface->setText(QCoreApplication::translate("SideWidget", "interpolating suface", nullptr));
        checkBoxShowNormalVectors->setText(QCoreApplication::translate("SideWidget", "normal vectors", nullptr));
        label_16->setText(QCoreApplication::translate("SideWidget", "material", nullptr));
        comboBoxMaterial->setItemText(0, QCoreApplication::translate("SideWidget", "Brass", nullptr));
        comboBoxMaterial->setItemText(1, QCoreApplication::translate("SideWidget", "Gold", nullptr));
        comboBoxMaterial->setItemText(2, QCoreApplication::translate("SideWidget", "Silver", nullptr));
        comboBoxMaterial->setItemText(3, QCoreApplication::translate("SideWidget", "Emerald", nullptr));
        comboBoxMaterial->setItemText(4, QCoreApplication::translate("SideWidget", "Pearl", nullptr));
        comboBoxMaterial->setItemText(5, QCoreApplication::translate("SideWidget", "Turquoise", nullptr));
        comboBoxMaterial->setItemText(6, QCoreApplication::translate("SideWidget", "Ruby", nullptr));

        label_17->setText(QCoreApplication::translate("SideWidget", "light", nullptr));
        comboBoxLight->setItemText(0, QCoreApplication::translate("SideWidget", "Directional light", nullptr));
        comboBoxLight->setItemText(1, QCoreApplication::translate("SideWidget", "Spot light", nullptr));
        comboBoxLight->setItemText(2, QCoreApplication::translate("SideWidget", "Point light", nullptr));

        checkBoxShowPatchDerivatives->setText(QCoreApplication::translate("SideWidget", "derivatives", nullptr));
        checkBoxShowPatchPartialDerivatives->setText(QCoreApplication::translate("SideWidget", "partial derivatives", nullptr));
        label_18->setText(QCoreApplication::translate("SideWidget", "derivatives scale", nullptr));
        checkBoxApplyLight->setText(QCoreApplication::translate("SideWidget", "light", nullptr));
        label_19->setText(QCoreApplication::translate("SideWidget", "x", nullptr));
        label_20->setText(QCoreApplication::translate("SideWidget", "y", nullptr));
        label_21->setText(QCoreApplication::translate("SideWidget", "z", nullptr));
        comboBoxSelectedJoiningPatch->setItemText(0, QCoreApplication::translate("SideWidget", "white", nullptr));
        comboBoxSelectedJoiningPatch->setItemText(1, QCoreApplication::translate("SideWidget", "pink", nullptr));
        comboBoxSelectedJoiningPatch->setItemText(2, QCoreApplication::translate("SideWidget", "purple", nullptr));
        comboBoxSelectedJoiningPatch->setItemText(3, QCoreApplication::translate("SideWidget", "blue", nullptr));
        comboBoxSelectedJoiningPatch->setItemText(4, QCoreApplication::translate("SideWidget", "green", nullptr));
        comboBoxSelectedJoiningPatch->setItemText(5, QCoreApplication::translate("SideWidget", "gray", nullptr));
        comboBoxSelectedJoiningPatch->setItemText(6, QCoreApplication::translate("SideWidget", "lime", nullptr));
        comboBoxSelectedJoiningPatch->setItemText(7, QCoreApplication::translate("SideWidget", "yellow", nullptr));
        comboBoxSelectedJoiningPatch->setItemText(8, QCoreApplication::translate("SideWidget", "brown", nullptr));

        comboBoxSelectedPatchJoinType->setItemText(0, QCoreApplication::translate("SideWidget", "north", nullptr));
        comboBoxSelectedPatchJoinType->setItemText(1, QCoreApplication::translate("SideWidget", "west", nullptr));
        comboBoxSelectedPatchJoinType->setItemText(2, QCoreApplication::translate("SideWidget", "east", nullptr));

        label_24->setText(QCoreApplication::translate("SideWidget", "join with", nullptr));
        label_25->setText(QCoreApplication::translate("SideWidget", "join type", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("SideWidget", "Isoparametric cuves", nullptr));
        checkBoxShowIsoparametricCurvesU->setText(QCoreApplication::translate("SideWidget", "show U", nullptr));
        checkBoxShowIsoparametricCurvesV->setText(QCoreApplication::translate("SideWidget", "show V", nullptr));
        checkBoxShowIsometricDerivatives->setText(QCoreApplication::translate("SideWidget", "derivatives", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("SideWidget", "Patches", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SideWidget: public Ui_SideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEWIDGET_H
