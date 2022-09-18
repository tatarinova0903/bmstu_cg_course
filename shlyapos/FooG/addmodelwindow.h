#ifndef ADDMODELWINDOW_H
#define ADDMODELWINDOW_H

#include <QDialog>
#include <QFileDialog>
#include <QColorDialog>

#include <cstdlib>

struct AddModelParameters
{
    float moveX, moveY, moveZ;
    float scaleX, scaleY, scaleZ;

    QString filename;
    QString modelName;

    QColor color;

    float enX, enY, enZ;

    void configPerson()
    {
        moveX = moveY = moveZ = 0.0;
        scaleX = scaleZ = 1.0;
        scaleY = -1.0;
        filename = "/Users/daria/Desktop/bmstu_cg_cource/shlyapos/FooG/SourceObjects/person.obj";
        modelName = "person";
        color = QColor(255, 255, 255, 127);
    }
};

namespace Ui {
class AddModelWindow;
}

class AddModelWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddModelWindow(int, QDialog *parent = nullptr);
    ~AddModelWindow();

private:
    Ui::AddModelWindow *ui;
    AddModelParameters params;

    // For auto name
    int modelCnt;
    std::string name;

    void initLabels();
    void initLineEdits();
    void initParams();

private slots:
    void openFileDialog();
    void chooseColor();

    void okButton();
    void cancelButton();

signals:
    void saveModelParams(AddModelParameters&);
};

#endif // ADDMODELWINDOW_H
