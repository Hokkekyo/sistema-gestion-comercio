🧑‍💻 Guía de colaboración – TP Integrador: Sistema de Gestión de Comercio

Este archivo define cómo colaborar correctamente en el proyecto para evitar 
conflictos y trabajar de forma ordenada entre los integrantes del grupo.

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

✅ Flujo de trabajo general

Antes de empezar a trabajar:
	1.	Entrá al directorio del proyecto:

cd sistema-gestion-comercio/
	2.	Traé la última versión del proyecto desde GitHub:

git pull origin main

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

Para guardar tus cambios:
	1.	Verificá qué archivos modificaste:

git status
	2.	Agregá los cambios:

git add .
	3.	Hacé el commit con un mensaje claro:

git commit -m "Descripción breve y clara de lo que hiciste"
	4.	Subí tus cambios al repo:

git push origin main

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

💡 Reglas para los mensajes de commit
	•	Escribí mensajes cortos, ejemplos:
	•	“Agrego módulo de productos”
	•	“Corrijo error en validación de login”
	•	“Update README with Git workflow”

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

📂 Organización del proyecto
	•	src/: Archivos .cpp
	•	include/: Archivos .h
	•	docs/: Diagramas y documentación del sistema
	•	test/: Casos de prueba
	•	README.md: Descripción general del proyecto
	•	CONTRIB.md: Guía para colaborar

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

🧠 Buenas prácticas
	•	Usar nombres de variables y funciones descriptivos.
	•	Evitar modificar archivos que estén siendo trabajados por otro compañero.
	•	Hacer pull antes de comenzar y push cuando termines.

