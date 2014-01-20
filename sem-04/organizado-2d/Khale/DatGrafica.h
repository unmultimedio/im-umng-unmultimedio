#pragma once


// Cuadro de diálogo de CDatGrafica

class CDatGrafica : public CDialog
{
	DECLARE_DYNAMIC(CDatGrafica)

public:
	CDatGrafica(CWnd* pParent = NULL);   // Constructor estándar
	virtual ~CDatGrafica();

// Datos del cuadro de diálogo
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	float sx;
	float sy;
	afx_msg void OnBnClickedButton1();
};
