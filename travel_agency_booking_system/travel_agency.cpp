#include "travel_agency.hpp"

void TravelAgency::register_user()
{
    std::cout << "User Registration\n";
    
    std::string name;
    std::cout << "Enter name: ";
    std::cin >> name;

    std::string contact_info;
    std::cout << "Enter contact information: ";
    std::cin >> contact_info;

    m_users.push_back(User(name, contact_info));

    std::cout << "User registration successful.\n";
}

void TravelAgency::register_travel_package()
{
    std::cout << "Travel Package Registration\n";

    std::string destination;
    std::cout << "Enter destination: ";
    std::cin >> destination;

    double price;
    std::cout << "Enter price: ";
    std::cin >> price;

    int available_slots;
    std::cout << "Enter available slots: ";
    std::cin >> available_slots;
    std::cin.ignore(); // Ignore the newline character

    m_travel_packages.push_back(TravelPackage(destination, price, available_slots));

    std::cout << "Travel package registration successful.\n";
}

void TravelAgency::search_and_book() 
{
    std::cout << "Search and Book\n";

    double max_price;
    std::cout << "Enter maximum price: ";
    std::cin >> max_price;

    int required_slots;
    std::cout << "Enter required slots: ";
    std::cin >> required_slots;
    std::cin.ignore(); // Ignore the newline character

    bool found = false;
    std::cout << "Matching Travel Packages:\n";
    for (const TravelPackage& package : m_travel_packages) {
        if (package.get_price() <= max_price && package.get_available_slots() >= required_slots) {
            std::cout << "Destination: " << package.get_destination() << std::endl;
            std::cout << "Price: " << package.get_price() << std::endl;
            std::cout << "Available Slots: " << package.get_available_slots() << std::endl;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No matching travel packages found.\n";
        return;
    }

    std::string user_name {};
    std::string booking_details {};
    int slots_to_book {};

    std::cout << "Enter your name: ";
    std::cin >> user_name;

    for (const User& user : m_users) {
        if (user.get_name() == user_name) {
            std::cout << "Enter booking details: ";
            std::cin >> booking_details;
            std::cout << "Enter number of slots to book: ";
            std::cin >> slots_to_book;
            std::cin.ignore(); // Ignore the newline character

            for (TravelPackage& package : m_travel_packages) {
                if (package.get_price() <= max_price && package.get_available_slots() >= required_slots) {
                    Booking new_booking(user, package, booking_details);
                    package.book_slots(slots_to_book);
                    m_bookings.push_back(new_booking);
                    generate_ticket(new_booking);
                    std::cout << "Booking successful.\n";
                    return;
                }
            }
        }
    }

    std::cout << "User not found.\n";
}

void TravelAgency::generate_ticket(const Booking& booking) {
    std::cout << "Ticket Details:\n";
    std::cout << "-----------------------------------\n";
    std::cout << "User: " << booking.get_user().get_name() << std::endl;
    std::cout << "Contact Information: " << booking.get_user().get_contact_info() << std::endl;
    std::cout << "Destination: " << booking.get_travel_package().get_destination() << std::endl;
    std::cout << "Price: " << booking.get_travel_package().get_price() << std::endl;
    std::cout << "Booking Details: " << booking.get_booking_details() << std::endl;
    std::cout << "-----------------------------------\n";
}

void TravelAgency::generate_report() {
    std::ofstream outputFile("report.txt");

    if (!outputFile) {
        std::cout << "Error opening report file.\n";
        return;
    }

    outputFile << "Travel Package Report\n";
    outputFile << "-----------------------------------\n";
    for (const TravelPackage& package : m_travel_packages) {
        outputFile << "Destination: " << package.get_destination() << std::endl;
        outputFile << "Price: " << package.get_price() << std::endl;
        outputFile << "Available Slots: " << package.get_available_slots() << std::endl;
        outputFile << "Booked Slots: " << package.get_booked_slots() << std::endl;
        outputFile << "-----------------------------------\n";
    }

    outputFile.close();
    std::cout << "Report generated and saved as 'report.txt'.\n";
}

void TravelAgency::run() {
    int choice;

    while (true) {
        std::cout << "\nTravel Agency Booking System\n";
        std::cout << "1. Register User\n";
        std::cout << "2. Register Travel Package\n";
        std::cout << "3. Search and Book\n";
        std::cout << "4. Generate Report\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Ignore the newline character

        switch (choice) {
            case 1:
                register_user();
                break;
            case 2:
                register_travel_package();
                break;
            case 3:
                search_and_book();
                break;
            case 4:
                generate_report();
                break;
            case 5:
                std::cout << "Exiting the program.\n";
                return;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    }
}