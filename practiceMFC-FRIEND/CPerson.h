#pragma once
#include <afx.h>
class CPerson : public CObject
{
public:
    CPerson();
    ~CPerson();

    int m_nAge;
    CString m_strName;
    BOOL m_bGender;
    virtual void Serialize(CArchive& ar);
};

