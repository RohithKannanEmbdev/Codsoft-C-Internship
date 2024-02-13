#include <iostream>
#include <vector>
using namespace std;

struct Task 
{
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList 
{
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) 
	{
        tasks.push_back(Task(description));
        cout << "Task added: " << description << endl;
    }

    void viewTasks() 
	{
        if (tasks.empty())
		{
            cout << "No tasks in the list.\n";
        } 
		else 
		{
            cout << "Tasks:\n";
            for (size_t i = 0; i < tasks.size(); ++i) 
			{
                cout << i + 1 << ". " << (tasks[i].completed ? "[Completed] " : "[Pending] ") << tasks[i].description << endl;
            }
        }
    }

    void markTaskAsCompleted(int index) 
	{
        if (index >= 1 && index <= static_cast<int>(tasks.size())) 
		{
            tasks[index - 1].completed = true;
            cout << "Task marked as completed: " << tasks[index - 1].description << endl;
        } 
		else 
		{
            cout << "Invalid task index.\n";
        }
    }

    void removeTask(int index) 
	{
        if (index >= 1 && index <= static_cast<int>(tasks.size())) 
		{
            cout << "Task removed: " << tasks[index - 1].description << endl;
            tasks.erase(tasks.begin() + index - 1);
        } 
		else 
		{
            cout << "Invalid task index.\n";
        }
    }
};

int main() 
{
    ToDoList toDoList;
    int choice;

    do 
	{
        cout << "--- ToDo List Manager ---\n\n";
        cout << "  1. Add Task\n";
        cout << "  2. View Tasks\n";
        cout << "  3. Mark Task as Completed\n";
        cout << "  4. Remove Task\n";
        cout << "  0. Exit\n";
        cout << "  Enter your choice: ";
        cin >> choice;

        switch (choice)
		{
            case 1: 
			{
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                toDoList.addTask(taskDescription);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: 
			{
                int taskIndex;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> taskIndex;
                toDoList.markTaskAsCompleted(taskIndex);
                break;
            }
            case 4: 
			{
                int taskIndex;
                cout << "Enter the index of the task to remove: ";
                cin >> taskIndex;
                toDoList.removeTask(taskIndex);
                break;
            }
            case 0:
                cout << "Exiting the ToDo List Manager.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 0);
}

