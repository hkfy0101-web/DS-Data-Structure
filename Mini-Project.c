#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Task
{
    int id;
    char name[50];
    int completed;
    struct Task *next;
};

struct Task *head = NULL;

void addTask()
{
    struct Task *newTask;
    
    newTask = (struct Task *)malloc(sizeof(struct Task));

    printf("Enter Task ID: ");
    scanf("%d", &newTask->id);

    printf("Enter Task Name: ");
    scanf(" %[^\n]", newTask->name);

    newTask->completed = 0;
    newTask->next = NULL;

    if (head == NULL)
    {
        head = newTask;
    }
    else
    {
        struct Task *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newTask;
    }

    printf("Task added successfully!\n");
}

void displayTasks()
{
    struct Task *temp = head;

    if (head == NULL)
    {
        printf("No tasks available.\n");
        return;
    }

    printf("\n--- Task List ---\n");

    while (temp != NULL)
    {
        printf("ID: %d\n", temp->id);
        printf("Task: %s\n", temp->name);

        if (temp->completed == 1)
            printf("Status: Completed\n");
        else
            printf("Status: Pending\n");

        printf("-----------------\n");

        temp = temp->next;
    }
}


void searchTask()
{
    int id;
    struct Task *temp = head;

    printf("Enter Task ID to search: ");
    scanf("%d", &id);

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            printf("Task Found!\n");
            printf("Task: %s\n", temp->name);

            if (temp->completed)
                printf("Status: Completed\n");
            else
                printf("Status: Pending\n");

            return;
        }

        temp = temp->next;
    }

    printf("Task not found.\n");
}


void completeTask()
{
    int id;
    struct Task *temp = head;

    printf("Enter Task ID: ");
    scanf("%d", &id);

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            temp->completed = 1;
            printf("Task marked as completed!\n");
            return;
        }

        temp = temp->next;
    }

    printf("Task not found.\n");
}


void deleteTask()
{
    int id;
    struct Task *temp = head;
    struct Task *previous = NULL;

    printf("Enter Task ID to delete: ");
    scanf("%d", &id);

    while (temp != NULL)
    {
        if (temp->id == id)
        {
            if (previous == NULL)
                head = temp->next;
            else
                previous->next = temp->next;

            free(temp);

            printf("Task deleted successfully!\n");
            return;
        }

        previous = temp;
        temp = temp->next;
    }

    printf("Task not found.\n");
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n===== TO-DO TASK MANAGER =====\n");
        printf("1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. Display Tasks\n");
        printf("4. Search Task\n");
        printf("5. Mark Task Completed\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addTask();
                break;

            case 2:
                deleteTask();
                break;

            case 3:
                displayTasks();
                break;

            case 4:
                searchTask();
                break;

            case 5:
                completeTask();
                break;

            case 6:
                printf("Thank you!\n");
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}