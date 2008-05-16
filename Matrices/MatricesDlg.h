// MatricesDlg.h: archivo de encabezado
//

#pragma once
#include "afxwin.h"


// Cuadro de diálogo de CMatricesDlg
class CMatricesDlg : public CDialog
{
// Construcción
public:
	CMatricesDlg(CWnd* pParent = NULL);	// Constructor estándar

// Datos del cuadro de diálogo
	enum { IDD = IDD_MATRICES_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Compatibilidad con DDX/DDV


// Implementación
protected:
	HICON m_hIcon;

	// Funciones de asignación de mensajes generadas
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_ETexto;
	CEdit m_EEncriptado;
	CEdit m_E11;
	CEdit m_E12;
	CEdit m_E13;
	CEdit m_E21;
	CEdit m_E22;
	CEdit m_E23;
	CEdit m_E31;
	CEdit m_E32;
	CEdit m_E33;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEtexto();
	afx_msg void OnEnChangeE11();
	CStatic m_SMensaje;
	int Determinante();
	int	m_nMatriz[3][3];
	int m_nIdentidad[3][3];

	CButton m_BAceptar;
	CString Encriptar(CString cadena);
	CString DesEncriptar(CString cadena);
	CString Multiplicar(int matriz[3]);
	CString MultiplicarInversa(int matriz[3]);

	// hallamos la inversa
	void MtrizInvrsa();
	int ModularInverse(int px, int py=26);
};
