#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class TaskManager{
    public:
        string List;
        int MenuChoice;
        vector<Task> tasks;
        
        void displayMenu(){
            cout << "/nWelcome to Jamie's Organiser! \n\n";
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
                tasks[in-1].completed  == true;
            }
        }

        void deleteTask(vector<Task>& tasks){
            int del;
            int j = tasks.size();
            cout << "Please select the task you would like to delete: \n";
            cin >> del;
            if (del > j+1 || del < 1){
                cout << "Please pick a valid task: \n\n";
            }
            else{
                tasks.erase(tasks.begin() + (del-1));
                cout << "Task" << del << "deleted. \n\n";
            }
        }

        void saveTasks(vector<Task>& tasks, string& List){
            ofstream outFile(List);

            if (!outFile){
                cout << "Error saving file.\n\n";
            }

            for (const auto& task: tasks){
                outFile << task.description << "\n" << task.completed << "\n";
            }

            outFile.close();
            cout << "Tasks saved. \n\n";
        }
        

        
};



int main(){
    int choice;
    vector<Task> tasks;
    string List;
    TaskManager taskObj;

    taskObj.displayMenu();
    cin >> choice;

    switch (choice){
        case 1:
            taskObj.viewTasks(tasks);
            break;
        case 2:
            taskObj.addTask(tasks);
            break;
        case 3:
            taskObj.markTask(tasks);
            break;
        case 4:
            taskObj.deleteTask(tasks);
            break;
        case 5:
            cout << "Saved.\n\n";
            break;
    }
    void saveTasks(vector<Task>& tasks, string& List);
return 0;
}
