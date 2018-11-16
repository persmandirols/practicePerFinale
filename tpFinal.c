#include<stdio.h>
#include<string.h>

#define MAXFECHA 9

typedef struct{
	int Ncuenta;
	float saldo;
	char fecha[MAXFECHA];
}t_cuenta;
typedef struct{
	int Ncuenta;
	float saldo;
	int tipo;
	char fecha[MAXFECHA];
}t_movimiento;
void cargar_maestro(FILE *);
void mostrar_datos(FILE *);
void cargar_novedad(FILE *);
void mostrar_novedades(FILE *);
int main()
{
	FILE *AMaestro;/*archivo maestro de cuentas*/
	FILE *ANovedad;/*archivos de novedades transacciones*/
/*	carga de archivos >>>>>>>>>>>>>>LIsto
	cargar_maestro(AMaestro);
	
	mostrar_datos(AMaestro);
	mostrar_novedades(ANovedad);
	
	cargar_novedad(ANovedad);
	
*/
  
}
void cargar_maestro(FILE * a)
{
	
	int i;
	t_cuenta datos;
	char fecha[MAXFECHA];
	a=fopen("archivoMaestro.dat","w");
	
	for(i=0;i<10;i++)
	{
		printf("ingrese n0 cuenta: ");
		scanf("%d",&datos.Ncuenta);
		
		printf("ingrese  saldo: ");
		scanf("%f",&datos.saldo);
		
		printf("Ingrese fecha: ");
		fflush(stdin);
		scanf("%s",fecha);
		strcpy(datos.fecha,fecha);
		
		fwrite(&datos,sizeof(t_cuenta),1,a);
	}
	fclose(a);
printf("Carga finalizada\n");	
	
}
void mostrar_datos(FILE *a)
{
	t_cuenta datos;
	a=fopen("archivoMaestro.dat","r");
	
	fread(&datos,sizeof(t_cuenta),1,a);
	while(!feof(a))
	{
		printf("n cuenta :%d\nSaldo: %d \nfecha :%s \n",datos.Ncuenta,datos.saldo,datos.fecha);
		fread(&datos,sizeof(t_cuenta),1,a);
		
	}
	fclose(a);
	
	
}
void cargar_novedad(FILE * a)
{
	t_movimiento datos;
	char fecha[MAXFECHA];
	a=fopen("archivoNovedades.dat","w");
	
	printf("ingrese n0 de cuenta sale on cero: ");
	scanf("%d",&datos.Ncuenta);
	while(datos.Ncuenta!=0)
	{
		printf("Ingrese tipo operacion 0 deb. 1 cred. ");
		scanf("%d",&datos.tipo);
		
		printf("Ingrese monto ");
		scanf("%f",&datos.saldo);
		
		printf("Ingrese fecha: ");
		fflush(stdin);
		scanf("%s",fecha);
		strcpy(datos.fecha,fecha);
		fflush(stdin);
		fwrite(&datos,sizeof(t_movimiento),1,a);
		
		printf("ingrese n0 de cuenta sale on cero: ");
		scanf("%d",&datos.Ncuenta);
	}
	fclose(a);
printf("Carga finalizada\n");	

}
void mostrar_novedades(FILE * a)
{
	t_movimiento datos;
	a=fopen("archivoNovedades.dat","r");
	
	fread(&datos,sizeof(t_movimiento),1,a);
	while(!feof(a))
	{
		printf("n0 cuenta: %d\nTipo tra: %d\nMonto: %.2f\nfecha: %s\n\n",datos.Ncuenta,datos.tipo,datos.saldo,datos.fecha);
		
		fread(&datos,sizeof(t_movimiento),1,a);
		
	}
	fclose(a);
}
