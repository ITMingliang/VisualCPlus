// DemoDoc.h : interface of the CDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEMODOC_H__5A2B671B_8CE4_4F6C_9CA5_C5F44D40D551__INCLUDED_)
#define AFX_DEMODOC_H__5A2B671B_8CE4_4F6C_9CA5_C5F44D40D551__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDemoDoc : public CDocument
{
protected: // create from serialization only
	CDemoDoc();
	DECLARE_DYNCREATE(CDemoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDemoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDemoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEMODOC_H__5A2B671B_8CE4_4F6C_9CA5_C5F44D40D551__INCLUDED_)
