#include "medical_history.hpp"

MedicalHistory::MedicalHistory(const std::string& diagnoses, const std::string& treatments, const std::string& medications)
    : m_diagnoses(diagnoses)
    , m_treatments(treatments)
    , m_medications(medications)
{
}

std::string MedicalHistory::get_diagnoses() const
{
    return m_diagnoses;
}

std::string MedicalHistory::get_treatments() const
{
    return m_treatments;
}

std::string MedicalHistory::get_medications() const
{
    return m_medications;
}

void MedicalHistory::set_diagnoses(const std::string& diagnoses)
{
    m_diagnoses = diagnoses;
}

void MedicalHistory::set_treatments(const std::string& treatments)
{
    m_treatments = treatments;
}

void MedicalHistory::set_medications(const std::string& medications)
{
    m_medications = medications;
}