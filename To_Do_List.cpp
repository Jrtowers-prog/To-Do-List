#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void saveTasks(const vector<Task>& tasks, const string& filename) {
    ofstream outFile(filename);

    if (!outFile) {
        cout << "Error saving file.\n\n";
        return;
    }

    for (const auto& task : tasks) {
        outFile << task.description << "\n" << task.completed << "\n";
    }

    outFile.close();
    cout << "Tasks saved successfully. \n\n";
}

// Function to load tasks from a file
void loadTasks(vector<Task>& tasks, const string& filename) {
    ifstream inFile(filename);

    if (!inFile) {
        cout << "No previous task list found.\n\n";
        return;
    }

    Task tempTask;
    while (getline(inFile, tempTask.description)) {
        inFile >> tempTask.completed;
        inFile.ignore();  // Ignore newline after bool
        tasks.push_back(tempTask);
    }

    inFile.close();
    cout << "Tasks loaded successfully.\n\n";
}

class TaskManager{
    public:
        string filename = "List.txt";
        string List;
        int MenuChoice;
        vector<Task> tasks;
        
        void displayMenu(){
            cout << "Welcome to Jamie's Organiser! \n\n";
            cout << " 1) View Tasks:\n\n2) Add Tasks:\n\n3) Mark Task as Complete:\n\n4) Delete Task:\n\n5) Save and Exit:";
        }

        void addTask(vector<Task>& tasks){
            Task newTask;

            cin.ignore();
            cout << "Please enter the task description:";
            getline(cin, newTask.description);

            newTask.completed = false;

            tasks.push_back(newTask);
            cout << "Task added. \n";
        }

        void viewTasks(vector<Task>& tasks){
            for (Task task: tasks){
                if (task.completed == true){
                    cout << "[X]" << task.description << endl;
                }
                else {
                    cout << "[ ]" << task.description << endl;
                }
            }
            cout << "\nPress Enter to return to the menu...";
            cin.ignore();
            cin.get();
        }

        void markTask(vector<Task>& tasks){
            int in;
            int n = tasks.size();
            cout << "Please select the task you would like to mark as finished: \n";
            cin >> in;
            if (in > n+1 || in < 1){
                cout << "Please pick a valid task: \n\n";
            }
            else {
                tasks[in-1].completed  = true;
            }
        }

        void deleteTask(vector<Task>& tasks){
            int del;
            int j = tasks.size();
            cout << "Please select the task you would like to delete: \n";
            cin >> del;
            if (del > j || del < 1){
                cout << "Please pick a valid task: \n\n";
                cin >> del;
            }
            else{
                tasks.erase(tasks.begin() + (del-1));
                cout << "Task" << del << "deleted. \n\n";
            }
        }

        void saveAndExit() {
            saveTasks(tasks, filename);
            cout << "Exiting program.\n";
        }
};



int main(){
    TaskManager taskObj;
    int choice = 0;
    loadTasks(taskObj.tasks, taskObj.filename);

    while (true) { //infinite loop ensures menu will always come back unless option 5 is selected (5 returns 0 and exits the function)2
        taskObj.displayMenu();
        cout << "\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                taskObj.viewTasks(taskObj.tasks);
                break;
            case 2:
                taskObj.addTask(taskObj.tasks);
                break;
            case 3:
                taskObj.markTask(taskObj.tasks);
                break;
            case 4:
                taskObj.deleteTask(taskObj.tasks);
                break;
            case 5:
                taskObj.saveAndExit();
                return 0;  // Exit the loop and end the program
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
