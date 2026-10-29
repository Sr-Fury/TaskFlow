#pragma once

#include "taskflow/models/Task.h"

#include <vector>

namespace taskflow
{

class TaskManager
{
public:
    int createTask(
        const std::string& title,
        const std::string& description,
        TaskPriority priority
    );

    const Task* getTaskById(int id) const;

    bool updateTaskStatus(int id, TaskStatus status);

    bool deleteTask(int id);

    std::vector<Task> getAllTasks() const;

private:
    std::vector<Task> tasks_;
    int nextId_ = 1;
};

} // namespace taskflow