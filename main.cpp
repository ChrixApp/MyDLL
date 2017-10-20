#include <windows.h>

// Función que muestra un cuadro de dialogo
void message()
{
    MessageBoxA(0, "Bienvenido a Quickhub!", "DLL Message", 0);
}

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // attach to process
            // return FALSE to fail DLL load
            // Crea un hilo
        CreateThread(0, 0, (LPTHREAD_START_ROUTINE)message, 0, 0, 0);
            break;

        case DLL_PROCESS_DETACH:
            // detach from process
            break;

        case DLL_THREAD_ATTACH:
            // attach to thread
            break;

        case DLL_THREAD_DETACH:
            // detach from thread
            break;
    }

    return TRUE; // succesful
}
