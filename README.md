# Patrón Cadena de Responsabilidad (Chain of Responsibility)

## 📌 Descripción
Este proyecto implementa el patrón de diseño **Cadena de Responsabilidad** en C++. 

Este patrón permite que múltiples objetos manejen una solicitud sin acoplar el emisor con el receptor específico. La solicitud se pasa a lo largo de una cadena hasta que algún objeto la procesa.

---

## ⚙️ Funcionamiento
Se implementan tres validaciones en cadena:

1. **Validar que la cadena no esté vacía**: Comprueba si el usuario ingresó algún texto.
2. **Validar que tenga una longitud mínima**: Verifica que el texto tenga al menos 5 caracteres.
3. **Validar que contenga al menos un número**: Busca la presencia de dígitos en la cadena.

Cada validación es un "handler" que decide si procesa la solicitud o la pasa al siguiente eslabón de la cadena.

---

## 🧠 Estructura
- `Handler`: Clase base que define la interfaz para manejar las solicitudes.
- `ValidarVacio`: Primer filtro de la cadena.
- `ValidarLongitud`: Segundo filtro de la cadena.
- `ValidarNumero`: Último filtro que finaliza la validación.

---

## 📊 Diagrama de Clases

```mermaid
classDiagram
    Handler <|-- ValidarVacio
    Handler <|-- ValidarLongitud
    Handler <|-- ValidarNumero
    Handler : +setSiguiente(Handler*)
    Handler : +manejar(string)
