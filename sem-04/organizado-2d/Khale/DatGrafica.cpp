// DatGrafica.cpp: archivo de implementación
//

#include "stdafx.h"
#include "Khale.h"
#include "DatGrafica.h"


// Cuadro de diálogo de CDatGrafica

IMPLEMENT_DYNAMIC(CDatGrafica, CDialog)

CDatGrafica::CDatGrafica(CWnd* pParent /*=NULL*/)
	: CDialog(CDatGrafica::IDD, pParent)
	, sx(1)
	, sy(1)
{

}

CDatGrafica::~CDatGrafica()
{
}

void CDatGrafica::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, sx);
	DDV_MinMaxFloat(pDX, sx, 0.1, 5);
	DDX_Text(pDX, IDC_EDIT2, sy);
	DDV_MinMaxFloat(pDX, sy, 0.1, 5);
}


BEGIN_MESSAGE_MAP(CDatGrafica, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, &CDatGrafica::OnBnClickedButton1)
END_MESSAGE_MAP()


// Controladores de mensajes de CDatGrafica

void CDatGrafica::OnBnClickedButton1()
{
	sx=sy=1;
	CDatGrafica::OnInitDialog();
}
