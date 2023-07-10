#include <iostream>
#include "electricity_billing_system.hpp"

int main() 
{
    ElectricityBillingSystem system;

    // Register customers
    system.register_customer("John Doe", "john.doe@example.com", "12345", 0.15);
    system.register_customer("Jane Smith", "jane.smith@example.com", "67890", 0.12);

    // Input electricity consumption
    system.input_electricity_consumption("12345", 100.5);
    system.input_electricity_consumption("67890", 150.2);

    // Generate bills
    system.generate_bill("12345", 0.15);
    system.generate_bill("67890", 0.12);

    // Save bills to file
    system.save_bill_to_file("12345");
    system.save_bill_to_file("67890");

    return 0;
}