================================================================================
    BIBLIOTECA MICROSOFT FOUNDATION CLASS: Información general del proyectoKhale
===============================================================================

El Asistente para aplicaciones ha creado esta aplicación Khale.  Esta aplicación no sólo muestra los fundamentos del uso de Microsoft 
Foundation Classes sino que también supone un punto de partida para el desarrollo de la propia aplicación.

Este archivo incluye un resumen acerca del contenido de los archivos que
constituyen su aplicación Khale.

Khale.vcproj
    Éste es el archivo de proyecto principal para los proyectos de VC++ generados mediante un asistente para aplicaciones. 
    Contiene información acerca de la versión de Visual C++ con la que se generó el archivo, así como
    información acerca de las plataformas, configuraciones y características del proyecto seleccionadas en el
    Asistente para aplicaciones.

Khale.h
    Éste es el archivo de encabezado principal para la aplicación.  Incluye otros encabezados
    específicos del proyecto y declara la clase de aplicación
    CKhaleApp.

Khale.cpp
    Éste es el archivo fuente principal de la aplicación contenido en la clase de 
    la aplicación CKhaleApp.

Khale.rc
    Ésta es una lista de todos los recursos de Microsoft Windows que utiliza el 
    programa.  Incluye los iconos, mapas de bits y cursores almacenados en el 
    subdirectorio RES.  Este archivo puede editarse directamente en Microsoft
    Visual C++. Los recursos de su proyecto se encuentran en 3082.

res\Khale.ico
    Éste es un archivo de icono, que se utiliza como el icono de la aplicación.     Éste
    icono está incluido en el archivo principal de recursos Khale.rc.

res\Khale.rc2
    Este archivo incluye recursos no editados por Microsoft 
    Visual C++. Debe colocar todos los recursos que no se pueden editar en 
    los editores de recursos de este archivo.

/////////////////////////////////////////////////////////////////////////////

Para la ventana de marco principal:
    El proyecto incluye una interfaz MFC estándar.

MainFrm.h, MainFrm.cpp
    Estos archivos contienen la clase de marco CMainFrame, que se deriva de
    CFrameWnd y que controla todas las características del marco SDI.

res\Toolbar.bmp
    Este archivo de mapa de bits se utiliza para crear imágenes organizadas en mosaico para la barra de herramientas.
    La barra de herramientas inicial y la barra de estado se crean en la clase CMainFrame. Edite este mapa de bits de barra de herramientas utilizando los editores de recursos, y
    actualice la matriz IDR_MAINFRAME TOOLBAR en Khale.rc para agregar botones de barra de herramientas.
/////////////////////////////////////////////////////////////////////////////

El Asistente para aplicaciones crea un tipo de documento y una sola vista:

KhaleDoc.h, KhaleDoc.cpp – el documento
    Estos archivos contienen su clase CKhaleDoc.  Edite estos archivos para 
    agregar los datos del documento especial y para guardar y cargar el archivo 
    (mediante CKhaleDoc::Serialize).

KhaleView.h, KhaleView.cpp – la vista del documento
    Estos archivos contienen su clase CKhaleView.
    Los objetos CKhaleView se utilizan para ver objetos CKhaleDoc.





/////////////////////////////////////////////////////////////////////////////

Otras características:

Controles ActiveX
    La aplicación es compatible con el uso de los controles ActiveX.

Compatibilidad con la impresión y la vista preliminar
    Este Asistente para aplicaciones genera el código necesario para controlar los comandos de impresión, la configuración de la impresora y la vista preliminar
    mediante llamadas a funciones miembro de la clase CView de la biblioteca MFC.

/////////////////////////////////////////////////////////////////////////////

Otros archivos estándar:

StdAfx.h, StdAfx.cpp
    Estos archivos se utilizan para generar un archivo de encabezado precompilado (PCH) 
    denominado Khale.pch y un archivo de tipos precompilado llamado StdAfx.obj.

Resource.h
    Éste es el archivo de encabezado estándar, que define nuevos identificadores de recurso.
    Microsoft Visual C++ lee y actualiza este archivo.

Khale.manifest
	Windows XP utiliza los archivos de manifiesto de la aplicación para describir la dependencia de una aplicación en versiones específicas de ensamblados simultáneos. El cargador utiliza esta información para cargar el ensamblado adecuado desde la caché de ensamblados o desde el directorio privado de la aplicación. El manifiesto de la aplicación puede incluirse para su redistribución como un archivo .manifest instalado en la misma carpeta que el ejecutable de la aplicación o puede incluirse en el ejecutable en forma de recurso. 
/////////////////////////////////////////////////////////////////////////////

Otras notas:

El Asistente para aplicaciones utiliza "TODO:" para indicar partes del código fuente que debería agregar o personalizar.

Si su aplicación utiliza MFC en un archivo DLL compartido, tendrá que copiar
los archivos DLL MFC. Si el idioma de su aplicación es distinto al idioma actual
del sistema operativo, también tendrá que copiar los recursos localizados correspondientes
MFC90XXX.DLL. Para obtener mas información sobre ambos temas, consulte la sección que trata
sobre al copia de aplicaciones de Visual C++ en la documentación de MSDN.

/////////////////////////////////////////////////////////////////////////////
