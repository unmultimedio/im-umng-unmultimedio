// KhaleDoc.h: interfaz de la clase CKhaleDoc
//


#pragma once


class CKhaleDoc : public CDocument
{
protected: // Crear sólo a partir de serialización
	CKhaleDoc();
	DECLARE_DYNCREATE(CKhaleDoc)

// Atributos
public:

// Operaciones
public:

// Reemplazos
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementación
public:
	virtual ~CKhaleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignación de mensajes generadas
protected:
	DECLARE_MESSAGE_MAP()
};


