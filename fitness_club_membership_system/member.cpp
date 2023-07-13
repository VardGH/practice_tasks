#include "member.hpp"

Member::Member(const std::string& name, const std::string& contact_info, const MembershipLevel membership_level)
    : m_name(name)
    , m_contact_info(contact_info)
    , m_membership_level(membership_level)
{
    if (membership_level == STANDARD) {
        m_remaining_entries_fitness_area = 12;
        m_remaining_massages = 1;
        m_remaining_fntries_pool = 6;
    } else if (membership_level == PREMIUM) {
        m_remaining_entries_fitness_area = 24;
        m_remaining_massages = 2;
        m_remaining_fntries_pool = 12;
    } else if (membership_level == ALL_INCLUDED) {
        m_remaining_entries_fitness_area = -1;  // -1 - unlimited
        m_remaining_massages = -1;  
        m_remaining_fntries_pool = -1;  
    }
}

std::string Member::get_name() const
{
    return m_name;
}

std::string Member::get_contact_info() const
{
    return m_contact_info;
}

MembershipLevel Member::get_membership_level() const
{
    return m_membership_level;
}

int Member::get_remaining_entries_fitness_area() const
{
    return m_remaining_entries_fitness_area;
}

int Member::get_remaining_massages() const
{
    return m_remaining_massages;
}

int Member::get_remaining_fntries_pool() const
{
    return m_remaining_fntries_pool;
}

void Member::set_name(const std::string& name)
{
    m_name = name;
}

void Member::set_contact_info(const std::string& contact_info)
{
    m_contact_info = contact_info;
}

void Member::set_membership_level(MembershipLevel membership_level)
{
    m_membership_level = membership_level;
}

void Member::set_remaining_fntries_pool(const int remaining_fntries_pool)
{
    m_remaining_fntries_pool = remaining_fntries_pool;
}

void Member::set_remaining_entries_fitness_area(const int remaining_entries_fitness_area)
{
    m_remaining_entries_fitness_area = remaining_entries_fitness_area;
}

void Member::set_remaining_massages(const int remaining_massages)
{
    m_remaining_massages = remaining_massages;
}

void Member::enter_fitness_area() 
{
    if (m_remaining_entries_fitness_area == 0) {
         std::cout << m_name << " has used all their entries to the Fitness Area." << std::endl;
    } else {
        m_remaining_entries_fitness_area--;
    }
}

void Member::use_massage() 
{
    if (m_remaining_massages == 0) {
        std::cout << m_name << " has used all their massages." << std::endl;
    } else {
        m_remaining_massages--;
    }
}

void Member::enter_pool() 
{
    if (m_remaining_fntries_pool == 0) {
        std::cout << m_name << " has used all their entries to the Pool." << std::endl;
    } else {
        m_remaining_fntries_pool--;
    }
}
