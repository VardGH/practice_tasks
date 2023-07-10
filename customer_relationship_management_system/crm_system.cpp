#include "crm_system.hpp"

void CRMSystem::register_customer(const std::string& name, const std::string& contact_info) {
    Customer customer(name, contact_info);
    m_customers.push_back(customer);
    std::cout << "Customer registered successfully." << std::endl;
}

void CRMSystem::display_customer_details(const std::string& customer_name) const
{
    auto it = std::find_if(m_customers.begin(), m_customers.end(), [&](const Customer& customer) {
        return customer.get_name() == customer_name;
    });

    if (it != m_customers.end()) {
        const Customer& customer = *it;
        std::cout << "Customer Name: " << customer.get_name() << std::endl;
        std::cout << "Contact Info: " << customer.get_contact_info() << std::endl;
        std::cout << "Interaction History:\n";
        for (const Interaction* interaction : customer.get_interactions()) {
            //std::cout << "Date: " << std::asctime(std::localtime(&interaction->date));
            std::cout << "User: " << interaction->get_user() << std::endl;
            interaction->display_details();
            std::cout << std::endl;
        }
    } else {
        std::cout << "Customer not found." << std::endl;
    }
}

void CRMSystem::generate_snd_save_report(const std::string& customer_name) const
{
    auto it = std::find_if(m_customers.begin(), m_customers.end(), [&](const Customer& customer) {
        return customer.get_name() == customer_name;
    });

    if (it != m_customers.end()) {
        ReportGenerator::generate_report(*it);
    } else {
        std::cout << "Customer not found." << std::endl;
    }
}

void CRMSystem::add_interaction(const std::string& customer_name, Interaction* interaction)
{
    auto it = std::find_if(m_customers.begin(), m_customers.end(), [&](const Customer& customer) {
        return customer.get_name() == customer_name;
    });

    if (it != m_customers.end()) {
        it->add_interaction(interaction);
    } else {
        std::cout << "Customer not found." << std::endl;
    }
}