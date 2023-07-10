#pragma once

#include <iostream>
#include <string>
#include <ctime>

class Interaction
{
public:
    Interaction(const std::string& user);
    virtual ~Interaction() {}

public:
    virtual void display_details() const = 0;

    std::string get_user() const;
    std::time_t get_data() const;

protected:
    std::string m_user;
    std::time_t m_date;
};

class Sale : public Interaction 
{
public:
    Sale(const std::string& user, const double amount, const std::string& warranty_period);

public:
    void display_details() const override;

    double get_amount() const;
    std::string get_warranty_period() const;

private:
    double m_amount;
    std::string m_warranty_period;
};

class WarrantyService : public Interaction 
{
public:
    WarrantyService(const std::string& user, const Sale& sale, double service_cost);
public:
    const Sale& get_sale() const;
    double get_service_cost() const;

    void display_details() const override;
    
private:
    Sale m_sale;
    double m_service_cost;
};

class Complaint : public Interaction 
{
public:
    Complaint(const std::string& user, const Sale& sale, const std::string& description);

    const Sale& get_sale() const;
    std::string get_description() const;

    void display_details() const override;
private:
    Sale m_sale;
    std::string m_description;
};
