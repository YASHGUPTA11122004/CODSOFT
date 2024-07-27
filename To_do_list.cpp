#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task 
{
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask() 
{
    string description;
    cout << "Enter the task description: ";
    cin.ignore();
    getline(cin, description);
    tasks.push_back({description, false});
    cout << "Task added." << endl;
}

void viewTasks() 
{
    if (tasks.empty()) 
    {
        cout << "No tasks available." << endl;
        return;
    }

    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) 
    {
        cout << i + 1 << ". " << tasks[i].description << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << endl;
    }
}

void markTaskCompleted() 
{
    if (tasks.empty()) 
    {
        cout << "No tasks available to mark as completed." << endl;
        return;
    }

    size_t taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) 
    {
        cout << "Invalid task number." << endl;
    } 
    else 
    {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed." << endl;
    }
}

void removeTheTask() 
{
    if (tasks.empty()) 
    {
        cout << "No tasks available to remove." << endl;
        return;
    }

    size_t taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;

    if (taskNumber < 1 || taskNumber > tasks.size()) 
    {
        cout << "Invalid task number." << endl;
    } else 
    {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task removed." << endl;
    }
}

void showMenu() 
{
    cout << "\nTo-Do List Manager" << endl;
    cout << "1.  To Add The Task" << endl;
    cout << "2. View The Tasks" << endl;
    cout << "3. Mark The Task as Completed" << endl;
    cout << "4. Remove  The Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Choose an option: ";
}

int main() 
{
    int ch;

    while (true) 
    {
        showMenu();
        cin >> ch;

        switch (ch) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskCompleted();
                break;
            case 4:
                removeTheTask();
                break;
            case 5:
                cout << "Exiting To-Do List Manager. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}
