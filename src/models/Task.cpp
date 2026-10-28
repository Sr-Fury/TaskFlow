#include "taskflow/models/Task.h"

#include <utility>

namespace taskflow
{

Task::Task(int id,
           std::string title,
           std::string description,
           TaskPriority priority)
    : id_(id),
      title_(std::move(title)),
      description_(std::move(description)),
      status_(TaskStatus::Todo),
      priority_(priority)
{
}

int Task::getId() const
{
    return id_;
}

const std::string& Task::getTitle() const
{
    return title_;
}

const std::string& Task::getDescription() const
{
    return description_;
}

TaskStatus Task::getStatus() const
{
    return status_;
}

TaskPriority Task::getPriority() const
{
    return priority_;
}

void Task::setStatus(TaskStatus status)
{
    status_ = status;
}

void Task::setPriority(TaskPriority priority)
{
    priority_ = priority;
}

} // namespace taskflow