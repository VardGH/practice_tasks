#include "fitness_club.hpp"

void FitnessClub::register_member(const std::string& name, const std::string& contact_info, const MembershipLevel membership_level)
{
    m_members.push_back(Member(name, contact_info, membership_level));
}

void FitnessClub::enter_area(Member& member, const std::string& area_name)
{
    if (area_name == "Fitness Area") {
        member.enter_fitness_area();
    } else if (area_name == "Massage") {
        member.use_massage();
    } else if (area_name == "Pool") {
        member.enter_pool();
    }
}

void FitnessClub::generate_monthly_statistics(const Member& member)
{
    std::cout << std::endl;
    std::cout << "Monthly Statistics for " << member.get_name() << std::endl;
    std::cout << "-------------------------" << std::endl;

    if (member.get_membership_level() == STANDARD)
    {
        std::cout << "Fitness Area: " << 12 - member.get_remaining_entries_fitness_area() << " entries used." << std::endl;
        std::cout << "Massages: " << 1 - member.get_remaining_massages() << " used." << std::endl;
        std::cout << "Pool: " << 6 - member.get_remaining_fntries_pool() << " entries used." << std::endl;

    } else if (member.get_membership_level() == PREMIUM) {
        std::cout << "Fitness Area: " << 24 - member.get_remaining_entries_fitness_area() << " entries used." << std::endl;
        std::cout << "Massages: " << 2 - member.get_remaining_massages() << " used." << std::endl;
        std::cout << "Pool: " << 12 - member.get_remaining_fntries_pool() << " entries used." << std::endl;

    } else if (member.get_membership_level() == ALL_INCLUDED) {
        std::cout << "Fitness Area: Unlimited usage." << std::endl;
        std::cout << "Massages: Unlimited usage." << std::endl;
        std::cout << "Pool: Unlimited usage." << std::endl;
    }
    std::cout << std::endl;
    generate_monthly_bill(member);
}

void FitnessClub::generate_monthly_bill(const Member& member)
{
    std::string file_name = member.get_name() + ".txt";
    std::ofstream bill_file(file_name);

    if (bill_file.is_open()) {
        bill_file << "Monthly Bill for " << member.get_name() << std::endl;
        bill_file << "-------------------------" << std::endl;

        bill_file << "Membership Level: ";
        if (member.get_membership_level() == STANDARD) {
            bill_file << "Standard" << std::endl;
            bill_file << "Fitness Area: " << 12 - member.get_remaining_entries_fitness_area() << " entries used." << std::endl;
            bill_file << "Massages: " << 1 - member.get_remaining_massages() << " used." << std::endl;
            bill_file << "Pool: " << 6 - member.get_remaining_fntries_pool() << " entries used." << std::endl;
        } else if (member.get_membership_level() == PREMIUM) {
            bill_file << "Premium" << std::endl;
            bill_file << "Fitness Area: " << 24 - member.get_remaining_entries_fitness_area() << " entries used." << std::endl;
            bill_file << "Massages: " << 2 - member.get_remaining_massages() << " used." << std::endl;
            bill_file << "Pool: " << 12 - member.get_remaining_fntries_pool() << " entries used." << std::endl;
        } else if (member.get_membership_level() == ALL_INCLUDED) {
            bill_file << "All Included" << std::endl;
            bill_file << "Fitness Area: " << "Unlimited usage" << std::endl;
            bill_file << "Massages: " << "Unlimited usage" << " used." << std::endl;
            bill_file << "Pool: " << "Unlimited usage" << " entries used." << std::endl;
        }

        bill_file << "Total Amount Due: $" << calculate_monthly_fee(member) << std::endl;
        bill_file << std::endl;
        bill_file.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }
    
}

double FitnessClub::calculate_monthly_fee(const Member& member) 
{
    double monthly_fee = 0.0;

    if (member.get_membership_level() == STANDARD) {
        monthly_fee = 50.0;
    } else if (member.get_membership_level() == PREMIUM) {
        monthly_fee = 75.0;
    } else if (member.get_membership_level() == ALL_INCLUDED) {
        monthly_fee = 100.0;
    }
    return monthly_fee;
}

Member& FitnessClub::get_member(const std::string& name) 
{
    for (Member& member : m_members) {
        if (member.get_name() == name) {
            return member;
        }
    }
    throw std::runtime_error("Member not found.");
}

void FitnessClub::downgrade_membership(Member& member) 
{
    MembershipLevel current_level = member.get_membership_level();

    if (current_level == ALL_INCLUDED) {
        member.set_membership_level(PREMIUM);
        member.set_remaining_entries_fitness_area(24);
        member.set_remaining_massages(2);
        member.set_remaining_fntries_pool(12);
        std::cout << member.get_name() << " downgraded their membership to Premium." << std::endl;
    } else if (current_level == PREMIUM) {
        member.set_membership_level(STANDARD);
        member.set_remaining_entries_fitness_area(12);
        member.set_remaining_massages(1);
        member.set_remaining_fntries_pool(6);
        std::cout << member.get_name() << " downgraded their membership to Standard." << std::endl;
    } else {
        std::cout << member.get_name() << " already has the lowest membership level." << std::endl;
    }
}

void FitnessClub::upgrade_membership(Member& member) 
{
    MembershipLevel current_level = member.get_membership_level();

    if (current_level == STANDARD) {
        member.set_membership_level(PREMIUM);
        member.set_remaining_entries_fitness_area(24);
        member.set_remaining_massages(2);
        member.set_remaining_fntries_pool(12);
        std::cout << member.get_name() << " upgraded their membership to Premium." << std::endl;
    } else if (current_level == PREMIUM) {
        member.set_membership_level(ALL_INCLUDED);
        member.set_remaining_entries_fitness_area(-1);
        member.set_remaining_massages(-1);
        member.set_remaining_fntries_pool(-1);
        std::cout << member.get_name() << " upgraded their membership to All Included." << std::endl;
    } else {
        std::cout << member.get_name() << " already has the highest membership level." << std::endl;
    }
}
