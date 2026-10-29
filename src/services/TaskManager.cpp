#include "taskflow/services/TaskManager.h"

#include <algorithm>
#include <utility>

namespace taskflow
{

int TaskManager::createTask(
    const std::string& title,
    const std::string& description,
    TaskPriority priority
)
{
    const int id = nextId_++;

    tasks_.emplace_back(
        id,
        title,
        description,
        priority
    );

    return id;
}

const Task* TaskManager::getTaskById(int id) const
{
    const auto it = std::find_if(
        tasks_.begin(),
        tasks_.end(),
        [id](const Task& task)
        {
            return task.getId() == id;
        }
    );

    if (it == tasks_.end())
    {
        return nullptr;
    }

    return &(*it);
}

bool TaskManager::updateTaskStatus(int id, TaskStatus status)
{
    const auto it = std::find_if(
        tasks_.begin(),
        tasks_.end(),
        [id](const Task& task)
        {
            return task.getId() == id;
        }
    );

    if (it == tasks_.end())
    {
        return false;
    }

    it->setStatus(status);
    return true;
}

bool TaskManager::deleteTask(int id)
{
    const auto it = std::find_if(
        tasks_.begin(),
        tasks_.end(),
        [id](const Task& task)
        {
            return task.getId() == id;
        }
    );

    if (it == tasks_.end())
    {
        return false;
    }

    tasks_.erase(it);
    return true;
}

std::vector<Task> TaskManager::getAllTasks() const
{
    return tasks_;
}

} // namespace taskflow