// ParcialIIDoc.h: interfaz de la clase CParcialIIDoc
//


#pragma once


class CParcialIIDoc : public CDocument
{
protected: // Crear sólo a partir de serialización
	CParcialIIDoc();
	DECLARE_DYNCREATE(CParcialIIDoc)

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
	virtual ~CParcialIIDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Funciones de asignación de mensajes generadas
protected:
	DECLARE_MESSAGE_MAP()
};


