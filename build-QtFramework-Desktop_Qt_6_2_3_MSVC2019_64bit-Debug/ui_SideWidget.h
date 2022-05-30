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
    QComboBox *comboBoxSelectedArc;
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
    QWidget *page_2;
    QWidget *formLayoutWidget_2;
    QFormLayout *formLayout_3;
    QLabel *label_14;

    void setupUi(QWidget *SideWidget)
    {
        if (SideWidget->objectName().isEmpty())
            SideWidget->setObjectName(QString::fromUtf8("SideWidget"));
        SideWidget->resize(289, 651);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SideWidget->sizePolicy().hasHeightForWidth());
        SideWidget->setSizePolicy(sizePolicy);
        SideWidget->setMinimumSize(QSize(269, 0));
        groupBox = new QGroupBox(SideWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 271, 261));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(3, 21, 261, 230));
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
        toolBox->setGeometry(QRect(20, 278, 251, 311));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 251, 251));
        formLayoutWidget = new QWidget(page);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 10, 231, 221));
        formLayout_2 = new QFormLayout(formLayoutWidget);
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(formLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_8);

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

        formLayout_2->setWidget(6, QFormLayout::FieldRole, doubleSpinBoxScaleArcDerivatives);

        label_11 = new QLabel(formLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_11);

        doubleSpinBoxArcX = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBoxArcX->setObjectName(QString::fromUtf8("doubleSpinBoxArcX"));
        doubleSpinBoxArcX->setMinimum(-99.000000000000000);
        doubleSpinBoxArcX->setSingleStep(0.100000000000000);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, doubleSpinBoxArcX);

        label_12 = new QLabel(formLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_12);

        doubleSpinBoxArcY = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBoxArcY->setObjectName(QString::fromUtf8("doubleSpinBoxArcY"));
        doubleSpinBoxArcY->setMinimum(-99.000000000000000);
        doubleSpinBoxArcY->setSingleStep(0.100000000000000);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, doubleSpinBoxArcY);

        label_13 = new QLabel(formLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, label_13);

        doubleSpinBoxArcZ = new QDoubleSpinBox(formLayoutWidget);
        doubleSpinBoxArcZ->setObjectName(QString::fromUtf8("doubleSpinBoxArcZ"));
        doubleSpinBoxArcZ->setMinimum(-99.000000000000000);
        doubleSpinBoxArcZ->setSingleStep(0.100000000000000);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, doubleSpinBoxArcZ);

        label_10 = new QLabel(formLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout_2->setWidget(6, QFormLayout::LabelRole, label_10);

        toolBox->addItem(page, QString::fromUtf8("Arcs"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 251, 251));
        formLayoutWidget_2 = new QWidget(page_2);
        formLayoutWidget_2->setObjectName(QString::fromUtf8("formLayoutWidget_2"));
        formLayoutWidget_2->setGeometry(QRect(9, 9, 231, 241));
        formLayout_3 = new QFormLayout(formLayoutWidget_2);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        formLayout_3->setContentsMargins(0, 0, 0, 0);
        label_14 = new QLabel(formLayoutWidget_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_14);

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

        toolBox->setCurrentIndex(1);


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
        comboBoxSelectedArc->setItemText(0, QCoreApplication::translate("SideWidget", "white", nullptr));
        comboBoxSelectedArc->setItemText(1, QCoreApplication::translate("SideWidget", "pink", nullptr));
        comboBoxSelectedArc->setItemText(2, QCoreApplication::translate("SideWidget", "purple", nullptr));
        comboBoxSelectedArc->setItemText(3, QCoreApplication::translate("SideWidget", "blue", nullptr));
        comboBoxSelectedArc->setItemText(4, QCoreApplication::translate("SideWidget", "green", nullptr));
        comboBoxSelectedArc->setItemText(5, QCoreApplication::translate("SideWidget", "gray", nullptr));
        comboBoxSelectedArc->setItemText(6, QCoreApplication::translate("SideWidget", "lime", nullptr));
        comboBoxSelectedArc->setItemText(7, QCoreApplication::translate("SideWidget", "yellow", nullptr));
        comboBoxSelectedArc->setItemText(8, QCoreApplication::translate("SideWidget", "brown", nullptr));

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
        toolBox->setItemText(toolBox->indexOf(page), QCoreApplication::translate("SideWidget", "Arcs", nullptr));
        label_14->setText(QCoreApplication::translate("SideWidget", "selected patch", nullptr));
        toolBox->setItemText(toolBox->indexOf(page_2), QCoreApplication::translate("SideWidget", "Patches", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SideWidget: public Ui_SideWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEWIDGET_H
