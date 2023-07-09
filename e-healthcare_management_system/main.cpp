#include <iostream>

#include "management_system.hpp"
#include <string>

int main()
{
    ManagementSystem health_system;

    health_system.register_doctor("Dr. John Doe", "Cardiology", 10, "johndoe@example.com");
    health_system.register_doctor("Dr. Jane Smith", "Dermatology", 8, "janesmith@example.com");

    health_system.register_patient("John Smith", "1990-01-01", "Male", "johnsmith@example.com");
    health_system.register_patient("Emily Johnson", "1985-03-15", "Female", "emilyjohnson@example.com");

    health_system.add_med_history_entry(0, "Hypertension", "Prescription medication", "Medicine A");
    health_system.add_med_history_entry(1, "Allergic reaction", "Antihistamine", "Medicine B");

    health_system.generate_report(0);
    health_system.generate_report(1);

    return 0;
}