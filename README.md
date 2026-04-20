# Patrón Cadena de Responsabilidad (Chain of Responsibility)

## 📌 Descripción
Este proyecto implementa el patrón de diseño **Cadena de Responsabilidad** en C++.

Este patrón permite que múltiples objetos manejen una solicitud sin acoplar el emisor con el receptor específico. La solicitud se pasa a lo largo de una cadena hasta que algún objeto la procesa.

---

## ⚙️ Funcionamiento

Se implementan tres validaciones:

1. Validar que la cadena no esté vacía
2. Validar que tenga una longitud mínima
3. Validar que contenga al menos un número

Cada validación es un "handler" que decide si procesa o pasa la solicitud al siguiente.

---

## 🧠 Estructura

- `Handler`: Clase base
- `ValidarVacio`: Primer filtro
- `ValidarLongitud`: Segundo filtro
- `ValidarNumero`: Último filtro

---

## ▶️ Ejecución

Compilar:

```bash
g++ main.cpp -o programa
