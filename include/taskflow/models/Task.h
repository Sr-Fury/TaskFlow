#pragma once

#include <string>

namespace taskflow
{

enum class TaskStatus
{
    Todo,
    InProgress,
    Completed
};

enum class TaskPriority
{
    Low,
    Medium,
    High,
    Critical
};

class Task
{
public:
    Task(int id,
         std::string title,
         std::string description,
         TaskPriority priority);

    int getId() const;
    const std::string& getTitle() const;
    const std::string& getDescription() const;

    TaskStatus getStatus() const;
    TaskPriority getPriority() const;

    void setStatus(TaskStatus status);
    void setPriority(TaskPriority priority);

private:
    int id_;
    std::string title_;
    std::string description_;

    TaskStatus status_;
    TaskPriority priority_;
};

} // namespace taskflow
