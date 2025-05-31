🧑‍💻 Guía de colaboración – TP Integrador: Sistema de Gestión de Comercio

Este archivo define cómo colaborar correctamente en el proyecto para evitar 
conflictos y trabajar de forma ordenada entre los integrantes del grupo.

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

✅ Flujo de trabajo general

## Antes de empezar a trabajar:
1.Entrá al directorio del proyecto:
cd sistema-gestion-comercio/

2.Traé la última versión del proyecto desde GitHub:
git pull origin main

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

## Para guardar tus cambios:
1. Verificá qué archivos modificaste:
```sh
git status
```

2. Agregá los cambios:
```sh
git add .
```

3. Hacé el commit con un mensaje claro:
```sh
git commit -m "Descripción breve y clara de lo que hiciste"
```

4. Subí tus cambios al repo:
```sh
git push origin main
```

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

## 💡 Reglas para los mensajes de commit
•Escribí mensajes cortos, ejemplos:
“Agrego módulo de productos”
“Corrijo error en validación de login”
“Update README with Git workflow”

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

```markdown
```text
sistema-gestion-comercio/
│
├── src/              → Archivos .cpp (main, lógica del sistema)
├── include/          → Archivos .h (declaraciones de funciones)
├── docs/             → Diagramas y documentación
├── test/             → Casos de prueba
├── [README.md](http://_vscodecontentref_/7)         → Descripción general del proyecto
├── [CONTRIB.md](http://_vscodecontentref_/8)        → Guía de colaboración

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––

🧠 Buenas prácticas
•	Usar nombres de variables y funciones descriptivos.
•	Mantener el main.cpp lo más limpio posible.
•	Mover la lógica a funciones en funciones.cpp.
•	No modificar archivos en los que está trabajando otro compañero.
•	Hacer git pull antes de empezar y git push cuando termines.
•	Comentar el código cuando algo no sea obvio.

–––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––
