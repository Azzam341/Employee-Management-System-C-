#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

// Function prototypes
void signUp();
void login();
void enterEmployeeData();
void searchEmployeeData(int id);
void deleteEmployeeData(int id);
void updateEmployeeData(int id);
void addEmployeeSalary();
void viewEmployeeSalary();
void updateEmployeeSalary();
void displayMenu();
void displayEmployeeData(const string& filename);
void calculateTaxes(double salary);
void addEmployeeSchedule();
void viewEmployeeSchedule();
void updateEmployeeSchedule();

int main() {
    int choice;

    // Ask the user if they want to sign up or log in
    cout << "Would you like to sign up (1) or log in (2)? ";
    cin >> choice;

    // Handle the user's choice
    if (choice == 1) {
        signUp();
    } else if (choice == 2) {
        login();
    } else {
        cout << "Invalid choice. Please enter either 1 for sign-up or 2 for log in." << endl;
    }

    return 0;
}

void signUp() {
    string username, password, choice, loginChoice;
    bool wantsToChange = true;

    // Loop to allow the user to change their details multiple times
    while (wantsToChange) {
        ofstream outfile("Password.txt"); // Open the file for writing (overwrite)

        if (!outfile) {
            cerr << "Error opening file for writing." << endl;
            return;
        }

        // Ask for sign-up details
        cout << "Please enter the sign-up details." << endl;
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;

        // Write the new username and password to the file
        outfile << username << " " << password << endl;
        outfile.close();

        cout << "Sign-up successful!" << endl;

        // Ask the user if they want to change their details
        cout << "Would you like to change your details? (Type 'Yes' to change or 'No' to stop): ";
        cin >> choice;

        // Check the user's response
        if (choice != "Yes" && choice != "yes") {
            wantsToChange = false;
        }
    }

    // After the user decides not to change their details
    // Ask if they would like to log in
    cout << "Would you like to log in now? (Type 'Yes' to log in or 'No' to exit): ";
    cin >> loginChoice;

    if (loginChoice == "Yes" || loginChoice == "yes") {
        // If the user wants to log in, call the login function
        login();
    }
}

void login() {
    string fileUsername, filePassword;
    string username, password;
    bool loggedIn = false;

    while (!loggedIn) {
        ifstream infile("Password.txt"); // Open the file for reading

        if (!infile) {
            cerr << "Error opening file for reading." << endl;
            return;
        }

        // Read the username and password from the file
        infile >> fileUsername >> filePassword;
        infile.close(); // Close the file

        // Ask for login details
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        // Check if the entered credentials match the stored ones
        if (username == fileUsername && password == filePassword) {
            cout << "You have logged in successfully!" << endl;
            loggedIn = true; // Set the flag to exit the loop
        } else {
            cout << "Login failed, try again..." << endl;
        }
    }

    // Once logged in, proceed to employee management system
    int menu_option;
    bool exit_program = false;

    // Menu loop
    while (!exit_program) {
        displayMenu(); // Display the menu options
        cout << "Enter your choice: ";
        cin >> menu_option;

        // Process the user's choice
        switch (menu_option) {
            case 1:
                enterEmployeeData();
                break;
            case 2: {
                int id;
                cout << "Enter employee ID: ";
                cin >> id;
                searchEmployeeData(id);
                break;
            }
            case 3: {
                int id;
                cout << "Enter employee ID to delete: ";
                cin >> id;
                deleteEmployeeData(id);
                break;
            }
            case 4: {
                int id;
                cout << "Enter employee ID to update: ";
                cin >> id;
                updateEmployeeData(id);
                break;
            }
            case 5:
                addEmployeeSalary();
                break;
            case 6:
                viewEmployeeSalary();
                break;
            case 7:
                updateEmployeeSalary();
                break;
            case 8:
                addEmployeeSchedule();
                break;
            case 9:
                viewEmployeeSchedule();
                break;
            case 10:
                updateEmployeeSchedule();
                break;
            case 11:
                cout << "Exiting the program..." << endl;
                exit_program = true;
                break;
            default:
                cout << "Invalid option. Please try again." << endl;
                break;
        }
    }
}

void enterEmployeeData() {
    string name, dob, maritalStatus, address, age, designation, mobileNo, email;
    int id, monthlyHours, overtimeHours, daysPresent, daysAbsent;
    double salary;

    // Prompt user for employee details
    cout << "Enter identification number: ";
    cin >> id;

    // Generate a filename using the employee ID and directory path
    string filename = "C:\\Users\\HP\\Desktop\\Employees\\employee_" + to_string(id) + ".txt";

    ofstream outfile(filename); // Open the file for writing

    if (!outfile.is_open()) {
        cerr << "Error: Unable to create file." << endl;
        return;
    }

    outfile << "ID: " << id << endl;

    cout << "Enter name: ";
    cin >> ws;  // Remove leading whitespace
    getline(cin, name);
    outfile << "Name: " << name << endl;

    cout << "Enter date of birth (DOB) (DD/MM/YYYY): ";
    cin >> dob;
    outfile << "DOB: " << dob << endl;

    cout << "Enter marital status: ";
    cin >> maritalStatus;
    outfile << "Marital Status: " << maritalStatus << endl;

    cout << "Enter address: ";
    cin >> ws;  // Remove leading whitespace
    getline(cin, address);
    outfile << "Address: " << address << endl;

    cout << "Enter age: ";
    cin >> age;
    outfile << "Age: " << age << endl;

    cout << "Enter designation: ";
    cin >> ws;  // Remove leading whitespace
    getline(cin, designation);
    outfile << "Designation: " << designation << endl;

    cout << "Enter monthly hours: ";
    cin >> monthlyHours;
    outfile << "Monthly Hours: " << monthlyHours << endl;

    cout << "Enter overtime hours: ";
    cin >> overtimeHours;
    outfile << "Overtime Hours: " << overtimeHours << endl;

    cout << "Enter days present: ";
    cin >> daysPresent;
    outfile << "Days Present: " << daysPresent << endl;

    cout << "Enter days absent: ";
    cin >> daysAbsent;
    outfile << "Days Absent: " << daysAbsent << endl;

    cout << "Enter mobile number: ";
    cin >> mobileNo;
    outfile << "Mobile No: " << mobileNo << endl;

    cout << "Enter email: ";
    cin >> email;
    outfile << "Email: " << email << endl;

    outfile.close(); // Close the file
}

void searchEmployeeData(int id) {
    string filename = "C:\\Users\\HP\\Desktop\\Employees\\employee_" + to_string(id) + ".txt";
    ifstream infile(filename); // Open the file for reading

    if (!infile.is_open()) {
        cerr << "Error: File not found." << endl;
        return;
    }

    string line;

    while (getline(infile, line)) {
        cout << line << endl;
    }

    infile.close(); // Close the file
}

void deleteEmployeeData(int id) {
    string filename = "C:\\Users\\HP\\Desktop\\Employees\\employee_" + to_string(id) + ".txt";

    // Check if the file exists before attempting to delete it
    ifstream infile(filename);
    if (!infile) {
        cerr << "Error: File not found." << endl;
        return;
    }
    infile.close();

    if (remove(filename.c_str()) != 0) {
        cerr << "Error deleting file." << endl;
    } else {
        cout << "File deleted successfully." << endl;
    }
}

void updateEmployeeData(int id) {
    // Delete the old employee data
    deleteEmployeeData(id);

    // Enter the updated data
    enterEmployeeData();
}

void addEmployeeSalary() {
    string id;
    double salary;

    cout << "Enter Employee ID: ";
    cin >> id;
    cout << "Enter Employee Salary: ";
    cin >> salary;

    // Generate filename based on employee ID
    string filename = "C:\\Users\\HP\\Desktop\\Employees\\employee_" + to_string(id) + ".txt";

    ofstream outfile(filename, ios::app);  // Open file in append mode

    if (outfile.is_open()) {
        outfile << "Salary: " << salary << endl;
        cout << "Employee salary added successfully." << endl;
        outfile.close();
    } else {
        cout << "Unable to open file!" << endl;
    }
}


void viewEmployeeSalary() {string id;
    cout << "Enter Employee ID: ";
    cin >> id;
// Generate a filename using the employee ID and directory path

    string filename = "C:\\Users\\HP\\Desktop\\Employees\\employee_" + to_string(id) + ".txt";


    ifstream infile(filename);
    if (file.is_open())
    {
        string line;
        bool found = false;
        while (getline(file, line))
        {
            if (line.find(id) != string::npos)
            {
                found = true;
                cout << "Employee Salary: " << line << endl;
            }
        }
        if (!found)
        {
            cout << "Salary not found for employee with ID: " << id << endl;
        }
    }
    else
    {
        cout << "Unable to open file!" << endl;
    }
    file.close();
    // Code to view employee salary
    // Implement your logic here
}

void updateEmployeeSalary() {
    string id;
    double newSalary;

    cout << "Enter Employee ID to update salary: ";
    cin >> id;

    string filename = "C:\\Users\\HP\\Desktop\\Employees\\employee_" + to_string(id) + ".txt";
    string tempFilename = "C:\\Users\\HP\\Desktop\\Employees\\employee_" + to_string(id) + "_temp.txt";

    ifstream infile(filename);
    ofstream outfile(tempFilename);

    if (!infile.is_open() || !outfile.is_open()) {
        cout << "Unable to open file!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(infile, line)) {
        if (line.find("Salary:") != string::npos) {
            found = true;
            cout << "Enter new Salary: ";
            cin >> newSalary;
            outfile << "Salary: " << newSalary << endl;
        } else {
            outfile << line << endl;
        }
    }

    if (found) {
        cout << "Employee salary updated successfully." << endl;
        infile.close();
        outfile.close();

        remove(filename.c_str());  // Delete the original file
        rename(tempFilename.c_str(), filename.c_str());  // Rename the temp file
    } else {
        cout << "Employee not found with ID: " << id << endl;
    }
}


void displayMenu() {
    cout << "\n===== Employee Management System =====" << endl;
    cout << "1. Enter employee data" << endl;
    cout << "2. Search employee data" << endl;
    cout << "3. Delete employee data" << endl;
    cout << "4. Update employee data" << endl;
    cout << "5. Add employee salary" << endl;
    cout << "6. View employee salary" << endl;
    cout << "7. Update employee salary" << endl;
    cout << "8. Add employee schedule" << endl;
    cout << "9. View employee schedule" << endl;
    cout << "10. Update employee schedule" << endl;
    cout << "11. Exit" << endl;
}

void addEmployeeSchedule() {
    int id;
    cout << "Enter Employee ID: ";
    cin >> id;

    string filename = "C:\\Users\\HP\\Desktop\\Employees\\employee_" + to_string(id) + "_schedule.txt";

    ofstream outfile(filename);

    if (!outfile.is_open()) {
        cout << "Error opening file for schedule." << endl;
        return;
    }

    string schedule;
    cout << "Enter Employee Schedule: ";
    cin >> ws;  // Remove leading whitespace
    getline(cin, schedule);

    outfile << "Schedule: " << schedule << endl;
    cout << "Employee schedule added successfully." << endl;

    outfile.close();
}

void updateEmployeeSchedule() {
    int id;
    cout << "Enter Employee ID to update schedule: ";
    cin >> id;

    // Generate a filename using the employee ID and directory path
    string filename = "C:\\Users\\HP\\Desktop\\Employees\\employee_" + to_string(id) + "_schedule.txt";

    ofstream outfile(filename); // Open the file for writing (overwrite mode)
    ifstream infile(filename); // Open the file for reading

    if (!outfile.is_open() || !infile.is_open())
    {
        cerr << "Error: Unable to open file. Employee schedule not found." << endl;
        return;
    }

    string newSchedule;
    cout << "Enter new Employee Schedule: ";
    cin >> ws;  // Remove leading whitespace
    getline(cin, newSchedule);

    outfile << "Schedule: " << newSchedule << endl;
    outfile.close();

    cout << "Employee schedule updated successfully." << endl;
    // Code to update employee schedule
    // Implement your logic here
}

void updateEmployeeSalary() {
    string id;
    double newSalary;

    cout << "Enter Employee ID to update salary: ";
    cin >> id;

    string filename = "C:\\Users\\HP\\Desktop\\Employees\\employee_" + id + ".txt";
    string tempFilename = "C:\\Users\\HP\\Desktop\\Employees\\temp.txt";

    ifstream infile(filename);
    ofstream outfile(tempFilename);

    if (!infile.is_open() || !outfile.is_open()) {
        cerr << "Error opening file(s)!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(infile, line)) {
        if (line.find("Salary:") != string::npos) {
            found = true;
            cout << "Current Salary: " << line.substr(8) << endl;
            cout << "Enter New Salary: ";
            cin >> newSalary;
            outfile << "Salary: " << newSalary << endl;
        } else {
            outfile << line << endl;
        }
    }

    infile.close();
    outfile.close();

    if (found) {
        remove(filename.c_str());
        rename(tempFilename.c_str(), filename.c_str());
        cout << "Salary updated successfully.\n";
    } else {
        remove(tempFilename.c_str());
        cerr << "Salary not found for Employee ID: " << id << endl;
    }
}


