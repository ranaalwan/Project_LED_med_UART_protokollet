# Project_LED_med_UART_protokollet


Detta projekt implementerar en UART-kommunikationsprotokoll på en STM32-mikrokontrollerplattform för att styra LED-lampor.
Projektet är utformat för att erbjuda en lättanvänd och tillförlitlig lösning för att fjärrstyra LED-lampor via en seriell kommunikationslinje.

Syfte och mål
Syftet med projektet är att visa hur man kan använda UART-protokollet för att kommunicera med en STM32-mikrokontroller och styra LED-lampor. Målet med projektet är att erbjuda en grundlig förståelse av hur UART-kommunikation fungerar och hur man kan implementera en pålitlig och effektiv drivrutin för att hantera kommunikationen.

Struktur
Projektet består av följande filer och mappar:

src: Mapp som innehåller källkoden för projektet.
main.c: Huvudprogrammet som initierar UART-kommunikationen och LED-styrningen.
uart.c: Implementeringen av UART-drivrutinen.
led.c: Implementeringen av LED-drivrutinen.
uart.h: Headerfil för UART-drivrutinen.
led.h: Headerfil för LED-drivrutinen.
include: Mapp som innehåller headerfiler för projektet.

Användning
För att använda projektet behöver du en STM32-mikrokontrollerplattform med stöd för UART-kommunikation och LED-lampor. Du kan ladda upp koden till mikrokontrollern och ansluta LED-lamporna till de utgångar som specificerats i LED-drivrutinen.

Begränsningar
Detta projekt är avsett att visa grundläggande funktionalitet för att styra LED-lampor med hjälp av UART-kommunikation på en STM32-mikrokontrollerplattform. Det är inte optimerat för prestanda eller energieffektivitet och bör inte användas i produktionssystem utan nödvändiga förbättringar och anpassningar.
