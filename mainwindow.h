#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QFile>
#include <QTextStream>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addTask();
    void deleteTask();
    void markTask();
    void saveTasks();
    void loadTasks();

private:
    QListWidget *taskList;
    QLineEdit *taskInput;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *markButton;
    QPushButton *saveButton;

    void setupUI();
};

#endif // MAINWINDOW_H
