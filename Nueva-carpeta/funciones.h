void buscarPorTamano(int *numeroHabitacion, char cuartos[][3][40], double costos[]);
void buscarHotel(int *numeroHabitacion, char cuartos[][3][40], double costos[]);      
void realizarReserva(int numeroHabitacion, char cuartos[][3][40], char huespedes[][2][40], int reservaciones[][4]);
void buscarReservaPorCedula(int *numeroReserva, char huespedes[][2][40], int reservaciones[][4]);
void imprimirReserva(int numeroReserva, int reservaciones[][4], char cuartos[][3][40], double costos[], char huespedes[][2][40]);
void pagarReserva(int numeroReserva, int reservaciones[][4], char cuartos[][3][40], double costos[], char huespedes[][2][40]);
void guardarDatos(char huespedes[][2][40], int reservaciones[][4]);
void cargarDatos(char huespedes[][2][40], int reservaciones[][4]);
