#include <stdio.h>
#include <string.h>

#define SIZE 100

// Patient structure
struct patient {
    int id;
    char name[50];
    int age;
    char disease[50];
};

// Billing structure
struct bill {
    int id;
    float amount;
};

// Discharge structure
struct discharge {
    int id;
    char summary[100];
};

// Arrays
struct patient list[SIZE];
struct bill bills[SIZE];
struct discharge discharges[SIZE];

int count = 0;       // Patient count
int billCount = 0;   // Billing count
int discCount = 0;   // Discharge count

// Emergency stack
int stack[SIZE];
char priority[SIZE][10];
int top = -1;

// Function declarations
void add();
void show();
void emergency();
void treat();
void showStack();
void generateBill();
void showBills();
void dischargePatient();
void showDischarges();
void menu();

int main() {
    int choice;
    while (1) {
        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: add(); break;
            case 2: show(); break;
            case 3: emergency(); break;
            case 4: treat(); break;
            case 5: showStack(); break;
            case 6: generateBill(); break;
            case 7: showBills(); break;
            case 8: dischargePatient(); break;
            case 9: showDischarges(); break;
            case 10: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}

void menu() {
    printf("\n=== Hospital Menu ===\n");
    printf("1. Add Patient\n");
    printf("2. Show All Patients\n");
    printf("3. Emergency Entry\n");
    printf("4. Treat Emergency\n");
    printf("5. Show Emergency Stack\n");
    printf("6. Generate Bill\n");
    printf("7. Show All Bills\n");
    printf("8. Discharge Patient\n");
    printf("9. Show Discharge Summaries\n");
    printf("10. Exit\n");
}

void add() {
    if (count >= SIZE) {
        printf("Patient list full!\n");
        return;
    }
    list[count].id = 1000 + count;
    printf("Enter Name: ");
    scanf(" %[^\n]", list[count].name);
    printf("Enter Age: ");
    scanf("%d", &list[count].age);
    printf("Enter Disease: ");
    scanf(" %[^\n]", list[count].disease);
    printf("Patient added with ID: %d\n", list[count].id);
    count++;
}

void show() {
    if (count == 0) {
        printf("No patients found.\n");
        return;
    }
    printf("\n--- Patient List ---\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d | Name: %s | Age: %d | Disease: %s\n",
               list[i].id, list[i].name, list[i].age, list[i].disease);
    }
}

void emergency() {
    if (top == SIZE - 1) {
        printf("Emergency stack full!\n");
        return;
    }
    int id;
    char level[10];
    printf("Enter Emergency Patient ID: ");
    scanf("%d", &id);
    printf("Enter Priority (High/Medium/Low): ");
    scanf(" %[^\n]", level);
    stack[++top] = id;
    strcpy(priority[top], level);
    printf("Emergency patient added with priority: %s\n", level);
}

void treat() {
    if (top == -1) {
        printf("No emergency cases.\n");
        return;
    }
    printf("Treating Patient ID: %d | Priority: %s\n", stack[top], priority[top]);
    top--;
}

void showStack() {
    if (top == -1) {
        printf("No emergency cases.\n");
        return;
    }
    printf("\n--- Emergency Stack ---\n");
    for (int i = top; i >= 0; i--) {
        printf("ID: %d | Priority: %s\n", stack[i], priority[i]);
    }
}

void generateBill() {
    if (billCount >= SIZE) {
        printf("Billing list full!\n");
        return;
    }
    int id;
    float amount;
    printf("Enter Patient ID for billing: ");
    scanf("%d", &id);
    printf("Enter Amount: ₹");
    scanf("%f", &amount);
    bills[billCount].id = id;
    bills[billCount].amount = amount;
    billCount++;
    printf("Bill generated for Patient ID %d: ₹%.2f\n", id, amount);
}

void showBills() {
    if (billCount == 0) {
        printf("No bills found.\n");
        return;
    }
    printf("\n--- Billing Records ---\n");
    for (int i = 0; i < billCount; i++) {
        printf("Patient ID: %d | Amount: ₹%.2f\n", bills[i].id, bills[i].amount);
    }
}

void dischargePatient() {
    if (discCount >= SIZE) {
        printf("Discharge list full!\n");
        return;
    }
    int id;
    printf("Enter Patient ID to discharge: ");
    scanf("%d", &id);
    printf("Enter Discharge Summary: ");
    scanf(" %[^\n]", discharges[discCount].summary);
    discharges[discCount].id = id;
    discCount++;
    printf("Discharge summary saved for Patient ID %d\n", id);
}

void showDischarges() {
    if (discCount == 0) {
        printf("No discharge summaries found.\n");
        return;
    }
    printf("\n--- Discharge Summaries ---\n");
    for (int i = 0; i < discCount; i++) {
        printf("Patient ID: %d | Summary: %s\n", discharges[i].id, discharges[i].summary);
    }
}