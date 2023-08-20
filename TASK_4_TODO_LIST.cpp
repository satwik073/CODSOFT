#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;
};

void displayTasks(const std::vector<Task>& tasks) {
    std::cout << "Tasks:" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << "[" << i + 1 << "] " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << std::endl;
    }
}

int main() {
    std::vector<Task> tasks;

    while (true) {
        std::cout << "To-Do List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Mark Task as Completed" << std::endl;
        std::cout << "4. Remove Task" << std::endl;
        std::cout << "5. Exit" << std::endl;

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string taskDescription;
                std::cout << "Enter task description: ";
                std::cin.ignore(); 
                std::getline(std::cin, taskDescription);
                tasks.push_back({taskDescription, false});
                std::cout << "Task added." << std::endl;
                break;
            }
            case 2:
                displayTasks(tasks);
                break;
            case 3: {
                displayTasks(tasks);
                int taskIndex;
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> taskIndex;
                if (taskIndex >= 1 && taskIndex <= tasks.size()) {
                    tasks[taskIndex - 1].completed = true;
                    std::cout << "Task marked as completed." << std::endl;
                } else {
                    std::cout << "Invalid task number." << std::endl;
                }
                break;
            }
            case 4: {
                displayTasks(tasks);
                int taskIndex;
                std::cout << "Enter task number to remove: ";
                std::cin >> taskIndex;
                if (taskIndex >= 1 && taskIndex <= tasks.size()) {
                    tasks.erase(tasks.begin() + taskIndex - 1);
                    std::cout << "Task removed." << std::endl;
                } else {
                    std::cout << "Invalid task number." << std::endl;
                }
                break;
            }
            case 5:
                std::cout << "Exiting." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Try again." << std::endl;
                break;
        }
    }

    return 0;
}
