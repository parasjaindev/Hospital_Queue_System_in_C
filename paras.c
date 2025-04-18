#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100
struct Patient {
 char name[50];
 int age;
};
struct Patient queue[SIZE];
int front = -1, rear = -1;
// Function to add a patient
void addPatient() {
 if (rear == SIZE - 1) {
 printf("\nQueue is full! Cannot add more patients.\n");
 return;
 }
 if (front == -1) {
 front = 0;
 }
 rear++;
 printf("\nEnter patient's name: ");
 fflush(stdin); // Use this to clear input buffer in Turbo C
 scanf("%s", queue[rear].name); // Avoids gets()
 printf("Enter patient's age: ");
 scanf("%d", &queue[rear].age);
 printf("Patient added successfully!\n");
}
// Function to serve the next patient
void servePatient() {
 if (front == -1 || front > rear) {
 printf("\nNo patients in the queue to serve.\n");
 return;
 }
 printf("\nServing Patient:\n");
 printf("Name: %s\n", queue[front].name);
 printf("Age: %d\n", queue[front].age);
 front++;
 if (front > rear) {
 front = rear = -1;
 }
}
// Function to display all patients in queue
void displayQueue() {
 if (front == -1 || front > rear) {
 printf("\nNo patients in the queue.\n");
 return;
 }
 printf("\n--- Current Patients in Queue ---\n");
 for (int i = front; i <= rear; i++) {
 printf("Name: %s, Age: %d\n", queue[i].name, queue[i].age);
 }
}
int main() {
 int choice;
 while (1) {
 printf("\n===== Hospital Queue Menu =====\n");
 printf("1. Add Patient\n");
 printf("2. Serve Patient\n");
 printf("3. Display Queue\n");
 printf("0. Exit\n");
 printf("Enter your choice: ");
 scanf("%d", &choice);
 switch (choice) {
 case 1:
 addPatient();
 break;
 case 2:
 servePatient();
 break;
 case 3:
 displayQueue();
 break;
 case 0:
 printf("\nExiting program. Thank you!\n");
 exit(0);
 default:
 printf("\nInvalid choice! Please try again.\n");
 }
 }
 return 0;
}
