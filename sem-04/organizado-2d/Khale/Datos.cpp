// Datos.cpp: archivo de implementación
//

#include "stdafx.h"
#include "Khale.h"
#include "Datos.h"


// Cuadro de diálogo de CDatos

IMPLEMENT_DYNAMIC(CDatos, CDialog)

CDatos::CDatos(CWnd* pParent /*=NULL*/)
	: CDialog(CDatos::IDD, pParent)
	, Tx(0)
	, Ty(0)
	, Sx(1)
	, Sy(1)
	, Theta(0)
	, p11(1)
	, p21(0)
	, p31(0)
	, p12(0)
	, p22(1)
	, p32(0)
	, p13(0)
	, p23(0)
	, p33(1)
	, Rx(FALSE)
	, Ry(FALSE)
{

}

CDatos::~CDatos()
{
}

void CDatos::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Tx);
	DDX_Text(pDX, IDC_EDIT2, Ty);
	DDX_Text(pDX, IDC_EDIT3, Sx);
	DDX_Text(pDX, IDC_EDIT4, Sy);
	DDX_Text(pDX, IDC_EDIT5, Theta);
	DDX_Text(pDX, IDC_EDIT7, p11);
	DDX_Text(pDX, IDC_EDIT6, p21);
	DDX_Text(pDX, IDC_EDIT8, p31);
	DDX_Text(pDX, IDC_EDIT9, p12);
	DDX_Text(pDX, IDC_EDIT10, p22);
	DDX_Text(pDX, IDC_EDIT11, p32);
	DDX_Text(pDX, IDC_EDIT12, p13);
	DDX_Text(pDX, IDC_EDIT13, p23);
	DDX_Text(pDX, IDC_EDIT14, p33);
	DDX_Check(pDX, IDC_CHECK2, Rx);
	DDX_Check(pDX, IDC_CHECK3, Ry);

	DDV_MinMaxDouble(pDX, Tx, -100, 100);
	DDV_MinMaxDouble(pDX, Ty, -100, 100);
	DDV_MinMaxDouble(pDX, Sx, 0.1, 2);
	DDV_MinMaxDouble(pDX, Sy, 0.1, 2);
	DDV_MinMaxFloat(pDX, Theta, 0, 360);
	DDV_MinMaxDouble(pDX, p11, 0.1, 2);
	DDV_MinMaxDouble(pDX, p21, -1, 1);
	DDV_MinMaxDouble(pDX, p31, -100, 100);
	DDV_MinMaxDouble(pDX, p12, -1, 1);
	DDV_MinMaxDouble(pDX, p22, 0.1, 2);
	DDV_MinMaxDouble(pDX, p32, -100, 100);
}


BEGIN_MESSAGE_MAP(CDatos, CDialog)
	ON_EN_CHANGE(IDC_EDIT1, &CDatos::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_INICIALIZAR, &CDatos::OnBnClickedButton1)
END_MESSAGE_MAP()


// Controladores de mensajes de CDatos

void CDatos::OnEnChangeEdit1()
{
	// TODO:  Si éste es un control RICHEDIT, el control no
	// enviará esta notificación a menos que se invalide la función CDialog::OnInitDialog()
	// y se llame a CRichEditCtrl().SetEventMask()
	// con el marcador ENM_CHANGE ORed en la máscara.

	// TODO:  Agregue aquí el controlador de notificación de controles
}

void CDatos::OnBnClickedButton1()
{
	Tx=0; Ty=0;
	Sx=1; Sy=1;
	Rx=false; Ry=false;
	Theta=0;
	p11=1; p12=0; p13=0; p21=0; p22=1; p23=0; p31=0; p32=0; p33=1;
	CDatos::OnInitDialog();
	CDatos::CenterWindow();
}
