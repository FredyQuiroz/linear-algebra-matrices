// MatricesDlg.cpp: archivo de implementación
//

#include "stdafx.h"
#include "Matrices.h"
#include "MatricesDlg.h"
# include <math.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cuadro de diálogo CAboutDlg utilizado para el comando Acerca de

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Datos del cuadro de diálogo
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Compatibilidad con DDX/DDV

// Implementación
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// Cuadro de diálogo de CMatricesDlg




CMatricesDlg::CMatricesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMatricesDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	for(int i=0; i<3; i++) 
		for(int j=0; j<3; j++)
			m_nMatriz[i][j]=0;
}

void CMatricesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ETEXTO, m_ETexto);
	DDX_Control(pDX, IDC_ENCRIPTADO, m_EEncriptado);
	DDX_Control(pDX, IDC_E11, m_E11);
	DDX_Control(pDX, IDC_E12, m_E12);
	DDX_Control(pDX, IDC_E13, m_E13);
	DDX_Control(pDX, IDC_E21, m_E21);
	DDX_Control(pDX, IDC_E22, m_E22);
	DDX_Control(pDX, IDC_E23, m_E23);
	DDX_Control(pDX, IDC_E31, m_E31);
	DDX_Control(pDX, IDC_E32, m_E32);
	DDX_Control(pDX, IDC_E33, m_E33);
	DDX_Control(pDX, IDC_SMENSAJE, m_SMensaje);
	DDX_Control(pDX, IDOK, m_BAceptar);
}

BEGIN_MESSAGE_MAP(CMatricesDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CMatricesDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMatricesDlg::OnBnClickedCancel)
	ON_EN_CHANGE(IDC_ETEXTO, &CMatricesDlg::OnEnChangeEtexto)
	ON_EN_CHANGE(IDC_ENCRIPTADO, &CMatricesDlg::OnEnChangeEtexto)
	ON_EN_CHANGE(IDC_E11, &CMatricesDlg::OnEnChangeE11)
	ON_EN_CHANGE(IDC_E12, &CMatricesDlg::OnEnChangeE11)
	ON_EN_CHANGE(IDC_E13, &CMatricesDlg::OnEnChangeE11)
	ON_EN_CHANGE(IDC_E21, &CMatricesDlg::OnEnChangeE11)
	ON_EN_CHANGE(IDC_E22, &CMatricesDlg::OnEnChangeE11)
	ON_EN_CHANGE(IDC_E23, &CMatricesDlg::OnEnChangeE11)
	ON_EN_CHANGE(IDC_E31, &CMatricesDlg::OnEnChangeE11)
	ON_EN_CHANGE(IDC_E32, &CMatricesDlg::OnEnChangeE11)
	ON_EN_CHANGE(IDC_E33, &CMatricesDlg::OnEnChangeE11)
END_MESSAGE_MAP()


// Controladores de mensaje de CMatricesDlg

BOOL CMatricesDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Agregar el elemento de menú "Acerca de..." al menú del sistema.

	// IDM_ABOUTBOX debe estar en el intervalo de comandos del sistema.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Establecer el icono para este cuadro de diálogo. El marco de trabajo realiza esta operación
	//  automáticamente cuando la ventana principal de la aplicación no es un cuadro de diálogo
	SetIcon(m_hIcon, TRUE);			// Establecer icono grande
	SetIcon(m_hIcon, FALSE);		// Establecer icono pequeño

	// m_ETexto.SetWindowText("Codigo");
	// m_EEncriptado.SetWindowText("WLPGSE");
	OnEnChangeEtexto();

	m_E11.SetWindowText("5");
	m_E12.SetWindowText("17");
	m_E13.SetWindowText("20");
	m_E21.SetWindowText("9");
	m_E22.SetWindowText("23");
	m_E23.SetWindowText("3");
	m_E31.SetWindowText("2");
	m_E32.SetWindowText("11");
	m_E33.SetWindowText("13");

	OnEnChangeE11();
	return TRUE;  // Devuelve TRUE  a menos que establezca el foco en un control
}

void CMatricesDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// Si agrega un botón Minimizar al cuadro de diálogo, necesitará el siguiente código
//  para dibujar el icono. Para aplicaciones MFC que utilicen el modelo de documentos y vistas,
//  esta operación la realiza automáticamente el marco de trabajo.

void CMatricesDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // Contexto de dispositivo para dibujo

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrar icono en el rectángulo de cliente
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dibujar el icono
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// El sistema llama a esta función para obtener el cursor que se muestra mientras el usuario arrastra
//  la ventana minimizada.
HCURSOR CMatricesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

CString CMatricesDlg::Multiplicar(int matriz[3]) {

	CString resultado;
	for(int i=0; i<3; i++) {
		int temp=0;
		for(int j=0;j<3; j++) {
			temp+= m_nMatriz[i][j]*matriz[j];
		}
		resultado+= (char )((temp%26)+65);
	}
	return resultado;
}

CString CMatricesDlg::Encriptar(CString cadena) {

	cadena.MakeUpper();
	CString resultado;
	for(int i=0;i<cadena.GetLength(); i++) {
		if(!isalpha(cadena[i])) {
			cadena.Delete(i);
			i--;
		}
	}
	while(cadena.GetLength()%3)
		cadena+="X";

	for(int i=0; i<cadena.GetLength(); i+=3) {

		int temp[3];
		temp[0]= cadena[i]-65;
		temp[1]= cadena[i+1]-65;
		temp[2]= cadena[i+2]-65;
		resultado+=Multiplicar(temp);
	}
	return resultado;
}

CString CMatricesDlg::MultiplicarInversa(int matriz[3]) {

	CString resultado;
	for(int i=0; i<3; i++) {
		int temp=0;
		for(int j=0;j<3; j++) {
			temp+= m_nIdentidad[i][j]*matriz[j];
		}
		resultado+= (char )((temp%26)+65);
	}
	return resultado;
}

CString CMatricesDlg::DesEncriptar(CString cadena) {

	cadena.MakeUpper();
	CString resultado;

	for(int i=0; i<cadena.GetLength(); i+=3) {

		int temp[3];
		temp[0]= cadena[i]-65;
		temp[1]= cadena[i+1]-65;
		temp[2]= cadena[i+2]-65;
		resultado+=MultiplicarInversa(temp);
	}
	return resultado;
}

void CMatricesDlg::OnBnClickedOk()
{
	if(Determinante()==0) {
		MessageBox("Debe ingresar una matriz invertible");
		return;
	}
	CString temp;
	m_ETexto.GetWindowText(temp);
	if(!temp.IsEmpty()) { // encriptar

		m_EEncriptado.SetWindowText(Encriptar(temp));
		return;
	}
	m_EEncriptado.GetWindowText(temp);
	if(!temp.IsEmpty()) { // desencriptar
		
		MtrizInvrsa();
		m_ETexto.SetWindowText(DesEncriptar(temp));
	}
	// OnOK();
}

void CMatricesDlg::OnBnClickedCancel()
{
	OnCancel();
}

void CMatricesDlg::OnEnChangeEtexto()
{
	CString temp;
	m_ETexto.GetWindowText(temp);
	if(!temp.IsEmpty()) {
		m_BAceptar.SetWindowText("Encriptar");
		m_BAceptar.EnableWindow(true);
		return;
	}
	m_EEncriptado.GetWindowText(temp);
	if(!temp.IsEmpty()) {
		m_BAceptar.SetWindowText("Desencriptar");
		m_BAceptar.EnableWindow(true);
		return;
	}
	m_BAceptar.EnableWindow(false);
}

int CMatricesDlg::Determinante() {

	int determinante = 0, aux = 0;
	int c;
	for(int j=0; j<3; j++){

		int menor[2][2];
		for(int k=1; k<3; k++){
			c = 0;
			for(int l=0; l<3; l++){
				if(l!=j){
					menor[k-1][c] = m_nMatriz[k][l];
					c++;
				}
			}
		}
		aux = ((int)pow((double)-1, (double)2+j))*m_nMatriz[0][j]*(menor[0][0]*menor[1][1] - menor[1][0]*menor[0][1]);
		determinante += aux;
	}
	return determinante;
}

void CMatricesDlg::OnEnChangeE11()
{
	CString temp;
	m_E11.GetWindowText(temp);
	m_nMatriz[0][0]=atoi(temp);
	m_E12.GetWindowText(temp);
	m_nMatriz[0][1]=atoi(temp);
	m_E13.GetWindowText(temp);
	m_nMatriz[0][2]=atoi(temp);
	m_E21.GetWindowText(temp);
	m_nMatriz[1][0]=atoi(temp);
	m_E22.GetWindowText(temp);
	m_nMatriz[1][1]=atoi(temp);
	m_E23.GetWindowText(temp);
	m_nMatriz[1][2]=atoi(temp);
	m_E31.GetWindowText(temp);
	m_nMatriz[2][0]=atoi(temp);
	m_E32.GetWindowText(temp);
	m_nMatriz[2][1]=atoi(temp);
	m_E33.GetWindowText(temp);
	m_nMatriz[2][2]=atoi(temp);

	m_SMensaje.SetWindowText(Determinante()==0 ? "Matriz no invertible" : "");
}

int CMatricesDlg::ModularInverse(int px, int py) {

	int x = px;
	int y = py;

	//Setup initial variables
	//Maintain throughout that ax * px + bx * py = x and that ay * px + by * py = y
	int ax = 1;
	int ay = 0;
	int bx = 0;
	int by = 1;
	int temp;

	//Perform extended gcd
	while(x)
	{
		if(x <= y)
		{
			int m = y / x;
			y -= m * x;
			ay -= ax * m;
			by -= bx * m;
		}
		else
		{
			temp= x;
			x=y;
			y=temp;

			temp= ax;
			ax=ay;
			ay=temp;

			temp= bx;
			bx=by;
			by= temp;
		}
	}

	//you can assert that ay * px + by * py = y = gcd(px, py)
	//you can assert that ax * px + bx * py = x = 0

	//If we're taking the modular inverse of px (mod py), then for it to exist gcd(px, py) = 1
	//If it does exist, it is given by ay (mod py)
	int inverse = ay % py;
	if(inverse < 0) inverse += py;
	return inverse;
}

void CMatricesDlg::MtrizInvrsa()
{
	int modularinverse= ModularInverse(Determinante());
	int i,j,ii,jj,i1,j1; 
	int det=1;
	int c[2][2];

	for (j=0;j<3;j++) { 
		for (i=0;i<3;i++) { 

			/* Form the adjoint a_ij */ 
			i1 = 0; 
			for (ii=0;ii<3;ii++) { 
				if (ii == i) 
					continue; 
				j1 = 0; 
				for (jj=0;jj<3;jj++) { 
					if (jj == j) 
						continue; 
					c[i1][j1] = m_nMatriz[ii][jj]; 
					j1++; 
				} 
				i1++; 
			} 
			det = c[0][0] * c[1][1] - c[1][0] * c[0][1];
			/* Fill in the elements of the cofactor */ 
			m_nIdentidad[i][j] = pow(-1.0,i+j+2.0) * det*modularinverse;
			m_nIdentidad[i][j]= m_nIdentidad[i][j]%26;
			if(m_nIdentidad[i][j]<0)
				m_nIdentidad[i][j]+=26;
		} 
	}
	int temp;
	for(int j=0; j<3; j++) {
		for (int i=j+1; i<3; i++)
		{
			temp= m_nIdentidad[i][j];
			m_nIdentidad[i][j]= m_nIdentidad[j][i];
			m_nIdentidad[j][i]=temp;
		}
	}
}