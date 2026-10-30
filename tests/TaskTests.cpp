#include "taskflow/models/Task.h"

#include <gtest/gtest.h>

namespace taskflow
{

TEST(TaskTests, ConstructorInitializesProperties)
{
    Task task(
        1,
        "Learn CI/CD",
        "Create automated tests",
        TaskPriority::High
    );

    EXPECT_EQ(task.getId(), 1);
    EXPECT_EQ(task.getTitle(), "Learn CI/CD");
    EXPECT_EQ(task.getDescription(), "Create automated tests");

    EXPECT_EQ(task.getPriority(), TaskPriority::High);
    EXPECT_EQ(task.getStatus(), TaskStatus::Todo);
}

TEST(TaskTests, StatusCanBeUpdated)
{
    Task task(
        1,
        "Learn CI/CD",
        "Create automated tests",
        TaskPriority::High
    );

    task.setStatus(TaskStatus::InProgress);

    EXPECT_EQ(task.getStatus(), TaskStatus::InProgress);
}

TEST(TaskTests, PriorityCanBeUpdated)
{
    Task task(
        1,
        "Learn CI/CD",
        "Create automated tests",
        TaskPriority::Medium
    );

    task.setPriority(TaskPriority::Critical);

    EXPECT_EQ(task.getPriority(), TaskPriority::Critical);
}

} // namespace taskflow