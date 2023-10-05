#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_MainWindow.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

private:
    std::unique_ptr<Ui::MainWindow> _ui = std::make_unique<Ui::MainWindow>();
};
#endif // MAINWINDOW_H
