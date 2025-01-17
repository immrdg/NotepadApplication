#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNew_triggered();

    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionSave_As_triggered();

    void on_actionPrint_triggered();

    void on_actionCut_triggered();

    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionFont_triggered();

    void on_actionColor_triggered();

    void on_actionBackbround_Color_triggered();

    void on_actionBold_triggered(bool bold);

    void on_actionItalic_triggered(bool italic);

    void on_actionUnderline_triggered(bool checked);

    void on_actionHighlight_Text_triggered();

    void on_actionInfo_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    QString file_path;
};
#endif // MAINWINDOW_H
