// Proyecto final de Programacion 2 de Sebastian Hernandez Martinez.

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct games   // La estructura de los juegos 
{
    string nombre;
    string genero;
    int peso;
    int duracion;
    int puntuacion;
    int logros;
    int precio;
};

void ordenar()  // Esta es la funcion para ver y ordenar los juegos
{
    ifstream file ("Games.txt");

    if (!file.is_open())
    {
        cout <<"Error al abrir el archivo" << endl;
        return;
    }

    string linea;
    games temporal;
    vector <games> vec;

    while (getline(file, linea))
    {
        temporal.nombre = linea;
        getline(file, linea);  temporal.genero = linea;
        getline(file, linea);  temporal.peso = stoi(linea);
        getline(file, linea);  temporal.duracion = stoi(linea);
        getline(file, linea);  temporal.puntuacion = stoi(linea);
        getline(file, linea);  temporal.logros = stoi(linea);
        getline(file, linea);  temporal.precio = stoi(linea);
        getline(file, linea);

        vec.push_back(temporal);
    }

    file.close();

    int n = vec.size();  

    for (int i = 0; i < n-1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (vec[i].nombre > vec[j].nombre)  // Aqui lo que hacemos es que si el nombre de la siguiente estructura es mayor al de la actual los cambiamos de lugar (es como un bubble)
            swap(vec[i], vec[j]);      
        }
    }

    for (auto elemento : vec)  // Imprimimos todas las estructuras ya ordenadas
    {
        cout <<"NOMBRE DEL JUEGO:\t\t"   << elemento.nombre << endl
             <<"GENERO DEL JUEGO:\t\t"   << elemento.genero << endl
             <<"PESO DEL JUEGO:\t\t\t"    << elemento.peso <<"GB" << endl
             <<"DURACION DEL JUEGO:\t\t"    << elemento.duracion <<" HORAS" << endl
             <<"PUNTACION DEL JUEGO:\t\t"     << elemento.puntuacion << endl
             <<"CANT. LOGROS DEL JUEGO:\t\t"   << elemento.logros << endl
             <<"PRECIO DEL JUEGO:\t\t$"      << elemento.precio << endl;

        cout <<"----------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }

    ofstream guardado ("Games.txt");

    if (!guardado.is_open())
    {
        cout <<"Error al abrir el archivo" << endl;
        return;
    }

    for (auto guardar : vec)
    {
        guardado << guardar.nombre << endl;
        guardado << guardar.genero << endl;
        guardado << guardar.peso << endl;
        guardado << guardar.duracion << endl;
        guardado << guardar.puntuacion << endl;
        guardado << guardar.logros << endl;
        guardado << guardar.precio << endl;
        guardado <<"------------------------------------------------------------------------------------------------------------------------" << endl;
    }

    guardado.close();

}

void eliminar()  // Esta es la funcion para eliminar un juego
{
    string name;

    cout <<"\nINGRESE EL NOMBRE DEL JUEGO QUE DESEA ELIMINAR: ";
    getline(cin, name);
    for (char &c : name)
    c = toupper(c);

    ifstream file ("Games.txt");

    if (!file.is_open())
    {
        cout <<"Error al abrir el archivo" << endl;
        return;
    }

    string linea;
    games temporal;
    vector <games> vec;

    while (getline(file, linea))   // Se pasa linea por linea y se la asigna a los atributos de la estructura temporal
    {
        temporal.nombre = linea;
        getline(file, linea);  temporal.genero = linea;
        getline(file, linea);  temporal.peso = stoi(linea);
        getline(file, linea);  temporal.duracion = stoi(linea);
        getline(file, linea);  temporal.puntuacion = stoi(linea);
        getline(file, linea);  temporal.logros = stoi(linea);
        getline(file, linea);  temporal.precio = stoi(linea);
        getline(file, linea);

        vec.push_back(temporal);   // Se mete la estructura al final del vector
    }

    file.close();

    bool found = false;

    for (auto elemento : vec)
    {
        if (elemento.nombre == name)
        {
            found = true;

            cout <<"\nNOMBRE DEL JUEGO:\t\t"   << elemento.nombre << endl
                 <<"GENERO DEL JUEGO:\t\t"   << elemento.genero << endl
                 <<"PESO DEL JUEGO:\t\t\t"    << elemento.peso <<"GB" << endl
                 <<"DURACION DEL JUEGO:\t\t"    << elemento.duracion <<" HORAS" << endl
                 <<"PUNTACION DEL JUEGO:\t\t"     << elemento.puntuacion << endl
                 <<"CANT. LOGROS DEL JUEGO:\t\t"   << elemento.logros << endl
                 <<"PRECIO DEL JUEGO:\t\t$"      << elemento.precio << endl;

            cout <<"----------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;
        } 
    }

    if (!found)
    {
        cout << name <<" NO SE ENCUENTRA EN LA TIENDA, INTENTE NUEVAMENTE" << endl;
        eliminar();
    }

    else
    {
        ofstream guardado ("Games.txt");

        if (!guardado.is_open())
        {
            cout <<"Error al abrir el archivo" << endl;
            return;
        }

        for (auto guardar : vec)   // Se recorre todo el vector y se guarda cada atributo en el archivo (excepto de la que se ingresó para eliminar)
        { 
            if (guardar.nombre != name)
            {
                guardado << guardar.nombre << endl;
                guardado << guardar.genero << endl;
                guardado << guardar.peso << endl;
                guardado << guardar.duracion << endl;
                guardado << guardar.puntuacion << endl;
                guardado << guardar.logros << endl;
                guardado << guardar.precio << endl;
                guardado <<"------------------------------------------------------------------------------------------------------------------------" << endl;
            }
        }

        guardado.close();

        cout << name <<" HA SIDO ELIMINADO DE LA TIENDA" << endl;
    }
}

void actualizar()   // Con esta funcion se edita un juego
{
    string name;

    cout <<"\nINGRESE EL NOMBRE DEL JUEGO QUE DESEA ACTUALIZAR: "; 
    getline (cin, name);

    for (char &c : name)
    c = toupper(c);

    ifstream file ("Games.txt");

    if (!file.is_open())
    {
        cout <<"Error al abrir el archivo" << endl;
        return;
    }

    string linea;
    games temporal;
    vector <games> vec;

    while (getline(file, linea))    // Se pasa por cada linea y se la asigna a los atributos de la estructura temporal
    {
        temporal.nombre = linea;
        getline(file, linea);  temporal.genero = linea;
        getline(file, linea);  temporal.peso = stoi(linea);
        getline(file, linea);  temporal.duracion = stoi(linea);
        getline(file, linea);  temporal.puntuacion = stoi(linea);
        getline(file, linea);  temporal.logros = stoi(linea);
        getline(file, linea);  temporal.precio = stoi(linea);
        getline(file, linea);

        vec.push_back(temporal);  // Mete la estructura al final del vector
    }

    file.close();

    bool found = false;

    for (auto& elemento : vec)   // Se usa auto& ya que necesitamos una referencia a cada elemento del vector
    {
        if (elemento.nombre == name)    // Si se encuentra una estructura con el nombre ingresado se imprime esa estructura y se cambia found
        {
            found = true;

            cout <<"\nNOMBRE DEL JUEGO:\t\t"   << elemento.nombre << endl
                 <<"GENERO DEL JUEGO:\t\t"   << elemento.genero << endl
                 <<"PESO DEL JUEGO:\t\t\t"    << elemento.peso <<"GB" << endl
                 <<"DURACION DEL JUEGO:\t\t"    << elemento.duracion <<" HORAS" << endl
                 <<"PUNTACION DEL JUEGO:\t\t"     << elemento.puntuacion << endl
                 <<"CANT. LOGROS DEL JUEGO:\t\t"   << elemento.logros << endl
                 <<"PRECIO DEL JUEGO:\t\t$"      << elemento.precio << endl;

            cout <<"----------------------------------------------------------------------------------------------------------------------------------------" << endl << endl;

            cout <<"EDITAR: " << endl;          // Aqui empezamos a editar los datos de la estructura encontrada
            cout <<"INGRESE EL NUEVO PRECIO DE " << name <<": ";
            cin >> elemento.precio;
            cin.ignore();

            cout <<"INGRESE LA NUEVA PUNTUACION DE " << name <<": ";
            cin >> elemento.puntuacion;
            cin.ignore();
        }
    }

    if (!found)
    {
        cout << name <<" NO SE ENCUENTRA EN LA TIENDA, INTENTE NUEVAMENTE" << endl;
        actualizar();
    }

    else
    {
        ofstream guardado ("Games.txt");     

        if (!guardado.is_open())
        {
            cout <<"Error al abrir el archivo" << endl;
            return;
        }

        for (auto guardar : vec)       // Se hace un bucle que pase por todo el vector y guarde cada atributo en el archivo
        {
            guardado << guardar.nombre << endl;
            guardado << guardar.genero << endl;
            guardado << guardar.peso << endl;
            guardado << guardar.duracion << endl;
            guardado << guardar.puntuacion << endl;
            guardado << guardar.logros << endl;
            guardado << guardar.precio << endl;
            guardado <<"------------------------------------------------------------------------------------------------------------------------" << endl;
        }

        guardado.close();

        cout <<"EL PRECIO Y LA PUNTUACION DE " << name <<" HAN SIDO ACTUALIZADOS" << endl;
    }
}

void buscaGenero(string genero)  // Con esta funcion se busca por el genero
{
    ifstream file ("Games.txt");
    if (!file.is_open())
    {
        cout <<"Error al abrir el archivo" << endl;
        return;
    }

    string linea;
    games temporal;
    bool found = false;

    while (getline(file, linea))        // Pasa por cada linea y se la asigna a los atributos de la estructura temporal
    {
        temporal.nombre = linea;
        getline(file, linea);  temporal.genero = linea;
        getline(file, linea);  temporal.peso = stoi(linea);
        getline(file, linea);  temporal.duracion = stoi(linea);
        getline(file, linea);  temporal.puntuacion = stoi(linea);
        getline(file, linea);  temporal.logros = stoi(linea);
        getline(file, linea);  temporal.precio = stoi(linea);
        getline(file, linea);

        if (temporal.genero == genero)      // Si se encuentra una estructura que tenga el genero ingresado se imprime
        {
            found = true;

            cout << "NOMBRE DEL JUEGO:\t\t" << temporal.nombre << endl
                 << "GENERO DEL JUEGO:\t\t" << temporal.genero << endl
                 << "PESO DEL JUEGO:\t\t\t" << temporal.peso << "GB" << endl
                 << "DURACION DEL JUEGO:\t\t" << temporal.duracion << " HORAS" << endl
                 << "PUNTACION DEL JUEGO:\t\t" << temporal.puntuacion << endl
                 << "CANT. LOGROS DEL JUEGO:\t\t" << temporal.logros << endl
                 << "PRECIO DEL JUEGO:\t\t$" << temporal.precio << endl
                 <<"-------------------------------------------------------------" << endl;
        }         
        
    }

    if (!found)
    cout <<"JUEGO NO ENCONTRADO. " << endl;

    file.close();
} 

void buscaNombre(string name)  // Con esta funcion se busca por el nombre
{
    ifstream file ("Games.txt");
    if (!file.is_open())
    {
        cout << "Error al abrir el archivo" << endl;
        return;
    }

    string linea;
    games temporal;
    bool found = false;

    while (getline(file, linea))  // Pasa por cada linea y se la asigna a los atributos de la estructura temporal
    {
        found = true;
        temporal.nombre = linea;
        getline(file, linea);  temporal.genero = linea;
        getline(file, linea);  temporal.peso = stoi(linea);
        getline(file, linea);  temporal.duracion = stoi(linea);
        getline(file, linea);  temporal.puntuacion = stoi(linea);
        getline(file, linea);  temporal.logros = stoi(linea);
        getline(file, linea);  temporal.precio = stoi(linea);
        getline(file, linea);  

        if (temporal.nombre == name)   // Si se encuentra una estructura que tenga el nombre ingresado se imprime
        {
            cout << "NOMBRE DEL JUEGO:\t\t" << temporal.nombre << endl
                 << "GENERO DEL JUEGO:\t\t" << temporal.genero << endl
                 << "PESO DEL JUEGO:\t\t\t" << temporal.peso << "GB" << endl
                 << "DURACION DEL JUEGO:\t\t" << temporal.duracion << " HORAS" << endl
                 << "PUNTACION DEL JUEGO:\t\t" << temporal.puntuacion << endl
                 << "CANT. LOGROS DEL JUEGO:\t\t" << temporal.logros << endl
                 << "PRECIO DEL JUEGO:\t\t$" << temporal.precio << endl;
        }
    }

    if (!found)
    cout << "JUEGO NO ENCONTRADO." << endl;

    file.close();
}

void consulta()   // Aqui esta la funcion principal de busqueda, esta se encarga de llamar a las otras funciones para buscar por nombre o por genero
{
    int opcion = 0;
    string busca;

    cout <<"\nINGRESE LA OPCION CON LA QUE DESEA BUSCAR:" << endl
         <<"1. BUSCAR POR NOMBRE" << endl
         <<"2. BUSCAR POR GENERO" << endl
         <<"3. SALIR." << endl;
    cin >> opcion;
    cin.ignore();

    while (opcion < 1 || opcion > 3)    
    {
        cout <<"OPCION INCORRECTA, POR FAVOR VUELVA A INTENTARLO." << endl;
        cin >> opcion;
    }

    if (opcion == 1)
    {
        cout <<"\nINGRESE EL NOMBRE DEL JUEGO: ";  getline(cin, busca);
        for (char &c : busca)
        c = toupper(c);

        buscaNombre(busca);
    }

    else if (opcion == 2)
    {
        cout <<"\nINGRESE EL GENERO DEL JUEGO: "; getline(cin, busca);
        for (char &c : busca)
        c = toupper(c);

        buscaGenero(busca);
    }
    
}   
    
bool verificar (string name)   // Esta funcion mira si el nombre ingresado ya esta en el archivo o no, va mirando linea por linea y en caso de que si este devuelve true    
{
    ifstream file ("Games.txt");
    if (!file.is_open())
    {
        cout <<"Error al abrir el archivo";
        return false;
    }

    string linea;
    while (getline(file, linea))
    {
        if (linea == name)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void registro()   // Funcion para los registros, primero se llenan todos los datos y luego se guarda el file
{
    games compra; 

    do                   // Hasta que no se ingrese un nombre nuevo se le va a seguir pidiendo al usuario que ingrese el nombre
    {
        cout <<"\nINGRESE EL NOMBRE DEL JUEGO: ";
        getline(cin, compra.nombre);
        for (char &c : compra.nombre)   // Se hace un for que convierta todos los caracteres del nombre en mayusculas
        c = toupper(c);

        if (verificar(compra.nombre))
        cout <<"ESTE JUEGO YA HA SIDO INGRESADO, POR FAVOR INGRESE OTRO";

    } while (verificar(compra.nombre));

    cout <<"\nINGRESE EL GENERO DEL JUEGO: ";
    getline(cin, compra.genero);
    for (char &c : compra.genero) 
    c = toupper(c);

    cout <<"\nINGRESE EL PESO DEL JUEGO (GB): ";
    cin >> compra.peso;
    cin.ignore();

    cout <<"\nINGRESE LA DURACION DEL JUEGO (HORAS): ";
    cin >> compra.duracion;
    cin.ignore();     

    cout <<"\nINGRESE LA PUNTUACION DEL JUEGO (0-100): ";
    cin >> compra.puntuacion;
    cin.ignore();

    cout <<"\nINGRESE LA CANTIDAD DE LOGROS DEL JUEGO: ";
    cin >> compra.logros;
    cin.ignore();

    cout <<"\nINGRESE EL PRECIO DEL JUEGO (COP): ";
    cin >> compra.precio;
    cin.ignore();

    cout <<"\n----------------------------------------------------------------------------------------------------------------------------------------" << endl;

    cout <<"DATOS INGRESADOS: " << endl << endl           // Aqui mostramos todos los datos que pedimos anteriormente
         <<"NOMBRE DEL JUEGO:\t\t"   << compra.nombre << endl
         <<"GENERO DEL JUEGO:\t\t"   << compra.genero << endl
         <<"PESO DEL JUEGO:\t\t\t"    << compra.peso <<"GB" << endl
         <<"DURACION DEL JUEGO:\t\t"    << compra.duracion <<" HORAS" << endl
         <<"PUNTACION DEL JUEGO:\t\t"     << compra.puntuacion << endl
         <<"CANT. LOGROS DEL JUEGO:\t\t"   << compra.logros << endl
         <<"PRECIO DEL JUEGO:\t\t$"      << compra.precio << endl;

    cout <<"----------------------------------------------------------------------------------------------------------------------------------------" << endl;

    ofstream file ("Games.txt", ios::app);      // Se guarda la estructura al final del archivo
    if (!file.is_open())
    {   
        cout <<"Error al abrir el archivo";
        return;
    }

    file << compra.nombre << endl;
    file << compra.genero << endl;
    file << compra.peso << endl;
    file << compra.duracion << endl;
    file << compra.puntuacion << endl;
    file << compra.logros << endl;
    file << compra.precio << endl;

    file <<"------------------------------------------------------------------------------------------------------------------------" << endl;

    file.close();
    cout <<"REGISTRO REALIZADO CON EXITO" << endl;

}

int main()
{
    int opcion = 0;

    do 
    {
        cout <<"\nBIENVENIDO A LA TIENDA DE VIDEOJUEGOS ALTAIR" << endl << endl
             <<"INGRESE LA OPCION QUE DESEA REALIZAR:" << endl << endl
             <<"1. REGISTRAR UN JUEGO." << endl
             <<"2. CONSULTAR JUEGOS." << endl
             <<"3. ACTUALIZAR LA INFORMACION DE UN JUEGO." << endl
             <<"4. ELIMINAR UN JUEGO." << endl
             <<"5. VER Y ORDENAR LOS JUEGOS" << endl
             <<"6. SALIR" << endl;

             cin >> opcion;
             cin.ignore();

             switch (opcion)
             {
                case 1: 
                registro();
                break;

                case 2: 
                consulta();
                break;

                case 3:
                actualizar();
                break;

                case 4:
                eliminar();
                break;

                case 5:
                ordenar();
                break;

                case 6: 
                cout <<"TENGA UN BUEN DIA";
                break;

                default:
                cout <<"OPCION INVALIDA, INTENTE NUEVAMENTE";
                break;
             }

             
    } while (opcion != 6);  

    return 0;
}