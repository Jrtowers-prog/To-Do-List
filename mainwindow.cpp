#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUI();
    loadTasks();
}

MainWindow::~MainWindow() {}

void MainWindow::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);

    taskList = new QListWidget(this);
    taskInput = new QLineEdit(this);
    addButton = new QPushButton("Add Task", this);
    deleteButton = new QPushButton("Delete Task", this);
    markButton = new QPushButton("Mark Completed", this);
    saveButton = new QPushButton("Save", this);

    layout->addWidget(taskList);
    layout->addWidget(taskInput);
    layout->addWidget(addButton);
    layout->addWidget(deleteButton);
    layout->addWidget(markButton);
    layout->addWidget(saveButton);

    setCentralWidget(centralWidget);

    connect(addButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(deleteButton, &QPushButton::clicked, this, &MainWindow::deleteTask);
    connect(markButton, &QPushButton::clicked, this, &MainWindow::markTask);
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::saveTasks);
}

void MainWindow::addTask() {
    QString taskText = taskInput->text();
    if (!taskText.isEmpty()) {
        taskList->addItem("[ ] " + taskText);
        taskInput->clear();
    }
}

void MainWindow::deleteTask() {
    delete taskList->currentItem();
}

void MainWindow::markTask() {
    QListWidgetItem *item = taskList->currentItem();
    if (item) {
        item->setText("[X] " + item->text().mid(3));
    }
}

void MainWindow::saveTasks() {
    QFile file("List.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        for (int i = 0; i < taskList->count(); ++i) {
            out << taskList->item(i)->text() << "\n";
        }
        file.close();
    }
}

void MainWindow::loadTasks() {
    QFile file("List.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        while (!in.atEnd()) {
            taskList->addItem(in.readLine());
        }
        file.close();
    }
}
