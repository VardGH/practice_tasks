#pragma once

#include <string>

class MedicalHistory
{
public:
    MedicalHistory(const std::string& diagnoses, const std::string& treatments, const std::string& medications);
    ~MedicalHistory() = default;
public:
    std::string get_diagnoses() const;
    std::string get_treatments() const;
    std::string get_medications() const;

    void set_diagnoses(const std::string& diagnoses);
    void set_treatments(const std::string& treatments);
    void set_medications(const std::string& medications);

private:
    std::string m_diagnoses;
    std::string m_treatments; 
    std::string m_medications;
};