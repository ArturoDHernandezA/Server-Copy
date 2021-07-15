#include <stdio.h>
#include <stlib.h>
#include <fcntl.h> 
char buffer[2048];
int version=1;

int main(argc, argv)
  int argc;
  char  *argv[];
{
   int fdold, fdnew;
   
   if (argc != 3)
   {
     printf(" Faltan parametros \n");
     exit(1);
   }
   fdold = open(argv[1], O_RDONLY);  /* abrir archivo fuente modo lectura */
   if (fdold == -1) 
   {
     printf(" El archivo %s no se puede abrir \n", argv[1]);
     exit(1);
   }
   fdnew = creat(argv[2], 0666);  /* creacion del archivo destino en modo rw para todos */
   if (fdnew == -1) 
   {
     printf(" Imposible de crear el archivo: %s \n", argv[2]);
     exit(1);
   }
   copy(fdold,fdnew);
   printf(" Dentro del main: Copiado exitosamente \n");
   exit(0);
} 

copy(old, new)
  int old, new;
{
  int count;
  
   while ((count = read(old, buffer, sizeof(buffer))) > 0)
      write(new, buffer, count);

   printf(" Archivo copiado exitosamente \n");
}