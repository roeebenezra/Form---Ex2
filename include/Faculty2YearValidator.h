#pragma once 
#include "FormValidator.h"
#include "BaseField.h"

//template class of courses to year validator - get two fields 
template <class T1, class T2>
class Faculty2YearValidator : public FormValidator
{
public:
	Faculty2YearValidator(T1* faculty, T2* year) : FormValidator("Faculty and year don't match\n"),
		m_faculty(faculty), m_year(year) {}

	bool validateForm() override;
	bool yearInRange(int, int);		//Range of year check

private:
	T1* m_faculty = nullptr;
	T2* m_year = nullptr;
};

//___________________________
template <class T1, class T2>
bool Faculty2YearValidator<T1, T2>::validateForm()
{
	if ((m_faculty->getElement() == CS		 &&	yearInRange(1, MaxCsYear)) ||
		(m_faculty->getElement() == Liteture && yearInRange(1, MaxLitetureYear)) ||
		(m_faculty->getElement() == Medicine && yearInRange(1, MaxMedicineYear)))
	{
		setFormValid(false);	//set the opposite - Form check in negative way
		return true;
	}
	setFormValid(true);
	m_faculty->setValid(false);
	m_year->setValid(false);
	return false;
}

//___________________________
template <class T1, class T2>
bool Faculty2YearValidator<T1, T2>::yearInRange(int min, int max)
{
	return (m_year->getElement() >= min && m_year->getElement() <= max);
}