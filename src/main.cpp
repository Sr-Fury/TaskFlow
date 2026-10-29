#include "taskflow/services/TaskManager.h"

#include <iostream>

int main()
{
    taskflow::TaskManager manager;

    const int firstId = manager.createTask(
        "Learn CI/CD",
        "Build the first GitHub Actions pipeline",
        taskflow::TaskPriority::High
    );

    const int secondId = manager.createTask(
        "Implement unit tests",
        "Test TaskManager functionality",
        taskflow::TaskPriority::Critical
    );

    std::cout << "TaskFlow started!\n\n";

    for (const taskflow::Task& task : manager.getAllTasks())
    {
        std::cout << "ID: " << task.getId() << '\n';
        std::cout << "Title: " << task.getTitle() << '\n';
        std::cout << '\n';
    }

    manager.updateTaskStatus(
        firstId,
        taskflow::TaskStatus::InProgress
    );

    std::cout << "First task updated: "
              << (manager.getTaskById(firstId) != nullptr)
              << '\n';

    manager.deleteTask(secondId);

    std::cout << "Remaining tasks: "
              << manager.getAllTasks().size()
              << '\n';

    return 0;
}