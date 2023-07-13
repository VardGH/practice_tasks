#pragma once

#include <string>
#include <iostream>

enum MembershipLevel {
    STANDARD,
    PREMIUM,
    ALL_INCLUDED
};

class Member
{
public:
    Member(const std::string& name, const std::string& contact_info, const MembershipLevel membership_level);
    ~Member() = default;

public:
    std::string get_name() const;
    std::string get_contact_info() const;
    MembershipLevel get_membership_level() const;
    int get_remaining_entries_fitness_area() const;
    int get_remaining_massages() const;
    int get_remaining_fntries_pool() const;

    void set_name(const std::string& name);
    void set_contact_info(const std::string& contact_info);
    void set_membership_level(const MembershipLevel membership_level);
    void set_remaining_entries_fitness_area(const int);
    void set_remaining_massages(const int);
    void set_remaining_fntries_pool(const int);

    void use_massage();
    void enter_pool();
    void enter_fitness_area(); 

private:
    std::string m_name;
    std::string m_contact_info;
    MembershipLevel m_membership_level;
    int m_remaining_entries_fitness_area;
    int m_remaining_massages;
    int m_remaining_fntries_pool;
};