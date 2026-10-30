#include "taskflow/services/TaskManager.h"

#include <gtest/gtest.h>

namespace taskflow
{

TEST(TaskManagerTests, CreatesTasksWithUniqueIds)
{
    TaskManager manager;

    int firstId = manager.createTask(
        "First task",
        "Description one",
        TaskPriority::Low
    );

    int secondId = manager.createTask(
        "Second task",
        "Description two",
        TaskPriority::High
    );

    EXPECT_EQ(firstId, 1);
    EXPECT_EQ(secondId, 2);
}

TEST(TaskManagerTests, FindsExistingTask)
{
    TaskManager manager;

    int id = manager.createTask(
        "Learn CMake",
        "Understand CMake configuration",
        TaskPriority::High
    );

    const Task* task = manager.getTaskById(id);

    ASSERT_NE(task, nullptr);
    EXPECT_EQ(task->getTitle(), "Learn CMake");
}

TEST(TaskManagerTests, ReturnsNullptrForMissingTask)
{
    TaskManager manager;

    EXPECT_EQ(manager.getTaskById(999), nullptr);
}

TEST(TaskManagerTests, UpdatesTaskStatus)
{
    TaskManager manager;

    int id = manager.createTask(
        "Write tests",
        "Test TaskManager",
        TaskPriority::High
    );

    bool updated = manager.updateTaskStatus(
        id,
        TaskStatus::Completed
    );

    EXPECT_TRUE(updated);

    const Task* task = manager.getTaskById(id);

    ASSERT_NE(task, nullptr);
    EXPECT_EQ(task->getStatus(), TaskStatus::Completed);
}

TEST(TaskManagerTests, DoesNotUpdateMissingTask)
{
    TaskManager manager;

    EXPECT_FALSE(
        manager.updateTaskStatus(999, TaskStatus::Completed)
    );
}

TEST(TaskManagerTests, DeletesExistingTask)
{
    TaskManager manager;

    int id = manager.createTask(
        "Temporary task",
        "This task will be deleted",
        TaskPriority::Low
    );

    EXPECT_TRUE(manager.deleteTask(id));
    EXPECT_EQ(manager.getTaskById(id), nullptr);
    EXPECT_TRUE(manager.getAllTasks().empty());
}

TEST(TaskManagerTests, DoesNotDeleteMissingTask)
{
    TaskManager manager;

    EXPECT_FALSE(manager.deleteTask(999));
}

TEST(TaskManagerTests, ReturnsAllTasks)
{
    TaskManager manager;

    manager.createTask(
        "First task",
        "Description one",
        TaskPriority::Low
    );

    manager.createTask(
        "Second task",
        "Description two",
        TaskPriority::High
    );

    const std::vector<Task> tasks = manager.getAllTasks();

    ASSERT_EQ(tasks.size(), 2);
    EXPECT_EQ(tasks[0].getTitle(), "First task");
    EXPECT_EQ(tasks[1].getTitle(), "Second task");
}

} // namespace taskflow