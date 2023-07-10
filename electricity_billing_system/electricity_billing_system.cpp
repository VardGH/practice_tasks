#include "electricity_billing_system.hpp"

void ElectricityBillingSystem::register_customer(const std::string& name, const std::string& contact_info, const std::string& meter_number, const double rate_per_unit)
{   
    Customer customer(name, contact_info, meter_number);
    m_customers.push_back(Customer(name, contact_info, meter_number));

    m_bills.push_back(Bill(customer, rate_per_unit));

    std::cout << "Customer registered successfully!" << std::endl;
}

Bill* ElectricityBillingSystem::find_pending_bill_by_meter_number(const std::string& meter_number) {
    for (Bill& bill : m_bills) {
        if (bill.get_customer().get_meter_number() == meter_number && bill.get_consumption() == 0.0) {
            return &bill;
        }
    }
    return nullptr;
}

Bill* ElectricityBillingSystem::find_generated_bill_by_meter_number(const std::string& meter_number) {
    for (Bill& bill : m_bills) {
        if (bill.get_customer().get_meter_number() == meter_number && bill.get_total_amount() == 0.0) {
            return &bill;
        }
    }
    return nullptr;
}

Bill* ElectricityBillingSystem::find_generated_bill(const std::string& meter_number) {
    for (Bill& bill : m_bills) {
        if (bill.get_customer().get_meter_number() == meter_number && bill.get_total_amount() != 0.0) {
            return &bill;
        }
    }
    return nullptr;
}

void ElectricityBillingSystem::input_electricity_consumption(const std::string& meter_number, const double consumption) {
    Bill* bill = find_pending_bill_by_meter_number(meter_number);
    if (bill != nullptr) {
        bill->set_consumption(consumption);
        std::cout << "Electricity consumption recorded successfully!" << std::endl;
    } else {
        std::cerr << "Error: No pending bill found for the customer with the given meter number." << std::endl;
    }
}

void ElectricityBillingSystem::generate_bill(const std::string& meter_number, const double rate_per_unit) {
    Bill* bill = find_generated_bill_by_meter_number(meter_number);
    if (bill != nullptr) {
        bill->set_rate_per_unit(rate_per_unit);
        bill->calculate_total_amount();
        bill->generate_bill();
        std::cout << "Bill generated successfully!" << std::endl;
    } else {
        std::cerr << "Error: No pending consumption found for the customer with the given meter number." << std::endl;
    }
}

void ElectricityBillingSystem::save_bill_to_file(const std::string& meter_number) {
    Bill* bill = find_generated_bill(meter_number);
    if (bill != nullptr) {
        bill->save_bill_to_file();
    } else {
        std::cerr << "Error: No bill found for the customer with the given meter number." << std::endl;
    }
}
