#include <iostream>

#include "crm_system.hpp"

int main() 
{
    CRMSystem crm;

    // Register customers
    crm.register_customer("John Doe", "john.doe@example.com");
    crm.register_customer("Jane Smith", "jane.smith@example.com");

    // Add interactions
    Sale* sale = new Sale("John Doe", 100.0, "1 year");
    crm.add_interaction("John Doe", sale);

    Sale* sale1 = new Sale("Jane Smith", 100.0, "1 year");
    crm.add_interaction("Jane Smith", new Complaint("Jane", *sale1, "Product not working"));
    
    crm.add_interaction("John Doe", new WarrantyService("John", *sale, 50.0));


    // Display customer details
    crm.display_customer_details("John Doe");
    std::cout << std::endl;
    crm.display_customer_details("Jane Smith");
    std::cout << std::endl;

    // Generate and save reports
    crm.generate_snd_save_report("John Doe");
    std::cout << std::endl;
    crm.generate_snd_save_report("Jane Smith");

    return 0;
}
