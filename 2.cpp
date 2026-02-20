//Fatemeh Ansari
//Samester 1 Project:
#include<stdio.h>
int main()
{
	char name[50][30];
	int studentID[50];
	float GPA[50];
	char major[50][30];
	int studentcount = 0;
	int choice;
	do
	{
		printf("\n***Student information management system***\n");
		printf("1)Registration of student information\n");
		printf("2)Search by student ID\n");
		printf("3)Edit student information\n");
		printf("4)Show all registered students\n");
		printf("5)Calculating the overall GPA\n");
		printf("6)Remove the student\n");
		printf("7)Exit\n");
		printf("Your choice: ");
		scanf_s("%d", &choice);
		if (choice == 1)
		{
			if (studentcount < 50)
			{
				printf("\n***Registering new student information***\n");
				printf("name of the student: ");
				scanf_s("%s",name[studentcount],30);
				printf(" student ID: ");
				scanf_s("%d", &studentID[studentcount]);
				printf("GPA: ");
				scanf_s("%f", &GPA[studentcount]);
				printf("name of the major: ");
				scanf_s("%s", major[studentcount],30);
				studentcount++;
				printf("Student successfully registered.\n");
			}
			else
			{
				printf("The capaciti is complete!you can register a maximum of 50 students.\n");
			}


		}
		else if (choice == 2)
		{
			int searchID, found = 0;
			printf("\nEnter the desired student ID: ");
			scanf_s("%d", &searchID);
			for (int i = 0; i < studentcount; i++)
			{
				if (studentID[i] == searchID)
				{
					printf("\n***Student information***\n");
					printf("name:%s\n", name[i]);
					printf("student ID:%d\n", studentID[i]);
					printf("GPA:%.2f\n", GPA[i]);
					printf("major:%s\n", major[i]);
					found = 1;
					break;
				}
			}
			if (!found)
			{
				printf("no student whit this ID was found!\n");
			}
		}
		else if (choice == 3)
		{
			int editID, found = 0;
			printf("\nstudent ID to edit: ");
			scanf_s("%d", &editID);
			for (int i = 0; i < studentcount; i++)
			{
				if (studentID[i] == editID)
				{
					printf("\ncurrent information:\n");
					printf("name:%s\n", name[i]);
					printf("GPA:%.2f\n", GPA[i]);
					printf("major:%s\n", major[i]);

					printf("\nnew name: ");
					scanf_s("%s", name[i],30);
					printf("\nnew GPA: ");
					scanf_s("%f", &GPA[i]);
					printf("\nnew major: ");
					scanf_s("%s", major[i],30);
					printf("\ninformation successfully edited.");
					found = 1;
					break;
				}
			}
			if (!found)
			{
				printf("no student with this ID was found!\n");
			}
		}
		else if (choice == 4)
		{
			if (studentcount > 0)
			{
				printf("\n***List of all students***\n");
				for (int i = 0; i < studentcount; i++)
				{
					printf("\n--student%d--\n", i + 1);
					printf("name:%s\n", name[i]);
					printf("student ID:%d\n", studentID[i]);
					printf("GPA:%.2f\n", GPA[i]);
					printf("major:%s\n", major[i]);
				}
			}
			else
			{
				printf("no students registered!");
			}
		}
		else if (choice == 5)
		{
			if (studentcount > 0)
			{
				float sum = 0, avg;
				for (int i = 0; i < studentcount; i++)
				{
					sum += GPA[i];
				}
				avg = sum / studentcount;
				printf("average GPA of all students: %.2f\n", avg);
			}
			else
			{
				printf("there are no students to calculate!\n");
			}
		}
		else if (choice == 6)
		{
			int deleteID, found = 0;
			printf("student ID to be deleted: \n");
			scanf_s("%d", &deleteID);
			for (int i = 0; i < studentcount; i++)
			{
				if (studentID[i] == deleteID)
				{
					for (int j = i; j < studentcount - 1; j++)
					{
						int k = 0;
						while (name[j + 1][k] != '\0')
						{
							name[j][k] = name[j + 1][k];
							k++;
						}
						name[j][k] = '\0';
						studentID[j] = studentID[j + 1];
						GPA[j] = GPA[j + 1];
						k = 0;
						while (major[j + 1][k] != '\0')
						{
							major[j][k] = major[j + 1][k];
							k++;
						}
						major[j][k] = '\0';
					}
					studentcount--;
					printf("student successfully deleted!\n");
					found = 1;
					break;
				}
			}
			if (!found)
			{
				printf("no studnt with this ID was found!\n");
			}
		}
		else if (choice == 7)
		{
			printf("\n***The program ended***\n");
		}
		else
		{
			printf("invalid selection!please try again.\n");
		}
	} while (choice != 7);
	return 0;
}