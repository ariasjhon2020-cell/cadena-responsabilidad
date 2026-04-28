using System;

// Clase base
abstract class Handler
{
    protected Handler siguiente;

    public void SetSiguiente(Handler sig)
    {
        siguiente = sig;
    }

    public virtual void Manejar(string solicitud)
    {
        if (siguiente != null)
        {
            siguiente.Manejar(solicitud);
        }
    }
}

// Validar que no esté vacía
class ValidarVacio : Handler
{
    public override void Manejar(string solicitud)
    {
        if (string.IsNullOrEmpty(solicitud))
        {
            Console.WriteLine("❌ Error: cadena vacía");
        }
        else
        {
            Console.WriteLine("✅ No está vacía");
            base.Manejar(solicitud);
        }
    }
}

// Validar longitud
class ValidarLongitud : Handler
{
    public override void Manejar(string solicitud)
    {
        if (solicitud.Length < 5)
        {
            Console.WriteLine("❌ Error: muy corta");
        }
        else
        {
            Console.WriteLine("✅ Longitud válida");
            base.Manejar(solicitud);
        }
    }
}

// Validar número
class ValidarNumero : Handler
{
    public override void Manejar(string solicitud)
    {
        bool tieneNumero = false;

        foreach (char c in solicitud)
        {
            if (char.IsDigit(c))
            {
                tieneNumero = true;
                break;
            }
        }

        if (!tieneNumero)
        {
            Console.WriteLine("❌ Error: no tiene números");
        }
        else
        {
            Console.WriteLine("✅ Contiene número");
            Console.WriteLine("🎉 Cadena válida completamente");
        }
    }
}

class Program
{
    static void Main(string[] args)
    {
        ValidarVacio h1 = new ValidarVacio();
        ValidarLongitud h2 = new ValidarLongitud();
        ValidarNumero h3 = new ValidarNumero();

        // Construir cadena
        h1.SetSiguiente(h2);
        h2.SetSiguiente(h3);

        Console.Write("Ingrese una cadena: ");
        string entrada = Console.ReadLine();

        h1.Manejar(entrada);
    }
}
