#pragma once 
#include "FormValidator.h"

//template class of courses to year validator - get two fields 
template <class T1, class T2>
class Courses2YearValidator : public FormValidator
{
public:
	Courses2YearValidator(T1* course, T2* year) : FormValidator("Course and year don't match\n"),
		m_course(course), m_year(year) {}
	
	bool validateForm() override;
private:
	T1* m_course = nullptr;
	T2* m_year = nullptr;
};

//___________________________
template <class T1, class T2>
bool Courses2YearValidator<T1, T2>::validateForm()
{
	if (m_year->getElement() >= MinCoursesPerYear)
	{
		setFormValid(false);	//set the opposite - Form check in negative way
		return true;
	}

	setFormValid(true);
	m_course->setValid(false);
	m_year->setValid(false);
	return false;
}
