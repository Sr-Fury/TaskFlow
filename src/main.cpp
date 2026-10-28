#include "taskflow/models/Task.h"

#include <iostream>

int main()
{
    taskflow::Task task(
        1,
        "Learn CI/CD",
        "Implement the first GitHub Actions workflow",
        taskflow::TaskPriority::High
    );

    std::cout << "TaskFlow started!" << '\n';
    std::cout << "Task ID: " << task.getId() << '\n';
    std::cout << "Task title: " << task.getTitle() << '\n';

    return 0;
}