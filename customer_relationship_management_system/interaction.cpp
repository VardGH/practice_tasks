#include "interaction.hpp"

Interaction::Interaction(const std::string& user) 
    : m_user(user) 
{
    m_date = std::time(0);
}

std::time_t Interaction::get_data() const
{
    return m_date;
}

std::string Interaction::get_user() const
{
    return m_user;
}

Sale::Sale(const std::string& user, const double amount, const std::string& warranty_period)
    : Interaction(user)
    , m_amount(amount)
    , m_warranty_period(warranty_period)
{
}

double Sale::get_amount() const
{
    return m_amount;
}

std::string Sale::get_warranty_period() const
{
    return m_warranty_period;
}

void Sale::display_details() const 
{
    std::cout << "Amount: " << m_amount << std::endl;
    std::cout << "Warranty Period: " << m_warranty_period << std::endl;
}

WarrantyService::WarrantyService(const std::string& user, const Sale& sale, double service_cost)
    : Interaction(user)
    , m_sale(sale)
    , m_service_cost(service_cost) 
{
}

const Sale& WarrantyService::get_sale() const 
{
    return m_sale;
}

double WarrantyService::get_service_cost() const 
{
    return m_service_cost;
}

void WarrantyService::display_details() const 
{
    std::cout << "Sale Details:" << std::endl;
    m_sale.display_details();
    std::cout << "Service Cost: " << m_service_cost << std::endl;
}

Complaint::Complaint(const std::string& user, const Sale& sale, const std::string& description)
    : Interaction(user)
    , m_sale(sale)
    , m_description(description) 
{
}

const Sale& Complaint::get_sale() const 
{
    return m_sale;
}

std::string Complaint::get_description() const 
{
    return m_description;
}

void Complaint::display_details() const {
    std::cout << "Sale Details:" << std::endl;
    m_sale.display_details();
    std::cout << "Description: " << m_description << std::endl;
}