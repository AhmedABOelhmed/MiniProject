/*
 ============================================================================
 Name        : Project.c
 Author      : Ahmed_Aboelhmed
 Description : The Student Management System is a C program designed to manage student information efficiently
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

// Define a structure for student data
struct student{
    int id ;
    char name[50];
    int age ;
    float gpa ;
};


// Define a node structure for linked list
struct node{
    struct student data ;
    struct node *next ;
};



// Initialize head and current pointers
struct node *head = NULL ;
struct node *current = NULL ;

// Function to add a student to the linked list
void addstudent(const struct student *const ptr)
{
    // Allocate memory for a new node
    struct node *link = (struct node *)malloc(sizeof(struct node));

    if(link == NULL)
    {
    	printf("Memory allocation failed.\n");
        return ;
    }

    // Copy student data to the new node and set next to NULL
    link->data= *ptr ;
    link->next = NULL ;

    // If the list is empty, set the new node as head
    if(head == NULL)
    {
        head = link ;
        return ;
    }

    current = head ;
    while(current != NULL)
    {
    	// Check for duplicate ID
        if(ptr->id == current->data.id)
        {
            printf("This ID is Already reserved.\n");
            free(link);
            return ;
        }
        current = current->next ;
    }

    // Traverse to the end of the list and add the new node
    current = head ;
    while(current->next != NULL)
    {
        current = current->next ;
    }
    current->next = link ;


}
// Function to display all students in the list
void display(void)
{
	// check if the list is empty
    if(head == NULL)
    {
    	printf("Empty linked list.\n");
    	return;
    }


    // Traverse the list and print each student's details
    current = head ;
    while(current != NULL)
    {
        printf("[ ID: %d, Name: %s, Age: %d, GPA: %f ]\n",current->data.id,current->data.name,current->data.age,current->data.gpa);
        current = current->next ;
    }

}

// Function to search for a student by ID
void searchStudentByID(int id)
{
    current = head ;

    while(current != NULL)
    {
    	// If a matching ID is found, print the student's details
        if(id == current->data.id)
        {
            printf("Student found:\n");
            printf("[ ID: %d, Name: %s, Age: %d, GPA: %f ]\n",current->data.id,current->data.name,current->data.age,current->data.gpa);
            return ;
        }
        current = current->next ;
    }

    // If no matching ID is found, print a message
    printf("Student with ID %d not found.\n",id);

}

// Function to update a student's information
void updateStudent(int id){
    current = head ;

    while(current != NULL)
    {
        // If a matching ID is found, prompt the user to enter new details
        if(id == current->data.id)
        {
            printf("Enter new details for the student with ID: %d\n",id);

            printf("Enter new name: ");
            scanf("%s",current->data.name);

            printf("Enter new Age: ");
            scanf("%d",&current->data.age);

            printf("Enter new GPA: ");
            scanf("%f",&current->data.gpa);
            printf("Student detalis updated successfully.\n");
            return ;
        }
        current = current->next ;
    }

    // If no matching ID is found, print a message
    printf("Student with ID %d not found.\n",id);
}

// Function to delete a student by ID
void deleteStudent(int id)
{
	struct node *prev = NULL , *temp = NULL ;

	// Check if the list is empty
    if(head == NULL)
    {
        printf("Student with ID %d not found.\n",id);
        return ;
    }
    prev = head ;
    temp = head->next ;

    // If the student to be deleted is the head
    if(head->data.id == id)
    {
        prev = prev->next ;
        free(head);
        head = prev ;
        printf("Student with ID %d deleted successfully.\n", id);
        return ;
    }


    // Traverse the list to find the student to be deleted
    while(temp != NULL)
    {
        if(id == temp->data.id)
        {
        	// Remove the node from the list and free its memory
            prev->next = temp->next ;
            free(temp);
            printf("Student with ID %d deleted successfully.\n", id);
            return ;
        }
        prev = prev->next ;
        temp = temp->next ;
    }

    // If no matching ID is found, print a message
    printf("Student with ID %d not found.\n",id);
}

// Function to calculate the average GPA of all students
float calculateAverageGPA(void)
{

    int size = 0 ;
    float sum = 0.0 , average = 0.0;

    // check if the list is empty
    if(head == NULL)
    {
        printf("Empty linked list.\n");
        return 0 ;
    }

    // Traverse the list and calculate the sum of GPAs
    current = head ;
    while(current != NULL)
    {
        sum = sum + current->data.gpa ;
        current = current->next ;
        size++;
    }
  /*  if(size == 1)
    {
    	average = head->data.gpa ;
    	return average ;
    }*/
    average = sum / size ;

    // Return the average GPA
    return average ;
}

// Function to find the student with the highest GPA
void searchHighestGPA(void)
{
	// check if the list is empty
    if(head == NULL)
    {
        printf("Empty linked list.\n");
        return ;
    }

    current = head ;
    struct node *HighestGPA = head ;

    // Traverse the list to find the student with the highest GPA
    while(current != NULL)
    {
        if(HighestGPA->data.gpa < current->data.gpa)
        {
            HighestGPA = current ;
        }
        current = current->next ;
    }

    // Print the details of the student with the highest GPA
    printf("Student with the highest GPA:\n");
    printf("[ ID: %d, Name: %s, Age: %d, GPA: %f ]\n",HighestGPA->data.id,HighestGPA->data.name,HighestGPA->data.age,HighestGPA->data.gpa);

}

// Main function
int main() {
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);

    float average ;
    int number = 0 ;
    int SearchId = 0 ;
    int updateID = 0 ;
    int deleteData = 0;
    struct student s  ;



    do{
    	// Display menu options
        printf("1. Add Student\n");
        printf("2. Display Student\n");
        printf("3. search Student by ID\n");
        printf("4. Update Student Information\n");
        printf("5. Delete Student\n");
        printf("6. calculate Average GPA\n");
        printf("7. Search for student with Highest GPA\n");
        printf("8. Exit\n");

        // Get user's choice
        printf("Enter choice: ");
        scanf("%d",&number);
        printf("---------------------------------------\n");

        // Process user's choice
        switch(number)
        {
            case 1:
            	// Add a new student
                printf("Enter student ID: ");
                scanf("%d",&s.id);

            	printf("Enter name: ");
                scanf("%s",s.name);

                printf("Enter age: ");
                scanf("%d",&s.age);

                printf("Enter GPA: ");
                scanf("%f",&s.gpa);

                addstudent(&s);    // Add student to the list
                printf("---------------------------------------\n");
            break ;
            case 2:
            	// Display all students
                display();
                printf("---------------------------------------\n");
            break ;
            case 3:
            	// Search for a student by ID
                printf("Enter Student ID to search: ");
                scanf("%d",&SearchId);
                searchStudentByID(SearchId);
                printf("---------------------------------------\n");
            break ;
            case 4:
            	// Update a student's information
                printf("Enter Student ID to update it's information : ");
                scanf("%d",&updateID);
                updateStudent(updateID);
                printf("---------------------------------------\n");
            break ;
            case 5:
            	// Delete a student by ID
                printf("Enter Student ID to Delete it's Data : ");
                scanf("%d",&deleteData);
                deleteStudent(deleteData);
                printf("---------------------------------------\n");
            break ;
            case 6:
            	// Calculate and display the average GPA
                average = calculateAverageGPA();
                printf("Average GPA = %f\n",average);
                printf("---------------------------------------\n");
            break ;
            case 7:
            	// Find and display the student with the highest GPA
                searchHighestGPA();
                printf("---------------------------------------\n");
            break;
            case 8:
            	// Exit the program
                printf("Exiting.....\n");
            break;
            default:
            	// Handle invalid input
                printf("Invalid choice. Try again.\n");
                printf("---------------------------------------\n");
        }


    }while(number != 8);

    return 0;
}




